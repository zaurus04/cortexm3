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
 *  @(#) $Id: dataqueue.h 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�ǡ������塼��ǽ
 */

#ifndef TOPPERS_DATAQUEUE_H
#define TOPPERS_DATAQUEUE_H

#include <queue.h>

/*
 *  �ǡ������塼������֥�å�
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥν�����֥�å��ζ�����ʬ
 *  ��WOBJINIB�ˤ��ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ�
 *  �ǽ�Υե�����ɤ����̤ˤʤäƤ��롥
 */
typedef struct dataqueue_initialization_block {
	ATR			dtqatr;			/* �ǡ������塼°�� */
	uint_t		dtqcnt;			/* �ǡ������塼������ */
	intptr_t	*p_dtqmb;		/* �ǡ������塼�����ΰ����Ƭ���� */
} DTQINIB;

/*
 *  �ǡ������塼�����֥�å�
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥδ����֥�å��ζ�����ʬ��WOBJCB��
 *  ���ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ��ǽ��2�Ĥ�
 *  �ե�����ɤ����̤ˤʤäƤ��롥
 */
typedef struct dataqueue_control_block {
	QUEUE		swait_queue;	/* �ǡ������塼�����Ԥ����塼 */
	const DTQINIB *p_dtqinib;	/* ������֥�å��ؤΥݥ��� */
	QUEUE		rwait_queue;	/* �ǡ������塼�����Ԥ����塼 */
	uint_t		count;			/* �ǡ������塼��Υǡ����ο� */
	uint_t		head;			/* �ǽ�Υǡ����γ�Ǽ��� */
	uint_t		tail;			/* �Ǹ�Υǡ����γ�Ǽ���μ� */
} DTQCB;

/*
 *  �ǡ������塼�Ԥ�����֥�å������
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥ��Ԥ�����֥�å��ζ�����ʬ
 *  ��WINFO_WOBJ�ˤ��ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ�
 *  �ǽ��2�ĤΥե�����ɤ����̤ˤʤäƤ��롥
 *  �ǡ������塼�ؤ������Ԥ��ȥǡ������塼����μ����Ԥ��ǡ�Ʊ���Ԥ���
 *  ��֥�å���Ȥ���
 */
typedef struct dataqueue_waiting_information {
	WINFO		winfo;			/* ɸ����Ԥ�����֥�å� */
	DTQCB		*p_dtqcb;		/* �ԤäƤ���ǡ������塼�δ����֥�å� */
	intptr_t	data;			/* �������ǡ��� */
} WINFO_DTQ;

/*
 *  �ǡ������塼ID�κ����͡�kernel_cfg.c��
 */
extern const ID	tmax_dtqid;

/*
 *  �ǡ������塼������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern const DTQINIB	dtqinib_table[];

/*
 *  �ǡ������塼�����֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern DTQCB	dtqcb_table[];

/*
 *  �ǡ������塼�����֥�å�����ǡ������塼ID����Ф�����Υޥ���
 */
#define	DTQID(p_dtqcb)	((ID)(((p_dtqcb) - dtqcb_table) + TMIN_DTQID))

/*
 *  �ǡ������塼��ǽ�ν����
 */
extern void	initialize_dataqueue(void);

/*
 *  �ǡ������塼�����ΰ�ؤΥǡ����γ�Ǽ
 */
extern void	enqueue_data(DTQCB *p_dtqcb, intptr_t data);

/*
 *  �ǡ������塼�����ΰ�ؤΥǡ����ζ�����Ǽ
 */
extern void	force_enqueue_data(DTQCB *p_dtqcb, intptr_t data);

/*
 *  �ǡ������塼�����ΰ褫��Υǡ����μ�Ф�
 */
extern void	dequeue_data(DTQCB *p_dtqcb, intptr_t *p_data);

/*
 *  �ǡ������塼�ؤΥǡ�������
 */
extern bool_t	send_data(DTQCB *p_dtqcb, intptr_t data, bool_t *p_reqdsp);

/*
 *  �ǡ������塼�ؤΥǡ�����������
 */
extern bool_t	force_send_data(DTQCB *p_dtqcb, intptr_t data);

/*
 *  �ǡ������塼����Υǡ�������
 */
extern bool_t	receive_data(DTQCB *p_dtqcb, intptr_t *p_data,
													bool_t *p_reqdsp);

#endif /* TOPPERS_DATAQUEUE_H */
