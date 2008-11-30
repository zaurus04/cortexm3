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
 *  @(#) $Id: cyclic.h 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�����ϥ�ɥ鵡ǽ
 */

#ifndef TOPPERS_CYCLIC_H
#define TOPPERS_CYCLIC_H

#include "time_event.h"

/*
 *  �����ϥ�ɥ������֥�å�
 */
typedef struct cyclic_handler_initialization_block {
	ATR			cycatr;			/* �����ϥ�ɥ�°�� */
	intptr_t	exinf;			/* �����ϥ�ɥ�γ�ĥ���� */
	CYCHDR		cychdr;			/* �����ϥ�ɥ�ε�ư���� */
	RELTIM		cyctim;			/* �����ϥ�ɥ�ε�ư���� */
	RELTIM		cycphs;			/* �����ϥ�ɥ�ε�ư���� */
} CYCINIB;

/*
 *  �����ϥ�ɥ�����֥�å�
 */
typedef struct cyclic_handler_control_block {
	const CYCINIB *p_cycinib;	/* ������֥�å��ؤΥݥ��� */
	bool_t		cycsta;			/* �����ϥ�ɥ��ư����� */
	EVTTIM		evttim;			/* ���˼����ϥ�ɥ��ư������� */
	TMEVTB		tmevtb;			/* �����।�٥�ȥ֥�å� */
} CYCCB;

/*
 *  �����ϥ�ɥ�ID�κ����͡�kernel_cfg.c��
 */
extern const ID	tmax_cycid;

/*
 *  �����ϥ�ɥ������֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern const CYCINIB	cycinib_table[];

/*
 *  �����ϥ�ɥ�����֥�å��Υ��ꥢ��kernel_cfg.c��
 */
extern CYCCB	cyccb_table[];

/*
 *  �����ϥ�ɥ鵡ǽ�ν����
 */
extern void	initialize_cyclic(void);

/*
 *  �����ϥ�ɥ鵯ư�롼����
 */
extern void	call_cychdr(CYCCB *p_cyccb);

#endif /* TOPPERS_CYCLIC_H */
