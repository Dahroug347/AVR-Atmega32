/* services */
#include "Std_types.h"
#include "Bit_utils.h"

/* MCAL */
#include "Dio.h"

#include "Buzzer.h"
#include "Buzzer_cfg.h"

static u8 read;             /*global variable used to preserve the last state of buzzer so that we can toggle it*/

Std_enuErrorStatus Buzz_tenuTurnOnBuzz	(void)
{
	Std_enuErrorStatus Loc_u8ErrStatusRetVal = OK;

	if (Dio_enuWriteChannel(BUZZ_PIN, BUZZ_ON) != Dio_enuOk)
	{
		Loc_u8ErrStatusRetVal = NOK;
	}
	else
	{

	}
	return Loc_u8ErrStatusRetVal;
}


Std_enuErrorStatus  Buzz_tenuTurnOffBuzz(void)
{
	Std_enuErrorStatus Loc_u8ErrStatusRetVal = OK;

	if (Dio_enuWriteChannel(BUZZ_PIN, BUZZ_OFF) != Dio_enuOk)
	{
		Loc_u8ErrStatusRetVal = NOK;
	}
	else
	{

	}
	return Loc_u8ErrStatusRetVal;
}

Std_enuErrorStatus  Buzz_tenuToggleBuzz	(void)
{

	 Std_enuErrorStatus Loc_u8ErrStatusRetVal = OK;

	 if (Dio_enuReadChannel (BUZZ_PIN, &read) == Dio_enuChannelError)
	 {
		 Loc_u8ErrStatusRetVal = INVALID_ARG;
	 }
	 else
	 {
		 if (read == BUZZ_ON)
		 {
			if (Dio_enuWriteChannel(BUZZ_PIN, BUZZ_OFF) != Dio_enuOk)
			{
				Loc_u8ErrStatusRetVal = INVALID_ARG;
			}
			else
			{

			}
		 }
		 else if (read == BUZZ_OFF)
		 {
			if (Dio_enuWriteChannel(BUZZ_PIN, BUZZ_ON) != Dio_enuOk)
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
			



