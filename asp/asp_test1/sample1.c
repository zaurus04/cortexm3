#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include <string.h>
#include "stm32f10x_lib.h"
#include "platform_config.h"
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "sample1.h"


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

void task1(intptr_t exinf)
{
    syslog( LOG_NOTICE, "test = %x", 0x444 );

  /* define local values */
  u16 DataValue = 0x0;
  u32 wcnt = 0; // counter for wait
  u16 Temperature = 0 ;

#ifdef DEBUG
  debug();
#endif

  /* System Clocks Configuration */
  RCC_Configuration();

  /* NVIC configuration */
  NVIC_Configuration();

  /* Configure the GPIO ports */
  GPIO_Configuration();



  /* ADC1 configuration ------------------------------------------------------*/
  ADC_InitStructure.ADC_Mode               = ADC_Mode_Independent;
  ADC_InitStructure.ADC_ScanConvMode       = ENABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConv   = ADC_ExternalTrigConv_None;
  ADC_InitStructure.ADC_DataAlign          = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfChannel       = 1;
  ADC_Init(ADC1, &ADC_InitStructure);
  /* ADC1 regular channels configuration */
  ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 1, ADC_SampleTime_239Cycles5);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_17, 2, ADC_SampleTime_239Cycles5);
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


  /* **************** */
  /*  MARKER for Debug*/
  /* **************** */

  /* Turn on led connected to PC.06 pin */
  //GPIO_SetBits(GPIOC, GPIO_Pin_6);
  /* Turn off led connected to PC.06 pin */
  GPIO_ResetBits(GPIOC, GPIO_Pin_6);


  while (1){

	 while( ADC_GetFlagStatus( ADC1, ADC_FLAG_EOC) == RESET );
     while( ( wcnt++ % 0x400000) != 0x0 ){ // wait loop
  	    DataValue = ADC_GetConversionValue(ADC1);
     }
      Temperature= (1.42 - DataValue*3.3/4096)*1000/4.35 + 25;
      DataValue = Temperature;

     syslog( LOG_NOTICE, "Temperature = %d", DataValue );
  }

}  // END OF TASK1





/*******************************************************************************
* Function Name  : RCC_Configuration
* Description    : Configures the different system clocks.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RCC_Configuration(void)
{
  // ADC Clock at 9Mhz (72/8)
  RCC_ADCCLKConfig(RCC_PCLK2_Div8);

  /* Enable GPIOx and AFIO clocks */
  // RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOx | RCC_APB2Periph_AFIO, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOx | RCC_APB2Periph_AFIO, ENABLE);

  /* Enable GPIOC clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

  /* Enable ADC1 clocks */
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

}


/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
