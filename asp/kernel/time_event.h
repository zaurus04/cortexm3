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
 *  @(#) $Id: time_event.h 1096 2008-06-10 10:52:22Z ertl-hiro $
 */

/*
 *		�����।�٥�ȴ����⥸�塼��
 */

#ifndef TOPPERS_TIME_EVENT_H
#define TOPPERS_TIME_EVENT_H

/*
 *  ���٥��ȯ������Υǡ����������
 *
 *  EVTTIM�ϡ�RELTIM�Ȥ��ƻ���Ǥ����ϰϤ��⹭���ϰϤ�ɽ���Ǥ���ɬ��
 *  �����롥��ITRON4.0���ͤΥ���������ɥץ�ե�����Ǥϡ�RELTIM��16�ӥ�
 *  �Ȱʾ�Ǥʤ���Фʤ�ʤ����ᡤEVTTIM��17�ӥåȰʾ�Ǥ��뤳�Ȥ�ɬ��
 *  �Ǥ��롥���Τ��ᡤ16�ӥåȤˤʤ��礬����uint_t�ǤϤʤ���ulong_t��
 *  ������Ƥ��롥
 */
typedef ulong_t	EVTTIM;

/* 
 *  �����।�٥�ȥ֥�å��Υǡ����������
 */
typedef void	(*CBACK)(void *);	/* ������Хå��ؿ��η� */

typedef struct time_event_block {
	uint_t	index;			/* �����।�٥�ȥҡ�����Ǥΰ��� */
	CBACK	callback;		/* ������Хå��ؿ� */
	void	*arg;			/* ������Хå��ؿ����Ϥ����� */
} TMEVTB;

/*
 *  �����।�٥�ȥҡ�����ΥΡ��ɤΥǡ����������
 */
typedef struct time_event_node {
	EVTTIM	time;			/* ���٥��ȯ������ */
	TMEVTB	*p_tmevtb;		/* �б����륿���।�٥�ȥ֥�å� */
} TMEVTN;

/*
 *  �����।�٥�ȥҡ��ס�kernel_cfg.c��
 */
extern TMEVTN	tmevt_heap[];

/*
 *  ���ߤΥ����ƥ�����ñ��: �ߥ��á�
 *
 *  �����ƥ൯ư����0�˽�������졤�ʹߡ�������ƥ��å������뤵����٤�
 *  ñĴ�����ä��롥
 */
extern EVTTIM	current_time;

/*
 *  ���Υ�����ƥ��å��Υ����ƥ�����ñ��: 1�ߥ��á�
 */
extern EVTTIM	next_time;

/*
 *  �����ƥ�����ѻ����ѿ���ñ��: 1/TIM_DENO�ߥ��á�
 *
 *  ���Υ�����ƥ��å��Υ����ƥ����β��̷�򼨤��ʾ�̷��next_time�ˡ�
 *  TIC_DENO��1�λ��ϡ����̷�Ͼ��0�Ǥ��뤿�ᡤ�����ѿ���ɬ�פʤ���
 */
#if TIC_DENO != 1U
extern uint_t	next_subtime;
#endif /* TIC_DENO != 1U */

/*
 *  ���л��֤Υ١��������ñ��: 1�ߥ��á�
 *
 *  ���Υ�����ƥ��å��Υ����ƥ������ڤ�夲�����TIC_DENO��1�λ�
 *  �ϡ�next_time�˰��פ��롥
 */
#if TIC_DENO == 1U
#define	base_time	(next_time)
#else /* TIC_DENO == 1U */
#define	base_time	(next_time + (next_subtime > 0U ? 1U : 0U))
#endif /* TIC_DENO == 1U */

/*
 *  �����।�٥�ȥҡ��פκǸ�λ����ΰ�Υ���ǥå���
 *
 *  �����।�٥�ȥҡ��פ���Ͽ����Ƥ��륿���।�٥�Ȥο��˰��פ��롥
 */
extern uint_t	last_index;

/*
 *  �����।�٥�ȴ����⥸�塼��ν����
 */
extern void	initialize_tmevt(void);

/*
 *  �����।�٥�Ȥ��������֤�õ��
 */
extern uint_t	tmevt_up(uint_t index, EVTTIM time);
extern uint_t	tmevt_down(uint_t index, EVTTIM time);

/*
 *  �����।�٥�ȥҡ��פؤ���Ͽ�Ⱥ��
 */
extern void	tmevtb_insert(TMEVTB *p_tmevtb, EVTTIM time);
extern void	tmevtb_delete(TMEVTB *p_tmevtb);

/*
 *  �����।�٥�ȥ֥�å�����Ͽ�����л��ֻ����
 *
 *  time�ǻ��ꤷ�����л��֤��вᤷ����ˡ�arg������Ȥ���callback����
 *  �ӽФ����褦�ˡ�p_tmevtb�ǻ��ꤷ�������।�٥�ȥ֥�å�����Ͽ��
 *  �롥
 *  
 */
Inline void
tmevtb_enqueue(TMEVTB *p_tmevtb, RELTIM time, CBACK callback, void *arg)
{
	assert(time <= TMAX_RELTIM);

	p_tmevtb->callback = callback;
	p_tmevtb->arg = arg;
	tmevtb_insert(p_tmevtb, base_time + time);
}

/*
 *  �����।�٥�ȥ֥�å�����Ͽ�ʥ��٥��ȯ����������
 *
 *  time�ǻ��ꤷ�����٥��ȯ������ˡ�arg������Ȥ���callback���Ƥӽ�
 *  �����褦�ˡ�p_tmevtb�ǻ��ꤷ�������।�٥�ȥ֥�å�����Ͽ���롥
 */
Inline void
tmevtb_enqueue_evttim(TMEVTB *p_tmevtb, EVTTIM time, CBACK callback, void *arg)
{
	p_tmevtb->callback = callback;
	p_tmevtb->arg = arg;
	tmevtb_insert(p_tmevtb, time);
}

/*
 *  �����।�٥�ȥ֥�å�����Ͽ���
 */
Inline void
tmevtb_dequeue(TMEVTB *p_tmevtb)
{
	tmevtb_delete(p_tmevtb);
}

/*
 *  �����।�٥�ȤޤǤλĤ���֤η׻�
 */
extern RELTIM	tmevt_lefttim(TMEVTB *p_tmevtb);

/*
 *  ������ƥ��å��ζ���
 */
extern void	signal_time(void);

#endif /* TOPPERS_TIME_EVENT_H */
