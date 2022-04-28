/* services */
#include "Std_types.h"
#include "Bit_utils.h"

/* MCAL */
#include "Port.h"
#include "Dio.h"

#include "Switch.h"
#include "Switch_cfg.h"


void Switch_vidConfiguration (u8 SWITCH_X_PIN, u8 ACTIVE_X)
{
	if (PORT_u8INPUT_PULLUP == ACTIVE_X)                                       /*would be modified using switch case later for better performance and time saving*/
	{
		Port_enuSetPinDirection(SWITCH_X_PIN, PORT_u8INPUT_PULLUP );
	}
	else if (PORT_u8INPUT_HIGH_IMPEADANCE== ACTIVE_X)
	{
		Port_enuSetPinDirection(SWITCH_X_PIN, PORT_u8INPUT_HIGH_IMPEADANCE);
	}
}

u8 Switch_u8GetStatus (u8 SWITCH_X)
{
	 static u8 status;
	
	switch (SWITCH_X)
	{
		case SWITCH_1:
		Dio_enuReadChannel (SWITCH_1_PIN, &status);
		break; 
		
		case SWITCH_2:
		Dio_enuReadChannel (SWITCH_2_PIN, &status);
		break;

		case SWITCH_3:
		Dio_enuReadChannel (SWITCH_3_PIN, &status);
		break;

		case SWITCH_4:
		Dio_enuReadChannel (SWITCH_4_PIN, &status);
		break;

		case SWITCH_5:
		Dio_enuReadChannel (SWITCH_5_PIN, &status);
		break;
 
		case SWITCH_6:
		Dio_enuReadChannel (SWITCH_6_PIN, &status);
		break;

		case SWITCH_7:
		Dio_enuReadChannel (SWITCH_7_PIN, &status);
		break;

		case SWITCH_8:
		Dio_enuReadChannel (SWITCH_8_PIN, &status);
		break;
	}
	return status;
}
