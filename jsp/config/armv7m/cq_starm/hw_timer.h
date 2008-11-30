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
 *  @(#) $Id: hw_timer.h,v 1.6 2008/08/03 06:06:48 suikan Exp $
 */

/*
 *	�^�C�}�h���C�o�iCQ-STARM�p�j
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
//#include <dve68k_dga.h>

/*
 *  �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_TIMER	1	CM3NI // STM32F103�̃^�C�}���荞�݃n���h���̃x�N�^�ԍ�������t���邱�ƁB1�͂Ƃ肠�����B

#ifndef _MACRO_ONLY

/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UW	CLOCK;

/*
 *  �^�C�}�l�̓����\���ƃ~���b�E�ʕb�P�ʂƂ̕ϊ�
 *
 *  CQ_STARM�{�[�h�ł́C�^�C�}��1/72�ʕb���ɃJ�E���g�A�b�v����D
 *  �Ȃ��ASYSTICK_CURRENT_VALUE�̓_�E���J�E���^�Ȃ̂ŁATO_USEC�̃}�C�N���b��1000����������l�ɂ���B
 */
#define	TO_CLOCK(nume, deno)	(72000 * (nume) / (deno))
#define	TO_USEC(clock)		(1000- (clock) / 72)	


/*
 *  �^�C�}�̌��ݒl�������ݔ����O�̒l�Ƃ݂Ȃ����̔��f
 */
#define	GET_TOLERANCE	7200	/* �����x��̌��ς�l�i�P�ʂ͓����\���j*/
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �^�C�}��~�܂ł̎��ԁinsec�P�ʁj
 *
 *  �l�ɍ����͂Ȃ��D
 */
#define	TIMER_STOP_DELAY	14400


/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
hw_timer_initialize()
{
	*(volatile UW*)0xE000E010 = 0;			/* SYSTIC Control Reg, initialize */
	*(volatile UW*)0xE000E014 = 72000 - 1;	/* SYSTIC Reload reg. assume clock is 72MHz. generate every 1mS interrupt*/

	*(volatile UW*)0xE000E010 = 0x07;		/* SYSTIC Control Reg. Enable Counting, Multi-shot, interrernal clock source */

}

/*
 *  �^�C�}�����ݗv���̃N���A
 */
Inline void
hw_timer_int_clear()
{
	CM3NI
/*
 * CORTEX-M3 TRM �ɂ� ARMv7M ALARM �ɂ�SYSTICK���荞�݂̃N���A���@�������Ă��Ȃ��B
 */
}

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
Inline void
hw_timer_terminate()
{
	/*
	 *  �^�C�}�̓�����~����D
	 */
	*(volatile UW*)0xE000E010 = 0;			/* SYSTIC Control Reg, initialize */
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 */
Inline CLOCK
hw_timer_get_current()
{
	return ( *(volatile UW*)0xE000E018 );	/* SYSTICK current Value register */
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 * ���荞�݂��v������Ă���Ȃ�TRUE
 */
Inline BOOL
hw_timer_fetch_interrupt()
{
	CM3NI
	return(0);		/* CORTEX-M3 TRM ��ǂ�ł��ASYSTICK��Pend��Ԃ��ǂ����ׂ�΂����̂��킩��Ȃ� */
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
