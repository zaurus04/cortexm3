/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: serial.c 1176 2008-07-01 10:24:46Z ertl-hiro $
 */

/*
 *		���ꥢ�륤�󥿥ե������ɥ饤��
 */

#include <kernel.h>
#include <t_syslog.h>
#include "target_syssvc.h"
#include "target_serial.h"
#include "serial.h"
#include "kernel_cfg.h"

/*
 *  �Хåե��������Υǥե�����ͤȥХåե������
 */
#ifndef SERIAL_RCV_BUFSZ1
#define	SERIAL_RCV_BUFSZ1	256			/* �ݡ���1�μ����Хåե������� */
#endif /* SERIAL_RCV_BUFSZ1 */

#ifndef SERIAL_SND_BUFSZ1
#define	SERIAL_SND_BUFSZ1	256			/* �ݡ���1�������Хåե������� */
#endif /* SERIAL_SND_BUFSZ1 */

static char_t	rcv_buffer1[SERIAL_RCV_BUFSZ1];
static char_t	snd_buffer1[SERIAL_SND_BUFSZ1];

#if TNUM_PORT >= 2						/* �ݡ���2�˴ؤ������ */

#ifndef SERIAL_RCV_BUFSZ2
#define	SERIAL_RCV_BUFSZ2	256			/* �ݡ���2�μ����Хåե������� */
#endif /* SERIAL_RCV_BUFSZ2 */

#ifndef SERIAL_SND_BUFSZ2
#define	SERIAL_SND_BUFSZ2	256			/* �ݡ���2�������Хåե������� */
#endif /* SERIAL_SND_BUFSZ2 */

static char_t	rcv_buffer2[SERIAL_RCV_BUFSZ2];
static char_t	snd_buffer2[SERIAL_SND_BUFSZ2];

#endif /* TNUM_PORT >= 2 */

#if TNUM_PORT >= 3						/* �ݡ���3�˴ؤ������ */

#ifndef SERIAL_RCV_BUFSZ3
#define	SERIAL_RCV_BUFSZ3	256			/* �ݡ���3�μ����Хåե������� */
#endif /* SERIAL_RCV_BUFSZ3 */

#ifndef SERIAL_SND_BUFSZ3
#define	SERIAL_SND_BUFSZ3	256			/* �ݡ���3�������Хåե������� */
#endif /* SERIAL_SND_BUFSZ3 */

static char_t	rcv_buffer3[SERIAL_RCV_BUFSZ3];
static char_t	snd_buffer3[SERIAL_SND_BUFSZ3];

#endif /* TNUM_PORT >= 3 */

/*
 *  �ե�����˴�Ϣ��������ȥޥ���
 */
#define	FC_STOP			'\023'		/* ����ȥ���-S */
#define	FC_START		'\021'		/* ����ȥ���-Q */

#define BUFCNT_STOP(bufsz)		((bufsz) * 3 / 4)	/* STOP��������ʸ���� */
#define BUFCNT_START(bufsz)		((bufsz) / 2)		/* START��������ʸ���� */

/*
 *  ���ꥢ��ݡ��Ƚ�����֥�å�
 */
typedef struct serial_port_initialization_block {
	ID		rcv_semid;		/* �����Хåե������ѥ��ޥե���ID */
	ID		snd_semid;		/* �����Хåե������ѥ��ޥե���ID */
	uint_t	rcv_bufsz;		/* �����Хåե������� */
	char_t	*rcv_buffer;	/* �����Хåե� */
	uint_t	snd_bufsz;		/* �����Хåե������� */
	char_t	*snd_buffer;	/* �����Хåե� */
} SPINIB;

static const SPINIB spinib_table[TNUM_PORT] = {
	{ SERIAL_RCV_SEM1, SERIAL_SND_SEM1,
	  SERIAL_RCV_BUFSZ1, rcv_buffer1,
	  SERIAL_SND_BUFSZ1, snd_buffer1 },
#if TNUM_PORT >= 2
	{ SERIAL_RCV_SEM2, SERIAL_SND_SEM2,
	  SERIAL_RCV_BUFSZ2, rcv_buffer2,
	  SERIAL_SND_BUFSZ2, snd_buffer2 },
#endif /* TNUM_PORT >= 2 */
#if TNUM_PORT >= 3
	{ SERIAL_RCV_SEM3, SERIAL_SND_SEM3,
	  SERIAL_RCV_BUFSZ3, rcv_buffer3,
	  SERIAL_SND_BUFSZ3, snd_buffer3 },
#endif /* TNUM_PORT >= 3 */
};

