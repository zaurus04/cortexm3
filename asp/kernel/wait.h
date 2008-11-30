/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: wait.h 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�Ԥ����ִ����⥸�塼��
 */

#ifndef TOPPERS_WAIT_H
#define TOPPERS_WAIT_H

#include "task.h"
#include "time_event.h"

/*
 *  ��������ͥ���ٽ���Ԥ����塼�ؤ�����
 *
 *  p_tcb�ǻ��ꤵ��륿�����򡤥�����ͥ���ٽ�Υ��塼p_queue���������롥
 *  ���塼�����Ʊ��ͥ���٤Υ�������������ˤϡ����κǸ���������롥
 */
Inline void
queue_insert_tpri(QUEUE *p_queue, TCB *p_tcb)
{
	QUEUE	*p_entry;
	uint_t	priority = p_tcb->priority;

	for (p_entry = p_queue->p_next; p_entry != p_queue;
										p_entry = p_entry->p_next) {
		if (priority < ((TCB *) p_entry)->priority) {
			break;
		}
	}
	queue_insert_prev(p_entry, &(p_tcb->task_queue));
}

/*
 *  �Ԥ����֤ؤΰܹ�
 *
 *  �¹���Υ��������Ԥ����֤˰ܹԤ����롥����Ū�ˤϡ��¹���Υ�������
 *  ��ǥ����塼����������TCB��p_winfo�ե�����ɡ�WINFO��p_tmevtb�ե���
 *  ��ɤ����ꤹ�롥
 */
Inline void
make_wait(WINFO *p_winfo)
{
	(void) make_non_runnable(p_runtsk);
	p_runtsk->p_winfo = p_winfo;
	p_winfo->p_tmevtb = NULL;
}

/*
 *  �Ԥ����֤ؤΰܹԡʥ����ॢ���Ȼ����
 *
 *  �¹���Υ������򡤥����ॢ���Ȼ����դ����Ԥ����֤˰ܹԤ����롥����
 *  Ū�ˤϡ��¹���Υ��������ǥ����塼����������TCB��p_winfo�ե���
 *  ��ɡ�WINFO��p_tmevtb�ե�����ɤ����ꤹ�롥�ޤ��������।�٥�ȥ�
 *  ��å�����Ͽ���롥
 */
extern void	make_wait_tmout(WINFO *p_winfo, TMEVTB *p_tmevtb, TMO tmout);

/*
 *  ���֥��������Ԥ����塼����κ��
 *
 *  p_tcb�ǻ��ꤵ��륿��������Ʊ�����̿����֥������Ȥ��Ԥ����塼�ˤ�
 *  �ʤ���Ƥ���С��Ԥ����塼���������롥
 */
Inline void
wait_dequeue_wobj(TCB *p_tcb)
{
	if (TSTAT_WAIT_WOBJ(p_tcb->tstat)) {
		queue_delete(&(p_tcb->task_queue));
	}
}

/*
 *  �����Ԥ��Τ���Υ����।�٥�ȥ֥�å�����Ͽ���
 *
 *  p_tcb�ǻ��ꤵ��륿�������Ф��ơ������Ԥ��Τ���Υ����।�٥�ȥ�
 *  ��å�����Ͽ����Ƥ���С��������Ͽ������롥
 */
Inline void
wait_dequeue_tmevtb(TCB *p_tcb)
{
	if (p_tcb->p_winfo->p_tmevtb != NULL) {
		tmevtb_dequeue(p_tcb->p_winfo->p_tmevtb);
	}
}

/*
 *  �Ԥ����
 *
 *  p_tcb�ǻ��ꤵ��륿�������Ԥ����֤������롥����Ū�ˤϡ������।
 *  �٥�ȥ֥�å�����Ͽ����Ƥ���С��������Ͽ������롥�ޤ���������
 *  ���֤򹹿������Ԥ����������������������ͤ�E_OK�Ȥ��롥�Ԥ����塼
 *  ����κ���ϹԤ�ʤ����Ԥ���������������ؤΥǥ����ѥå���ɬ�פʾ�
 *  ��ˤ�true���֤���
 */
extern bool_t	wait_complete(TCB *p_tcb);

/*
 *  �����ॢ���Ȥ�ȼ���Ԥ����
 *
 *  p_tcb�ǻ��ꤵ��륿���������Ԥ����塼�ˤĤʤ���Ƥ�����Ԥ����塼
 *  �������������������֤򹹿����롥�ޤ����Ԥ���������������������
 *  �ͤ�wait_tmout�Ǥ�E_TMOUT��wait_tmout_ok�Ǥ�E_OK�Ȥ��롥�Ԥ����
 *  �����������ؤΥǥ����ѥå���ɬ�פʻ��ϡ�reqflg��true�ˤ��롥
 *
 *  wait_tmout_ok�ϡ�dly_tsk�ǻȤ�����Τ�Τǡ��Ԥ����塼����������
 *  ������Ԥ�ʤ���
 *
 *  ������δؿ��⡤�����।�٥�ȤΥ�����Хå��ؿ��Ȥ����Ѥ��뤿���
 *  ��Τǡ�����ߥϥ�ɥ餫��ƤӽФ���뤳�Ȥ����ꤷ�Ƥ��롥
 */
extern void	wait_tmout(TCB *p_tcb);
extern void	wait_tmout_ok(TCB *p_tcb);

