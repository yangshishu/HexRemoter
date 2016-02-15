#ifndef __ANO_DRV_MPU6050_H
#define	__ANO_DRV_MPU6050_H

#include "board.h"

#define CALIBRATING_GYRO_CYCLES             1000
#define CALIBRATING_ACC_CYCLES              400

class ANO_MPU6050:public ANO_I2C_Soft
{
public:
	
	ANO_MPU6050(void);

	u8 Acc_CALIBRATED;
	u8 Gyro_CALIBRATED;
	Vector3i Acc_Offset,Gyro_Offset;

	//��ʼ��6050
	void Init(uint16_t sample_rate, uint16_t lpf);
	//��ȡ���ٶ�
	void Read_Acc_Data(void);
	//��ȡ���ٶ�
	void Read_Gyro_Data(void);
	//���ؼ��ٶȵ�ֵ
	Vector3f Get_Acc(void);
	//���ؽ��ٶȵ�ֵ
	Vector3f Get_Gyro(void);
	//���ص�λΪ��ÿ��Ľ��ٶ�
	Vector3f Get_Gyro_in_dps(void);

private:
	
	u8 mpu6050_buffer[14]; //�������ݻ�����
	Vector3f Acc_ADC,Gyro_ADC;
	Vector3f Gyro_dps;

	//���ٶ���ƫ����
	void CalOffset_Acc(void);
	//��������ƫ����
	void CalOffset_Gyro(void);

	void delayms(uint16_t ms);
};

extern ANO_MPU6050 mpu6050;

#endif







