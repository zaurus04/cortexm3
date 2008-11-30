/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
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
 *  @(#) $Id: bit_kernel.c 1234 2008-08-09 14:24:38Z ertl-hiro $
 */

/*
 *		�����ͥ������������
 */

#include "kernel/kernel_impl.h"
#include "kernel/task.h"
#include "kernel/wait.h"
#include "kernel/semaphore.h"
#include "kernel/eventflag.h"
#include "kernel/dataqueue.h"
#include "kernel/pridataq.h"
#include "kernel/mailbox.h"
#include "kernel/mempfix.h"
#include "kernel/time_event.h"

/*
 *   ���顼�����ɤ����
 */
#define E_SYS_LINENO	ERCD(E_SYS, -(__LINE__))

/*
 *  �����֥�å��Υ��ɥ쥹���������Υ����å�
 */
#define VALID_TCB(p_tcb) \
		((((char *) p_tcb) - ((char *) tcb_table)) % sizeof(TCB) == 0 \
			&& TMIN_TSKID <= TSKID(p_tcb) && TSKID(p_tcb) <= tmax_tskid)

#define VALID_SEMCB(p_semcb) \
		((((char *) p_semcb) - ((char *) semcb_table)) % sizeof(SEMCB) == 0 \
			&& TMIN_SEMID <= SEMID(p_semcb) && SEMID(p_semcb) <= tmax_semid)
				
#define VALID_FLGCB(p_flgcb) \
		((((char *) p_flgcb) - ((char *) flgcb_table)) % sizeof(FLGCB) == 0 \
			&& TMIN_FLGID <= FLGID(p_flgcb) && FLGID(p_flgcb) <= tmax_flgid)

#define VALID_DTQCB(p_dtqcb) \
		((((char *) p_dtqcb) - ((char *) dtqcb_table)) % sizeof(DTQCB) == 0 \
			&& TMIN_DTQID <= DTQID(p_dtqcb) && DTQID(p_dtqcb) <= tmax_dtqid)

#define VALID_PDQCB(p_pdqcb) \
		((((char *) p_pdqcb) - ((char *) pdqcb_table)) % sizeof(PDQCB) == 0 \
			&& TMIN_PDQID <= PDQID(p_pdqcb) && PDQID(p_pdqcb) <= tmax_pdqid)

#define VALID_MBXCB(p_mbxcb) \
		((((char *) p_mbxcb) - ((char *) mbxcb_table)) % sizeof(MBXCB) == 0 \
			&& TMIN_MBXID <= MBXID(p_mbxcb) && MBXID(p_mbxcb) <= tmax_mbxid)

#define VALID_MPFCB(p_mpfcb) \
		((((char *) p_mpfcb) - ((char *) mpfcb_table)) % sizeof(MPFCB) == 0 \
			&& TMIN_MPFID <= MPFID(p_mpfcb) && MPFID(p_mpfcb) <= tmax_mpfid)

/*
 *  ���塼�Υ����å��Τ���δؿ�
 *
 *  p_queue��p_entry���ޤޤ�Ƥ��뤫��Ĵ�٤롥�ޤޤ�Ƥ����true���ޤ�
 *  ��Ƥ��ʤ����ˤ�false���֤������֥��󥯤�������ξ��ˤ⡤
 *  false���֤���
 */
static bool_t
in_queue(QUEUE *p_queue, QUEUE *p_entry)
{
	QUEUE	*p_current, *p_next;

	p_current = p_queue->p_next;
	if (p_current->p_prev != p_queue) {
		return(false);					/* ���֥��󥯤������� */
	}
	while (p_current != p_queue) {
		if (p_current == p_entry) {
			return(true);				/* p_entry���ޤޤ�Ƥ��� */
		}

		/*
		 *  ���塼�μ������Ǥ˿ʤ�
		 */
		p_next = p_current->p_next;
		if (p_next->p_prev != p_current) {
			return(false);				 /* ���֥��󥯤������� */
		}
		p_current = p_next;
	}
	return(false);
}

/*
 *  �����å����ؤ��Ƥ��뤫�θ���
 */
static bool_t
on_stack(void *addr, const TINIB *p_tinib)
{
	if (p_tinib->stk <= addr
				&& addr < (void *)((char *)(p_tinib->stk) + p_tinib->stksz)) {
		return(true);
	}
	return(false);
}

/*
 *  �������������������
 */
static ER
bit_task(ID tskid)
{
	TCB			*p_tcb;
	const TINIB	*p_tinib;
	uint_t		tstat, tstat_wait, priority;
	TMEVTB		*p_tmevtb;
	SEMCB		*p_semcb;
	FLGCB		*p_flgcb;
	DTQCB		*p_dtqcb;
	PDQCB		*p_pdqcb;
	MBXCB		*p_mbxcb;
	MPFCB		*p_mpfcb;

	if (!(TMIN_TSKID <= (tskid) && (tskid) <= tmax_tskid)) {
		return(E_ID);
	}
	p_tcb = get_tcb(tskid);
	p_tinib = p_tcb->p_tinib;
	tstat = p_tcb->tstat;
	tstat_wait = (tstat & TS_WAIT_MASK);
	priority = p_tcb->priority;

	/*
	 *  ������֥�å��ؤΥݥ��󥿤θ���
	 */
	if (p_tinib != &(tinib_table[INDEX_TSK(tskid)])) {
		return(E_SYS_LINENO);
	}

	/*
	 *  tstat�θ���
	 */
	switch (tstat & (TS_RUNNABLE | TS_WAITING | TS_SUSPENDED)) {
	case TS_DORMANT:
		if (tstat != TS_DORMANT) {
			return(E_SYS_LINENO);
		}
		break;
	case TS_RUNNABLE:
		if (tstat != TS_RUNNABLE) {
			return(E_SYS_LINENO);
		}
		break;
	case TS_WAITING:
	case (TS_WAITING | TS_SUSPENDED):
		if (!(TS_WAIT_DLY <= tstat_wait && tstat_wait <= TS_WAIT_MPF)) {
			return(E_SYS_LINENO);
		}
		if ((tstat & ~(TS_WAIT_MASK | TS_RUNNABLE | TS_WAITING | TS_SUSPENDED))
																	!= 0U) {
			return(E_SYS_LINENO);
		}
		break;
	case TS_SUSPENDED:
		if (tstat != TS_SUSPENDED) {
			return(E_SYS_LINENO);
		}
		break;
	default:
		return(E_SYS_LINENO);
	}

	/*
	 *  actque�θ���
	 */
	if (TSTAT_DORMANT(tstat) && p_tcb->actque) {
		return(E_SYS_LINENO);
	}

	/*
	 *  ������ͥ���٤θ���
	 */
	if (priority >= TNUM_TPRI) {
		return(E_SYS_LINENO);
	}

	/*
	 *  texptn�θ���
	 */
	if (p_tcb->p_tinib->texrtn == NULL && p_tcb->texptn != 0U) {
		return(E_SYS_LINENO);
	}

	/*
	 *  �ٻ߾��֤ˤ���������å�
	 */
	if (TSTAT_DORMANT(tstat)) {
		if (!(priority == p_tinib->ipriority)
					&& (p_tcb->wupque == false)
					&& (p_tcb->enatex == false)
					&& (p_tcb->texptn == 0U)) {
			return(E_SYS_LINENO);
		}
	}

	/*
	 *  �¹ԤǤ�����֤ˤ���������å�
	 */
	if (TSTAT_RUNNABLE(tstat)) {
		if (!in_queue(&ready_queue[priority], &(p_tcb->task_queue))) {
			return(E_SYS_LINENO);
		}
	}

	/*
	 *  �Ԥ����֤ˤ���������å�
	 */
	if (TSTAT_WAITING(tstat)) {
		if (!on_stack(p_tcb->p_winfo, p_tinib)) {
			return(E_SYS_LINENO);
		}
		p_tmevtb = p_tcb->p_winfo->p_tmevtb;
		if (p_tmevtb != NULL) {
			if (!on_stack(p_tmevtb, p_tinib)) {
				return(E_SYS_LINENO);
			}
			/*
			 *  (*p_tmevtb)�θ�����̤������
			 */
		}

		switch (tstat & TS_WAIT_MASK) {
			case TS_WAIT_SLP:
				if (p_tcb->wupque == true) {
					return(E_SYS_LINENO);
				}
				break;

			case TS_WAIT_DLY:
				if (p_tmevtb == NULL) {
					return(E_SYS_LINENO);
				}
				break;

			case TS_WAIT_SEM:
				p_semcb = ((WINFO_SEM *)(p_tcb->p_winfo))->p_semcb;
				if (!VALID_SEMCB(p_semcb)) {
					return(E_SYS_LINENO);
				}
				if (!in_queue(&(p_semcb->wait_queue), &(p_tcb->task_queue))) {
					return(E_SYS_LINENO);
				}
				break;

			case TS_WAIT_FLG:
				p_flgcb = ((WINFO_FLG *)(p_tcb->p_winfo))->p_flgcb;
				if (!VALID_FLGCB(p_flgcb)) {
					return(E_SYS_LINENO);
				}
				if (!in_queue(&(p_flgcb->wait_queue), &(p_tcb->task_queue))) {
					return(E_SYS_LINENO);
				}
				break;

			case TS_WAIT_SDTQ:
				p_dtqcb = ((WINFO_DTQ *)(p_tcb->p_winfo))->p_dtqcb;
				if (!VALID_DTQCB(p_dtqcb)) {
					return(E_SYS_LINENO);
				}
				if (!in_queue(&(p_dtqcb->swait_queue), &(p_tcb->task_queue))) {
					return(E_SYS_LINENO);
				}
				break;

			case TS_WAIT_RDTQ:
				p_dtqcb = ((WINFO_DTQ *)(p_tcb->p_winfo))->p_dtqcb;
				if (!VALID_DTQCB(p_dtqcb)) {
					return(E_SYS_LINENO);
				}
				if (!in_queue(&(p_dtqcb->rwait_queue), &(p_tcb->task_queue))) {
					return(E_SYS_LINENO);
				}
				break;

			case TS_WAIT_SPDQ:
				p_pdqcb = ((WINFO_PDQ *)(p_tcb->p_winfo))->p_pdqcb;
				if (!VALID_PDQCB(p_pdqcb)) {
					return(E_SYS_LINENO);
				}
				if (!in_queue(&(p_pdqcb->swait_queue), &(p_tcb->task_queue))) {
					return(E_SYS_LINENO);
				}
				break;

			case TS_WAIT_RPDQ:
				p_pdqcb = ((WINFO_PDQ *)(p_tcb->p_winfo))->p_pdqcb;
				if (!VALID_PDQCB(p_pdqcb)) {
					return(E_SYS_LINENO);
				}
				if (!in_queue(&(p_pdqcb->rwait_queue), &(p_tcb->task_queue))) {
					return(E_SYS_LINENO);
				}
				break;

			case TS_WAIT_MBX:
				p_mbxcb = ((WINFO_MBX *)(p_tcb->p_winfo))->p_mbxcb;
				if (!VALID_MBXCB(p_mbxcb)) {
					return(E_SYS_LINENO);
				}
				if (!in_queue(&(p_mbxcb->wait_queue), &(p_tcb->task_queue))) {
					return(E_SYS_LINENO);
				}
				break;

			case TS_WAIT_MPF:
				p_mpfcb = ((WINFO_MPF *)(p_tcb->p_winfo))->p_mpfcb;
				if (!VALID_MPFCB(p_mpfcb)) {
					return(E_SYS_LINENO);
				}
				if (!in_queue(&(p_mpfcb->wait_queue), &(p_tcb->task_queue))) {
					return(E_SYS_LINENO);
				}
				break;
		}
	}

	/*
	 *  tskctxb�θ���
	 */
	if (!TSTAT_DORMANT(tstat) && p_tcb != p_runtsk) {
		/*
		 *  �������åȰ�¸�θ���
		 */
#if 0
		if (bit_tskctxb(&(p_tcb->tskctxb))) {
			return(E_SYS_LINENO);
		}
#endif
	}
	return(E_OK);
}

/*
 *  ���ޥե��������������
 */
#define INDEX_SEM(semid)	((uint_t)((semid) - TMIN_SEMID))
#define get_semcb(semid)	(&(semcb_table[INDEX_SEM(semid)]))

static ER
bit_semaphore(ID semid)
{
	SEMCB			*p_semcb;
	const SEMINIB	*p_seminib;
	uint_t			semcnt;
	QUEUE			*p_queue;
	TCB				*p_tcb;

	if (!(TMIN_SEMID <= (semid) && (semid) <= tmax_semid)) {
		return(E_ID);
	}
	p_semcb = get_semcb(semid);
	p_seminib = p_semcb->p_seminib;
	semcnt = p_semcb->semcnt;

	/*
	 *  ������֥�å��ؤΥݥ��󥿤θ���
	 */
	if (p_seminib != &(seminib_table[INDEX_SEM(semid)])) {
		return(E_SYS_LINENO);
	}

	/*
	 *  semcnt�θ���
	 */
	if (semcnt > p_seminib->maxsem) {
		return(E_SYS_LINENO);
	}

	/*
	 *  wait_queue�θ���
	 */
	if (semcnt == 0) {
		p_queue = p_semcb->wait_queue.p_next;
		while (p_queue != &(p_semcb->wait_queue)) {
			p_tcb = (TCB *) p_queue;
			p_queue = p_queue->p_next;
			if (!VALID_TCB(p_tcb)) {
				return(E_SYS_LINENO);
			}
			if (p_tcb->tstat != (TS_WAITING | TS_WAIT_SEM)) {
				return(E_SYS_LINENO);
			}
			if (p_semcb != ((WINFO_SEM *)(p_tcb->p_winfo))->p_semcb) {
				return(E_SYS_LINENO);
			}
		}
	}
	else {
		if (!queue_empty(&(p_semcb->wait_queue))) {
			return(E_SYS_LINENO);
		}
	}
	return(E_OK);
}

/*
 *  �����������롼��������
 */
ER
bit_kernel(void)
{
	ID		tskid;
	ID		semid;
	ER		ercd;

	/*
	 *  ��������θ���
	 */
	for (tskid = TMIN_TSKID; tskid <= tmax_tskid; tskid++) {
		ercd = bit_task(tskid);
		if (ercd != E_OK) {
			return(ercd);
		}
	}

	/*
	 *  ���ޥե���θ���
	 */
	for (semid = TMIN_SEMID; semid <= tmax_semid; semid++) {
		ercd = bit_semaphore(semid);
		if (ercd != E_OK) {
			return(ercd);
		}
	}

	return(E_OK);
}
