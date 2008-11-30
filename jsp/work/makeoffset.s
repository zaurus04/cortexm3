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
	.file	"makeoffset.c"
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.text
.Ltext0:
	.align	2
	.global	makeoffset
	.thumb
	.thumb_func
	.type	makeoffset, %function
makeoffset:
.LFB28:
	.file 1 "../config/armv7m/makeoffset.c"
	.loc 1 62 0
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	@ lr needed for prologue
	.loc 1 63 0
	OFFSET_DEF TCB_texptn = #16
	.loc 1 64 0
	OFFSET_DEF TCB_sp = #24
	.loc 1 65 0
	OFFSET_DEF TCB_pc = #28
	.loc 1 66 0
	.thumb
	bx	lr
.LFE28:
	.size	makeoffset, .-makeoffset
	.global	BIT_REF_4
	.global	BIT_REF_2
	.global	BIT_REF_1
	.global	BIT_BB_TCB_enatex
	.data
	.align	2
	.type	BIT_REF_4, %object
	.size	BIT_REF_4, 4
BIT_REF_4:
	.word	305419896
	.type	BIT_REF_2, %object
	.size	BIT_REF_2, 2
BIT_REF_2:
	.short	4660
	.type	BIT_REF_1, %object
	.size	BIT_REF_1, 1
BIT_REF_1:
	.byte	18
	.space	1
	.type	BIT_BB_TCB_enatex, %object
	.size	BIT_BB_TCB_enatex, 32
BIT_BB_TCB_enatex:
	.word	0
	.word	0
	.word	0
	.byte	0
	.byte	0
	.byte	4
	.space	1
	.word	0
	.word	0
	.word	0
	.word	0
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
	.4byte	.LFB28
	.4byte	.LFE28-.LFB28
	.align	2
.LEFDE0:
	.text
