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
 *  @(#) $Id: target_config.h 887 2008-04-11 11:16:07Z hiro $
 */

/*
 *		�������åȰ�¸�⥸�塼���DVE-68K/40�ѡ�
 *
 *  �����ͥ�Υ������åȰ�¸���Υ��󥯥롼�ɥե����롥kernel_impl.h�Υ���
 *  ���åȰ�¸���ΰ����դ��Ȥʤ롥
 */

#ifndef TOPPERS_TARGET_CONFIG_H
#define TOPPERS_TARGET_CONFIG_H

/*
 *  �������åȥ����ƥ�Υϡ��ɥ������񸻤����
 */
#include "dve68k.h"

/*
 *  �ȥ졼�����˴ؤ�������
 */
#ifdef TOPPERS_ENABLE_TRACE
#include "logtrace/trace_config.h"
#endif /* TOPPERS_ENABLE_TRACE */

/*
 *  ASP�����ͥ�ư����Υ���ޥåפȴ�Ϣ�������
 *
 *	00000000 - 0000ffff		ROM��˥��������֥�����ꥢ��64KB��
 *	00010000 - 000fffff		�������ΰ����1MB��
 *	00100000 -				�ǡ����ΰ����3MB��
 *			 - 003fffff		�ǥե���Ȥ��󥿥�������ƥ������ѤΥ����å��ΰ�
 */

/*
 *  �ǥե���Ȥ��󥿥�������ƥ������ѤΥ����å��ΰ�����
 */
#define DEFAULT_ISTKSZ		0x2000U
#define DEFAULT_ISTK		(void *)(0x00400000U - DEFAULT_ISTKSZ)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �ץ��å����̤Τ�����ѿ��ʥޥ���ץ��å��б���
 */
extern uint_t	board_id;		/* �ܡ���ID */
extern void		*board_addr;	/* ������������Ƭ���ɥ쥹 */

/*
 *  ������ֹ���ϰϤ�Ƚ��
 *
 *  �ӥåȥѥ���������Τ��ưפˤ��뤿��ˡ�8�Ϸ��֤ˤʤäƤ��롥
 */
#define VALID_INTNO(intno)	(1U <= (intno) && (intno) <= 31U && (intno) != 8U)
#define VALID_INTNO_DISINT(intno)	VALID_INTNO(intno)
#define VALID_INTNO_CFGINT(intno)	VALID_INTNO(intno)

/*
 *  ������׵�����뤿��Υӥåȥѥ���������ޥ���
 *
 *  ���եȱ黻���٤��ץ��å��ǡ������;͵��������ˤϡ�ɽ�����
 *  ���Ǽ������������褤������ɽ������ʤ顤������ֹ�8����֤ˤ���
 *  ɬ�פϤʤ���
 */
#define DGA_INT_BITPAT(intno)	(1U << (32U - (intno)))

/*
 *  ��٥�ȥꥬ�����å��ȥꥬ������Ǥ��뤫��Ƚ�������
 */
#define DGA_INT_TRG_CONF	(0xe0000000U)	/* ������ˤ�����Ǥ��� */
#define DGA_INT_TRG_LEVEL	(0x108f00feU)	/* ��٥�ȥꥬ�˸��� */
#define DGA_INT_TRG_EDGE	(0x0e70ff00U)	/* ���å��ȥꥬ�˸��� */

/*
 *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ���kernel_cfg.c��
 */
extern const uint32_t	bitpat_cfgint;

/*
 *  ������׵�ػߥե饰�Υ��å�
 *
 *  �����°�������ꤵ��Ƥ��ʤ�������׵�饤����Ф��Ƴ�����׵�ػ�
 *  �ե饰�򥻥åȤ��褦�Ȥ������ˤϡ�false���֤���
 */
Inline bool_t
x_disable_int(INTNO intno)
{
	uint32_t	bitpat = DGA_INT_BITPAT(intno);

	if ((bitpat_cfgint & bitpat) == 0U) {
		return(false);
	}
	dga_bit_and((void *) TADR_DGA_CSR21, ~bitpat);
	return(true);
}

#define t_disable_int(intno)	x_disable_int(intno)
#define i_disable_int(intno)	x_disable_int(intno)

/*
 *  ������׵�ػߥե饰�Υ��ꥢ
 *
 *  �����°�������ꤵ��Ƥ��ʤ�������׵�饤����Ф��Ƴ�����׵�ػ�
 *  �ե饰�򥯥ꥢ���褦�Ȥ������ˤϡ�false���֤���
 */
Inline bool_t
x_enable_int(INTNO intno)
{
	uint32_t	bitpat = DGA_INT_BITPAT(intno);

	if ((bitpat_cfgint & bitpat) == 0U) {
		return(false);
	}
	dga_bit_or((void *) TADR_DGA_CSR21, bitpat);
	return(true);
}

#define t_enable_int(intno)		x_enable_int(intno)
#define i_enable_int(intno)		x_enable_int(intno)

/*
 *  ������׵�Υ��ꥢ
 */
Inline void
x_clear_int(INTNO intno)
{
	dga_write((void *) TADR_DGA_CSR23, DGA_INT_BITPAT(intno));
}

#define t_clear_int(intno)		x_clear_int(intno)
#define i_clear_int(intno)		x_clear_int(intno)

/*
 *  ������׵�Υ����å�
 */
Inline bool_t
x_probe_int(INTNO intno)
{
	return((dga_read((void *) TADR_DGA_CSR20) & DGA_INT_BITPAT(intno)) != 0U);
}

#define t_probe_int(intno)		x_probe_int(intno)
#define i_probe_int(intno)		x_probe_int(intno)

/*
 *  ������׵�饤���°��������
 *
 *  DVE-68K/40��IRC�Ǥϡ�������׵�饤��γ����ͥ���٤�NMI����ꤹ��
 *  ���Ȥ��Ǥ����ᡤ-7��Ϳ�����NMI�����ꤵ��뤳�ȤȤ���ʥ������å���
 *  ���γ�ĥ�ˡ�
 */
extern void	x_config_int(INTNO intno, ATR intatr, PRI intpri);

/*
 *  ����ߥϥ�ɥ��������ɬ�פ�IRC���
 *
 *  ���å��ȥꥬ�ξ��ˤϡ�������׵�򥯥ꥢ���롥���å��ȥꥬ�����
 *  ��ȥꥬ��������Ǥ�����⡤���ߤ������ͤ򸫤��˥��ꥢ���Ƥ��롥
 *  ��٥�ȥꥬ�ξ��⥯�ꥢ�����򤷤ƺ����٤��ʤ�������Ŭ���Ǿä���
 *  ���Ȥ���Ԥ��ơ����ꥢ���ʤ����ȤȤ��Ƥ��롥
 */
Inline void
i_begin_int(INTNO intno)
{
	if ((DGA_INT_BITPAT(intno) & (DGA_INT_TRG_CONF | DGA_INT_TRG_EDGE))
																!= 0U) {
		i_clear_int(intno);
	}
}

/*
 *  ����ߥϥ�ɥ�νи���ɬ�פ�IRC���
 *
 *  DVE-68K/40�Ǥ�ɬ�פ�IRC���Ϥʤ���
 */
Inline void
i_end_int(INTNO intno)
{
}

#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �������åȥ����ƥ��¸�ν����
 */
extern void	target_initialize(void);

/*
 *  �������åȥ����ƥ�ν�λ
 *
 *  �����ƥ��λ������˻Ȥ���
 */
extern void	target_exit(void) NoReturn;

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  ���������Ԥ��Τ��������������SIL�Υ������åȰ�¸����
 */
#define SIL_DLY_TIM1	420
#define SIL_DLY_TIM2	90

/*
 *  �ץ��å���¸�⥸�塼���M68040�ѡ�
 */
#include "m68k_gcc/prc_config.h"

#endif /* TOPPERS_TARGET_CONFIG_H */
