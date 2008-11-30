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
 *  @(#) $Id: startup.c 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�����ͥ�ν�����Ƚ�λ����
 */

#include "kernel_impl.h"
#include "time_event.h"
#include <sil.h>

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_KER_ENTER
#define LOG_KER_ENTER()
#endif /* LOG_KER_ENTER */

#ifndef LOG_KER_LEAVE
#define LOG_KER_LEAVE()
#endif /* LOG_KER_LEAVE */

#ifndef LOG_EXT_KER_ENTER
#define LOG_EXT_KER_ENTER()
#endif /* LOG_EXT_KER_ENTER */

#ifndef LOG_EXT_KER_LEAVE
#define LOG_EXT_KER_LEAVE(ercd)
#endif /* LOG_EXT_KER_LEAVE */

#ifdef TOPPERS_sta_ker

/*
 *  �����ͥ�ư����֥ե饰
 *
 *  �������ȥ��åץ롼����ǡ�false�ʡ�0�ˤ˽��������뤳�Ȥ���Ԥ���
 *  ���롥
 */
bool_t	kerflg = false;

/*
 *  �����ͥ�ε�ư
 */
void
sta_ker(void)
{
	/*
	 *  �������åȰ�¸�ν����
	 */
	target_initialize();

	/*
	 *  �ƥ⥸�塼��ν����
	 *
	 *  �����।�٥�ȴ����⥸�塼���¾�Υ⥸�塼������˽����
	 *  ����ɬ�פ����롥
	 */
	initialize_tmevt();
	initialize_object();

	/*
	 *  ������롼����μ¹�
	 */ 
	call_inirtn();

	/*
	 *  �����ͥ�ư��γ���
	 */
	kerflg = true;
	LOG_KER_ENTER();
	start_dispatch();
	assert(0);
}

#endif /* TOPPERS_sta_ker */

/*
 *  �����ͥ�ν�λ
 */
#ifdef TOPPERS_ext_ker

ER
ext_ker(void)
{
	SIL_PRE_LOC;

	LOG_EXT_KER_ENTER();

	/*
	 *  ����ߥ�å����֤˰ܹ�
	 */
	SIL_LOC_INT();

	/*
	 *  �����ͥ�ư��ν�λ
	 */
	LOG_KER_LEAVE();
	kerflg = false;

	/*
	 *  �����ͥ�ν�λ�����θƽФ�
	 *
	 *  �󥿥�������ƥ����Ȥ��ڤ괹���ơ�exit_kernel��ƤӽФ���
	 */
	call_exit_kernel();
	assert(0);
}

/*
 *  �����ͥ�ν�λ����
 */
void
exit_kernel(void)
{
	/*
	 *  ��λ�����롼����μ¹�
	 */
	call_terrtn();

	/*
	 *  atexit�ν����ȥǥ��ȥ饯���μ¹�
	 */
	call_atexit();

	/*
	 *  �������åȰ�¸�ν�λ����
	 */
	target_exit();
	assert(0);
}

#endif /* TOPPERS_ext_ker */
