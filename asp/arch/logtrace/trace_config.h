/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2007 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: trace_config.h 1230 2008-08-08 05:52:17Z ertl-hiro $
 */

/*
 *		�ȥ졼�����˴ؤ�������
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�target_config.h�����target_syssvc.h��
 *  �ߤ��饤�󥯥롼�ɤ���롥¾�Υե����뤫��ľ�ܥ��󥯥롼�ɤ��ƤϤ�
 *  ��ʤ���
 */

#ifndef TOPPERS_TRACE_CONFIG_H
#define TOPPERS_TRACE_CONFIG_H

/*
 *  �ȥ졼�����Хåե��Υ�����
 */
#ifndef TCNT_TRACE_BUFFER
#define TCNT_TRACE_BUFFER	1024
#endif /* TCNT_TRACE_BUFFER */

/*
 *  �ȥ졼������μ�����ˡ
 */
#ifndef TRACE_GET_TIM
#define TRACE_GET_TIM()		(current_time)
#endif /* TRACE_GET_TIM */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �ȥ졼�����Υǡ�����¤
 *
 *  �����ƥ����ǽ�Υ�����Υǡ�����¤��Ʊ����Τ��Ѥ��롥
 */
#include <t_syslog.h>
typedef	SYSLOG	TRACE;

/*
 *  �ȥ졼�����Хåե��Ȥ���˥����������뤿��Υݥ���
 */
extern TRACE	trace_buffer[];		/* �ȥ졼�����Хåե� */
extern uint_t	trace_count;		/* �ȥ졼�����Хåե���Υ��ο� */
extern uint_t	trace_head;			/* ��Ƭ�Υȥ졼�����γ�Ǽ���� */
extern uint_t	trace_tail;			/* ���Υȥ졼�����γ�Ǽ���� */
extern uint_t	trace_lost;			/* ����줿�ȥ졼���ο� */

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �ȥ졼���⡼�ɤ����
 */
#define TRACE_STOP			UINT_C(0x00)	/* �ȥ졼����� */
#define TRACE_RINGBUF		UINT_C(0x01)	/* ��󥰥Хåե��⡼�� */
#define TRACE_AUTOSTOP		UINT_C(0x02)	/* ��ư��ߥ⡼�� */
#define TRACE_CLEAR			UINT_C(0x04)	/* �ȥ졼�����Υ��ꥢ */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �ȥ졼������ǽ�ν����
 *
 *  �ȥ졼������ǽ���������롥������롼����Ȥ�����Ͽ���뤳�Ȥ���
 *  �ꤷ�Ƥ��롥�����ˤ�꼡��ư���Ԥ���
 *
 *  TRACE_STOP��������Τߤǥȥ졼���ϳ��Ϥ��ʤ���
 *  TRACE_RINGBUF����󥰥Хåե��⡼�ɤǥȥ졼���򳫻ϡ�
 *  TRACE_AUTOSTOP����ư��ߥ⡼�ɤǥȥ졼���򳫻ϡ�
 */
extern void	trace_initialize(intptr_t exinf);

/*
 *  �ȥ졼�����γ���
 *
 *  �ȥ졼�����ε�Ͽ�򳫻ϡ���ߤ��롥�����ˤ�꼡��ư���Ԥ���
 *
 *  TRACE_STOP���ȥ졼������ߡ�
 *  TRACE_RINGBUF����󥰥Хåե��⡼�ɤǥȥ졼���򳫻ϡ�
 *  TRACE_AUTOSTOP����ư��ߥ⡼�ɤǥȥ졼���򳫻ϡ�
 *  TRACE_CLEAR���ȥ졼�����򥯥ꥢ��
 */
extern ER	trace_sta_log(MODE mode);

/*
 *  �ȥ졼�����ν����
 */
extern ER	trace_wri_log(TRACE *p_trace);

/*
 *  �ȥ졼�������ɽФ�
 */
extern ER	trace_rea_log(TRACE *p_trace);

/* 
 *  �ȥ졼�����Υ���ס�trace_dump.c��
 *
 *  �ȥ졼���������פ��롥��λ�����롼����Ȥ�����Ͽ���뤳�Ȥ�����
 *  ���Ƥ��롥�����Ȥ��ơ��������Ȥʤ�ʸ�����ϴؿ��ؤΥݥ��󥿤��Ϥ���
 *  �������åȰ�¸�����٥�ʸ�����Ϥ����Ѥ�����ˤϡ�target_putc����
 *  ����
 */
extern void	trace_dump(intptr_t exinf);

/*
 *  �ȥ졼��������Ϥ��뤿��Υ饤�֥��ؿ�
 */
extern void	trace_write_0(uint_t type);
extern void	trace_write_1(uint_t type, intptr_t arg1);
extern void	trace_write_2(uint_t type, intptr_t arg1, intptr_t arg2);
extern void	trace_write_3(uint_t type, intptr_t arg1, intptr_t arg2,
														intptr_t arg3);

/*
 *  �ȥ졼��������Ϥ��뤿��Υޥ���
 */

#define trace_0(type) \
				trace_write_0(type)

#define trace_1(type, arg1) \
				trace_write_1(type, (intptr_t)(arg1))

#define trace_2(type, arg1, arg2) \
				trace_write_2(type, (intptr_t)(arg1), (intptr_t)(arg2))

#define trace_3(type, arg1, arg2, arg3) \
				trace_write_3(type, (intptr_t)(arg1), (intptr_t)(arg2), \
						(intptr_t)(arg3))

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �ȥ졼������ˡ������
 */
#define LOG_TSKSTAT(p_tcb)		trace_2(LOG_TYPE_TSKSTAT, p_tcb, p_tcb->tstat)

#define LOG_DSP_LEAVE(p_tcb)	trace_1(LOG_TYPE_DSP|LOG_LEAVE, p_tcb)

#define LOG_SYSLOG_WRI_LOG_ENTER(prio, p_syslog) \
								trace_wri_log((TRACE *) p_syslog)

#endif /* TOPPERS_TRACE_CONFIG_H */
