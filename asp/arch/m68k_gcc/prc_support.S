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
 *  @(#) $Id: prc_support.S 759 2008-03-07 23:01:20Z hiro $
 */

/*
 *		プロセッサ依存モジュール アセンブリ言語部（M68040用）
 */

#define	TOPPERS_MACRO_ONLY
#define UINT_C(val)			(val)		/* uint_t型の定数を作るマクロ */
#define ULONG_C(val)		(val)		/* ulong_t型の定数を作るマクロ */
#define CAST(type, val)		(val)		/* 型キャストを行うマクロ */
#include "kernel_impl.h"
#include "offset.h"

/*
 *  タスクディスパッチャ
 */
	.text
	.globl dispatch
dispatch:
	/*
	 *  このルーチンは，タスクコンテキスト・CPUロック状態・ディスパッチ
	 *  許可状態・（モデル上の）割込み優先度マスク全解除状態で呼び出さ
	 *  れる．
	 */
	movem.l %d2-%d7/%a2-%a6, -(%sp)		/* レジスタを保存 */
	move.l p_runtsk, %a0				/* p_runtskをA0に */
	move.l %sp, TCB_msp(%a0)			/* タスクスタックを保存 */
	move.l #dispatch_r, TCB_pc(%a0)		/* 実行再開番地を保存 */
	jbra dispatcher

dispatch_r:
	movem.l (%sp)+, %d2-%d7/%a2-%a6		/* レジスタを復帰 */
	btst.b #TCB_enatex_bit, TCB_enatex(%a0)
	jbeq dispatch_r_1					/* enatexがfalseならリターン */
	tst.l TCB_texptn(%a0)				/* texptnが0でなければ             */
	jbne call_texrtn					/*  タスク例外処理ルーチンの呼出し */
dispatch_r_1:
	rts

/*
 *  ディスパッチャの動作開始（prc_support.S）
 */
	.globl start_dispatch
start_dispatch:
	/*
	 *  このルーチンは，カーネル起動時に，すべての割込みを禁止した状態
	 * （割込みロック状態と同等）で呼び出される．また，割込みモード（非
	 *  タスクコンテキストと同等）で呼び出されることを想定している．
	 *
	 *  prc_initializeで，lock_flagをtrueに，saved_iipmをIIPM_ENAALLに
	 *  初期化しているため，カーネル管理外の割込みを許可することで，
	 *  CPUロック状態・（モデル上の）割込み優先度マスク全解除状態になる．
	 *  また，task_initializeでdisdspをfalseに初期化しているため，ディ
	 *  スパッチ許可状態になっている．
	 */
#if TIPM_LOCK == -7
	or.w #0x1000, %sr					/* マスタモードに */
#else /* TIPM_LOCK == -7 */
	move.w %sr, %d0						/* マスタモード・                */
	and.w #~0x0700, %d0					/*  カーネル管理外の割込みを許可 */
	or.w #(0x1000 | IIPM_LOCK), %d0
	move.w %d0, %sr
#endif /* TIPM_LOCK == -7 */
	jbra dispatcher_0

/*
 *  現在のコンテキストを捨ててディスパッチ
 */
	.globl exit_and_dispatch
exit_and_dispatch:
	/* ディスパッチャ本体（dispatcher）へ */

/*
 *  ディスパッチャ本体
 */
dispatcher:
	/*
	 *  このルーチンは，タスクコンテキスト・CPUロック状態・ディスパッチ
	 *  許可状態・（モデル上の）割込み優先度マスク全解除状態で呼び出さ
	 *  れる．
	 *
	 *  すなわち，マスタモード・lock_flagがtrue・disdspがfalse・dspflg
	 *  がtrue・saved_iipmがIIPM_ENAALLとなっている．実行再開番地へもこ
	 *  の状態のまま分岐する．
	 */
#ifdef LOG_DSP_ENTER
	move.l p_runtsk, %d0				/* p_runtskをパラメータに */
	move.l %d0, -(%sp)
	jsr log_dsp_enter
	addq.l #4, %sp
#endif /* LOG_DSP_ENTER */
dispatcher_0:
	move.l p_schedtsk, %a0				/* p_schedtskをp_runtskに */
	move.l %a0, p_runtsk
	jbeq dispatcher_1					/* p_runtskがNULLならdispatcher_1へ */
	move.l TCB_msp(%a0), %sp			/* タスクスタックを復帰 */
#ifdef LOG_DSP_LEAVE
	move.l %a0, -(%sp)					/* p_runtskをパラメータに */
	jsr log_dsp_leave
	addq.l #4, %sp
	move.l p_runtsk, %a0
#endif /* LOG_DSP_LEAVE */
	move.l TCB_pc(%a0), %a1				/* 実行再開番地へ分岐 */
	jmp (%a1)
dispatcher_1:
	/*
	 *  CPUロック状態を解除する準備をする．
	 */
	move.w %sr, %d0						/* SRをD0に保存 */
	clr.l lock_flag						/* CPUロック解除状態に */
dispatcher_2:
	/*
	 *  割込みを許可し，割込みモードに切り換えて，割込みを待つ．
	 *
	 *  ここで割込みモードに切り換えるのは，ここで発生する割込み処理に
	 *  どのスタックを使うかという問題の解決と，割込みハンドラ内でのタ
	 *  スクディスパッチの防止という2つの意味がある．
	 *
	 *  プロセッサを割込み待ちに移行させる処理と，割込み許可とは，不可
	 *  分に行なう必要がある（M68040ではstop命令で両方行なうので問題な
	 *  い）．これを不可分に行なわない場合，割込みを許可した直後に割込
	 *  みが入り，その中でタスクが実行可能状態になると，実行すべきタス
	 *  クがあるにもかかわらずプロセッサが割込み待ちになってしまう．
	 *
	 *  割込み待ちの間は，p_runtskをNULL（＝0）に設定しなければならな
	 *  い．このように設定しないと，割込みハンドラからiget_tidを呼び出
	 *  した際の動作が仕様に合致しなくなる．
	 */
	stop #0x2000						/* 割込み待ち */
	move.w %d0, %sr						/* 元の状態に戻す */
	tst.l reqflg						/* reqflgがfalseならdispatcher_2へ */
	jbeq dispatcher_2
	clr.l reqflg						/* reqflgをfalseに */
	/*
	 *  CPUロック状態に戻す．割込み待ちの間に実行した割込みハンドラによ
	 *  り，saved_iipmが書き換えられる可能性があるため，元の値に戻す必
	 *  要がある．dispatcherが実行される時は，saved_iipmがIIPM_ENAALL
	 *  となっているため，ここではsaved_iipmをIIPM_ENAALL（＝0）に戻せ
	 *  ばよい．
	 */
	clr.w saved_iipm					/* saved_iipmを0にする */
	move.l #true, lock_flag				/* CPUロック状態に */
	jbra dispatcher_0

/*
 *  カーネルの終了処理の呼出し
 *
 *  M68040では，モード切換えによりスタックも切り換わるため，明示的なス
 *  タック切換えは必要ない．最初から割込みモードであった場合も，同じ処
 *  理でよい．
 */
	.globl call_exit_kernel
call_exit_kernel:
	and.w #~0x1000, %sr					/* 割込みモードに */
	jmp exit_kernel						/* カーネルの終了処理を呼ぶ */
	
/*
 *  タスク開始時処理
 */
	.text
	.globl start_r
start_r:
	clr.l lock_flag						/* CPUロック解除状態に */
	and.w #~0x0700, %sr
	move.l TCB_p_tinib(%a0), %a1		/* p_runtsk->p_tinibをA1に */
	move.l TINIB_exinf(%a1), -(%sp)		/* exinfをスタックに積む */
	move.l #ext_tsk, -(%sp)				/* ext_tskをスタックに積む */
	move.l TINIB_task(%a1), %a0			/* タスクの起動番地をA0に */
	jmp (%a0)

/*
 *  割込みハンドラ出口処理
 *
 *  ret_intは，割込みハンドラから戻った直後に実行するルーチンで，
 *  INTHDR_ENTRYマクロで展開する割込みハンドラの入口処理で，割込みハン
 *  ドラからの戻り番地に設定される．
 */
	.text
	.globl ret_int
ret_int:
	btst.b #4, 16(%sp)					/* 戻り先が割込みモードなら */
	jbne ret_int_1						/*           すぐにリターン */
	/*
	 *  カーネル管理の割込みを禁止する．この時点では，CPUロック状態に
	 *  はならない（lock_flagとsaved_iipmは更新しない）．
	 *
	 *  reqflgをチェックする前に割込みを禁止するのは，reqflgをチェック
	 *  した直後に割込みハンドラが起動され，その中でディスパッチが要求
	 *  された場合に，すぐにディスパッチされないという問題が生じるため
	 *  である．
	 */
#if TIPM_LOCK == -7
	or.w #0x0700, %sr					/* すべての割込みを禁止 */
#else /* TIPM_LOCK == -7 */
	/*
	 *  このルーチンはカーネル管理の割込みから起動されるため，ここでは，
	 *  割込み優先度マスクがTIPM_LOCKよりも低いと想定できる．
	 */
	move.w %sr, %d0						/* カーネル管理の割込みを禁止 */
	and.w #~0x0700, %d0
	or.w #IIPM_LOCK, %d0
	move.w %d0, %sr
#endif /* TIPM_LOCK == -7 */
	tst.l reqflg						/* reqflgがtrueであればret_int_2へ */
	jbne ret_int_2
ret_int_1:
	/*
	 *  割込み処理からのリターンにより，CPUロック解除状態に移行するよう
	 *  準備する．割込み優先度マスクは，RTE命令により元の値に戻るため，
	 *  lock_flagをfalseにしておけばよい（lock_flagをfalseにするのは，
	 *  CPUロック状態のまま割込みハンドラから戻った時の対策）．
	 */
	clr.l lock_flag						/* CPUロック解除の準備 */
	movem.l (%sp)+, %d0-%d1/%a0-%a1		/* スクラッチレジスタを復帰 */
	rte

ret_int_2:
	movem.l (%sp)+, %d0-%d1/%a0-%a1		/* スクラッチレジスタを復帰 */
	addq.l #8, %sp						/* スローアウェイフレームを捨てる */
	or.w #0x1000, %sr					/* マスタモードに（スタック切換え）*/
	movem.l %d0-%d1/%a0-%a1, -(%sp)		/* スクラッチレジスタを保存 */
ret_int_3:
	/*
	 *  ここへは，CPU例外ハンドラの出口処理からも分岐してくる．
	 *
	 *  ここでは，戻り先がタスクであり，スタックは，例外スタックフレー
	 *  ムの上にスクラッチレジスタのみが保存された状態になっている．ま
	 *  た，プロセッサは，マスタモード・カーネル管理の割込みを禁止した
	 *  状態となっている．
	 */
	clr.l reqflg						/* reqflgをfalseに */
	/*
	 *  CPUロック状態に移行する．カーネル管理の割込みはすでに禁止して
	 *  いるので，lock_flagとsaved_iipmを更新する．saved_iipmは，戻り
	 *  先の割込み優先度マスク（の内部表現）に設定する．
	 *
	 *  この時点でCPUロック状態とするのは，dispatcherへ分岐する時と，
	 *  call_texrtnを呼び出す時に，CPUロック状態になっている必要がある
	 *  ためである．
	 */
	move.w 16(%sp), %d0					/* 戻り先のSRをD0に */
	and.w #0x0700, %d0					/* IPMを取り出してsaved_iipmに */
	move.w %d0, saved_iipm
	move.l #true, lock_flag				/* lock_flagをtrueに */
	/*
	 *  dspflgがfalseである場合と，p_runtskとp_schedtskが同じ場合には，
	 *  ディスパッチを行わない．このチェックが必要なのは，タスク例外処
	 *  理ルーチンの呼出しが必要な場合に，ディスパッチが必要なくても，
	 *  reqflgをtrueにするためである．
	 */
	move.l p_runtsk, %a0				/* p_runtskをA0に */
	tst.l dspflg						/* dspflgがfalseならret_int_4へ */
	jbeq ret_int_4
	cmp.l p_schedtsk, %a0				/* p_runtskとp_schedtskが同じなら */
	jbeq ret_int_4						/*                    ret_int_4へ */
	movem.l %d2-%d7/%a2-%a6, -(%sp)		/* 残りのレジスタを保存 */
	move.l %sp, TCB_msp(%a0)			/* タスクスタックを保存 */
	move.l #ret_int_r, TCB_pc(%a0)		/* 実行再開番地を保存 */
	jbra dispatcher

ret_int_r:
	movem.l (%sp)+, %d2-%d7/%a2-%a6		/* レジスタを復帰 */
ret_int_4:
	/*
	 *  enatexがtrueで，texptnが0でなければ，タスク例外処理ルーチンを
	 *  呼び出す．
	 */
	btst.b #TCB_enatex_bit, TCB_enatex(%a0)
	jbeq ret_int_5						/* enatexがfalseならret_int_5へ */
	tst.l TCB_texptn(%a0)				/* texptnが0ならret_int_5へ */
	jbeq ret_int_5
	jsr call_texrtn						/* タスク例外処理ルーチンの呼出し */
ret_int_5:
	/*
	 *  割込み処理からのリターンにより，CPUロック解除状態に移行するよ
	 *  う準備する．割込み優先度マスクは，RTE命令により元の値に戻るた
	 *  め，lock_flagをfalseにしておけばよい．
	 */
	clr.l lock_flag						/* CPUロック解除の準備 */
	movem.l (%sp)+, %d0-%d1/%a0-%a1		/* スクラッチレジスタを復帰 */
	rte

/*
 *  CPU例外ハンドラ出口処理
 *
 *  ret_excは，CPU例外ハンドラから戻った直後に実行するルーチンで，
 *  EXCHDR_ENTRYマクロで展開するCPU例外ハンドラの入口処理で，CPU例外ハ
 *  ンドラからの戻り番地に設定される．
 */
	.text
	.globl ret_exc
ret_exc:
	addq.l #4, %sp						/* スタック上の引数を捨てる */
	move.l (%sp)+, %d0					/* lock_flagを元に戻す */
	move.l %d0, lock_flag
	move.l (%sp)+, %d0					/* 元のSRをD0に */
	and.w #0x1000, %d0					/* 元が割込みモードなら */
	jbeq ret_exc_2						/*       すぐにリターン */
	/*
	 *  カーネル管理の割込みを禁止し，マスタモードに戻す．この時点では，
	 *  CPUロック状態にはならない（lock_flagとsaved_iipmは更新しない）．
	 *
	 *  reqflgをチェックする前に割込みを禁止するのは，reqflgをチェック
	 *  した直後に割込みハンドラが起動され，その中でディスパッチが要求
	 *  された場合に，すぐにディスパッチされないという問題が生じるため
	 *  である．
	 */
#if TIPM_LOCK == -7
	or.w #0x1700, %sr					/* マスタモード・全割込み禁止 */
#else /* TIPM_LOCK == -7 */
	/*
	 *  CPU例外は任意の状態で発生するため，ここでは，IPMがTIPM_LOCKより
	 *  も低いと想定することができない．
	 */
	move.w %sr, %d0						/* 現在のIPM（内部表現）を取り出す */
	and.w #0x0700, %d0
	cmp.w #LOCK_IIPM, %d0				/* 現在のIPMがTIPM_LOCKと同じか   */
	jbge ret_exc_1						/*    それより高いならret_exc_1へ */
	move.w %sr, %d0						/* カーネル管理の割込みを禁止 */
	and.w #~0x0700, %d0
	or.w #LOCK_IIPM, %d0
	move.w %d0, %sr
ret_exc_1:
	or.w #0x1000, %sr					/* マスタモード */
#endif /* TIPM_LOCK == -7 */
	/*
	 *  CPUロック状態でCPU例外が発生した場合，reqflgがtrueになることは
	 *  ないので，CPUロック状態の場合はret_int_3へは分岐しない．
	 */
	tst.l reqflg						/* reqflgがtrueであればret_int_3へ */
	jbne ret_int_3
ret_exc_2:
	movem.l (%sp)+, %d0-%d1/%a0-%a1		/* スクラッチレジスタを復帰 */
	rte

/*
 *  微少時間待ち（本来はSILのターゲット依存部）
 */
	.globl _sil_dly_nse
_sil_dly_nse:
	subi.l #SIL_DLY_TIM1, %d0			/* D0からSIL_DLY_TIM1を引く */
	jbhi _sil_dly_nse_1					/* 結果が0以下ならリターン */
	rts
_sil_dly_nse_1:
	subi.l #SIL_DLY_TIM2, %d0			/* D0からSIL_DLY_TIM2を引く */
	jbhi _sil_dly_nse_1					/* 結果が0より大きければループ */
	rts
