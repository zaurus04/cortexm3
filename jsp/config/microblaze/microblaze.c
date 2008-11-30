/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: microblaze.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*                                                                              * Microblaze �W���y���t�F�����p�h���C�o
 */
#include <s_services.h>
#include <microblaze.h>


/*
 * UART Lite�p �ȈՃh���C�o
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

Inline void
uart_ena_int(void){
  sil_wrw_mem((VP)UARTLITE_CTREG,
              sil_rew_mem((VP)UARTLITE_CTREG) | UARTLITE_ENABLE_INTR);
}

Inline void
uart_dis_int(void){
  sil_wrw_mem((VP)UARTLITE_CTREG,
              sil_rew_mem((VP)UARTLITE_CTREG) & ~UARTLITE_ENABLE_INTR);
}

/*
 * ��������M������?                                                       
 */
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
    return((sil_rew_mem((VP)UARTLITE_SRREG) &
            UARTLITE_RX_FIFO_VALID_DATA) != 0);

}

/*                                                                             
 * �����𑗐M�ł��邩?                                                         
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
  return((sil_rew_mem((VP)UARTLITE_SRREG) & UARTLITE_TX_FIFO_FULL) == 0);
}

/*                                                                             
 *  ��M���������̎��o��                                                     
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
    return((UB)sil_rew_mem((VP)UARTLITE_RXREG));
}

/*                                                                            
 *  ���M���镶���̏�������                                                    
 */
Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
  sil_wrw_mem((VP)UARTLITE_TXREG, c);
}

/*
 * ���M����֐�
 * UART Lite �ɂ͑��M�����݂��ʂɋ֎~������@�\�͂Ȃ�
 * ���̂��߁C���M�I�����ɂ͕K��1�񊄍��݂�����  
 */
/*                                                                             
 *  ���M�����݋���                                                             
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
  
}

/*                                                                             
 *  ���M�����݋֎~                                                             
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{

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

    /*
     *  ����M�o�b�t�@�N���A
     */
    sil_wrw_mem((VP)UARTLITE_CTREG, UARTLITE_RST_RX_FIFO
                | UARTLITE_RST_TX_FIFO | UARTLITE_ENABLE_INTR);
    
//    sil_wrw_mem((VP)UARTLITE_CTREG, UARTLITE_RST_RX_FIFO
//                | UARTLITE_RST_TX_FIFO );
    
    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    return(siopcb);
}


void
uart_cls_por(SIOPCB *siopcb){
  sil_wrw_mem((VP)UARTLITE_CTREG, ~UARTLITE_ENABLE_INTR);   /* �����݋֎~    */
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
    if (uart_getready(siopcb)) {
        return((INT)(UB) uart_getchar(siopcb));
    }
    return(-1);
}

/*
 *  OPB_UARTLITE �͑��M�Ǝ�M�����݂��ʂɋ���/�֎~����@�\�͎����Ȃ�
 */

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{

}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{

}


/*                                                                            
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���                                       
 */
static void
uart_isr_siop(SIOPCB *siopcb)
{
    /*
     * �G�b�W�����݂̂��ߊ����ݏ����O��ACK
     */
    intc_ack_interrupt(1 << (UARTINTLVL - 1));
    
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

