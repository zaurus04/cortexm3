/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2007,2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: trace_dump.c 1230 2008-08-08 05:52:17Z ertl-hiro $
 */

/*
 *		�ȥ졼�����Υ����
 */

#include "kernel_impl.h"
#include "task.h"
#include <log_output.h>

/* 
 *  �����ͥ����μ�Ф�
 */
static intptr_t
get_tskid(intptr_t info)
{
	TCB		*p_tcb;
	ID		tskid;

	p_tcb = (TCB *) info;
	if (p_tcb == NULL) {
		tskid = 0;
	}
	else {
		tskid = TSKID(p_tcb);
	}
	return((intptr_t) tskid);
}

static intptr_t
get_tskstat(intptr_t info)
{
	uint_t		tstat;
	const char	*tstatstr;

	tstat = (uint_t) info;
	switch (tstat & (TS_RUNNABLE|TS_WAITING|TS_SUSPENDED)) {
	case TS_DORMANT:
		tstatstr = "DORMANT";
		break;
	case TS_RUNNABLE:
		tstatstr = "RUNNABLE";
		break;
	case TS_WAITING:
		tstatstr = "WAITING";
		break;
	case TS_SUSPENDED:
		tstatstr = "SUSPENDED";
		break;
	case TS_WAITING|TS_SUSPENDED:
		tstatstr = "WAITING-SUSPENDED";
		break;
	default:
		tstatstr = "unknown state";
		break;
	}
	return((intptr_t) tstatstr);
}

/* 
 *  �ȥ졼������ɽ��
 */
static void
trace_print(TRACE *p_trace, void (*putc)(char_t))
{
	intptr_t	traceinfo[TMAX_LOGINFO + 1];
	const char	*tracemsg;
	int_t		i;

	traceinfo[0] = (intptr_t)(p_trace->logtim);
	syslog_printf("[%d] ", traceinfo, putc);

	switch (p_trace->logtype) {
	case LOG_TYPE_TSKSTAT:
		traceinfo[0] = get_tskid(p_trace->loginfo[0]);
		traceinfo[1] = get_tskstat(p_trace->loginfo[1]);
		tracemsg = "task %d becomes %s.";
		break;
	case LOG_TYPE_DSP|LOG_LEAVE:
		traceinfo[0] = get_tskid(p_trace->loginfo[0]);
		tracemsg = "dispatch to task %d.";
		break;
	case LOG_TYPE_COMMENT:
		for (i = 1; i < TMAX_LOGINFO; i++) {
			traceinfo[i-1] = p_trace->loginfo[i];
		}
		tracemsg = (const char *)(p_trace->loginfo[0]);
		break;
	case LOG_TYPE_ASSERT:
		traceinfo[0] = p_trace->loginfo[0];
		traceinfo[1] = p_trace->loginfo[1];
		traceinfo[2] = p_trace->loginfo[2];
		tracemsg = "%s:%u: Assertion `%s' failed.";
		break;
	default:
		traceinfo[0] = p_trace->logtype;
		tracemsg = "unknown trace log type: %d.";
		break;
	}
	syslog_printf(tracemsg, traceinfo, putc);
	(*putc)('\n');
}

/* 
 *  �ȥ졼�����Υ����
 */
void
trace_dump(intptr_t exinf)
{
	TRACE	trace;
	void	(*putc)(char_t);

	putc = (void (*)(char_t)) exinf;
	while (trace_rea_log(&trace) >= 0) {
		trace_print(&trace, putc);
	}
}
