/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: semaphore.h 264 2007-07-12 08:23:10Z hiro $
 */

/*
 *		���ޥե���ǽ
 */

#ifndef TOPPERS_SEMAPHORE_H
#define TOPPERS_SEMAPHORE_H

#include <queue.h>

/*
 *  ���ޥե�������֥�å�
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥν�����֥�å��ζ�����ʬ
 *  ��WOBJINIB�ˤ��ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ�
 *  �ǽ�Υե�����ɤ����̤ˤʤäƤ��롥
 */
typedef struct semaphore_initialization_block {
	ATR			sematr;			/* ���ޥե�°�� */
	uint_t		isemcnt;		/* ���ޥե��λ񸻿��ν���� */
	uint_t		maxsem;			/* ���ޥե��κ���񸻿� */
} SEMINIB;

/*
 *  ���ޥե������֥�å�
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥδ����֥�å��ζ�����ʬ��WOBJCB��
 *  ���ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ��ǽ��2�Ĥ�
 *  �ե�����ɤ����̤ˤʤäƤ��롥
 */
typedef struct semaphore_control_block {
	QUEUE		wait_queue;		/* ���ޥե��Ԥ����塼 */
	const SEMINIB *p_seminib;	/* ������֥�å��ؤΥݥ��� */
	uint_t		semcnt;			/* ���ޥե����ߥ�������� */
} SEMCB;

/*
 *  ���ޥե��Ԥ�����֥�å������
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥ��Ԥ�����֥�å��ζ�����ʬ
 *  ��WINFO_WOBJ�ˤ��ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ�
 *  ���٤ƤΥե�����ɤ����̤ˤʤäƤ��롥
 */
typedef struct semaphore_waiting_information {
	WINFO	winfo;			/* ɸ����Ԥ�����֥�å� */
	SEMCB	*p_semcb;		/* �ԤäƤ��륻�ޥե��δ����֥�å� */
} WINFO_SEM;

/*
 *  ���ޥե�ID�κ����͡�kernel_cfg.c��
 */
extern const ID	tmax_semid;

/*
 *  ���ޥե�������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern const SEMINIB	seminib_table[];

/*
 *  ���ޥե������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern SEMCB	semcb_table[];

/*
 *  ���ޥե������֥�å����饻�ޥե�ID����Ф�����Υޥ���
 */
#define	SEMID(p_semcb)	((ID)(((p_semcb) - semcb_table) + TMIN_SEMID))

/*
 *  ���ޥե���ǽ�ν����
 */
extern void	initialize_semaphore(void);

#endif /* TOPPERS_SEMAPHORE_H */
