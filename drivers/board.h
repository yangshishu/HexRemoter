
#ifndef __BOARD_H__
#define __BOARD_H__

#include "stm32f10x.h"
#include "string.h"
#include "ANO_Math.h"

#define ARMAPI extern "C"

/***************LED GPIO定义******************/
#define ANO_RCC_LED			RCC_APB2Periph_GPIOB
#define ANO_PORT_LED		GPIOB
#define ANO_Pin_LED1		GPIO_Pin_8

#define ANO_Pin_LED2		GPIO_Pin_9

#define ANO_Pin_LED3		GPIO_Pin_10

#define ANO_Pin_LED4		GPIO_Pin_11

#define LED1_OFF   ANO_PORT_LED->BSRR = ANO_Pin_LED1;
#define LED1_ON    ANO_PORT_LED->BRR  = ANO_Pin_LED1;//SET 0

#define LED2_OFF   ANO_PORT_LED->BSRR = ANO_Pin_LED2;
#define LED2_ON    ANO_PORT_LED->BRR  = ANO_Pin_LED2;//SET 0

#define LED3_OFF   ANO_PORT_LED->BSRR = ANO_Pin_LED3;
#define LED3_ON    ANO_PORT_LED->BRR  = ANO_Pin_LED3;//SET 0

#define LED4_OFF   ANO_PORT_LED->BSRR = ANO_Pin_LED4;
#define LED4_ON    ANO_PORT_LED->BRR  = ANO_Pin_LED4;//SET 0
/*********************************************/

/***************I2C GPIO定义******************/
#define ANO_GPIO_I2C	GPIOB
#define I2C_Pin_SCL		GPIO_Pin_11
#define I2C_Pin_SDA		GPIO_Pin_10
#define ANO_RCC_I2C		RCC_APB2Periph_GPIOB
/*********************************************/

/***************SPI2 GPIO定义******************/
#define ANO_GPIO_SPI2		GPIOB
#define ANO_GPIO_CE2		GPIOB
#define ANO_GPIO_CSN		GPIOB
#define SPI2_Pin_SCK		GPIO_Pin_13
#define SPI2_Pin_MISO		GPIO_Pin_14
#define SPI2_Pin_MOSI		GPIO_Pin_15
#define SPI2_Pin_CE2		GPIO_Pin_0
#define SPI2_Pin_CSN		GPIO_Pin_12
#define RCC_GPIO_SPI2		RCC_APB2Periph_GPIOB
#define RCC_GPIO_CE2		RCC_APB2Periph_GPIOB
#define NRF_IRQ_PORT 		GPIOB
#define NRF_IRQ_PIN 		GPIO_Pin_1

/*********************************************/

/***************硬件中断优先级******************/
#define NVIC_UART_P	5
#define NVIC_UART_S	1
/***********************************************/

#include "ANO_Config.h"
#include "ANO_Drv_Usart1.h"
#include "ANO_Drv_ADC.h"
#include "ANO_Drv_SPI2.h"
#include "ANO_Drv_Nrf24l01.h"
#include "ANO_Drv_EEPROM.h"
#include "ANO_Drv_I2C_soft.h"
#include "ANO_Drv_MPU6050.h"

void ANO_Remoter_board_Init(void);
void SysTick_IRQ(void);


#endif /* __BOARD_H__ */

// 




