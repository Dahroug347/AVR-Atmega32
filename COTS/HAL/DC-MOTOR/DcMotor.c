#include "Std_types.h"

#include "dio.h"

#include "DcMotor.h"
#include "DcMotor_cfg.h"

void DcMotor_vidFullSpeedRight(void)
{
	Dio_enuWriteChannel(DC_MOTOR_PIN1, DIO_u8HIGH);
	Dio_enuWriteChannel(DC_MOTOR_PIN2, DIO_u8LOW);
}

void DcMotor_vidFullSpeedLeft (void)
{
	Dio_enuWriteChannel(DC_MOTOR_PIN1, DIO_u8LOW);
	Dio_enuWriteChannel(DC_MOTOR_PIN2, DIO_u8HIGH);
}
void DcMotor_vidStop(void)
{
	Dio_enuWriteChannel(DC_MOTOR_PIN1, DIO_u8LOW);
	Dio_enuWriteChannel(DC_MOTOR_PIN2, DIO_u8LOW);
}

void DcMotor_vidForceStop(void)
{
	Dio_enuWriteChannel(DC_MOTOR_PIN1, DIO_u8HIGH);
	Dio_enuWriteChannel(DC_MOTOR_PIN2, DIO_u8HIGH);
}