.Letext0:
	.file 2 "../include/itron.h"
	.file 3 "c:\\cygwin\\usr\\local\\arm\\bin\\../lib/gcc/arm-none-eabi/4.2.3/include/stddef.h"
	.file 4 "../include/kernel.h"
	.file 5 "../config/armv7m/cpu_config.h"
	.file 6 "../kernel/queue.h"
	.file 7 "../kernel/time_event.h"
	.file 8 "../kernel/task.h"
	.section	.debug_info
	.4byte	0x3f7
	.2byte	0x2
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF57
	.byte	0x1
	.4byte	.LASF58
	.4byte	.LASF59
	.4byte	.Ltext0
	.4byte	.Letext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x3
	.4byte	.LASF2
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
	.uleb128 0x5
	.ascii	"UB\000"
	.byte	0x2
	.byte	0x61
	.4byte	0x4f
	.uleb128 0x4
	.byte	0x1
	.byte	0x8
	.4byte	.LASF3
	.uleb128 0x4
	.byte	0x1
	.byte	0x8
	.4byte	.LASF4
	.uleb128 0x4
	.byte	0x2
	.byte	0x5
	.4byte	.LASF5
	.uleb128 0x5
	.ascii	"UH\000"
	.byte	0x2
	.byte	0x67
	.4byte	0x6e
	.uleb128 0x4
	.byte	0x2
	.byte	0x7
	.4byte	.LASF6
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
	.4byte	0x97
	.uleb128 0x6
	.byte	0x4
	.uleb128 0x5
	.ascii	"FP\000"
	.byte	0x2
	.byte	0x76
	.4byte	0xa3
	.uleb128 0x7
	.byte	0x4
	.4byte	0xa9
	.uleb128 0x8
	.4byte	0xb0
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
	.4byte	0xb0
	.uleb128 0x5
	.ascii	"ATR\000"
	.byte	0x2
	.byte	0x80
	.4byte	0xbb
	.uleb128 0x3
	.4byte	.LASF10
	.byte	0x2
	.byte	0x84
	.4byte	0x2c
	.uleb128 0x3
	.4byte	.LASF11
	.byte	0x2
	.byte	0x88
	.4byte	0x75
	.uleb128 0x3
	.4byte	.LASF12
	.byte	0x2
	.byte	0x8d
	.4byte	0x8d
	.uleb128 0xa
	.byte	0x4
	.byte	0x7
	.uleb128 0x3
	.4byte	.LASF13
	.byte	0x4
	.byte	0x65
	.4byte	0xbb
	.uleb128 0xb
	.4byte	.LASF15
	.byte	0x8
	.byte	0x5
	.byte	0x56
	.4byte	0x131
	.uleb128 0xc
	.ascii	"sp\000"
	.byte	0x5
	.byte	0x57
	.4byte	0x8d
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xc
	.ascii	"pc\000"
	.byte	0x5
	.byte	0x58
	.4byte	0x99
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x3
	.4byte	.LASF14
	.byte	0x5
	.byte	0x59
	.4byte	0x10a
	.uleb128 0xb
	.4byte	.LASF16
	.byte	0x4
	.byte	0x5
	.byte	0xc0
	.4byte	0x157
	.uleb128 0xd
	.4byte	.LASF17
	.byte	0x5
	.byte	0xc1
	.4byte	0x99
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x3
	.4byte	.LASF18
	.byte	0x5
	.byte	0xc2
	.4byte	0x13c
	.uleb128 0xb
	.4byte	.LASF19
	.byte	0x8
	.byte	0x6
	.byte	0x38
	.4byte	0x18b
	.uleb128 0xd
	.4byte	.LASF20
	.byte	0x6
	.byte	0x39
	.4byte	0x18b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF21
	.byte	0x6
	.byte	0x3a
	.4byte	0x18b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x7
	.byte	0x4
	.4byte	0x162
	.uleb128 0x3
	.4byte	.LASF22
	.byte	0x6
	.byte	0x3b
	.4byte	0x162
	.uleb128 0x3
	.4byte	.LASF23
	.byte	0x7
	.byte	0x40
	.4byte	0x1a7
	.uleb128 0x7
	.byte	0x4
	.4byte	0x1ad
	.uleb128 0xe
	.byte	0x1
	.4byte	0x1b9
	.uleb128 0xf
	.4byte	0x8d
	.byte	0x0
	.uleb128 0xb
	.4byte	.LASF24
	.byte	0xc
	.byte	0x7
	.byte	0x42
	.4byte	0x1f0
	.uleb128 0xd
	.4byte	.LASF25
	.byte	0x7
	.byte	0x43
	.4byte	0xbb
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF26
	.byte	0x7
	.byte	0x44
	.4byte	0x19c
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xc
	.ascii	"arg\000"
	.byte	0x7
	.byte	0x45
	.4byte	0x8d
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0x3
	.4byte	.LASF27
	.byte	0x7
	.byte	0x46
	.4byte	0x1b9
	.uleb128 0x7
	.byte	0x4
	.4byte	0x1f0
	.uleb128 0x10
	.4byte	.LASF60
	.byte	0x4
	.byte	0x8
	.byte	0x82
	.4byte	0x224
	.uleb128 0x11
	.4byte	.LASF28
	.byte	0x8
	.byte	0x83
	.4byte	0xc6
	.uleb128 0x11
	.4byte	.LASF29
	.byte	0x8
	.byte	0x84
	.4byte	0x1fb
	.byte	0x0
	.uleb128 0x3
	.4byte	.LASF30
	.byte	0x8
	.byte	0x85
	.4byte	0x201
	.uleb128 0xb
	.4byte	.LASF31
	.byte	0x20
	.byte	0x8
	.byte	0x94
	.4byte	0x2ac
	.uleb128 0xd
	.4byte	.LASF32
	.byte	0x8
	.byte	0x95
	.4byte	0xd0
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF33
	.byte	0x8
	.byte	0x96
	.4byte	0xf1
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xd
	.4byte	.LASF34
	.byte	0x8
	.byte	0x97
	.4byte	0x99
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0xd
	.4byte	.LASF35
	.byte	0x8
	.byte	0x98
	.4byte	0xbb
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0xd
	.4byte	.LASF36
	.byte	0x8
	.byte	0x99
	.4byte	0xdb
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0xc
	.ascii	"stk\000"
	.byte	0x8
	.byte	0x9a
	.4byte	0x8d
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0xd
	.4byte	.LASF37
	.byte	0x8
	.byte	0x9c
	.4byte	0xd0
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0xd
	.4byte	.LASF38
	.byte	0x8
	.byte	0x9d
	.4byte	0x99
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.byte	0x0
	.uleb128 0x3
	.4byte	.LASF39
	.byte	0x8
	.byte	0x9e
	.4byte	0x22f
	.uleb128 0xb
	.4byte	.LASF40
	.byte	0x20
	.byte	0x8
	.byte	0xb7
	.4byte	0x35f
	.uleb128 0xd
	.4byte	.LASF41
	.byte	0x8
	.byte	0xb8
	.4byte	0x191
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xd
	.4byte	.LASF42
	.byte	0x8
	.byte	0xb9
	.4byte	0x35f
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.4byte	.LASF43
	.byte	0x8
	.byte	0xbb
	.4byte	0x37
	.byte	0x4
	.byte	0x8
	.byte	0x18
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.4byte	.LASF44
	.byte	0x8
	.byte	0xbc
	.4byte	0x37
	.byte	0x4
	.byte	0x8
	.byte	0x10
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.4byte	.LASF45
	.byte	0x8
	.byte	0xbe
	.4byte	0x37
	.byte	0x4
	.byte	0x1
	.byte	0xf
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.4byte	.LASF46
	.byte	0x8
	.byte	0xbf
	.4byte	0x37
	.byte	0x4
	.byte	0x1
	.byte	0xe
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.4byte	.LASF47
	.byte	0x8
	.byte	0xc0
	.4byte	0x37
	.byte	0x4
	.byte	0x1
	.byte	0xd
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0xd
	.4byte	.LASF48
	.byte	0x8
	.byte	0xc2
	.4byte	0xff
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0xd
	.4byte	.LASF49
	.byte	0x8
	.byte	0xc3
	.4byte	0x36a
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0xd
	.4byte	.LASF50
	.byte	0x8
	.byte	0xc4
	.4byte	0x131
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.byte	0x0
	.uleb128 0x7
	.byte	0x4
	.4byte	0x365
	.uleb128 0x13
	.4byte	0x2ac
	.uleb128 0x7
	.byte	0x4
	.4byte	0x224
	.uleb128 0x5
	.ascii	"TCB\000"
	.byte	0x8
	.byte	0xc5
	.4byte	0x2b7
	.uleb128 0x14
	.byte	0x1
	.4byte	.LASF61
	.byte	0x1
	.byte	0x3e
	.4byte	.LFB28
	.4byte	.LFE28
	.byte	0x1
	.byte	0x5d
	.uleb128 0x15
	.4byte	0x157
	.4byte	0x398
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x17
	.4byte	.LASF51
	.byte	0x5
	.byte	0xc4
	.4byte	0x38d
	.byte	0x1
	.byte	0x1
	.uleb128 0x17
	.4byte	.LASF52
	.byte	0x7
	.byte	0x65
	.4byte	0xe6
	.byte	0x1
	.byte	0x1
	.uleb128 0x18
	.4byte	.LASF53
	.byte	0x1
	.byte	0x44
	.4byte	0x75
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.4byte	BIT_REF_4
	.uleb128 0x18
	.4byte	.LASF54
	.byte	0x1
	.byte	0x45
	.4byte	0x64
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.4byte	BIT_REF_2
	.uleb128 0x18
	.4byte	.LASF55
	.byte	0x1
	.byte	0x46
	.4byte	0x45
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.4byte	BIT_REF_1
	.uleb128 0x18
	.4byte	.LASF56
	.byte	0x1
	.byte	0x48
	.4byte	0x370
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.4byte	BIT_BB_TCB_enatex
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
	.uleb128 0x18
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
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,"",%progbits
	.4byte	0x5d
	.2byte	0x2
	.4byte	.Ldebug_info0
	.4byte	0x3fb
	.4byte	0x37b
	.ascii	"makeoffset\000"
	.4byte	0x3b2
	.ascii	"BIT_REF_4\000"
	.4byte	0x3c4
	.ascii	"BIT_REF_2\000"
	.4byte	0x3d6
	.ascii	"BIT_REF_1\000"
	.4byte	0x3e8
	.ascii	"BIT_BB_TCB_enatex\000"
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
.LASF10:
	.ascii	"SIZE\000"
