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
 *  @(#) $Id: wait.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�҂���ԊǗ����W���[��
 */

#include "jsp_kernel.h"
#include "wait.h"

/*
 *  �҂���Ԃւ̈ڍs�i�^�C���A�E�g�w��j
 *
 */
#ifdef __waimake

void
make_wait_tmout(WINFO *winfo, TMEVTB *tmevtb, TMO tmout)
{
	make_non_runnable(runtsk);
	runtsk->winfo = winfo;
	if (tmout > 0) {
		winfo->tmevtb = tmevtb;
		tmevtb_enqueue(tmevtb, (RELTIM) tmout,
					(CBACK) wait_tmout, (VP) runtsk);
	}
	else {
		assert(tmout == TMO_FEVR);
		winfo->tmevtb = NULL;
	}
}

#endif /* __waimake */

/*
 *  �҂������̂��߂̃^�X�N��Ԃ̍X�V
 *
 *  tcb �Ŏw�肳���^�X�N���C�҂���������悤�^�X�N��Ԃ��X�V����D��
 *  ����������^�X�N�����s�ł����ԂɂȂ�ꍇ�́C���f�B�L���[�ɂȂ��D
 *  �܂��C�f�B�X�p�b�`���K�v�ȏꍇ�ɂ� TRUE ��Ԃ��D
 */
Inline BOOL
make_non_wait(TCB *tcb)
{
	assert(TSTAT_WAITING(tcb->tstat));

	if (!(TSTAT_SUSPENDED(tcb->tstat))) {
		/*
		 *  �҂���Ԃ�����s�ł����Ԃւ̑J��
		 */
		return(make_runnable(tcb));
	}
	else {
		/*
		 *  ��d�҂���Ԃ��狭���҂���Ԃւ̑J��
		 */
		tcb->tstat = TS_SUSPENDED;
		LOG_TSKSTAT(tcb);
		return(FALSE);
	}
}

/*
 *  �҂�����
 */
#ifdef __waicmp

BOOL
wait_complete(TCB *tcb)
{
	if (tcb->winfo->tmevtb != NULL) {
		tmevtb_dequeue(tcb->winfo->tmevtb);
	}
	tcb->winfo->wercd = E_OK;
	return(make_non_wait(tcb));
}

#endif /* __waicmp */

/*
 *  �^�C���A�E�g�ɔ����҂�����
 */
#ifdef __waitmo

void
wait_tmout(TCB *tcb)
{
	if ((tcb->tstat & TS_WAIT_WOBJ) != 0) {
		queue_delete(&(tcb->task_queue));
	}
	tcb->winfo->wercd = E_TMOUT;
	if (make_non_wait(tcb)) {
		reqflg = TRUE;
	}
}

#endif /* __waitmo */
#ifdef __waitmook

void
wait_tmout_ok(TCB *tcb)
{
	tcb->winfo->wercd = E_OK;
	if (make_non_wait(tcb)) {
		reqflg = TRUE;
	}
}

#endif /* __waitmook */

/*
 *  �҂���Ԃ̋�������
 */
#ifdef __waican

void
wait_cancel(TCB *tcb)
{
	if (tcb->winfo->tmevtb != NULL) {
		tmevtb_dequeue(tcb->winfo->tmevtb);
	}
	if ((tcb->tstat & TS_WAIT_WOBJ) != 0) {
		queue_delete(&(tcb->task_queue));
	}
}

#endif /* __waican */
#ifdef __wairel

BOOL
wait_release(TCB *tcb)
{
	wait_cancel(tcb);
	tcb->winfo->wercd = E_RLWAI;
	return(make_non_wait(tcb));
}

#endif /* __wairel */

/*
 *  �^�X�N�̗D��x���̑҂��L���[�ւ̑}��
 */
Inline void
queue_insert_tpri(TCB *tcb, QUEUE *queue)
{
	QUEUE	*entry;
	UINT	priority = tcb->priority;

	for (entry = queue->next; entry != queue; entry = entry->next) {
		if (priority < ((TCB *) entry)->priority) {
			break;
		}
	}
	queue_insert_prev(entry, &(tcb->task_queue));
}

/*
 *  ���s���̃^�X�N�̓����E�ʐM�I�u�W�F�N�g�̑҂��L���[�ւ̑}��
 */
Inline void
wobj_queue_insert(WOBJCB *wobjcb)
{
	if ((wobjcb->wobjinib->wobjatr & TA_TPRI) != 0) {
		queue_insert_tpri(runtsk, &(wobjcb->wait_queue));
	}
	else {
		queue_insert_prev(&(wobjcb->wait_queue),
					&(runtsk->task_queue));
	}
}

/*
 *  �����E�ʐM�I�u�W�F�N�g�ɑ΂���҂���Ԃւ̈ڍs
 */
#ifdef __wobjwai

void
wobj_make_wait(WOBJCB *wobjcb, WINFO_WOBJ *winfo)
{
	runtsk->tstat = (TS_WAITING | TS_WAIT_WOBJ | TS_WAIT_WOBJCB);
	make_wait(&(winfo->winfo));
	wobj_queue_insert(wobjcb);
	winfo->wobjcb = wobjcb;
	LOG_TSKSTAT(runtsk);
}

#endif /* __wobjwai */
#ifdef __wobjwaitmo

void
wobj_make_wait_tmout(WOBJCB *wobjcb, WINFO_WOBJ *winfo,
					TMEVTB *tmevtb, TMO tmout)
{
	runtsk->tstat = (TS_WAITING | TS_WAIT_WOBJ | TS_WAIT_WOBJCB);
	make_wait_tmout(&(winfo->winfo), tmevtb, tmout);
	wobj_queue_insert(wobjcb);
	winfo->wobjcb = wobjcb;
	LOG_TSKSTAT(runtsk);
}

#endif /* __wobjwaitmo */
/*
 *  �^�X�N�̗D��x�ύX���̏���
 */
#ifdef __wobjpri

void
wobj_change_priority(WOBJCB *wobjcb, TCB *tcb)
{
	if ((wobjcb->wobjinib->wobjatr & TA_TPRI) != 0) {
		queue_delete(&(tcb->task_queue));
		queue_insert_tpri(tcb, &(wobjcb->wait_queue));
	}
}

#endif /* __wobjpri */
