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
 *  @(#) $Id: pridataq.h 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		ͥ���٥ǡ������塼��ǽ
 */

#ifndef TOPPERS_PRIDATAQ_H
#define TOPPERS_PRIDATAQ_H

#include <queue.h>

/*
 *  ͥ���٥ǡ��������֥�å�
 */
typedef struct pridata_management_block PDQMB;

struct pridata_management_block {
	PDQMB		*p_next;		/* ���Υǡ��� */
	intptr_t	data;			/* �ǡ������� */
	PRI			datapri;		/* �ǡ���ͥ���� */
};

/*
 *  ͥ���٥ǡ������塼������֥�å�
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥν�����֥�å��ζ�����ʬ
 *  ��WOBJINIB�ˤ��ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ�
 *  �ǽ�Υե�����ɤ����̤ˤʤäƤ��롥
 */
typedef struct pridataq_initialization_block {
	ATR			pdqatr;			/* ͥ���٥ǡ������塼°�� */
	uint_t		pdqcnt;			/* ͥ���٥ǡ������塼������ */
	PRI			maxdpri;		/* �ǡ���ͥ���٤κ����� */
	PDQMB		*p_pdqmb;		/* ͥ���٥ǡ������塼�����ΰ����Ƭ���� */
} PDQINIB;

/*
 *  ͥ���٥ǡ������塼�����֥�å�
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥδ����֥�å��ζ�����ʬ��WOBJCB��
 *  ���ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ��ǽ��2�Ĥ�
 *  �ե�����ɤ����̤ˤʤäƤ��롥
 */
typedef struct pridataq_control_block {
	QUEUE		swait_queue;	/* ͥ���٥ǡ������塼�����Ԥ����塼 */
	const PDQINIB *p_pdqinib;	/* ������֥�å��ؤΥݥ��� */
	QUEUE		rwait_queue;	/* ͥ���٥ǡ������塼�����Ԥ����塼 */
	uint_t		count;			/* ͥ���٥ǡ������塼��Υǡ����ο� */
	PDQMB		*p_head;		/* �ǽ�Υǡ��� */
	uint_t		unused;			/* ̤���ѥǡ��������֥�å�����Ƭ */
	PDQMB		*p_freelist;	/* ̤�����ƥǡ��������֥�å��Υꥹ�� */
} PDQCB;

/*
 *  ͥ���٥ǡ������塼�Ԥ�����֥�å������
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥ��Ԥ�����֥�å��ζ�����ʬ
 *  ��WINFO_WOBJ�ˤ��ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ�
 *  �ǽ��2�ĤΥե�����ɤ����̤ˤʤäƤ��롥
 *  ͥ���٥ǡ������塼�ؤ������Ԥ���ͥ���٥ǡ������塼����μ����Ԥ��ǡ�
 *  Ʊ���Ԥ�����֥�å���Ȥ���
 */
typedef struct pridataq_waiting_information {
	WINFO		winfo;			/* ɸ����Ԥ�����֥�å� */
	PDQCB		*p_pdqcb;		/* �ԤäƤ���ͥ���٥ǡ������塼�δ����֥�å�*/
	intptr_t	data;			/* �������ǡ��� */
	PRI			datapri;		/* �ǡ���ͥ���� */
} WINFO_PDQ;

/*
 *  ͥ���٥ǡ������塼ID�κ����͡�kernel_cfg.c��
 */
extern const ID	tmax_pdqid;

/*
 *  ͥ���٥ǡ������塼������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern const PDQINIB	pdqinib_table[];

/*
 *  ͥ���٥ǡ������塼�����֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern PDQCB	pdqcb_table[];

/*
 *  ͥ���٥ǡ������塼�����֥�å�����ͥ���٥ǡ������塼ID����Ф���
 *  ��Υޥ���
 */
#define	PDQID(p_pdqcb)	((ID)(((p_pdqcb) - pdqcb_table) + TMIN_PDQID))

/*
 *  ͥ���٥ǡ������塼��ǽ�ν����
 */
extern void	initialize_pridataq(void);

/*
 *  ͥ���٥ǡ������塼�����ΰ�ؤΥǡ����γ�Ǽ
 */
extern void	enqueue_pridata(PDQCB *p_pdqcb, intptr_t data, PRI datapri);

/*
 *  ͥ���٥ǡ������塼�����ΰ褫��Υǡ����μ�Ф�
 */
extern void	dequeue_pridata(PDQCB *p_pdqcb, intptr_t *p_data, PRI *p_datapri);

/*
 *  ͥ���٥ǡ������塼�ؤΥǡ�������
 */
extern bool_t	send_pridata(PDQCB *p_pdqcb, intptr_t data,
											PRI datapri, bool_t *p_reqdsp);

/*
 *  ͥ���٥ǡ������塼����Υǡ�������
 */
extern bool_t	receive_pridata(PDQCB *p_pdqcb, intptr_t *p_data,
											PRI *p_datapri, bool_t *p_reqdsp);

#endif /* TOPPERS_PRIDATAQ_H */
