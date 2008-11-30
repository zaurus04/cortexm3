/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2008 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: wait.c 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�Ԥ����ִ����⥸�塼��
 */

#include "kernel_impl.h"
#include "wait.h"

/*
 *  �Ԥ����֤ؤΰܹԡʥ����ॢ���Ȼ����
 */
#ifdef TOPPERS_waimake

void
make_wait_tmout(WINFO *p_winfo, TMEVTB *p_tmevtb, TMO tmout)
{
	(void) make_non_runnable(p_runtsk);
	p_runtsk->p_winfo = p_winfo;
	if (tmout > 0) {
		p_winfo->p_tmevtb = p_tmevtb;
		tmevtb_enqueue(p_tmevtb, (RELTIM) tmout,
						(CBACK) wait_tmout, (void *) p_runtsk);
	}
	else {
		assert(tmout == TMO_FEVR);
		p_winfo->p_tmevtb = NULL;
	}
}

#endif /* TOPPERS_waimake */

/*
 *  �Ԥ�����Τ���Υ��������֤ι���
 *
 *  p_tcb�ǻ��ꤵ��륿�������Ԥ��������褦���������֤򹹿����롥
 *  �Ԥ�������륿�������¹ԤǤ�����֤ˤʤ���ϡ���ǥ����塼�ˤĤ�
 *  �����ޤ����ǥ����ѥå���ɬ�פʾ��ˤ�true���֤���
 */
Inline bool_t
make_non_wait(TCB *p_tcb)
{
	assert(TSTAT_WAITING(p_tcb->tstat));

	if (!TSTAT_SUSPENDED(p_tcb->tstat)) {
		/*
		 *  �Ԥ����֤���¹ԤǤ�����֤ؤ�����
		 */
		return(make_runnable(p_tcb));
	}
	else {
		/*
		 *  ����Ԥ����֤��鶯���Ԥ����֤ؤ�����
		 */
		p_tcb->tstat = TS_SUSPENDED;
		LOG_TSKSTAT(p_tcb);
		return(false);
	}
}

/*
 *  �Ԥ����
 */
#ifdef TOPPERS_waicmp

bool_t
wait_complete(TCB *p_tcb)
{
	wait_dequeue_tmevtb(p_tcb);
	p_tcb->p_winfo->wercd = E_OK;
	return(make_non_wait(p_tcb));
}

#endif /* TOPPERS_waicmp */

/*
 *  �����ॢ���Ȥ�ȼ���Ԥ����
 */
#ifdef TOPPERS_waitmo

void
wait_tmout(TCB *p_tcb)
{
	wait_dequeue_wobj(p_tcb);
	p_tcb->p_winfo->wercd = E_TMOUT;
	if (make_non_wait(p_tcb)) {
		reqflg = true;
	}

	/*
	 *  ������ͥ���٤ι⤤����ߤ�����դ��롥
	 */
	i_unlock_cpu();
	i_lock_cpu();
}

#endif /* TOPPERS_waitmo */
#ifdef TOPPERS_waitmook

void
wait_tmout_ok(TCB *p_tcb)
{
	p_tcb->p_winfo->wercd = E_OK;
	if (make_non_wait(p_tcb)) {
		reqflg = true;
	}

	/*
	 *  ������ͥ���٤ι⤤����ߤ�����դ��롥
	 */
	i_unlock_cpu();
	i_lock_cpu();
}

#endif /* TOPPERS_waitmook */

/*
 *  �Ԥ����֤ζ������
 */
#ifdef TOPPERS_wairel

bool_t
wait_release(TCB *p_tcb)
{
	wait_dequeue_wobj(p_tcb);
	wait_dequeue_tmevtb(p_tcb);
	p_tcb->p_winfo->wercd = E_RLWAI;
	return(make_non_wait(p_tcb));
}

#endif /* TOPPERS_wairel */

/*
 *  �¹���Υ�������Ʊ�����̿����֥������Ȥ��Ԥ����塼�ؤ�����
 *
 *  �¹���Υ�������Ʊ�����̿����֥������Ȥ��Ԥ����塼���������롥��
 *  �֥������Ȥ�°���˱����ơ�FIFO��ޤ��ϥ�����ͥ���ٽ���������롥
 */
Inline void
wobj_queue_insert(WOBJCB *p_wobjcb)
{
	if ((p_wobjcb->p_wobjinib->wobjatr & TA_TPRI) != 0U) {
		queue_insert_tpri(&(p_wobjcb->wait_queue), p_runtsk);
	}
	else {
		queue_insert_prev(&(p_wobjcb->wait_queue), &(p_runtsk->task_queue));
	}
}

/*
 *  Ʊ�����̿����֥������Ȥ��Ф����Ԥ����֤ؤΰܹ�
 */
#ifdef TOPPERS_wobjwai

void
wobj_make_wait(WOBJCB *p_wobjcb, WINFO_WOBJ *p_winfo_wobj)
{
	make_wait((WINFO *) p_winfo_wobj);
	wobj_queue_insert(p_wobjcb);
	p_winfo_wobj->p_wobjcb = p_wobjcb;
	LOG_TSKSTAT(p_runtsk);
}

#endif /* TOPPERS_wobjwai */
#ifdef TOPPERS_wobjwaitmo

void
wobj_make_wait_tmout(WOBJCB *p_wobjcb, WINFO_WOBJ *p_winfo_wobj,
								TMEVTB *p_tmevtb, TMO tmout)
{
	make_wait_tmout((WINFO *) p_winfo_wobj, p_tmevtb, tmout);
	wobj_queue_insert(p_wobjcb);
	p_winfo_wobj->p_wobjcb = p_wobjcb;
	LOG_TSKSTAT(p_runtsk);
}

#endif /* TOPPERS_wobjwaitmo */

/*
 *  �Ԥ����塼�ν����
 */
#ifdef TOPPERS_iniwque

bool_t
init_wait_queue(QUEUE *p_wait_queue)
{
	TCB		*p_tcb;
	bool_t	dspreq = false;

	while (!queue_empty(p_wait_queue)) {
		p_tcb = (TCB *) queue_delete_next(p_wait_queue);
		wait_dequeue_tmevtb(p_tcb);
		p_tcb->p_winfo->wercd = E_DLT;
		if (make_non_wait(p_tcb)) {
			dspreq = true;
		};
	}
	return(dspreq);
}

#endif /* TOPPERS_iniwque */
