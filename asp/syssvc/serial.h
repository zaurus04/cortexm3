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
 *  @(#) $Id: serial.h 1176 2008-07-01 10:24:46Z ertl-hiro $
 */

/*
 *		���ꥢ�륤�󥿥ե������ɥ饤��
 */

#ifndef TOPPERS_SERIAL_H
#define TOPPERS_SERIAL_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ���ꥢ�륤�󥿥ե������ɥ饤�Ф��Ѥ���ѥ��å�
 */
typedef struct {
	uint_t		reacnt;			/* �����Хåե����ʸ���� */
	uint_t		wricnt;			/* �����Хåե����ʸ���� */
} T_SERIAL_RPOR;

/*
 *  ���ꥢ�륤�󥿥ե������ɥ饤�Фν�����롼����
 */
extern void		serial_initialize(intptr_t exinf) throw();

/*
 *  ���ꥢ�륤�󥿥ե������ɥ饤�Ф����̤����ʸ���μ�Ф�
 */
extern bool_t	serial_get_chr(ID portid, char_t *p_c) throw();

/*
 *  ���ꥢ�륤�󥿥ե������ɥ饤�ФΥ����ӥ�������
 */
extern ER		serial_opn_por(ID portid) throw();
extern ER		serial_cls_por(ID portid) throw();
extern ER_UINT	serial_rea_dat(ID portid, char_t *buf, uint_t len) throw();
extern ER_UINT	serial_wri_dat(ID portid, const char_t *buf, uint_t len)
																	throw();
extern ER		serial_ctl_por(ID portid, uint_t ioctl) throw();
extern ER		serial_ref_por(ID portid, T_SERIAL_RPOR *pk_rpor) throw();

/*
 *  ���ꥢ�륤�󥿥ե������ɥ饤�Ф�ư�������ѤΤ�������
 *
 *  �ʲ�������ϡ��ӥå���������¤�Ȥä��Ѥ��롥
 */
#define	IOCTL_NULL	0U			/* ����ʤ� */
#define	IOCTL_ECHO	0x0001U		/* ��������ʸ���򥨥����Хå� */
#define	IOCTL_CRLF	0x0010U		/* LF��������������CR���ղ� */
#define	IOCTL_FCSND	0x0100U		/* �������Ф��ƥե������Ԥ� */
#define	IOCTL_FCANY	0x0200U		/* �ɤΤ褦��ʸ���Ǥ������Ƴ� */
#define	IOCTL_FCRCV	0x0400U		/* �������Ф��ƥե������Ԥ� */

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_SERIAL_H */
