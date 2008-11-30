;******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
;* File Name          : cortexm3_macro.asm
;* Author             : MCD Application Team
;* Version            : V2.0.3
;* Date               : 09/22/2008
;* Description        : Instruction wrappers for special Cortex-M3 instructions
;*                      to be used with HiTOP toolchain.
;*******************************************************************************
; THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
; WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
; AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
; INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
; CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
; INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
;*******************************************************************************

   .define __WORKAROUND "1"

   .section .text
   .thumb
   .align 2

   ; global functions
   .global __WFI
   .global __WFE
   .global __SEV
   .global __ISB
   .global __DSB
   .global __DMB
   .global __SVC
   .global __MRS_CONTROL
   .global __MSR_CONTROL
   .global __MRS_PSP
   .global __MSR_PSP
   .global __MRS_MSP
   .global __MSR_MSP 
   .global __RESETPRIMASK   
   .global __SETPRIMASK
   .global __READ_PRIMASK
   .global __RESETFAULTMASK
   .global __SETFAULTMASK
   .global __READ_FAULTMASK
   .global __BASEPRICONFIG
   .global __GetBASEPRI
   .global __REV_HalfWord
   .global __REV_Word 

;*******************************************************************************
; Function Name  : __WFI
; Description    : Assembler function for the WFI instruction.
; Input          : None
; Return         : None
;*******************************************************************************
__WFI       .type func

      WFI
      BX r14
   .size __WFI,$-__WFI
;*******************************************************************************
; Function Name  : __WFE
; Description    : Assembler function for the WFE instruction.
; Input          : None
; Return         : None
;*******************************************************************************
__WFE:      .type func

      WFE
      BX r14
   .size __WFE,$-__WFE
;*******************************************************************************
; Function Name  : __SEV
; Description    : Assembler function for the SEV instruction.
; Input          : None
; Return         : None
;*******************************************************************************
__SEV:      .type func

      SEV
      BX r14
   .size __SEV,$-__SEV
;*******************************************************************************
; Function Name  : __ISB
; Description    : Assembler function for the ISB instruction.
; Input          : None
; Return         : None
;*******************************************************************************
__ISB:      .type func

      .if @defined('__WORKAROUND')
         isb     sy
      .else
         isb
      .endif
   .size __ISB,$-__ISB
;*******************************************************************************
; Function Name  : __DSB
; Description    : Assembler function for the DSB instruction.
; Input          : None
; Return         : None
;*******************************************************************************
__DSB:      .type func

      .if @defined('__WORKAROUND')
         dsb     sy
      .else
         dsb
      .endif
   .size __DSB,$-__DSB
;*******************************************************************************
; Function Name  : __DMB
; Description    : Assembler function for the DMB instruction.
; Input          : None
; Return         : None
;*******************************************************************************
__DMB:      .type func

      .if @defined('__WORKAROUND')
         dmb     sy
      .else
         dmb
      .endif
   .size __DMB,$-__DMB
;*******************************************************************************
; Function Name  : __SVC
; Description    : Assembler function for the SVC instruction.
; Input          : None
; Return         : None
;*******************************************************************************
__SVC:      .type func

      SVC 0x01
      BX r14
   .size __SVC,$-__SVC
;*******************************************************************************
; Function Name  : __MRS_CONTROL
; Description    : Assembler function for the MRS instruction.
; Input          : None
; Return         : - r4 : Cortex-M3 CONTROL register value.
;*******************************************************************************
__MRS_CONTROL: .type func

      MRS r4, CONTROL
      BX r14
   .size __MRS_CONTROL,$-__MRS_CONTROL
;*******************************************************************************
; Function Name  : __MSR_CONTROL
; Description    : Assembler function for the MSR instruction.
; Input          : - R0 : Cortex-M3 CONTROL register new value.
; Return         : None
;*******************************************************************************
__MSR_CONTROL:      .type func

      MSR CONTROL, r0
      BX r14
   .size __MSR_CONTROL,$-__MSR_CONTROL
;*******************************************************************************
; Function Name  : __MRS_PSP
; Description    : Assembler function for the MRS instruction.
; Input          : None
; Return         : - r0 : Process Stack value.
;*******************************************************************************
__MRS_PSP          .type func

    MRS r0, PSP
    BX r14
  .size __MRS_PSP,$-__MRS_PSP 

;*******************************************************************************
; Function Name  : __MSR_PSP
; Description    : Assembler function for the MSR instruction.
; Input          : - r0 : Process Stack new value.  
; Return         : None
;*******************************************************************************
__MSR_PSP          .type func
 
     MSR PSP, r0 ; set Process Stack value
     BX r14
  .size __MSR_PSP,$-__MSR_PSP 

;*******************************************************************************
; Function Name  : __MRS_MSP
; Description    : Assembler function for the MRS instruction.
; Input          : None
; Return         : - r0 : Main Stack value.
;*******************************************************************************
__MRS_MSP          .type func

    MRS r0, MSP
    BX r14
  .size __MRS_MSP,$-__MRS_MSP

