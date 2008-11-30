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
 *  @(#) $Id: task_sync.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�^�X�N�t�������@�\
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "wait.h"

/*
 *  �N���҂�
 */
#ifdef __slp_tsk

SYSCALL ER
slp_tsk()
{
	WINFO	winfo;
	ER	ercd;

	LOG_SLP_TSK_ENTER();
	CHECK_DISPATCH();

	t_lock_cpu();
	if (runtsk->wupcnt) {
		runtsk->wupcnt = FALSE;
		ercd = E_OK;
	}
	else {
		runtsk->tstat = (TS_WAITING | TS_WAIT_SLEEP);
		make_wait(&winfo);
		LOG_TSKSTAT(runtsk);
		dispatch();
		ercd = winfo.wercd;
	}
	t_unlock_cpu();

    exit:
	LOG_SLP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* __slp_tsk */

/*
 *  �N���҂��i�^�C���A�E�g����j
 */
#ifdef __tslp_tsk

SYSCALL ER
tslp_tsk(TMO tmout)
{
	WINFO	winfo;
	TMEVTB	tmevtb;
	ER	ercd;

	LOG_TSLP_TSK_ENTER(tmout);
	CHECK_DISPATCH();
	CHECK_TMOUT(tmout);

	t_lock_cpu();
	if (runtsk->wupcnt) {
		runtsk->wupcnt = FALSE;
		ercd = E_OK;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		runtsk->tstat = (TS_WAITING | TS_WAIT_SLEEP);
		make_wait_tmout(&winfo, &tmevtb, tmout);
		LOG_TSKSTAT(runtsk);
		dispatch();
		ercd = winfo.wercd;
	}
	t_unlock_cpu();

    exit:
	LOG_TSLP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* __tslp_tsk */

/*
 *  �^�X�N�̋N��
 */
#ifdef __wup_tsk

SYSCALL ER
wup_tsk(ID tskid)
{
	TCB	*tcb;
	UINT	tstat;
	ER	ercd;

	LOG_WUP_TSK_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(tstat = tcb->tstat)) {
		ercd = E_OBJ;
	}
	else if ((tstat & TS_WAIT_SLEEP) != 0) {
		if (wait_complete(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (!(tcb->wupcnt)) {
		tcb->wupcnt = TRUE;
		ercd = E_OK;
	}
	else {
		ercd = E_QOVR;
	}
	t_unlock_cpu();

    exit:
	LOG_WUP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* __wup_tsk */

/*
 *  �^�X�N�̋N���i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef __iwup_tsk

SYSCALL ER
iwup_tsk(ID tskid)
{
	TCB	*tcb;
	UINT	tstat;
	ER	ercd;

	LOG_IWUP_TSK_ENTER(tskid);
	CHECK_INTCTX_UNL();
	CHECK_TSKID(tskid);
	tcb = get_tcb(tskid);

	i_lock_cpu();
	if (TSTAT_DORMANT(tstat = tcb->tstat)) {
		ercd = E_OBJ;
	}
	else if ((tstat & TS_WAIT_SLEEP) != 0) {
		if (wait_complete(tcb)) {
			reqflg = TRUE;
		}
		ercd = E_OK;
	}
	else if (!(tcb->wupcnt)) {
		tcb->wupcnt = TRUE;
		ercd = E_OK;
	}
	else {
		ercd = E_QOVR;
	}
	i_unlock_cpu();

    exit:
	LOG_IWUP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* __iwup_tsk */

/*
 *  �^�X�N�N���v���̃L�����Z��
 */
#ifdef __can_wup

SYSCALL ER_UINT
can_wup(ID tskid)
{
	TCB	*tcb;
	ER_UINT	ercd;

	LOG_CAN_WUP_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(tcb->tstat)) {
		ercd = E_OBJ;
	}
	else {
		ercd = tcb->wupcnt ? 1 : 0;
		tcb->wupcnt = FALSE;
	}
	t_unlock_cpu();

    exit:
	LOG_CAN_WUP_LEAVE(ercd);
	return(ercd);
}

#endif /* __can_wup */

/*
 *  �҂���Ԃ̋�������
 */
#ifdef __rel_wai

SYSCALL ER
rel_wai(ID tskid)
{
	TCB	*tcb;
	ER	ercd;

	LOG_REL_WAI_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID(tskid);
	tcb = get_tcb(tskid);

	t_lock_cpu();
	if (!(TSTAT_WAITING(tcb->tstat))) {
		ercd = E_OBJ;
	}
	else {
		if (wait_release(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

    exit:
	LOG_REL_WAI_LEAVE(ercd);
	return(ercd);
}

#endif /* __rel_wai */

/*
 *  �҂���Ԃ̋��������i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef __irel_wai

SYSCALL ER
irel_wai(ID tskid)
{
	TCB	*tcb;
	ER	ercd;

	LOG_IREL_WAI_ENTER(tskid);
	CHECK_INTCTX_UNL();
	CHECK_TSKID(tskid);
	tcb = get_tcb(tskid);

	i_lock_cpu();
	if (!(TSTAT_WAITING(tcb->tstat))) {
		ercd = E_OBJ;
	}
	else {
		if (wait_release(tcb)) {
			reqflg = TRUE;
		}
		ercd = E_OK;
	}
	i_unlock_cpu();

    exit:
	LOG_IREL_WAI_LEAVE(ercd);
	return(ercd);
}

#endif /* __irel_wai */

/*
 *  �����҂���Ԃւ̈ڍs
 */
#ifdef __sus_tsk

SYSCALL ER
sus_tsk(ID tskid)
{
	TCB	*tcb;
	UINT	tstat;
	ER	ercd;

	LOG_SUS_TSK_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (tcb == runtsk && !(enadsp)) {
		ercd = E_CTX;
	}
	else if (TSTAT_DORMANT(tstat = tcb->tstat)) {
		ercd = E_OBJ;
	}
	else if (TSTAT_RUNNABLE(tstat)) {
		/*
		 *  ���s�ł����Ԃ��狭���҂���Ԃւ̑J��
		 */
		tcb->tstat = TS_SUSPENDED;
		LOG_TSKSTAT(tcb);
		if (make_non_runnable(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (TSTAT_SUSPENDED(tstat)) {
		ercd = E_QOVR;
	}
	else {
		/*
		 *  �҂���Ԃ����d�҂���Ԃւ̑J��
		 */
		tcb->tstat |= TS_SUSPENDED;
		LOG_TSKSTAT(tcb);
		ercd = E_OK;
	}
	t_unlock_cpu();

    exit:
	LOG_SUS_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* __sus_tsk */

/*
 *  �����҂���Ԃ���̍ĊJ
 */
#ifdef __rsm_tsk

SYSCALL ER
rsm_tsk(ID tskid)
{
	TCB	*tcb;
	UINT	tstat;
	ER	ercd;

	LOG_RSM_TSK_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID(tskid);
	tcb = get_tcb(tskid);

	t_lock_cpu();
	if (!(TSTAT_SUSPENDED(tstat = tcb->tstat))) {
		ercd = E_OBJ;
	}
	else if (!(TSTAT_WAITING(tstat))) {
		/*
		 *  �����҂���Ԃ�����s�ł����Ԃւ̑J��
		 */
		if (make_runnable(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else {
		/*
		 *  ��d�҂���Ԃ���҂���Ԃւ̑J��
		 */
		tcb->tstat &= ~TS_SUSPENDED;
		LOG_TSKSTAT(tcb);
		ercd = E_OK;
	}
	t_unlock_cpu();

    exit:
	LOG_RSM_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* __rsm_tsk */

/*
 *  �����҂���Ԃ���̋����ĊJ
 *
 *  JSP�J�[�l���ł́Cfrsm_tsk �� rsm_tsk �͓���̏����ƂȂ�Dfrsm_tsk 
 *  ���Ă΂��ƁCfrsm_tsk �� rsm_tsk �̗����̃T�[�r�X�R�[���̃g���[�X
 *  ���O���o�͂����D���O�擾��� rsm_tsk �̃g���[�X���O���폜���邱
 *  �Ƃ��K�v�ł���Drsm_tsk �̃g���[�X���O�𐳂����폜���邽�߂ɂ́C�^
 *  �X�N�f�B�X�p�b�`�̃��O�ƁC�^�X�N��O�����̃��O���擾���邱�Ƃ��K�v
 *  �ƂȂ�̂ŁC���ӂ��K�v�ł���D
 */
#ifdef __frsm_tsk

SYSCALL ER
frsm_tsk(ID tskid)
{
	ER	ercd;

	LOG_FRSM_TSK_ENTER(tskid);
	ercd = rsm_tsk(tskid);
	LOG_FRSM_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* __frsm_tsk */

/*
 *  ���^�X�N�̒x��
 */
#ifdef __dly_tsk

SYSCALL ER
dly_tsk(RELTIM dlytim)
{
	WINFO	winfo;
	TMEVTB	tmevtb;
	ER	ercd;

	LOG_DLY_TSK_ENTER(dlytim);
	CHECK_DISPATCH();
	CHECK_PAR(dlytim <= TMAX_RELTIM);

	t_lock_cpu();
	runtsk->tstat = TS_WAITING;
	make_non_runnable(runtsk);
	runtsk->winfo = &winfo;
	winfo.tmevtb = &tmevtb;
	tmevtb_enqueue(&tmevtb, dlytim, (CBACK) wait_tmout_ok, (VP) runtsk);
	LOG_TSKSTAT(runtsk);
	dispatch();
	ercd = winfo.wercd;
	t_unlock_cpu();

    exit:
	LOG_DLY_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* __dly_tsk */
