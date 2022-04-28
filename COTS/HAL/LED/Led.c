/*Default system libraries*/
//#include <util/delay.h>

/* services */
#include "Std_types.h"
#include "Bit_utils.h"

/* MCAL */
#include "Dio.h"

#include "Led.h"
#include "Led_cfg.h"


#define     LED_1_INDEX		    0

#define     LED_2_INDEX		    1

#define     LED_3_INDEX		    2

#define     LED_4_INDEX		    3

#define     LED_5_INDEX		    4

#define     LED_6_INDEX		    5

#define     LED_7_INDEX		    6

#define     LED_8_INDEX		    7


#define 	LEDS_MAX_VAL		255


static u8 read;                 /*global variable used to preserve the last state of a led so that we can toggle it*/



Std_enuErrorStatus Led_tenuTurnOnLed 	(u8 LED_X_PIN)
{
	Std_enuErrorStatus Loc_u8ErrStatusRetVal = OK;

	if (Dio_enuWriteChannel(LED_X_PIN, LED_u8ON) != Dio_enuOk)
	{
		Loc_u8ErrStatusRetVal = INVALID_ARG;
	}
	else
	{

	}
	return Loc_u8ErrStatusRetVal;
}

Std_enuErrorStatus Led_tenuTurnOffLed 	(u8 LED_X_PIN)
{
	Std_enuErrorStatus Loc_u8ErrStatusRetVal = OK;

	if (Dio_enuWriteChannel(LED_X_PIN, LED_u8OFF) != Dio_enuOk)
	{
		Loc_u8ErrStatusRetVal = INVALID_ARG;
	}
	else
	{

	}
	return Loc_u8ErrStatusRetVal;
}

Std_enuErrorStatus Led_tenuToggleLed 	(u8 LED_X_PIN)
{
	 Std_enuErrorStatus Loc_u8ErrStatusRetVal = OK;

	 if (Dio_enuReadChannel (LED_X_PIN, &read) == Dio_enuChannelError)
	 {
		 Loc_u8ErrStatusRetVal = INVALID_ARG;
	 }
	 else
	 {
		 if (read == LED_u8ON)
		 {
			if (Dio_enuWriteChannel(LED_X_PIN, LED_u8OFF) != Dio_enuOk)
			{
				Loc_u8ErrStatusRetVal = INVALID_ARG;
			}
			else
			{

			}
		 }
		 else if (read == LED_u8OFF)
		 {
			if (Dio_enuWriteChannel(LED_X_PIN, LED_u8ON) != Dio_enuOk)
			{
				Loc_u8ErrStatusRetVal = INVALID_ARG;
			}
			else
			{

			}
		 }
		 else
		 {
			 Loc_u8ErrStatusRetVal = NULL_PTR;
		 }
	 }

	return Loc_u8ErrStatusRetVal;
}

Std_enuErrorStatus Led_tenuNumberPattern (u8 value)
{
	Std_enuErrorStatus Loc_u8ErrStatusRetVal = OK;

	if (value > LEDS_MAX_VAL)
	{
		Loc_u8ErrStatusRetVal = INVALID_ARG;
	}
	else
	{
		Loc_u8ErrStatusRetVal = Dio_enuWriteChannel(LED_1_PIN, GET_BIT(value, LED_1_INDEX));
		Loc_u8ErrStatusRetVal = Dio_enuWriteChannel(LED_2_PIN, GET_BIT(value, LED_2_INDEX));
		Loc_u8ErrStatusRetVal = Dio_enuWriteChannel(LED_3_PIN, GET_BIT(value, LED_3_INDEX));
		Loc_u8ErrStatusRetVal = Dio_enuWriteChannel(LED_4_PIN, GET_BIT(value, LED_4_INDEX));
		Loc_u8ErrStatusRetVal = Dio_enuWriteChannel(LED_5_PIN, GET_BIT(value, LED_5_INDEX));
		Loc_u8ErrStatusRetVal = Dio_enuWriteChannel(LED_6_PIN, GET_BIT(value, LED_6_INDEX));
		Loc_u8ErrStatusRetVal = Dio_enuWriteChannel(LED_7_PIN, GET_BIT(value, LED_7_INDEX));
		Loc_u8ErrStatusRetVal = Dio_enuWriteChannel(LED_8_PIN, GET_BIT(value, LED_8_INDEX));

		if (Loc_u8ErrStatusRetVal != OK)
		{
			Loc_u8ErrStatusRetVal = INVALID_ARG;
		}
		else
		{

		}
	}

	return Loc_u8ErrStatusRetVal;
}			



