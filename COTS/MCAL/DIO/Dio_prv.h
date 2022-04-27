/*
 * DIO_Prv.h
 *
 *  Created on: Mar 10, 2022
 *      Author: Dahroug
 */

#ifndef DIO_PRV_H_
#define DIO_PRV_H_

#define     PIND 						*((volatile u8*)0x30)      /* Accessing  content of physical registers in the memory*/
#define     DDRD 						*((volatile u8*)0x31)
#define     PORTD						*((volatile u8*)0x32)
						
#define     PINC 						*((volatile u8*)0x33)
#define     DDRC 						*((volatile u8*)0x34)
#define     PORTC 						*((volatile u8*)0x35)
						
#define     PINB 						*((volatile u8*)0x36)
#define     DDRB 						*((volatile u8*)0x37)
#define     PORTB 						*((volatile u8*)0x38)
						
#define     PINA 						*((volatile u8*)0x39)
#define     DDRA 						*((volatile u8*)0x3A)
#define     PORTA 						*((volatile u8*)0x3B)


#define 	DIO_u8MCU_PINS				32
#define 	DIO_u8LEVELS				 2
#define 	DIO_u8MCU_PORTS				 4

#endif

