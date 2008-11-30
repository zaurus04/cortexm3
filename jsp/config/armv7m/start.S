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
 *  @(#) $Id: start.S,v 1.14 2008/07/31 12:39:26 suikan Exp $
 */

/*
 *	カーネル用のスタートアップモジュール（CORTEX-M3用）
 */

#define	_MACRO_ONLY
#include <t_config.h>

		/*
		* CORTEX-M3 リセット・ベクトル
		*
		* システム・スタート時に参照される4エントリ分のベクトル。
		* CORTEX-M3 TRM 5.9.1節を参照
		*/
    .section .rodata
    .align 4
    .global vector_table
vector_table:
	.long	__master_stack					/* MSPの初期値。 */
	.long	start + 1						/* 実行開始番地。Thumbモードに入れるため、LSBは1でなければならない */
	.long	default_nmi_handler +1			/* NMI。Thumbモードに入れるため、LSBは1でなければならない */
	.long	default_hard_fault_handler + 1	/* ハード・フォルト。Thumbモードに入れるため、LSBは1でなければならない */

	.align 2
	.thumb
	.text
	.globl start
start:
	/*
	 *  プロセッサモードとスタックポインタの初期化。CORTEX-M3では、ここに到達した時点で
	 *  MSPに正しいスタック領域の最上位のアドレスが設定されている。
	 */	 
	
			/* 割り込み禁止状態に変更 */
	cpsid	i					/* 割り込み禁止。 lock_cpu に相当*/
	movw	r0,#0xFF
	msr		basepri,r0			/* BASEPRI = 0xFF : 全レベルの割り込みを許可 */
	
			/* スタックポインタの値をMSPからPSPにコピー */
	mrs		r0,msp				/* MSPの値を取得 */
	msr		psp,r0				/* PSPに取得した値をセット */
	
			/* スタックを PSP に切り替える */
	mrs		r0,control
	mov		r1,#2
	orr		r0,r1				/* CONTROL[1]でThread Mode時にPSPを使うようにする。
								 * CONTROLはリセット時に0にされ(ARMV7M AAPMRM B1-9 )、
								 * かつリセット直後はThread ModeでMSPを使うので、CONTROL[1]を
								 * 1にすると、PSPが使えるはず */
	msr		control,r0
	isb							/* control への書き込みが浸透するのを待つ */
	 
	/*
	 *  hardware_init_hook の呼出し（0 でない場合）
	 *
	 *  ターゲットハードウェアに依存して必要な初期化処理がある場合
	 *  は，hardware_init_hook という関数を用意する．
	 */
	ldr r0,=hardware_init_hook +1
	cmp r0,r1					/* アドレスは1か */
	beq	start_1					/* hardware_init_hookのアドレスが1なら、呼ばない */
	blx	r0;

	/*
	 *  bssセクションのクリア
	 */
start_1:
	ldr		r0,=__bss_start		/* 領域の開始アドレス */
	ldr		r1,=__bss_end		/* 領域の終了アドレス */
	mov		r2,#0
	cmp		r0,r1				/* 領域終了 ? */
	beq		start_3				/* if yes, finish */
	
start_2:
	strb	r2,[r0]
	add		r0,#1
	cmp		r0,r1				/* 領域終了 ? */
	bne		start_2				/* if no, repeat again */


	/*
	 *  dataセクションの初期化（ROM化対応）
	 *
	 *  __idata_start から __idata_end までを，__data_start 以降に
	 *  コピーする．
	 */
start_3:
	ldr		r0,=__idata_start	/* ソース領域の開始番地 */
	ldr		r1,=__idata_end		/* ソース領域の終了番地（の次の番地） */
	ldr		r2,=__data_start	/* ディスティネーション領域の開始番地 */
	cmp		r0,r1				/* ソース領域終わり ? */
	beq		start_5				/* if yes, finish */



start_4:
	ldrb	r3,[r0]				/* ソースデータ取得 */
	strb	r3,[r2]				/* ディスティネーションに格納 */
	add		r0,#1				/* ソース・アドレスポインタ更新 */
	add		r2,#1				/* ディスティネーション・アドレスポインタ更新 */
	cmp		r0,r1				/* 領域終了 ? */
	bne		start_4				/* if no, repeat again */

	/*
	 *  software_init_hook を呼出し（0 でない場合）
	 *
	 *  ソフトウェア環境（特にライブラリ）に依存して必要な初期化処
	 *  理がある場合は，software_init_hook という関数を用意すれば
	 *  よい．
	 */
start_5:
	ldr	r0,=software_init_hook+1
	cmp r0,r1					/* アドレスは1か */
	beq	start_6					/* hardware_init_hookのアドレスが1なら、呼ばない */
	blx	r0;


	/*
	 *  カーネルを起動する．
	 */
start_6:
	ldr r0,=kernel_start+1
	bx	r0						/* kernel_start()を呼ぶ。どうせ戻ってこないので blxにする必要はない */
