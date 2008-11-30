/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
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
 *  @(#) $Id: oaks32.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

#ifndef _OAKS32_H_
#define	_OAKS32_H_

/*
 *  �����ݔԍ��̒�`
 */
#define	INT_BRK		0		/* BRK */
#define INT_AD1		7		/* �`-�c�ϊ���1 */
#define INT_DMA0	8		/* DMA0 */
#define INT_DMA1	9		/* DMA1 */
#define INT_DMA2	10		/* DMA2 */
#define INT_DMA3	11		/* DMA3 */
#define INT_TA0		12		/* �^�C�}A0 */
#define INT_TA1		13		/* �^�C�}A1 */
#define INT_TA2		14		/* �^�C�}A2 */
#define INT_TA3		15		/* �^�C�}A3 */
#define INT_TA4		16		/* �^�C�}A4 */
#define INT_S0TNACK	17		/* UART0���M,NACK */
#define INT_S0RACK	18		/* UART0��M,ACK */
#define INT_S1TNACK	19		/* UART1���M,NACK */
#define INT_S1RACK	20		/* UART1��M,ACK */
#define INT_TB0		21		/* �^�C�}B0 */
#define INT_TB1		22		/* �^�C�}B1 */
#define INT_TB2		23		/* �^�C�}B2 */
#define INT_TB3		24		/* �^�C�}B3 */
#define INT_TB4		25		/* �^�C�}B4 */
#define INT_INT5	26		/* INT5 */
#define INT_INT4	27		/* INT4 */
#define INT_INT3	28		/* INT3 */
#define INT_INT2	29		/* INT2 */
#define INT_INT1	30		/* INT1 */
#define INT_INT0	31		/* INT0 */
#define INT_TB5		32		/* �^�C�}B5 */
#define INT_S2TNACK 	33		/* UART2���M,NACK */
#define INT_S2RACK 	34		/* UART2��M,ACK */
#define INT_S3TNACK 	35		/* UART3���M,NACK */
#define INT_S3RACK 	36		/* UART3��M,ACK */
#define INT_S4TNACK 	37		/* UART4���M,NACK */
#define INT_S4RACK 	38		/* UART4��M,ACK */

#define INT_AD0		42		/* �`-�c�ϊ���0 */
#define INT_KEY		43		/* �L�[���͊��荞�� */
#define INT_IIO0	44		/* �C���e���W�F���gI/O������0 */
#define INT_IIO1	45		/* �C���e���W�F���gI/O������1 */
#define INT_IIO2	46		/* �C���e���W�F���gI/O������2 */
#define INT_IIO3	47		/* �C���e���W�F���gI/O������3 */
#define INT_IIO4	48		/* �C���e���W�F���gI/O������4 */
#define INT_IIO5	49		/* �C���e���W�F���gI/O������5 */
#define INT_IIO6	50		/* �C���e���W�F���gI/O������6 */
#define INT_IIO7	51		/* �C���e���W�F���gI/O������7 */
#define INT_IIO8	52		/* �C���e���W�F���gI/O������8 */
#define INT_IIO9CAN0	53		/* �C���e���W�F���gI/O������9,CAN0 */
#define INT_IIO10CAN1	54		/* �C���e���W�F���gI/O������10,CAN1 */
#define INT_IIO11CAN2	57		/* �C���e���W�F���gI/O������11,CAN2 */

/*
 *  OAKS32 SFR�A�h���X��`
 *
 *  �����݃��W�X�^
 */
#define	TADR_SFR_INT_BASE       0x60			/* �����݊֘A�̃x�[�X�A�h���X */
#define TADR_SFR_DM0IC_OFFSET  8				/* DMA0�����ݐ��䃌�W�X�^ */
#define TADR_SFR_TB5IC_OFFSET   9				/* timerB5 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_DMA2IC_OFFSET  10				/* DMA2�����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S2RIC_OFFSET   11				/* uart2��M�����ݐ��䃌�W�X�^ */
#define	TADR_SFR_TA0IC_OFFSET   12				/* timerA0 �����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S3RIC_OFFSET   13				/* uart3��M�����ݐ��䃌�W�X�^ */
#define TADR_SFR_TA2IC_OFFSET   14				/* timerA2 �����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S4RIC_OFFSET   15				/* uart4��M�����ݐ��䃌�W�X�^ */
#define TADR_SFR_TA4IC_OFFSET   16				/* timerA4 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_BCN0IC_OFFSET  17				/* UART0�o�X�Փˌ��o�����ݐ��䃌�W�X�^ */
#define TADR_SFR_BCN3IC_OFFSET  17				/* UART3�o�X�Փˌ��o�����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S0RIC_OFFSET   18				/* uart0��M�����ݐ��䃌�W�X�^ */
#define TADR_SFR_AD0IC_OFFSET   19				/* A-D0�ϊ������ݐ��䃌�W�X�^ */
#define	TADR_SFR_S1RIC_OFFSET   20				/* uart1��M�����ݐ��䃌�W�X�^ */
#define TADR_SFR_IIO0IC_OFFSET  21				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^0 */
#define TADR_SFR_TB1IC_OFFSET   22				/* timerB1 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_IIO2IC_OFFSET  23				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^2 */
#define TADR_SFR_TB3IC_OFFSET   24				/* timerB3 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_IIO4IC_OFFSET  25				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^4 */
#define TADR_SFR_INT5IC_OFFSET  26				/* SI/O4/INT5 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_IIO6IC_OFFSET  27				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^6 */
#define TADR_SFR_INT3IC_OFFSET  28				/* INT3 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_IIO8IC_OFFSET  29				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^8 */
#define TADR_SFR_INT1IC_OFFSET  30				/* INT1 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_IIO10IC_OFFSET 31				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^10 */
#define TADR_SFR_CAN1IC_OFFSET  31				/* CAN������1���䃌�W�X�^ */
#define TADR_SFR_IIO11IC_OFFSET 33				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^11 */
#define TADR_SFR_CAN2IC_OFFSET  33				/* CAN������2���䃌�W�X�^ */
#define TADR_SFR_AD1IC_OFFSET   38				/* A-D1�ϊ������ݐ��䃌�W�X�^ */
#define TADR_SFR_DM1IC_OFFSET   40				/* DMA1�����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S2TIC_OFFSET   41				/* uart2���M�����ݐ��䃌�W�X�^ */
#define TADR_SFR_DM3IC_OFFSET   42				/* DMA3�����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S3TIC_OFFSET   43				/* uart3���M�����ݐ��䃌�W�X�^ */
#define TADR_SFR_TA1IC_OFFSET   44				/* timerA1 �����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S4TIC_OFFSET   45				/* uart4���M�����ݐ��䃌�W�X�^ */
#define TADR_SFR_TA3IC_OFFSET   46				/* timerA3 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_BCN2IC_OFFSET  47				/* UART2�o�X�Փˌ��o�����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S0TIC_OFFSET   48				/* uart0���M�����ݐ��䃌�W�X�^ */
#define TADR_SFR_BCN1IC_OFFSET  49				/* UART1�o�X�Փˌ��o�����ݐ��䃌�W�X�^ */
#define TADR_SFR_BCN4IC_OFFSET  49				/* UART4�o�X�Փˌ��o�����ݐ��䃌�W�X�^ */
#define	TADR_SFR_S1TIC_OFFSET   50				/* uart1���M�����ݐ��䃌�W�X�^ */
#define TADR_SFR_KUPIC_OFFSET   51				/* �L�[���͊����ݐ��䃌�W�X�^ */
#define TADR_SFR_TB0IC_OFFSET   52				/* timerB0 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_IIO1IC_OFFSET  53				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^1 */
#define TADR_SFR_TB2IC_OFFSET   54				/* timerB2 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_IIO3IC_OFFSET  55				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^3 */
#define TADR_SFR_TB4IC_OFFSET   56				/* timerB4 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_IIO5IC_OFFSET  57				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^5 */
#define TADR_SFR_INT4IC_OFFSET  58				/* INT4 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_IIO7IC_OFFSET  59				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^7 */
#define TADR_SFR_INT2IC_OFFSET  60				/* INT2 �����ݐ��䃌�W�X�^ */
#define TADR_SFR_IIO9IC_OFFSET  61				/* �C���e���W�F���gI/O�����ݐ��䃌�W�X�^9 */
#define TADR_SFR_CAN0IC_OFFSET  61				/* CAN������0���䃌�W�X�^ */
#define TADR_SFR_INT0IC_OFFSET  62				/* INT0 �����ݐ��䃌�W�X�^ */

/*
 *  �^�C�}�[���W�X�^
 */
#define TADR_SFR_TBSR           0x300			/* timerB3,4,5�J�E���g�J�n�t���O */
#define TADR_SFR_TA11           0x302			/* timerA1-1���W�X�^ */
#define TADR_SFR_TA21           0x304			/* timerA2-1���W�X�^ */
#define TADR_SFR_TA41           0x306			/* timerA4-1���W�X�^ */
#define TADR_SFR_INVC0          0x308			/* �O��PWM���䃌�W�X�^�O */
#define TADR_SFR_INVC1          0x309			/* �O��PWM���䃌�W�X�^�P */
#define TADR_SFR_IDB0           0x30a			/* �O���o�̓o�b�t�@���W�X�^�O */
#define TADR_SFR_IDB1           0x30b			/* �O���o�̓o�b�t�@���W�X�^�P */
#define TADR_SFR_DTT            0x30c			/* �Z���h�~�^�C�} */
#define TADR_SFR_ICTB2          0x30d			/* timerB2�����ݔ����p�x�ݒ�J�E���^ */
#define TADR_SFR_TB3            0x310			/* timerB3���W�X�^ */
#define TADR_SFR_TB4            0x312			/* timerB4���W�X�^ */
#define TADR_SFR_TB5            0x314			/* timerB5���W�X�^ */
#define	TADR_SFR_TB3MR          0x31b			/* timerB3���[�h���W�X�^ */
#define	TADR_SFR_TB4MR          0x31c			/* timerB4���[�h���W�X�^ */
#define	TADR_SFR_TB5MR          0x31d			/* timerB5���[�h���W�X�^ */
#define TADR_SFR_IFSR           0x31f			/* �����ݗv���I�����W�X�^ */

#define	TADR_SFR_TABSR          0x340			/* �J�E���g�J�n�t���O */
#define TADR_SFR_CPSRF          0x341			/* ���Z�b�g �v���X�P�[�� ���Z�b�g�t���O */
#define TADR_SFR_ONSF           0x342			/* �����V���g �X�^�[�g�t���O */
#define TADR_SFR_TRGSR          0x343			/* �g���K�[�Z���N�g ���W�X�^ */
#define	TADR_SFR_UDF            0x344			/* �A�b�v�_�E���t���O */
#define	TADR_SFR_TA0            0x346			/* timerA0���W�X�^ */
#define TADR_SFR_TA1            0x348			/* timerA1���W�X�^ */
#define TADR_SFR_TA2            0x34a			/* timerA2���W�X�^ */
#define TADR_SFR_TA3            0x34c			/* timerA3���W�X�^ */
#define TADR_SFR_TA4            0x34e			/* timerA4���W�X�^ */
#define TADR_SFR_TB0            0x350			/* timerB0���W�X�^ */
#define TADR_SFR_TB1            0x352			/* timerB1���W�X�^ */
#define TADR_SFR_TB2            0x354			/* timerB2���W�X�^ */
#define	TADR_SFR_TA0MR          0x356			/* timerA0���[�h���W�X�^ */
#define	TADR_SFR_TA1MR          0x357			/* timerA1���[�h���W�X�^ */
#define	TADR_SFR_TA2MR          0x358			/* timerA2���[�h���W�X�^ */
#define	TADR_SFR_TA3MR          0x359			/* timerA3���[�h���W�X�^ */
#define	TADR_SFR_TA4MR          0x35a			/* timerA4���[�h���W�X�^ */
#define	TADR_SFR_TB0MR          0x35b			/* timerB0���[�h���W�X�^ */
#define	TADR_SFR_TB1MR		0x35c			/* timerB1���[�h���W�X�^ */
#define	TADR_SFR_TB2MR          0x35d			/* timerB2���[�h���W�X�^ */
#define	TADR_SFR_TB2SC          0x35e			/* timerB2�X�y�V�������[�h���W�X�^ */
#define TADR_SFR_TCSPR          0x35f			/* �J�E���g�\�[�X�v���X�P�[�����W�X�^ */

/*
 *  �V���A�����W�X�^
 */
#define	TADR_SFR_UART0_BASE     0x360			/* uart0���W�X�^�x�[�X�A�h���X */
#define	TADR_SFR_UART1_BASE     0x2e0			/* uart1���W�X�^�x�[�X�A�h���X */
#define	TADR_SFR_UART2_BASE     0x330			/* uart2���W�X�^�x�[�X�A�h���X */
#define	TADR_SFR_UART3_BASE     0x320			/* uart3���W�X�^�x�[�X�A�h���X */
#define	TADR_SFR_UART4_BASE     0x2f0			/* uart4���W�X�^�x�[�X�A�h���X */

#define	TADR_SFR_USMR_OFFSET    7			/* ���ꃂ�[�h���W�X�^ */
#define	TADR_SFR_USMR2_OFFSET   6			/* ���ꃂ�[�h���W�X�^2 */
#define	TADR_SFR_USMR3_OFFSET   5			/* ���ꃂ�[�h���W�X�^3 */
#define	TADR_SFR_USMR4_OFFSET   4			/* ���ꃂ�[�h���W�X�^4 */

#define	TADR_SFR_UMR_OFFSET     8			/* uart����M���[�h���W�X�^ */
#define	TADR_SFR_UBRG_OFFSET    9			/* uart�{�[���[�g�W�F�l���[�^ */
#define	TADR_SFR_UTB_OFFSET     10			/* uart���M�o�b�t�@���W�X�^ */
#define	TADR_SFR_UC0_OFFSET     12			/* uart����M���䃌�W�X�^#0 */
#define	TADR_SFR_UC1_OFFSET     13			/* uart����M���䃌�W�X�^#1 */
#define	TADR_SFR_URB_OFFSET     14			/* uart��M�o�b�t�@���W�X�^ */

/*
 *  A-D/D-A���W�X�^
 */
#define TADR_SFR_AD00            0x380			/* A-D���W�X�^�O */
#define TADR_SFR_AD01            0x382			/* A-D���W�X�^�P */
#define TADR_SFR_AD02            0x384			/* A-D���W�X�^�Q */
#define TADR_SFR_AD03            0x386			/* A-D���W�X�^�R */
#define TADR_SFR_AD04            0x388			/* A-D���W�X�^�S */
#define TADR_SFR_AD05            0x38a			/* A-D���W�X�^�T */
#define TADR_SFR_AD06            0x38c			/* A-D���W�X�^�U */
#define TADR_SFR_AD07            0x38e			/* A-D���W�X�^�V */
#define TADR_SFR_AD0CON2         0x394			/* A-D���䃌�W�X�^�Q */
#define TADR_SFR_AD0CON0         0x396			/* A-D���䃌�W�X�^�O */
#define TADR_SFR_AD0CON1         0x397			/* A-D���䃌�W�X�^�P */

#define TADR_SFR_AD10            0x1c0			/* A-D���W�X�^�O */
#define TADR_SFR_AD11            0x1c2			/* A-D���W�X�^�P */
#define TADR_SFR_AD12            0x1c4			/* A-D���W�X�^�Q */
#define TADR_SFR_AD13            0x1c6			/* A-D���W�X�^�R */
#define TADR_SFR_AD14            0x1c8			/* A-D���W�X�^�S */
#define TADR_SFR_AD15            0x1ca			/* A-D���W�X�^�T */
#define TADR_SFR_AD16            0x1cc			/* A-D���W�X�^�U */
#define TADR_SFR_AD17            0x1ce			/* A-D���W�X�^�V */
#define TADR_SFR_AD1CON2         0x1d4			/* A-D���䃌�W�X�^�Q */
#define TADR_SFR_AD1CON0         0x1d6			/* A-D���䃌�W�X�^�O */
#define TADR_SFR_AD1CON1         0x1d7			/* A-D���䃌�W�X�^�P */

#define TADR_SFR_DA0            0x398			/* D-A���W�X�^�O */
#define TADR_SFR_DA1            0x39a			/* D-A���W�X�^�P */
#define TADR_SFR_DACON          0x39c			/* D-A���䃌�W�X�^ */

/*
 *  �ėp�|�[�g���W�X�^(�ꕔ�A144�s���ł̂�)
 */
#define TADR_SFR_P0             0x3e0           /* �|�[�gP0���W�X�^ */
#define TADR_SFR_P1             0x3e1           /* �|�[�gP1���W�X�^ */
#define TADR_SFR_PD0            0x3e2		/* �|�[�gP0�������W�X�^ */
#define TADR_SFR_PD1            0x3e3		/* �|�[�gP1�������W�X�^ */
#define TADR_SFR_P2             0x3e4		/* �|�[�gP2���W�X�^ */
#define TADR_SFR_P3             0x3e5		/* �|�[�gP3���W�X�^ */
#define	TADR_SFR_PD2            0x3e6		/* �|�[�gP2�������W�X�^ */
#define	TADR_SFR_PD3            0x3e7		/* �|�[�gP3�������W�X�^ */
#define TADR_SFR_P4             0x3e8		/* �|�[�gP4���W�X�^ */
#define	TADR_SFR_P5             0x3e9		/* �|�[�gP5���W�X�^ */
#define	TADR_SFR_PD4            0x3ea		/* �|�[�gP4�������W�X�^ */
#define	TADR_SFR_PD5            0x3eb		/* �|�[�gP5�������W�X�^ */
#define TADR_SFR_P6             0x3c0		/* �|�[�gP6���W�X�^ */
#define	TADR_SFR_P7             0x3c1		/* �|�[�gP7���W�X�^ */
#define	TADR_SFR_PD6            0x3c2		/* �|�[�gP6�������W�X�^ */
#define	TADR_SFR_PD7            0x3c3		/* �|�[�gP7�������W�X�^ */
#define	TADR_SFR_P8             0x3c4		/* �|�[�gP8���W�X�^ */
#define TADR_SFR_P9             0x3c5		/* �|�[�gP9���W�X�^ */
#define	TADR_SFR_PD8            0x3c6		/* �|�[�gP8�������W�X�^ */
#define TADR_SFR_PD9            0x3c7		/* �|�[�gP9�������W�X�^ */
#define TADR_SFR_P10            0x3c8		/* �|�[�gP10���W�X�^ */
#define TADR_SFR_P11            0x3c9		/* �|�[�gP11���W�X�^(144�s���ł̂�) */
#define TADR_SFR_PD10           0x3ca		/* �|�[�gP10�������W�X�^ */
#define TADR_SFR_PD11           0x3cb		/* �|�[�gP11�������W�X�^(144�s���ł̂�) */
#define TADR_SFR_P12            0x3cc		/* �|�[�gP12���W�X�^(144�s���ł̂�) */
#define TADR_SFR_P13            0x3cd		/* �|�[�gP13���W�X�^(144�s���ł̂�) */
#define TADR_SFR_PD12           0x3ce		/* �|�[�gP12�������W�X�^(144�s���ł̂�) */
#define TADR_SFR_PD13           0x3cf		/* �|�[�gP13�������W�X�^(144�s���ł̂�) */
#define TADR_SFR_P14            0x3d0		/* �|�[�gP14���W�X�^(144�s���ł̂�) */
#define TADR_SFR_P15            0x3d1		/* �|�[�gP15���W�X�^(144�s���ł̂�) */
#define TADR_SFR_PD14           0x3d2		/* �|�[�gP14�������W�X�^(144�s���ł̂�) */
#define TADR_SFR_PD15           0x3d3		/* �|�[�gP15�������W�X�^(144�s���ł̂�) */

#define	TADR_SFR_PUR0           0x3f0		/* �v���A�b�v���䃌�W�X�^�O */
#define	TADR_SFR_PUR1           0x3f1		/* �v���A�b�v���䃌�W�X�^�P */
#define	TADR_SFR_PUR2           0x3da		/* �v���A�b�v���䃌�W�X�^�Q */
#define	TADR_SFR_PUR3           0x3db		/* �v���A�b�v���䃌�W�X�^�R */
#define	TADR_SFR_PUR4           0x3dc		/* �v���A�b�v���䃌�W�X�^�S(144�s���ł̂�) */

#define	TADR_SFR_PCR            0x3ff		/* �|�[�g���䃌�W�X�^ */

#define TADR_SFR_PS0            0x3b0		/* �@�\�I�����W�X�^A0 */
#define TADR_SFR_PS1            0x3b1		/* �@�\�I�����W�X�^A1 */
#define TADR_SFR_PS2            0x3b4		/* �@�\�I�����W�X�^A2 */
#define TADR_SFR_PS3            0x3b5		/* �@�\�I�����W�X�^A3 */
#define TADR_SFR_PS5            0x3b9		/* �@�\�I�����W�X�^A5(144�s���ł̂�) */
#define TADR_SFR_PS6            0x3bc		/* �@�\�I�����W�X�^A6(144�s���ł̂�) */
#define TADR_SFR_PS7            0x3bd		/* �@�\�I�����W�X�^A7(144�s���ł̂�) */
#define TADR_SFR_PS8            0x3a0		/* �@�\�I�����W�X�^A8(144�s���ł̂�) */
#define TADR_SFR_PS9            0x3a1		/* �@�\�I�����W�X�^A9(144�s���ł̂�) */

#define TADR_SFR_PSL0           0x3b2		/* �@�\�I�����W�X�^B0 */
#define TADR_SFR_PSL1           0x3b3		/* �@�\�I�����W�X�^B1 */
#define TADR_SFR_PSL2           0x3b6		/* �@�\�I�����W�X�^B2 */
#define TADR_SFR_PSL3           0x3b7		/* �@�\�I�����W�X�^B3 */

#define TADR_SFR_PSC            0x3af		/* �@�\�I�����W�X�^C */


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
//#define	P7_LED1					0x10			/* LED1�r�b�g��` */
//#define	P7_LED2					0x20			/* LED2�r�b�g��` */

#ifndef _MACRO_ONLY

#include "cpu_defs.h"

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */

Inline void
oaks32_putc(char c)
{
	char enabled;
	volatile char * p = (volatile char *)TADR_SFR_UART0_BASE;

	/* ���M������Ă��Ȃ���΋����� */
	enabled = p[TADR_SFR_UC1_OFFSET] & TBIT_UiC1_TE;
	if(!enabled) {
		p[TADR_SFR_UC1_OFFSET] |= TBIT_UiC1_TE;
	}

	/* ���M�o�b�t�@����ɂȂ�܂ő҂�(�L�����ԓ��̏�������������) */
	while((p[TADR_SFR_UC1_OFFSET] & TBIT_UiC1_TI) == 0);

	/* 1�������M */
	p[TADR_SFR_UTB_OFFSET] = c;

	if(!enabled) {
		p[TADR_SFR_UC1_OFFSET] &= ~TBIT_UiC1_TE;
	}
}

#endif /* _MACRO_ONLY */
#endif /* _OAKS32_H_ */

