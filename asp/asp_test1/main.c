/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : main.c
* Author             : MCD Application Team
* Version            : V2.0.2
* Date               : 07/11/2008
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
#include "string.h"
#include "stm32f10x_lib.h"
#include "platform_config.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define TxBufferSize   (countof(TxBuffer) - 1)
#define RxBufferSize   0xFF
#define ADC1_DR_Address    ((u32)0x4001244C)

/* Private macro -------------------------------------------------------------*/
#define countof(a)   (sizeof(a) / sizeof(*(a)))

/* Private variables ---------------------------------------------------------*/
ADC_InitTypeDef ADC_InitStructure;
vu32 ADC_DualConvertedValueTab[16];

USART_InitTypeDef USART_InitStructure;
u8 TxBuffer[] = "\n\rUSART Hyperterminal ADConverter Example: USART - \
Hyperterminal communication using hardware flow control\n\r";
u8 RxBuffer[RxBufferSize];
u8 NbrOfDataToTransfer = TxBufferSize;
u8 TxCounter = 0;
u8 RxCounter = 0;

DMA_InitTypeDef DMA_InitStructure;
vu16 ADCConvertedValue;
ErrorStatus HSEStartUpStatus;



/* Private function prototypes -----------------------------------------------*/
void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);

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
  /* define local values */
  u16 DataValue = 0x0;
  u16 Keta = 0;
  u16 cnt = 0;  // counter
  u32 wcnt = 0; // counter for wait
  u16 Temperature = 0 ;
  u8  a, b, c, d;

#ifdef DEBUG
  debug();
#endif

  /* System Clocks Configuration */
  RCC_Configuration();

  /* NVIC configuration */
  NVIC_Configuration();

  /* Configure the GPIO ports */
  GPIO_Configuration();             // ADCópÇÃGPIOÇÃê›íËÇÕÇµÇ»Ç≠ÇƒÇ¢Ç¢ÇÊÇÀÅB


/* USART2 configuration ------------------------------------------------------*/
  /* USART2 configured as follow:
        - BaudRate = 115200 baud
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control enabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No ;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_RTS_CTS;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART2, &USART_InitStructure);
  /* Enable the USART2 */
  USART_Cmd(USART2, ENABLE);

  /* ADC1 configuration ------------------------------------------------------*/
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfChannel = 1;
  ADC_Init(ADC1, &ADC_InitStructure);
  /* ADC1 regular channels configuration */
  ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 1, ADC_SampleTime_239Cycles5);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_17, 2, ADC_SampleTime_239Cycles5);
  /* Enable ADC1 DMA */
//  ADC_DMACmd(ADC1, ENABLE);
  /* Enable Vrefint channel17 */
  ADC_TempSensorVrefintCmd(ENABLE);
  /* Enable ADC1 */
  ADC_Cmd(ADC1, ENABLE);


  /* Enable ADC1 reset calibaration register */
  ADC_ResetCalibration(ADC1);
  /* Check the end of ADC1 reset calibration register */
  while(ADC_GetResetCalibrationStatus(ADC1));
  /* Start ADC1 calibaration */
  ADC_StartCalibration(ADC1);
  /* Check the end of ADC1 calibration */
  while(ADC_GetCalibrationStatus(ADC1));

  /* Start ADC1 Software Conversion */
  ADC_SoftwareStartConvCmd(ADC1, ENABLE);

  /* Test on DMA1 channel1 transfer complete flag */
  //while(!DMA_GetFlagStatus(DMA1_FLAG_TC1));
  /* Clear DMA1 channel1 transfer complete flag */
  //DMA_ClearFlag(DMA1_FLAG_TC1);



  /*  DEBUG MARKER */
  /* ************* */

  /* Turn on led connected to PC.06 pin */
  //GPIO_SetBits(GPIOC, GPIO_Pin_6);
  /* Turn off led connected to PC.06 pin */
  GPIO_ResetBits(GPIOC, GPIO_Pin_6);

  /* Communication hyperterminal-USART2 using hardware flow control -------------*/
  /* Send a buffer from USART to hyperterminal */
  while(NbrOfDataToTransfer--)
  {
    USART_SendData(USART2, TxBuffer[TxCounter++]);
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
  }
  /* ************* */

  while (1){
     //while( ADC_GetFlagStatus( ADC1, ADC_FLAG_EOC) == RESET );
     //DataValue = ADCConvertedValue;

	 while( ADC_GetFlagStatus( ADC1, ADC_FLAG_EOC) == RESET );
     while( ( wcnt++ % 0x400000) != 0x0 ){ // wait loop
  	    DataValue = ADC_GetConversionValue(ADC1);
     }
     Temperature= (1.42 - DataValue*3.3/4096)*1000/4.35 + 25;
     DataValue = Temperature;

     // rotate value.
     Keta = ( DataValue & 0xf000 ) / 0x1000 ;
     Keta = (( DataValue & 0x0f00 ) / 0x10 ) + Keta ;
     Keta = (( DataValue & 0x00f0 ) * 0x10 ) + Keta ;
     Keta = (( DataValue & 0x000f ) * 0x1000 ) + Keta ;
     DataValue = Keta ;

     // printf ( "%s", DataValue );
     for ( cnt = 0 ; cnt < 4 ; cnt++ ){
        Keta = 0 ;
        if ( DataValue % 16 >= 10 ){
        	Keta = 'A' + ( DataValue % 16 - 10 );
        } else {
        	Keta = '0' + ( DataValue % 16 );
        }
        DataValue = DataValue /16 ;
        USART_SendData(USART2, Keta );
           while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
     }

     // printf( "\n\r" );
     USART_SendData(USART2, '\n');
        while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
     USART_SendData(USART2, '\r');
        while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);

  }

  /* Receive a string (Max RxBufferSize bytes) from the Hyperterminal ended by '\r' (Enter key) */
  do
  {
    if((USART_GetFlagStatus(USART2, USART_FLAG_RXNE) != RESET)&&(RxCounter < RxBufferSize))
    {
       RxBuffer[RxCounter] = USART_ReceiveData(USART2);
       USART_SendData(USART2, RxBuffer[RxCounter++]);
    }

  }
  while((RxBuffer[RxCounter - 1] != '\r')&&(RxCounter != RxBufferSize));

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

  // ADC Clock at 9Mhz (72/8)
  RCC_ADCCLKConfig(RCC_PCLK2_Div8);

  /* Enable GPIOx and AFIO clocks */
  // RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOx | RCC_APB2Periph_AFIO, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOx | RCC_APB2Periph_AFIO, ENABLE);

  /* Enable GPIOC clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

  /* Enable USART2 clocks */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

  /* Enable DMA clocks */
  //RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  /* Enable ADC1 clocks */
  // The following function name was mistake. 2008/11/16 nt
  //RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
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

  /* Configure USART2 RTS and USART2 Tx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_RTSPin | GPIO_TxPin;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOx, &GPIO_InitStructure);

  /* Configure USART2 CTS and USART2 Rx as input floating */
  GPIO_InitStructure.GPIO_Pin = GPIO_CTSPin | GPIO_RxPin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOx, &GPIO_InitStructure);

  /* Configure PC.06, PC.07, PC.08 and PC.09 as Output push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
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