.LASF14:
	.ascii	"CTXB\000"
.LASF28:
	.ascii	"wercd\000"
.LASF58:
	.ascii	"../config/armv7m/makeoffset.c\000"
.LASF2:
	.ascii	"size_t\000"
.LASF53:
	.ascii	"BIT_REF_4\000"
.LASF12:
	.ascii	"VP_INT\000"
.LASF41:
	.ascii	"task_queue\000"
.LASF29:
	.ascii	"tmevtb\000"
.LASF48:
	.ascii	"texptn\000"
.LASF42:
	.ascii	"tinib\000"
.LASF34:
	.ascii	"task\000"
.LASF39:
	.ascii	"TINIB\000"
.LASF57:
	.ascii	"GNU C 4.2.3\000"
.LASF33:
	.ascii	"exinf\000"
.LASF59:
	.ascii	"C:\\cygwin\\home\\develop\\CortexM3\\jsp\\work\000"
.LASF5:
	.ascii	"short int\000"
.LASF25:
	.ascii	"index\000"
.LASF15:
	.ascii	"task_context_block\000"
.LASF32:
	.ascii	"tskatr\000"
.LASF40:
	.ascii	"task_control_block\000"
.LASF60:
	.ascii	"waiting_information\000"
.LASF23:
	.ascii	"CBACK\000"
