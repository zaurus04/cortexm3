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
 *  @(#) $Id: time_manage.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�V�X�e�������Ǘ��@�\
 */

#include "jsp_kernel.h"
#include "check.h"
#include "time_event.h"

/*
 *  �V�X�e�������̐ݒ�
 */
#ifdef __set_tim

SYSCALL ER
set_tim(const SYSTIM *p_systim)
{
	ER	ercd;

	LOG_SET_TIM_ENTER(p_systim);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	systim_offset = *p_systim - current_time;
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_SET_TIM_LEAVE(ercd);
	return(ercd);
}

#endif /* __set_tim */

/*
 *  �V�X�e�������̎Q��
 */
#ifdef __get_tim

SYSCALL ER
get_tim(SYSTIM *p_systim)
{
	ER	ercd;

	LOG_GET_TIM_ENTER(p_systim);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_systim = systim_offset + current_time;
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_GET_TIM_LEAVE(ercd, *p_systim);
	return(ercd);
}

#endif /* __get_tim */

/*
 *  ���\�]���p�V�X�e�������̎Q��
 */
#ifdef __vxget_tim
#ifdef SUPPORT_VXGET_TIM
#include <hw_timer.h>

SYSCALL ER
vxget_tim(SYSUTIM *p_sysutim)
{
	SYSUTIM	utime;
	SYSTIM	time;
#if TIC_DENO != 1
	INT	subtime;
#endif /* TIC_DENO != 1 */
	CLOCK	clock;
	BOOL	ireq;
	BOOL	locked;
	ER	ercd;

	LOG_VXGET_TIM_ENTER(p_sysutim);
	CHECK_TSKCTX();

	locked = sense_lock();
	if (!(locked)) {
		t_lock_cpu();
	}
	time = systim_offset + next_time;
#if TIC_DENO != 1
	subtime = (INT) next_subtime;
#endif /* TIC_DENO != 1 */
	clock = hw_timer_get_current();
	ireq = hw_timer_fetch_interrupt();
	if (!(locked)) {
		t_unlock_cpu();
	}

	utime = ((SYSUTIM) time) * 1000;
#if TIC_DENO != 1
	utime += subtime * 1000 / TIC_DENO;
#endif /* TIC_DENO != 1 */
	if (!(ireq && !(BEFORE_IREQ(clock)))) {
		utime -= TIC_NUME * 1000 / TIC_DENO;
	}
	utime += TO_USEC(clock);
	*p_sysutim = utime;
	ercd = E_OK;

    exit:
	LOG_VXGET_TIM_LEAVE(ercd, *p_sysutim);
	return(ercd);
}

#endif /* SUPPORT_VXGET_TIM */
#endif /* __vxget_tim */
