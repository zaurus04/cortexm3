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
 *  @(#) $Id: itron.h 1014 2008-05-10 08:28:40Z ertl-hiro $
 */

/*
 *		ITRON���Ͷ��̵���Υǡ�������������ޥ���
 *
 *  ���Υإå��ե�����ϡ�ITRON���Ͷ��̵���Υǡ�������������ޥ������
 *  �ǡ�TOPPERS���̥إå��ե�����˴ޤޤ�ʤ���Τ������ޤࡥITRON��
 *  �ͤȤθߴ�����ɬ�פȤ��륢�ץꥱ������󤬥��󥯥롼�ɤ��뤳�Ȥ���
 *  �ꤷ�Ƥ��롥
 *
 *  ������֥����Υ������ե����뤫�餳�Υե�����򥤥󥯥롼�ɤ����
 *  �ϡ�TOPPERS_MACRO_ONLY��������Ƥ���������ˤ�ꡤ�ޥ�������ʳ���
 *  �����褦�ˤʤäƤ��롥
 */

#ifndef TOPPERS_ITRON_H
#define TOPPERS_ITRON_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  TOPPERS���̥إå��ե�����
 */
#include "t_stddef.h"

/*
 *  ITRON���Ͷ��̥ǡ�����
 */
#ifndef TOPPERS_MACRO_ONLY

#ifdef INT8_MAX
typedef	int8_t			B;			/* ����դ�8�ӥå����� */
#endif /* INT8_MAX */

#ifdef UINT8_MAX
typedef	uint8_t			UB;			/* ���̵��8�ӥå����� */
typedef	uint8_t			VB;			/* ������ޤ�ʤ�8�ӥåȤ��� */
#endif /* UINT8_MAX */

typedef	int16_t			H;			/* ����դ�16�ӥå����� */
typedef	uint16_t		UH;			/* ���̵��16�ӥå����� */
typedef	uint16_t		VH;			/* ������ޤ�ʤ�16�ӥåȤ��� */

typedef	int32_t			W;			/* ����դ�32�ӥå����� */
typedef	uint32_t		UW;			/* ���̵��32�ӥå����� */
typedef	uint32_t		VW;			/* ������ޤ�ʤ�32�ӥåȤ��� */

#ifdef INT64_MAX
typedef	int64_t			D;			/* ����դ�64�ӥå����� */
#endif /* INT64_MAX */

#ifdef UINT64_MAX
typedef	uint64_t		UD;			/* ���̵��64�ӥå����� */
typedef	uint64_t		VD;			/* ������ޤ�ʤ�64�ӥåȤ��� */
#endif /* UINT64_MAX */

typedef	void			*VP;		/* ������ޤ�ʤ���ΤؤΥݥ��� */

typedef int_t			INT;		/* �����ʥ�����������դ����� */
typedef uint_t			UINT;		/* �����ʥ����������̵������ */

typedef bool_t			BOOL;		/* ������ */

typedef	intptr_t		VP_INT;		/* �ݥ��󥿤ޤ�������դ����� */

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  ITRON���Ͷ������
 */
#define	TRUE		true			/* �� */
#define	FALSE		false			/* �� */

/*
 *  ���֥�������°�������
 */
#define TA_HLNG			UINT_C(0x00)	/* �������ѥ��󥿥ե����� */
#define TA_TFIFO		UINT_C(0x00)	/* ���������Ԥ������FIFO��� */
#define TA_MFIFO		UINT_C(0x00)	/* ��å��������塼��FIFO��� */
#define TA_WSGL			UINT_C(0x00)	/* �Ԥ���������1�ĤΤ� */
#define TA_DISINT		UINT_C(0x00)	/* ������׵�ػߥե饰�򥻥å� */
#define TA_LEVEL		UINT_C(0x00)	/* ��٥�ȥꥬ */

/*
 *  �ͥ��Ȳ���κ�����
 */
#define TMAX_SUSCNT		UINT_C(1)		/* �����Ԥ��׵�ͥ��ȿ��κ����� */

/*
 *  �����Ԥ����֤���ζ����Ƴ�
 */
#define frsm_tsk(tskid)		rsm_tsk(tskid)

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_ITRON_H */
