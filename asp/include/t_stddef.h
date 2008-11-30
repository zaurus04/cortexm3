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
 *  @(#) $Id: t_stddef.h 1096 2008-06-10 10:52:22Z ertl-hiro $
 */

/*
 *		TOPPERS���̥إå��ե�����
 *
 *  TOPPERS��Ϣ�Τ��٤ƤΥ������ե�����ǥ��󥯥롼�ɤ��٤��إå��ե���
 *  �롥�Ƽ�Υ����ͥ�䥽�եȥ��������ʤǶ��̤��Ѥ��뤳�Ȥ����ꤷ�Ƥ�
 *  �롥TOPPERS�γƼ�Υ����ͥ�䥽�եȥ��������ʤǶ��̤��Ѥ���ǡ�������
 *  ������ޥ��������ʤɤ�ޤࡥ
 *
 *  ������֥����Υ������ե����뤫�餳�Υե�����򥤥󥯥롼�ɤ����
 *  �ϡ�TOPPERS_MACRO_ONLY��������Ƥ���������ˤ�ꡤ�ޥ�������ʳ���
 *  �����褦�ˤʤäƤ��롥
 *
 *  ���Υե�����򥤥󥯥롼�ɤ������˥��󥯥롼�ɤ��Ƥ����٤��ե�����
 *  �Ϥʤ���
 */

#ifndef TOPPERS_T_STDDEF_H
#define TOPPERS_T_STDDEF_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  �������åȰ�¸��
 */
#include "target_stddef.h"

/*
 *  C����/EC++��throw()���н褹�뤿������
 */
#if !defined(__cplusplus) || defined(__embedded_cplusplus)
#define throw()
#endif

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �������åȰ�¸�Υǡ������Υޥ���Υǥե�������
 */
#ifndef TOPPERS_bool
#define TOPPERS_bool	int				/* �֡��뷿 */
#endif /* TOPPERS_bool */

#ifndef TOPPERS_size
#define TOPPERS_size	uintptr_t		/* �������� */
#endif /* TOPPERS_size */

#ifndef TOPPERS_fp
struct TOPPERS_dummy_t { int TOPPERS_dummy_field; };
typedef	void			(*TOPPERS_fp_t)(struct TOPPERS_dummy_t);
#define TOPPERS_fp		TOPPERS_fp_t	/* �ץ����ε�ư���� */
#endif /* TOPPERS_fp */

/*
 *  ���̥ǡ�����
 */
typedef TOPPERS_bool	bool_t;		/* ������ */
typedef unsigned char	char_t;		/* ���̵����ʸ���� */

typedef signed int		int_t;		/* �����ʥ�����������դ����� */
typedef unsigned int	uint_t;		/* �����ʥ����������̵������ */

typedef signed long		long_t;		/* Ĺ��Υ�����������դ����� */
typedef unsigned long	ulong_t;	/* Ĺ��Υ����������̵������ */

typedef int_t			FN;			/* ��ǽ������ */
typedef	int_t			ER;			/* ���顼������ */
typedef	int_t			ID;			/* ���֥������Ȥ�ID�ֹ� */
typedef	uint_t			ATR;		/* ���֥������Ȥ�°�� */
typedef	uint_t			STAT;		/* ���֥������Ȥξ��� */
typedef	uint_t			MODE;		/* �����ӥ��������ư��⡼�� */
typedef	int_t			PRI;		/* ͥ���� */
typedef	TOPPERS_size	SIZE;		/* �����ΰ�Υ����� */

typedef	int_t			TMO;		/* �����ॢ���Ȼ��� */
typedef	uint_t			RELTIM;		/* ���л��� */
typedef	ulong_t			SYSTIM;		/* �����ƥ���� */
typedef	ulong_t			SYSUTM;		/* ��ǽɾ���ѥ����ƥ���� */

typedef	TOPPERS_fp		FP;			/* �ץ����ε�ư���� */

typedef	int_t			ER_BOOL;	/* ���顼�����ɤޤ��Ͽ����� */
typedef	int_t			ER_ID;		/* ���顼�����ɤޤ���ID�ֹ� */
typedef	int_t			ER_UINT;	/* ���顼�����ɤޤ������̵������ */

typedef	uint32_t		ACPTN;		/* �����������ĥѥ����� */
typedef	struct acvct {				/* �����������ĥ٥��� */
	ACPTN		acptn1;				/* �̾����1�Υ����������ĥѥ����� */
	ACPTN		acptn2;				/* �̾����2�Υ����������ĥѥ����� */
	ACPTN		acptn3;				/* �������Υ����������ĥѥ����� */
	ACPTN		acptn4;				/* �������Υ����������ĥѥ����� */
} ACVCT;

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �����������ޥ���
 */
#ifndef UINT_C
#define UINT_C(val)		(val ## U)		/* uint_t�����������ޥ��� */
#endif /* UINT_C */

#ifndef ULONG_C
#define ULONG_C(val)	(val ## UL)		/* ulong_t�����������ޥ��� */
#endif /* ULONG_C */

/*
 *  �������
 */
#ifndef NULL
#define NULL		0			/* ̵���ݥ��� */
#endif /* NULL */

#ifndef true
#define true		1			/* �� */
#endif /* true */

#ifndef false
#define false		0			/* �� */
#endif /* false */

#define E_OK		0			/* ���ｪλ */

/*
 *  �ᥤ�󥨥顼������
 */
#define E_SYS		(-5)		/* �����ƥ२�顼 */
#define E_NOSPT		(-9)		/* ̤���ݡ��ȵ�ǽ */
#define E_RSFN		(-10)		/* ͽ��ǽ������ */
#define E_RSATR		(-11)		/* ͽ��°�� */
#define E_PAR		(-17)		/* �ѥ�᡼�����顼 */
#define E_ID		(-18)		/* ����ID�ֹ� */
#define E_CTX		(-25)		/* ����ƥ����ȥ��顼 */
#define E_MACV		(-26)		/* ���ꥢ��������ȿ */
#define E_OACV		(-27)		/* ���֥������ȥ���������ȿ */
#define E_ILUSE		(-28)		/* �����ӥ��������������� */
#define E_NOMEM		(-33)		/* ������­ */
#define E_NOID		(-34)		/* ID�ֹ���­ */
#define E_OBJ		(-41)		/* ���֥������Ⱦ��֥��顼 */
#define E_NOEXS		(-42)		/* ���֥�������̤���� */
#define E_QOVR		(-43)		/* ���塼���󥰥����С��ե� */
#define E_RLWAI		(-49)		/* �Ԥ����֤ζ������ */
#define E_TMOUT		(-50)		/* �ݡ���󥰼��Ԥޤ��ϥ����ॢ���� */
#define E_DLT		(-51)		/* �Ԥ����֥������Ȥκ�� */
#define E_CLS		(-52)		/* �Ԥ����֥������Ȥξ����Ѳ� */
#define E_WBLK		(-57)		/* �Υ�֥�å��󥰼��դ� */
#define E_BOVR		(-58)		/* �Хåե������С��ե� */

/*
 *  ���֥�������°��
 */
#define TA_NULL		UINT_C(0)	/* ���֥�������°������ꤷ�ʤ� */

/*
 *  �����ॢ���Ȼ���
 */
#define TMO_POL		0			/* �ݡ���� */
#define TMO_FEVR	(-1)		/* �ʵ��Ԥ� */
#define TMO_NBLK	(-2)		/* �Υ�֥�å��� */

/*
 *  �����������ĥѥ�����
 */
#define TACP_KERNEL		(0U)	/* �����ͥ�ɥᥤ������˥������������ */
#define TACP_SHARED		(~0U)	/* ���٤ƤΥɥᥤ�󤫤饢����������� */

/*
 *  ���˴ؤ���������Ф�����Υޥ���
 */
#ifndef offsetof
#define	offsetof(structure, field)	((uintptr_t) &(((structure *) 0)->field))
#endif /* offsetof */

#ifndef alignof
#define alignof(type)	offsetof(struct { char field1; type field2; }, field2)
#endif /* alignof */

#ifndef ALIGN_TYPE				/* ���饤����ȤΥ����å� */
#define ALIGN_TYPE(addr, type) \
						((((uintptr_t)(addr)) & (alignof(type) - 1)) == 0U)
#endif /* ALIGN_TYPE */

/*
 *  assert�ޥ���
 */
#undef assert
#ifndef NDEBUG
#define assert(exp)		((void)((exp) ? 0 : (TOPPERS_assert_fail(#exp, \
							__FILE__, __LINE__), TOPPERS_assert_abort(), 0)))
