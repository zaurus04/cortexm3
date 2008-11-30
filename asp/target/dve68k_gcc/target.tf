$ 
$ 		�ѥ�2�Υ������åȰ�¸�ƥ�ץ졼�ȡ�DVE68K/40�ѡ�
$ 

$ 
$  ATT_ISR�ǻ��ѤǤ��������ֹ�Ȥ�����б��������ߥϥ�ɥ��ֹ�
$ 
$INTNO_ATTISR_VALID = { 1,2,...,7;9,10,...,16;17,18,...,24 }$
$INHNO_ATTISR_VALID = { 0x47,0x46,...,0x41;0x4f,0x4e,...,0x48;
						0x57,0x56,...,0x50 }$

$ 
$  DEF_INT��DEF_EXC�ǻ��ѤǤ������ߥϥ�ɥ��ֹ桿CPU�㳰�ϥ�ɥ��ֹ�
$ 
$INHNO_DEFINH_VALID = { 0x10,0x11,...,0x1f;0x40,0x41,...,0xff }$
$EXCNO_DEFEXC_VALID = { 0x02,0x03,...,0x0f;0x20,0x21,...,0x3f }$

$ 
$  CFG_INT�ǻ��ѤǤ��������ֹ�ȳ����ͥ����
$ 
$INTNO_CFGINT_VALID = { 1,2,...,7;9,10,...,31 }$
$INTPRI_CFGINT_VALID = { -7,-6,...,-1 }$

$ 
$  �����å���ˡ�λ���
$ 
$CHECK_STKSZ_ALIGN = 4$

$ 
$  ɸ��ƥ�ץ졼�ȥե�����Υ��󥯥롼��
$ 
$INCLUDE "kernel/kernel.tf"$

/*$NL$
$SPC$*  Target-dependent Definitions (DVE68K/40)$NL$
$SPC$*/$NL$
$NL$

$ 
$   CFG_INT�Υ������åȰ�¸�Υ��顼�����å���_kernel_bitpat_cfgint������
$ 
$bitpat_cfgint = 0$

$FOREACH intno INT.ORDER_LIST$
	$bitpat = (1 << (32 - INT.INTNO[intno]))$
	$bitpat_cfgint = bitpat_cfgint | bitpat$

	$IF (bitpat & DGA_INT_TRG_LEVEL) != 0$
		$IF (INT.INTATR[intno] & TA_EDGE) != 0$
			$ERROR INT.TEXT_LINE[intno]$E_RSATR: $FORMAT("Edge trigger (TA_EDGE) is not supported for intno `%1%\' in CFG_INT", INT.INTNO[intno])$$END$
		$END$
	$ELSE$
	$IF (bitpat & DGA_INT_TRG_EDGE) != 0$
		$IF (INT.INTATR[intno] & TA_EDGE) == 0$
			$ERROR INT.TEXT_LINE[intno]$E_RSATR: $FORMAT("Level trigger is not supported for intno `%1%\' in CFG_INT", INT.INTNO[intno])$$END$
		$END$
	$END$
	$END$
$END$
const uint32_t	_kernel_bitpat_cfgint = UINT32_C($FORMAT("0x%08x", bitpat_cfgint)$);
$NL$