/*
 *  ���ꥢ��ݡ��ȴ����֥�å�
 */
typedef struct serial_port_control_block {
	const SPINIB *p_spinib;		/* ���ꥢ��ݡ��Ƚ�����֥�å� */
	SIOPCB	*p_siopcb;			/* ���ꥢ��I/O�ݡ��ȴ����֥�å� */
	bool_t	openflag;			/* �����ץ�Ѥߥե饰 */
	bool_t	errorflag;			/* ���顼�ե饰 */
	uint_t	ioctl;				/* ư������������� */

	uint_t	rcv_read_ptr;		/* �����Хåե��ɽФ��ݥ��� */
	uint_t	rcv_write_ptr;		/* �����Хåե�����ߥݥ��� */
	uint_t	rcv_count;			/* �����Хåե����ʸ���� */
	char_t	rcv_fc_chr;			/* ����٤�START/STOP */
	bool_t	rcv_stopped;		/* STOP�����ä����֤��� */

	uint_t	snd_read_ptr;		/* �����Хåե��ɽФ��ݥ��� */
	uint_t	snd_write_ptr;		/* �����Хåե�����ߥݥ��� */
	uint_t	snd_count;			/* �����Хåե����ʸ���� */
	bool_t	snd_stopped;		/* STOP�������ä����֤��� */
} SPCB;

static SPCB	spcb_table[TNUM_PORT];

/*
 *  ���ꥢ��ݡ���ID���饷�ꥢ��ݡ��ȴ����֥�å�����Ф�����Υޥ���
 */
#define INDEX_PORT(portid)	((uint_t)((portid) - 1))
#define get_spcb(portid)	(&(spcb_table[INDEX_PORT(portid)]))

/*
 *  �ݥ��󥿤Υ��󥯥����
 */
#define INC_PTR(ptr, bufsz)		{ if (++(ptr) == (bufsz)) { (ptr) = 0; }}

/*
 *  �����ӥ�������ƽФ��ޥ���
 *
 *  �����ӥ�������ƽФ���ޤ༰exp��ɾ���������ͤ����顼������͡ˤξ�
 *  ��ˤϡ�erc��ercd_exp��ɾ�������ͤ���������error_exit��goto���롥
 */
#define SVC(exp, ercd_exp) \
				{ if ((exp) < 0) { ercd = (ercd_exp); goto error_exit; }}

/*
 *  E_SYS���顼������
 */
static ER
gen_ercd_sys(SPCB *p_spcb)
{
	p_spcb->errorflag = true;
	return(E_SYS);
}

/*
 *  �Ԥ������륵���ӥ������뤫��Υ��顼���Ѵ�
 */
static ER
gen_ercd_wait(ER rercd, SPCB *p_spcb)
{
	switch (MERCD(rercd)) {
	case E_RLWAI:
	case E_DLT:
		return(rercd);
	default:
		p_spcb->errorflag = true;
		return(E_SYS);
	}
}

/*
 *  ���ꥢ�륤�󥿥ե������ɥ饤�Фν�����롼����
 */
void
serial_initialize(intptr_t exinf)
{
	uint_t	i;
	SPCB	*p_spcb;

	for (p_spcb = spcb_table, i = 0; i < TNUM_PORT; p_spcb++, i++) {
		p_spcb->p_spinib = &(spinib_table[i]);
		p_spcb->openflag = false;
	}
}

/*
 *  ���ꥢ��ݡ��ȤΥ����ץ�ʥ����ӥ��������
 */
