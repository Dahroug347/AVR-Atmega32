/*
 * Dio.h
 *
 *  Created on: Mar 10, 2022
 *      Author: Dahroug
 */

#ifndef		DIO_H_
#define		DIO_H_

#define 	DIO_u8PA0 		0
#define 	DIO_u8PA1 		1
#define 	DIO_u8PA2 		2
#define 	DIO_u8PA3 		3
#define 	DIO_u8PA4 		4
#define 	DIO_u8PA5 		5
#define 	DIO_u8PA6 		6
#define 	DIO_u8PA7 		7
				 
#define 	DIO_u8PB0 		8
#define 	DIO_u8PB1 		9
#define 	DIO_u8PB2 		10
#define 	DIO_u8PB3 		11
#define 	DIO_u8PB4 		12
#define 	DIO_u8PB5 		13
#define 	DIO_u8PB6 		14
#define 	DIO_u8PB7 		15
				 
#define 	DIO_u8PC0 		16
#define 	DIO_u8PC1 		17
#define 	DIO_u8PC2 		18
#define 	DIO_u8PC3 		19
#define 	DIO_u8PC4 		20
#define 	DIO_u8PC5 		21
#define 	DIO_u8PC6 		22
#define 	DIO_u8PC7 		23
				 
#define 	DIO_u8PD0 		24
#define 	DIO_u8PD1 		25
#define 	DIO_u8PD2 		26
#define 	DIO_u8PD3 		27
#define 	DIO_u8PD4 		28
#define 	DIO_u8PD5 		29
#define 	DIO_u8PD6 		30
#define 	DIO_u8PD7 		31

/*	channel level Values*/
#define 	DIO_u8LOW		0
#define 	DIO_u8HIGH		1


#define 	DIO_u8PORTA		0
#define 	DIO_u8PORTB		1
#define 	DIO_u8PORTC		2
#define 	DIO_u8PORTD		3

typedef enum
{
	Dio_enuOk,
	Dio_enuChannelError,
	Dio_enuLevelError,
	Dio_enuNullPtr,
	Dio_enuPortError

}Dio_tenuErrorStatus;

extern Dio_tenuErrorStatus Dio_enuWriteChannel(u8 Copy_u8ChannelId,u8 Copy_u8Level);
extern Dio_tenuErrorStatus Dio_enuReadChannel(u8 Copy_u8ChannelId,u8* Add_pu8ChannelLevel);
extern Dio_tenuErrorStatus Dio_enuWritePort(u8 Copy_u8PortId,u8 Copy_u8Value);
extern Dio_tenuErrorStatus Dio_enuReadPort(u8 Copy_u8PortId, pu8 Add_pu8PortLevel);
extern Dio_tenuErrorStatus Dio_enuFlipChannel (u8 Copy_u8ChannelId);

#endif		/* DIO_H_ */

/*---------------------------------------------------------------------------------------------------------------------------------------*/


