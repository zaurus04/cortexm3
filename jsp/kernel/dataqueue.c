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
 *  @(#) $Id: dataqueue.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�f�[�^�L���[�@�\
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "wait.h"
#include "dataqueue.h"

/*
 *  �f�[�^�L���[ID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_dtqid;

/*
 *  �f�[�^�L���[�������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const DTQINIB	dtqinib_table[];

/*
 *  �f�[�^�L���[�̐�
 */
#define TNUM_DTQ	((UINT)(tmax_dtqid - TMIN_DTQID + 1))

/*
 *  �f�[�^�L���[�Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern DTQCB	dtqcb_table[];

/*
 *  �f�[�^�L���[ID����f�[�^�L���[�Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_DTQ(dtqid)	((UINT)((dtqid) - TMIN_DTQID))
#define get_dtqcb(dtqid)	(&(dtqcb_table[INDEX_DTQ(dtqid)]))

/*
 *  �f�[�^�L���[�҂����u���b�N�̒�`
 *
 *  �f�[�^�L���[�ւ̑��M�҂��ƃf�[�^�L���[����̎�M�҂��ŁC�����҂���
 *  ��u���b�N���g���D
 */
typedef struct dataqueue_waiting_information {
	WINFO	winfo;		/* �W���̑҂����u���b�N */
	WOBJCB	*wobjcb;	/* �҂��I�u�W�F�N�g�̊Ǘ��u���b�N */
	VP_INT	data;		/* ����M�f�[�^  */
} WINFO_DTQ;

/*
 *  �f�[�^�L���[�@�\�̏�����
 */
#ifdef __dtqini

void
dataqueue_initialize(void)
{
	UINT	i;
	DTQCB	*dtqcb;

	for (dtqcb = dtqcb_table, i = 0; i < TNUM_DTQ; dtqcb++, i++) {
		queue_initialize(&(dtqcb->swait_queue));
		dtqcb->dtqinib = &(dtqinib_table[i]);
		queue_initialize(&(dtqcb->rwait_queue));
		dtqcb->count = 0;
		dtqcb->head = 0;
		dtqcb->tail = 0;
	}
}

#endif /* __dtqini */

/*
 *  �f�[�^�L���[�̈�Ƀf�[�^���i�[
 */
#ifdef __dtqenq

BOOL
enqueue_data(DTQCB *dtqcb, VP_INT data)
{
	if (dtqcb->count < dtqcb->dtqinib->dtqcnt) {
		*((VP_INT *)(dtqcb->dtqinib->dtq) + dtqcb->tail) = data;
		dtqcb->count++;
		dtqcb->tail++;
		if (dtqcb->tail >= dtqcb->dtqinib->dtqcnt) {
			dtqcb->tail = 0;
		}
		return(TRUE);
	}
	return(FALSE);
}

#endif /* __dtqenq */

/*
 *  �f�[�^�L���[�̈�Ƀf�[�^�������i�[
 */
#ifdef __dtqfenq

void
force_enqueue_data(DTQCB *dtqcb, VP_INT data)
{
	*((VP_INT *)(dtqcb->dtqinib->dtq) + dtqcb->tail) = data;
	dtqcb->tail++;
	if (dtqcb->tail >= dtqcb->dtqinib->dtqcnt) {
		dtqcb->tail = 0;
	}
	if (dtqcb->count < dtqcb->dtqinib->dtqcnt) {
		dtqcb->count++;
	}
	else {
		dtqcb->head = dtqcb->tail;
	}
}

#endif /* __dtqfenq */

/*
 *  �f�[�^�L���[�̈悩��f�[�^����o��
 */
#ifdef __dtqdeq

BOOL
dequeue_data(DTQCB *dtqcb, VP_INT *p_data)
{
	if (dtqcb->count > 0) {
		*p_data = *((VP_INT *)(dtqcb->dtqinib->dtq) + dtqcb->head);
		dtqcb->count--;
		dtqcb->head++;
		if (dtqcb->head >= dtqcb->dtqinib->dtqcnt) {
			dtqcb->head = 0;
		}
		return(TRUE);
	}
	return(FALSE);
}

#endif /* __dtqdeq */

/*
 *  ��M�҂��L���[�̐擪�^�X�N�ւ̃f�[�^���M
 */
#ifdef __dtqsnd

TCB *
send_data_rwait(DTQCB *dtqcb, VP_INT data)
{
	TCB	*tcb;

	if (!(queue_empty(&(dtqcb->rwait_queue)))) {
		tcb = (TCB *) queue_delete_next(&(dtqcb->rwait_queue));
		((WINFO_DTQ *)(tcb->winfo))->data = data;
		return(tcb);
	}
	return(NULL);
}

#endif /* __dtqsnd */

/*
 *  ���M�҂��L���[�̐擪�^�X�N����̃f�[�^��M
 */
#ifdef __dtqrcv

TCB *
receive_data_swait(DTQCB *dtqcb, VP_INT *p_data)
{
	TCB	*tcb;

	if (!(queue_empty(&(dtqcb->swait_queue)))) {
		tcb = (TCB *) queue_delete_next(&(dtqcb->swait_queue));
		*p_data = ((WINFO_DTQ *)(tcb->winfo))->data;
		return(tcb);
	}
	return(NULL);
}

#endif /* __dtqrcv */

/*
 *  �f�[�^�L���[�ւ̑��M
 */
#ifdef __snd_dtq

SYSCALL ER
snd_dtq(ID dtqid, VP_INT data)
{
	DTQCB	*dtqcb;
	WINFO_DTQ winfo;
	TCB	*tcb;
	ER	ercd;

	LOG_SND_DTQ_ENTER(dtqid, data);
	CHECK_DISPATCH();
	CHECK_DTQID(dtqid);
	dtqcb = get_dtqcb(dtqid);

	t_lock_cpu();
	if ((tcb = send_data_rwait(dtqcb, data)) != NULL) {
		if (wait_complete(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (enqueue_data(dtqcb, data)) {
		ercd = E_OK;
	}
	else {
		winfo.data = data;
		wobj_make_wait((WOBJCB *) dtqcb, (WINFO_WOBJ *) &winfo);
		dispatch();
		ercd = winfo.winfo.wercd;
	}
	t_unlock_cpu();

    exit:
	LOG_SND_DTQ_LEAVE(ercd);
	return(ercd);
}

#endif /* __snd_dtq */

/*
 *  �f�[�^�L���[�ւ̑��M�i�|�[�����O�j
 */
#ifdef __psnd_dtq

SYSCALL ER
psnd_dtq(ID dtqid, VP_INT data)
{
	DTQCB	*dtqcb;
	TCB	*tcb;
	ER	ercd;

	LOG_PSND_DTQ_ENTER(dtqid, data);
	CHECK_TSKCTX_UNL();
	CHECK_DTQID(dtqid);
	dtqcb = get_dtqcb(dtqid);

	t_lock_cpu();
	if ((tcb = send_data_rwait(dtqcb, data)) != NULL) {
		if (wait_complete(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (enqueue_data(dtqcb, data)) {
		ercd = E_OK;
	}
	else {
		ercd = E_TMOUT;
	}
	t_unlock_cpu();

    exit:
	LOG_PSND_DTQ_LEAVE(ercd);
	return(ercd);
}

#endif /* __psnd_dtq */

/*
 *  �f�[�^�L���[�ւ̑��M�i�|�[�����O�C��^�X�N�R���e�L�X�g�p�j
 */
#ifdef __ipsnd_dtq

SYSCALL ER
ipsnd_dtq(ID dtqid, VP_INT data)
{
	DTQCB	*dtqcb;
	TCB	*tcb;
	ER	ercd;

	LOG_IPSND_DTQ_ENTER(dtqid, data);
	CHECK_INTCTX_UNL();
	CHECK_DTQID(dtqid);
	dtqcb = get_dtqcb(dtqid);

	i_lock_cpu();
	if ((tcb = send_data_rwait(dtqcb, data)) != NULL) {
		if (wait_complete(tcb)) {
			reqflg = TRUE;
		}
		ercd = E_OK;
	}
	else if (enqueue_data(dtqcb, data)) {
		ercd = E_OK;
	}
	else {
		ercd = E_TMOUT;
	}
	i_unlock_cpu();

    exit:
	LOG_IPSND_DTQ_LEAVE(ercd);
	return(ercd);
}

#endif /* __ipsnd_dtq */

/*
 *  �f�[�^�L���[�ւ̑��M�i�^�C���A�E�g����j
 */
#ifdef __tsnd_dtq

SYSCALL ER
tsnd_dtq(ID dtqid, VP_INT data, TMO tmout)
{
	DTQCB	*dtqcb;
	WINFO_DTQ winfo;
	TMEVTB	tmevtb;
	TCB	*tcb;
	ER	ercd;

	LOG_TSND_DTQ_ENTER(dtqid, data, tmout);
	CHECK_DISPATCH();
	CHECK_DTQID(dtqid);
	CHECK_TMOUT(tmout);
	dtqcb = get_dtqcb(dtqid);

	t_lock_cpu();
	if ((tcb = send_data_rwait(dtqcb, data)) != NULL) {
		if (wait_complete(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (enqueue_data(dtqcb, data)) {
		ercd = E_OK;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		winfo.data = data;
		wobj_make_wait_tmout((WOBJCB *) dtqcb, (WINFO_WOBJ *) &winfo,
						&tmevtb, tmout);
		dispatch();
		ercd = winfo.winfo.wercd;
	}
	t_unlock_cpu();

    exit:
	LOG_TSND_DTQ_LEAVE(ercd);
	return(ercd);
}

#endif /* __tsnd_dtq */

/*
 *  �f�[�^�L���[�ւ̋������M
 */
#ifdef __fsnd_dtq

SYSCALL ER
fsnd_dtq(ID dtqid, VP_INT data)
{
	DTQCB	*dtqcb;	
	TCB	*tcb;
	ER	ercd;

	LOG_FSND_DTQ_ENTER(dtqid, data);
	CHECK_TSKCTX_UNL();
	CHECK_DTQID(dtqid);
	dtqcb = get_dtqcb(dtqid);
	CHECK_ILUSE(dtqcb->dtqinib->dtqcnt > 0);

	t_lock_cpu();
	if ((tcb = send_data_rwait(dtqcb, data)) != NULL) {
		if (wait_complete(tcb)) {
			dispatch();
		}
	}
	else {
		force_enqueue_data(dtqcb, data);
	}
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_FSND_DTQ_LEAVE(ercd);
	return(ercd);
}

#endif /* __fsnd_dtq */

/*
 *  �f�[�^�L���[�ւ̋������M�i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef __ifsnd_dtq

SYSCALL ER
ifsnd_dtq(ID dtqid, VP_INT data)
{
	DTQCB	*dtqcb;
	TCB	*tcb;
	ER	ercd;

	LOG_IFSND_DTQ_ENTER(dtqid, data);
	CHECK_INTCTX_UNL();
	CHECK_DTQID(dtqid);
	dtqcb = get_dtqcb(dtqid);
	CHECK_ILUSE(dtqcb->dtqinib->dtqcnt > 0);

	i_lock_cpu();
	if ((tcb = send_data_rwait(dtqcb, data)) != NULL) {
		if (wait_complete(tcb)) {
			reqflg = TRUE;
		}
	}
	else {
		force_enqueue_data(dtqcb, data);
	}
	ercd = E_OK;
	i_unlock_cpu();

    exit:
	LOG_IFSND_DTQ_LEAVE(ercd);
	return(ercd);
}

#endif /* __ifsnd_dtq */

/*
 *  �f�[�^�L���[����̎�M
 */
#ifdef __rcv_dtq

SYSCALL ER
rcv_dtq(ID dtqid, VP_INT *p_data)
{
	DTQCB	*dtqcb;
	WINFO_DTQ winfo;
	TCB	*tcb;
	VP_INT	data;
	ER	ercd;

	LOG_RCV_DTQ_ENTER(dtqid, p_data);
	CHECK_DISPATCH();
	CHECK_DTQID(dtqid);
	dtqcb = get_dtqcb(dtqid);

	t_lock_cpu();
	if (dequeue_data(dtqcb, p_data)) {
		if ((tcb = receive_data_swait(dtqcb, &data)) != NULL) {
			enqueue_data(dtqcb, data);
			if (wait_complete(tcb)) {
				dispatch();
			}
		}
		ercd = E_OK;
	}
	else if ((tcb = receive_data_swait(dtqcb, p_data)) != NULL) {
		if (wait_complete(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else {
		runtsk->tstat = (TS_WAITING | TS_WAIT_WOBJ);
		make_wait(&(winfo.winfo));
		queue_insert_prev(&(dtqcb->rwait_queue),
					&(runtsk->task_queue));
		winfo.wobjcb = (WOBJCB *) dtqcb;
		LOG_TSKSTAT(runtsk);
		dispatch();
		ercd = winfo.winfo.wercd;
		if (ercd == E_OK) {
			*p_data = winfo.data;
		}
	}
	t_unlock_cpu();

    exit:
	LOG_RCV_DTQ_LEAVE(ercd, *p_data);
	return(ercd);
}

#endif /* __rcv_dtq */

/*
 *  �f�[�^�L���[����̎�M�i�|�[�����O�j
 */
#ifdef __prcv_dtq

SYSCALL ER
prcv_dtq(ID dtqid, VP_INT *p_data)
{
	DTQCB	*dtqcb;
	TCB	*tcb;
	VP_INT	data;
	ER	ercd;

	LOG_PRCV_DTQ_ENTER(dtqid, p_data);
	CHECK_TSKCTX_UNL();
	CHECK_DTQID(dtqid);
	dtqcb = get_dtqcb(dtqid);

	t_lock_cpu();
	if (dequeue_data(dtqcb, p_data)) {
		if ((tcb = receive_data_swait(dtqcb, &data)) != NULL) {
			enqueue_data(dtqcb, data);
			if (wait_complete(tcb)) {
				dispatch();
			}
		}
		ercd = E_OK;
	}
	else if ((tcb = receive_data_swait(dtqcb, p_data)) != NULL) {
		if (wait_complete(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else {
		ercd = E_TMOUT;
	}
	t_unlock_cpu();

    exit:
	LOG_PRCV_DTQ_LEAVE(ercd, *p_data);
	return(ercd);
}

#endif /* __prcv_dtq */

/*
 *  �f�[�^�L���[����̎�M�i�^�C���A�E�g����j
 */
#ifdef __trcv_dtq

SYSCALL ER
trcv_dtq(ID dtqid, VP_INT *p_data, TMO tmout)
{
	DTQCB	*dtqcb;
	WINFO_DTQ winfo;
	TMEVTB	tmevtb;
	TCB	*tcb;
	VP_INT	data;
	ER	ercd;

	LOG_TRCV_DTQ_ENTER(dtqid, p_data, tmout);
	CHECK_DISPATCH();
	CHECK_DTQID(dtqid);
	CHECK_TMOUT(tmout);
	dtqcb = get_dtqcb(dtqid);

	t_lock_cpu();
	if (dequeue_data(dtqcb, p_data)) {
		if ((tcb = receive_data_swait(dtqcb, &data)) != NULL) {
			enqueue_data(dtqcb, data);
			if (wait_complete(tcb)) {
				dispatch();
			}
		}
		ercd = E_OK;
	}
	else if ((tcb = receive_data_swait(dtqcb, p_data)) != NULL) {
		if (wait_complete(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		runtsk->tstat = (TS_WAITING | TS_WAIT_WOBJ);
		make_wait_tmout(&(winfo.winfo), &tmevtb, tmout);
		queue_insert_prev(&(dtqcb->rwait_queue),
					&(runtsk->task_queue));
		winfo.wobjcb = (WOBJCB *) dtqcb;
		LOG_TSKSTAT(runtsk);
		dispatch();
		ercd = winfo.winfo.wercd;
		if (ercd == E_OK) {
			*p_data = winfo.data;
		}
	}
	t_unlock_cpu();

    exit:
	LOG_TRCV_DTQ_LEAVE(ercd, *p_data);
	return(ercd);
}

#endif /* __trcv_dtq */
