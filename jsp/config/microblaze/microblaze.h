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
 *  @(#) $Id: microblaze.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#ifndef _MICROBLAZE_H_
#define _MICROBLAZE_H_



#ifndef _MACRO_ONLY
#include <itron.h>
#include <sil.h>
#endif /* _MACRO_ONLY */


/*
 *  MSR�̃r�b�g
 */
#define MSR_CC  0x80000000
#define MSR_DCE 0x80
#define MSR_DZ  0x40
#define MSR_ICE 0x20
#define MSR_FSL 0x10
#define MSR_BIP 0x08
#define MSR_C   0x04
#define MSR_IE  0x02
#define MSR_BE  0x01


/*
 * INTC Registers
 */
#define INTC_INT_STATUS_REG    0x00
#define INTC_INT_PENDING_REG   0x04
#define INTC_INT_ENABLE_REG    0x08
#define INTC_INT_ACK_REG       0x0c
#define INTC_SET_INT_ENABLE    0x10
#define INTC_CLEAR_INT_ENABLE  0x14
#define INTC_INT_VECTOR_REG    0x18
#define INTC_MASTER_ENABLE_REG 0x1c

/* 
 * Masks for the INTC Registers
 */
#define INTC_HIE_MASK 0x2
#define INTC_ME_MASK  0x1



#define INTC_ISR (INTC_BASE + INTC_INT_STATUS_REG)
#define INTC_IPR (INTC_BASE + INTC_INT_PENDING_REG)
#define INTC_IER (INTC_BASE + INTC_INT_ENABLE_REG)
#define INTC_IAR (INTC_BASE + INTC_INT_ACK_REG)
#define INTC_SIE (INTC_BASE + INTC_SET_INT_ENABLE)
#define INTC_CIE (INTC_BASE + INTC_CLEAR_INT_ENABLE)
#define INTC_IVR (INTC_BASE + INTC_INT_VECTOR_REG)
#define INTC_MER (INTC_BASE + INTC_MASTER_ENABLE_REG)

#ifndef _MACRO_ONLY
/*
 *  INTC����֐�
 */
Inline void
intc_start(void){
  sil_wrw_mem((VP)INTC_MER, INTC_HIE_MASK | INTC_ME_MASK);
}

Inline void
intc_disable_allinterrupt(){
  sil_wrw_mem((VP)INTC_MER, 0);
}

Inline void
intc_enable_interrupt(UW mask)
{
  sil_wrw_mem((VP)INTC_SIE, mask);
}

Inline void
intc_disable_interrupt(UW mask)
{
  sil_wrw_mem((VP)INTC_CIE, mask);
}

Inline void
intc_ack_interrupt(UW mask)
{
  sil_wrw_mem((VP)INTC_IAR, mask);
}

#endif /* _MACRO_ONLY */



/*
 * �^�C�}�h���C�o�p�̃}�N����`
 */


/*
 * Masks for the control/status register
 */
#define TIMER_ENABLE_ALL    0x400
#define TIMER_PWM           0x200
#define TIMER_INTERRUPT     0x100
#define TIMER_ENABLE        0x080
#define TIMER_ENABLE_INTR   0x040
#define TIMER_RESET         0x020
#define TIMER_RELOAD        0x010
#define TIMER_EXT_CAPTURE   0x008
#define TIMER_EXT_COMPARE   0x004
#define TIMER_DOWN_COUNT    0x002
#define TIMER_CAPTURE_MODE  0x001

#define TIMER_CONTROL_STATUS_0  0x0
#define TIMER_COMPARE_CAPTURE_0 0x4
#define TIMER_COUNTER_0         0x8
#define TIMER_CONTROL_STATUS_1  0x10
#define TIMER_COMPARE_CAPTURE_1 0x14
#define TIMER_COUNTER_1         0x18


#define TIMER_TCSR0 (TIMER_BASE + TIMER_CONTROL_STATUS_0)
#define TIMER_TCCR0 (TIMER_BASE + TIMER_COMPARE_CAPTURE_0)
#define TIMER_TCR0  (TIMER_BASE + TIMER_COUNTER_0)
#define TIMER_TCSR1 (TIMER_BASE + TIMER_CONTROL_STATUS_1)
#define TIMER_TCCR1 (TIMER_BASE + TIMER_COMPARE_CAPTURE_1)
#define TIMER_TCR1  (TIMER_BASE + TIMER_COUNTER_1)


/*
 *  UART�h���C�o�p�̃}�N����`
 */

/*
 * Error condition masks 
 */
#define UARTLITE_PAR_ERROR     0x80
#define UARTLITE_FRAME_ERROR   0x40
#define UARTLITE_OVERRUN_ERROR 0x20


/*
 * Other status bit masks
 */
#define UARTLITE_INTR_ENABLED       0x10
#define UARTLITE_TX_FIFO_FULL       0x08
#define UARTLITE_TX_FIFO_EMPTY      0x04
#define UARTLITE_RX_FIFO_FULL       0x02
#define UARTLITE_RX_FIFO_VALID_DATA 0x01

/*
 * Control bit masks 
 */
#define UARTLITE_ENABLE_INTR  0x10
#define UARTLITE_RST_RX_FIFO  0x02
#define UARTLITE_RST_TX_FIFO  0x01

/*
 * UARTLITE Registers
 */
#define UARTLITE_RECEIVE_REG  0x0
#define UARTLITE_TRANSMIT_REG 0x4
#define UARTLITE_STATUS_REG   0x8
#define UARTLITE_CONTROL_REG  0xc


#define UARTLITE_RXREG (UART_BASE + UARTLITE_RECEIVE_REG)
#define UARTLITE_TXREG (UART_BASE + UARTLITE_TRANSMIT_REG)
#define UARTLITE_SRREG (UART_BASE + UARTLITE_STATUS_REG)
#define UARTLITE_CTREG (UART_BASE + UARTLITE_CONTROL_REG)



#ifndef _MACRO_ONLY
/*                                                                          
 * ����UART�p �Ȉ�SIO�h���C�o                                                 
 */

/*                                                                            
 *  �V���A��I/O�|�[�g�������u���b�N                                         
 */
typedef struct sio_port_initialization_block {

} SIOPINIB;

/*                                                                            
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N                                            
 */
typedef struct sio_port_control_block {
    const SIOPINIB  *siopinib;  /* �V���A��I/O�|�[�g�������u���b�N */
    VP_INT          exinf;      /* �g����� */
    BOOL    openflag;           /* �I�[�v���ς݃t���O */
    BOOL    sendflag;           /* ���M�����݃C�l�[�u���t���O */
    BOOL    getready;           /* ��������M������� */
    BOOL    putready;           /* �����𑗐M�ł����� */
} SIOPCB;

extern SIOPCB   siopcb_table[];

#define uart_openflag   (siopcb_table[0].openflag)

Inline void
uart_putc(unsigned char c){
  while(sil_rew_mem((VP)UARTLITE_SRREG) & UARTLITE_TX_FIFO_FULL);
  sil_wrw_mem((VP)UARTLITE_TXREG, c);
}

Inline unsigned char
uart_getc(void){
  while(!(sil_rew_mem((VP)UARTLITE_SRREG) & UARTLITE_RX_FIFO_VALID_DATA));
  return (char)(sil_rew_mem((VP)UARTLITE_RXREG));
}

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 *  OPB_UARTLITE �́C����M�����݂�������Ă��Ȃ����߁C�Ӗ��͂Ȃ��D
 */
#define SIO_ERDY_SND    1u              /* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV    2u              /* ��M�ʒm�R�[���o�b�N */


/*                                                                           
 *  SIO�h���C�o�̏��������[�`��                                                
 */
extern void uart_initialize(void);


/*                                                                           
 *  �V���A��I/O�|�[�g�̃I�[�v��                                              
 */
extern SIOPCB   *uart_opn_por(ID siopid, VP_INT exinf);

/*                                                                         
 *  �V���A��I/O�|�[�g�̃N���[�Y                                             
 */
extern void uart_cls_por(SIOPCB *siopcb);

/*                                                                            
 *  �V���A��I/O�|�[�g�ւ̕������M                                            
 */
extern BOOL uart_snd_chr(SIOPCB *siopcb, INT chr);

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT  uart_rcv_chr(SIOPCB *siopcb);


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn);


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn);


/*                                                                            
 *  SIO�̊����݃T�[�r�X���[�`��                                              
 */
extern void uart_isr(void);


/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void uart_ierdy_snd(VP_INT exinf);


/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void uart_ierdy_rcv(VP_INT exinf);




#endif  /* _MACRO_ONLY */

#endif /* _MICROBLAZE_H_*/

