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
 *  @(#) $Id: sample1.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *  �T���v���v���O����(1)�̃w�b�_�t�@�C��
 */

#include "cpu_defs.h"
#include "sys_defs.h"

/*
 *  �e�^�X�N�̗D��x�̒�`
 */

#define MAIN_PRIORITY	5		/* ���C���^�X�N�̗D��x */
					/* HIGH_PRIORITY ��荂�����邱�� */

#define HIGH_PRIORITY	9		/* ����Ɏ��s�����^�X�N�̗D��x */
#define MID_PRIORITY	10
#define LOW_PRIORITY	11

/*
 *  �^�[�Q�b�g�ˑ��̒�`�iCPU��O�n���h���̋N�����@�Ȃǁj
 */

#ifdef M68K

#define CPUEXC1		5		/* �[�����Z��O */
#define RAISE_CPU_EXCEPTION	syslog(LOG_NOTICE, "zerodiv = %d", 10 / 0)

#elif defined(SH3)

#define CPUEXC1		224		/* ���[�h�G���[��O */
#define RAISE_CPU_EXCEPTION	(*((volatile int *) 0xFFFFFEC1))

#elif defined(SH1)

#define CPUEXC1		9		/* CPU�A�h���X�G���[��O */
#define RAISE_CPU_EXCEPTION	(*((volatile int *) 0xFFFFFEC1))
#ifdef TOKIWA_SH1
#define	STACK_SIZE	512		/* �^�X�N�̃X�^�b�N�T�C�Y */
#endif /* TOKIWA_SH1 */

#elif defined(ARM7TDMI)

#define CPUEXC1		4		/* ���[�h�G���[��O */
#define RAISE_CPU_EXCEPTION	(*((volatile int *) 0xFFFFFEC1))

#elif defined(V850)

#elif defined(H8)

#undef CPUEXC1				/* CPU��O�n���h�����T�|�[�g���Ȃ� */

#elif defined(H8S)

#undef CPUEXC1				/* CPU��O�n���h�����T�|�[�g���Ȃ� */
#define LOOP_REF	4000L		/* ���x�v���p�̃��[�v�� */

#elif defined(MICROBLAZE)

#undef CPUEXC1				/* CPU��O�n���h�����T�|�[�g���Ȃ� */
#define STACK_SIZE	2048		/* �^�X�N�̃X�^�b�N�T�C�Y */

#elif defined(I386)

#define CPUEXC1		0		/* �[�����Z��O */
#define RAISE_CPU_EXCEPTION   syslog(LOG_NOTICE, "zerodiv = %d", 10 / 0)
#define OMIT_VGET_TIM

#elif defined(TMS320C54X)

#undef CPUEXC1				/* CPU��O�n���h�����T�|�[�g���Ȃ� */
#define STACK_SIZE	320		/* �^�X�N�̃X�^�b�N�T�C�Y */
#define LOOP_REF	500000L		/* ���x�v���p�̃��[�v�� */

#elif defined(LINUX)

#undef CPUEXC1				/* CPU��O�n���h�����T�|�[�g���Ȃ� */
#define OMIT_VGET_TIM
#define LOOP_REF	4000000		/* ���x�v���p�̃��[�v�� */

#elif defined(WINDOWS)

#define LOOP_REF	5000000		/* ���x�v���p�̃��[�v�� */

#endif

/*
 *  �^�[�Q�b�g�Ɉˑ�����\���̂���萔�̒�`
 */

#ifndef TASK_PORTID
#define	TASK_PORTID	1		/* �������͂���V���A���|�[�gID */
#endif /* TASK_PORTID */

#ifndef STACK_SIZE
#define	STACK_SIZE	8192		/* �^�X�N�̃X�^�b�N�T�C�Y */
#endif /* STACK_SIZE */

#ifndef LOOP_REF
#define LOOP_REF	1000000		/* ���x�v���p�̃��[�v�� */
#endif /* LOOP_REF */

/*
 *  �֐��̃v���g�^�C�v�錾
 */
#ifndef _MACRO_ONLY

extern void	task(VP_INT tskno);
extern void	main_task(VP_INT exinf);
extern void	tex_routine(TEXPTN texptn, VP_INT tskno);
extern void	cyclic_handler(VP_INT exinf);
extern void	cpuexc_handler(VP p_excinf);

#endif /* _MACRO_ONLY */
