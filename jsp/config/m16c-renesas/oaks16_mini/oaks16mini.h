/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 * 
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă��� 
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
 *  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
 *      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
 *      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
 *      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
 *      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
 *        ���ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
 *  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
 *  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
 *  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: oaks16mini.h,v 1.1 2008/06/17 00:04:55 suikan Exp $
 */

#ifndef _OAKS16MINI_H_
#define	_OAKS16MINI_H_

/*
 *  �����ݔԍ��̒�`
 */
#define	INT_BRK         0			/* BRK */
#define INT_DMA0        11			/* DMA0 */
#define INT_DMA1        12			/* DMA1 */
#define INT_KEY         13			/* �L�[���͊��荞�� */
#define INT_AD          14			/* �`-�c�ϊ��� */
#define INT_S0T         17			/* UART0���M */
#define INT_S0R         18			/* UART0��M */
#define INT_S1T         19			/* UART1���M */
#define INT_S1R         20			/* UART1��M */
#define INT_TA0         21			/* �^�C�}A0 */
#define INT_TA1         22			/* �^�C�}A1 */
#define INT_TA2         23			/* �^�C�}A2 */
#define INT_TA3         24			/* �^�C�}A3 */
#define INT_TA4         25			/* �^�C�}A4 */
#define INT_TB0         26			/* �^�C�}B0 */
#define INT_TB1         27			/* �^�C�}B1 */
#define INT_TB2         28			/* �^�C�}B2 */
#define INT_INT0        29			/* INT0 */
#define INT_INT1        30			/* INT1 */

/*
 *  OAKS16 MINI SFR�A�h���X��`
 *
 *  �����݃��W�X�^
 */
#define	TADR_SFR_INT_BASE       0x040			/* �����݊֘A�̃x�[�X�A�h���X */
#define TADR_SFR_DMA0IC_OFFSET  11				/* DMA0�����ݐ��䃌�W�X�^ */
#define TADR_SFR_DMA1IC_OFFSET  12				/* DMA1�����ݐ��䃌�W�X�^ */
#define TADR_SFR_KUPIC_OFFSET   13				/* �L�[���͊����ݐ��䃌�W�X�^ */
#define TADR_SFR_ADIC_OFFSET    14				/* A-D�ϊ������ݐ��䃌�W�X�^ */
#define	TADR_SFR_S0TIC_OFFSET   17				/* uart0���M�����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S0RIC_OFFSET   18				/* uart0��M�����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S1TIC_OFFSET   19				/* uart1���M�����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S1RIC_OFFSET   20				/* uart1��M�����ݐ��䃌�W�X�^ */
#define	TADR_SFR_TA0IC_OFFSET   21				/* timerA0 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_TA1IC_OFFSET   22				/* timerA1 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_TA2IC_OFFSET   23				/* timerA2 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_TA3IC_OFFSET   24				/* timerA3 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_TA4IC_OFFSET   25				/* timerA4 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_TB0IC_OFFSET   26				/* timerB0 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_TB1IC_OFFSET   27				/* timerB1 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_TB2IC_OFFSET   28				/* timerB2 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_INT0IC_OFFSET  29				/* INT0 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_INT1IC_OFFSET  30				/* INT1 �����ݐ��䃌�W�X�^ */

/*
 *  DMA���W�X�^
 */
#define TADR_SFR_SAR0           0x020			/* DMA0�\�[�X�|�C���^ */
#define TADR_SFR_DAR0           0x024			/* DMA0�f�X�e�B�l�[�V�����|�C���^ */
#define TADR_SFR_TCR0			0x028			/* DMA0�]���J�E���^ */
#define TADR_SFR_DM0CON         0x02c			/* DMA0���䃌�W�X�^ */
#define TADR_SFR_SAR1           0x030			/* DMA1�\�[�X�|�C���^ */
#define TADR_SFR_DAR1           0x034			/* DMA1�f�X�e�B�l�[�V�����|�C���^ */
#define TADR_SFR_TCR1			0x038			/* DMA1�]���J�E���^ */
#define TADR_SFR_DM1CON         0x03c			/* DMA1���䃌�W�X�^ */

