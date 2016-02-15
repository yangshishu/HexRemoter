/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * ����		 �������ƴ�
 * �ļ���  ��board.c
 * ����    ��Ӳ����ʼ��
 * ����    ��www.anotc.com
 * �Ա�    ��anotc.taobao.com
 * ����QȺ ��190169595
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
	 
	/*���� SPI_NRF_SPI�� SCK,MISO,MOSI���� */ 
	GPIO_InitStructure.GPIO_Pin = ANO_Pin_LED1|ANO_Pin_LED2|ANO_Pin_LED3|ANO_Pin_LED4; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //���ù��� 
	GPIO_Init(ANO_PORT_LED, &GPIO_InitStructure);
	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;
	
}


void ANO_Remoter_board_Init(void)
{
	u8 data[32]={0};u8 ack[32]={0};
	//�ж����ȼ��������
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//��ʼ��ϵͳ�δ�ʱ��
	SysTick_Config(SystemCoreClock / 1000);	
	LED_INIT();
	//��ʼ��ģ��I2C
	ANO_I2C_Soft::Init();	
	
	//��ʼ������1
	Uart1_Init(115200);
	
	//��ʼ��SPI2
	ANO_SPI2::Init();	

	while(nrf.Check()==false);
	//��ʼ��NRF
	nrf.Init(MODEL_RX2,40);
//while(1)
//{
//	//memset(data,0,sizeof(data));
//	data[0]=0x31;data[1]=0x32;data[2]=0x33;
//	nrf.NRF_Tx_Dat(data,ack);
//	nrf.delayms(50);
//}
	//��ʼ��ADC����
	ADC1_Init();
	
	//����flash
	FLASH_Unlock();	
	//��ʼ������eeprom����
	EE_Init();	
	
}



/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/