.LASF7:
	.ascii	"long long int\000"
.LASF50:
	.ascii	"tskctxb\000"
.LASF47:
	.ascii	"enatex\000"
.LASF51:
	.ascii	"_kernel_exception_vector\000"
.LASF9:
	.ascii	"UINT\000"
.LASF61:
	.ascii	"makeoffset\000"
.LASF46:
	.ascii	"wupcnt\000"
.LASF49:
	.ascii	"winfo\000"
.LASF19:
	.ascii	"queue\000"
.LASF30:
	.ascii	"WINFO\000"
.LASF22:
	.ascii	"QUEUE\000"
.LASF17:
	.ascii	"exchdr\000"
.LASF3:
	.ascii	"unsigned char\000"
.LASF1:
	.ascii	"signed char\000"
.LASF8:
	.ascii	"long long unsigned int\000"
.LASF11:
	.ascii	"SYSTIM\000"
.LASF0:
	.ascii	"unsigned int\000"
.LASF6:
	.ascii	"short unsigned int\000"
.LASF4:
	.ascii	"char\000"
.LASF44:
	.ascii	"priority\000"
.LASF18:
	.ascii	"EXCVE\000"
.LASF56:
	.ascii	"BIT_BB_TCB_enatex\000"
.LASF16:
	.ascii	"exc_vector_entry\000"
.LASF13:
	.ascii	"TEXPTN\000"
.LASF37:
	.ascii	"texatr\000"
.LASF36:
	.ascii	"stksz\000"
.LASF38:
	.ascii	"texrtn\000"
.LASF35:
	.ascii	"ipriority\000"
.LASF45:
	.ascii	"actcnt\000"
.LASF52:
	.ascii	"_kernel_next_time\000"
.LASF31:
	.ascii	"task_initialization_block\000"
.LASF27:
	.ascii	"TMEVTB\000"
.LASF24:
	.ascii	"time_event_block\000"
.LASF55:
	.ascii	"BIT_REF_1\000"
.LASF54:
	.ascii	"BIT_REF_2\000"
.LASF21:
	.ascii	"prev\000"
.LASF43:
	.ascii	"tstat\000"
.LASF20:
	.ascii	"next\000"
.LASF26:
	.ascii	"callback\000"
	.ident	"GCC: (Sourcery G++ Lite 2008q1-126) 4.2.3"
