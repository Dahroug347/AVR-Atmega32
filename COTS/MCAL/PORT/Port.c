#include "Std_types.h"
#include "Bit_utils.h"

#include "Port.h"
#include "Port_cfg.h"
#include "Port_prv.h"


Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum,u8 Copy_u8PinDirection)
{
	Port_tenuErrorStatus Loc_enuReturnStatus = Port_enuOk;
	
	u8 Loc_u8Port;
	u8 Loc_u8Pin;
	
	if (Copy_u8PinNum >= PORT_u8MCU_PINS)
	{
		Loc_enuReturnStatus = Port_enuPinError;
	}
	
	else if (Copy_u8PinDirection >= PORT_u8DIRECTIONS)
	{
		Loc_enuReturnStatus = Port_enuDirectionError;
	}
	else
	{
		Loc_u8Port = Copy_u8PinNum/REG_SIZE;
		Loc_u8Pin  = Copy_u8PinNum%REG_SIZE;
		
		switch (Loc_u8Port)
		{
			case PORT_PORTA:
			
				if (Copy_u8PinDirection == PORT_u8OUTPUT)
				{
					SET_BIT(DDRA, Loc_u8Pin);				//DDRA |= (1<<Loc_u8Pin);
				}
				else
				{
					CLR_BIT(DDRA, Loc_u8Pin);				//DDRA &= ~(1<<Loc_u8Pin);
				}
			break;
			
			case PORT_PORTB:
			
				if (Copy_u8PinDirection == PORT_u8OUTPUT)
				{
					SET_BIT(DDRB, Loc_u8Pin);
				}
				else
				{
					CLR_BIT(DDRB, Loc_u8Pin);
				}
			break;
			
			case PORT_PORTC:
			
				if (Copy_u8PinDirection == PORT_u8OUTPUT)
				{
					SET_BIT(DDRC, Loc_u8Pin);
				}
				else
				{
					CLR_BIT(DDRC, Loc_u8Pin);
				}
			break;
			
			case PORT_PORTD:
				if (Copy_u8PinDirection == PORT_u8OUTPUT)
				{
					SET_BIT(DDRD, Loc_u8Pin);
				}
				else
				{
					CLR_BIT(DDRD, Loc_u8Pin);
				}
			break;
			
			default:
				break;
		}
	}
	return Loc_enuReturnStatus;
}



Port_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum,u8 Copy_u8PinMode)
{
	Port_tenuErrorStatus Loc_enuReturnStatus = Port_enuOk;
	
	u8 Loc_u8Port;
	u8 Loc_u8Pin;
	
	if (Copy_u8PinNum >= PORT_u8MCU_PINS)
	{
		Loc_enuReturnStatus = Port_enuPinError;
	}
	
	else if (Copy_u8PinMode >= PORT_u8MODES)
	{
		Loc_enuReturnStatus = Port_enuModeError;
	}
	else
	{
		Loc_u8Port = Copy_u8PinNum/REG_SIZE;
		Loc_u8Pin  = Copy_u8PinNum%REG_SIZE;
		
		switch (Loc_u8Port)
		{
			case PORT_PORTA:
			
				switch (Copy_u8PinMode)
				{
					case PORT_u8INPUT_HIGH_IMPEADANCE:
					
						CLR_BIT(DDRA, Loc_u8Pin);
						CLR_BIT(PORTA, Loc_u8Pin);
						
					break;
					
					case PORT_u8INPUT_PULLUP:
					
						CLR_BIT(DDRA, Loc_u8Pin);
						SET_BIT(PORTA, Loc_u8Pin);
						
					break;
					
					case PORT_u8OUTPUT_LOW:
						
						SET_BIT(DDRA, Loc_u8Pin);
						CLR_BIT(PORTA, Loc_u8Pin);
						
					break;
					
					case PORT_u8OUTPUT_HIGH:
					
						SET_BIT(DDRA, Loc_u8Pin);
						SET_BIT(PORTA, Loc_u8Pin);
						
					break;
					
					default:
						break;
				}
			break;
			
			case PORT_PORTB:
			
				switch (Copy_u8PinMode)
				{
					case PORT_u8INPUT_HIGH_IMPEADANCE:
					
						CLR_BIT(DDRB, Loc_u8Pin);
						CLR_BIT(PORTB, Loc_u8Pin);
						
					break;
					
					case PORT_u8INPUT_PULLUP:
					
						CLR_BIT(DDRB, Loc_u8Pin);
						SET_BIT(PORTB, Loc_u8Pin);
						
					break;
					
					case PORT_u8OUTPUT_LOW:
						
						SET_BIT(DDRB, Loc_u8Pin);
						CLR_BIT(PORTB, Loc_u8Pin);
						
					break;
					
					case PORT_u8OUTPUT_HIGH:
					
						SET_BIT(DDRB, Loc_u8Pin);
						SET_BIT(PORTB, Loc_u8Pin);
						
					break;
					
					default:
						break;
				}
			break;
			
			case PORT_PORTC:
			
				switch (Copy_u8PinMode)
				{
					case PORT_u8INPUT_HIGH_IMPEADANCE:
					
						CLR_BIT(DDRC, Loc_u8Pin);
						CLR_BIT(PORTC, Loc_u8Pin);
						
					break;
					
					case PORT_u8INPUT_PULLUP:
					
						CLR_BIT(DDRC, Loc_u8Pin);
						SET_BIT(PORTC, Loc_u8Pin);
						
					break;
					
					case PORT_u8OUTPUT_LOW:
						
						SET_BIT(DDRC, Loc_u8Pin);
						CLR_BIT(PORTC, Loc_u8Pin);
						
					break;
					
					case PORT_u8OUTPUT_HIGH:
					
						SET_BIT(DDRC, Loc_u8Pin);
						SET_BIT(PORTC, Loc_u8Pin);
						
					break;
					
					default:
						break;
				}
			break;
			
			case PORT_PORTD:
			
				switch (Copy_u8PinMode)
				{
					case PORT_u8INPUT_HIGH_IMPEADANCE:
					
						CLR_BIT(DDRD, Loc_u8Pin);
						CLR_BIT(PORTD, Loc_u8Pin);
						
					break;
					
					case PORT_u8INPUT_PULLUP:
					
						CLR_BIT(DDRD, Loc_u8Pin);
						SET_BIT(PORTD, Loc_u8Pin);
						
					break;
					
					case PORT_u8OUTPUT_LOW:
						
						SET_BIT(DDRD, Loc_u8Pin);
						CLR_BIT(PORTD, Loc_u8Pin);
						
					break;
					
					case PORT_u8OUTPUT_HIGH:
					
						SET_BIT(DDRD, Loc_u8Pin);
						SET_BIT(PORTD, Loc_u8Pin);
						
					break;
					
					default:
						break;
				}
			break;
			
			default:
				break;
		}
	}
	return Loc_enuReturnStatus;
}


void Port_vidInit(void)
{
	DDRA  = DDRA_INIT_VALUE;
	DDRB  = DDRB_INIT_VALUE;
	DDRC  = DDRC_INIT_VALUE;
	DDRD  = DDRD_INIT_VALUE;
	
	PORTA = PORTA_INIT_VALUE;
	PORTB = PORTB_INIT_VALUE;
	PORTC = PORTC_INIT_VALUE;
	PORTD = PORTD_INIT_VALUE;		
}
	
