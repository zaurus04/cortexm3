;******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
;* File Name          : cstart_thum2.asm
;* Author             : MCD Application Team
;* Version            : V2.0.3
;* Date               : 09/22/2008
;* Description        : STM32F10x vector table for HiTOP toolchain. 
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler,
;*                      - Set the vector table entries with the exceptions ISR address,
;*                      - Configure external SRAM mounted on STM3210E-EVAL board
;*                         to be used as data memory (optional, to be enabled by user)
;*                      - Branches to __main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the CortexM3 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;* <<< Use Configuration Wizard in Context Menu >>>   
;*******************************************************************************
; THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
; WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
; AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
; INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
; CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
; INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
;*******************************************************************************

;;  NOTE: To allow the use of this file for both ARMv6M and ARMv7M,
;;        we will only use 16-bit Thumb intructions.

   .extern _lc_ub_stack            ; usr/sys mode stack pointer
   .extern _lc_ue_stack            ; symbol required by debugger
   .extern _lc_ub_table            ; ROM to RAM copy table
   .extern main
   .extern _Exit
;  .global __RESET
   .extern exit
   .weak   exit
   .extern _init_hardware

   .if @defined('__PROF_ENABLE__')
      .extern __prof_init
   .endif
   .if @defined('__POSIX__')
      .extern posix_main
      .extern _posix_boot_stack_top
   .endif

   .global _START

   .section .text.cstart
   .thumb
; If you need to use external SRAM mounted on STM3210E-EVAL board as data memory,
; change the following define value to '1'
; External SRAM Configuration  <0=> DISABLE <1=> ENABLE 

DATA_IN_ExtSRAM  .equ    0

_START:
      ;; anticipate possible ROM/RAM remapping
      ;; by loading the 'real' program address
      ldr     r1,=_Next
      bx      r1
_Next:
      ;; initialize the stack pointer
      ; this is also part of the vector table
      ldr     r1,=_lc_ub_stack
      mov     sp,r1

      ;; call a user function which initializes hardware
      ;; such as ROM/RAM re-mapping or MMU configuration
     bl      _init_hardware
     
             				 
				          .if DATA_IN_ExtSRAM  

; FSMC Bank1 NOR/SRAM3 is used for the STM3210E-EVAL, if another Bank is 
; required, then adjust the Register Addresses


; Enable FSMC clock
				         LDR R0,= 0x00000114 
				         LDR R1,= 0x40021014
				         STR R0,[R1]	                 
                  
; Enable GPIOD, GPIOE, GPIOF and GPIOG clocks
				         LDR R0,= 0x000001E0
				         LDR R1,= 0x40021018
				         STR R0,[R1]	   

; SRAM Data lines, NOE and NWE configuration 
; SRAM Address lines configuration 
; NOE and NWE configuration   
; NE3 configuration 
; NBL0, NBL1 configuration 

				         LDR R0,= 0x44BB44BB 
				         LDR R1,= 0x40011400
				         STR R0,[R1]		
				 
				         LDR R0,= 0xBBBBBBBB 
				         LDR R1,= 0x40011404
				         STR R0,[R1]		
				 
				         LDR R0,= 0xB44444BB 
				         LDR R1,= 0x40011800
				         STR R0,[R1]		
				 
				         LDR R0,= 0xBBBBBBBB 
				         LDR R1,= 0x40011804
				         STR R0,[R1]		
				 
				         LDR R0,= 0x44BBBBBB 
				         LDR R1,= 0x40011C00
				         STR R0,[R1]	    

				         LDR R0,= 0xBBBB4444 
				         LDR R1,= 0x40011C04
				         STR R0,[R1]	    

				         LDR R0,= 0x44BBBBBB
				         LDR R1,= 0x40012000
				         STR R0,[R1]		

				         LDR R0,= 0x44444B44
				         LDR R1,= 0x40012004
				         STR R0,[R1]      
				         
; FSMC Configuration   
; Enable FSMC Bank1_SRAM Bank 

				        LDR R0,= 0x00001011
				        LDR R1,= 0xA0000010
				        STR R0,[R1]	

				        LDR R0,= 0x00000200 
				        LDR R1,= 0xA0000014
				        STR R0,[R1]	

				  		 
				        .endif  


    ;; copy initialized sections from ROM to RAM
      ;; and clear uninitialized data sections in RAM

      ldr     r3,=_lc_ub_table
      movs    r0,#0
cploop:
      ldr     r4,[r3,#0]      ; load type
      ldr     r5,[r3,#4]      ; dst address
      ldr     r6,[r3,#8]      ; src address
      ldr     r7,[r3,#12]     ; size

      cmp     r4,#1
      beq     copy
      cmp     r4,#2
      beq     clear
      b       done

copy:
      subs    r7,r7,#1
      ldrb    r1,[r6,r7]
      strb    r1,[r5,r7]
      bne     copy

      adds    r3,r3,#16
      b       cploop

clear:
      subs    r7,r7,#1
      strb    r0,[r5,r7]
      bne     clear

      adds    r3,r3,#16
      b       cploop

done:
      ;; initialize or copy the vector table

      .if @defined('__POSIX__')

         ;; posix stack buffer for system upbringing
         ldr     r0,=_posix_boot_stack_top
         ldr     r0, [r0]
         mov     sp,r0

      .else

         ;; load r10 with end of USR/SYS stack, which is
         ;; needed in case stack overflow checking is on
         ;; NOTE: use 16-bit instructions only, for ARMv6M
         ldr     r0,=_lc_ue_stack
         mov     r10,r0

      .endif

      .if @defined('__PROF_ENABLE__')
         bl      __prof_init
      .endif

      .if @defined('__POSIX__')
         ;; call posix_main with no arguments
         bl      posix_main
      .else
         ;; call main with argv[0]==NULL & argc==0
         movs     r0,#0
         movs     r1,#0
         bl       main
      .endif

         ;; call exit using the return value from main()
         ;; Note. Calling exit will also run all functions
         ;; that were supplied through atexit().
         bl      exit

      .ltorg
      .endsec

      .calls  '_START','_init_hardware'
      .calls  '_START','_init_vector_table'
      .if @defined('__PROF_ENABLE__')
         .calls  '_START','__prof_init'
      .endif
      .if @defined('__POSIX__')
         .calls  '_START','posix_main'
      .else
         .calls  '_START','main'
      .endif
         .calls  '_START','exit'
         .calls  '_START','',0

      .end
