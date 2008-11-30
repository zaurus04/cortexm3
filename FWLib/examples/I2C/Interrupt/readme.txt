/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V2.0.3
* Date               : 09/22/2008
* Description        : Description of the I2C interrupt mode example.
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
This example provides a description of how to manage data transfer from 
master transmitter to slave receiver and from slave transmitter to master receiver 
using interrupts.

After enabling the two I2C peripherals, both event and buffer interrupts for 
I2C1 and I2C2 and error interrupt for I2C2, the transfer in 7-bit addressing 
mode starts after I2C1 start condition generation.

First, the master transmitter I2C1 send I2C1_Buffer_Tx data buffer to the 
salve receiver I2C2. Data received by I2C2 is stored in I2C2_Buffer_Rx buffer.
Each time an event occurs on the master or the slave, it is managed in the I2C1 
or I2C2 interrupts routines, respectively. 
The PEC value is also transmitted from master transmitter to slave receiver and 
it is stored in the same reception buffer I2C2_Buffer_Rx.
The transmitted and received buffers are compared to check that all data have 
been correctly transferred (except the PEC value). This transfer status is stored 
in TransferStatus1 variable.

Once the Re-Start condition is sent, thus the second step is started and the 
I2C2_Buffer_Tx will be sent from the slave transmitter I2C2 to be recieved by 
the master receiver I2C1 and stored in I2C1_Buffer_Rx. 
Each time an event occurs on the master or the slave, it is managed in the I2C1 
or I2C2 interrupts routines, respectively. 
The transmitted and received buffers are compared to check that all data have been 
correctly transferred. This transfer status is stored in TransferStatus2 variable.

The communication clock speed is set to 200KHz.


Directory contents
==================
stm32f10x_conf.h  Library Configuration file
stm32f10x_it.c    Interrupt handlers
stm32f10x_it.h    Interrupt handlers header file
main.h            Main header file
main.c            Main program


Hardware environment
====================
This example runs on STMicroelectronics STM3210B-EVAL and STM3210E-EVAL evaluation
boards and can be easily tailored to any other hardware.

 - Connect I2C1 SCL pin (PB.06) to I2C2 SCL pin (PB.10)
 - Connect I2C1 SDA pin (PB.07) to I2C2 SDA pin	(PB.11)
 - Check that a pull-up resistor is connected on one I2C SDA pin
 - Check that a pull-up resistor is connected on one I2C SCL pin

Note: The pull-up resitors are already implemented on the STM3210B-EVAL and
      STM3210E-EVAL evaluation boards.


How to use it
=============
In order to make the program work, you must do the following :
- Create a project and setup all your toolchain's start-up files
- Compile the directory content files and required Library files :
  + stm32f10x_lib.c
  + stm32f10x_i2c.c
  + stm32f10x_rcc.c
  + stm32f10x_nvic.c
  + stm32f10x_gpio.c
  + stm32f10x_flash.c
    
- Link all compiled files and load your image into target memory
- Run the example


******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE******
