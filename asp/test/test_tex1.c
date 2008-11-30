/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2006-2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_tex1.c 818 2008-03-18 12:56:15Z hiro $
 */

/* 
 *		タスク例外処理に関するテスト(1)
 *
 * 【テストの目的】
 *
 *  タスクからタスク例外処理ルーチンを起動する処理を網羅的にテストする．
 *
 * 【テスト項目】
 *
 *	(A) ras_tex，ref_texのエラー検出
 *		(A-1) 対象タスクが休止状態
 *		(A-2) 対象タスクのタスク例外処理ルーチンが定義されていない
 *	(B) dis_tex，ena_texのエラー検出
 *		(B-1) 自タスクのタスク例外処理ルーチンが定義されていない
 *	(C) ras_texの正常処理
 *		(C-1) 対象タスクが自タスクかつタスク例外処理許可で，すぐに起動
 *		(C-2) 対象タスクが自タスクでない
 *		(C-3) 対象タスクが自タスクだがタスク例外処理禁止
 *	(D) ena_texの正常処理
 *		(D-1) タスク例外処理要求があり，すぐに起動
 *		(D-2) タスク例外処理要求がない
 *	(E) タスクディスパッチャによる起動
 *		(E-1) ディスパッチ後のタスクがタスク例外許可でタスク例外処理要
 *			  求あり
 *	(F) タスク例外処理ルーチンからのリターンによる起動（連続起動）
 *	(G) タスク例外処理ルーチンからの戻り時による状態復帰
 *		(G-1) タスクに戻ってくる時
 *		(G-2) タスク例外処理ルーチンが連続起動される時
 *	(H) タスク例外処理ルーチンの多重起動
 *	(I) タスク例外処理ルーチンからの戻り時のタスク切換え
 *
 * 【使用リソース】
 *
 *	TASK1: メインのタスク．自タスクに対してタスク例外処理を要求する
 *	TASK2: 他タスクに対してタスク例外処理を要求する対象タスク
 *	TASK3: タスク例外処理ルーチンが定義されていないタスク
 *	TASK4: 休止状態のタスク
 *
 * 【テストシーケンス】
 *
 *	== TASK1（優先度：10）==
 *	1:	初期状態のチェック
 *		ref_tex(TSK_SELF, &rtex)
 *		ras_tex(TASK3, 0x0001)		... (A-2)
 *		ras_tex(TASK4, 0x0001)		... (A-1)
 *		ref_tex(TASK3, &rtex)		... (A-2)
 *		ref_tex(TASK4, &rtex)		... (A-1)
 *	2:	ena_tex()					... (D-2)
 *		ref_tex(TSK_SELF, &rtex)
 *	3:	ras_tex(TSK_SELF, 0x0001)	... (C-1)
 *	== TASK1タスク例外処理ルーチン（1回目）==
 *	4:	初期状態のチェック
 *	5:	dis_dsp() ... 4つの状態をそれぞれ変化させる
 *		chg_ipm(TMAX_INTPRI)
 *		ena_tex()
 *		loc_cpu()
 *		リターン
 *	== TASK1（続き）==
 *	6:	戻ってきた状態のチェック	... (G-1)
 *	7:	dis_dsp() ... 3つの状態をそれぞれ変化させる
 *		chg_ipm(TMIN_INTPRI)
 *		dis_tex()
 *	8:	ras_tex(TASK1, 0x0002)		... (C-3)
 *		ref_tex(TSK_SELF, &rtex)
 *	9:	ena_tex()					... (D-1)
 *	== TASK1タスク例外処理ルーチン（2回目）==
 *	10:	初期状態のチェック
 *	11:	ras_tex(TASK1, 0x0001)		... (C-3)
 *		ras_tex(TASK1, 0x0002)		... (C-3)
 *	12:	ena_dsp() ... 3つの状態をそれぞれ変化させる
 *		chg_ipm(TMAX_INTPRI)
 *		loc_cpu()
 *		リターン					... (F)
 *	== TASK1タスク例外処理ルーチン（3回目）==
 *	13:	初期状態のチェック
 *	14:	ena_dsp() ... 3つの状態をそれぞれ変化させる
 *		chg_ipm(TMAX_INTPRI)
 *		ena_tex()
 *	15: ras_tex(TSK_SELF, 0x0004)	... (H)
 *	== TASK1タスク例外処理ルーチン（4回目）==
 *	16:	初期状態のチェック
 *	17:	dis_dsp() ... 3つの状態をそれぞれ変化させる
 *		chg_ipm(TIPM_ENAALL)
 *		loc_cpu()
 *		リターン
 *	== TASK1タスク例外処理ルーチン（3回目続き）==
 *	18:	戻ってきた状態のチェック	... (G-2)
 *		リターン
 *	== TASK1（続き）==
 *	19:	戻ってきた状態のチェック	... (G-1)
 *	20: ena_dsp()
 *		chg_ipm(TIPM_ENAALL)
 *		rot_rdq(TPRI_SELF)
 *	== TASK2（優先度：10）	==
 *	21:	初期状態のチェック
 *	22:	ena_tex()
 *		rot_rdq(TPRI_SELF)
 *	== TASK3（優先度：10）	==
 *	23:	初期状態のチェック
 *	24:	ena_tex()
 *	25:	dis_tex()					... (B-1)
 *		ext_tsk()					... (B-1)
 *	== TASK1（続き）==
 *	26: ras_tex(TASK2, 0x0001)		... (C-2)
 *		ref_tex(TASK2, &rtex)
 *	27:	rot_rdq(TPRI_SELF)			... (E-1)
 *	== TASK2タスク例外処理ルーチン（1回目）==
 *	28:	初期状態のチェック
 *		リターン
 *	== TASK2（続き）==
 *	29: ras_tex(TSK_SELF, 0x0002)
 *	== TASK2タスク例外処理ルーチン（2回目）==
 *	30:	初期状態のチェック
 *	31:	dis_dsp
 *		rot_rdq(TPRI_SELF)
 *	32:	リターン					... (I)
 *	== TASK1（続き）==
 *	33:	リターン（タスク終了）
 *	== TASK2（続き）==
 *	34:	テスト終了
 */

