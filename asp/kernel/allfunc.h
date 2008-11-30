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
 *  @(#) $Id: allfunc.h 879 2008-04-11 10:38:16Z hiro $
 */

/*
 *		���٤Ƥδؿ��򥳥�ѥ��뤹�뤿������
 */

#ifndef TOPPERS_ALLFUNC_H
#define TOPPERS_ALLFUNC_H

/* startup.c */
#define TOPPERS_sta_ker
#define TOPPERS_ext_ker

/* task.c */
#define TOPPERS_tskini
#define TOPPERS_tsksched
#define TOPPERS_tskrun
#define TOPPERS_tsknrun
#define TOPPERS_tskdmt
#define TOPPERS_tskact
#define TOPPERS_tskpri
#define TOPPERS_tskrot
#define TOPPERS_tsktex

/* wait.c */
#define TOPPERS_waimake
#define TOPPERS_waicmp
#define TOPPERS_waitmo
#define TOPPERS_waitmook
#define TOPPERS_wairel
#define TOPPERS_wobjwai
#define TOPPERS_wobjwaitmo
#define TOPPERS_iniwque

/* time_event.c */
#define TOPPERS_tmeini
#define TOPPERS_tmeup
#define TOPPERS_tmedown
#define TOPPERS_tmeins
#define TOPPERS_tmedel
#define TOPPERS_tmeltim
#define TOPPERS_sigtim

/* task_manage.c */
#define TOPPERS_act_tsk
#define TOPPERS_iact_tsk
#define TOPPERS_can_act
#define TOPPERS_ext_tsk
#define TOPPERS_ter_tsk
#define TOPPERS_chg_pri
#define TOPPERS_get_pri
#define TOPPERS_get_inf

/* task_refer.c */
#define TOPPERS_ref_tsk

/* task_sync.c */
#define TOPPERS_slp_tsk
#define TOPPERS_tslp_tsk
#define TOPPERS_wup_tsk
#define TOPPERS_iwup_tsk
#define TOPPERS_can_wup
#define TOPPERS_rel_wai
#define TOPPERS_irel_wai
#define TOPPERS_sus_tsk
#define TOPPERS_rsm_tsk
#define TOPPERS_dly_tsk

/* task_except.c */
#define TOPPERS_ras_tex
#define TOPPERS_iras_tex
#define TOPPERS_dis_tex
#define TOPPERS_ena_tex
#define TOPPERS_sns_tex
#define TOPPERS_ref_tex

/* semaphore.c */
#define TOPPERS_semini
#define TOPPERS_sig_sem
#define TOPPERS_isig_sem
#define TOPPERS_wai_sem
#define TOPPERS_pol_sem
#define TOPPERS_twai_sem
#define TOPPERS_ini_sem
#define TOPPERS_ref_sem

/* eventflag.c */
#define TOPPERS_flgini
#define TOPPERS_flgcnd
#define TOPPERS_set_flg
#define TOPPERS_iset_flg
#define TOPPERS_clr_flg
#define TOPPERS_wai_flg
#define TOPPERS_pol_flg
#define TOPPERS_twai_flg
#define TOPPERS_ini_flg
#define TOPPERS_ref_flg

/* dataqueue.c */
#define TOPPERS_dtqini
#define TOPPERS_dtqenq
#define TOPPERS_dtqfenq
#define TOPPERS_dtqdeq
#define TOPPERS_dtqsnd
#define TOPPERS_dtqfsnd
#define TOPPERS_dtqrcv
#define TOPPERS_snd_dtq
#define TOPPERS_psnd_dtq
#define TOPPERS_ipsnd_dtq
#define TOPPERS_tsnd_dtq
#define TOPPERS_fsnd_dtq
#define TOPPERS_ifsnd_dtq
#define TOPPERS_rcv_dtq
#define TOPPERS_prcv_dtq
#define TOPPERS_trcv_dtq
#define TOPPERS_ini_dtq
#define TOPPERS_ref_dtq

/* pridataq.c */
#define TOPPERS_pdqini
#define TOPPERS_pdqenq
#define TOPPERS_pdqdeq
#define TOPPERS_pdqsnd
#define TOPPERS_pdqrcv
#define TOPPERS_snd_pdq
#define TOPPERS_psnd_pdq
#define TOPPERS_ipsnd_pdq
#define TOPPERS_tsnd_pdq
#define TOPPERS_rcv_pdq
#define TOPPERS_prcv_pdq
#define TOPPERS_trcv_pdq
#define TOPPERS_ini_pdq
#define TOPPERS_ref_pdq

/* mailbox.c */
#define TOPPERS_mbxini
#define TOPPERS_snd_mbx
#define TOPPERS_rcv_mbx
#define TOPPERS_prcv_mbx
#define TOPPERS_trcv_mbx
#define TOPPERS_ini_mbx
#define TOPPERS_ref_mbx

/* mempfix.c */
#define TOPPERS_mpfini
#define TOPPERS_mpfget
#define TOPPERS_get_mpf
#define TOPPERS_pget_mpf
#define TOPPERS_tget_mpf
#define TOPPERS_rel_mpf
#define TOPPERS_ini_mpf
#define TOPPERS_ref_mpf

/* time_manage.c */
#define TOPPERS_get_tim
#define TOPPERS_get_utm

/* cyclic.c */
#define TOPPERS_cycini
#define TOPPERS_sta_cyc
#define TOPPERS_stp_cyc
#define TOPPERS_ref_cyc
#define TOPPERS_cyccal

/* alarm.c */
#define TOPPERS_almini
#define TOPPERS_sta_alm
#define TOPPERS_ista_alm
#define TOPPERS_stp_alm
#define TOPPERS_istp_alm
#define TOPPERS_ref_alm
#define TOPPERS_almcal

/* sys_manage.c */
#define TOPPERS_rot_rdq
#define TOPPERS_irot_rdq
#define TOPPERS_get_tid
#define TOPPERS_iget_tid
#define TOPPERS_loc_cpu
#define TOPPERS_iloc_cpu
#define TOPPERS_unl_cpu
#define TOPPERS_iunl_cpu
#define TOPPERS_dis_dsp
#define TOPPERS_ena_dsp
#define TOPPERS_sns_ctx
#define TOPPERS_sns_loc
#define TOPPERS_sns_dsp
#define TOPPERS_sns_dpn
#define TOPPERS_sns_ker

/* interrupt.c */
#define TOPPERS_intini
#define TOPPERS_dis_int
#define TOPPERS_ena_int
#define TOPPERS_chg_ipm
#define TOPPERS_get_ipm

/* exception.c */
#define TOPPERS_excini
#define TOPPERS_xsns_dpn
#define TOPPERS_xsns_xpn

#endif /* TOPPERS_ALLFUNC_H */
