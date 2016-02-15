/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * 作者		 ：匿名科创
 * 文件名  ：board.c
 * 描述    ：硬件初始化
 * 官网    ：www.anotc.com
 * 淘宝    ：anotc.taobao.com
 * 技术Q群 ：190169595
**********************************************************************************/
#include "board.h"

void SysTick_IRQ(void)
{
	scheduler.cnt_1ms++;
	scheduler.cnt_2ms++;
	scheduler.cnt_5ms++;
	scheduler.cnt_10ms++;
	scheduler.cnt_30ms++;
}

void LED_INIT()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(ANO_RCC_LED, ENABLE);
	 
	/*配置 SPI_NRF_SPI的 SCK,MISO,MOSI引脚 */ 
	GPIO_InitStructure.GPIO_Pin = ANO_Pin_LED1|ANO_Pin_LED2|ANO_Pin_LED3|ANO_Pin_LED4; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //复用功能 
	GPIO_Init(ANO_PORT_LED, &GPIO_InitStructure);
	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;
	
}


void ANO_Remoter_board_Init(void)
{
	u8 data[32]={0};u8 ack[32]={0};
	//中断优先级组别设置
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//初始化系统滴答定时器
	SysTick_Config(SystemCoreClock / 1000);	
	LED_INIT();
	//初始化模拟I2C
	ANO_I2C_Soft::Init();	
	
	//初始化串口1
	Uart1_Init(115200);
	
	//初始化SPI2
	ANO_SPI2::Init();	

	while(nrf.Check()==false);
	//初始化NRF
	nrf.Init(MODEL_RX2,40);
//while(1)
//{
//	//memset(data,0,sizeof(data));
//	data[0]=0x31;data[1]=0x32;data[2]=0x33;
//	nrf.NRF_Tx_Dat(data,ack);
//	nrf.delayms(50);
//}
	//初始化ADC采样
	ADC1_Init();
	
	//解锁flash
	FLASH_Unlock();	
	//初始化虚拟eeprom设置
	EE_Init();	
	
}



/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/
