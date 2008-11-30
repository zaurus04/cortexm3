/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005,2006 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: alarm.h 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		���顼��ϥ�ɥ鵡ǽ
 */

#ifndef TOPPERS_ALARM_H
#define TOPPERS_ALARM_H

#include "time_event.h"

/*
 *  ���顼��ϥ�ɥ������֥�å�
 */
typedef struct alarm_handler_initialization_block {
	ATR			almatr;			/* ���顼��ϥ�ɥ�°�� */
	intptr_t	exinf;			/* ���顼��ϥ�ɥ�γ�ĥ���� */
	ALMHDR		almhdr;			/* ���顼��ϥ�ɥ�ε�ư���� */
} ALMINIB;

/*
 *  ���顼��ϥ�ɥ�����֥�å�
 */
typedef struct alarm_handler_control_block {
	const ALMINIB *p_alminib;	/* ������֥�å��ؤΥݥ��� */
	bool_t		almsta;			/* ���顼��ϥ�ɥ��ư����� */
	TMEVTB		tmevtb;			/* �����।�٥�ȥ֥�å� */
} ALMCB;

/*
 *  ���顼��ϥ�ɥ�ID�κ����͡�kernel_cfg.c��
 */
extern const ID	tmax_almid;

/*
 *  ���顼��ϥ�ɥ������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern const ALMINIB	alminib_table[];

/*
 *  ���顼��ϥ�ɥ�����֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern ALMCB	almcb_table[];

/*
 *  ���顼��ϥ�ɥ鵡ǽ�ν����
 */
extern void	initialize_alarm(void);

/*
 *  ���顼��ϥ�ɥ鵯ư�롼����
 */
extern void	call_almhdr(ALMCB *p_almcb);

#endif /* TOPPERS_ALARM_H */
