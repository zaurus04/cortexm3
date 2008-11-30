/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  上記著作権者は，以下の (1)～(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
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
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: hw_timer.h,v 1.6 2008/08/03 06:06:48 suikan Exp $
 */

/*
 *	タイマドライバ（CQ-STARM用）
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
//#include <dve68k_dga.h>

/*
 *  タイマ割込みハンドラのベクタ番号
 */
#define	INHNO_TIMER	1	CM3NI // STM32F103のタイマ割り込みハンドラのベクタ番号を割り付けること。1はとりあえず。

#ifndef _MACRO_ONLY

/*
 *  タイマ値の内部表現の型
 */
typedef UW	CLOCK;

/*
 *  タイマ値の内部表現とミリ秒・μ秒単位との変換
 *
 *  CQ_STARMボードでは，タイマは1/72μ秒毎にカウントアップする．
 *  なお、SYSTICK_CURRENT_VALUEはダウンカウンタなので、TO_USECのマイクロ秒は1000から引いた値にする。
 */
#define	TO_CLOCK(nume, deno)	(72000 * (nume) / (deno))
#define	TO_USEC(clock)		(1000- (clock) / 72)	


/*
 *  タイマの現在値を割込み発生前の値とみなすかの判断
 */
#define	GET_TOLERANCE	7200	/* 処理遅れの見積り値（単位は内部表現）*/
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  タイマ停止までの時間（nsec単位）
 *
 *  値に根拠はない．
 */
#define	TIMER_STOP_DELAY	14400


/*
 *  タイマの起動処理
 *
 *  タイマを初期化し，周期的なタイマ割込み要求を発生させる．
 */
Inline void
hw_timer_initialize()
{
	*(volatile UW*)0xE000E010 = 0;			/* SYSTIC Control Reg, initialize */
	*(volatile UW*)0xE000E014 = 72000 - 1;	/* SYSTIC Reload reg. assume clock is 72MHz. generate every 1mS interrupt*/

	*(volatile UW*)0xE000E010 = 0x07;		/* SYSTIC Control Reg. Enable Counting, Multi-shot, interrernal clock source */

}

/*
 *  タイマ割込み要求のクリア
 */
Inline void
hw_timer_int_clear()
{
	CM3NI
/*
 * CORTEX-M3 TRM にも ARMv7M ALARM にもSYSTICK割り込みのクリア方法が書いていない。
 */
}

/*
 *  タイマの停止処理
 *
 *  タイマの動作を停止させる．
 */
Inline void
hw_timer_terminate()
{
	/*
	 *  タイマの動作を停止する．
	 */
	*(volatile UW*)0xE000E010 = 0;			/* SYSTIC Control Reg, initialize */
}

/*
 *  タイマの現在値の読出し
 */
Inline CLOCK
hw_timer_get_current()
{
	return ( *(volatile UW*)0xE000E018 );	/* SYSTICK current Value register */
}

/*
 *  タイマ割込み要求のチェック
 * 割り込みが要求されているならTRUE
 */
Inline BOOL
hw_timer_fetch_interrupt()
{
	CM3NI
	return(0);		/* CORTEX-M3 TRM を読んでも、SYSTICKのPend状態をどう調べればいいのかわからない */
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