/*
 *  �^�C�}�[���W�X�^
 */
#define TADR_SFR_TA11           0x342			/* timerA1-1���W�X�^ */
#define TADR_SFR_TA21           0x344			/* timerA2-1���W�X�^ */
#define TADR_SFR_TA41           0x346			/* timerA4-1���W�X�^ */
#define TADR_SFR_INVC0          0x348			/* �O��PWM���䃌�W�X�^�O */
#define TADR_SFR_INVC1          0x349			/* �O��PWM���䃌�W�X�^�P */
#define TADR_SFR_IDB0           0x34a			/* �O���o�̓o�b�t�@���W�X�^�O */
#define TADR_SFR_IDB1           0x34b			/* �O���o�̓o�b�t�@���W�X�^�P */
#define TADR_SFR_DTT            0x34c			/* �Z���h�~�^�C�} */
#define TADR_SFR_ICTB2          0x34d			/* timerB2�����ݔ����p�x�ݒ�J�E���^ */
#define TADR_SFR_IFSR           0x35f			/* �����ݗv���I�����W�X�^ */

#define	TADR_SFR_TABSR          0x380			/* �J�E���g�J�n�t���O */
#define TADR_SFR_CPSRF          0x381			/* ���Z�b�g �v���X�P�[�� ���Z�b�g�t���O */
#define TADR_SFR_ONSF           0x382			/* �����V���g �X�^�[�g�t���O */
#define TADR_SFR_TRGSR          0x383			/* �g���K�[�Z���N�g ���W�X�^ */
#define	TADR_SFR_UDF            0x384			/* �A�b�v�_�E���t���O */
#define	TADR_SFR_TA0            0x386			/* timerA0���W�X�^ */
#define TADR_SFR_TA1            0x388			/* timerA1���W�X�^ */
#define TADR_SFR_TA2            0x38a			/* timerA2���W�X�^ */
#define TADR_SFR_TA3            0x38c			/* timerA3���W�X�^ */
#define TADR_SFR_TA4            0x38e			/* timerA4���W�X�^ */
#define TADR_SFR_TB0            0x390			/* timerB0���W�X�^ */
#define TADR_SFR_TB1            0x392			/* timerB1���W�X�^ */
#define TADR_SFR_TB2            0x394			/* timerB2���W�X�^ */
#define	TADR_SFR_TA0MR          0x396			/* timerA0���[�h���W�X�^ */
#define	TADR_SFR_TA1MR          0x397			/* timerA1���[�h���W�X�^ */
#define	TADR_SFR_TA2MR          0x398			/* timerA2���[�h���W�X�^ */
#define	TADR_SFR_TA3MR          0x399			/* timerA3���[�h���W�X�^ */
#define	TADR_SFR_TA4MR          0x39a			/* timerA4���[�h���W�X�^ */
#define	TADR_SFR_TB0MR          0x39b			/* timerB0���[�h���W�X�^ */
#define	TADR_SFR_TB1MR			0x39c			/* timerB1���[�h���W�X�^ */
#define	TADR_SFR_TB2MR          0x39d			/* timerB2���[�h���W�X�^ */
#define	TADR_SFR_TB2SR          0x39e			/* timerB2�X�y�V�������[�h���W�X�^ */

/*
 *  �V���A�����W�X�^
 */
#define	TADR_SFR_UART0_BASE     0x3a0			/* uart0���W�X�^�x�[�X�A�h���X */
#define	TADR_SFR_UART1_BASE     0x3a8			/* uart1���W�X�^�x�[�X�A�h���X */

