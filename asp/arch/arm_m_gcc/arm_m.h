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
 *  @(#) $Id: arm_m.h 1304 2008-08-27 07:28:36Z ertl-honda $
 */

/*
 *  ARMVx-M�Υϡ��ɥ������񸻤����
 */

#ifndef ARM_M_H
#define ARM_M_H


/*
 *  EPSR��T�ӥå�
 */
#define EPSR_T   0x01000000

/*
 * IPSR�� ISR NUMBER
 */
#define IPSR_ISR_NUMBER 0x1ff

/*
 *  �㳰�������ȯ�����˥����å�����Ѥޤ����¸�ΰ�Υ�����
 *  �ܥ����ͥ�Ǥ��㳰�ե졼��ȸƤ�
 */
#define EXC_FRAME_SIZE         (8*4)

/*
 *  �㳰�������ȯ������LR�����ꤵ���EXC_RETURN����
 */
#define EXC_RETURN_HANDLER      0x0
#define EXC_RETURN_THREAD       0x8
#define EXC_RETURN_MSP          0x0
#define EXC_RETURN_PSP          0x4

/*
 *  CONTROL�쥸����
 */
#define CONTROL_PSP            0x02
#define CONTROL_MSP            0x00

/*
 *  �㳰�ֹ�
 */
#define EXCNO_NMI         2
#define EXCNO_HARD        3
#define EXCNO_MPU         4
#define EXCNO_BUS         5
#define EXCNO_USAGE       6
#define EXCNO_SVCALL     11          
#define EXCNO_DEBUG      12
#define EXCNO_PENDSV     14

/*
 *  �㳰�ֹ�κǾ��ͤȺ�����
 */
#define TMIN_EXCNO   2
#define TMAX_EXCNO  14

/*
 *  ������ֹ�
 */
#define IRQNO_SYSTICK    15

/*
 *  ������ֹ�κǾ���
 */
#define TMIN_INTNO       15

/*
 *  �㳰�ե졼��Υ��ե��å�
 */
#define P_EXCINF_OFFSET_EXC_RETURN  0x00
#define P_EXCINF_OFFSET_BASEPRI     0x01
#define P_EXCINF_OFFSET_XPSR        0x09
#define P_EXCINF_OFFSET_PC          0x08

/*
 *  NVIC��Ϣ
 */

/*
 *  ����ȥ���쥸����
 */
#define NVIC_INT_CTRL       0xe000ed04

#define NVIC_PENDSVSET      0x10000000

/*
 *  �����ƥ�ϥ�ɥ顼����ȥ���쥸����
 */
#define NVIC_SYS_HND_CTRL   0xE000ED24

/*
 *  ���㳰�ε��ĥӥå�
 */
#define NVIC_SYS_HND_CTRL_USAGE 0x00040000
#define NVIC_SYS_HND_CTRL_BUS   0x00020000
#define NVIC_SYS_HND_CTRL_MEM   0x00010000

/*
 *  ͥ��������쥸����
 */
#define NVIC_SYS_PRI1       0xE000ED18  // Sys. Handlers 4 to 7 Priority
#define NVIC_SYS_PRI2       0xE000ED1C  // Sys. Handlers 8 to 11 Priority
#define NVIC_SYS_PRI3       0xE000ED20  // Sys. Handlers 12 to 15 Priority
#define NVIC_PRI0           0xE000E400  // IRQ 0 to 3 Priority Register

/*
 *  ����ߵ��ĥ쥸����
 */
#define NVIC_SETENA0        0xE000E100  // IRQ 0 to 31 Set Enable Register

/*
 *  ����߶ػߥ쥸����
 */
#define NVIC_CLRENA0        0xE000E180  // IRQ 0 to 31 Set Disable Register

/*
 *  �٥����ơ��֥륪�ե��åȥ쥸����
 */
#define NVIC_VECTTBL        0xE000ED08


/*
 *  SYSTIC��Ϣ�쥸����
 */
#define SYSTIC_CONTROL_STATUS 0xE000E010
#define SYSTIC_RELOAD_VALUE   0xE000E014
#define SYSTIC_CURRENT_VALUE  0xE000E018
#define SYSTIC_CALIBRATION    0xE000E01C

#define SYSTIC_ENABLE    0x01
#define SYSTIC_TICINT    0x02
#define SYSTIC_CLKSOURCE 0x04
#define SYSTIC_COUNTFLAG 0x10000

#define SYSTIC_SKEW      0x40000000
#define SYSTIC_NOREF     0x80000000
#define SYSTIC_TENMS     0x00ffffff

#endif  /* ARM_M_H */