ER
serial_opn_por(ID portid)
{
	SPCB	*p_spcb;
	ER		ercd;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);				/* �ݡ����ֹ�Υ����å� */
	}
	p_spcb = get_spcb(portid);

	SVC(dis_dsp(), gen_ercd_sys(p_spcb));
	if (p_spcb->openflag) {			/* �����ץ�Ѥߤ��Υ����å� */
		ercd = E_OBJ;
	}
	else {
		/*
		 *  �ѿ��ν����
		 */
		p_spcb->ioctl = (IOCTL_ECHO | IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV);

		p_spcb->rcv_read_ptr = p_spcb->rcv_write_ptr = 0U;
		p_spcb->rcv_count = 0U;
		p_spcb->rcv_fc_chr = '\0';
		p_spcb->rcv_stopped = false;

		p_spcb->snd_read_ptr = p_spcb->snd_write_ptr = 0U;
		p_spcb->snd_count = 0U;
		p_spcb->snd_stopped = false;

		/*
		 *  ����ʹߡ�����ߤ�ػߤ��롥
		 */
		if (loc_cpu() < 0) {
			ercd = E_SYS;
			goto error_exit_enadsp;
		}

		/*
		 *  �ϡ��ɥ�������¸�Υ����ץ����
		 */
		p_spcb->p_siopcb = sio_opn_por(portid, (intptr_t) p_spcb);

		/*
		 *  �������Υ�����Хå�����Ĥ��롥
		 */
		sio_ena_cbr(p_spcb->p_siopcb, SIO_RDY_RCV);
		p_spcb->openflag = true;
		p_spcb->errorflag = false;

		if (unl_cpu() < 0) {
			p_spcb->errorflag = true;
			ercd = E_SYS;
			goto error_exit_enadsp;
		}
		ercd = E_OK;
	}

  error_exit_enadsp:
	SVC(ena_dsp(), gen_ercd_sys(p_spcb));

  error_exit:
	return(ercd);
}

/*
 *  ���ꥢ��ݡ��ȤΥ������ʥ����ӥ��������
 */
ER
serial_cls_por(ID portid)
{
	SPCB	*p_spcb;
	ER		ercd;
	bool_t	eflag = false;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);				/* �ݡ����ֹ�Υ����å� */
	}
	p_spcb = get_spcb(portid);

	SVC(dis_dsp(), gen_ercd_sys(p_spcb));
	if (!(p_spcb->openflag)) {		/* �����ץ�Ѥߤ��Υ����å� */
		ercd = E_OBJ;
	}
	else {
		/*
		 *  �ϡ��ɥ�������¸�Υ���������
		 */
		if (loc_cpu() < 0) {
			eflag = true;
		}
		sio_cls_por(p_spcb->p_siopcb);
		p_spcb->openflag = false;
		if (unl_cpu() < 0) {
			eflag = true;
		}

		/*
		 *  ���ޥե��ν����
		 */
		if (ini_sem(p_spcb->p_spinib->snd_semid) < 0) {
			eflag = true;
		}
		if (ini_sem(p_spcb->p_spinib->rcv_semid) < 0) {
			eflag = true;
		}

		/*
		 *  ���顼�����ɤ�����
		 */
		if (eflag) {
			ercd = gen_ercd_sys(p_spcb);
		}
		else {
			ercd = E_OK;
		}
	}
	SVC(ena_dsp(), gen_ercd_sys(p_spcb));

  error_exit:
	return(ercd);
}

/*
 *  ���ꥢ��ݡ��Ȥؤ�ʸ������
 *
 *  p_spcb�ǻ��ꤵ��륷�ꥢ��I/O�ݡ��Ȥ��Ф��ơ�ʸ��c���������롥ʸ��
 *  �������쥸�����ˤ��줿���ˤ�true���֤��������Ǥʤ����ˤϡ�����
 *  �쥸���������������Ȥ����Τ��륳����Хå��ؿ�����Ĥ���false���֤���
 *  ���δؿ��ϡ�CPU��å����֤ǸƤӽФ���롥
 */
Inline bool_t
serial_snd_chr(SPCB *p_spcb, char_t c)
{
	if (sio_snd_chr(p_spcb->p_siopcb, c)) {
		return(true);
	}
	else {
		sio_ena_cbr(p_spcb->p_siopcb, SIO_RDY_SND);
		return(false);
	}
}

/*
 *  ���ꥢ��ݡ��Ȥؤ�1ʸ������
 */
