	.syntax unified
	.arch armv7m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 18, 4
	.thumb
	.file	"kernel_chk.c"
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.text
.Ltext0:
	.align	2
	.global	checker_function
	.thumb
	.thumb_func
	.type	checker_function, %function
checker_function:
.LFB29:
	.file 1 "kernel_chk.c"
	.loc 1 27 0
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	@ lr needed for prologue
	.loc 1 28 0
	sTMAX_TPRI,(#16),(0)@
	.loc 1 29 0
	sTMIN_TPRI,(#1),(0)@
	.loc 1 31 0
	sTMAX_MPRI,(#16),(0)@
	.loc 1 32 0
	sTMIN_MPRI,(#1),(0)@
	.loc 1 34 0
	sTMAX_RELTIM,(#2147483647),(0)@
	.loc 1 36 0
	squeue::next,(#4),(#0)@
	.loc 1 37 0
	squeue::prev,(#4),(#4)@
	.loc 1 42 0
	dtask_5,LOGTASK@
	.loc 1 43 0
	dtask_4,MAIN_TASK@
	.loc 1 44 0
	dtask_1,TASK1@
	.loc 1 45 0
	dtask_2,TASK2@
	.loc 1 46 0
	dtask_3,TASK3@
	.loc 1 47 0
	s_kernel_tmax_tskid,(#4),(0)@
	.loc 1 48 0
	s_kernel_tinib_table,(#32),(0)@
	.loc 1 49 0
	stask_initialization_block::tskatr,(#4),(#0)@
	.loc 1 50 0
	stask_initialization_block::exinf,(#4),(#4)@
	.loc 1 51 0
	stask_initialization_block::task,(#4),(#8)@
	.loc 1 52 0
	stask_initialization_block::ipriority,(#4),(#12)@
	.loc 1 53 0
	stask_initialization_block::stksz,(#4),(#16)@
	.loc 1 54 0
	stask_initialization_block::stk,(#4),(#20)@
	.loc 1 55 0
	stask_initialization_block::texatr,(#4),(#24)@
	.loc 1 56 0
	stask_initialization_block::texrtn,(#4),(#28)@
	.loc 1 61 0
	dsemaphore_1,SERIAL_RCV_SEM1@
	.loc 1 62 0
	dsemaphore_2,SERIAL_SND_SEM1@
	.loc 1 63 0
	s_kernel_tmax_semid,(#4),(0)@
	.loc 1 64 0
	s_kernel_seminib_table,(#12),(0)@
	.loc 1 65 0
	ssemaphore_initialization_block::sematr,(#4),(#0)@
	.loc 1 66 0
	ssemaphore_initialization_block::isemcnt,(#4),(#4)@
	.loc 1 67 0
	ssemaphore_initialization_block::maxsem,(#4),(#8)@
	.loc 1 72 0
	s_kernel_tmax_flgid,(#4),(0)@
	.loc 1 73 0
	s_kernel_flginib_table,(#8),(0)@
	.loc 1 74 0
	seventflag_initialization_block::flgatr,(#4),(#0)@
	.loc 1 75 0
	seventflag_initialization_block::iflgptn,(#4),(#4)@
	.loc 1 80 0
	s_kernel_tmax_dtqid,(#4),(0)@
	.loc 1 81 0
	s_kernel_dtqinib_table,(#12),(0)@
	.loc 1 82 0
	sdataqueue_initialization_block::dtqatr,(#4),(#0)@
	.loc 1 83 0
	sdataqueue_initialization_block::dtqcnt,(#4),(#4)@
	.loc 1 84 0
	sdataqueue_initialization_block::dtq,(#4),(#8)@
	.loc 1 89 0
	s_kernel_tmax_mbxid,(#4),(0)@
	.loc 1 90 0
	s_kernel_mbxinib_table,(#8),(0)@
	.loc 1 91 0
	smailbox_initialization_block::mbxatr,(#4),(#0)@
	.loc 1 92 0
	smailbox_initialization_block::maxmpri,(#4),(#4)@
	.loc 1 97 0
	s_kernel_tmax_mpfid,(#4),(0)@
	.loc 1 98 0
	s_kernel_mpfinib_table,(#16),(0)@
	.loc 1 99 0
	sfixed_memorypool_initialization_block::mpfatr,(#4),(#0)@
	.loc 1 100 0
	sfixed_memorypool_initialization_block::blksz,(#4),(#4)@
	.loc 1 101 0
	sfixed_memorypool_initialization_block::mpf,(#4),(#8)@
	.loc 1 102 0
	sfixed_memorypool_initialization_block::limit,(#4),(#12)@
	.loc 1 107 0
	dcyclic_1,CYCHDR1@
	.loc 1 108 0
	s_kernel_tmax_cycid,(#4),(0)@
	.loc 1 109 0
	s_kernel_cycinib_table,(#20),(0)@
	.loc 1 110 0
	scyclic_handler_initialization_block::cycatr,(#4),(#0)@
	.loc 1 111 0
	scyclic_handler_initialization_block::exinf,(#4),(#4)@
	.loc 1 112 0
	scyclic_handler_initialization_block::cychdr,(#4),(#8)@
	.loc 1 113 0
	scyclic_handler_initialization_block::cyctim,(#4),(#12)@
	.loc 1 114 0
	scyclic_handler_initialization_block::cycphs,(#4),(#16)@
	.loc 1 119 0
	dinterrupt_0,0@
	.loc 1 120 0
	dinterrupt_1,1@
	.loc 1 121 0
	s_kernel_tnum_inhno,(#4),(0)@
	.loc 1 122 0
	s_kernel_inhinib_table,(#12),(0)@
	.loc 1 123 0
	sinterrupt_handler_initialization_block::inhno,(#4),(#0)@
	.loc 1 124 0
	sinterrupt_handler_initialization_block::inhatr,(#4),(#4)@
	.loc 1 125 0
	sinterrupt_handler_initialization_block::inthdr,(#4),(#8)@
	.loc 1 130 0
	s_kernel_tnum_excno,(#4),(0)@
	.loc 1 131 0
	s_kernel_excinib_table,(#12),(0)@
	.loc 1 132 0
	scpu_exception_handler_initialization_block::excno,(#4),(#0)@
	.loc 1 133 0
	scpu_exception_handler_initialization_block::excatr,(#4),(#4)@
	.loc 1 134 0
	scpu_exception_handler_initialization_block::exchdr,(#4),(#8)@
	.loc 1 136 0
	.thumb
	bx	lr
.LFE29:
	.size	checker_function, .-checker_function
	.section	.debug_frame,"",%progbits
.Lframe0:
	.4byte	.LECIE0-.LSCIE0
.LSCIE0:
	.4byte	0xffffffff
	.byte	0x1
	.ascii	"\000"
	.uleb128 0x1
	.sleb128 -4
	.byte	0xe
	.byte	0xc
	.uleb128 0xd
	.uleb128 0x0
	.align	2
.LECIE0:
.LSFDE0:
	.4byte	.LEFDE0-.LASFDE0
.LASFDE0:
	.4byte	.Lframe0
	.4byte	.LFB29
	.4byte	.LFE29-.LFB29
	.align	2
.LEFDE0:
	.text
.Letext0:
	.file 2 "../include/itron.h"
	.file 3 "c:\\cygwin\\usr\\local\\arm\\bin\\../lib/gcc/arm-none-eabi/4.2.3/include/stddef.h"
	.file 4 "../config/armv7m/cpu_defs.h"
	.file 5 "../include/kernel.h"
	.file 6 "../config/armv7m/cpu_config.h"
	.file 7 "../kernel/queue.h"
	.file 8 "../kernel/time_event.h"
	.file 9 "../kernel/task.h"
	.file 10 "../kernel/semaphore.h"
	.file 11 "../kernel/eventflag.h"
	.file 12 "../kernel/dataqueue.h"
	.file 13 "../kernel/mailbox.h"
	.file 14 "../kernel/mempfix.h"
	.file 15 "../kernel/cyclic.h"
	.file 16 "../kernel/exception.h"
	.file 17 "../kernel/interrupt.h"
	.section	.debug_info
	.4byte	0x5ac
	.2byte	0x2
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF87
	.byte	0x1
	.4byte	.LASF88
	.4byte	.LASF89
	.4byte	.Ltext0
	.4byte	.Letext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x3
	.4byte	.LASF6
	.byte	0x3
	.byte	0xd6
	.4byte	0x37
	.uleb128 0x4
	.byte	0x4
	.byte	0x7
	.4byte	.LASF0
	.uleb128 0x4
	.byte	0x1
	.byte	0x6
	.4byte	.LASF1
	.uleb128 0x4
	.byte	0x1
	.byte	0x8
	.4byte	.LASF2
	.uleb128 0x4
	.byte	0x1
	.byte	0x8
	.4byte	.LASF3
	.uleb128 0x4
	.byte	0x2
	.byte	0x5
	.4byte	.LASF4
	.uleb128 0x4
	.byte	0x2
	.byte	0x7
	.4byte	.LASF5
	.uleb128 0x5
	.ascii	"UW\000"
	.byte	0x2
	.byte	0x6c
	.4byte	0x37
	.uleb128 0x4
	.byte	0x8
	.byte	0x5
	.4byte	.LASF7
	.uleb128 0x4
	.byte	0x8
	.byte	0x7
	.4byte	.LASF8
	.uleb128 0x5
	.ascii	"VP\000"
	.byte	0x2
	.byte	0x75
	.4byte	0x83
	.uleb128 0x6
	.byte	0x4
	.uleb128 0x5
	.ascii	"FP\000"
	.byte	0x2
	.byte	0x76
	.4byte	0x8f
	.uleb128 0x7
	.byte	0x4
	.4byte	0x95
	.uleb128 0x8
	.4byte	0x9c
	.uleb128 0x9
	.byte	0x0
	.uleb128 0x5
	.ascii	"INT\000"
	.byte	0x2
	.byte	0x78
	.4byte	0x25
	.uleb128 0x3
	.4byte	.LASF9
	.byte	0x2
	.byte	0x79
	.4byte	0x37
	.uleb128 0x5
	.ascii	"ER\000"
	.byte	0x2
	.byte	0x7e
	.4byte	0x9c
	.uleb128 0x5
	.ascii	"ATR\000"
	.byte	0x2
	.byte	0x80
	.4byte	0xa7
	.uleb128 0x5
	.ascii	"PRI\000"
	.byte	0x2
	.byte	0x83
	.4byte	0x9c
	.uleb128 0x3
	.4byte	.LASF10
	.byte	0x2
	.byte	0x84
	.4byte	0x2c
	.uleb128 0x3
	.4byte	.LASF11
	.byte	0x2
	.byte	0x87
	.4byte	0xa7
	.uleb128 0x3
	.4byte	.LASF12
	.byte	0x2
	.byte	0x88
	.4byte	0x61
	.uleb128 0x3
	.4byte	.LASF13
	.byte	0x2
	.byte	0x8d
	.4byte	0x79
	.uleb128 0x3
	.4byte	.LASF14
	.byte	0x4
	.byte	0x3e
	.4byte	0xa7
	.uleb128 0x3
	.4byte	.LASF15
	.byte	0x4
	.byte	0x3f
	.4byte	0xa7
	.uleb128 0xa
	.byte	0x4
	.byte	0x7
	.uleb128 0x3
	.4byte	.LASF16
	.byte	0x5
	.byte	0x65
	.4byte	0xa7
	.uleb128 0x3
	.4byte	.LASF17
	.byte	0x5
	.byte	0x66
	.4byte	0xa7
	.uleb128 0xb
	.4byte	.LASF19
	.byte	0x8
	.byte	0x6
	.byte	0x56
	.4byte	0x154
	.uleb128 0xc
	.ascii	"sp\000"
	.byte	0x6
	.byte	0x57
	.4byte	0x79
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xc
	.ascii	"pc\000"
	.byte	0x6
	.byte	0x58
	.4byte	0x85
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x3
	.4byte	.LASF18
	.byte	0x6
	.byte	0x59
	.4byte	0x12d
	.uleb128 0xb
	.4byte	.LASF20
	.byte	0x4
	.byte	0x6
	.byte	0xc0
	.4byte	0x17a
	.uleb128 0xd
	.4byte	.LASF21
	.byte	0x6
	.byte	0xc1
	.4byte	0x85
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x3
	.4byte	.LASF22
	.byte	0x6
	.byte	0xc2
	.4byte	0x15f
	.uleb128 0xb
	.4byte	.LASF23
	.byte	0x8
	.byte	0x7
	.byte	0x38
	.4byte	0x1ae
	.uleb128 0xd
	.4byte	.LASF24
	.byte	0x7
	.byte	0x39
	.4byte	0x1ae
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF25
	.byte	0x7
	.byte	0x3a
	.4byte	0x1ae
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x7
	.byte	0x4
	.4byte	0x185
	.uleb128 0x3
	.4byte	.LASF26
	.byte	0x7
	.byte	0x3b
	.4byte	0x185
	.uleb128 0x3
	.4byte	.LASF27
	.byte	0x8
	.byte	0x40
	.4byte	0x1ca
	.uleb128 0x7
	.byte	0x4
	.4byte	0x1d0
	.uleb128 0xe
	.byte	0x1
	.4byte	0x1dc
	.uleb128 0xf
	.4byte	0x79
	.byte	0x0
	.uleb128 0xb
	.4byte	.LASF28
	.byte	0xc
	.byte	0x8
	.byte	0x42
	.4byte	0x213
	.uleb128 0xd
	.4byte	.LASF29
	.byte	0x8
	.byte	0x43
	.4byte	0xa7
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF30
	.byte	0x8
	.byte	0x44
	.4byte	0x1bf
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xc
	.ascii	"arg\000"
	.byte	0x8
	.byte	0x45
	.4byte	0x79
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0x3
	.4byte	.LASF31
	.byte	0x8
	.byte	0x46
	.4byte	0x1dc
	.uleb128 0x7
	.byte	0x4
	.4byte	0x213
	.uleb128 0x10
	.4byte	.LASF90
	.byte	0x4
	.byte	0x9
	.byte	0x82
	.4byte	0x247
	.uleb128 0x11
	.4byte	.LASF32
	.byte	0x9
	.byte	0x83
	.4byte	0xb2
	.uleb128 0x11
	.4byte	.LASF33
	.byte	0x9
	.byte	0x84
	.4byte	0x21e
	.byte	0x0
	.uleb128 0x3
	.4byte	.LASF34
	.byte	0x9
	.byte	0x85
	.4byte	0x224
	.uleb128 0xb
	.4byte	.LASF35
	.byte	0x20
	.byte	0x9
	.byte	0x94
	.4byte	0x2cf
	.uleb128 0xd
	.4byte	.LASF36
	.byte	0x9
	.byte	0x95
	.4byte	0xbc
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF37
	.byte	0x9
	.byte	0x96
	.4byte	0xf3
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xd
	.4byte	.LASF38
	.byte	0x9
	.byte	0x97
	.4byte	0x85
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0xd
	.4byte	.LASF39
	.byte	0x9
	.byte	0x98
	.4byte	0xa7
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0xd
	.4byte	.LASF40
	.byte	0x9
	.byte	0x99
	.4byte	0xd2
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0xc
	.ascii	"stk\000"
	.byte	0x9
	.byte	0x9a
	.4byte	0x79
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0xd
	.4byte	.LASF41
	.byte	0x9
	.byte	0x9c
	.4byte	0xbc
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0xd
	.4byte	.LASF42
	.byte	0x9
	.byte	0x9d
	.4byte	0x85
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.byte	0x0
	.uleb128 0x3
	.4byte	.LASF43
	.byte	0x9
	.byte	0x9e
	.4byte	0x252
	.uleb128 0xb
	.4byte	.LASF44
	.byte	0x20
	.byte	0x9
	.byte	0xb7
	.4byte	0x382
	.uleb128 0xd
	.4byte	.LASF45
	.byte	0x9
	.byte	0xb8
	.4byte	0x1b4
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF46
	.byte	0x9
	.byte	0xb9
	.4byte	0x382
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.4byte	.LASF47
	.byte	0x9
	.byte	0xbb
	.4byte	0x37
	.byte	0x4
	.byte	0x8
	.byte	0x18
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.4byte	.LASF48
	.byte	0x9
	.byte	0xbc
	.4byte	0x37
	.byte	0x4
	.byte	0x8
	.byte	0x10
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.4byte	.LASF49
	.byte	0x9
	.byte	0xbe
	.4byte	0x37
	.byte	0x4
	.byte	0x1
	.byte	0xf
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.4byte	.LASF50
	.byte	0x9
	.byte	0xbf
	.4byte	0x37
	.byte	0x4
	.byte	0x1
	.byte	0xe
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.4byte	.LASF51
	.byte	0x9
	.byte	0xc0
	.4byte	0x37
	.byte	0x4
	.byte	0x1
	.byte	0xd
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0xd
	.4byte	.LASF52
	.byte	0x9
	.byte	0xc2
	.4byte	0x117
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0xd
	.4byte	.LASF53
	.byte	0x9
	.byte	0xc3
	.4byte	0x38d
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0xd
	.4byte	.LASF54
	.byte	0x9
	.byte	0xc4
	.4byte	0x154
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.byte	0x0
	.uleb128 0x7
	.byte	0x4
	.4byte	0x388
	.uleb128 0x13
	.4byte	0x2cf
	.uleb128 0x7
	.byte	0x4
	.4byte	0x247
	.uleb128 0x5
	.ascii	"TCB\000"
	.byte	0x9
	.byte	0xc5
	.4byte	0x2da
	.uleb128 0xb
	.4byte	.LASF55
	.byte	0xc
	.byte	0xa
	.byte	0x33
	.4byte	0x3d5
	.uleb128 0xd
	.4byte	.LASF56
	.byte	0xa
	.byte	0x34
	.4byte	0xbc
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF57
	.byte	0xa
	.byte	0x35
	.4byte	0xa7
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xd
	.4byte	.LASF58
	.byte	0xa
	.byte	0x36
	.4byte	0xa7
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0xb
	.4byte	.LASF59
	.byte	0x8
	.byte	0xb
	.byte	0x33
	.4byte	0x3fe
	.uleb128 0xd
	.4byte	.LASF60
	.byte	0xb
	.byte	0x34
	.4byte	0xbc
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF61
	.byte	0xb
	.byte	0x35
	.4byte	0x122
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0xb
	.4byte	.LASF62
	.byte	0xc
	.byte	0xc
	.byte	0x33
	.4byte	0x435
	.uleb128 0xd
	.4byte	.LASF63
	.byte	0xc
	.byte	0x34
	.4byte	0xbc
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF64
	.byte	0xc
	.byte	0x35
	.4byte	0xa7
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xc
	.ascii	"dtq\000"
	.byte	0xc
	.byte	0x36
	.4byte	0x79
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0xb
	.4byte	.LASF65
	.byte	0x8
	.byte	0xd
	.byte	0x33
	.4byte	0x45e
	.uleb128 0xd
	.4byte	.LASF66
	.byte	0xd
	.byte	0x34
	.4byte	0xbc
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF67
	.byte	0xd
	.byte	0x35
	.4byte	0xc7
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0xb
	.4byte	.LASF68
	.byte	0x10
	.byte	0xe
	.byte	0x33
	.4byte	0x4a3
	.uleb128 0xd
	.4byte	.LASF69
	.byte	0xe
	.byte	0x34
	.4byte	0xbc
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF70
	.byte	0xe
	.byte	0x35
	.4byte	0xa7
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xc
	.ascii	"mpf\000"
	.byte	0xe
	.byte	0x36
	.4byte	0x79
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0xd
	.4byte	.LASF71
	.byte	0xe
	.byte	0x37
	.4byte	0x79
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.byte	0x0
	.uleb128 0xb
	.4byte	.LASF72
	.byte	0x14
	.byte	0xf
	.byte	0x34
	.4byte	0x4f6
	.uleb128 0xd
	.4byte	.LASF73
	.byte	0xf
	.byte	0x35
	.4byte	0xbc
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF37
	.byte	0xf
	.byte	0x36
	.4byte	0xf3
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xd
	.4byte	.LASF74
	.byte	0xf
	.byte	0x37
	.4byte	0x85
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0xd
	.4byte	.LASF75
	.byte	0xf
	.byte	0x38
	.4byte	0xdd
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0xd
	.4byte	.LASF76
	.byte	0xf
	.byte	0x39
	.4byte	0xdd
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.byte	0x0
	.uleb128 0xb
	.4byte	.LASF77
	.byte	0xc
	.byte	0x10
	.byte	0x31
	.4byte	0x52d
	.uleb128 0xd
	.4byte	.LASF78
	.byte	0x10
	.byte	0x32
	.4byte	0x109
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF79
	.byte	0x10
	.byte	0x33
	.4byte	0xbc
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xd
	.4byte	.LASF21
	.byte	0x10
	.byte	0x34
	.4byte	0x85
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0xb
	.4byte	.LASF80
	.byte	0xc
	.byte	0x11
	.byte	0x31
	.4byte	0x564
	.uleb128 0xd
	.4byte	.LASF81
	.byte	0x11
	.byte	0x32
	.4byte	0xfe
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF82
	.byte	0x11
	.byte	0x33
	.4byte	0xbc
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xd
	.4byte	.LASF83
	.byte	0x11
	.byte	0x34
	.4byte	0x85
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0x14
	.byte	0x1
	.4byte	.LASF91
	.byte	0x1
	.byte	0x1b
	.byte	0x1
	.4byte	.LFB29
	.4byte	.LFE29
	.byte	0x1
	.byte	0x5d
	.uleb128 0x15
	.4byte	0x17a
	.4byte	0x582
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x17
	.4byte	.LASF84
	.byte	0x6
	.byte	0xc4
	.4byte	0x577
	.byte	0x1
	.byte	0x1
	.uleb128 0x17
	.4byte	.LASF85
	.byte	0x8
	.byte	0x65
	.4byte	0xe8
	.byte	0x1
	.byte	0x1
	.uleb128 0x17
	.4byte	.LASF86
	.byte	0x9
	.byte	0xd0
	.4byte	0x5a9
	.byte	0x1
	.byte	0x1
	.uleb128 0x7
	.byte	0x4
	.4byte	0x393
	.byte	0x0
	.section	.debug_abbrev
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0x0
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0x0
	.byte	0x0
	.uleb128 0x5
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x7
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x9
	.uleb128 0x18
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0xa
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0xb
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xc
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0xd
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0xe
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xf
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x10
	.uleb128 0x17
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x11
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x12
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0xd
	.uleb128 0xb
	.uleb128 0xc
	.uleb128 0xb
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x13
	.uleb128 0x26
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x14
	.uleb128 0x2e
	.byte	0x0
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x15
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x16
	.uleb128 0x21
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x17
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,"",%progbits
	.4byte	0x23
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x5b0
	.4byte	0x564
	.ascii	"checker_function\000"
	.4byte	0x0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0x0
	.2byte	0x0
	.2byte	0x0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0x0
	.4byte	0x0
	.section	.debug_str,"MS",%progbits,1
.LASF27:
	.ascii	"CBACK\000"
.LASF47:
	.ascii	"tstat\000"
.LASF6:
	.ascii	"size_t\000"
.LASF32:
	.ascii	"wercd\000"
.LASF62:
	.ascii	"dataqueue_initialization_block\000"
.LASF52:
	.ascii	"texptn\000"
.LASF25:
	.ascii	"prev\000"
.LASF80:
	.ascii	"interrupt_handler_initialization_block\000"
.LASF8:
	.ascii	"long long unsigned int\000"
.LASF51:
	.ascii	"enatex\000"
.LASF71:
	.ascii	"limit\000"
.LASF10:
	.ascii	"SIZE\000"
.LASF24:
	.ascii	"next\000"
.LASF58:
	.ascii	"maxsem\000"
.LASF65:
	.ascii	"mailbox_initialization_block\000"
.LASF14:
	.ascii	"INHNO\000"
.LASF7:
	.ascii	"long long int\000"
.LASF1:
	.ascii	"signed char\000"
.LASF57:
	.ascii	"isemcnt\000"
.LASF63:
	.ascii	"dtqatr\000"
.LASF70:
	.ascii	"blksz\000"
.LASF21:
	.ascii	"exchdr\000"
.LASF72:
	.ascii	"cyclic_handler_initialization_block\000"
.LASF46:
	.ascii	"tinib\000"
.LASF39:
	.ascii	"ipriority\000"
.LASF23:
	.ascii	"queue\000"
.LASF49:
	.ascii	"actcnt\000"
.LASF42:
	.ascii	"texrtn\000"
.LASF74:
	.ascii	"cychdr\000"
.LASF40:
	.ascii	"stksz\000"
.LASF67:
	.ascii	"maxmpri\000"
.LASF0:
	.ascii	"unsigned int\000"
.LASF41:
	.ascii	"texatr\000"
.LASF9:
	.ascii	"UINT\000"
.LASF77:
	.ascii	"cpu_exception_handler_initialization_block\000"
.LASF34:
	.ascii	"WINFO\000"
.LASF86:
	.ascii	"_kernel_runtsk\000"
.LASF5:
	.ascii	"short unsigned int\000"
.LASF37:
	.ascii	"exinf\000"
.LASF30:
	.ascii	"callback\000"
.LASF48:
	.ascii	"priority\000"
.LASF15:
	.ascii	"EXCNO\000"
.LASF56:
	.ascii	"sematr\000"
.LASF12:
	.ascii	"SYSTIM\000"
.LASF22:
	.ascii	"EXCVE\000"
.LASF87:
	.ascii	"GNU C 4.2.3\000"
.LASF59:
	.ascii	"eventflag_initialization_block\000"
.LASF82:
	.ascii	"inhatr\000"
.LASF11:
	.ascii	"RELTIM\000"
.LASF78:
	.ascii	"excno\000"
.LASF89:
	.ascii	"C:\\cygwin\\home\\develop\\CortexM3\\jsp\\work\000"
.LASF85:
	.ascii	"_kernel_next_time\000"
.LASF79:
	.ascii	"excatr\000"
.LASF36:
	.ascii	"tskatr\000"
.LASF84:
	.ascii	"_kernel_exception_vector\000"
.LASF16:
	.ascii	"TEXPTN\000"
.LASF28:
	.ascii	"time_event_block\000"
.LASF18:
	.ascii	"CTXB\000"
.LASF31:
	.ascii	"TMEVTB\000"
.LASF55:
	.ascii	"semaphore_initialization_block\000"
.LASF33:
	.ascii	"tmevtb\000"
.LASF73:
	.ascii	"cycatr\000"
.LASF2:
	.ascii	"unsigned char\000"
.LASF4:
	.ascii	"short int\000"
.LASF91:
	.ascii	"checker_function\000"
.LASF81:
	.ascii	"inhno\000"
.LASF60:
	.ascii	"flgatr\000"
.LASF53:
	.ascii	"winfo\000"
.LASF75:
	.ascii	"cyctim\000"
.LASF3:
	.ascii	"char\000"
.LASF69:
	.ascii	"mpfatr\000"
.LASF29:
	.ascii	"index\000"
.LASF13:
	.ascii	"VP_INT\000"
.LASF50:
	.ascii	"wupcnt\000"
.LASF38:
	.ascii	"task\000"
.LASF83:
	.ascii	"inthdr\000"
.LASF20:
	.ascii	"exc_vector_entry\000"
.LASF43:
	.ascii	"TINIB\000"
.LASF26:
	.ascii	"QUEUE\000"
.LASF44:
	.ascii	"task_control_block\000"
.LASF45:
	.ascii	"task_queue\000"
.LASF61:
	.ascii	"iflgptn\000"
.LASF90:
	.ascii	"waiting_information\000"
.LASF19:
	.ascii	"task_context_block\000"
.LASF64:
	.ascii	"dtqcnt\000"
.LASF76:
	.ascii	"cycphs\000"
.LASF88:
	.ascii	"kernel_chk.c\000"
.LASF54:
	.ascii	"tskctxb\000"
.LASF68:
	.ascii	"fixed_memorypool_initialization_block\000"
.LASF17:
	.ascii	"FLGPTN\000"
.LASF35:
	.ascii	"task_initialization_block\000"
.LASF66:
	.ascii	"mbxatr\000"
	.ident	"GCC: (Sourcery G++ Lite 2008q1-126) 4.2.3"
