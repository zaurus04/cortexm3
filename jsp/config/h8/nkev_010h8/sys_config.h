/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Kunihiko Ohnaka
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
 *  @(#) $Id: sys_config.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */

#include <sys_rename.h>

/*
 *  �^�[�Q�b�g�V�X�e���̃n�[�h�E�F�A�����̒�`
 */

#include <h8_3069f.h>

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g��
 */

#define	TARGET_NAME	"NKEV-010H8"

/*
 *  chg_ipm���T�|�[�g���邩�ǂ����̒�`
 */
#define SUPPORT_CHG_IPM

/*
 *  vxget_tim ���T�|�[�g���邩�ǂ����̒�`
 */

#define	SUPPORT_VXGET_TIM

/*
 *   �X�^�b�N�̈�̒�`
 */

#define STACKTOP    	(H8IN_RAM_BASE + H8IN_RAM_SIZE)	/* �^�X�N�Ɨ����p�X�^�b�N�̏����l */
#define str_STACKTOP	_TO_STRING(STACKTOP)

#ifndef _MACRO_ONLY

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */

extern void	sys_initialize(void);

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 *
 *  �V�X�e�����I�����鎞�Ɏg���DROM���j�^�ďo���Ŏ������邱�Ƃ�z�肵
 *  �Ă���D
 */

extern void	sys_exit(void);

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 *
 *  �V�X�e���̒჌�x���̕����o�̓��[�`���DROM���j�^�ďo���Ŏ������邱
 *  �Ƃ�z�肵�Ă���D
 */

extern void cpu_putc(char c);

Inline void
sys_putc(char c)
{
#ifndef GDB_STUB

	cpu_putc(c);

#else	/* of #ifndef GDB_STUB */

/* GDB STUB���g���ꍇ�ɒ჌�x���o�͂�GDB�̃R���\�[���֏o�� */
	asm ("	push.l	er1			\n"\
		"	mov.l	er0, er1	\n"\
		"	sub.l	er0, er0	\n"\
		"	trapa	#1			\n"\
		"	pop.l	er1			\n"\
	);

#endif	/* of #ifndef GDB_STUB */

	};

#endif /* _MACRO_ONLY */


/*
 *  (1) �V���A���|�[�g�̐ݒ�
 *  (2) �^�C�}�[�̐ݒ�
 *  (3) �O���A�h���X��Ԑ���
 */

/*
 *  �T�|�[�g����V���A���f�B�o�C�X�̐��͍ő� 3�B
 *  �������A���݂� 2 �܂Œ�`���Ă���B
 *  
 *  �T���v���v���O�����𓮂����ꍇ��
 *  sys_defs.h�ɂ���TASK_PORTID�̒�`�ɂ�����
 */

#ifdef GDB_STUB

/* GDB stub���g�p����Ƃ��͋����I��TNUM_POTR = 1�ɂ��� */
#define TNUM_PORT	1

#else	/* of #ifdef GDB_STUB */

#define TNUM_PORT	2

#endif	/* of #ifdef GDB_STUB */

#define	CONSOLE_PORTID		SYSTEM_PORTID	/* �R���\�[���ɗp����V���A���|�[�g�ԍ�     */
#define	LOGTASK_PORTID		SYSTEM_PORTID	/* �V�X�e�����O���o�͂���V���A���|�[�g�ԍ� */

#define H8_MIN_BAUD_RATE	9600		/* SCI ���N���[�Y����O�̑҂����Ԃ̌v�Z�Ɏg�p����B*/

/* �G���[���荞�݂��A���͊��荞�݂ƕʂɑ��삷��ꍇ�̓R�����g���͂����B*/
/*#define H8_CFG_SCI_ERR_HANDLER*/

/*
 *  SYSTEM �p SCI �̐ݒ�l
 */

#ifdef GDB_STUB

/* GDB stub���g�p���鎞��SYSTEM_SCI��SCI0���g�p���� */
#define SYSTEM_SCI			H8SCI0
#define SYSTEM_SCI_IPR		H8IPRB
#define SYSTEM_SCI_IP_BIT	H8IPR_SCI0_BIT

#else	/* of #ifdef GDB_STUB */

#define SYSTEM_SCI			H8SCI1
#define SYSTEM_SCI_IPR		H8IPRB
#define SYSTEM_SCI_IP_BIT	H8IPR_SCI1_BIT

#endif	/* of #ifdef GDB_STUB */

#define SYSTEM_SCI_SMR		0
			/* ����M�t�H�[�}�b�g			*/
	     		/* ����������				*/
	     		/* �L�����N�^�����O�X�F8�r�b�g		*/
	     		/* �p���e�B�Ȃ�				*/
	     		/* �X�g�b�v�r�b�g�����O�X�F1		*/
	     		/* �N���b�N�Z���N�g�i������j:1		*/

#define SYSTEM_BAUD_RATE	38400			/* bps	*/

#if TNUM_PORT == 1

#define	SYSTEM_PORTID		1

#ifdef GDB_STUB

#define INHNO_SERIAL_IN		IRQ_RXI0
#define INHNO_SERIAL_OUT	IRQ_TXI0
#define INHNO_SERIAL_ERR	IRQ_ERI0

#else	/*	#ifdef GDB_STUB */

#define INHNO_SERIAL_IN		IRQ_RXI1
#define INHNO_SERIAL_OUT	IRQ_TXI1
#define INHNO_SERIAL_ERR	IRQ_ERI1

#endif	/*	#ifdef GDB_STUB */

#elif TNUM_PORT == 2	/* of #if TNUM_PORT == 1 */

#define USER_SCI		H8SCI0

#define USER_SCI_IPR		H8IPRB
#define USER_SCI_IP_BIT		H8IPR_SCI0_BIT

#define USER_SCI_SMR		0
			/* ����M�t�H�[�}�b�g			*/
	     		/* ����������				*/
	     		/* �L�����N�^�����O�X�F8�r�b�g		*/
	     		/* �p���e�B�Ȃ�				*/
	     		/* �X�g�b�v�r�b�g�����O�X�F1		*/
	     		/* �N���b�N�Z���N�g�i������j:1		*/

#define USER_BAUD_RATE		38400			/* bps	*/

#define	USER_PORTID		1
#define	SYSTEM_PORTID		2

#define INHNO_SERIAL_IN		IRQ_RXI0
#define INHNO_SERIAL_OUT	IRQ_TXI0
#define INHNO_SERIAL_ERR	IRQ_ERI0

#define INHNO_SERIAL2_IN	IRQ_RXI1
#define INHNO_SERIAL2_OUT	IRQ_TXI1
#define INHNO_SERIAL2_ERR	IRQ_ERI1

#else	/* of #if TNUM_PORT == 1 */

#error TNUM_PORT <= 2

#endif	/* of #if TNUM_PORT == 1 */

/*  �v���C�I���e�B���x���ݒ�p�̃f�[�^  */

/*  �����ݗv���̃��x���ݒ�  */
#define SYSTEM_SCI_IPM			IPM_LEVEL0
#define USER_SCI_IPM			IPM_LEVEL0

/*  
 * �����݃n���h�����s���̊����݃}�X�N�̒l
 * �@�@���̊����݂��}�X�N���邽�߂̐ݒ�  
 * �@�@�����Ɠ������x���̊����ݗv�����u���b�N���邽�߁A
 * �@�@��L�̊����ݗv�����x�����P�������x���ɐݒ肷��B
 */
#if TNUM_PORT == 1	/*  �|�[�g�P�F�V�X�e���E�|�[�g  */

/*  �V�X�e���E�|�[�g  */
#if SYSTEM_SCI_IPM == IPM_LEVEL0
#define sio_in_handler_intmask		IPM_LEVEL1
#elif SYSTEM_SCI_IPM == IPM_LEVEL1
#define sio_in_handler_intmask		IPM_LEVEL2
#endif 	/* SYSTEM_SCI_IPM == IPM_LEVEL0 */


#elif TNUM_PORT == 2	/* of #if TNUM_PORT == 1 */
			/*  �|�[�g�P�F���[�U�[�E�|�[�g  */
			/*  �|�[�g�Q�F�V�X�e���E�|�[�g  */
/*  ���[�U�[�E�|�[�g  */
#if USER_SCI_IPM == IPM_LEVEL0
#define sio_in_handler_intmask		IPM_LEVEL1
#elif USER_SCI_IPM == IPM_LEVEL1
#define sio_in_handler_intmask		IPM_LEVEL2
#endif 	/* USER_SCI_IPM == IPM_LEVEL0 */

/*  �V�X�e���E�|�[�g  */
#if SYSTEM_SCI_IPM == IPM_LEVEL0
#define sio_in2_handler_intmask		IPM_LEVEL1
#elif SYSTEM_SCI_IPM == IPM_LEVEL1
#define sio_in2_handler_intmask		IPM_LEVEL2
#endif 	/* SYSTEM_SCI_IPM == IPM_LEVEL0 */

#endif	/* of #if TNUM_PORT == 1 */

#define sio_out_handler_intmask		sio_in_handler_intmask
#define sio_err_handler_intmask		sio_in_handler_intmask

#ifndef GDB_STUB

#define sio_out2_handler_intmask	sio_in2_handler_intmask
#define sio_err2_handler_intmask	sio_in2_handler_intmask

#endif
/*
 *  �^�C�}�̐ݒ�
 */

#define SYSTEM_TIMER		H816TU0

#define SYSTEM_TIMER_CNT	(SYSTEM_TIMER + H8TCNT)
#define SYSTEM_TIMER_TCR	(SYSTEM_TIMER + H8TCR)
#define SYSTEM_TIMER_TIOR	(SYSTEM_TIMER + H8TIOR)
#define SYSTEM_TIMER_IER	H816TU_TISRA
#define SYSTEM_TIMER_IFR	H816TU_TISRA
#define SYSTEM_TIMER_TSTR	H816TU_TSTR
#define SYSTEM_TIMER_GR		(SYSTEM_TIMER + H8GRA)

#define SYSTEM_TIMER_STR	H8TSTR_STR0
#define SYSTEM_TIMER_STR_BIT	H8TSTR_STR0_BIT
#define SYSTEM_TIMER_IE		H8TISRA_IMIEA0		/* interrupt mask */
#define SYSTEM_TIMER_IE_BIT	H8TISRA_IMIEA0_BIT
#define SYSTEM_TIMER_IF		H8TISRA_IMFA0		/* match flag */
#define SYSTEM_TIMER_IF_BIT	H8TISRA_IMFA0_BIT

#define INHNO_TIMER		IRQ_IMIA0

#define SYSTEM_TIMER_TCR_BIT	(H8TCR_CCLR0 | H8TCR_TPSC1 | H8TCR_TPSC0)
#define SYSTEM_TIMER_TIOR_BIT	(0)

#define TIMER_CLOCK		((CPU_CLOCK)/8000)	/* 20MHz / 8 = 2.5MHz = 2500KHz */

/*  �v���C�I���e�B���x���ݒ�p�̃f�[�^  */

/*  �����ݗv���̃��x���ݒ�  */
#define SYSTEM_TIMER_IPR                H8IPRA
#define SYSTEM_TIMER_IP_BIT             H8IPR_ITU0_BIT
#define SYSTEM_TIMER_IPM                IPM_LEVEL1

/*  
 * �����݃n���h�����s���̊����݃}�X�N�̒l
 * �@�@���̊����݂��}�X�N���邽�߂̐ݒ�  
 * �@�@�����Ɠ������x���̊����ݗv�����u���b�N���邽�߁A
 * �@�@��L�̊����ݗv�����x�����P�������x���ɐݒ肷��B
 */
#if SYSTEM_TIMER_IPM == IPM_LEVEL0
#define timer_handler_intmask		IPM_LEVEL1
#elif SYSTEM_TIMER_IPM == IPM_LEVEL1
#define timer_handler_intmask		IPM_LEVEL2
#endif 	/* SYSTEM_TIMER_IPM == IPM_LEVEL0 */

/*
 *  �O���A�h���X��Ԑ���
 */

#define	ENABLE_P8_CS		(H8P8DDR_CS0|H8P8DDR_CS1|H8P8DDR_CS2|H8P8DDR_CS3)

#if 0

#define	ENABLE_LOWER_DATA
#define	ENABLE_PB_CS		(H8PADDR_CS4|H8PADDR_CS5|H8PADDR_CS6|H8PBDDR_CS7)

#endif	/* of #if 0 */

#define	HEAP_TOP		0x600000UL

/*
 *  �������ԑ҂��̂��߂̒�`
 */

#if defined(ROM)

/*  ROM���i���߂������t���b�V��ROM��ɔz�u����Ă���j  */
#define	SIL_DLY_TIM1	 4540
#define	SIL_DLY_TIM2	  529

#elif defined(INMEM_ONLY)

/*  ROM���A�����������̂ݎg�p */
#define	SIL_DLY_TIM1	 2800
#define	SIL_DLY_TIM2	  521

#else	/* of #if defined(ROM) */

/*  ���߂��O��RAM��ɔz�u����Ă���  */
#define	SIL_DLY_TIM1	 8290
#define	SIL_DLY_TIM2	 1693

#endif	/* of #if defined(ROM) */


/*
 *  DDR�̏����l�̒�`
 */

#define	H8P1DDR0        0xff				/*  �|�[�g1  */
#define	H8P2DDR0        0xff				/*  �|�[�g2  */
#define	H8P3DDR0        DUMMY				/*  �|�[�g3  */
#define	H8P4DDR0        DUMMY				/*  �|�[�g4  */
#define	H8P5DDR0        0xff				/*  �|�[�g5  */
#define	H8P6DDR0        DUMMY				/*  �|�[�g6  */

/*  �|�[�g7�͓��͐�p��DDR���W�X�^���Ȃ����߁A�ȗ����Ă���B  */

#define	H8P8DDR0        (H8P8DDR_CS1 | H8P8DDR_CS2 | H8P8DDR_CS3)
							/*  �|�[�g8  */
#define	H8P9DDR0        DUMMY				/*  �|�[�g9  */
#define	H8PADDR0        DUMMY				/*  �|�[�gA  */
#define	H8PBDDR0        DUMMY				/*  �|�[�gB  */

#endif /* _SYS_CONFIG_H_ */
