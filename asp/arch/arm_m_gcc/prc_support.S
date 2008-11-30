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
 *  @(#) $Id: prc_support.S 1365 2008-09-28 07:23:15Z futl-takaki $
 */

/*
 *  プロセッサ依存モジュール アセンブリ言語部（ARM-M用）
 */

#define TOPPERS_MACRO_ONLY
#define UINT_C(val)		(val)		/* uint_t型の定数を作るマクロ */
#define ULONG_C(val)	(val)		/* ulong_t型の定数を作るマクロ */
#define CAST(type, val)	(val)		/* 型キャストを行うマクロ */

#include "kernel_impl.h"
#include "arm_m.h"
#include "offset.h"


/*
 *  タスクディスパッチャ
 */
	.text
	.syntax unified
	.code 16
	.global dispatch
	.type dispatch, function
dispatch:
	/*
	 *
	 *  このルーチンは，タスクコンテキスト・CPUロック状態・ディパッチ許可状態
	 *  ・（モデル上の）割込み優先度マスク全開状態で呼び出される．
	 */
	stmfd sp!,{r4-r11,lr}         /* レジスタの保存 */
	ldr   r0, =p_runtsk           /* p_runtskを読み込む */
	ldr   r1, [r0]
	str   sp, [r1,#TCB_sp]        /* タスクスタックを保存 */
	ldr   lr, =dispatch_r         /* 実行再開番地を保存 */
	str   lr, [r1,#TCB_pc]        
	b     dispatcher

	.text
	.syntax unified
	.code 16
	.type dispatch_r, function
dispatch_r:
	ldmfd sp!,{r4 - r11,lr}       /* レジスタの復帰 */
	/*
	 * タスク例外処理ルーチンの起動
	 * dispatcherから呼び出されるため，TCBのアドレスはr1に入っている
	 */
	ldrb  r0,[r1,#TCB_enatex]
	tst   r0,#TCB_enatex_mask
	beq   dispatch_r_1            /* enatex が false ならリターン */
	ldr   r0,[r1,#TCB_texptn]     /* texptn が0でなければ         */
	tst   r0,r0                 
	bne   call_texrtn             /* タスク例外ルーチンの呼び出し */
dispatch_r_1:                     /* タスクへのcall_textnから戻る */
	mov   pc,lr


/*
 *  CPU例外エントリ
 *
 *  割込みエントリと処理の内容は同等だが，ログの種類が異なるため，
 *  分けている．
 */
	.align 2
	.syntax unified
	.code 16
	.global exc_entry
	.type exc_entry, function
exc_entry:
	/*
	 *  例外/割込みが発生すると，発生時にアクティブなスタックにスクラ
	 *  ッチレジスタ等が保存される．
	 *  この内容に加えて，CPU例外ハンドラへの情報として，basepri の値と，
	 *  EXC_RETURNの情報を加えて保存する．basepriの値は，CPU例外からの
	 *  リターン時に割込み優先度マスクの値を元に戻すためにも用いられる．
	 *
	 *   -----------
	 *  | EXC_RETURN|  
	 *   -----------
	 *  |  basepri  |  
	 *   -----------
	 *  |    R0     |  
	 *   -----------
	 *  |    R1     |
	 *   -----------
	 *  |    R2     |
	 *   -----------
	 *  |    R3     |
	 *   -----------
	 *  |    R12    |
	 *   -----------
	 *  |    LR     |
	 *   -----------
	 *  |    PC     |
	 *   -----------
	 *  |   xPSR    |
	 *   -----------
	 *
	 */

	/*
	 *  割込み発生時の割込み優先度マスクをスタックに保存するため取得
	 */
	mrs   r2, basepri             /* baepriの値を取得 */

	/*
	 * 多重割込みかチェック
	 * EXC_RETURN（割込み時にLRに設定される値）をチェックして，例外発生時に
	 * アクティブなスタックを特定することで多重割込みか判定する．
	 */
	tst   lr, #EXC_RETURN_PSP    /* 割込み元がMSPなら多重割込み */
	beq   exc_entry_1            /* 多重割込みならexc_entry_1へ */
	mrs   r0, psp                /* 一段目の割込みの場合はPSP上に */
	stmfd r0!,{r2}               /* 割込み発生時の割込み優先度マスクを積む */
	stmfd r0!,{lr}               /* EXC_RETURN を積む             */
	msr   psp, r0                /* CPU例外ハンドラへの引数となる */
	push  {lr}                   /* MSP上にもEXC_RETURN を積む    */ 
	b     exc_entry_2
exc_entry_1:                     /* 多重割込みの場合 */
	push  {r2}                   /* 割込み発生時の割込み優先度マスクを積む */
	push  {lr}                   /* EXC_RETURN を積む             */ 
	mov   r0, sp                 /* CPU例外ハンドラへの引数となる */

	/*
	 *  共通処理
	 */
exc_entry_2:                     
	mrs   r3, ipsr               /* ハンドラアドレスを取得 */
	ldr   r1, =_kernel_exc_tbl
	ldr   r2, [r1, r3, lsl #2]

#ifdef LOG_EXC_ENTER
	push  {r0,r2,r3}
	mov   r0, r3                 /* 例外番号をパラメータに  */
	bl    log_exc_enter          /* log_exc_enterを呼び出す */
	pop   {r0,r2,r3}
	push  {r3}                   /* 例外番号をスタックへ    */
#endif /* LOG_EXC_ENTER */

	/*
	 *  CPU例外ハンドラの呼び出し
	 */
	blx   r2

#ifdef LOG_EXC_ENTER
	pop   {r0}                   /* 例外番号を引数に        */
	bl    log_exc_leave          /* log_exc_leaveを呼び出す */
#endif /* LOG_EXC_ENTER */

	b     ret_exc


/*
 *  割込みエントリ
 */
	.align 2
	.syntax unified
	.code 16
	.global int_entry
	.type int_entry, function
int_entry:
	/*
	 *  割込み発生時の割込み優先度マスクをスタックに保存するため取得
	 */
	mrs   r2, basepri             /* baepriの値を取得 */

	/*
	 * 多重割込みかチェック
	 * EXC_RETURN（割込み時にLRに設定される値）をチェックして，例外発生時に
	 * アクティブなスタックを特定することで多重割込みか判定する．
	 */
	tst   lr, #EXC_RETURN_PSP    /* 割込み元がMSPなら多重割込み */
	beq   int_entry_1            /* 多重割込みならint_entry_1へ    */
	mrs   r0, psp                /* 一段目の割込みの場合はPSP上に */
	stmfd r0!,{r2}               /* 割込み発生時の割込み優先度マスクを積む */
	stmfd r0!,{lr}               /* EXC_RETURN を積む             */
	msr   psp, r0                /* CPU例外ハンドラへの引数となる */
	push  {lr}                   /* MSP上にもEXC_RETURN を積む    */ 
	b     int_entry_2
int_entry_1:                     /* 多重割込みの場合 */
	push  {r2}                   /* 割込み発生時の割込み優先度マスクを積む */
	push  {lr}                   /* EXC_RETURN を積む             */ 
	mov   r0, sp                 /* 未定義の割込みが発生した場合の情報とする */

	/*
	 *  共通処理
	 */
int_entry_2:                     
	mrs   r3, ipsr               /* ハンドラアドレスを取得 */
	ldr   r1, =_kernel_exc_tbl
	ldr   r2, [r1, r3, lsl #2]

#ifdef LOG_EXC_ENTER
	push  {r0,r2,r3}
	mov   r0, r3                 /* 例外番号をパラメータに  */
	bl    log_inh_enter          /* log_exc_enterを呼び出す */
	pop   {r0,r2,r3}
	push  {r3}                   /* 例外番号をスタックへ    */
#endif /* LOG_EXC_ENTER */

	/*
	 *  割込みハンドラの呼び出し
	 */
	blx   r2

#ifdef LOG_EXC_ENTER
	pop   {r0}                   /* 例外番号を引数に        */
	bl    log_exc_leave          /* log_exc_leaveを呼び出す */
#endif /* LOG_EXC_ENTER */



/*
 *  割込み/例外出口
 *
 *  ret_exc/ret_intは，CPU例外/割込みハンドラから戻った直後に実行する
 *  ルーチンである．
 */
ret_exc:
ret_int:
	/*
	 *  割込みロック状態とする．この時点では，CPUロック状態にはならない
	 * （basepriとlock_flagとsaved_iipmは更新しない）．
	 *
	 *  割込みロック状態とするのは，戻り先のコンテキストのチェックと，
	 *  戻り先が非タスクコンテキストであった場合のリターンをアトミック
	 *  に行うためである．bsepriをCPUロックの値にすることでもアトミッ
	 *  クなチェックと復帰は可能であるが，割込みからリターンしても，
	 *  basepri の設定内容は元に戻らないため，使用することができない． 
	 *  一方，FAULTMASKは，割込みからのリターン処理によって，'0'にクリ
	 *  アされる．
	 */
	cpsid f                        

	/*
	 *  戻り先のコンテキストの判定
	 * 
	 *  割込みハンドラ実行にLRにセットされるEXC_RETURNをチェックして，戻り
	 *  先でMSPが使われていれば，割込み先が非タスクコンテキストと判定する．
	 */
	pop   {r3}                     /* lrをスタックから取得         */
	tst   r3, #EXC_RETURN_PSP      /* 戻り先がPSPなら ret_int_1 へ */
	bne   ret_int_1
	pop   {r1}                     /* 元の割込み優先度マスク(basepri)をr1へ */
	b     ret_int_2                /* の値をMSPから取得 */

	/*
	 *  一段目の割込みの出口処理
	 */
ret_int_1:
	/*
	 *  PSP上からEXC_RETURNを削除
	 */
	mrs   r2, psp                 
	add   r2, r2, #4
	msr   psp, r2                 

	/*
	 *  reqflgをチェックする
	 * 
	 *  カーネル管理内の割込みは禁止した状態で実行する必要があるため，
	 *  FAULTMASKを'1'にした状態で実行する．
	 *  reqflgをチェックする前に割込みを禁止するのは，reqflgをチェック
	 *  した直後に割込みハンドラが起動され，その中でディスパッチが要求
	 *  された場合に，すぐにディスパッチされないという問題が生じるため
	 *  である．
	 */
	ldr   r0, =reqflg             /* reqflgがfalseならそのまま戻る */
	ldr   r1, [r0]
	cbnz  r1, ret_int_3           /* trueならret_int_3へ           */
	mrs   r2, psp                 /* 元の割込み優先度マスク(basepri) */
	ldmfd r2!, {r1}               /* の値をPSPから取得 */
	msr   psp, r2                 

ret_int_2:
	/*
	 *  ここには割込みロック状態（FAULTMASKがセット）された状態で来る．
	 *  Threadモードからのリターンにより自動的に割込みロック解除状態になる．
	 *  割込み優先度マスクは割込み前に状態に戻す．
	 */ 
	msr   basepri, r1             /* 割込み優先度マスクを割込み前に状態へ */
	bx    r3                      /* リターン */


ret_int_3:
	/*
	 *  ここでは，戻り先がタスクであり，PSP上にスクラッチレジスタと割
	 *  込み優先度マスク(basepri)が保存された状態になっている．また，
	 *  プロセッサは，Handlerモード・割込みロック状態となっている．
	 *  また，r0には，reqflgのアドレス，r3には割込み受付時のlrの値が保
	 *  持されている．
	 */
	mov   r1, #0                   /* reqflgをfalseに */
	str   r1, [r0]

	/*
	 *  CPUロック状態に移行する．
	 *
	 *  カーネルの管理内の割込みを禁止するようにbasepriを設定し，
	 *  lock_flag と saved_iipm を更新する．saved_iipmは，戻り先の割込み
	 *  優先度マスク（の内部表現）に設定する．
	 *  この時点でCPUロック状態とするのは，dispatcherへ分岐する時と，
	 *  call_texrtnを呼び出す時に，CPUロック状態になっている必要がある
	 *  ためである．
     *  なお，この処理の後，Threadモードへの移行処理を行なうため，割込み
     *  ロック状態(FAULTMASKを"1")は保持する．
	 */
	ldr   r1, =IIPM_LOCK          /* CPUロック状態 */ 
	msr   basepri, r1          
	mov   r1, #0x01               /* lock_flag を trueに */
	ldr   r0, =lock_flag          
	str   r1, [r0]             
	mrs   r2, psp                 /* 割込み前の割込み優先度マスクを */
	ldr   r1, [r2]                /* タスクスタックから取得         */
	ldr   r0, =saved_iipm         /* saved_iipmに保存 */
	str   r1, [r0]             

	/*
	 *  Threadモードへ移行する．
	 *
	 *  dispatcherやcall_texrnを呼び出す場合は，Threadモードである必
	 *  要があるため，PSPスタック上にダミーの例外フレームを置いて，
	 *  擬似的に割込みハンドラからリターンする．
	 *  リターンと同時にFAULTMASKが自動的にクリアされ，カーネル管理外の
	 *  割込みが許可される．
	 */
	ldr   r0, =ret_int_4          /* PC   */
	ldr   r1, =EPSR_T             /* xPSR(Tビットが'1'である必要がある) */
	stmfd r2!, {r0-r1}            /* ダミーフレームをスタック上に積む   */
	sub   r2, #(EXC_FRAME_SIZE - (4*2)) /* r0-r3,r12,lrの内容は設定する必要がない */
	msr   psp,r2                  
	bx    r3                      /* Threadモードへ移行 */
    
ret_int_4:
	/*
	 *  上記の処理により，Threadモードで実行される．
	 *  dspflgがfalseである場合と，p_runtskとp_schedtskが同じ場合には，
	 *  ディスパッチを行わない．このチェックが必要なのは，タスク例外処
	 *  理ルーチンの呼出しが必要な場合に，ディスパッチが必要なくても，
	 *  reqflgをtrueにするためである．
	 */
	ldr   r0, =p_runtsk       /* ディスパッチを行わない場合でも，r1にp_runtsk の値(TCB) */
	ldr   r1, [r0]            /* が入っている必要があるので，先に読み込む */
	ldr   r0, =dspflg         
	ldr   r2, [r0]
	cbz   r2, ret_int_r_1     /* dspflgがfalseならret_int_r_1へ */
	ldr   r0, =p_schedtsk     
	ldr   r2, [r0]
	cmp   r1, r2              /* p_runtskとp_schedtskが同じなら */
	beq   ret_int_r_1         /*                  ret_int_r_1へ */
	stmfd sp!, {r4-r11}       /* 残りのレジスタを保存 */
	str   sp, [r1,#TCB_sp]    /* タスクスタックを保存 */
	ldr   lr, =ret_int_r      /* 実行再開番地を保存   */
	str   lr, [r1,#TCB_pc]
	b     dispatcher          /* ディスパッチャへ */

/*
 * 割込みによりプリエンプトされたタスクへのリターン処理
 *
 * Threadモードで，ディスパッチャや割込みの出口処理から呼び出される．
 * 割込みによりプリエンプトされたタスクへリターンするには，いったん
 * Handlerモードに移行し，PCに0xfffffffdを代入してリターンする必要
 * がある．そのため，SVCにより，SVCハンドラを呼び出し，Handlerモー
 * ドへ移行する．
 */
	.text
	.syntax unified
	.code 16
	.type ret_int_r, function
ret_int_r:
	pop {r4-r11}                  /* レジスタの復帰 */
ret_int_r_1:
	/*
	 *  enatexがtrueで，texptnが0でなければ，タスク例外処理ルーチンを
	 *  呼び出す．
	 *  dispatcherから呼び出されるため，TCBのアドレスはr1に入っている
	 */
	ldrb  r0, [r1,#TCB_enatex]
	tst   r0, #TCB_enatex_mask
	beq   ret_int_r_2           /* enatex が false なら ret_int_r_2へ */
	ldr   r0, [r1,#TCB_texptn]  /* texptnをロード                     */
	cbz   r0, ret_int_r_2       /* '0'ならリターン */
	bl    call_texrtn           /* タスク例外ルーチンの呼び出し */
ret_int_r_2:
	svc   0                     /* SVCの呼び出し */

/*
 *  SVCハンドラ
 */
	.text
	.syntax unified
	.thumb
	.thumb_func
	.global svc_handler
	.type svc_handler, function
svc_handler:
	/*
	 *  割込み処理からのリターンにより，CPUロック解除状態に移行するよ
	 *  う準備する．
	 */
	cpsid f                       /* 割込みロック状態へ */
	mrs   r0, psp
	add   r0, #EXC_FRAME_SIZE     /* スタックを捨てる   */
	msr   psp, r0
	mov   r0, #0
	ldr   r1, =lock_flag          /* CPUロック解除状態へ */
	str   r0, [r1]
	mrs   r0, psp                 /* 割込み優先度マスクをタスクスタック */
	ldmfd r0!, {r1}               /* から取得                           */
	msr   psp, r0
	msr   basepri, r1             /* 割込み優先度マスクを設定           */
	bx    lr                      /* リターン     */

/*
 *  ディスパッチャの動作開始
 */
	.align	2
	.thumb
	.thumb_func
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
	ldr   r0,=istkpt              /* MSPを初期化   */
	ldr   r1,[r0]                 /* start_dispatch呼び出し時に呼び出し用に */
	msr   msp, r1                 /* 使用しているため初期化する             */
	ldr   r1, =IIPM_LOCK          /* カーネル管理内の割込みを禁止 */
	msr   basepri, r1 
	cpsie f                       /* カーネル管理外の割込みを許可 */
	mov   r0, #CONTROL_PSP        /* PSPを有効に  */
	msr   control, r0
	isb                           /* control の操作後に必要 */

/*
 *  現在のコンテキストを捨ててディスパッチ
 */
	.align	2
	.thumb
	.thumb_func
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
	 *  すなわち，Threadモード・lock_flagがtrue・disdspがfalse・dspflg
	 *  がtrue・saved_iipmがIIPM_ENAALLとなっている．実行再開番地へもこ
	 *  の状態のまま分岐する．
	 */
#ifdef LOG_DSP_ENTER
	ldr   r1, =p_runtsk     /* p_runtskをパラメータに */
	ldr   r0, [r1]        
	bl    log_dsp_enter
#endif /* LOG_DSP_ENTER */
dispatcher_0:
	ldr   r0, =p_schedtsk   /* p_schedtskをp_runtskに */
	ldr   r1, [r0]
	ldr   r2, =p_runtsk   
	str   r1, [r2]        
	cmp   r1, #0            /* p_runtskがNULLならdispatcher_1へ */
	beq   dispatcher_1             
	ldr   sp, [r1,#TCB_sp]  /* タスクスタックを復帰 */
#ifdef LOG_DSP_LEAVE
	mov   r0, r1            /* p_runtskをパラメータに */
	mov   r4, r1            /* r1はスクラッチレジスタなので保存 */
	bl    log_dsp_leave
	mov   r1, r4
#endif /* LOG_DSP_LEAVE */
	ldr   pc, [r1,#TCB_pc]  /* 実行再開番地を復帰   */    
dispatcher_1:
	/*
	 * CPUロック状態の解除と，非タスクコンテキスト実行状態への
	 * 準備をする
	 */
	mov   r0, #CONTROL_MSP  /* MSPを有効に  */
	msr   control, r0       
	isb                     /* control の操作後に必要 */
	ldr   r2, =reqflg       /* r2 <- reqflg */
	ldr   r1, =IIPM_LOCK    /* 割込みロック状態の割込み優先度マスクの値 */
	mov   r0, #0
	ldr   r4, =lock_flag    /* CPUロック解除状態へ */
	str   r0, [r4]
dispatcher_2:
	/*
	 *  割込みを許可し，非タスクコンテキスト実行状態とし割込みを待つ．
	 *
	 *  ここで非タスクコンテキスト実行状態に切り換えるのは，ここで発生
	 *  する割込み処理にどのスタックを使うかという問題の解決と，割込み
	 *  ハンドラ内でのタスクディスパッチの防止という2つの意味がある．
	 *
	 *  プロセッサを割込み待ちに移行させる処理と，割込み許可とは，不可
	 *  分に行なう必要がある．
	 *  これを不可分に行なわない場合，割込みを許可した直後に割込
	 *  みが入り，その中でタスクが実行可能状態になると，実行すべきタス
	 *  クがあるにもかかわらずプロセッサが割込み待ちになってしまう．
	 *  ARM-Mでは，PRIMASKをセットした状態でWFIを呼び出すことで実現できる．
	 *  この状態で割込みが入ると，割込みは実行されず，WFIからリターンす
	 *  ることになるので，一旦割込みを許可して割込みハンドラを実行する．
	 *
	 *  割込み待ちの間は，p_runtskをNULL（＝0）に設定しなければならな
	 *  い．このように設定しないと，割込みハンドラからiget_tidを呼び出
	 *  した際の動作が仕様に合致しなくなる．
	 *
	 */
#ifdef TOPPERS_CUSTOM_IDEL
	toppers_asm_custom_idle
#else
	cpsid i               /* PRIMASK をセット */
	msr   basepri, r0     /* 全割込み許可 */ 
	wfi
	cpsie i               /* PRIMASK をクリア（割込みを受け付ける） */
	msr   basepri, r1     /* CPUロック状態へ */ 
#endif /* TOPPERS_CUSTOM_IDLE */

	ldr   r6, [r2]        /* reqflgがfalseならdispatcher_2へ */
	cmp   r6, #0
	beq   dispatcher_2
	str   r0, [r2]        /* reqflgをfalseに */

	/*
	 *  CPUロック状態に戻す．割込み待ちの間に実行した割込みハンドラによ
	 *  り，saved_iipmが書き換えられる可能性があるため，元の値に戻す必
	 *  要がある．dispatcherが実行される時は，saved_iipmがIIPM_ENAALL
	 *  となっているため，ここではsaved_iipmをIIPM_ENAALL（＝0）に戻せ
	 *  ばよい．
	 */
	mov   r0, #CONTROL_PSP  /* PSPを有効に  */ 
	msr   control, r0      
	isb                     /* control の操作後に必要 */
	mov   r2, #1            /* lock_flagをtrueへ */
	ldr   r4, =lock_flag  
	str   r2, [r4]
	ldr   r4, =saved_iipm   /* saved_iipm を0に */
	mov   r0, #0
	str   r0, [r4]
	b     dispatcher_0


/*
 *  カーネルの終了処理の呼出し
 *
 *  スタックを非タスクコンテキスト用に切り替え．
 *  
 */
	.text
	.syntax unified
	.code 16
	.globl call_exit_kernel
	.type call_exit_kernel, function
call_exit_kernel:
	mov   r0, #CONTROL_MSP
	msr   control, r0       /* MSPを有効に  */
	isb                     /* control の操作後に必要 */
	b     exit_kernel       /* カーネルの終了処理を呼ぶ */


/*
 *  タスク起動処理
 *
 *  dispatcherから呼び出されるため，TCBのアドレスはr1に入っている
 *
 */ 
	.text
	.syntax unified
	.code 16
	.global start_r
	.type start_r, function
start_r:
	mov   r0, #0
	ldr   r4, =lock_flag                    /* CPUロック解除状態へ */
	str   r0, [r4]
	msr   basepri, r0                       /* 割込み許可   */
	ldr   lr, =ext_tsk                      /* 戻り番地設定 */
	ldr   r2, [r1, #TCB_p_tinib]            /* p_runtsk->p_tinibをr2に  */
	ldr   r0, [r2, #TINIB_exinf]            /* exinfを引数レジスタr0に  */
	ldr   r1, [r2, #TINIB_task]             /* タスク起動番地にジャンプ */
	mov   pc, r1 

/*
 *  微少時間待ち
 */
	.text
	.syntax unified
	.code 16
	.globl sil_dly_nse
	.type sil_dly_nse, function
sil_dly_nse:
	sub   r0, r0, #SIL_DLY_TIM1
	cmp   r0, #0
	bgt   sil_dly_nse1
	mov   pc, lr
sil_dly_nse1:
	sub   r0, r0, #SIL_DLY_TIM2
	cmp   r0, #0
	bgt   sil_dly_nse1
	mov   pc, lr
