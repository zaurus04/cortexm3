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
* CQ-STARM(STM32F103VB)は、128kBのフラッシュと、20KBのSRAMを持っている。
* 以下ではそれぞれのメモリセグメントの宣言を行う。
*/
MEMORY{
    flash(arx)  : org = 0x08003000, len = 116K /* DFUの12KB を削ってある */
    ram(w)      : org = 0x20000000, len = 16K
}


SECTIONS
{
	
	.reset_vector :	/* リセット時に参照される例外ベクトル。4エントリのみ。FLASH領域の先頭にする */
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
    * 以下のセクションで、 "AT(FOO)"は、アドレスFOOにオブジェクトを配置することを意味する。
    * __idata_startは、直前で.に初期化されており、.は現在リンカがデータを配置している
    * 位置を表す。前のセクションの流れから、現在リンカがデータを配置しているのはflashである。
    * つまり、.dataはflashに配置される。一方、"}>ram"は、実行時にはram内部に配置される
    * ことを意味する。
    *
    * 以上のことから、.dataはflash内部に格納されているが、プログラム実行前にramにコピー
    * しなければならないことがわかる。これを行っているのが、$(CPU)/start.S である。
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

    
	/* 例外ベクトルサイズより大きい2の冪に整列する[BYTE]. この整列は、CORTEX-M3のアーキテクチャによる要請である  */
    
    .exc_vector ALIGN(256):	/*  例外ベクトル。 */
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
