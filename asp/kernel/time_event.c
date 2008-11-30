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
 *  @(#) $Id: time_event.c 874 2008-04-11 10:33:17Z hiro $
 */

/*
 *		�����।�٥�ȴ����⥸�塼��
 */

#include "kernel_impl.h"
#include "check.h"
#include "time_event.h"

/*
 *  �����।�٥�ȥҡ������ޥ���
 */
#define	PARENT(index)		((index) >> 1)		/* �ƥΡ��ɤ���� */
#define	LCHILD(index)		((index) << 1)		/* ���λҥΡ��ɤ���� */
#define	TMEVT_NODE(index)	(tmevt_heap[(index) - 1])

/*
 *  ���٥��ȯ��������ӥޥ���
 *
 *  ���٥��ȯ������ϡ�current_time����������ͤ���Ӥ��롥���ʤ����
 *  current_time��Ǿ��͡ʺǤ�ᤤ����ˡ�current_time-1�������͡ʺǤ�
 *  �󤤻���ˤȤߤʤ�����Ӥ��롥
 */
#define	EVTTIM_LT(t1, t2) (((t1) - current_time) < ((t2) - current_time))
#define	EVTTIM_LE(t1, t2) (((t1) - current_time) <= ((t2) - current_time))

#ifdef TOPPERS_tmeini

/*
 *  ���ߤΥ����ƥ�����ñ��: �ߥ��á�
 *
 *  ��̩�ˤϡ����Υ�����ƥ��å��Υ����ƥ���
 */
EVTTIM	current_time;

/*
 *  ���Υ�����ƥ��å��Υ����ƥ�����ñ��: 1�ߥ��á�
 */
EVTTIM	next_time;

/*
 *  �����ƥ�����ѻ����ѿ���ñ��: 1/TIM_DENO�ߥ��á�
 */
#if TIC_DENO != 1U
uint_t	next_subtime;
#endif /* TIC_DENO != 1U */

/*
 *  �����।�٥�ȥҡ��פκǸ�λ����ΰ�Υ���ǥå���
 */
uint_t	last_index;

/*
 *  �����ޥ⥸�塼��ν����
 */
void
initialize_tmevt(void)
{
	current_time = 0U;
	next_time = current_time + TIC_NUME / TIC_DENO;
#if TIC_DENO != 1U
	next_subtime = TIC_NUME % TIC_DENO;
#endif /* TIC_DENO != 1U */
	last_index = 0U;
}

#endif /* TOPPERS_tmeini */

/*
 *  �����।�٥�Ȥ��������֤�������õ��
 *
 *  ����time��ȯ�����륿���।�٥�Ȥ���������Ρ��ɤ�����뤿��ˡ�
 *  �ҡ��פξ�˸����äƶ��Ρ��ɤ��ư�����롥��ư���ζ��Ρ��ɤΰ��֤�
 *  index���Ϥ��ȡ���ư��ζ��Ρ��ɤΰ��֡ʤ��ʤ���������֡ˤ��֤���
 */
#ifdef TOPPERS_tmeup

uint_t
tmevt_up(uint_t index, EVTTIM time)
{
	uint_t	parent;

	while (index > 1) {
		/*
		 *  �ƥΡ��ɤΥ��٥��ȯ������������ᤤ�ʤޤ���Ʊ����
		 *  �ʤ�С�index ���������֤ʤΤǥ롼�פ�ȴ���롥
		 */
		parent = PARENT(index);
		if (EVTTIM_LE(TMEVT_NODE(parent).time, time)) {
			break;
		}

		/*
		 *  �ƥΡ��ɤ� index �ΰ��֤˰�ư�����롥
		 */
		TMEVT_NODE(index) = TMEVT_NODE(parent);
		TMEVT_NODE(index).p_tmevtb->index = index;

		/*
		 *  index ��ƥΡ��ɤΰ��֤˹�����
		 */
		index = parent;
	}
	return(index);
}

#endif /* TOPPERS_tmeup */

/*
 *  �����।�٥�Ȥ��������֤򲼸�����õ��
 *
 *  ����time��ȯ�����륿���।�٥�Ȥ���������Ρ��ɤ�����뤿��ˡ�
 *  �ҡ��פβ��˸����äƶ��Ρ��ɤ��ư�����롥��ư���ζ��Ρ��ɤΰ��֤� 
 *  index���Ϥ��ȡ���ư��ζ��Ρ��ɤΰ��֡ʤ��ʤ���������֡ˤ��֤���
 */
#ifdef TOPPERS_tmedown

uint_t
tmevt_down(uint_t index, EVTTIM time)
{
	uint_t	child;

	while ((child = LCHILD(index)) <= last_index) {
		/*
		 *  �����λҥΡ��ɤΥ��٥��ȯ���������Ӥ����ᤤ����
		 *  �ҥΡ��ɤΰ��֤� child �����ꤹ�롥�ʲ��λҥΡ���
		 *  �ϡ����������Ф줿���λҥΡ��ɤΤ��ȡ�
		 */
		if (child + 1 <= last_index
						&& EVTTIM_LT(TMEVT_NODE(child + 1).time,
										TMEVT_NODE(child).time)) {
			child = child + 1;
		}

		/*
		 *  �ҥΡ��ɤΥ��٥��ȯ������������٤��ʤޤ���Ʊ����
		 *  �ʤ�С�index ���������֤ʤΤǥ롼�פ�ȴ���롥
		 */
		if (EVTTIM_LE(time, TMEVT_NODE(child).time)) {
			break;
		}

		/*
		 *  �ҥΡ��ɤ� index �ΰ��֤˰�ư�����롥
		 */
		TMEVT_NODE(index) = TMEVT_NODE(child);
		TMEVT_NODE(index).p_tmevtb->index = index;

		/*
		 *  index ��ҥΡ��ɤΰ��֤˹�����
		 */
		index = child;
	}
	return(index);
}

#endif /* TOPPERS_tmedown */

/*
 *  �����।�٥�ȥҡ��פؤ���Ͽ
 *
 *  p_tmevtb�ǻ��ꤷ�������।�٥�ȥ֥�å���time�ǻ��ꤷ�����֤���
 *  ���˥��٥�Ȥ�ȯ������褦�ˡ������।�٥�ȥҡ��פ���Ͽ���롥
 */
#ifdef TOPPERS_tmeins

void
tmevtb_insert(TMEVTB *p_tmevtb, EVTTIM time)
{
	uint_t	index;

	/*
	 *  last_index �򥤥󥯥���Ȥ��������������������֤�õ����
	 */
	index = tmevt_up(++last_index, time);

	/*
	 *  �����।�٥�Ȥ� index �ΰ��֤��������롥
	 */ 
	TMEVT_NODE(index).time = time;
	TMEVT_NODE(index).p_tmevtb = p_tmevtb;
	p_tmevtb->index = index;
}

#endif /* TOPPERS_tmeins */

/*
 *  �����।�٥�ȥҡ��פ���κ��
 */
#ifdef TOPPERS_tmedel

void
tmevtb_delete(TMEVTB *p_tmevtb)
{
	uint_t	index = p_tmevtb->index;
	uint_t	parent;
	EVTTIM	event_time = TMEVT_NODE(last_index).time;

	/*
	 *  ����ˤ�꥿���।�٥�ȥҡ��פ����ˤʤ���ϲ��⤷�ʤ���
	 */
	if (--last_index == 0) {
		return;
	}

	/*
	 *  ��������Ρ��ɤΰ��֤˺Ǹ�ΥΡ��ɡ�last_index+1�ΰ��֤ΥΡ��ɡ�
	 *  ���������������Ŭ�ڤʰ��֤ذ�ư�����롥�ºݤˤϡ��Ǹ�ΥΡ���
	 *  ��ºݤ���������ΤǤϤʤ�����������Ρ��ɤΰ��֤����Ρ��ɤˤ�
	 *  ��Τǡ��Ǹ�ΥΡ��ɤ��������٤����֤ظ����ƶ��Ρ��ɤ��ư����
	 *  �롥
	 *  �Ǹ�ΥΡ��ɤΥ��٥��ȯ�����郎����������Ρ��ɤοƥΡ��ɤΥ�
	 *  �٥��ȯ�����������ξ��ˤϡ���˸����ä��������֤�õ������
	 *  ���Ǥʤ����ˤϡ����˸����ä�õ����
	 */
	if (index > 1 && EVTTIM_LT(event_time,
								TMEVT_NODE(parent = PARENT(index)).time)) {
		/*
		 *  �ƥΡ��ɤ�index�ΰ��֤˰�ư�����롥
		 */
		TMEVT_NODE(index) = TMEVT_NODE(parent);
		TMEVT_NODE(index).p_tmevtb->index = index;

		/*
		 *  ��������Ρ��ɤοƥΡ��ɤ����˸����ä��������֤�õ����
		 */
		index = tmevt_up(parent, event_time);
	}
	else {
		/*
		 *  ��������Ρ��ɤ��鲼�˸����ä��������֤�õ����
		 */
		index = tmevt_down(index, event_time);
	}

	/*
	 *  �Ǹ�ΥΡ��ɤ�index�ΰ��֤��������롥
	 */ 
	TMEVT_NODE(index) = TMEVT_NODE(last_index + 1);
	TMEVT_NODE(index).p_tmevtb->index = index;
}

#endif /* TOPPERS_tmedel */

/*
 *  �����।�٥�ȥҡ��פ���Ƭ�ΥΡ��ɤκ��
 */
Inline void
tmevtb_delete_top(void)
{
	uint_t	index;
	EVTTIM	event_time = TMEVT_NODE(last_index).time;

	/*
	 *  ����ˤ�꥿���।�٥�ȥҡ��פ����ˤʤ���ϲ��⤷�ʤ���
	 */
	if (--last_index == 0) {
		return;
	}

	/*
	 *  �롼�ȥΡ��ɤ˺Ǹ�ΥΡ��ɡ�last_index + 1 �ΰ��֤ΥΡ��ɡˤ�
	 *  �������������Ŭ�ڤʰ��֤ذ�ư�����롥�ºݤˤϡ��Ǹ�ΥΡ��ɤ�
	 *  �ºݤ���������ΤǤϤʤ����롼�ȥΡ��ɤ����Ρ��ɤˤʤ�Τǡ���
	 *  ��ΥΡ��ɤ��������٤����֤ظ����ƶ��Ρ��ɤ��ư�����롥
	 */
	index = tmevt_down(1, event_time);

	/*
	 *  �Ǹ�ΥΡ��ɤ�index�ΰ��֤��������롥
	 */ 
	TMEVT_NODE(index) = TMEVT_NODE(last_index + 1);
	TMEVT_NODE(index).p_tmevtb->index = index;
}

/*
 *  �����।�٥�ȤޤǤλĤ���֤η׻�
 */
#ifdef TOPPERS_tmeltim

RELTIM
tmevt_lefttim(TMEVTB *p_tmevtb)
{
	EVTTIM	time;

	time = TMEVT_NODE(p_tmevtb->index).time;
	if (EVTTIM_LE(time, next_time)) {
		/*
		 *  ���Υ�����ƥ��å��ǽ����������ˤ�0���֤���
		 */
		return(0U);
	}
	else {
		return((RELTIM)(time - base_time));
	}
}

#endif /* TOPPERS_tmeltim */

/*
 *  ������ƥ��å��ζ���
 */
#ifdef TOPPERS_sigtim

void
signal_time(void)
{
	TMEVTB	*p_tmevtb;

	assert(sense_context());
	assert(!i_sense_lock());
	i_lock_cpu();

	/*
	 *  next_time��ꥤ�٥��ȯ��������ᤤ�ʤޤ���Ʊ���˥����।�٥�
	 *  �Ȥ򡤥����।�٥�ȥҡ��פ���������������Хå��ؿ���Ƥӽ�
	 *  ����
	 */
	while (last_index > 0 && EVTTIM_LE(TMEVT_NODE(1).time, next_time)) {
		p_tmevtb = TMEVT_NODE(1).p_tmevtb;
		tmevtb_delete_top();
		(*(p_tmevtb->callback))(p_tmevtb->arg);
	}

	/*
	 *  current_time�򹹿����롥
	 */
	current_time = next_time;

	/*
	 *  next_time��next_subtime�򹹿����롥
	 *
	 *  TIC_NUME < TIC_DENO�λ��ϡ�������Ȥ鷺�˻���ι������Ǥ��뤬��
	 *  �����������ɤ��ɤߤ䤹���ˤ��뤿���#if��¿�Ѥ��򤱤Ƥ��롥
	 */
#if TIC_DENO == 1U
	next_time = current_time + TIC_NUME;
#else /* TIC_DENO == 1U */
	next_subtime += TIC_NUME % TIC_DENO;
	next_time = current_time + TIC_NUME / TIC_DENO;
	if (next_subtime >= TIC_DENO) {
		next_subtime -= TIC_DENO;
		next_time += 1U;
	}
#endif /* TIC_DENO == 1U */

	i_unlock_cpu();
}

#endif /* TOPPERS_sigtim */
