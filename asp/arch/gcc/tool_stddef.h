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
 *  @(#) $Id: tool_stddef.h 819 2008-03-18 12:58:50Z hiro $
 */

/*
 *		t_stddef.h�γ�ȯ�Ķ���¸����GCC�ѡ�
 */

#ifndef TOPPERS_TOOL_STDDEF_H
#define TOPPERS_TOOL_STDDEF_H

/*
 *  ����ѥ���γ�ĥ��ǽ�Τ���Υޥ������
 */
#ifndef __cplusplus					/* C++�ˤ�inline ������ */
#if __STDC_VERSION__ < 199901L		/* C99�ˤ�inline ������ */
#define inline	__inline__			/* ����饤��ؿ� */
#endif /* __STDC_VERSION__ < 199901L */
#endif /* __cplusplus */

#define Inline	static __inline__	/* ����饤��ؿ� */

#ifndef __cplusplus					/* C++�ˤ�asm������ */
#define asm		__asm__				/* ����饤�󥢥���֥� */
#endif /* __cplusplus */

#define Asm		__asm__ volatile	/* ����饤�󥢥���֥�ʺ�Ŭ���޻ߡ�*/

#define NoReturn	__attribute__((__noreturn__))
									/* �꥿���󤷤ʤ��ؿ� */

/*
 *  ��ȯ�Ķ���ɸ�।�󥯥롼�ɥե����������
 *
 *  NULL�������stddef.h���顤INT_MAX��INT_MIN��UINT_MAX��LONG_MAX��
 *  LONG_MIN��ULONG_MAX��CHAR_BIT�������limits.h��������ࡥ
 *
 *  C++/EC++�Ǥϡ�ɸ����;�Ϥ����Υ��󥯥롼�ɥե����뤬�Ѱդ����
 *  ����Ȥϸ¤�ʤ��Τ���դ�ɬ�פǤ���ʤۤȤ�ɤγ�ȯ�Ķ����Ѱդ���
 *  �Ƥ���ˡ�
 */
#ifndef TOPPERS_MACRO_ONLY
#include <stddef.h>
#include <limits.h>
#endif /* TOPPERS_MACRO_ONLY */

/*
 *  stdint.h�����ѤȤʤ����
 *
 *  ��ȯ�Ķ���stdint.h���Ѱդ���Ƥ��餺�����������Υ�����������ѥ���
 *  ������ƤϤޤ���ˡ�stdint.h�����ѤȤʤ������Ϳ���롥
 *
 *  TOPPERS_STDINT_TYPE1: char/short/int/long long�Υӥå�Ĺ�����줾��
 *                        8/16/32/64�ӥåȤǡ��ݥ��󥿤Υӥå�Ĺ��long
 *                        �Υӥå�Ĺ�Ȱ��פ�����
 */
#ifdef TOPPERS_STDINT_TYPE1

/*
 *  ����ѥ����¸�Υǡ����������
 */
#ifndef TOPPERS_MACRO_ONLY

typedef signed char			int8_t;		/* ����դ�8�ӥå����� */
typedef unsigned char		uint8_t;	/* ���̵��8�ӥå����� */

typedef signed short		int16_t;	/* ����դ�16�ӥå����� */
typedef unsigned short		uint16_t;	/* ���̵��16�ӥå����� */

typedef signed int			int32_t;	/* ����դ�32�ӥå����� */
typedef unsigned int		uint32_t;	/* ���̵��32�ӥå����� */

typedef signed long long	int64_t;	/* ����դ�64�ӥå����� */
typedef unsigned long long	uint64_t;	/* ���̵��64�ӥå����� */

typedef int8_t				int_least8_t;	/* 8�ӥåȰʾ������դ����� */
typedef uint8_t				uint_least8_t;	/* 8�ӥåȰʾ�����̵������ */

typedef long				intptr_t;	/* �ݥ��󥿤��Ǽ�Ǥ�������դ����� */
typedef unsigned long		uintptr_t;	/* �ݥ��󥿤��Ǽ�Ǥ������̵������ */

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  ����ѥ����¸�Υǡ������������������ޥ���
 */
#ifndef INT8_C
#define INT8_C(val)			(val)
#endif /* INT8_C */

#ifndef UINT8_C
#define UINT8_C(val)		(val ## U)
#endif /* UINT8_C */

#ifndef INT16_C
#define INT16_C(val)		(val)
#endif /* INT16_C */

#ifndef UINT16_C
#define UINT16_C(val)		(val ## U)
#endif /* UINT16_C */

#ifndef INT32_C
#define INT32_C(val)		(val)
#endif /* INT32_C */

#ifndef UINT32_C
#define UINT32_C(val)		(val ## U)
#endif /* UINT32_C */

#ifndef INT64_C
#define INT64_C(val)		(val ## LL)
#endif /* INT64_C */

#ifndef UINT64_C
#define UINT64_C(val)		(val ## ULL)
#endif /* UINT64_C */

/*
 *  ����ѥ����¸�Υǡ������˳�Ǽ�Ǥ�������ͤȺǾ��ͤ����
 */
#define INT8_MAX			SCHAR_MAX
#define INT8_MIN			SCHAR_MIN
#define UINT8_MAX			UCHAR_MAX

#define INT16_MAX			SHRT_MAX
#define INT16_MIN			SHRT_MIN
#define UINT16_MAX			USHRT_MAX

#define INT32_MAX			INT_MAX
#define INT32_MIN			INT_MIN
#define UINT32_MAX			UINT_MAX

#define INT64_MAX			LLONG_MAX
#define INT64_MIN			LLONG_MIN
#define UINT64_MAX			ULLONG_MAX

#define INT_LEAST8_MAX		INT8_MAX
#define INT_LEAST8_MIN		INT8_MIN
#define UINT_LEAST8_MAX		INT8_MAX

#endif /* TOPPERS_STDINT_TYPE1 */

/*
 *  ��ư���������˴ؤ������
 *
 *  TOPPERS_STDFLOAT_TYPE1: float��IEEE754����ñ������ư����������
 *							double����������ư���������ξ��
 */
#ifdef TOPPERS_STDFLOAT_TYPE1
#ifndef TOPPERS_MACRO_ONLY

typedef float		float32_t;			/* IEEE754����ñ������ư�������� */
typedef double		double64_t;			/* IEEE754������������ư�������� */

#endif /* TOPPERS_MACRO_ONLY */

#define FLOAT32_MIN		1.17549435e-38F
#define FLOAT32_MAX		3.40282347e+38F
#define DOUBLE64_MIN	2.2250738585072014e-308
#define DOUBLE64_MAX	1.7976931348623157e+308

#endif /* TOPPERS_STDFLOAT_TYPE1 */
#endif /* TOPPERS_TOOL_STDDEF_H */
