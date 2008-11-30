/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V2.0.3
* Date               : 09/22/2008
* Description        : This sub-directory contains all the user-modifiable files 
*                      needed to create a new project linked with the STM32F10x  
*                      Firmware Library and working with RIDE7 software toolchain 
*                      (RIDE7 IDE:7.02.0001, RKitARM for RIDE7:1.04.0001)
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

Directory contents
===================
- project .rprj/.rapp: A pre-configured project file with the provided library 
                       structure that produces an executable image with RIDE7.
                
- stm32f10x_vector.c: This file contains the vector table for STM32F10x.
                      User can also enable the use of external SRAM mounted on 
                      STM3210E-EVAL board as data memory.
                      
- cortexm3_macro.s: Instruction wrappers for special Cortex-M3 instructions. 

      
How to use it
=============
- Open the Project.rprj project.
- In the configuration toolbar(Project->properties) select the project config:
   - STM3210B-EVAL: to configure the project for STM32 Medium-density devices
   - STM3210E-EVAL: to configure the project for STM32 High-density devices
- Rebuild all files: Project->build project
- Load project image: Debug->start(ctrl+D)
- Run program: Debug->Run(ctrl+F9)  

NOTE:
 - Medium-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 32 and 128 Kbytes.
 - High-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 256 and 512 Kbytes. 

******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE******
