/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : readme.txt
* Author             : MCD Application Team
* Version            : V2.0.3
* Date               : 09/22/2008
* Description        : This sub-directory contains all the user-modifiable files 
*                      needed to create a new project linked with the STM32F10x  
*                      Firmware Library and working with HiTOP for ARM  software
                       toolchain (version 5.30)
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

1) STM3210E-EVAL: contains the workspace and all specific folders for project
                  for STM32 High-density devices.

2) STM3210B-EVAL: contains the workspace and all specific folders for project
                  for STM32 Medium-density devices.

 Both of the above directories have the following architecture:                  
                    
- project .htp: A pre-configured project file with the provided library 
                structure that produces an executable image
                with HiTOP.

- objects: This directory will contain the executable images. 

- Settings: This directory contains the linker and script files.

             * STM32F10x.lsl: This file is the HiTOP specific linking and loading 
                              file used to load in FLASH and execute code and variables 
                              to target memories and regions. 
                              You can customize this file to your need.

             * StartupScript.scr: this script resets the target before loading 
                                  the executable image. 


3) Source: This directory includes the needed files for hardware initialization:          
             
              * cstart_thumb2.asm: This file contains the Stack and Heap definition.
                                   User can also enable the use of external SRAM 
                                   mounted on STM3210E-EVAL board as data memory.

              * initvectortable.asm: STM32F10x vector table.

              * cortexm3_macro.asm: Instruction wrappers for special Cortex-M3 
                                    instructions.

              * inithardware.asm: ensure hardware initialization the if required.            
     
How to use it
=============
- Open the HiTOP toolchain, a "using projects in HiTOP" window appears.
- Select open an existing project.
- Open the project.htp.
- Rebuild all files: Project->Rebuild all
- Click on ok in the "download project" window.
- Run program: Debug->Go(F5).

* When using High-density devices, it is mandatory to reset the target before loading the project into  target
* It is recommended to run the reset script ( click on TR button in the toolbar menu)
 after loading the project into target. 



NOTE:
 - Medium-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 32 and 128 Kbytes.
 - High-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 256 and 512 Kbytes.    

******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE******
