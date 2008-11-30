/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : main.c
* Author             : MCD Application Team
* Version            : V2.0.3
* Date               : 09/22/2008
* Description        : Main program body
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
#include "main.h"


/* Private typedef -----------------------------------------------------------*/
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

/* Private define ------------------------------------------------------------*/
#define I2C1_SLAVE_ADDRESS7     0x30
#define ClockSpeed              200000

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
I2C_InitTypeDef   I2C_InitStructure;
NVIC_InitTypeDef  NVIC_InitStructure;

u8 I2C1_Buffer_Tx[Tx1BufferSize] = {1,2,3,4}, I2C2_Buffer_Tx[Tx2BufferSize] = {5,6,7,8};
u8 I2C1_Buffer_Rx[Tx2BufferSize], I2C2_Buffer_Rx[Tx1BufferSize+1];
vu8 Tx1_Idx = 0, Rx1_Idx = 0, Tx2_Idx = 0, Rx2_Idx = 0;
vu8 Direction = Transmitter;
volatile TestStatus TransferStatus1 = FAILED, TransferStatus2 = FAILED;
ErrorStatus HSEStartUpStatus;
    
/* Private functions ---------------------------------------------------------*/
void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);
TestStatus Buffercmp(u8* pBuffer1, u8* pBuffer2, u16 BufferLength);

/*******************************************************************************
* Function Name  : main
* Description    : Main program
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int main(void)
{
#ifdef DEBUG
  debug();
#endif

  /* System clocks configuration ---------------------------------------------*/
  RCC_Configuration();

  /* NVIC configuration ------------------------------------------------------*/
  NVIC_Configuration();

  /* GPIO configuration ------------------------------------------------------*/
  GPIO_Configuration();

  /* Enable I2C1 and I2C2 ----------------------------------------------------*/
  I2C_Cmd(I2C1, ENABLE);
  I2C_Cmd(I2C2, ENABLE);

  /* I2C1 configuration ------------------------------------------------------*/
  I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
  I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
  I2C_InitStructure.I2C_OwnAddress1 = I2C1_SLAVE_ADDRESS7;
  I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStructure.I2C_ClockSpeed = ClockSpeed;
  I2C_Init(I2C1, &I2C_InitStructure);
  /* I2C2 configuration ------------------------------------------------------*/
  I2C_InitStructure.I2C_OwnAddress1 = I2C2_SLAVE_ADDRESS7;
  I2C_Init(I2C2, &I2C_InitStructure);

  I2C_CalculatePEC(I2C1, ENABLE);  
  I2C_CalculatePEC(I2C2, ENABLE);  
  
  /* Enable I2C1 event and buffer interrupts */
  I2C_ITConfig(I2C1, I2C_IT_EVT | I2C_IT_BUF, ENABLE);
  /* Enable I2C1 event and buffer interrupts */
  I2C_ITConfig(I2C2, I2C_IT_EVT | I2C_IT_BUF, ENABLE);
  
  /*----- Transmission Phase -------------------------------------------------*/
  /* Set data direction to transmitter */
  Direction = Transmitter;
  /* Send I2C1 START condition */
  I2C_GenerateSTART(I2C1, ENABLE);

  /* Wait until all data and the PEC value are received */
  /* I2C2_Buffer_Rx buffer will contain the data plus the PEC value */
  while(Rx2_Idx < Tx1BufferSize)
  {
  }
  
  /* Check the corectness of the I2C1 transmitted data */
  TransferStatus1 = Buffercmp(I2C1_Buffer_Tx, I2C2_Buffer_Rx, Tx1BufferSize);
  /* TransferStatus1 = PASSED, if the transmitted and received data
     are equal */
  /* TransferStatus1 = FAILED, if the transmitted and received data 
     are different */
     

  /*----- Reception Phase --------------------------------------------------*/
  /* Re-configure and enable I2C1 event interrupt to have the higher priority */
  NVIC_InitStructure.NVIC_IRQChannel = I2C1_EV_IRQChannel;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
 
 
  /* Wait until end of Slave transmission */
  while(Rx1_Idx < Tx2BufferSize)
  {
  }

  /* Check the corectness of the I2C1 received data */
  TransferStatus2 = Buffercmp(I2C2_Buffer_Tx, I2C1_Buffer_Rx, Tx2BufferSize);
  /* TransferStatus2 = PASSED, if the transmitted and received data
     are equal */
  /* TransferStatus2 = FAILED, if the transmitted and received data 
     are different */
   
  while(1)
  {
  }
}