/*
 *  �Ԥ����֤ζ������
 *
 *  p_tcb�ǻ��ꤵ��륿�������Ԥ����֤���Ū�˲�����롥����Ū�ˤϡ�
 *  ���������Ԥ����塼�ˤĤʤ���Ƥ�����Ԥ����塼���������������।
 *  �٥�ȥ֥�å�����Ͽ����Ƥ���Ф������Ͽ������롥�ޤ�����������
 *  ���֤򹹿������Ԥ����������������������ͤ�E_RLWAI�Ȥ��롥�ޤ���
 *  �Ԥ���������������ؤΥǥ����ѥå���ɬ�פʾ��ˤ�true���֤���
 */
extern bool_t	wait_release(TCB *p_tcb);

/*
 *  �Ԥ����塼����Ƭ�Υ�����ID
 *
 *  p_wait_queue�ǻ��ꤷ���Ԥ����塼����Ƭ�Υ�����ID���֤����Ԥ����塼
 *  �����ξ��ˤϡ�TSK_NONE���֤���
 */
Inline ID
wait_tskid(QUEUE *p_wait_queue)
{
	if (!queue_empty(p_wait_queue)) {
		return(TSKID((TCB *) p_wait_queue->p_next));
	}
	else {
		return(TSK_NONE);
	}
}

/*
 *  Ʊ�����̿����֥������Ȥδ����֥�å��ζ�����ʬ���롼����
 *
 *  Ʊ�����̿����֥������Ȥν�����֥�å��ȴ����֥�å�����Ƭ��ʬ�϶�
 *  �̤ˤʤäƤ��롥�ʲ��ϡ����ζ�����ʬ�򰷤�����η�����ӥ롼����
 *  �Ǥ��롥
 *
 *  ʣ�����Ԥ����塼�����Ʊ�����̿����֥������Ȥξ�硤��Ƭ�ʳ����Ԥ�
 *  ���塼��������ˤϡ������Υ롼����ϻȤ��ʤ����ޤ������֥���
 *  ����°����TA_TPRI�ӥåȤ򻲾Ȥ���Τǡ����ΥӥåȤ�¾����Ū�˻Ȥä�
 *  ������⡤�����Υ롼����ϻȤ��ʤ���
 */

/*
 *  Ʊ�����̿����֥������Ȥν�����֥�å��ζ�����ʬ
 */
typedef struct wait_object_initialization_block {
	ATR			wobjatr;		/* ���֥�������°�� */
} WOBJINIB;

/*
 *  Ʊ�����̿����֥������Ȥδ����֥�å��ζ�����ʬ
 */
typedef struct wait_object_control_block {
	QUEUE		wait_queue;		/* �Ԥ����塼 */
	const WOBJINIB *p_wobjinib;	/* ������֥�å��ؤΥݥ��� */
} WOBJCB;

/*
 *  Ʊ�����̿����֥������Ȥ��Ԥ�����֥�å��ζ�����ʬ
 *
 *  ���ι�¤�Τϡ��Ԥ�����֥�å���WINFO�ˤ��ĥ�ʥ��֥������Ȼظ���
 *  ��ηѾ��������ˤ�����ΤǤ��뤬��WINFO�������Τ��������Ƥ��뤿
 *  ��ˡ�1�ĤΥե�����ɤȤ��ƴޤ�Ƥ��롥
 */
typedef struct wait_object_waiting_information {
	WINFO	winfo;			/* ɸ����Ԥ�����֥�å� */
	WOBJCB	*p_wobjcb;		/* �Ԥ����֥������Ȥδ����֥�å� */
} WINFO_WOBJ;

/*
 *  Ʊ�����̿����֥������Ȥ��Ф����Ԥ����֤ؤΰܹ�
 *  
 *  �¹���Υ��������Ԥ����֤˰ܹԤ�����Ʊ�����̿����֥������Ȥ��Ԥ����塼
 *  �ˤĤʤ����ޤ����Ԥ�����֥�å���WINFO�ˤ�p_wobjcb�����ꤹ�롥
 *  wobj_make_wait_tmout�ϡ������।�٥�ȥ֥�å�����Ͽ��Ԥ���
 */
extern void	wobj_make_wait(WOBJCB *p_wobjcb, WINFO_WOBJ *p_winfo);
extern void	wobj_make_wait_tmout(WOBJCB *p_wobjcb, WINFO_WOBJ *p_winfo,
											TMEVTB *p_tmevtb, TMO tmout);

/*
 *  ������ͥ�����ѹ����ν���
 *
 *  Ʊ�����̿����֥������Ȥ��Ф����Ԥ����֤ˤ��륿������ͥ���٤��ѹ���
 *  �줿���ˡ��Ԥ����塼����ǤΥ������ΰ��֤������롥
 */
Inline void
wobj_change_priority(WOBJCB *p_wobjcb, TCB *p_tcb)
{
	if ((p_wobjcb->p_wobjinib->wobjatr & TA_TPRI) != 0U) {
		queue_delete(&(p_tcb->task_queue));
		queue_insert_tpri(&(p_wobjcb->wait_queue), p_tcb);
	}
}

/*
 *  �Ԥ����塼�ν����
 *
 *  �Ԥ����塼�ˤĤʤ���Ƥ��륿�����򤹤٤��Ԥ�������롥�Ԥ��������
 *  ��������������ͤϡ�E_DLT�Ȥ��롥�Ԥ���������������ؤΥǥ����ѥå�
 *  ��ɬ�פʾ���true�������Ǥʤ�����false���֤���
 */
extern bool_t	init_wait_queue(QUEUE *p_wait_queue);

#endif /* TOPPERS_WAIT_H */
