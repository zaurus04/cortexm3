/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: prc_insn.h 1304 2008-08-27 07:28:36Z ertl-honda $
 */


/*
 *  ������¸���ü�̿��Υ���饤��ؿ������ARM-M�ѡ�
 */

#ifndef CORE_INSN_H
#define CORE_INSN_H

#include <arm_m.h>

/*
 *  FAULTMASK�Υ��å�
 */
Inline void
set_faultmask(void){
	Asm("cpsid f":::"memory");
}

/*
 *  FAULTMASK�Υ��ꥢ
 */
Inline void
clear_faultmask(void){
	Asm("cpsie f":::"memory");
}

/*
 *  PRIMASK�Υ��å�
 */
Inline void
set_primask(void){
	Asm("cpsid i":::"memory");
}

/*
 *  PRIMASK�Υ��ꥢ
 */
Inline void
clear_primask(void){
	Asm("cpsie i":::"memory");
}

/*
 *  BASEPRI�Υ��å�
 */
Inline void
set_basepri(uint32_t val){
	Asm("msr BASEPRI, %0" : : "r"(val) : "memory");
}

/*
 *  BASEPRI�μ���
 */
Inline uint32_t
get_basepri(void){
	uint32_t val;
	Asm("mrs  %0, BASEPRI" : "=r"(val));
	return(val);
}

/*
 *  CONTROL�Υ��å�
 */
Inline void
set_control(uint32_t val){
	Asm("msr control, %0 \n"
		" isb"
		: : "r"(val) : "memory");
}

/*
 *  CONTROL�μ���
 */
Inline uint32_t
get_control(void){
	uint32_t val;
	Asm("mrs  %0, CONTROL" : "=r"(val));
	return(val);
}

/*
 *  ���ơ������쥸������CPSR�ˤθ����ͤ��ɽФ�
 */
Inline uint32_t
get_ipsr(void)
{
    uint32_t sr;
    Asm("mrs  %0, ipsr" : "=r"(sr));
    return(sr);
}

#endif /* CORE_INSN_H */
