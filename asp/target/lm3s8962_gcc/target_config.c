/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: target_config.c 1309 2008-08-27 07:48:51Z ertl-honda $
 */

/*
 * ターゲット依存モジュール（LM3S8962用）
 */
#include "kernel_impl.h"
#include <sil.h>

#include "hw_types.h"
#include "hw_sysctl.h"
#include "sysctl.h"
#include "hw_memmap.h"
#include "gpio.h"
#include "uart.h"
#include "hw_ints.h"

/*
 *  ターゲット依存の初期化
 */
void
target_initialize(void){
	/*
	 *  クロックの初期化
	 */
	if( DEVICE_IS_REVA2 ) {
		SysCtlLDOSet( SYSCTL_LDO_2_75V );
	}

	SysCtlClockSet( SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ );

	/*
	 *  LEDの初期化
	 */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIODirModeSet( GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_DIR_MODE_OUT );
	GPIOPadConfigSet( GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD );

	/*
	 * チップ依存の初期化
	 */
	prc_initialize();

	/*
	 *  sys_putc が可能になるようにUARTを初期化
	 */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
						(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
						 UART_CONFIG_PAR_NONE));

} 


/*
 *  ターゲット依存の終了処理
 */
void
target_exit(void)
{
	/*
	 *  チップ依存の終了処理
	 */
	prc_terminate();

	/*
	 *  開発環境依存の終了処理
	 */
	while(1);
}


/*
 *  システムログの低レベル出力のための文字出力
 */
void
target_fput_log(char_t c)
{
	if (c == '\n') {
		UARTCharPut(UART0_BASE, '\r');
	}
	UARTCharPut(UART0_BASE, c);
}
