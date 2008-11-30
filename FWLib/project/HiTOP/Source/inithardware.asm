; hardware uinitialization if required

   .section .text.librt
      .if @thumb()
         .thumb
      .else
         .arm
      .endif

; default (empty) init_hardware
      .global _init_hardware
_init_hardware:      .type func
         bx      lr

      .size   _init_hardware,$-_init_hardware
   .endsec

   .calls  '_init_hardware','',0

   .end