#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_tex1.h"

void
tex_task1(TEXPTN texptn, intptr_t exinf)
{
	ER		ercd;

	switch (texptn) {
	case 0x0001:
		check_point(4);
		check_state(false, false, TIPM_ENAALL, false, false, true);

		/*
		 *  ディスパッチ禁止，割込み優先度マスク変更，タスク例外処理許可
		 */
		check_point(5);
		ercd = dis_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TMAX_INTPRI);
		check_ercd(ercd, E_OK);
		ercd = ena_tex();
		check_ercd(ercd, E_OK);
		ercd = loc_cpu();
		check_ercd(ercd, E_OK);
		check_state(false, true, TMAX_INTPRI, true, true, false);
		break;

	case 0x0002:
		check_point(10);
		check_state(false, false, TMIN_INTPRI, true, true, true);

		/*
		 *  タスク例外処理を要求
		 */
		check_point(11);
		ercd = ras_tex(TSK_SELF, 0x0001);
		check_ercd(ercd, E_OK);
		ercd = ras_tex(TSK_SELF, 0x0002);
		check_ercd(ercd, E_OK);

		/*
		 *  ディスパッチ許可，割込み優先度マスク変更，CPUロック
		 */
		check_point(12);
		ercd = ena_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TMAX_INTPRI);
		check_ercd(ercd, E_OK);
		ercd = loc_cpu();
		check_ercd(ercd, E_OK);
		check_state(false, true, TMAX_INTPRI, false, true, true);
		break;

	case 0x0003:
		check_point(13);
		check_state(false, false, TMIN_INTPRI, true, true, true);

		/*
		 *  ディスパッチ許可，割込み優先度マスク変更，タスク例外許可
		 */
		check_point(14);
		ercd = ena_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TMAX_INTPRI);
		check_ercd(ercd, E_OK);
		ercd = ena_tex();
		check_ercd(ercd, E_OK);
		check_state(false, false, TMAX_INTPRI, false, true, false);

		/*
		 *  タスク例外処理を要求
		 */
		check_point(15);
		ercd = ras_tex(TSK_SELF, 0x0004);
		/* ここでタスク例外処理ルーチンが動作する */
		check_ercd(ercd, E_OK);

		/*
		 *  タスク例外処理からのリターンにより元の状態に戻っていること
		 *  をチェック
		 */
		check_point(18);
		check_state(false, false, TMAX_INTPRI, false, true, false);
		break;

	case 0x0004:
		check_point(16);
		check_state(false, false, TMAX_INTPRI, false, true, true);

		/*
		 *  ディスパッチ禁止，割込み優先度マスク変更，CPUロック
		 */
		check_point(17);
		ercd = dis_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TIPM_ENAALL);
		check_ercd(ercd, E_OK);
		ercd = loc_cpu();
		check_ercd(ercd, E_OK);
		check_state(false, true, TIPM_ENAALL, true, true, true);
		break;

	default:
		check_point(0);
		break;
	}
}

