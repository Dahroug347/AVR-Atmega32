/*
 * Port.h
 *
 *  Created on: Mar 6, 2022
 *      Author: dahroug
 */

#ifndef		PORT_H_
#define		PORT_H_

/* pins macros */
#define 	PORT_u8PA0 							0
#define 	PORT_u8PA1 							1
#define 	PORT_u8PA2 							2
#define 	PORT_u8PA3 							3
#define 	PORT_u8PA4 							4
#define 	PORT_u8PA5 							5
#define 	PORT_u8PA6 							6
#define 	PORT_u8PA7 							7
									
#define 	PORT_u8PB0 							8
#define 	PORT_u8PB1 							9
#define 	PORT_u8PB2 							10
#define 	PORT_u8PB3 							11
#define 	PORT_u8PB4 							12
#define 	PORT_u8PB5 							13
#define 	PORT_u8PB6 							14
#define 	PORT_u8PB7 							15
									
#define 	PORT_u8PC0 							16
#define 	PORT_u8PC1 							17
#define 	PORT_u8PC2 							18
#define 	PORT_u8PC3 							19
#define 	PORT_u8PC4 							20
#define 	PORT_u8PC5 							21
#define 	PORT_u8PC6 							22
#define 	PORT_u8PC7 							23
									
#define 	PORT_u8PD0 							24
#define 	PORT_u8PD1 							25
#define 	PORT_u8PD2 							26
#define 	PORT_u8PD3 							27
#define 	PORT_u8PD4 							28
#define 	PORT_u8PD5 							29
#define 	PORT_u8PD6 							30
#define 	PORT_u8PD7 							31

/*	set pin direction function macros */
#define 	PORT_u8INPUT						0
#define 	PORT_u8OUTPUT						1

/*	set pin mode function macros */
#define 	PORT_u8INPUT_HIGH_IMPEADANCE		0
#define 	PORT_u8INPUT_PULLUP					1
#define 	PORT_u8OUTPUT_LOW					2
#define 	PORT_u8OUTPUT_HIGH					3

typedef enum
{
	Port_enuOk,
	Port_enuPinError,
	Port_enuDirectionError,
	Port_enuModeError

}Port_tenuErrorStatus;

extern Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum,u8 Copy_u8PinDirection);
extern Port_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum,u8 Copy_u8PinMode);
void Port_vidInit(void);

#endif		/* PORT_H_ */

