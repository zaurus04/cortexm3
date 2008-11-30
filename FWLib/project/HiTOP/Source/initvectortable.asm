
   .extern _lc_ub_vector_table
   .global _init_vector_table
   .global _Reset_Handler
   .section .text.vector
   .thumb

_init_vector_table:    .type func
 
  .extern  _START
  .extern  _lc_ub_stack  ; imported from scatter file

  ; Import exceptions handlers
  .extern  NMIException
  .extern  HardFaultException
  .extern  MemManageException
  .extern  BusFaultException
  .extern  UsageFaultException
  .extern  SVCHandler
  .extern  DebugMonitor
  .extern  PendSVC
  .extern  SysTickHandler
  .extern  WWDG_IRQHandler
  .extern  PVD_IRQHandler
  .extern  TAMPER_IRQHandler
  .extern  RTC_IRQHandler
  .extern  FLASH_IRQHandler
  .extern  RCC_IRQHandler
  .extern  EXTI0_IRQHandler
  .extern  EXTI1_IRQHandler
  .extern  EXTI2_IRQHandler
  .extern  EXTI3_IRQHandler
  .extern  EXTI4_IRQHandler
  .extern DMA1_Channel1_IRQHandler
  .extern DMA1_Channel2_IRQHandler
  .extern DMA1_Channel3_IRQHandler
  .extern DMA1_Channel4_IRQHandler
  .extern DMA1_Channel5_IRQHandler
  .extern DMA1_Channel6_IRQHandler
  .extern DMA1_Channel7_IRQHandler
  .extern  ADC1_2_IRQHandler
  .extern  USB_HP_CAN_TX_IRQHandler
  .extern  USB_LP_CAN_RX0_IRQHandler
  .extern  CAN_RX1_IRQHandler
  .extern  CAN_SCE_IRQHandler
  .extern  EXTI9_5_IRQHandler
  .extern  TIM1_BRK_IRQHandler
  .extern  TIM1_UP_IRQHandler
  .extern  TIM1_TRG_COM_IRQHandler
  .extern  TIM1_CC_IRQHandler
  .extern  TIM2_IRQHandler
  .extern  TIM3_IRQHandler
  .extern  TIM4_IRQHandler
  .extern  I2C1_EV_IRQHandler
  .extern  I2C1_ER_IRQHandler
  .extern  I2C2_EV_IRQHandler
  .extern  I2C2_ER_IRQHandler
  .extern  SPI1_IRQHandler
  .extern  SPI2_IRQHandler
  .extern  USART1_IRQHandler
  .extern  USART2_IRQHandler
  .extern  USART3_IRQHandler
  .extern  EXTI15_10_IRQHandler
  .extern  RTCAlarm_IRQHandler
  .extern  USBWakeUp_IRQHandler
  .extern  TIM8_BRK_IRQHandler
  .extern  TIM8_UP_IRQHandler
  .extern  TIM8_TRG_COM_IRQHandler
  .extern  TIM8_CC_IRQHandler
  .extern  ADC3_IRQHandler
  .extern  FSMC_IRQHandler
  .extern  SDIO_IRQHandler
  .extern  TIM5_IRQHandler
  .extern  SPI3_IRQHandler
  .extern  UART4_IRQHandler
  .extern  UART5_IRQHandler
  .extern  TIM6_IRQHandler
  .extern  TIM7_IRQHandler
  .extern  DMA2_Channel1_IRQHandler
  .extern  DMA2_Channel2_IRQHandler
  .extern  DMA2_Channel3_IRQHandler
  .extern  DMA2_Channel4_5_IRQHandler
  
;*******************************************************************************
; Fill-up the Vector Table entries with the exceptions ISR address
;*******************************************************************************

   .DW  _lc_ub_stack   ; Top of Stack
   .DW  _START         ;Reset_Handler
   .DW  NMIException
   .DW  HardFaultException
   .DW  MemManageException
   .DW  BusFaultException
   .DW  UsageFaultException
   .DW  0                ; Reserved
   .DW  0                ; Reserved
   .DW  0                ; Reserved
   .DW  0                ; Reserved
   .DW  SVCHandler
   .DW  DebugMonitor
   .DW  0                ; Reserved
   .DW  PendSVC
   .DW  SysTickHandler
   .DW  WWDG_IRQHandler
   .DW  PVD_IRQHandler
   .DW  TAMPER_IRQHandler
   .DW  RTC_IRQHandler
   .DW  FLASH_IRQHandler
   .DW  RCC_IRQHandler
   .DW  EXTI0_IRQHandler
   .DW  EXTI1_IRQHandler
   .DW  EXTI2_IRQHandler
   .DW  EXTI3_IRQHandler
   .DW  EXTI4_IRQHandler
   .DW  DMA1_Channel1_IRQHandler
   .DW  DMA1_Channel2_IRQHandler
   .DW  DMA1_Channel3_IRQHandler
   .DW  DMA1_Channel4_IRQHandler
   .DW  DMA1_Channel5_IRQHandler
   .DW  DMA1_Channel6_IRQHandler
   .DW  DMA1_Channel7_IRQHandler
   .DW  ADC1_2_IRQHandler
   .DW  USB_HP_CAN_TX_IRQHandler
   .DW  USB_LP_CAN_RX0_IRQHandler
   .DW  CAN_RX1_IRQHandler
   .DW  CAN_SCE_IRQHandler
   .DW  EXTI9_5_IRQHandler
   .DW  TIM1_BRK_IRQHandler
   .DW  TIM1_UP_IRQHandler
   .DW TIM1_TRG_COM_IRQHandler
   .DW  TIM1_CC_IRQHandler
   .DW  TIM2_IRQHandler
   .DW  TIM3_IRQHandler
   .DW  TIM4_IRQHandler
   .DW  I2C1_EV_IRQHandler
   .DW  I2C1_ER_IRQHandler
   .DW  I2C2_EV_IRQHandler
   .DW  I2C2_ER_IRQHandler
   .DW  SPI1_IRQHandler
   .DW  SPI2_IRQHandler
   .DW  USART1_IRQHandler
   .DW  USART2_IRQHandler
   .DW  USART3_IRQHandler
   .DW  EXTI15_10_IRQHandler
   .DW  RTCAlarm_IRQHandler
   .DW  USBWakeUp_IRQHandler
   .DW TIM8_BRK_IRQHandler
   .DW TIM8_UP_IRQHandler
   .DW TIM8_TRG_COM_IRQHandler
   .DW TIM8_CC_IRQHandler
   .DW ADC3_IRQHandler
   .DW FSMC_IRQHandler
   .DW SDIO_IRQHandler
   .DW TIM5_IRQHandler
   .DW SPI3_IRQHandler
   .DW UART4_IRQHandler
   .DW UART5_IRQHandler
   .DW TIM6_IRQHandler
   .DW TIM7_IRQHandler
   .DW DMA2_Channel1_IRQHandler
   .DW DMA2_Channel2_IRQHandler
   .DW DMA2_Channel3_IRQHandler
   .DW DMA2_Channel4_5_IRQHandler 
   
   .size   _init_vector_table,$-_init_vector_table
   .endsec
   
   .section .text.cstart
   .align 4
_Reset_Handler:
   ; Branch to C entry point
   bl      _START

init_fail:
   b      _START

   .size   _Reset_Handler,$-_Reset_Handler
   .endsec

   .calls  '_Reset_Handler','',0
   .calls  '_init_vector_table','',0

   .end
