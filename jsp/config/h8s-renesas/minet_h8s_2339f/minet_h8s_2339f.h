/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 */

#ifndef _MINET_H8S_2339F_H_
#define _MINET_H8S_2339F_H_

/*
 *  MiSPO MiNET-H8S/2339F�p��`
 */

#define MINET_H8S_2339F

/*
 *  SYSCR�̏����l
 *  �@�EINTM1=1,INTM0=0�F�����ݐ��䃂�[�h�Q
 *  �@�ENMIEG=0�FNMI���̗͂�����G�b�W�Ŋ��荞�ݗv���𔭐�
 *  �@�EIRQPAS�FIRQ���͒[�q�Z���N�g
 *  �@�ERAME=1�F����RAM�L��
 */
#define	SYS_SYSCR	(INT_MODE2 | RAME)

/*
 *  CPU �N���b�N
 */
#define CPU_CLOCK	24576			/* kHz�P�� �i24.576MHz�j*/

/*
 *  �^�C�}�ɋ��������N���b�N (�����N���b�N��/4�ŃJ�E���g)
 */
#define TIMER_CLOCK	((CPU_CLOCK)/4)		/* kHz�P�� */

/*
 *  �V���A���|�[�g��BRR���W�X�^�l�̒�`
 *    �v�Z����p������@�����邪�A�덷�̔��肪�K�v�Ȃ̂ŁA
 *�@�@�ʂɃ}�N����`���Ă���B
 *�@�@BRR_RATE�}�N���̓}�j���A�����N�ɑΉ�����B
 *�@�@�������n=0�ł���B
 *�@�@BAUD_RATE��user_config.h�Œ�`����B
 */
#if CPU_CLOCK != 24576
#error CPU_CLOCK is invalid value.
#else /*  CPU_CLOCK != 24576  */

/*  SCI0  */
#if BAUD_RATE0 == 9600		/* �r�b�g���[�g�F 9600[bps] */
	#define BRR0_RATE	79
#elif BAUD_RATE0 == 19200	/* �r�b�g���[�g�F19200[bps] */
	#define BRR0_RATE	39
#elif BAUD_RATE0 == 38400	/* �r�b�g���[�g�F38400[bps] */
	#define BRR0_RATE	19
#endif /* BAUD_RATE0 == 9600  */

/*  SCI1  */
#if BAUD_RATE1 == 9600		/* �r�b�g���[�g�F 9600[bps] */
	#define BRR1_RATE	79
#elif BAUD_RATE1 == 19200	/* �r�b�g���[�g�F19200[bps] */
	#define BRR1_RATE	39
#elif BAUD_RATE1 == 38400	/* �r�b�g���[�g�F38400[bps] */
	#define BRR1_RATE	19
#endif /* BAUD_RATE1 == 9600  */

/*  SCI1  */
#if BAUD_RATE2 == 9600		/* �r�b�g���[�g�F 9600[bps] */
	#define BRR2_RATE	79
#elif BAUD_RATE2 == 19200	/* �r�b�g���[�g�F19200[bps] */
	#define BRR2_RATE	39
#elif BAUD_RATE2 == 38400	/* �r�b�g���[�g�F38400[bps] */
	#define BRR2_RATE	19
#endif /* BAUD_RATE1 == 9600  */

/*
 *  SCR���W�X�^��CKS0,CKS1�r�b�g
 *�@�@�{�[���[�g�v�Z����n=0�ɑΉ�
 *�@�@�{�[���[�g���ɒl���قȂ�ꍇ������̂Œ���
 */
#define SCR0_CKS		0	/*  SCI0  */
#define SCR1_CKS		0	/*  SCI1  */
#define SCR2_CKS		0	/*  SCI2  */

#endif /* CPU_CLOCK != 24576 */

/*
 *  DDR���W�X�^�̏����l�̒�`
 */
#define P1DDR0		0xf0
#define P2DDR0		DUMMY
#define P3DDR0		DUMMY
/*  �|�[�g�S��DDR���Ȃ����߁A����  */
#define P5DDR0		DUMMY
#define P6DDR0		0xc3
#define P7DDR0		DUMMY
#define P8DDR0		DUMMY
#define P9DDR0		0xe0
#define PADDR0		0xff
#define PBDDR0		0xff
#define PCDDR0		0xff
#define PDDDR0		DUMMY
#define PEDDR0		DUMMY
#define PFDDR0		0xff
#define PGDDR0		0x1f




#endif /* _MINET_H8S_2339F_H_ */
