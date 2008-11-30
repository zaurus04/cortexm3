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
 *  @(#) $Id: nios2.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#ifndef _NIOSII_H_
#define _NIOSII_H_

#ifndef _MACRO_ONLY
#include <itron.h>
#endif /* _MACRO_ONLY */

/*
 *  �����݃r�b�g
 */
#define STATUS_U   0x02
#define STATUS_PIE 0x01

/*
 * �����݂̐�
 */
#define MAX_INT_NUM 32

/*
 * ��O�̌�
 */
#define MAX_EXC_NUM 32


/*
 *  Timer
 *  Full-featured�T�|�[�g 
 */

/*
 * �I�t�Z�b�g�l
 */
#define TIM_STATUS_OFFSET  0x00
#define TIM_CONTROL_OFFSET 0x04
#define TIM_PERIODL_OFFSET 0x08
#define TIM_PERIODH_OFFSET 0x0C
#define TIM_SNAPL_OFFSET 0x10
#define TIM_SNAPH_OFFSET 0x14

#define TIM_STATUS_RUN 0x02
#define TIM_STATUS_TO  0x01

#define TIM_CONTROL_STOP  0x08
#define TIM_CONTROL_START 0x04
#define TIM_CONTROL_COUNT 0x02
#define TIM_CONTROL_ITO   0x01

/*
 *
 */
#define TIM_STATUS  (TIM_BASE + TIM_STATUS_OFFSET)
#define TIM_CONTROL (TIM_BASE + TIM_CONTROL_OFFSET)
#define TIM_PERIODL (TIM_BASE + TIM_PERIODL_OFFSET)
#define TIM_PERIODH (TIM_BASE + TIM_PERIODH_OFFSET)
#define TIM_SNAPL   (TIM_BASE + TIM_SNAPL_OFFSET)
#define TIM_SNAPH   (TIM_BASE + TIM_SNAPH_OFFSET)


/*
 * UART
 */
#define UART_RXDATA_OFFSET  0x00
#define UART_TXDATA_OFFSET  0x04
#define UART_STATUS_OFFSET  0x08
#define UART_CONTROL_OFFSET 0x0C
#define UART_DIVISOR_OFFSET 0x10
#define UART_ENDOFPACKET_OFFSET 0x1C

#define UART_STATUS_EOP   0x1000
#define UART_STATUS_CTS   0x0800
#define UART_STATUS_DCTS  0x0400
#define UART_STATUS_E     0x0100
#define UART_STATUS_RRDY  0x0080
#define UART_STATUS_TRDY  0x0040
#define UART_STATUS_TMT   0x0020
#define UART_STATUS_TOE   0x0010
#define UART_STATUS_ROE   0x0008
#define UART_STATUS_BRK   0x0004
#define UART_STATUS_FE    0x0002
#define UART_STATUS_PE    0x0001

#define UART_CONTROL_IEOP  0x1000
#define UART_CONTROL_RTS   0x0800
#define UART_CONTROL_IDCTS 0x0400
#define UART_CONTROL_TRDK  0x0200
#define UART_CONTROL_IE    0x0100
#define UART_CONTROL_IRRDY 0x0080
#define UART_CONTROL_ITRD  0x0040
#define UART_CONTROL_ITMT  0x0020
#define UART_CONTROL_ITOE  0x0010
#define UART_CONTROL_IROE  0x0008
#define UART_CONTROL_IBRK  0x0004
#define UART_CONTROL_IFE   0x0002
#define UART_CONTROL_IPE   0x0001

#define UART_RXDATA  (UART_BASE + UART_RXDATA_OFFSET)
#define UART_TXDATA  (UART_BASE + UART_TXDATA_OFFSET)
#define UART_STATUS  (UART_BASE + UART_STATUS_OFFSET)
#define UART_CONTROL (UART_BASE + UART_CONTROL_OFFSET)
#define UART_DIVISOR (UART_BASE + UART_DIVISOR_OFFSET)
#define UART_ENDOFPACKET (UART_BASE + UART_ENDOFPACKET_OFFSET)


/*
 * JTAG UART�֘A
 */ 
#define JTAG_UART_DATA_OFFSET    0x00
#define JTAG_UART_CONTROL_OFFSET 0x04

#define JTAG_UART_DATA_RVALID 0x8000

#define JTAG_UART_CONTROL_RIE 0x01
#define JTAG_UART_CONTROL_WIE 0x02
#define JTAG_UART_CONTROL_RIP 0x04
#define JTAG_UART_CONTROL_WIP 0x08
#define JTAG_UART_CONTROL_WSAPCE 0x0ffff0000

#define JTAG_UART_DATA    (UART_BASE + JTAG_UART_DATA_OFFSET)
#define JTAG_UART_CONTROL (UART_BASE + JTAG_UART_CONTROL_OFFSET)


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
#ifndef USE_JTAG_UART	
	while(!(sil_rew_mem((VP)UART_STATUS) & UART_STATUS_TRDY));
	sil_wrw_mem((VP)UART_TXDATA, c);
#else
	while(!((sil_rew_mem((VP)JTAG_UART_CONTROL) & JTAG_UART_CONTROL_WSAPCE) > 0));
	sil_wrw_mem((VP)JTAG_UART_DATA, c);	
#endif /* USE_JTAG_UART	*/	
}

Inline unsigned char
uart_getc(void){
#ifndef USE_JTAG_UART	
	while(!(sil_rew_mem((VP)UART_STATUS) & UART_STATUS_RRDY));
	return (char)(sil_rew_mem((VP)UART_RXDATA));
#else
	int tmp;
	do{
		tmp = sil_rew_mem((VP)JTAG_UART_DATA);
	}while((tmp &JTAG_UART_DATA_RVALID) == 0);

	return (char)tmp;
#endif /* USE_JTAG_UART	*/			
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

#endif /* _NIOSII_H_ */