#define	TADR_SFR_UMR_OFFSET     0				/* uart����M���[�h���W�X�^ */
#define	TADR_SFR_UBRG_OFFSET    1				/* uart�{�[���[�g�W�F�l���[�^ */
#define	TADR_SFR_UTB_OFFSET     2				/* uart���M�o�b�t�@���W�X�^ */
#define	TADR_SFR_UC0_OFFSET     4				/* uart����M���䃌�W�X�^#0 */
#define	TADR_SFR_UC1_OFFSET     5				/* uart����M���䃌�W�X�^#1 */
#define	TADR_SFR_URB_OFFSET     6				/* uart��M�o�b�t�@���W�X�^ */
#define	TADR_SFR_UC2_OFFSET     16				/* uart����M���䃌�W�X�^#2 */

/*
 *  �ėp�|�[�g���W�X�^
 */
#define TADR_SFR_P1             0x3e1           /* �|�[�gP1���W�X�^ */
#define TADR_SFR_PD1            0x3e3			/* �|�[�gP1�������W�X�^ */
#define TADR_SFR_P6             0x3ec			/* �|�[�gP6���W�X�^ */
#define	TADR_SFR_P7             0x3ed			/* �|�[�gP7���W�X�^ */
#define	TADR_SFR_PD6            0x3ee			/* �|�[�gP6�������W�X�^ */
#define	TADR_SFR_PD7            0x3ef			/* �|�[�gP7�������W�X�^ */
#define	TADR_SFR_P8             0x3f0			/* �|�[�gP8���W�X�^ */
#define TADR_SFR_P9             0x3f1			/* �|�[�gP9���W�X�^ */
#define	TADR_SFR_PD8            0x3f2			/* �|�[�gP8�������W�X�^ */
#define TADR_SFR_PD9            0x3f3			/* �|�[�gP9�������W�X�^ */
#define TADR_SFR_P10            0x3f4			/* �|�[�gP10���W�X�^ */
#define TADR_SFR_PD10           0x3f6			/* �|�[�gP10�������W�X�^ */
#define	TADR_SFR_PUR0           0x3fc			/* �v���A�b�v���䃌�W�X�^�O */
#define	TADR_SFR_PUR1           0x3fd			/* �v���A�b�v���䃌�W�X�^�P */
#define	TADR_SFR_PUR2           0x3fe			/* �v���A�b�v���䃌�W�X�^�Q */
#define	TADR_SFR_PCR            0x3ff			/* �|�[�g���䃌�W�X�^ */

/*
 *  ����M���䃌�W�X�^1 (UART0,UART1)
 */
#define	TBIT_UiC1_RI	0x08	/* ��M�����t���O */
#define	TBIT_UiC1_RE	0x04	/* ��M���r�b�g */
#define	TBIT_UiC1_TI	0x02	/* ���M�o�b�t�@��t���O */
#define	TBIT_UiC1_TE	0x01	/* ���M���r�b�g */

#define TBIT_UiC0_TXEPT	0x08	/* ���M���W�X�^��t���O */

/*
 *  �����ݐ��䃌�W�X�^
 */
#define	TBIT_TAiIC_IR	0x08

/*
 *  �J�E���g�J�n�t���O (TABSR)
 */
#define TBIT_TABSR_TA0S	0x01

/*
 *  �A�b�v�_�E���t���O(UDF)
 */
#define TBIT_UDF_TA0UD	0x01

/*
 *  �|�[�g�V�ݒ�
 */
#define	P7_LED1					0x10			/* LED1�r�b�g��` */
#define	P7_LED2					0x20			/* LED2�r�b�g��` */

/*
 *  �|�[�g�W�ݒ�
 */
#define	P8_SW1					0x01			/* SW1�r�b�g��` */
#define	P8_SW2					0x02			/* SW2�r�b�g��` */

#ifndef _MACRO_ONLY

#include "cpu_defs.h"

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */

Inline void
oaks16_putc(char c)
{
	volatile char * p = (volatile char *)TADR_SFR_UART1_BASE;

	while((p[TADR_SFR_UC1_OFFSET] & TBIT_UiC1_TI) == 0);
	p[TADR_SFR_UTB_OFFSET] = c;
}

#endif /* _MACRO_ONLY */
#endif /* _OAKS16MINI_H_ */

