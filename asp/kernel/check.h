/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2007 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: check.h 1139 2008-06-19 07:03:34Z ertl-hiro $
 */

/*
 *		���顼�����å��ѥޥ���
 */

#ifndef TOPPERS_CHECK_H
#define TOPPERS_CHECK_H

/*
 *  ͥ���٤��ϰϤ�Ƚ��
 */
#define VALID_TPRI(tpri)	(TMIN_TPRI <= (tpri) && (tpri) <= TMAX_TPRI)

#ifndef VALID_INTPRI_CHGIPM
#define VALID_INTPRI_CHGIPM(intpri) \
				(TMIN_INTPRI <= (intpri) && (intpri) <= TIPM_ENAALL)
#endif /* VALID_INTPRI_CHGIPM */

/*
 *  ������ͥ���٤Υ����å���E_PAR��
 */
#define CHECK_TPRI(tpri) {									\
	if (!VALID_TPRI(tpri)) {								\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
}

#define CHECK_TPRI_INI(tpri) {								\
	if (!(VALID_TPRI(tpri) || (tpri) == TPRI_INI)) {		\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
}

#define CHECK_TPRI_SELF(tpri) {								\
	if (!(VALID_TPRI(tpri) || (tpri) == TPRI_SELF)) {		\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
}

/*
 *  �����ॢ���Ȼ����ͤΥ����å���E_PAR��
 */
#define CHECK_TMOUT(tmout) {								\
	if (!(TMO_FEVR <= (tmout))) {							\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
}

/*
 *  �����ͥ���٤Υ����å���E_PAR��
 */
#define CHECK_INTPRI_CHGIPM(inttpri) {						\
	if (!VALID_INTPRI_CHGIPM(intpri)) {						\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
}

/*
 *  ������ֹ�Υ����å���E_PAR��
 */
#define CHECK_INTNO_DISINT(intno) {							\
	if (!VALID_INTNO_DISINT(intno)) {						\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
}

/*
 *  ����¾�Υѥ�᡼�����顼�Υ����å���E_PAR��
 */
#define CHECK_PAR(exp) {									\
	if (!(exp)) {											\
		ercd = E_PAR;										\
		goto error_exit;									\
	}														\
}

/*
 *  ���֥�������ID���ϰϤ�Ƚ��
 */
#define VALID_TSKID(tskid)	(TMIN_TSKID <= (tskid) && (tskid) <= tmax_tskid)
#define VALID_SEMID(semid)	(TMIN_SEMID <= (semid) && (semid) <= tmax_semid)
#define VALID_FLGID(flgid)	(TMIN_FLGID <= (flgid) && (flgid) <= tmax_flgid)
#define VALID_DTQID(dtqid)	(TMIN_DTQID <= (dtqid) && (dtqid) <= tmax_dtqid)
#define VALID_PDQID(pdqid)	(TMIN_PDQID <= (pdqid) && (pdqid) <= tmax_pdqid)
#define VALID_MBXID(mbxid)	(TMIN_MBXID <= (mbxid) && (mbxid) <= tmax_mbxid)
#define VALID_MPFID(mpfid)	(TMIN_MPFID <= (mpfid) && (mpfid) <= tmax_mpfid)
#define VALID_CYCID(cycid)	(TMIN_CYCID <= (cycid) && (cycid) <= tmax_cycid)
#define VALID_ALMID(almid)	(TMIN_ALMID <= (almid) && (almid) <= tmax_almid)

/*
 *  ���֥�������ID�Υ����å���E_ID��
 */
#define CHECK_TSKID(tskid) {								\
	if (!VALID_TSKID(tskid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
}

#define CHECK_TSKID_SELF(tskid) {							\
	if (!(VALID_TSKID(tskid) || (tskid) == TSK_SELF)) {		\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
}

#define CHECK_SEMID(semid) {								\
	if (!VALID_SEMID(semid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
}

#define CHECK_FLGID(flgid) {								\
	if (!VALID_FLGID(flgid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
}

#define CHECK_DTQID(dtqid) {								\
	if (!VALID_DTQID(dtqid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
}

#define CHECK_PDQID(pdqid) {								\
	if (!VALID_PDQID(pdqid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
}

#define CHECK_MBXID(mbxid) {								\
	if (!VALID_MBXID(mbxid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
}

#define CHECK_MPFID(mpfid) {								\
	if (!VALID_MPFID(mpfid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
}

#define CHECK_CYCID(cycid) {								\
	if (!VALID_CYCID(cycid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
}

#define CHECK_ALMID(almid) {								\
	if (!VALID_ALMID(almid)) {								\
		ercd = E_ID;										\
		goto error_exit;									\
	}														\
}

/*
 *  �ƽФ�����ƥ����ȤΥ����å���E_CTX��
 */
#define CHECK_TSKCTX() {									\
	if (sense_context()) {									\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
}

#define CHECK_INTCTX() {									\
	if (!sense_context()) {									\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
}

/*
 *  �ƽФ�����ƥ����Ȥ�CPU��å����֤Υ����å���E_CTX��
 */
#define CHECK_TSKCTX_UNL() {								\
	if (sense_context() || t_sense_lock()) {				\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
}

#define CHECK_INTCTX_UNL() {								\
	if (!sense_context() || i_sense_lock()) {				\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
}

/*
 *  �ǥ����ѥå���α���֤Ǥʤ����Υ����å���E_CTX��
 */
#define CHECK_DISPATCH() {									\
	if (sense_context() || t_sense_lock() || !dspflg) {		\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
}

/*
 *  ����¾�Υ���ƥ����ȥ��顼�Υ����å���E_CTX��
 */
#define CHECK_CTX(exp) {									\
	if (!(exp)) {											\
		ercd = E_CTX;										\
		goto error_exit;									\
	}														\
}

/*
 *  ������������ꤷ�Ƥ��ʤ����Υ����å���E_ILUSE��
 */
#define CHECK_NONSELF(p_tcb) {								\
	if ((p_tcb) == p_runtsk) {								\
		ercd = E_ILUSE;										\
		goto error_exit;									\
	}														\
}

/*
 *  ����¾���������ѥ��顼�Υ����å���E_ILUSE��
 */
#define CHECK_ILUSE(exp) {									\
	if (!(exp)) {											\
		ercd = E_ILUSE;										\
		goto error_exit;									\
	}														\
}

#endif /* TOPPERS_CHECK_H */
