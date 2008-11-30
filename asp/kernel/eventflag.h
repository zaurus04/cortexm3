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
 *  @(#) $Id: eventflag.h 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		���٥�ȥե饰��ǽ
 */

#ifndef TOPPERS_EVENTFLAG_H
#define TOPPERS_EVENTFLAG_H

#include <queue.h>

/*
 *  ���٥�ȥե饰������֥�å�
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥν�����֥�å��ζ�����ʬ
 *  ��WOBJINIB�ˤ��ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ�
 *  �ǽ�Υե�����ɤ����̤ˤʤäƤ��롥
 */
typedef struct eventflag_initialization_block {
	ATR			flgatr;			/* ���٥�ȥե饰°�� */
	FLGPTN		iflgptn;		/* ���٥�ȥե饰�Υӥåȥѥ�����ν���� */
} FLGINIB;

/*
 *  ���٥�ȥե饰�����֥�å�
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥδ����֥�å��ζ�����ʬ��WOBJCB��
 *  ���ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ��ǽ��2�Ĥ�
 *  �ե�����ɤ����̤ˤʤäƤ��롥
 */
typedef struct eventflag_control_block {
	QUEUE		wait_queue;		/* ���٥�ȥե饰�Ԥ����塼 */
	const FLGINIB *p_flginib;	/* ������֥�å��ؤΥݥ��� */
	FLGPTN		flgptn;			/* ���٥�ȥե饰���ߥѥ����� */
} FLGCB;

/*
 *  ���٥�ȥե饰�Ԥ�����֥�å������
 *
 *  ���ι�¤�Τϡ�Ʊ�����̿����֥������Ȥ��Ԥ�����֥�å��ζ�����ʬ
 *  ��WINFO_WOBJ�ˤ��ĥ�ʥ��֥������Ȼظ�����ηѾ��������ˤ�����Τǡ�
 *  �ǽ��2�ĤΥե�����ɤ����̤ˤʤäƤ��롥
 *
 *  flgptn�ϡ�waiptn�����wfmode��Ʊ���˻Ȥ����ȤϤʤ����ᡤ�����Τ��
 *  ���Х�������󤹤뤳�Ȥ���ǽ�Ǥ��롥
 */
typedef struct eventflag_waiting_information {
	WINFO		winfo;			/* ɸ����Ԥ�����֥�å� */
	FLGCB		*p_flgcb;		/* �ԤäƤ��륤�٥�ȥե饰�δ����֥�å� */
	FLGPTN		waiptn;			/* �Ԥ��ѥ����� */
	MODE		wfmode;			/* �Ԥ��⡼�� */
	FLGPTN		flgptn;			/* �Ԥ�������Υѥ����� */
} WINFO_FLG;

/*
 *  ���٥�ȥե饰ID�κ����͡�kernel_cfg.c��
 */
extern const ID	tmax_flgid;

/*
 *  ���٥�ȥե饰������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern const FLGINIB	flginib_table[];

/*
 *  ���٥�ȥե饰�����֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern FLGCB	flgcb_table[];

/*
 *  ���٥�ȥե饰�����֥�å����饤�٥�ȥե饰ID����Ф�����Υޥ���
 */
#define	FLGID(p_flgcb)	((ID)(((p_flgcb) - flgcb_table) + TMIN_FLGID))

/*
 *  ���٥�ȥե饰��ǽ�ν����
 */
extern void	initialize_eventflag(void);

/*
 *  ���٥�ȥե饰�Ԥ�������Υ����å�
 */
extern bool_t	check_flg_cond(FLGCB *p_flgcb, FLGPTN waiptn,
								MODE wfmode, FLGPTN *p_flgptn);

#endif /* TOPPERS_EVENTFLAG_H */