static ER_BOOL
serial_wri_chr(SPCB *p_spcb, char_t c)
{
	bool_t	buffer_full;
	ER		ercd, rercd;

	/*
	 *  LF������CR���������롥
	 */
	if (c == '\n' && (p_spcb->ioctl & IOCTL_CRLF) != 0U) {
		SVC(rercd = serial_wri_chr(p_spcb, '\r'), rercd);
		if ((bool_t) rercd) {
			SVC(rercd = wai_sem(p_spcb->p_spinib->snd_semid),
										gen_ercd_wait(rercd, p_spcb));
		}
	}

	SVC(loc_cpu(), gen_ercd_sys(p_spcb));
	if (p_spcb->snd_count == 0U && !(p_spcb->snd_stopped)
								&& serial_snd_chr(p_spcb, c)) {
		/*
		 *  ���ꥢ��I/O�ǥХ����������쥸������ʸ��������뤳�Ȥ�������
		 *  ����硥
		 */
		buffer_full = false;
	}
	else {
		/*
		 *  �����Хåե���ʸ��������롥
		 */
		p_spcb->p_spinib->snd_buffer[p_spcb->snd_write_ptr] = c;
		INC_PTR(p_spcb->snd_write_ptr, p_spcb->p_spinib->snd_bufsz);
		p_spcb->snd_count++;
		buffer_full = (p_spcb->snd_count == p_spcb->p_spinib->snd_bufsz);
	}

	SVC(unl_cpu(), gen_ercd_sys(p_spcb));
	ercd = (ER_BOOL) buffer_full;

  error_exit:
	return(ercd);
}

/*
 *  ���ꥢ��ݡ��Ȥؤ�ʸ���������ʥ����ӥ��������
 */
ER_UINT
serial_wri_dat(ID portid, const char_t *buf, uint_t len)
{
	SPCB	*p_spcb;
	bool_t	buffer_full;
	uint_t	wricnt = 0U;
	ER		ercd, rercd;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);				/* �ݡ����ֹ�Υ����å� */
	}

	p_spcb = get_spcb(portid);
	if (!(p_spcb->openflag)) {		/* �����ץ�Ѥߤ��Υ����å� */
		return(E_OBJ);
	}
	if (p_spcb->errorflag) {		/* ���顼���֤��Υ����å� */
		return(E_SYS);
	}

	buffer_full = true;				/* �롼�פ�1����wai_sem���� */
	while (wricnt < len) {
		if (buffer_full) {
			SVC(rercd = wai_sem(p_spcb->p_spinib->snd_semid),
										gen_ercd_wait(rercd, p_spcb));
		}
		SVC(rercd = serial_wri_chr(p_spcb, *buf++), rercd);
		wricnt++;
		buffer_full = (bool_t) rercd;
	}
	if (!buffer_full) {
		SVC(sig_sem(p_spcb->p_spinib->snd_semid), gen_ercd_sys(p_spcb));
	}
	ercd = E_OK;

  error_exit:
	return(wricnt > 0U ? (ER_UINT) wricnt : ercd);
}

/*
 *  ���ꥢ��ݡ��Ȥ����1ʸ������
 */
static bool_t
serial_rea_chr(SPCB *p_spcb, char_t *p_c)
{
	bool_t	buffer_empty;
	ER		ercd;

	SVC(loc_cpu(), gen_ercd_sys(p_spcb));

	/*
	 *  �����Хåե�����ʸ������Ф���
	 */
	*p_c = p_spcb->p_spinib->rcv_buffer[p_spcb->rcv_read_ptr];
	INC_PTR(p_spcb->rcv_read_ptr, p_spcb->p_spinib->rcv_bufsz);
	p_spcb->rcv_count--;
	buffer_empty = (p_spcb->rcv_count == 0U);

	/*
	 *  START���������롥
	 */
	if (p_spcb->rcv_stopped && p_spcb->rcv_count
								<= BUFCNT_START(p_spcb->p_spinib->rcv_bufsz)) {
		if (!serial_snd_chr(p_spcb, FC_START)) {
			p_spcb->rcv_fc_chr = FC_START;
		}
		p_spcb->rcv_stopped = false;
	}

	SVC(unl_cpu(), gen_ercd_sys(p_spcb));
	ercd = (ER_BOOL) buffer_empty;

  error_exit:
	return(ercd);
}

/*
 *  ���ꥢ��ݡ��Ȥ����ʸ��������ʥ����ӥ��������
 */
