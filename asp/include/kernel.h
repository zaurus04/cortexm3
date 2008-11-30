/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
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
 *  @(#) $Id: kernel.h 1236 2008-08-10 02:42:00Z ertl-hiro $
 */

/*
 *		TOPPERS/ASP�����ͥ� ɸ��إå��ե�����
 *
 *  TOPPERS/ASP�����ͥ뤬���ݡ��Ȥ��륵���ӥ������������ȡ�ɬ�פʥǡ�
 *  ������������ޥ���������ޤ�إå��ե����롥
 *
 *  ������֥����Υ������ե����뤫�餳�Υե�����򥤥󥯥롼�ɤ����
 *  �ϡ�TOPPERS_MACRO_ONLY��������Ƥ���������ˤ�ꡤ�ޥ�������ʳ���
 *  �����褦�ˤʤäƤ��롥
 *
 *  ���Υե�����򥤥󥯥롼�ɤ������˥��󥯥롼�ɤ��Ƥ����٤��ե�����
 *  �Ϥʤ���
 */

#ifndef TOPPERS_KERNEL_H
#define TOPPERS_KERNEL_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *	TOPPERS���̤Υǡ�������������ޥ���
 */
#include <t_stddef.h>

/*
 *  �������åȰ�¸��
 */
#include "target_kernel.h"

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �ǡ����������
 */

/*
 *  �ӥåȥѥ�����䥪�֥��������ֹ�η����
 */
typedef	uint_t		TEXPTN;		/* �������㳰�װ��Υӥåȥѥ����� */
typedef	uint_t		FLGPTN;		/* ���٥�ȥե饰�Υӥåȥѥ����� */
typedef	uint_t		INTNO;		/* ������ֹ� */
typedef	uint_t		INHNO;		/* ����ߥϥ�ɥ��ֹ� */
typedef	uint_t		EXCNO;		/* CPU�㳰�ϥ�ɥ��ֹ� */

/*
 *  ����ñ�̤η����
 */
typedef void	(*TASK)(intptr_t exinf);
typedef void	(*TEXRTN)(TEXPTN texptn, intptr_t exinf);
typedef void	(*CYCHDR)(intptr_t exinf);
typedef void	(*ALMHDR)(intptr_t exinf);
typedef void	(*ISR)(intptr_t exinf);
typedef void	(*INTHDR)(void);
typedef void	(*EXCHDR)(void *p_excinf);
typedef void	(*INIRTN)(intptr_t exinf);
typedef void	(*TERRTN)(intptr_t exinf);

/*
 *  �����ΰ���ݤΤ���η����
 */
#ifndef TOPPERS_STK_T
#define TOPPERS_STK_T	intptr_t
#endif /* TOPPERS_STK_T */
typedef	TOPPERS_STK_T	STK_T;	/* �����å��ΰ����ݤ��뤿��η� */

#ifndef TOPPERS_MPF_T
#define TOPPERS_MPF_T	intptr_t
#endif /* TOPPERS_MPF_T */
typedef	TOPPERS_MPF_T	MPF_T;	/* ����Ĺ����ס����ΰ����ݤ��뤿��η� */

/*
 *  ��å������إå��η����
 */
typedef	struct t_msg {			/* �᡼��ܥå����Υ�å������إå� */
	struct t_msg	*pk_next;
} T_MSG;

typedef	struct t_msg_pri {		/* ͥ�����դ���å������إå� */
	T_MSG	msgque;				/* ��å������إå� */
	PRI		msgpri;				/* ��å�����ͥ���� */
} T_MSG_PRI;

/*
 *  �ѥ��åȷ��������
 */
typedef struct t_rtsk {
	STAT	tskstat;	/* ���������� */
	PRI		tskpri;		/* �������θ���ͥ���� */
	PRI		tskbpri;	/* �������Υ١���ͥ���� */
	STAT	tskwait;	/* �Ԥ��װ� */
	ID		wobjid;		/* �Ԥ��оݤΥ��֥������Ȥ�ID */
	TMO		lefttmo;	/* �����ॢ���Ȥ���ޤǤλ��� */
	uint_t	actcnt;		/* ��ư�׵ᥭ�塼���󥰿� */
	uint_t	wupcnt;		/* �����׵ᥭ�塼���󥰿� */
} T_RTSK;

typedef struct t_rtex {
	STAT	texstat;	/* �������㳰�����ξ��� */
	TEXPTN	pndptn;		/* ��α�㳰�װ� */
} T_RTEX;

typedef struct t_rsem {
	ID		wtskid;		/* ���ޥե����Ԥ��������Ƭ�Υ�������ID�ֹ� */
	uint_t	semcnt;		/* ���ޥե��θ��ߤλ񸻿� */
} T_RSEM;

typedef struct t_rflg {
	ID		wtskid;		/* ���٥�ȥե饰���Ԥ��������Ƭ�Υ�������ID�ֹ� */
	FLGPTN	flgptn;		/* ���٥�ȥե饰�θ��ߤΥӥåȥѥ����� */
} T_RFLG;

typedef struct t_rdtq {
	ID		stskid;		/* �ǡ������塼�������Ԥ��������Ƭ�Υ�������ID�ֹ� */
	ID		rtskid;		/* �ǡ������塼�μ����Ԥ��������Ƭ�Υ�������ID�ֹ� */
	uint_t	sdtqcnt;	/* �ǡ������塼�����ΰ�˳�Ǽ����Ƥ���ǡ����ο� */
} T_RDTQ;

typedef struct t_rpdq {
	ID		stskid;		/* ͥ���٥ǡ������塼�������Ԥ��������Ƭ�Υ�����
						   ��ID�ֹ� */
	ID		rtskid;		/* ͥ���٥ǡ������塼�μ����Ԥ��������Ƭ�Υ�����
						   ��ID�ֹ� */
	uint_t	spdqcnt;	/* ͥ���٥ǡ������塼�����ΰ�˳�Ǽ����Ƥ���ǡ�
						   ���ο� */
} T_RPDQ;

typedef struct t_rmbx {
	ID		wtskid;		/* �᡼��ܥå������Ԥ��������Ƭ�Υ�������ID�ֹ� */
	T_MSG	*pk_msg;	/* ��å��������塼����Ƭ�ˤĤʤ��줿��å�����
						   ����Ƭ���� */
} T_RMBX;

typedef struct t_rmpf {
	ID		wtskid;		/* ����Ĺ����ס�����Ԥ��������Ƭ�Υ�������
						   ID�ֹ� */
	uint_t	fblkcnt;	/* ����Ĺ����ס����ΰ�ζ��������ΰ�˳��
						   �դ��뤳�Ȥ��Ǥ������Ĺ����֥�å��ο� */
} T_RMPF;

typedef struct t_rcyc {
	STAT	cycstat;	/* �����ϥ�ɥ��ư����� */
	RELTIM	lefttim;	/* ���˼����ϥ�ɥ��ư�������ޤǤ����л��� */
} T_RCYC;

typedef struct t_ralm {
	STAT	almstat;	/* ���顼��ϥ�ɥ��ư����� */
	RELTIM	lefttim;	/* ���顼��ϥ�ɥ��ư�������ޤǤ����л��� */
} T_RALM;

/*
 *  �����ӥ�����������
 */

/*
 *  ������������ǽ
 */
extern ER		act_tsk(ID tskid) throw();
extern ER		iact_tsk(ID tskid) throw();
extern ER_UINT	can_act(ID tskid) throw();
extern ER		ext_tsk(void) throw();
extern ER		ter_tsk(ID tskid) throw();
extern ER		chg_pri(ID tskid, PRI tskpri) throw();
extern ER		get_pri(ID tskid, PRI *p_tskpri) throw();
extern ER		get_inf(intptr_t *p_exinf) throw();
extern ER		ref_tsk(ID tskid, T_RTSK *pk_rtsk) throw();

/*
 *  ��������°Ʊ����ǽ
 */
extern ER		slp_tsk(void) throw();
extern ER		tslp_tsk(TMO tmout) throw();
extern ER		wup_tsk(ID tskid) throw();
extern ER		iwup_tsk(ID tskid) throw();
extern ER_UINT	can_wup(ID tskid) throw();
extern ER		rel_wai(ID tskid) throw();
extern ER		irel_wai(ID tskid) throw();
extern ER		sus_tsk(ID tskid) throw();
extern ER		rsm_tsk(ID tskid) throw();
extern ER		dly_tsk(RELTIM dlytim) throw();

/*
 *  �������㳰������ǽ
 */
extern ER		ras_tex(ID tskid, TEXPTN rasptn) throw();
extern ER		iras_tex(ID tskid, TEXPTN rasptn) throw();
extern ER		dis_tex(void) throw();
extern ER		ena_tex(void) throw();
extern bool_t	sns_tex(void) throw();
extern ER		ref_tex(ID tskid, T_RTEX *pk_rtex) throw();

/*
 *  Ʊ�����̿���ǽ
 */
extern ER		sig_sem(ID semid) throw();
extern ER		isig_sem(ID semid) throw();
extern ER		wai_sem(ID semid) throw();
extern ER		pol_sem(ID semid) throw();
extern ER		twai_sem(ID semid, TMO tmout) throw();
extern ER		ini_sem(ID semid) throw();
extern ER		ref_sem(ID semid, T_RSEM *pk_rsem) throw();

extern ER		set_flg(ID flgid, FLGPTN setptn) throw();
extern ER		iset_flg(ID flgid, FLGPTN setptn) throw();
extern ER		clr_flg(ID flgid, FLGPTN clrptn) throw();
extern ER		wai_flg(ID flgid, FLGPTN waiptn,
						MODE wfmode, FLGPTN *p_flgptn) throw();
extern ER		pol_flg(ID flgid, FLGPTN waiptn,
						MODE wfmode, FLGPTN *p_flgptn) throw();
extern ER		twai_flg(ID flgid, FLGPTN waiptn,
						MODE wfmode, FLGPTN *p_flgptn, TMO tmout) throw();
extern ER		ini_flg(ID flgid) throw();
extern ER		ref_flg(ID flgid, T_RFLG *pk_rflg) throw();

extern ER		snd_dtq(ID dtqid, intptr_t data) throw();
extern ER		psnd_dtq(ID dtqid, intptr_t data) throw();
extern ER		ipsnd_dtq(ID dtqid, intptr_t data) throw();
extern ER		tsnd_dtq(ID dtqid, intptr_t data, TMO tmout) throw();
extern ER		fsnd_dtq(ID dtqid, intptr_t data) throw();
extern ER		ifsnd_dtq(ID dtqid, intptr_t data) throw();
extern ER		rcv_dtq(ID dtqid, intptr_t *p_data) throw();
extern ER		prcv_dtq(ID dtqid, intptr_t *p_data) throw();
extern ER		trcv_dtq(ID dtqid, intptr_t *p_data, TMO tmout) throw();
extern ER		ini_dtq(ID dtqid) throw();
extern ER		ref_dtq(ID dtqid, T_RDTQ *pk_rdtq) throw();

extern ER		snd_pdq(ID pdqid, intptr_t data, PRI datapri) throw();
extern ER		psnd_pdq(ID pdqid, intptr_t data, PRI datapri) throw();
extern ER		ipsnd_pdq(ID pdqid, intptr_t data, PRI datapri) throw();
extern ER		tsnd_pdq(ID pdqid, intptr_t data,
										PRI datapri, TMO tmout) throw();
extern ER		rcv_pdq(ID pdqid, intptr_t *p_data, PRI *p_datapri) throw();
extern ER		prcv_pdq(ID pdqid, intptr_t *p_data, PRI *p_datapri) throw();
extern ER		trcv_pdq(ID pdqid, intptr_t *p_data,
										PRI *p_datapri, TMO tmout) throw();
extern ER		ini_pdq(ID pdqid) throw();
extern ER		ref_pdq(ID pdqid, T_RPDQ *pk_rpdq) throw();

extern ER		snd_mbx(ID mbxid, T_MSG *pk_msg) throw();
extern ER		rcv_mbx(ID mbxid, T_MSG **ppk_msg) throw();
extern ER		prcv_mbx(ID mbxid, T_MSG **ppk_msg) throw();
extern ER		trcv_mbx(ID mbxid, T_MSG **ppk_msg, TMO tmout) throw();
extern ER		ini_mbx(ID mbxid) throw();
extern ER		ref_mbx(ID mbxid, T_RMBX *pk_rmbx) throw();

/*
 *  ����ס��������ǽ
 */
extern ER		get_mpf(ID mpfid, void **p_blk) throw();
extern ER		pget_mpf(ID mpfid, void **p_blk) throw();
extern ER		tget_mpf(ID mpfid, void **p_blk, TMO tmout) throw();
extern ER		rel_mpf(ID mpfid, void *blk) throw();
extern ER		ini_mpf(ID mpfid) throw();
extern ER		ref_mpf(ID mpfid, T_RMPF *pk_rmpf) throw();

/*
 *  ���ִ�����ǽ
 */
extern ER		get_tim(SYSTIM *p_systim) throw();
extern ER		get_utm(SYSUTM *p_sysutm) throw();

extern ER		sta_cyc(ID cycid) throw();
extern ER		stp_cyc(ID cycid) throw();
extern ER		ref_cyc(ID cycid, T_RCYC *pk_rcyc) throw();

extern ER		sta_alm(ID almid, RELTIM almtim) throw();
extern ER		ista_alm(ID almid, RELTIM almtim) throw();
extern ER		stp_alm(ID almid) throw();
extern ER		istp_alm(ID almid) throw();
extern ER		ref_alm(ID almid, T_RALM *pk_ralm) throw();

/*
 *  �����ƥ���ִ�����ǽ
 */
extern ER		rot_rdq(PRI tskpri) throw();
extern ER		irot_rdq(PRI tskpri) throw();
extern ER		get_tid(ID *p_tskid) throw();
extern ER		iget_tid(ID *p_tskid) throw();
extern ER		loc_cpu(void) throw();
extern ER		iloc_cpu(void) throw();
extern ER		unl_cpu(void) throw();
extern ER		iunl_cpu(void) throw();
extern ER		dis_dsp(void) throw();
extern ER		ena_dsp(void) throw();
extern bool_t	sns_ctx(void) throw();
extern bool_t	sns_loc(void) throw();
extern bool_t	sns_dsp(void) throw();
extern bool_t	sns_dpn(void) throw();
extern bool_t	sns_ker(void) throw();
extern ER		ext_ker(void) throw();

/*
 *  ����ߴ�����ǽ
 */
extern ER		dis_int(INTNO intno) throw();
extern ER		ena_int(INTNO intno) throw();
extern ER		chg_ipm(PRI intpri) throw();
extern ER		get_ipm(PRI *p_intpri) throw();

/*
 *  CPU�㳰������ǽ
 */
extern bool_t	xsns_dpn(void *p_excinf) throw();
extern bool_t	xsns_xpn(void *p_excinf) throw();

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  ���֥�������°�������
 */
#define TA_ACT			UINT_C(0x02)	/* ��������ư���줿���֤����� */

#define TA_TPRI			UINT_C(0x01)	/* ���������Ԥ������ͥ���ٽ�� */
#define TA_MPRI			UINT_C(0x02)	/* ��å��������塼��ͥ���ٽ�� */

#define TA_WMUL			UINT_C(0x02)	/* ʣ�����Ԥ������� */
#define TA_CLR			UINT_C(0x04)	/* ���٥�ȥե饰�Υ��ꥢ���� */

#define TA_STA			UINT_C(0x02)	/* �����ϥ�ɥ��ư����֤����� */

#define TA_NONKERNEL	UINT_C(0x02)	/* �����ͥ�������γ���� */

#define TA_ENAINT		UINT_C(0x01)	/* ������׵�ػߥե饰�򥯥ꥢ */
#define TA_EDGE			UINT_C(0x02)	/* ���å��ȥꥬ */

/*
 *  �����ӥ��������ư��⡼�ɤ����
 */
#define TWF_ORW			UINT_C(0x01)	/* ���٥�ȥե饰��OR�Ԥ� */
#define TWF_ANDW		UINT_C(0x02)	/* ���٥�ȥե饰��AND�Ԥ� */

/*
 *  ���֥������Ȥξ��֤����
 */
#define TTS_RUN			UINT_C(0x01)	/* �¹Ծ��� */
#define TTS_RDY			UINT_C(0x02)	/* �¹Բ�ǽ���� */
#define TTS_WAI			UINT_C(0x04)	/* �Ԥ����� */
#define TTS_SUS			UINT_C(0x08)	/* �����Ԥ����� */
#define TTS_WAS			UINT_C(0x0c)	/* ����Ԥ����� */
#define TTS_DMT			UINT_C(0x10)	/* �ٻ߾��� */

#define TTW_SLP			UINT_C(0x0001)	/* �����Ԥ� */
#define TTW_DLY			UINT_C(0x0002)	/* ���ַв��Ԥ� */
#define TTW_SEM			UINT_C(0x0004)	/* ���ޥե��λ񸻳����Ԥ� */
#define TTW_FLG			UINT_C(0x0008)	/* ���٥�ȥե饰�Ԥ� */
#define TTW_SDTQ		UINT_C(0x0010)	/* �ǡ������塼�ؤ������Ԥ� */
#define TTW_RDTQ		UINT_C(0x0020)	/* �ǡ������塼����μ����Ԥ� */
#define TTW_SPDQ		UINT_C(0x0100)	/* ͥ���٥ǡ������塼�ؤ������Ԥ� */
#define TTW_RPDQ		UINT_C(0x0200)	/* ͥ���٥ǡ������塼����μ����Ԥ� */
#define TTW_MBX			UINT_C(0x0040)	/* �᡼��ܥå�������μ����Ԥ� */
#define TTW_MPF			UINT_C(0x2000)	/* ����Ĺ����֥�å��γ����Ԥ� */

#define TTEX_ENA		UINT_C(0x01)	/* �������㳰�������ľ��� */
#define TTEX_DIS		UINT_C(0x02)	/* �������㳰�����ػ߾��� */

#define TCYC_STP		UINT_C(0x01)	/* �����ϥ�ɥ餬ư��Ƥ��ʤ� */
#define TCYC_STA		UINT_C(0x02)	/* �����ϥ�ɥ餬ư��Ƥ��� */

#define TALM_STP		UINT_C(0x01)	/* ���顼��ϥ�ɥ餬ư��Ƥ��ʤ� */
#define TALM_STA		UINT_C(0x02)	/* ���顼��ϥ�ɥ餬ư��Ƥ��� */

/*
 *  ����¾����������
 */
#define TSK_SELF		0			/* ������������ */
#define TSK_NONE		0			/* �������륿�������ʤ� */

#define TPRI_SELF		0			/* ���������Υ١���ͥ���� */
#define TPRI_INI		0			/* �������ε�ư��ͥ���� */

#define TIPM_ENAALL		0			/* �����ͥ���٥ޥ�������� */

/*
 *  ��������ȥޥ���
 */

/*
 *  ͥ���٤��ϰ�
 */
#define TMIN_TPRI		1			/* ������ͥ���٤κǾ��͡ʺǹ��͡�*/
#define TMAX_TPRI		16			/* ������ͥ���٤κ����͡ʺ����͡�*/
#define TMIN_DPRI		1			/* �ǡ���ͥ���٤κǾ��͡ʺǹ��͡�*/
#define TMAX_DPRI		16			/* �ǡ���ͥ���٤κ����͡ʺ����͡�*/
#define TMIN_MPRI		1			/* ��å�����ͥ���٤κǾ��͡ʺǹ��͡�*/
#define TMAX_MPRI		16			/* ��å�����ͥ���٤κ����͡ʺ����͡�*/
#define TMIN_ISRPRI		1			/* ����ߥ����ӥ��롼����ͥ���٤κǾ��� */
#define TMAX_ISRPRI		16			/* ����ߥ����ӥ��롼����ͥ���٤κ����� */

/*
 *  �С���������
 */
#define TKERNEL_MAKER	UINT_C(0x0118)	/* �����ͥ�Υ᡼���������� */
#define TKERNEL_PRID	UINT_C(0x0007)	/* �����ͥ�μ����ֹ� */
#define TKERNEL_SPVER	UINT_C(0xf5b1)	/* �����ͥ���ͤΥС�������ֹ� */
#define TKERNEL_PRVER	UINT_C(0x1032)	/* �����ͥ�ΥС�������ֹ� */

/*
 *  ���塼���󥰲���κ�����
 */
#define TMAX_ACTCNT		UINT_C(1)		/* ��ư�׵ᥭ�塼���󥰿��κ����� */
#define TMAX_WUPCNT		UINT_C(1)		/* �����׵ᥭ�塼���󥰿��κ����� */

/*
 *  �ӥåȥѥ�����Υӥåȿ�
 */
#ifndef TBIT_TEXPTN					/* �������㳰�װ��Υӥåȿ� */
#define TBIT_TEXPTN		(sizeof(TEXPTN) * CHAR_BIT)
#endif /* TBIT_TEXPTN */

#ifndef TBIT_FLGPTN					/* ���٥�ȥե饰�Υӥåȿ� */
#define TBIT_FLGPTN		(sizeof(FLGPTN) * CHAR_BIT)
#endif /* TBIT_FLGPTN */

/*
 *  �����ΰ���ݤΤ���Υޥ���
 *
 *  �ʲ���TOPPERS_COUNT_SZ��TOPPERS_ROUND_SZ������ϡ�unit��2�ζҾ�Ǥ�
 *  �뤳�Ȥ��ꤷ�Ƥ��롥
 */
#ifndef TOPPERS_COUNT_SZ
#define TOPPERS_COUNT_SZ(sz, unit)	(((sz) + (unit) - 1) / (unit))
#endif /* TOPPERS_COUNT_SZ */
#ifndef TOPPERS_ROUND_SZ
#define TOPPERS_ROUND_SZ(sz, unit)	(((sz) + (unit) - 1) & ~((unit) - 1))
#endif /* TOPPERS_ROUND_SZ */

#define COUNT_STK_T(sz)		TOPPERS_COUNT_SZ(sz, sizeof(STK_T))
#define ROUND_STK_T(sz)		TOPPERS_ROUND_SZ(sz, sizeof(STK_T))

#define COUNT_MPF_T(sz)		TOPPERS_COUNT_SZ(sz, sizeof(MPF_T))
#define ROUND_MPF_T(sz)		TOPPERS_ROUND_SZ(sz, sizeof(MPF_T))

/*
 *  ɬ�פʥ����ΰ�Υ�����
 */
#define TSZ_MPF(blkcnt, blksz)		((blkcnt) * ROUND_MPF_T(blksz))

/*
 *  ����¾�ι������
 */
#define TMAX_MAXSEM		UINT_MAX	/* ���ޥե��κ���񸻿��κ����� */

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_KERNEL_H */