/*******************************************************************************
* Function Name  : RCC_Configuration
* Description    : Configures the different system clocks.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RCC_Configuration(void)
{
  /* RCC system reset(for debug purpose) */
  RCC_DeInit();

  /* Enable HSE */
  RCC_HSEConfig(RCC_HSE_ON);

  /* Wait till HSE is ready */
  HSEStartUpStatus = RCC_WaitForHSEStartUp();

  if(HSEStartUpStatus == SUCCESS)
  {
    /* Enable Prefetch Buffer */
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

    /* Flash 2 wait state */
    FLASH_SetLatency(FLASH_Latency_2);
 
    /* HCLK = SYSCLK */
    RCC_HCLKConfig(RCC_SYSCLK_Div1); 
  
    /* PCLK2 = HCLK */
    RCC_PCLK2Config(RCC_HCLK_Div1); 

    /* PCLK1 = HCLK/2 */
    RCC_PCLK1Config(RCC_HCLK_Div2);
 
    /* PLLCLK = 8MHz * 9 = 72 MHz */
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);

    /* Enable PLL */ 
    RCC_PLLCmd(ENABLE);

    /* Wait till PLL is ready */
    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
    {
    }

    /* Select PLL as system clock source */
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

    /* Wait till PLL is used as system clock source */
    while(RCC_GetSYSCLKSource() != 0x08)
    {
    }
  }

/* Enable peripheral clocks --------------------------------------------------*/
  /* Enable I2C1 and I2C2 clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1 | RCC_APB1Periph_I2C2, ENABLE);
  /* Enable GPIOB clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
}

/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : Configures the different GPIO ports.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Configure I2C1 pins: SCL and SDA ----------------------------------------*/
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Configure I2C2 pins: SCL and SDA ----------------------------------------*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configures NVIC and Vector Table base location.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_Configuration(void)
{ 
#ifdef  VECT_TAB_RAM  
  /* Set the Vector Table base location at 0x20000000 */ 
  NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0); 
#else  /* VECT_TAB_FLASH  */
  /* Set the Vector Table base location at 0x08000000 */ 
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);   
#endif

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
  
  /* Configure and enable I2C1 event interrupt -------------------------------*/
  NVIC_InitStructure.NVIC_IRQChannel = I2C1_EV_IRQChannel;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  /* Configure and enable I2C2 event interrupt -------------------------------*/  
  NVIC_InitStructure.NVIC_IRQChannel = I2C2_EV_IRQChannel;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_Init(&NVIC_InitStructure);

  /* Configure and enable I2C2 error interrupt -------------------------------*/  
  NVIC_InitStructure.NVIC_IRQChannel = I2C2_ER_IRQChannel;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
* Function Name  : Buffercmp
* Description    : Compares two buffers.
* Input          : - pBuffer1, pBuffer2: buffers to be compared.
*                : - BufferLength: buffer's length
* Output         : None
* Return         : PASSED: pBuffer1 identical to pBuffer2
*                  FAILED: pBuffer1 differs from pBuffer2
*******************************************************************************/
TestStatus Buffercmp(u8* pBuffer1, u8* pBuffer2, u16 BufferLength)
{
  while(BufferLength--)
  {
    if(*pBuffer1 != *pBuffer2)
    {
      return FAILED;
    }
    
    pBuffer1++;
    pBuffer2++;
  }

  return PASSED;  
}

#ifdef  DEBUG
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
