/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                     2003  by Advanced Data Controls, Corp
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
 *  @(#) $Id: fdc37c935a.c,v 1.1 2008/06/17 00:04:58 suikan Exp $
 */

/*
 * �X�[�pI/O FDC37C935A �p�h���C�o
 */

#include <s_services.h>
#include "fdc37c935a.h"

/*
 *  ������
 */
void
smsc_init(void)
{
    /*
     * Enter Config mode 
     */
    sil_wrh_mem((VP)SMSC_CONFIG_PORT, (0x55 << 8));
    sil_wrh_mem((VP)SMSC_CONFIG_PORT, (0x55 << 8));

    /*
     * Init SCI0
     */
    /* Power on */
    smsc_config_write(0x22, (smsc_config_read(0x22) | 0x10));
    /* Select SCI0 */
    smsc_config_write(0x07, 0x04);
    /* Enable SCI0 */
    smsc_config_write(0x30, 0x01);
    /* Set SCI0 Base Address */
    smsc_config_write(0x60, (SMSC_SCI0_BASE_ADDR & 0xff00) >> 8);
    smsc_config_write(0x61, (SMSC_SCI0_BASE_ADDR & 0xff));    
    /* IRQ4 */
    smsc_config_write(0x70, 0x04);
    

    /*
     *  Exit Config mode
     */
    sil_wrh_mem((VP)SMSC_CONFIG_PORT, (0xAA << 8));
}


/*
 *  �X�[�p�[I/O(FDC37C935A)�p �Ȉ�SIO�h���C�o
 */

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
typedef struct sio_port_initialization_block {
    char dummy;
} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N
 */
struct sio_port_control_block {
    const SIOPINIB  *siopinib;  /* �V���A��I/O�|�[�g�������u���b�N */
    VP_INT          exinf;      /* �g����� */
    BOOL    openflag;           /* �I�[�v���ς݃t���O */
    BOOL    sendflag;           /* ���M�����݃C�l�[�u���t���O */
    BOOL    getready;           /* ��������M������� */
    BOOL    putready;           /* �����𑗐M�ł����� */
};

/*
 * �V���A��I/O�|�[�g�������u���b�N
 */
const SIOPINIB siopinib_table[TNUM_SIOP]= {{0}};

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
smsc_sci0_getready(SIOPCB *siopcb)
{
    return(((sil_reh_mem((VP)SMSC_SCI0_LSR) >> 8) & 0x01) != 0);
}

/*
 * �����𑗐M�ł��邩?
 */
Inline BOOL
smsc_sci0_putready(SIOPCB *siopcb)
{
	return(((sil_reh_mem((VP)SMSC_SCI0_LSR) >> 8) & 0x60) != 0);
}

/*
 *  ��M���������̎��o��
 */
Inline char
smsc_sci0_getchar(SIOPCB *siopcb)
{
    return (sil_reh_mem((VP)SMSC_SCI0_RBR) >> 8);
}

/*
 *  ���M���镶���̏�������
 */
Inline void
smsc_sci0_putchar(SIOPCB *siopcb, char c)
{
    sil_wrh_mem((VP)SMSC_SCI0_THR, c << 8);
}

/*
 *  ���M�����݋���
 */
Inline void
smsc_sci0_enable_send(SIOPCB *siopcb)
{

    sil_wrh_mem((VP)SMSC_SCI0_IER,
                (((sil_reh_mem((VP)SMSC_SCI0_IER) >> 8) | 0x02) << 8));   
}

/*
 *  ���M�����݋֎~
 */
Inline void
smsc_sci0_disable_send(SIOPCB *siopcb)
{
    sil_wrh_mem((VP)SMSC_SCI0_IER,
                (((sil_reh_mem((VP)SMSC_SCI0_IER) >> 8) & ~0x02) << 8));   
}

/*
 *  ��M�����݋���
 */
Inline void
smsc_sci0_enable_rcv(SIOPCB *siopcb)
{

    sil_wrh_mem((VP)SMSC_SCI0_IER,
                (((sil_reh_mem((VP)SMSC_SCI0_IER) >> 8) | 0x01) << 8));   
}

/*
 *  ��M�����݋֎~
 */
Inline void
smsc_sci0_disable_rcv(SIOPCB *siopcb)
{
    sil_wrh_mem((VP)SMSC_SCI0_IER,
                (((sil_reh_mem((VP)SMSC_SCI0_IER) >> 8) & ~0x01) << 8));   
}





/*
 *  SIO�h���C�o�̏��������[�`��
 *  1�|�[�g�����Ȃ����߁C���܂�Ӗ��͂Ȃ�
 */
void
smsc_sci0_initialize()
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
 *  �����݈ȊO�̏�����
 */
void
fdc37c935a_init(void)
{
    volatile UH dummy;
    
    /* BIT7 = 1 */
    sil_wrh_mem((VP)SMSC_SCI0_LCR, 0x83 << 8);

    /* Set BPS */
    sil_wrh_mem((VP)SMSC_SCI0_DLL, ((SMSC_SCI0_BPS & 0x00ff) << 8));   
    sil_wrh_mem((VP)SMSC_SCI0_DLM, ((SMSC_SCI0_BPS >> 8) << 8));

    /* BIT7 = 0 Divisor Latch BIT6 = 0 No Break : BIT3 = 0 NoParity
       : BIT2 = 0 1Stopbit : BIT1,0 = {1.1} 8bitData */    
    sil_wrh_mem((VP)SMSC_SCI0_LCR, 0x03 << 8);

    /* Do not use FIFO */
    sil_wrh_mem((VP)SMSC_SCI0_FCR, 0x0000);

    /* Clear Status */
    dummy = sil_reh_mem((VP)SMSC_SCI0_RBR);
    dummy = sil_reh_mem((VP)SMSC_SCI0_LSR);    
}

/*
 * �I�[�v�����Ă���|�[�g�����邩
 */
BOOL
smsc_sci0_openflag(void)
{
    return(siopcb_table[0].openflag);
}

/*
 * �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
smsc_sci0_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;


    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;

    fdc37c935a_init();
        
    /* Enable Receive Data Interrupt */
    sil_wrh_mem((VP)SMSC_SCI0_IER, (0x01 << 8));
    sil_wrh_mem((VP)SMSC_SCI0_MCR, 0x08 << 8);

    /*
     * MS7729RSE01�ł́C��x���M�����݂𔭐������Ă����Ȃ��Ɗ�����
     * ���x��16�̊����݂��������Ă��܂����������삵�Ȃ��D
     */
    /* ���M���荞�ݗv�������� */
    sil_wrh_mem((VP)SMSC_SCI0_IER,
                (((sil_reh_mem((VP)SMSC_SCI0_IER) >> 8) | 0x02) << 8));   
    /* ���M���荞�ݗv�����֎~ */        
    sil_wrh_mem((VP)SMSC_SCI0_IER,
                (((sil_reh_mem((VP)SMSC_SCI0_IER) >> 8) & ~0x02) << 8));   

    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
smsc_sci0_cls_por(SIOPCB *siopcb)
{
    sil_wrh_mem((VP)SMSC_SCI0_IER, 0x00);      /* �����݂̋֎~ */
    siopcb->openflag = FALSE;
}

/*
 * �V���A��I/O�|�[�g�ւ̃|�[�����O�ł̏o��
 */
void
fdc37c935a_pol_putc(char c)
{
    while(((sil_reh_mem((VP)SMSC_SCI0_LSR) >> 8) & 0x60) == 0)
        ;

    sil_wrh_mem((VP)SMSC_SCI0_THR, c << 8);
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
smsc_sci0_snd_chr(SIOPCB *siopcb, char c)
{
    if (smsc_sci0_putready(siopcb)){
        smsc_sci0_putchar(siopcb, c);
        return(TRUE);
    }
    return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
smsc_sci0_rcv_chr(SIOPCB *siopcb)
{
    if (smsc_sci0_getready(siopcb)) {
        return((INT)(UB) smsc_sci0_getchar(siopcb));
    }
    return(-1);
}


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
smsc_sci0_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{

    switch (cbrtn) {
        case SIO_ERDY_SND:
            smsc_sci0_enable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            smsc_sci0_enable_rcv(siopcb);
            break;
    }
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
smsc_sci0_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    switch (cbrtn) {
        case SIO_ERDY_SND:
            smsc_sci0_disable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            smsc_sci0_disable_rcv(siopcb);
            break;
    }
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���
 */
static void
smsc_sci0_isr_siop(SIOPCB *siopcb)
{
    if (smsc_sci0_getready(siopcb)) {
        /*
         *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
         */
        smsc_sci0_ierdy_rcv(siopcb->exinf);
    }
    if (smsc_sci0_putready(siopcb)) {
        /*
         *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
         */
        smsc_sci0_ierdy_snd(siopcb->exinf);
    }
}

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
smsc_sci0_isr()
{
    smsc_sci0_isr_siop(&(siopcb_table[0]));
}
