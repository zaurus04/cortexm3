/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006-2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: queue.h 753 2008-03-07 17:40:04Z hiro $
 */

/*
 *		���塼���饤�֥��
 *
 *  ���Υ��塼���饤�֥��Ǥϡ����塼�إå���ޤ��󥰹�¤�Υ��֥�
 *  ��󥯥��塼�򰷤�������Ū�ˤϡ����塼�إå��μ�����ȥ�ϥ��塼��
 *  ��Ƭ�Υ���ȥꡤ������ȥ�ϥ��塼�������Υ���ȥ�Ȥ��롥�ޤ�����
 *  �塼����Ƭ�Υ���ȥ��������ȥ�ȡ����塼�������Υ���ȥ�μ�����
 *  �ȥ�ϡ����塼�إå��Ȥ��롥���Υ��塼�ϡ�������ȥꡤ������ȥ��
 *  �⼫ʬ���Ȥ�ؤ����塼�إå��Ǥ���魯��
 */

#ifndef	TOPPERS_QUEUE_H
#define	TOPPERS_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ���塼�Υǡ�����¤�����
 */
typedef struct queue {
	struct queue *p_next;		/* ������ȥ�ؤΥݥ��� */
	struct queue *p_prev;		/* ������ȥ�ؤΥݥ��� */
} QUEUE;

/*
 *  ���塼�ν����
 *
 *  p_queue�ˤϥ��塼�إå�����ꤹ�롥
 */
Inline void
queue_initialize(QUEUE *p_queue)
{
	p_queue->p_prev = p_queue->p_next = p_queue;
}

/*
 *  ���塼��������ȥ�ؤ�����
 *
 *  p_queue������p_entry���������롥p_queue�˥��塼�إå�����ꤷ����
 *  ��ˤϡ����塼��������p_entry���������뤳�Ȥˤʤ롥
 */
Inline void
queue_insert_prev(QUEUE *p_queue, QUEUE *p_entry)
{
	p_entry->p_prev = p_queue->p_prev;
	p_entry->p_next = p_queue;
	p_queue->p_prev->p_next = p_entry;
	p_queue->p_prev = p_entry;
}

/*
 *  ����ȥ�κ��
 *
 *  p_entry�򥭥塼���������롥
 */
Inline void
queue_delete(QUEUE *p_entry)
{
	p_entry->p_prev->p_next = p_entry->p_next;
	p_entry->p_next->p_prev = p_entry->p_prev;
}

/*
 *  ���塼�μ�����ȥ�μ�Ф�
 *
 *  p_queue�μ�����ȥ�򥭥塼���������������������ȥ���֤���
 *  p_queue�˥��塼�إå�����ꤷ�����ˤϡ����塼����Ƭ�Υ���ȥ��
 *  ���Ф����Ȥˤʤ롥p_queue�˶��Υ��塼����ꤷ�ƸƤӽФ��ƤϤʤ�
 *  �ʤ���
 */
Inline QUEUE *
queue_delete_next(QUEUE *p_queue)
{
	QUEUE	*p_entry;

	assert(p_queue->p_next != p_queue);
	p_entry = p_queue->p_next;
	p_queue->p_next = p_entry->p_next;
	p_entry->p_next->p_prev = p_queue;
	return(p_entry);
}

/*
 *  ���塼�������ɤ����Υ����å�
 *
 *  p_queue�ˤϥ��塼�إå�����ꤹ�롥
 */
Inline bool_t
queue_empty(QUEUE *p_queue)
{
	if (p_queue->p_next == p_queue) {
		assert(p_queue->p_prev == p_queue);
		return(true);
	}
	return(false);
}

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_QUEUE_H */