ER_UINT
serial_rea_dat(ID portid, char_t *buf, uint_t len)
{
	SPCB	*p_spcb;
	bool_t	buffer_empty;
	uint_t	reacnt = 0U;
	char_t	c = '\0';		/* ����ѥ���ηٹ���޻ߤ��뤿��˽�������� */
	ER		ercd, rercd;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);				/* �ݡ����ֹ�Υ����å� */
	}

	p_spcb = get_spcb(portid);
	if (!(p_spcb->openflag)) {		/* �����ץ�Ѥߤ��Υ����å� */
		return(E_OBJ);
	}
	if (p_spcb->errorflag) {		/* ���顼���֤��Υ����å� */
		return(E_SYS);
	}

	buffer_empty = true;			/* �롼�פ�1����wai_sem���� */
	while (reacnt < len) {
		if (buffer_empty) {
			SVC(rercd = wai_sem(p_spcb->p_spinib->rcv_semid),
										gen_ercd_wait(rercd, p_spcb));
		}
		SVC(rercd = serial_rea_chr(p_spcb, &c), rercd);
		*buf++ = c;
		reacnt++;
		buffer_empty = (bool_t) rercd;

		/*
		 *  �������Хå�������
		 */
		if ((p_spcb->ioctl & IOCTL_ECHO) != 0U) {
			SVC(rercd = wai_sem(p_spcb->p_spinib->snd_semid),
										gen_ercd_wait(rercd, p_spcb));
			SVC(rercd = serial_wri_chr(p_spcb, c), rercd);
			if (!((bool_t) rercd)) {
				SVC(sig_sem(p_spcb->p_spinib->snd_semid),
										gen_ercd_sys(p_spcb));
			}
		}
	}
	if (!buffer_empty) {
		SVC(sig_sem(p_spcb->p_spinib->rcv_semid), gen_ercd_sys(p_spcb));
	}
	ercd = E_OK;

  error_exit:
	return(reacnt > 0U ? (ER_UINT) reacnt : ercd);
}

/*
 *  ���ꥢ��ݡ��Ȥ�����ʥ����ӥ��������
 */
ER
serial_ctl_por(ID portid, uint_t ioctl)
{
	SPCB	*p_spcb;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);				/* �ݡ����ֹ�Υ����å� */
	}

	p_spcb = get_spcb(portid);
	if (!(p_spcb->openflag)) {		/* �����ץ�Ѥߤ��Υ����å� */
		return(E_OBJ);
	}
	if (p_spcb->errorflag) {		/* ���顼���֤��Υ����å� */
		return(E_SYS);
	}

	p_spcb->ioctl = ioctl;
	return(E_OK);
}

/*
 *  ���ꥢ��ݡ��Ⱦ��֤λ��ȡʥ����ӥ��������
 */
ER
serial_ref_por(ID portid, T_SERIAL_RPOR *pk_rpor)
{
	SPCB	*p_spcb;

	if (sns_dpn()) {				/* ����ƥ����ȤΥ����å� */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);				/* �ݡ����ֹ�Υ����å� */
	}

	p_spcb = get_spcb(portid);
	if (!(p_spcb->openflag)) {		/* �����ץ�Ѥߤ��Υ����å� */
		return(E_OBJ);
	}
	if (p_spcb->errorflag) {		/* ���顼���֤��Υ����å� */
		return(E_SYS);
	}

	pk_rpor->reacnt = p_spcb->rcv_count;
	pk_rpor->wricnt = p_spcb->snd_count;
	return(E_OK);
}

/*
 *  ���ꥢ��ݡ��Ȥ����������ǽ������Хå�
 */
void
sio_irdy_snd(intptr_t exinf)
{
	SPCB	*p_spcb;

	p_spcb = (SPCB *) exinf;
	if (p_spcb->rcv_fc_chr != '\0') {
		/*
		 *  START/STOP ���������롥
		 */
		(void) sio_snd_chr(p_spcb->p_siopcb, p_spcb->rcv_fc_chr);
		p_spcb->rcv_fc_chr = '\0';
	}
	else if (!(p_spcb->snd_stopped) && p_spcb->snd_count > 0U) {
		/*
		 *  �����Хåե��椫��ʸ������Ф����������롥
		 */
		(void) sio_snd_chr(p_spcb->p_siopcb,
					p_spcb->p_spinib->snd_buffer[p_spcb->snd_read_ptr]);
		INC_PTR(p_spcb->snd_read_ptr, p_spcb->p_spinib->snd_bufsz);
		if (p_spcb->snd_count == p_spcb->p_spinib->snd_bufsz) {
			if (isig_sem(p_spcb->p_spinib->snd_semid) < 0) {
				p_spcb->errorflag = true;
			}
		}
		p_spcb->snd_count--;
	}
	else {
		/*
		 *  �������٤�ʸ�����ʤ����ϡ�������ǽ������Хå���ػߤ��롥
		 */
		sio_dis_cbr(p_spcb->p_siopcb, SIO_RDY_SND);
	}
}

