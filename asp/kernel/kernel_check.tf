$ ======================================================================
$ 
$   TOPPERS/ASP Kernel
$       Toyohashi Open Platform for Embedded Real-Time Systems/
$       Advanced Standard Profile Kernel
$ 
$   Copyright (C) 2008 by Embedded and Real-Time Systems Laboratory
$               Graduate School of Information Science, Nagoya Univ., JAPAN
$  
$   �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
$   �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
$   �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
$   (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
$       ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
$       ����������˴ޤޤ�Ƥ��뤳�ȡ�
$   (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$       �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
$       �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
$       ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
$   (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$       �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
$       �ȡ�
$     (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
$         �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
$     (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
$         ��𤹤뤳�ȡ�
$   (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
$       ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
$       �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
$       ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
$       ���դ��뤳�ȡ�
$  
$   �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
$   ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
$   ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
$   �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
$   ����Ǥ�����ʤ���
$ 
$   @(#) $Id$
$  
$ =====================================================================

$ 
$  �ؿ�����Ƭ���ϤΥ����å�
$ 
$IF LENGTH(CHECK_FUNC_ALIGN) || LENGTH(CHECK_FUNC_NONNULL)$
$	// �������ȥ������㳰�����롼�������Ƭ���ϤΥ����å�
	$tinib = SYMBOL("_kernel_tinib_table")$
	$FOREACH tskid TSK.ID_LIST$
		$task = PEEK(tinib + offsetof_TINIB_task, sizeof_FP)$
		$IF LENGTH(CHECK_FUNC_ALIGN) && (task & (CHECK_FUNC_ALIGN - 1))$
			$ERROR TSK.TEXT_LINE[tskid]$E_PAR: 
				$FORMAT(_("%1% `%2%\' of `%3%\' in %4% is not aligned"),
				"task", TSK.TASK[tskid], tskid, "CRE_TSK")$$END$
		$END$
		$IF LENGTH(CHECK_FUNC_NONNULL) && (task == 0)$
			$ERROR TSK.TEXT_LINE[tskid]$E_PAR: 
				$FORMAT(_("%1% `%2%\' of `%3%\' in %4% is null"),
				"task", TSK.TASK[tskid], tskid, "CRE_TSK")$$END$
		$END$
		$texrtn = PEEK(tinib + offsetof_TINIB_texrtn, sizeof_FP)$
		$IF LENGTH(CHECK_FUNC_ALIGN) && (texrtn & (CHECK_FUNC_ALIGN - 1))$
			$ERROR DEF_TEX.TEXT_LINE[tskid]$E_PAR: 
				$FORMAT(_("%1% `%2%\' of `%3%\' in %4% is not aligned"),
				"texrtn", TSK.TEXRTN[tskid], tskid, "DEF_TEX")$$END$
		$END$
		$tinib = tinib + sizeof_TINIB$
	$END$

$	// �����ϥ�ɥ����Ƭ���ϤΥ����å�
	$cycinib = SYMBOL("_kernel_cycinib_table")$
	$FOREACH cycid CYC.ID_LIST$
		$cychdr = PEEK(cycinib + offsetof_CYCINIB_cychdr, 4)$
		$IF LENGTH(CHECK_FUNC_ALIGN) && (cychdr & (CHECK_FUNC_ALIGN - 1))$
			$ERROR CYC.TEXT_LINE[cycid]$E_PAR: 
				$FORMAT(_("%1% `%2%\' of `%3%\' in %4% is not aligned"),
				"cychdr", CYC.CYCHDR[cycid], cycid, "CRE_CYC")$$END$
		$END$
		$IF LENGTH(CHECK_FUNC_NONNULL) && (cychdr == 0)$
			$ERROR CYC.TEXT_LINE[cycid]$E_PAR: 
				$FORMAT(_("%1% `%2%\' of `%3%\' in %4% is null"),
				"cychdr", CYC.CYCHDR[cycid], cycid, "CRE_CYC")$$END$
		$END$
		$cycinib = cycinib + sizeof_CYCINIB$
	$END$

$	// ���顼��ϥ�ɥ����Ƭ���ϤΥ����å�
	$alminib = SYMBOL("_kernel_alminib_table")$
	$FOREACH almid ALM.ID_LIST$
		$almhdr = PEEK(alminib + offsetof_ALMINIB_almhdr, 4)$
		$IF LENGTH(CHECK_FUNC_ALIGN) && (almhdr & (CHECK_FUNC_ALIGN - 1))$
			$ERROR ALM.TEXT_LINE[almid]$E_PAR: 
				$FORMAT(_("%1% `%2%\' of `%3%\' in %4% is not aligned"),
				"almhdr", ALM.ALMHDR[almid], almid, "CRE_ALM")$$END$
		$END$
		$IF LENGTH(CHECK_FUNC_NONNULL) && (almhdr == 0)$
			$ERROR ALM.TEXT_LINE[almid]$E_PAR: 
				$FORMAT(_("%1% `%2%\' of `%3%\' in %4% is null"),
				"almhdr", ALM.ALMHDR[almid], almid, "CRE_ALM")$$END$
		$END$
		$alminib = alminib + sizeof_ALMINIB$
	$END$
$END$

$ 
$  �����å��ΰ����Ƭ���ϤΥ����å�
$ 
$IF LENGTH(CHECK_STACK_ALIGN) || LENGTH(CHECK_STACK_NONNULL)$
$	// �������Υ����å��ΰ����Ƭ���ϤΥ����å�
	$tinib = SYMBOL("_kernel_tinib_table")$
	$FOREACH tskid TSK.ID_LIST$
		$stk = PEEK(tinib + offsetof_TINIB_stk, sizeof_void_ptr)$
		$IF LENGTH(CHECK_STACK_ALIGN) && (stk & (CHECK_STACK_ALIGN - 1))$
			$ERROR TSK.TEXT_LINE[tskid]$E_PAR: 
				$FORMAT(_("%1% `%2%\' of `%3%\' in %4% is not aligned"),
				"stk", TSK.STK[tskid], tskid, "CRE_TSK")$$END$
		$END$
		$IF LENGTH(CHECK_STACK_NONNULL) && (stk == 0)$
			$ERROR TSK.TEXT_LINE[tskid]$E_PAR: 
				$FORMAT(_("%1% `%2%\' of `%3%\' in %4% is null"),
				"stk", TSK.STK[tskid], tskid, "CRE_TSK")$$END$
		$END$
		$tinib = tinib + sizeof_TINIB$
	$END$

$	// �󥿥�������ƥ������ѤΥ����å��ΰ����Ƭ���ϤΥ����å�
	$istk = PEEK(SYMBOL("_kernel_istk"), sizeof_void_ptr)$
	$IF LENGTH(CHECK_STACK_ALIGN) && (istk & (CHECK_STACK_ALIGN - 1))$
		$ERROR ICE.TEXT_LINE[1]$E_PAR: 
			$FORMAT(_("%1% `%2%\' in %3% is not aligned"),
			"istk", ICS.ISTK[1], "DEF_ICS")$$END$
	$END$
	$IF LENGTH(CHECK_STACK_NONNULL) && (istk == 0)$
		$ERROR ICE.TEXT_LINE[1]$E_PAR: 
			$FORMAT(_("%1% `%2%\' in %3% is null"),
			"istk", ICS.ISTK[1], "DEF_ICS")$$END$
	$END$
$END$

$ 
$  ����Ĺ����ס����ΰ����Ƭ���ϤΥ����å�
$ 
$IF LENGTH(CHECK_MPF_ALIGN) || LENGTH(CHECK_MPF_NONNULL)$
$	// ����Ĺ����ס����ΰ����Ƭ���ϤΥ����å�
	$mpfinib = SYMBOL("_kernel_mpfinib_table")$
	$FOREACH mpfid MPF.ID_LIST$
		$mpf = PEEK(mpfinib + offsetof_MPFINIB_mpf, sizeof_void_ptr)$
		$IF LENGTH(CHECK_MPF_ALIGN) && (mpf & (CHECK_MPF_ALIGN - 1))$
			$ERROR MPF.TEXT_LINE[mpfid]$E_PAR: 
				$FORMAT(_("%1% `%2%\' of `%3%\' in %4% is not aligned"),
				"mpf", MPF.MPF[mpfid], mpfid, "CRE_MPF")$$END$
		$END$
		$IF LENGTH(CHECK_MPF_NONNULL) && (mpf == 0)$
			$ERROR MPF.TEXT_LINE[mpfid]$E_PAR: 
				$FORMAT(_("%1% `%2%\' of `%3%\' in %4% is null"),
				"mpf", MPF.MPF[mpfid], mpfid, "CRE_MPF")$$END$
		$END$
		$mpfinib = mpfinib + sizeof_MPFINIB$
	$END$
$END$
