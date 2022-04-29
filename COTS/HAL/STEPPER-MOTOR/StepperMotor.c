#include    "Std_types.h"
#include    "Delay_ms.h"

#include    "Dio.h"

#include    "StepperMotor.h"
#include    "StepperMotor_cfg.h"

#define 	STEPPER_ZERO_VAL		                        0
#define 	STEPPER_ONE_VAL			                        1
#define 	STEPPER_COIL_DELAY		                        2
#define 	STEPPER_COIL_STEP							    2
#define		STEPPER_ACTUAL_DEGREE_SHAFT_MOVEMENT_FACTOR		(10/7)
#define 	STEPPER_COIL_STEPS_REFERENCE					16

#define 	STEPPER_COIL1_DIRECTION						    0
#define 	STEPPER_COIL2_DIRECTION						    1
#define 	STEPPER_COIL3_DIRECTION						    2
#define 	STEPPER_COIL4_DIRECTION						    3

void Stepper_vidMov (s16 angle)
{
	u16 count = STEPPER_ZERO_VAL;

	if(angle  > STEPPER_ZERO_VAL)
	{
		/*	!comment: since a full magnet rotation only results in 0.7 degrees for the actual motor rotation
						we need to calc the amount of complete magnet rotation to move to a certain degree*/
		count = angle *STEPPER_ACTUAL_DEGREE_SHAFT_MOVEMENT_FACTOR;
		
		for(u16 counter = STEPPER_ZERO_VAL; counter < count; counter ++)
		{
		/*	!comment: i<16 because we need the loop to run only 4 times,
						as there are only 4 coils in the stepper motor (check the lec for more details) */
			for(u8 i = STEPPER_ONE_VAL; i < STEPPER_COIL_STEPS_REFERENCE ; i*=STEPPER_COIL_STEP)
			{
				Dio_enuWriteChannel(STEPPER_COIL1_PIN,((i>>STEPPER_COIL1_DIRECTION)&STEPPER_ONE_VAL));
				Dio_enuWriteChannel(STEPPER_COIL2_PIN,((i>>STEPPER_COIL2_DIRECTION)&STEPPER_ONE_VAL));
				Dio_enuWriteChannel(STEPPER_COIL3_PIN,((i>>STEPPER_COIL3_DIRECTION)&STEPPER_ONE_VAL));
				Dio_enuWriteChannel(STEPPER_COIL4_PIN,((i>>STEPPER_COIL4_DIRECTION)&STEPPER_ONE_VAL));
			}
			delay_ms(STEPPER_COIL_DELAY);
		}
	}
	else if(angle == STEPPER_ZERO_VAL)
	{}
	else
	{
		/*	!comment: since a full magnet rotation only results in 0.7 degrees for the actual motor rotation
						we need to calc the amount of complete magnet rotation to move to a certain degree*/
		count = (angle*(-STEPPER_ONE_VAL)) *STEPPER_ACTUAL_DEGREE_SHAFT_MOVEMENT_FACTOR;
		
		for(u16 counter = STEPPER_ZERO_VAL; counter < count; counter ++)
		{
		/*	!comment: i<16 because we need the loop to run only 4 times,
						as there are only 4 coils in the stepper motor (check the lec for more details) */
			for(u8 i = STEPPER_ONE_VAL; i < STEPPER_COIL_STEPS_REFERENCE ; i*=STEPPER_COIL_STEP)
			{
				Dio_enuWriteChannel(STEPPER_COIL1_PIN,((i>>STEPPER_COIL4_DIRECTION)&STEPPER_ONE_VAL));
				Dio_enuWriteChannel(STEPPER_COIL2_PIN,((i>>STEPPER_COIL3_DIRECTION)&STEPPER_ONE_VAL));
				Dio_enuWriteChannel(STEPPER_COIL3_PIN,((i>>STEPPER_COIL2_DIRECTION)&STEPPER_ONE_VAL));
				Dio_enuWriteChannel(STEPPER_COIL4_PIN,((i>>STEPPER_COIL1_DIRECTION)&STEPPER_ONE_VAL));
			}
			delay_ms(STEPPER_COIL_DELAY);
		}
	}
}