/*
 *  ���ꥢ��ݡ��Ȥ���μ������Υ�����Хå�
 */
void
sio_irdy_rcv(intptr_t exinf)
{
	SPCB	*p_spcb;
	char_t	c;

	p_spcb = (SPCB *) exinf;
	c = (char_t) sio_rcv_chr(p_spcb->p_siopcb);
	if ((p_spcb->ioctl & IOCTL_FCSND) != 0U && c == FC_STOP) {
		/*
		 *  ����������ߤ��롥�������ʸ���Ϥ��Τޤ��������롥
		 */
		p_spcb->snd_stopped = true;
	}
	else if (p_spcb->snd_stopped && (c == FC_START
				|| (p_spcb->ioctl & IOCTL_FCANY) != 0U)) {
		/*
		 *  ������Ƴ����롥
		 */
		p_spcb->snd_stopped = false;
		if (p_spcb->snd_count > 0U) {
			c = p_spcb->p_spinib->snd_buffer[p_spcb->snd_read_ptr];
			if (serial_snd_chr(p_spcb, c)) {
				INC_PTR(p_spcb->snd_read_ptr, p_spcb->p_spinib->snd_bufsz);
				if (p_spcb->snd_count == p_spcb->p_spinib->snd_bufsz) {
					if (isig_sem(p_spcb->p_spinib->snd_semid) < 0) {
						p_spcb->errorflag = true;
					}
				}
				p_spcb->snd_count--;
			}
		}
	}
	else if ((p_spcb->ioctl & IOCTL_FCSND) != 0U && c == FC_START) {
		/*
		 *  �������Ф��ƥե����椷�Ƥ����硤START �ϼΤƤ롥
		 */
	}
	else if (p_spcb->rcv_count == p_spcb->p_spinib->rcv_bufsz) {
		/*
		 *  �Хåե��ե�ξ�硤��������ʸ����ΤƤ롥
		 */
	}
	else {
		/*
		 *  ��������ʸ��������Хåե�������롥
		 */
		p_spcb->p_spinib->rcv_buffer[p_spcb->rcv_write_ptr] = c;
		INC_PTR(p_spcb->rcv_write_ptr, p_spcb->p_spinib->rcv_bufsz);
		if (p_spcb->rcv_count == 0U) {
			if (isig_sem(p_spcb->p_spinib->rcv_semid) < 0) {
				p_spcb->errorflag = true;
			}
		}
		p_spcb->rcv_count++;

		/*
		 *  STOP���������롥
		 */
		if ((p_spcb->ioctl & IOCTL_FCRCV) != 0U && !(p_spcb->rcv_stopped)
						&& p_spcb->rcv_count
							>= BUFCNT_STOP(p_spcb->p_spinib->rcv_bufsz)) {
			if (!serial_snd_chr(p_spcb, FC_STOP)) {
				p_spcb->rcv_fc_chr = FC_STOP;
			}
			p_spcb->rcv_stopped = true;
		}
	}
}

/*
 *  ���ꥢ�륤�󥿥ե������ɥ饤�Ф����̤����ʸ���μ�Ф�
 */
bool_t
serial_get_chr(ID portid, char_t *p_c)
{
	SPCB	*p_spcb;

	if (1 <= portid && portid <= TNUM_PORT) {	/* �ݡ����ֹ�Υ����å� */
		p_spcb = get_spcb(portid);
		if (p_spcb->openflag) {					/* �����ץ�Ѥߤ��Υ����å� */
			if (p_spcb->snd_count > 0U) {
				*p_c = p_spcb->p_spinib->snd_buffer[p_spcb->snd_read_ptr];
				INC_PTR(p_spcb->snd_read_ptr, p_spcb->p_spinib->snd_bufsz);
				p_spcb->snd_count--;
				return(true);
			}
		}
	}
	return(false);
}