;*******************************************************************************
; Function Name  : __MSR_MSP
; Description    : Assembler function for the MSR instruction.
; Input          : - r0 : Main Stack new value.  
; Return         : None
;*******************************************************************************
__MSR_MSP         .type func
 
    MSR MSP, r0 ; set Main Stack value
    BX r14
  .size __MSR_MSP,$-__MSR_MSP 
            
;*******************************************************************************
; Function Name  : __RESETPRIMASK
; Description    : Assembler function to reset the PRIMASK.
; Input          : None
; Return         : None
;*******************************************************************************
__RESETPRIMASK:      .type func

      CPSIE i
      BX r14
   .size __RESETPRIMASK,$-__RESETPRIMASK
;*******************************************************************************
; Function Name  : __SETPRIMASK
; Description    : Assembler function to set the PRIMASK.
; Input          : None
; Return         : None
;*******************************************************************************
__SETPRIMASK:      .type func

      CPSID i
      BX r14
   .size __SETPRIMASK,$-__SETPRIMASK
;*******************************************************************************
; Function Name  : __READ_PRIMASK
; Description    : Assembler function to get the PRIMASK value.
; Input          : None
; Return         : - r0 : PRIMASK register value 
;*******************************************************************************
__READ_PRIMASK      .type func
 
    MRS r0, PRIMASK
   BX r14
  
  .size __READ_PRIMASK,$-__READ_PRIMASK
  
;*******************************************************************************
; Function Name  : __RESETFAULTMASK
; Description    : Assembler function to reset the FAULTMASK.
; Input          : None 
; Return         : None
;*******************************************************************************
__RESETFAULTMASK   .type func

   CPSIE f
   BX r14
  .size __RESETFAULTMASK ,$-__RESETFAULTMASK 
  
;*******************************************************************************
; Function Name  : __SETFAULTMASK
; Description    : Assembler function to set the FAULTMASK.
; Input          : None
; Return         : None
;*******************************************************************************
__SETFAULTMASK:      .type func

      CPSID f
      BX r14
   .size __SETFAULTMASK,$-__SETFAULTMASK
;*******************************************************************************
; Function Name  : __READ_FAULTMASK
; Description    : Assembler function to get the FAULTMASK value.
; Input          : None
; Return         : - r0 : FAULTMASK register value 
;*******************************************************************************
__READ_FAULTMASK    .type func
 
  MRS r0, FAULTMASK
  BX r14  
 .size __READ_FAULTMASK,$-__READ_FAULTMASK
;*******************************************************************************
; Function Name  : __BASEPRICONFIG
; Description    : Assembler function to set the Base Priority.
; Input          : - R0 : Base Priority new value
; Return         : None
;*******************************************************************************
__BASEPRICONFIG:      .type func

      MSR BASEPRI, r0
      BX r14
   .size __BASEPRICONFIG,$-__BASEPRICONFIG
;*******************************************************************************
; Function Name  : __GetBASEPRI
; Description    : Assembler function to get the Base Priority value.
; Input          : None
; Return         : - r4 : Base Priority value
;*******************************************************************************
__GetBASEPRI:      .type func

      MRS r4, BASEPRI_MAX
      BX r14
   .size __GetBASEPRI,$-__GetBASEPRI
;*******************************************************************************
; Function Name  : __REV_HalfWord
; Description    : Reverses the byte order in HalfWord(16-bit) input variable.
; Input          : - r0 : specifies the input variable
; Return         : - r0 : holds tve variable value after byte reversing.
;*******************************************************************************
__REV_HalfWord:      .type func

      REV16 r0, r0
      BX r14
   .size __REV_HalfWord,$-__REV_HalfWord
  
;*******************************************************************************
; Function Name  : __REV_Word
; Description    : Reverses the byte order in Word(32-bit) input variable.
; Input          : - r0 : specifies the input variable
; Return         : - r0 : holds tve variable value after byte reversing.e
;*******************************************************************************
__REV_Word:      .type func

      REV r0, r0
      BX r14
   .size __REV_Word,$-__REV_Word
      
   .endsec

   .calls '__WFI','',0
   .calls '__WFE','',0
   .calls '__SEV','',0
   .calls '__ISB','',0
   .calls '__DSB','',0
   .calls '__DMB','',0
   .calls '__SVC','',0
   .calls '__MRS_CONTROL','',0
   .calls '__MSR_CONTROL','',0
   .calls '__MRS_PSP','',0
   .calls '__MSR_PSP','',0
   .calls '__MRS_MSP','',0
   .calls '__MSR_MSP','',0 
   .calls '__RESETPRIMASK','',0 
   .calls '__SETPRIMASK','',0
   .calls '__READ_PRIMASK','',0
   .calls '__RESETFAULTMASK','',0
   .calls '__SETFAULTMASK','',0
   .calls '__READ_FAULTMASK','',0
   .calls '__BASEPRICONFIG','',0
   .calls '__GetBASEPRI','',0
   .calls '__REV_HalfWord','',0
   .calls '__REV_Word','',0
   


   .end

;******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE*****
