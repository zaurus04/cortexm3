/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2008 by TOPPERS/JSP for CORTEX-M3 project
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
 *  @(#) $Id: cpu_support.S,v 1.17 2008/08/02 07:52:58 suikan Exp $
 */

/*
 *	プロセッサ依存モジュール アセンブリ言語部（CORTEX-M3用）
 */

#define	_MACRO_ONLY
#include "jsp_kernel.h"
#include "offset.h"

/*
 *  タスクディスパッチャ
 *
 *  dispatch は，スレッドモード・割込み禁止状態で呼び出さなければならな
 *  い．
 *  runtsk, schedtskは jsp/kernel/task.hで次のように宣言されている
 *
 *  extern TCB * runtsk;
 *  extern TCB * schedtsk;
 */
 	.syntax unified
	.text
	.globl dispatch
	.globl exit_and_dispatch
dispatch:
	push.w {r4 - r11, lr}	/* レジスタを保存 */
	ldr r0, =runtsk			/* r0 を &runtsk に */
	ldr r1, [r0]			/* r1 を runtsk に */
	str sp, [r1, #TCB_sp]	/* runtsk->spにタスクスタックを保存 */
	ldr r2, =dispatch_r+1	/*　実行再開番地を取得 */
	str r2, [r1, #TCB_pc]	/* runtsk->pcに実行再開番地を保存 */

exit_and_dispatch:
dispatcher:
	/*
	 *  ここではスレッドモード・割込み禁止状態でなければならない．
	 */
	ldr r0, =runtsk			/* r0 を &runtsk に */
	ldr r2, =schedtsk
	ldr r1,[r2]				/* schedtsk を取り出す */
	str r1,[r0]				/* *runtsk = *schedtsk */
	tst r1,r1				
	beq dispatcher_1		/* runtsk があるか？ */
	ldr	sp,[r0,#TCB_sp]		/* runtsk->spからタスクスタックを復帰 */
	ldr pc,[r0,#TCB_pc]		/* runtsk->ｐｃから実行再開番地を復帰 */
	
dispatcher_1:
				/* スタックを MSP に切り替える */
	mrs		r3,control
	bic		r3,#02			/* CONTROL[1]でThread Mode時にMSPを使うようにする。 */
	msr		control,r3
	isb						/* controlの書き込み終了待ち　*/
	
	wfi						/* 割り込み待ち */
	/*
	 *  ここでMSPに切り換えるのは，ここで発生する割込み処理
	 *  にどのスタックを使うかという問題の解決と，割込みハンドラ内で
	 *  のタスクディスパッチの防止という2つの意味がある．
	 *
	 *  プロセッサを待ちモードに移行させる処理と，割込み許可とは，
	 *  不可分に行なう必要がある（CORTEX-M3 では WFI命令が
	 *  割り込み禁止中でも割り込み入力でSLEEPから抜け出すので
	 *  ので問題ない）．これを不可分に行なわない場合，割込みを許可
	 *  した直後に割込みが入り，その中でタスクが実行可能状態になる
	 *  と，実行すべきタスクがあるにもかかわらずプロセッサが待ちモー
	 *  ドになってしまう．
	 *
	 *  割込みを待つ間は，runtsk を NULL（=0）に設定しなければなら
	 *  ない．このように設定しないと，割込みハンドラから iget_tid 
	 *  を呼び出した際の動作が仕様に合致しなくなる．
	 */
	 			/* WFI を中断させた割り込みの受け付け */
	cpsie i				/* 割り込み許可 */
	nop					/*　ここで割り込みが発生する */
	cpsid i				/* 割り込み禁止 */
	 
	orr r3,#02				/* CONTROL[1]でThread Mode時にPSPを使うようにする。 */
	msr	control,r3
	isb						/* controlの書き込み終了待ち　*/
	 
	ldr r1, =reqflg
	ldr r2, [r1]			/* reqflg をロード　*/
	tst r2,r2				/* 0? */
	beq dispatcher_1		/* リクエストがないなら割り込みを待つ */
	mov r2,#0
	str r2, [r1]			/* reqflg を FALSE に */
	b dispatcher
	
dispatch_r:
			/* r0 には &runtskが入っている */
			/* r1 には runtskが入っている */
	pop.w {r4 - r11}				/* レジスタを復帰. lrは最後に復帰する */
	ldrb r2, [r1,#TCB_enatex]		/* runtsk->enatex からタスク例外状態を取得 */
	tst	r2, #(1<<TCB_enatex_bit)	/* enatexはセットされているか */
	beq dispatch_r_1				/* enatex が FALSE ならリターン */
	ldr r2, [r1,#TCB_texptn]		/* runtsk->texptn */
	tst r2,r2						/* texptn は 0 か  */
	beq dispatch_r_1				/* texptn が 0 ならリターン */
	ldr r1, =call_texrtn +1
	blx r1							/*   タスク例外処理ルーチンの呼出し */
dispatch_r_1:
	pop {pc }						/* lrを復帰して、その番地（dispatchを呼び出した番地）に戻る */


	
	
/*
 *  タスク起動時処理
 */
	.text
	.globl activate_r
activate_r:
	/*
	 *  タスク起動直後はタスク例外処理が禁止されているため，ここでタ
	 *  スク例外処理ルーチンを呼び出す条件は成り立たない．
	 *
	 *  このコードは、タスクスタックから必要な情報を取り出す。スタックに
	 *  情報を埋め込むのは、cpu_context.hの activate_context()である。
	 */
	 pop {r0,lr}				/* extinfと戻り番地 ( ext_tsk )を設定 */ 
	 cpsie i					/* タスクは起動直後にCPUアンロック状態になる */
	 pop {pc}					/* タスクの開始 */

/*
 *  割込みハンドラ／CPU例外ハンドラ出口処理
 *
 *  ret_int へは、ハンドラモード、MSP、割り込み許可状態で入ってくる。このときの、スタックの様子は
 *  以下のとおり
 *  [空] <- MSP (R13)
 *  
 *  [xPSR]    +28
 *  [ PC ]    +24
 *  [ LR ]    +20
 *  [ R12]    +16
 *  [ R3 ]    +12
 *  [ R2 ]    + 8
 *  [ R1 ]    + 4
 *  [ R0 ] <- PSP
 */
	.text
 	.syntax unified
	.globl ret_int
ret_int:
	cpsid i					/* CPUロック (割り込み禁止) */
	mrs r12,psp				/* PSPの値を取得 */
	ldr r3,[R12,#28]		/* xPSRの値を取得 */
	ldr r2,=ret_int_0+1		/* タスクモードに遷移するための再突入点を設定 */
	stmdb r12!,{r0-r3}		/* 偽の R12,LR,PC,xPSRを保存。PCとxPSR以外はでたらめでいい */
	stmdb r12!,{r0-r3}		/* 偽の r0,1,2,3,を保存。全部でたらめでいい */
	msr psp,r12				/* PSPに新しい値を設定 */

/*
　* ここでのスタック構成は以下のとおり
　*
 *  [空] <- PSP (R13)
 *  
 *  [xPSR]    +60
 *  [ PC ]    +56
 *  [ LR ]    +52
 *  [ R12]    +48
 *  [ R3 ]    +44
 *  [ R2 ]    +40
 *  [ R1 ]    +36
 *  [ R0 ] <- 古いPSP
 *  [xPSR]    +28
 *  [ PC ]    +24 : ret_int_0
 *  [ LR ]    +20
 *  [ R12]    +16
 *  [ R3 ]    +12
 *  [ R2 ]    + 8
 *  [ R1 ]    + 4
 *  [ R0 ] <- 新しいPSP
 *  
 * 古いPSPより下の領域は、タスクモードに遷移するための偽データである。
 */
	bx lr					/* 割り込みからの復帰。実は次の番地に進むだけ*/
ret_int_0:					/* Thread mode 割り込み禁止。 PSP */
/*
　* ここでのスタック構成は以下のとおり
　*
 *  [xPSR]    +28
 *  [ PC ]    +24
 *  [ LR ]    +20
 *  [ R12]    +16
 *  [ R3 ]    +12
 *  [ R2 ]    +8
 *  [ R1 ]    +4
 *  [ R0 ] <- PSP(R13)
 */
	ldr r0,=reqflg			/* &reqflg */
	ldr r1,[r0]				/* reqflgを取得 */
	tst r1,r1				/* reqflg == FLASE? */
	beq ret_int_2			/* FALSE->割り込みから帰る */
	mov r1,#0				/* TRUEだった */
	str r1,[r0]				/* reqflg = FLALSE */
	ldr r0,=runtsk			/* &runtsk */
	ldr r1,[r0]				/* r0 <- runtsk */
	ldr r2,=enadsp
	ldr r3,[r2]				/* enadspを取得 */
	tst r3,r3				/* enadsp　== FALSE? */
	beq	ret_int_1			/*     then ret_int_1 */
	ldr r2,=schedtsk
	ldr r3,[r2]				/* schedtsk */
	cmp r1,r3				/* runtsk == schedtsk ? */
	beq	ret_int_1			/*     then ret_int_1 */
							/* enadspがTRUEで、runtsk != schedtsk だった */
	ldr r0,=dispatch+1
	blx r0					/* dispatch() */
    b ret_int_2				/* 割り込みから戻る */
ret_int_1:					/* texの処理 */
	ldr r0,=runtsk					/* &runtsk */
	ldr r1,[r0]						/* runtsk */
	ldrb r2, [r1,#TCB_enatex]		/* runtsk->enatex からタスク例外状態を取得 */
	tst	r2, #(1<<TCB_enatex_bit)	/* enatexはセットされているか */
	beq ret_int_2					/* enatex が FALSE ならリターン */
	ldr r2, [r1,#TCB_texptn]		/* runtsk->texptn */
	tst r2,r2						/* texptn は 0 か  */
	beq ret_int_2					/* texptn が 0 ならリターン */
	ldr r1, =call_texrtn +1
	blx r1							/* call_texrtn() */

ret_int_2:					/* 割り込みから戻る。ただし、現在Thread Modeなので、EXC_RETRUNは使わない */
	ldr r1,[sp,#28]			/* xPSR */
	ldr r2,[sp,#24]			/* PC */
	ldr r3,[sp,#20]			/* LR */
	
	str r2,[sp,#28]         /* PC */
	str r3,[sp,#24]			/* LR */
	str r1,[sp,#20]			/* xPSR */
/*
　* ここでのスタック構成は以下のとおり
　*
 *  [ PC ]    +28
 *  [ LR ]    +24
 *  [xPSR]    +20
 *  [ R12]    +16
 *  [ R3 ]    +12
 *  [ R2 ]    +8
 *  [ R1 ]    +4
 *  [ R0 ] <- PSP (R13)
 */
	
	pop.w {r0-r3,r12,lr}	/* LRには旧xPSRが代入される */
	msr xpsr,lr				/* 旧xPSRを復帰 */
	pop {lr}				/* LRを復帰 */
	cpsie	i				/* CPUアンロック (割り込み許可) */
	pop {pc}				/* 戻り番地に飛ぶ */

/*
 *  微少時間待ち
 */
	.globl _sil_dly_nse
_sil_dly_nse:
	subs r0, #SIL_DLY_TIM1	/* D0 から SIL_DLY_TIM1 を引く */
	bgt _sil_dly_nse_1		/* 結果が 0 以下ならリターン */
	bx lr
_sil_dly_nse_1:
	subs r0, #SIL_DLY_TIM2	/* D0 から SIL_DLY_TIM2 を引く */
	bgt _sil_dly_nse_1		/* 結果が 0 より大きければループ */
	bx lr
