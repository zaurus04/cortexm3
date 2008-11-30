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
 *  @(#) $Id: cpu_config.h,v 1.19 2008/08/02 07:36:14 suikan Exp $
 */

/*
 *	プロセッサ依存モジュール（CORTEX-M3用）
 *
 *  このインクルードファイルは，t_config.h のみからインクルードされる．
 *  他のファイルから直接インクルードしてはならない．
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  カーネルの内部識別名のリネーム
 */
#include <cpu_rename.h>

/*
 * CORTEX-M3移植中の「埋め草」。コンパイルエラーをつぶすために
 * 便宜上、空にした関数の中にCM3NIと書いておく。以下の#define定義を
 * コメントアウトすると、移植が完了していない関数を洗い出せる。
 * 
 * CORTEX-M3 Not Implemented
 */
#define CM3NI
 
/*
 *  プロセッサの特殊命令のインライン関数定義
 */
#ifndef _MACRO_ONLY
#include <cpu_insn.h>
#endif /* _MACRO_ONLY */


/*
 *  TCB 中のフィールドのビット幅の定義
 *
 *  cpu_context.h に入れる方がエレガントだが，参照の依存性の関係で，
 *  cpu_context.h には入れられない．
 */
#define	TBIT_TCB_TSTAT		8	/* tstat フィールドのビット幅 */
#define	TBIT_TCB_PRIORITY	8	/* priority フィールドのビット幅 */

#ifndef _MACRO_ONLY
/*
 *  タスクコンテキストブロックの定義
 */
typedef struct task_context_block {
	VP	sp;		/* スタックポインタ */
	FP	pc;		/* プログラムカウンタ */
} CTXB;



/*
 *  システム状態参照
 * 
 *  非タスク・コンテキストならTRUEを返す。TOPPERS/JSP for CORTEX-M3では、
 *  タスク・コンテキストをThreadモードに割り当てているため、ipsrが0ならタスク
 *  コンテキスト、それ以外は非タスク・コンテキストといえる。この関数は、dispatch()の
 *  中で呼ぶと正確な情報を返さないが、dispatch()はこれを呼ばないので問題ない。
 * 
 * MRS Rx, IPSR 命令はIPSRの値を取り出す。IPSRは下位9bitに実行レベル情報を
 * 持っているので、そこだけマスクで取り出して真偽判定につかう。
 */

Inline BOOL
sense_context()
{
	unsigned int ipsr_value;
	
	Asm( "mrs %0,ipsr" : "=r"(ipsr_value) );
	return(ipsr_value & 0x1FF);
}

/*
 *  ロック状態参照
 * 
 * CPUロック状態ならTRUEを返す。TOPPERS/JSP for CORTEX-M3では、
 * 全割り込み禁止をもってロック状態とする。そのため、PRIMASKのbit1が
 * ロック状態を反映する。
 * 
 * MRS Rx, PRIMASK 命令はPRIMASKの値を取り出す。PRIMASKはLSBに
 * 割り込み禁止情報をもっており、1なら禁止である。そこだけマスクで取り出して
 * 真偽判定につかう。
 */

Inline BOOL
sense_lock()
{
	unsigned int primask_value;
	
	Asm( "mrs %0,primask" : "=r"(primask_value) );
	return(primask_value & 0x01);
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 * CPUロックとその解除（タスクコンテキスト用）
 *
 * CORTEX-M3版では、CPUロックを全割り込み禁止で行う。そのため、
 * CPSID I命令でCPUロック、CPSIE I命令でアンロックできる。この
 * 命令はコンテキストにかかわらず使える。
 */


Inline void
t_lock_cpu()
{
	Asm( "cpsid i" );
}

Inline void
t_unlock_cpu()
{
	Asm( "cpsie i" );
}

/*
 *  CPUロックとその解除（非タスクコンテキスト用）
 */

#define i_lock_cpu t_lock_cpu
#define i_unlock_cpu t_unlock_cpu

/*
 *  タスクディスパッチャ
 */

/*
 *  最高優先順位タスクへのディスパッチ（cpu_support.S）
 *
 *  dispatch は，タスクコンテキストから呼び出されたサービスコール処理
 *  内で，CPUロック状態で呼び出さなければならない．
 */
extern void	dispatch(void);

/*
 *  現在のコンテキストを捨ててディスパッチ（cpu_support.S）
 *
 *  exit_and_dispatch は，CPUロック状態で呼び出さなければならない．
 */
extern void	exit_and_dispatch(void);

/*
 *  割込みハンドラ／CPU例外ハンドラの設定
 */

/*
 *  例外ベクタテーブルの構造の定義
 */
typedef struct exc_vector_entry {
	FP	exchdr;			/* 例外ハンドラの起動番地 */
} EXCVE;

extern EXCVE exception_vector[];

/*
 *  割込みハンドラの設定
 *
 *  ベクトル番号 inhno の割込みハンドラの起動番地を inthdr に設定する．
 */
Inline void
define_inh(INHNO inhno, FP inthdr)
{

	exception_vector[inhno].exchdr = inthdr;
}

/*
 *  CPU例外ハンドラの設定
 *
 *  ベクトル番号 excno のCPU例外ハンドラの起動番地を exchdr に設定する．
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{
	exception_vector[excno].exchdr = exchdr;
}

/*
 *  割込みハンドラ／CPU例外ハンドラの出入口処理
 */

/*
 *  割込みハンドラの出入口処理の生成マクロ
 *
 */

#define	INTHDR_ENTRY(inthdr)		\
extern void inthdr##_entry(void);	\
asm(".text				\n" \
#inthdr "_entry:			\n" \
"	push {lr} \n"				/* 戻り番地を保存 */\
"	ldr r0,=" #inthdr "+1 \n"		/* ハンドラの番地 */\
"	blx r0 \n"					/* ハンドラを呼び出す */\
"	pop {lr} \n"				/* 戻り番地を復帰 */\
"	and r0,lr,#0x0F \n"			/* EXC_RETURNの下位4bitを取り出す */\
"	cmp r0,#0x0D \n"			/* LSB 4bitが 0b1101ならば、一番外側の割り込み */\
"   beq.w _kernel_ret_int \n"	/* 一番外側なら出口処理 */\
"	bx lr " );					/* リターン */

#define	INT_ENTRY(inthdr)	inthdr##_entry

/*
 *  CPU例外ハンドラの出入口処理の生成マクロ
 *
 * CORTEX-M3版では実装しない
 */

#define	EXCHDR_ENTRY(exchdr)
#define	EXC_ENTRY(exchdr)	exchdr##_entry

/*
 *  CPU例外の発生した時のシステム状態の参照
 */

/*
 *  CPU例外の発生した時のコンテキストの参照
 *  CORTEX-M3版では実装しない。返すのはでたらめの値である。
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	return(0);
}

/*
 *  CPU例外の発生した時のCPUロック状態の参照
 *  CORTEX-M3版では実装しない。返すのはでたらめの値である。
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return(0);
}

/*
 *  プロセッサ依存の初期化
 */
extern void	cpu_initialize(void);

/*
 *  プロセッサ依存の終了時処理
 */
extern void	cpu_terminate(void);

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
