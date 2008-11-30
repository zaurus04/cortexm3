/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2005 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN    
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
 *  @(#) $Id: nios2.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 * Nios2 �W���y���t�F�����p�h���C�o
 */
#include <s_services.h>
#include <nios2.h>


/*
 * UART �p �ȈՃh���C�o
 */

/*                                                                       
 * �V���A��I/O�|�[�g�������u���b�N                                         
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {{}};

/*                                                                      
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A                                
 */
SIOPCB  siopcb_table[TNUM_SIOP];

/*                                                                          
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��                  
 */
#define INDEX_SIOP(siopid)  ((UINT)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))

#ifdef USE_JTAG_UART
/*
 *  JTAG_UART �̓X�e�[�^�X�ƃf�[�^�𓯎��Ɏ擾���邽�߁C�X�e�[�^�X��
 *  �`�F�b�N����ƃf�[�^��ǂݍ���ł��܂��D���̂��߁Cuart_getready()
 *  �����s������̃f�[�^������D  
 */ 
UB jtag_uart_buf = -1;
#endif /* USE_JTAG_UART */

/*
 * ��������M������?                                                       
 */
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART
	return((sil_rew_mem((VP)UART_STATUS) &
			UART_STATUS_RRDY) != 0);
#else
	UW tmp = sil_rew_mem((VP)JTAG_UART_DATA);
	jtag_uart_buf = (UB)tmp;	
	return ((tmp & JTAG_UART_DATA_RVALID) != 0);
#endif /* USE_JTAG_UART	*/	
}

/*                                                                             
 * �����𑗐M�ł��邩?                                                         
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART		
	return((sil_rew_mem((VP)UART_STATUS) & UART_STATUS_TRDY) != 0);
#else
	return((sil_rew_mem(
		(VP)JTAG_UART_CONTROL) & JTAG_UART_CONTROL_WSAPCE) > 0);
#endif /* USE_JTAG_UART	*/
}

/*                                                                             
 *  ��M���������̎��o��                                                     
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART
	return((UB)(sil_rew_mem((VP)UART_RXDATA)));
#else
	return((UB)(sil_rew_mem((VP)JTAG_UART_DATA)));
#endif /* USE_JTAG_UART	*/
}

/*                                                                            
 *  ���M���镶���̏�������                                                    
 */
Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
#ifndef USE_JTAG_UART
	sil_wrw_mem((VP)UART_TXDATA, c);
#else
	sil_wrw_mem((VP)JTAG_UART_DATA,c);
#endif /* USE_JTAG_UART	*/
}

/*
 * ���M����֐�
 */
/*                                                                             
 *  ���M�����݋���                                                             
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART
	sil_wrw_mem((VP)UART_CONTROL,
				sil_rew_mem((VP)UART_CONTROL)|UART_CONTROL_ITRD);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,
				sil_rew_mem((VP)JTAG_UART_CONTROL)|JTAG_UART_CONTROL_WIE);
#endif /* USE_JTAG_UART	*/	
}

/*                                                                             
 *  ���M�����݋֎~                                                             
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART
	sil_wrw_mem((VP)UART_CONTROL,
				sil_rew_mem((VP)UART_CONTROL)&~UART_CONTROL_ITRD);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,
				sil_rew_mem((VP)JTAG_UART_CONTROL)&~JTAG_UART_CONTROL_WIE);
#endif /* USE_JTAG_UART	*/
}

/*
 * ��M����֐�
 */
/*                                                                             
 *  ��M�����݋���                                                             
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART
	sil_wrw_mem((VP)UART_CONTROL,
				sil_rew_mem((VP)UART_CONTROL)|UART_STATUS_RRDY);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,
				sil_rew_mem((VP)JTAG_UART_CONTROL)|JTAG_UART_CONTROL_RIE);
#endif /* USE_JTAG_UART	*/
}

/*                                                                             
 *  ��M�����݋֎~                                                             
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
#ifndef USE_JTAG_UART	
	sil_wrw_mem((VP)UART_CONTROL,
				sil_rew_mem((VP)UART_CONTROL)&~UART_STATUS_RRDY);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,
				sil_rew_mem((VP)JTAG_UART_CONTROL)&~JTAG_UART_CONTROL_RIE);
#endif /* USE_JTAG_UART	*/	
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


SIOPCB   *
uart_opn_por(ID siopid, VP_INT exinf){

    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;

    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;

#ifndef USE_JTAG_UART		
//    sil_wrw_mem(UART_DIVISOR, UART_DIVISOR_VAL);
    sil_wrw_mem((VP)UART_STATUS, 0x00);
    
    /*
     *  ��M���荞�݋���
     */
    sil_wrw_mem((VP)UART_CONTROL, UART_STATUS_RRDY);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,JTAG_UART_CONTROL_RIE);
#endif /* USE_JTAG_UART	*/
	
    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    return(siopcb);
}


void
uart_cls_por(SIOPCB *siopcb){
#ifndef USE_JTAG_UART	
    /* �����݋֎~ */
    sil_wrw_mem((VP)UART_CONTROL, 0x00);
#else
	sil_wrw_mem((VP)JTAG_UART_CONTROL,0x00);
#endif /* USE_JTAG_UART	*/		
    siopcb->openflag = FALSE;
    siopcb->sendflag = FALSE;
}



/*                                                                             
 *  �V���A��I/O�|�[�g�ւ̕������M                                            
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, INT chr)
{
    if(uart_putready(siopcb)){
        uart_putchar(siopcb, (UB) chr);
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
#ifndef USE_JTAG_UART
	if (uart_getready(siopcb)) {
		return((INT)(UB) uart_getchar(siopcb));
	}
	return(-1);
#else
	UB tmp;
	
	if (jtag_uart_buf != -1) {
		tmp = jtag_uart_buf;
		jtag_uart_buf = -1;
		return tmp;
	}
	return(-1);
#endif /* USE_JTAG_UART	*/	
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
uart_isr()
{
    if (siopcb_table[0].openflag) {
        uart_isr_siop(&(siopcb_table[0]));
    }
}

