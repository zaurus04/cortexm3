/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V2.0.3
* Date               : 09/22/2008
* Description        : Description of the USART DMA Polling Example.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

Example description
===================
This example provides a basic communication between USART1 and USART2 using DMA 
capability.

First, the DMA transfers data from TxBuffer2 buffer to USART2 Transmit data 
register, then this data is sent to USART1. Data received by USART1 is transferred
by DMA and stored in RxBuffer1 then compared with the send ones and the result 
of this comparison is stored in the "TransferStatus1" variable.
 
In the same time, the DMA transfers data from TxBuffer1 buffer to USART1 Transmit
data register, then this data is sent to USART2. Data received by USART2 is
transferred by DMA and stored in RxBuffer2 then compared with the send ones and
the result of this comparison is stored in the "TransferStatus2" variable. 

USART1 and USART2 configured as follow:
  - BaudRate = 230400 baud  
  - Word Length = 8 Bits
  - One Stop Bit
  - No parity
  - Hardware flow control disabled (RTS and CTS signals)
  - Receive and transmit enabled
       
        
Directory contents
==================
platform_config.h    Evaluation board specific configuration file
stm32f10x_conf.h     Library Configuration file
stm32f10x_it.h       Interrupt handlers header file
stm32f10x_it.c       Interrupt handlers
main.c               Main program


Hardware environment
====================
This example runs on STMicroelectronics STM3210B-EVAL and STM3210E-EVAL evaluation
boards and can be easily tailored to any other hardware.
To select the STMicroelectronics evaluation board used to run the example, uncomment
the corresponding line in platform_config.h file.

 + STM3210B-EVAL 
    - Connect a null-modem female/female RS232 cable between CN5 and CN6.
    - Note: in this case USART2 Tx and Rx pins are remapped by software on 
            PD.05 and PD.06 respectively. 
 
 + STM3210E-EVAL
    - Connect a null-modem female/female RS232 cable between CN12 and CN8.
  
  
How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_gpio.c
  + stm32f10x_rcc.c
  + stm32f10x_usart.c
  + stm32f10x_nvic.c
  + stm32f10x_dma.c
  + stm32f10x_flash.c
    
- Link all compiled files and load your image into target memory
- Run the example

******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE******
