/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *  @(#) $Id: uart.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *  �񓯊��ʐM (UART)�V���A���`�����l���f�o�C�X�iSIO�j�h���C�o
 *  �iZup-F16�g���{�[�h�p�j
 */

#ifndef _UART_H_
#define _UART_H_

/*
 * �V���A���R���g���[�����W�X�^�̐ݒ�l 
 */
/* 19200bps = (6144000*4)/4/(BRCK)/(BRS+(16-BRK)/16)/16	*/
/* BRCK=4����,BRS=5�J�E���g,+(16-BRK)/16 �͖��g�p */
#define	BRCR_19200  	(TBIT_SIOBRCK2 | 5)
#define	BRADD_19200		0
/* 38400bps = (6144000*4)/4/(BRCK)/(BRS+(16-BRK)/16)/16	*/
/* BRCK=1����,BRS=10�J�E���g,+(16-BRK)/16 �͖��g�p */
#define	BRCR_38400		(TBIT_SIOBRCK0 | 10)
#define	BRADD_38400		0
#define	INT_LEVEL_UART	5		/* �����݃��x�� */

/*
 *  �V���A��I/O�̊����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_SERIAL_IN1	INT_NO_RX1
#define	INHNO_SERIAL_OUT1	INT_NO_TX1
#define INHNO_SERIAL_IN2	INT_NO_RX0
#define INHNO_SERIAL_OUT2	INT_NO_TX0

#ifndef _MACRO_ONLY

/*
 *  �V���A��I/O�|�[�g�������u���b�N�̒�`
 */
typedef struct sio_port_initialization_block {
	UH  cntrl;		/* �R���g���[�����W�X�^�̔Ԓn */
	UH  hint;		/* �����݃��W�X�^�̔Ԓn */

	UB  pcrfc_def;		/* �f�t�H�[���g�̐ݒ�l (P9CR/P9FC) */
	UB  scmod0_def;		/* �f�t�H�[���g�̐ݒ�l (SCMOD0)	*/
	UB  sccr_def;		/* �f�t�H�[���g�̐ݒ�l (SCCR)		*/
	UB  brcr_def;		/* �f�t�H�[���g�̐ݒ�l (BRCR)		*/
	UB  bradd_def;		/* �f�t�H�[���g�̐ݒ�l (BRADD)		*/
	UB  int_clr;		/* �����ݗv���t���O�N���A�R�}���h	*/
} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
typedef struct sio_port_control_block {
	const SIOPINIB	*siopinib;	/* �V���A��I/O�|�[�g�������u���b�N */
	VP_INT			exinf;		/* �g����� */
	INT				rxb;		/* ��M�o�b�t�@	*/
	volatile UB		sts_flag;	/* ���M�o�b�t�@��t���O	*/
} SIOPCB;

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define UART_ERDY_SND		1u			/* ���M�\�R�[���o�b�N			*/
#define UART_ERDY_RCV		2u			/* ��M�ʒm�R�[���o�b�N			*/

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void	uart_initialize(void);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB * uart_opn_por(ID siopid, VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void	uart_cls_por(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL	uart_snd_chr(SIOPCB *siopcb, char c);

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT	uart_rcv_chr(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void	uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void	uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void	uart_ierdy_snd(VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void	uart_ierdy_rcv(VP_INT exinf);

#endif /* _MACRO_ONLY */
#endif /* _UART_H_ */