void
task1(intptr_t exinf)
{
	ER		ercd;
	T_RTEX	rtex;

	/*
	 *  初期状態のチェック
	 */
	check_point(1);
	check_state(false, false, TIPM_ENAALL, false, false, true);
	ercd = ref_tex(TSK_SELF, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_DIS) != 0);
	check_assert(rtex.pndptn == 0);

	/*
	 *  ras_texのエラー検出
	 */
	ercd = ras_tex(TASK3, 0x0001);
	check_ercd(ercd, E_OBJ);
	ercd = ras_tex(TASK4, 0x0001);
	check_ercd(ercd, E_OBJ);

	/*
	 *  ref_texのエラー検出
	 */
	ercd = ref_tex(TASK3, &rtex);
	check_ercd(ercd, E_OBJ);
	ercd = ref_tex(TASK4, &rtex);
	check_ercd(ercd, E_OBJ);

	/*
	 *  タスク例外処理の許可
	 */
	check_point(2);
	ercd = ena_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, false, false, false);
	ercd = ref_tex(TSK_SELF, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_ENA) != 0);
	check_assert(rtex.pndptn == 0);

	/*
	 *  タスク例外処理を要求
	 */
	check_point(3);
	ercd = ras_tex(TSK_SELF, 0x0001);
	/* ここでタスク例外処理ルーチンが動作する */
	check_ercd(ercd, E_OK);

	/*
	 *  タスク例外処理からのリターンにより元の状態に戻っていることを
	 *  チェック
	 */
	check_point(6);
	check_state(false, false, TIPM_ENAALL, false, false, false);

	/*
	 *  ディスパッチ禁止，割込み優先度マスク変更，タスク例外処理禁止
	 */
	check_point(7);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);
	ercd = chg_ipm(TMIN_INTPRI);
	check_ercd(ercd, E_OK);
	ercd = dis_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TMIN_INTPRI, true, true, true);

	/*
	 *  タスク例外処理を要求
	 */
	check_point(8);
	ercd = ras_tex(TASK1, 0x0002);
	check_ercd(ercd, E_OK);
	ercd = ref_tex(TSK_SELF, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_DIS) != 0);
	check_assert(rtex.pndptn == 0x0002);

	/*
	 *  タスク例外処理を許可
	 */
	check_point(9);
	ercd = ena_tex();
	/* ここでタスク例外処理ルーチンが動作する */
	check_ercd(ercd, E_OK);

	/*
	 *  タスク例外処理からのリターンにより元の状態に戻っていることを
	 *  チェック
	 */
	check_point(19);
	check_state(false, false, TMIN_INTPRI, true, true, false);

	/*
	 *  タスク2に切り換える
	 */
	check_point(20);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);
	ercd = chg_ipm(TIPM_ENAALL);
	check_ercd(ercd, E_OK);
	ercd = rot_rdq(TPRI_SELF);
	/* ここで他のタスクが動作する */
	check_ercd(ercd, E_OK);

	/*
	 *  タスク2に対してタスク例外処理を要求
	 */
	check_point(26);
	ercd = ras_tex(TASK2, 0x0001);
	check_ercd(ercd, E_OK);
	ercd = ref_tex(TASK2, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_ENA) != 0);
	check_assert(rtex.pndptn == 0x0001);

	/*
	 *  タスク2に切り換える
	 */
	check_point(27);
	ercd = rot_rdq(TPRI_SELF);
	/* ここで他のタスクが動作する */
	check_ercd(ercd, E_OK);

	/*
	 *  タスク終了
	 */
	check_point(33);
}

void
tex_task2(TEXPTN texptn, intptr_t exinf)
{
	ER		ercd;

	switch (texptn) {
	case 0x0001:
		check_point(28);
		check_state(false, false, TIPM_ENAALL, false, false, true);
		break;

	case 0x0002:
		check_point(30);
		check_state(false, false, TIPM_ENAALL, false, false, true);

		/*
		 *  ディスパッチを禁止して，タスク切換えを要求する．
		 */
		check_point(31);
		ercd = dis_dsp();
		check_ercd(ercd, E_OK);
		ercd = rot_rdq(TPRI_SELF);
		check_ercd(ercd, E_OK);

		/*
		 *  タスク例外処理ルーチンからのリターンで，タスク切換えが発生
		 *  する．
		 */
		check_point(32);
		break;

	default:
		check_point(0);
		break;
	}
}

void
task2(intptr_t exinf)
{
	ER		ercd;

	/*
	 *  初期状態のチェック
	 */
	check_point(21);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  タスク例外処理の許可
	 */
	check_point(22);
	ercd = ena_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, false, false, false);

	/*
	 *  タスク3に切り換える
	 */
	ercd = rot_rdq(TPRI_SELF);
	/* ここで他のタスクが動作する */
	check_ercd(ercd, E_OK);

	/*
	 *  タスク例外処理を要求
	 */
	check_point(29);
	ercd = ras_tex(TSK_SELF, 0x0002);
	/* ここでタスク例外処理ルーチンが動作する */
	check_ercd(ercd, E_OK);

	/*
	 *  テスト終了
	 */
	check_finish(34);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	/*
	 *  初期状態のチェック
	 */
	check_point(23);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  タスク例外処理の許可
	 */
	check_point(24);
	ercd = ena_tex();
	check_ercd(ercd, E_OBJ);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  タスク例外処理の禁止
	 */
	check_point(25);
	ercd = dis_tex();
	check_ercd(ercd, E_OBJ);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  タスク終了
	 */
	ercd = ext_tsk();
	check_point(0);
}

void
task4(intptr_t exinf)
{
	check_point(0);
}

void
tex_task4(TEXPTN texptn, intptr_t exinf)
{
	check_point(0);
}
