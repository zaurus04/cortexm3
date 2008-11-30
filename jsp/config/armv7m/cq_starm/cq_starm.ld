/*
 *  @(#) $Id: cq_starm.ld,v 1.8 2008/07/10 12:30:46 suikan Exp $
 */

PROVIDE (__stack = 0) ;
PROVIDE (hardware_init_hook = 0) ;
PROVIDE (software_init_hook = 0) ;
PROVIDE (software_term_hook = 0) ;
PROVIDE (default_nmi_handler = 0) ;
PROVIDE (default_hard_fault_handler = 0) ;

/*
* CQ-STARM(STM32F103VB)�́A128kB�̃t���b�V���ƁA20KB��SRAM�������Ă���B
* �ȉ��ł͂��ꂼ��̃������Z�O�����g�̐錾���s���B
*/
MEMORY{
    flash(arx)  : org = 0x08003000, len = 116K /* DFU��12KB ������Ă��� */
    ram(w)      : org = 0x20000000, len = 16K
}


SECTIONS
{
	
	.reset_vector :	/* ���Z�b�g���ɎQ�Ƃ�����O�x�N�g���B4�G���g���̂݁BFLASH�̈�̐擪�ɂ��� */
	{
		KEEP (start.o(.rodata))
	} > flash 
	
    
    .text :
    {
        __text = . ;
        *(.text .stub .text.* .gnu.linkonce.t.*)

    } > flash
    
    .fini :
    {
        KEEP (*(.fini))
    } > flash
    
    _etext = . ;
    PROVIDE (etext = .) ;
    .rodata :
    {
        *(.rodata .rodata.* .gnu.linkonce.r.*)
    } > flash
    
    /*
    * �ȉ��̃Z�N�V�����ŁA "AT(FOO)"�́A�A�h���XFOO�ɃI�u�W�F�N�g��z�u���邱�Ƃ��Ӗ�����B
    * __idata_start�́A���O��.�ɏ���������Ă���A.�͌��݃����J���f�[�^��z�u���Ă���
    * �ʒu��\���B�O�̃Z�N�V�����̗��ꂩ��A���݃����J���f�[�^��z�u���Ă���̂�flash�ł���B
    * �܂�A.data��flash�ɔz�u�����B����A"}>ram"�́A���s���ɂ�ram�����ɔz�u�����
    * ���Ƃ��Ӗ�����B
    *
    * �ȏ�̂��Ƃ���A.data��flash�����Ɋi�[����Ă��邪�A�v���O�������s�O��ram�ɃR�s�[
    * ���Ȃ���΂Ȃ�Ȃ����Ƃ��킩��B������s���Ă���̂��A$(CPU)/start.S �ł���B
    */
    . = ALIGN(4) ;
    __idata_start = . ;
    .data : AT(__idata_start) 
    {
        __data_start = . ;
        *(.data)
    } > ram
    
    .eh_frame : AT(.){ KEEP (*(.eh_frame)) } > ram
 
    .gcc_except_table : AT(.){ *(.gcc_except_table) } > ram
 
    .ctors : AT(.)
    {
        KEEP (*crtbegin.o(.ctors))
        KEEP (*(EXCLUDE_FILE (*crtend.o ) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*(.ctors))
    } > ram
    
    .dtors : AT(.)
    {
        KEEP (*crtbegin.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o ) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*(.dtors))
    } > ram
  
    __idata_end = __idata_start + SIZEOF(.data) ;
    
    
    _edata  = . ;
    PROVIDE (edata = .) ;
    . = ALIGN(4) ;
    __bss_start = . ;
    .bss :
    {
        *(.bss)
        *(COMMON)
    } > ram
    _end = . ;
    __bss_end = . ;
    
    
	.master_stack ALIGN(4): 
	{
		KEEP (*(.master_stack))
	} > ram
    __master_stack = . -4;

    
	/* ��O�x�N�g���T�C�Y���傫��2�̙p�ɐ��񂷂�[BYTE]. ���̐���́ACORTEX-M3�̃A�[�L�e�N�`���ɂ��v���ł���  */
    
    .exc_vector ALIGN(256):	/*  ��O�x�N�g���B */
	{
		KEEP (*(.vector))
	} > ram
    
    
    
    
    PROVIDE (end = .) ;
    
    .comment        0 : { *(.comment) }
    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
}