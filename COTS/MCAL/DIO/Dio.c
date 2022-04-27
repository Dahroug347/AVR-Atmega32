/*
 * Dio.c
 *
 *  Created on: Mar 10, 2022
 *      Author: Dahroug
 */

#include "Std_types.h"
#include "Bit_utils.h"

#include "Dio.h"
#include "Dio_Prv.h"



Dio_tenuErrorStatus Dio_enuWriteChannel(u8 Copy_u8ChannelId,u8 Copy_u8Level)
{
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk;
	
	u8 Loc_u8Port;
	u8 Loc_u8Pin;
	
	if (Copy_u8ChannelId >= DIO_u8MCU_PINS)
	{
		Loc_enuReturnStatus = Dio_enuChannelError;
	}
	
	else if (Copy_u8Level >= DIO_u8LEVELS)
	{
		Loc_enuReturnStatus = Dio_enuLevelError;
	}
	else
	{
		Loc_u8Port = Copy_u8ChannelId/REG_SIZE;
		Loc_u8Pin  = Copy_u8ChannelId%REG_SIZE;
		
		switch (Loc_u8Port)
		{
			case DIO_u8PORTA:
			
				if (Copy_u8Level == DIO_u8HIGH)
				{
					SET_BIT(PORTA, Loc_u8Pin);				
				}
				else
				{
					CLR_BIT(PORTA, Loc_u8Pin);				
				}
			break;
			
			case DIO_u8PORTB:
			
				if (Copy_u8Level == DIO_u8HIGH)
				{
					SET_BIT(PORTB, Loc_u8Pin);				
				}
				else
				{
					CLR_BIT(PORTB, Loc_u8Pin);				
				}
			break;
			
			case DIO_u8PORTC:
			
				if (Copy_u8Level == DIO_u8HIGH)
				{
					SET_BIT(PORTC, Loc_u8Pin);				
				}
				else
				{
					CLR_BIT(PORTC, Loc_u8Pin);				
				}
			break;
			
			case DIO_u8PORTD:
			
				if (Copy_u8Level == DIO_u8HIGH)
				{
					SET_BIT(PORTD, Loc_u8Pin);				
				}
				else
				{
					CLR_BIT(PORTD, Loc_u8Pin);				
				}
			break;
			
			default:
				break;
		}
	}
	return Loc_enuReturnStatus;
}



Dio_tenuErrorStatus Dio_enuReadChannel(u8 Copy_u8ChannelId,u8* Add_pu8ChannelLevel)
{
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk;
	
	u8 Loc_u8Port;
	u8 Loc_u8Pin;
	
	if (Copy_u8ChannelId >= DIO_u8MCU_PINS)
	{
		Loc_enuReturnStatus = Dio_enuChannelError;
	}
	
	else if (Add_pu8ChannelLevel == NULL)
	{
		Loc_enuReturnStatus = Dio_enuNullPtr;
	}
	else
	{
		Loc_u8Port = Copy_u8ChannelId/REG_SIZE;
		Loc_u8Pin  = Copy_u8ChannelId%REG_SIZE;
		
		switch (Loc_u8Port)
		{
			case DIO_u8PORTA:
			
				*Add_pu8ChannelLevel = GET_BIT(PINA, Loc_u8Pin);
					
			break;
			
			case DIO_u8PORTB:
			
				*Add_pu8ChannelLevel = GET_BIT(PINB, Loc_u8Pin);
					
			break;
			
			case DIO_u8PORTC:
			
				*Add_pu8ChannelLevel = GET_BIT(PINC, Loc_u8Pin);
					
			break;
			
			case DIO_u8PORTD:
			
				*Add_pu8ChannelLevel = GET_BIT(PIND, Loc_u8Pin);
					
			break;
			
			default:
		 break;
		}
	}
	return Loc_enuReturnStatus;
}

Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId,u8 Copy_u8Value)
{
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk;
	
	if ( Copy_u8PortId >= DIO_u8MCU_PORTS)
	{
		Loc_enuReturnStatus = Dio_enuPortError;
	}
	else
	{
		switch (Copy_u8PortId)
		{
			case DIO_u8PORTA:
				ASSIGN_REG(PORTA,Copy_u8Value);
		    break;	

			case DIO_u8PORTB:
				ASSIGN_REG(PORTB,Copy_u8Value);
		    break;	

			case DIO_u8PORTC:
				ASSIGN_REG(PORTC,Copy_u8Value);
		    break;	

			case DIO_u8PORTD:
				ASSIGN_REG(PORTD,Copy_u8Value);
		    break;

			default:
			break;
		}
	}
	return Loc_enuReturnStatus;
}

Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId, pu8 Add_pu8PortLevel)
{
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk;
	
	if ( Copy_u8PortId >= DIO_u8MCU_PORTS)
	{
		Loc_enuReturnStatus = Dio_enuPortError;
	}
	
	else if (Add_pu8PortLevel == NULL)
	{
		Loc_enuReturnStatus = Dio_enuNullPtr;
	}
	else
	{		
		switch (Copy_u8PortId)
		{
			case DIO_u8PORTA:
			
				*Add_pu8PortLevel = PINA;
					
			break;
			
			case DIO_u8PORTB:
			
				*Add_pu8PortLevel = PINB;
					
			break;
			
			case DIO_u8PORTC:
			
				*Add_pu8PortLevel = PINC;
					
			break;
			
			case DIO_u8PORTD:
			
				*Add_pu8PortLevel = PIND;
					
			break;
			
			default:
		 break;
		}
	}
	return Loc_enuReturnStatus;
}


Dio_tenuErrorStatus Dio_enuFlipChannel (u8 Copy_u8ChannelId)
{
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOk;
	
	u8 Loc_u8Port;
	u8 Loc_u8Pin;
	
	if (Copy_u8ChannelId >= DIO_u8MCU_PINS)
	{
		Loc_enuReturnStatus = Dio_enuChannelError;
	}

	else
	{
		Loc_u8Port = Copy_u8ChannelId/REG_SIZE;
		Loc_u8Pin  = Copy_u8ChannelId%REG_SIZE;
		
		switch (Loc_u8Port)
		{
			case DIO_u8PORTA:
			
				TGL_BIT(PORTA,Loc_u8Pin);
					
			break;
			
			case DIO_u8PORTB:
			
				TGL_BIT(PORTB,Loc_u8Pin);
					
			break;
			
			case DIO_u8PORTC:
			
				TGL_BIT(PORTC,Loc_u8Pin);
					
			break;
			
			case DIO_u8PORTD:
			
				TGL_BIT(PORTD,Loc_u8Pin);
					
			break;
			
			default:
		 break;
		}
	}
	return Loc_enuReturnStatus;
}
