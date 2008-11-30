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
 *  @(#) $Id: task.c 1159 2008-06-27 18:17:41Z ertl-hiro $
 */

/*
 *		�����������⥸�塼��
 */

#include "kernel_impl.h"
#include "wait.h"
#include "task.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_TEX_ENTER
#define LOG_TEX_ENTER(texptn)
#endif /* LOG_TEX_ENTER */

#ifndef LOG_TEX_LEAVE
#define LOG_TEX_LEAVE(texptn)
#endif /* LOG_TEX_LEAVE */

#ifdef TOPPERS_tskini

/*
 *  �¹Ծ��֤Υ�����
 */
TCB		*p_runtsk;

/*
 *  �ǹ�ͥ���̤Υ�����
 */
TCB		*p_schedtsk;

/*
 *  �������ǥ����ѥå����������㳰�����롼����ư�׵�ե饰
 */
bool_t	reqflg;

/*
 *  �ǥ����ѥå��ػ߾���
 */
bool_t	disdsp;

/*
 *  �������ǥ����ѥå���ǽ����
 */
bool_t	dspflg;

/*
 *  ��ǥ����塼
 */
QUEUE	ready_queue[TNUM_TPRI];

/*
 *  ��ǥ����塼�������Τ���Υӥåȥޥå�
 */
uint16_t	ready_primap;

/*
 *  �����������⥸�塼��ν����
 */
void
initialize_task(void)
{
	uint_t	i, j;
	TCB		*p_tcb;

	p_runtsk = p_schedtsk = NULL;
	reqflg = false;
	disdsp = false;
	dspflg = true;

	for (i = 0; i < TNUM_TPRI; i++) {
		queue_initialize(&(ready_queue[i]));
	}
	ready_primap = 0U;

	for (i = 0; i < tnum_tsk; i++) {
		j = INDEX_TSK(torder_table[i]);
		p_tcb = &(tcb_table[j]);
		p_tcb->p_tinib = &(tinib_table[j]);
		p_tcb->actque = false;
		make_dormant(p_tcb);
		if ((p_tcb->p_tinib->tskatr & TA_ACT) != 0U) {
			make_active(p_tcb);
		}
	}
}

#endif /* TOPPERS_tskini */

/*
 *  �ӥåȥޥåץ������ؿ�
 *
 *  bitmap���1�ΥӥåȤ��⡤�ǤⲼ�̡ʱ��ˤΤ�Τ򥵡����������Υӥ�
 *  ���ֹ���֤����ӥå��ֹ�ϡ��ǲ��̥ӥåȤ�0�Ȥ��롥bitmap��0�����
 *  ���ƤϤʤ�ʤ������δؿ��Ǥϡ�bitmap��16�ӥåȤǤ��뤳�Ȥ��ꤷ��
 *  uint16_t���Ȥ��Ƥ��롥
 *
 *  �ӥåȥ�����̿�����ĥץ��å��Ǥϡ��ӥåȥ�����̿���Ȥ��褦��
 *  ��ľ����������Ψ���ɤ���礬���롥���Τ褦�ʾ��ˤϡ��������å�
 *  ��¸���ǥӥåȥ�����̿���Ȥä�bitmap_search���������
 *  OMIT_BITMAP_SEARCH��ޥ����������Ф褤���ޤ����ӥåȥ�����̿���
 *  �������������դʤɤ���ͳ��ͥ���٤ȥӥåȤȤ��б����ѹ�����������
 *  �ϡ�PRIMAP_BIT��ޥ����������Ф褤��
 *
 *  �ޤ���ɸ��饤�֥���ffs������ʤ顤���Τ褦���������ɸ��饤��
 *  ����Ȥä�������Ψ���ɤ���ǽ���⤢�롥
 *		#define	bitmap_search(bitmap) (ffs(bitmap) - 1)
 */
#ifndef PRIMAP_BIT
#define	PRIMAP_BIT(pri)		(1U << (pri))
#endif /* PRIMAP_BIT */

#ifndef OMIT_BITMAP_SEARCH

static const unsigned char bitmap_search_table[] = { 0, 1, 0, 2, 0, 1, 0,
												3, 0, 1, 0, 2, 0, 1, 0 };

Inline uint_t
bitmap_search(uint16_t bitmap)
{
	uint_t	n = 0U;

	assert(bitmap != 0U);
	if ((bitmap & 0x00ffU) == 0U) {
		bitmap >>= 8;
		n += 8;
	}
	if ((bitmap & 0x0fU) == 0U) {
		bitmap >>= 4;
		n += 4;
	}
	return(n + bitmap_search_table[(bitmap & 0x0fU) - 1]);
}

#endif /* OMIT_BITMAP_SEARCH */

/*
 *  ͥ���٥ӥåȥޥåפ������Υ����å�
 */
Inline bool_t
primap_empty(void)
{
	return(ready_primap == 0U);
}

/*
 *  ͥ���٥ӥåȥޥåפΥ�����
 */
Inline uint_t
primap_search(void)
{
	return(bitmap_search(ready_primap));
}

/*
 *  ͥ���٥ӥåȥޥåפΥ��å�
 */
Inline void
primap_set(uint_t pri)
{
	ready_primap |= PRIMAP_BIT(pri);
}

/*
 *  ͥ���٥ӥåȥޥåפΥ��ꥢ
 */
Inline void
primap_clear(uint_t pri)
{
	ready_primap &= ~PRIMAP_BIT(pri);
}

/*
 *  �ǹ�ͥ���̥������Υ�����
 */
#ifdef TOPPERS_tsksched

TCB *
search_schedtsk(void)
{
	uint_t	schedpri;

	schedpri = primap_search();
	return((TCB *)(ready_queue[schedpri].p_next));
}

#endif /* TOPPERS_tsksched */

/*
 *  �¹ԤǤ�����֤ؤΰܹ�
 *
 *  �ǹ�ͥ���̤Υ������򹹿�����Τϡ��¹ԤǤ��륿�������ʤ��ä����
 *  �ȡ�p_tcb��ͥ���٤��ǹ�ͥ���̤Υ�������ͥ���٤���⤤���Ǥ�
 *  �롥
 */
#ifdef TOPPERS_tskrun

bool_t
make_runnable(TCB *p_tcb)
{
	uint_t	pri = p_tcb->priority;

	p_tcb->tstat = TS_RUNNABLE;
	LOG_TSKSTAT(p_tcb);
	queue_insert_prev(&(ready_queue[pri]), &(p_tcb->task_queue));
	primap_set(pri);

	if (p_schedtsk == (TCB *) NULL || pri < p_schedtsk->priority) {
		p_schedtsk = p_tcb;
		return(dspflg);
	}
	return(false);
}

#endif /* TOPPERS_tskrun */

/*
 *  �¹ԤǤ�����֤���¾�ξ��֤ؤΰܹ�
 *
 *  �ǹ�ͥ���̤Υ������򹹿�����Τϡ�p_tcb���ǹ�ͥ���̤Υ�������
 *  ���ä����Ǥ��롥p_tcb��Ʊ��ͥ���٤Υ�������¾�ˤ�����ϡ�p_tcb
 *  �μ��Υ��������ǹ�ͥ���̤ˤʤ롥�����Ǥʤ����ϡ���ǥ����塼��
 *  ����������ɬ�פ����롥
 */
#ifdef TOPPERS_tsknrun

bool_t
make_non_runnable(TCB *p_tcb)
{
	uint_t	pri = p_tcb->priority;
	QUEUE	*p_queue = &(ready_queue[pri]);

	queue_delete(&(p_tcb->task_queue));
	if (queue_empty(p_queue)) {
		primap_clear(pri);
		if (p_schedtsk == p_tcb) {
			p_schedtsk = primap_empty() ? (TCB *) NULL : search_schedtsk();
			return(dspflg);
		}
	}
	else {
		if (p_schedtsk == p_tcb) {
			p_schedtsk = (TCB *)(p_queue->p_next);
			return(dspflg);
		}
	}
	return(false);
}

#endif /* TOPPERS_tsknrun */

/*
 *  �ٻ߾��֤ؤΰܹ�
 */
#ifdef TOPPERS_tskdmt

void
make_dormant(TCB *p_tcb)
{
	p_tcb->tstat = TS_DORMANT;
	p_tcb->priority = p_tcb->p_tinib->ipriority;
	p_tcb->wupque = false;
	p_tcb->enatex = false;
	p_tcb->texptn = 0U;
	LOG_TSKSTAT(p_tcb);
}

#endif /* TOPPERS_tskdmt */

/*
 *  �ٻ߾��֤���¹ԤǤ�����֤ؤΰܹ�
 */
#ifdef TOPPERS_tskact

bool_t
make_active(TCB *p_tcb)
{
	activate_context(p_tcb);
	return(make_runnable(p_tcb));
}

#endif /* TOPPERS_tskact */

/*
 *  ��������ͥ���٤��ѹ�
 *
 *  ���������¹ԤǤ�����֤ξ��ˤϡ���ǥ����塼����Ǥΰ��֤��ѹ���
 *  �롥���֥������Ȥ��Ԥ����塼������Ԥ����֤ˤʤäƤ�����ˤϡ���
 *  �����塼����Ǥΰ��֤��ѹ����롥
 *
 *  �ǹ�ͥ���̤Υ������򹹿�����Τϡ�(1) p_tcb���ǹ�ͥ���̤Υ���
 *  ���Ǥ��äơ�����ͥ���٤򲼤�����硤(2) p_tcb���ǹ�ͥ���̤Υ���
 *  ���ǤϤʤ����ѹ����ͥ���٤��ǹ�ͥ���̤Υ�������ͥ���٤���⤤
 *  ���Ǥ��롥(1)�ξ��ˤϡ���ǥ����塼�򥵡�������ɬ�פ����롥
 */
#ifdef TOPPERS_tskpri

bool_t
change_priority(TCB *p_tcb, uint_t newpri)
{
	uint_t	oldpri;

	oldpri = p_tcb->priority;
	p_tcb->priority = newpri;

	if (TSTAT_RUNNABLE(p_tcb->tstat)) {
		/*
		 *  ���������¹ԤǤ�����֤ξ��
		 */
		queue_delete(&(p_tcb->task_queue));
		if (queue_empty(&(ready_queue[oldpri]))) {
			primap_clear(oldpri);
		}
		queue_insert_prev(&(ready_queue[newpri]), &(p_tcb->task_queue));
		primap_set(newpri);

		if (p_schedtsk == p_tcb) {
			if (newpri >= oldpri) {
				p_schedtsk = search_schedtsk();
				return(p_schedtsk != p_tcb && dspflg);
			}
		}
		else {
			if (newpri < p_schedtsk->priority) {
				p_schedtsk = p_tcb;
				return(dspflg);
			}
		}
	}
	else {
		if (TSTAT_WAIT_WOBJCB(p_tcb->tstat)) {
			/*
			 *  ����������Ʊ�����̿����֥������Ȥδ����֥�å��ζ�����
			 *  ʬ��WOBJCB�ˤ��Ԥ����塼�ˤĤʤ���Ƥ�����
			 */
			wobj_change_priority(((WINFO_WOBJ *)(p_tcb->p_winfo))->p_wobjcb,
																	p_tcb);
		}
	}
	return(false);
}

#endif /* TOPPERS_tskpri */

/*
 *  ��ǥ����塼�β�ž
 *
 *  �ǹ�ͥ���̤Υ������򹹿�����Τϡ��ǹ�ͥ���̤Υ���������������
 *  �塼�������˰�ư�������Ǥ��롥
 */
#ifdef TOPPERS_tskrot

bool_t
rotate_ready_queue(uint_t pri)
{
	QUEUE	*p_queue = &(ready_queue[pri]);
	QUEUE	*p_entry;

	if (!queue_empty(p_queue) && p_queue->p_next->p_next != p_queue) {
		p_entry = queue_delete_next(p_queue);
		queue_insert_prev(p_queue, p_entry);
		if (p_schedtsk == (TCB *) p_entry) {
			p_schedtsk = (TCB *)(p_queue->p_next);
			return(dspflg);
		}
	}
	return(false);
}

#endif /* TOPPERS_tskrot */

/*
 *  �������㳰�����롼����θƽФ�
 *
 *  ASP�����ͥ�Ǥϡ��������㳰�����롼�������CPU��å����֤˰ܹԤ���
 *  ���ξ��֤��ᤵ���˥꥿���󤷤���硤�����ͥ뤬���ξ��֤��᤹��
 */
#ifdef TOPPERS_tsktex
#ifndef OMIT_CALL_TEXRTN

void
call_texrtn(void)
{
	TEXPTN	texptn;
	PRI		saved_ipm;
	bool_t	saved_disdsp, saved_dspflg;

	saved_ipm = t_get_ipm();
	saved_disdsp = disdsp;
	saved_dspflg = dspflg;
	do {
		texptn = p_runtsk->texptn;
		p_runtsk->enatex = false;
		p_runtsk->texptn = 0U;

		t_unlock_cpu();
		LOG_TEX_ENTER(texptn);
		(*((TEXRTN)(p_runtsk->p_tinib->texrtn)))(texptn,
												p_runtsk->p_tinib->exinf);
		LOG_TEX_LEAVE(texptn);
		if (!t_sense_lock()) {
			t_lock_cpu();
		}
		t_set_ipm(saved_ipm);
		disdsp = saved_disdsp;
		dspflg = saved_dspflg;
		if (p_runtsk != p_schedtsk && dspflg) {
			dispatch();
		}
	} while (p_runtsk->texptn != 0U);
	p_runtsk->enatex = true;
}

#endif /* OMIT_CALL_TEXRTN */

/*
 *  �������㳰�����롼����ε�ư
 */
#ifndef OMIT_CALLTEX

void
calltex(void)
{
	if (p_runtsk->enatex && p_runtsk->texptn != 0U) {
		call_texrtn();
	}
}

#endif /* OMIT_CALLTEX */
#endif /* TOPPERS_tsktex */
