/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                2003      by Advanced Data Controls, Corp
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: integrator.c,v 1.1 2008/06/17 00:04:58 suikan Exp $
 *  
 */

/*
 * Integrator �����@�\�p�h���C�o
 */
#include <s_services.h>
#include <integrator.h>


/*
 * �V���A��I/O�|�[�g�������u���b�N
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
    {(VP)UART1_DR,(VP)UART1_CR,(VP)UART1_LCRL,
     (VP)UART1_LCRM,(VP)UART1_LCRH,(VP)UART1_IIR,
     (VP)UART1_FR,IRQ_UART1
    }
#if TNUM_SIOP >= 2
    ,
    {(VP)UART0_DR,(VP)UART0_CR,(VP)UART0_LCRL,
     (VP)UART0_LCRM,(VP)UART0_LCRH,(VP)UART0_IIR,
     (VP)UART0_FR,IRQ_UART0
    }

#endif /* TNUM_SIOP >= 2 */
};


/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
SIOPCB  siopcb_table[TNUM_SIOP];


/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)  ((UINT)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))


/*
 * ��������M������?
 */ 
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
    return((sil_rew_mem((VP)(siopcb->siopinib->int_identifier)) & IIR_RIS)!=0);
}

/*
 * �����𑗐M�ł��邩?
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
    return((sil_rew_mem((VP)(siopcb->siopinib->flag_register)) & UFR_BUSY)==0);
}

/*
 *  ��M���������̎��o��
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
    return(sil_rew_mem((VP)(siopcb->siopinib->uart_data)));
}

/*
 *  ���M���镶���̏�������
 */
Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_data),c);
}

/*
 *  ���M�����݋���
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_control),
            (sil_rew_mem((VP)(siopcb->siopinib->uart_control)) | UCR_TIE));
}

/*
 *  ���M�����݋֎~
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_control),
	    (sil_rew_mem((VP)(siopcb->siopinib->uart_control)) & ~UCR_TIE));
}


/*
 *  ��M�����݋���
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_control),
	    (sil_rew_mem((VP)(siopcb->siopinib->uart_control)) | UCR_RIE));
}

/*
 *  ��M�����݋֎~
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{

    sil_wrw_mem((VP)(siopcb->siopinib->uart_control),
	    (sil_rew_mem((VP)(siopcb->siopinib->uart_control)) & ~UCR_RIE));

}



/*
 *  SIO�h���C�o�̏��������[�`��
 *  1�|�[�g�����Ȃ����߁C���܂�Ӗ��͂Ȃ�
 */
void
uart_initialize()
{
    SIOPCB  *siopcb;
    UINT    i;

    /*
     *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
     */
    for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
        siopcb->siopinib = &(siopinib_table[i]);
        siopcb->openflag = FALSE;
        siopcb->sendflag = FALSE;
    }
}

/*
 * �I�[�v�����Ă���|�[�g�����邩
 */
BOOL
uart_openflag(void)
{
    return(siopcb_table[0].openflag);
}

/*
 * �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;

    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;

    /* Disable Interrupt */
    sil_wrw_mem((VP)siopinib->uart_control, ~UCR_UARTEN);
    /* 19200bps */
    sil_wrw_mem((VP)siopinib->linectrl_lo, ULCRL_19200); 
    sil_wrw_mem((VP)siopinib->linectrl_mid, ULCRM_19200);
    /* 8Data, 1Stop, No Parity */
    sil_wrw_mem((VP)siopinib->linectrl_hi, ULCRH_WLEN_8BIT);

    
    /*
     * �����݊֘A�̐ݒ�
     */
    sil_wrw_mem((VP)siopinib->uart_control, UCR_UARTEN); /* Enable Interrupt */
    sil_wrw_mem((VP)IRQ0_ENABLESET,siopinib->irq_bit);/*Enable interrupt register*/
    
    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    return(siopcb);    
}



/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
uart_cls_por(SIOPCB *siopcb)
{
    sil_wrw_mem((VP)(siopcb->siopinib->uart_control),
	    (sil_rew_mem((VP)(siopcb->siopinib->uart_control))&~UCR_UARTEN)); /* Disable Interrupt */
    
    siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, char c)
{
    if (uart_putready(siopcb)){
        uart_putchar(siopcb, c);
        return(TRUE);
    }
    return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
uart_rcv_chr(SIOPCB *siopcb)
{
    if (uart_getready(siopcb)) {
        return((INT)(UB) uart_getchar(siopcb));
    }
    return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    switch (cbrtn) {
        case SIO_ERDY_SND:
            uart_enable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            uart_enable_rcv(siopcb);
            break;
    }
}


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    switch (cbrtn) {
        case SIO_ERDY_SND:
            uart_disable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            uart_disable_rcv(siopcb);
            break;
    }
}



/*
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���
 */
static void
uart_isr_siop(SIOPCB *siopcb)
{
    if (uart_getready(siopcb)) {
        /*
         *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
         */
        uart_ierdy_rcv(siopcb->exinf);
    }
    if (uart_putready(siopcb)) {
        /*
         *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
         */
        uart_ierdy_snd(siopcb->exinf);
    }
}


/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
uart_isr0()
{
    uart_isr_siop(&(siopcb_table[0]));
}

#if TNUM_SIOP >= 2
void
uart_isr1()
{
    uart_isr_siop(&(siopcb_table[1]));
}
#endif
