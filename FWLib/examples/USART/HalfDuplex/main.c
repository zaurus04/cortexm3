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
#include "platform_config.h"

/* Private typedef -----------------------------------------------------------*/
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

/* Private define ------------------------------------------------------------*/
#define TxBufferSize1   (countof(TxBuffer1) - 1)
#define TxBufferSize2   (countof(TxBuffer2) - 1)

/* Private macro -------------------------------------------------------------*/
#define countof(a)   (sizeof(a) / sizeof(*(a)))

/* Private variables ---------------------------------------------------------*/
USART_InitTypeDef USART_InitStructure;
u8 TxBuffer1[] = "USART Half Duplex: USART1 -> USART2 using HalfDuplex mode";
u8 TxBuffer2[] = "USART Half Duplex: USART2 -> USART1 using HalfDuplex mode";
u8 RxBuffer1[TxBufferSize2];
u8 RxBuffer2[TxBufferSize1];
u8 NbrOfDataToRead1 = TxBufferSize2;
u8 NbrOfDataToRead2 = TxBufferSize1;
u8 TxCounter1 = 0, RxCounter1 = 0;
u8 TxCounter2 = 0, RxCounter2 = 0;
volatile TestStatus TransferStatus1 = FAILED, TransferStatus2 = FAILED;  
ErrorStatus HSEStartUpStatus;

/* Private function prototypes -----------------------------------------------*/
void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);
TestStatus Buffercmp(u8* pBuffer1, u8* pBuffer2, u16 BufferLength);
  
/* Private functions ---------------------------------------------------------*/

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

  /* System Clocks Configuration */
  RCC_Configuration();
       
  /* NVIC configuration */
  NVIC_Configuration();

  /* Configure the GPIO ports */
  GPIO_Configuration();

/* USART1 and USART2 configuration ------------------------------------------------------*/
  /* USART1 and USART2 configured as follow:
        - BaudRate = 230400 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled

  */
  USART_InitStructure.USART_BaudRate = 230400;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  /* Configure USART1 */
  USART_Init(USART1, &USART_InitStructure);
  /* Configure USART2 */
  USART_Init(USART2, &USART_InitStructure);
  
  /* Enable the USART1 */
  USART_Cmd(USART1, ENABLE);
  /* Enable the USART2 */
  USART_Cmd(USART2, ENABLE);

  /* Enable USART1 Half Duplex Mode*/
  USART_HalfDuplexCmd(USART1, ENABLE);
  /* Enable USART2 Half Duplex Mode*/
  USART_HalfDuplexCmd(USART2, ENABLE);

  while(NbrOfDataToRead2--)
  {
    /* Wait until end of transmit */
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
    {
    }
    /* Write one byte in the USART1 Transmit Data Register */
    USART_SendData(USART1, TxBuffer1[TxCounter1++]);

    /* Wait the byte is entirtly received by USART2 */  
    while(USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET)
    {
    }
    /* Store the received byte in the RxBuffer2 */
    RxBuffer2[RxCounter2++] = USART_ReceiveData(USART2);
  }

  /* Clear the USART1 Data Register */
  USART_ReceiveData(USART1);

  while(NbrOfDataToRead1--)
  { 
    /* Wait until end of transmit */
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE)== RESET)
    {
    }
    /* Write one byte in the USART2 Transmit Data Register */
    USART_SendData(USART2, TxBuffer2[TxCounter2++]);

    /* Wait the byte is entirtly received by USART1 */
    while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) == RESET)
    {
    }
    /* Store the received byte in the RxBuffer1 */
    RxBuffer1[RxCounter1++] = USART_ReceiveData(USART1);
  }
  
  /* Check the received data with the send ones */
  TransferStatus1 = Buffercmp(TxBuffer1, RxBuffer2, TxBufferSize1);
  /* TransferStatus = PASSED, if the data transmitted from USART1 and  
     received by USART2 are the same */
  /* TransferStatus = FAILED, if the data transmitted from USART1 and 
     received by USART2 are different */
  TransferStatus2 = Buffercmp(TxBuffer2, RxBuffer1, TxBufferSize2);
  /* TransferStatus = PASSED, if the data transmitted from USART2 and  
     received by USART1 are the same */
  /* TransferStatus = FAILED, if the data transmitted from USART2 and 
     received by USART1 are different */

  while (1)
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
    
  /* Enable USART1, GPIOA, GPIOx and AFIO clocks */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOx
                         | RCC_APB2Periph_AFIO, ENABLE);
  /* Enable USART2 clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
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

#ifdef USE_STM3210B_EVAL
  /* Enable the USART2 Pins Software Remapping */
  GPIO_PinRemapConfig(GPIO_Remap_USART2, ENABLE);
#endif

  /* Configure USART1 Tx (PA.09) as alternate function open-drain */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Configure USART2 Tx as alternate function open-drain */
  GPIO_InitStructure.GPIO_Pin = GPIO_TxPin;
  GPIO_Init(GPIOx, &GPIO_InitStructure);
}

/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configures Vector Table base location.
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
