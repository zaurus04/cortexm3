/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: target_stddef.h 778 2008-03-11 02:12:39Z hiro $
 */

/*
 *		t_stddef.h�Υ������åȰ�¸����DVE68K/40�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�t_stddef.h����Ƭ�ǥ��󥯥롼�ɤ���롥
 *  ¾�Υե����뤫���ľ�ܥ��󥯥롼�ɤ��뤳�ȤϤʤ���¾�Υ��󥯥롼��
 *  �ե��������Ω�äƽ�������뤿�ᡤ¾�Υ��󥯥롼�ɥե�����˰�¸��
 *  �ƤϤʤ�ʤ���
 */

#ifndef TOPPERS_TARGET_STDDEF_H
#define TOPPERS_TARGET_STDDEF_H

/*
 *  �������åȤ��̤��뤿��Υޥ�������
 */
#define TOPPERS_DVE68K				/* �����ƥ�ά�� */

/*
 *  ��ȯ�Ķ��Ƕ��̤����
 *
 *  ��ȯ�Ķ���stdint.h���Ѱդ���Ƥ�����ˤϡ�TOPPERS_STDINT_TYPE1��
 *  �ޥ��������������stdint.h�򥤥󥯥롼�ɤ���Ф褤��
 */
#define TOPPERS_STDINT_TYPE1
#define TOPPERS_STDFLOAT_TYPE1
#include "gcc/tool_stddef.h"

/*
 *  �ץ��å��Ƕ��̤����
 */
#include "m68k_gcc/prc_stddef.h"

/*
 *  �����������μ��Ի��μ¹����ǽ���
 */
#ifndef TOPPERS_MACRO_ONLY
#ifdef TOPPERS_GDB_STUB				/* GDB������ */

Inline void
TOPPERS_assert_abort(void)
{
	Asm("trap #2");
}

#else /* TOPPERS_GDB_STUB */		/* ����¾�γ�ȯ�Ķ� */

extern void		TOPPERS_assert_abort(void);

#endif /* TOPPERS_GDB_STUB */
#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_STDDEF_H */