#else /* NDEBUG */
#define assert(exp)		((void) 0)
#endif /* NDEBUG */

#ifdef __cplusplus
}
#endif

/*
 *  ���顼������������ʬ��ޥ���
 *
 *  �ʲ��Υޥ�������ϡ�����դ�������2�������ɽ������Ƥ��ꡤ�����ե�
 *  �黻�ҡ�>>�ˤ����ѥ��եȤ���뤳�Ȥ��ꤷ�Ƥ��롥�����Ǥʤ���ȯ��
 *  ���Ǥϡ�target_stddef.h�Ǥ�����������񤭤��ʤ���Фʤ�ʤ���
 *
 *  MERCD�ޥ��������ϡ��ᥤ�󥨥顼�����ɤ���Ǥ��뤳�Ȥ��ꤷ�Ƥ��롥
 *  �����Ǥʤ���硤2�Ĥ���������פ��ʤ��ʤ롥
 */
#ifndef ERCD
#define ERCD(mercd, sercd) \
				((ER)((((uint_t) sercd) << 8) | (((uint_t) mercd) & 0xffU)))
#endif /* ERCD */

#ifndef MERCD
#ifdef INT8_MAX
#define MERCD(ercd)		((ER)((int8_t)(ercd)))
#else /* INT8_MAX */
#define MERCD(ercd)		((ER)(((uint_t) ercd) | ~0xffU))
#endif /* INT8_MAX */
#endif /* MERCD */

#ifndef SERCD
#define SERCD(ercd)		((ER)((ercd) >> 8))
#endif /* SERCD */

/*
 *  �����������ĥѥ����������ޥ���
 */
#define TACP(domid)		(1U << ((domid) - 1))	/* domid�����˥������������ */

/*
 *  ���л��֡�RELTIM�ˤ˻���Ǥ��������
 */
#if UINT_MAX < LONG_MAX
#define TMAX_RELTIM		((RELTIM) UINT_MAX)
#else /* UINT_MAX < LONG_MAX */
#define TMAX_RELTIM		((RELTIM) LONG_MAX)
#endif /* UINT_MAX < LONG_MAX */

#endif /* TOPPERS_T_STDDEF_H */
