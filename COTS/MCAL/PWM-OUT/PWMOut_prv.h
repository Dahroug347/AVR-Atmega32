/*
 * PWMOut_prv.h
 *
 *  Created on: May 19, 2022
 *      Author: dahroug
 */

#ifndef       PWMOUT_PRV_H_
#define       PWMOUT_PRV_H_

#define 	ICR1			                    (*(volatile u16*)0x46)
#define 	OCR1B			                    (*(volatile u16*)0x48)
#define 	OCR1A			                    (*(volatile u16*)0x4A)
#define 	TCNT1			                    (*(volatile u16*)0x4C)
#define 	TCCR1			                    (*(volatile u16*)0x4E)

#define 	TCNT0 			                    (*(volatile u8*)0x52)
#define 	TCCR0 			                    (*(volatile u8*)0x53)
#define 	OCR0 			                    (*(volatile u8*)0x5C)

#define 	TCNT2 			                    (*(volatile u8*)0x44)
#define 	TCCR2 			                    (*(volatile u8*)0x45)
#define 	OCR2 			                    (*(volatile u8*)0x43)

#define 	TIFR 			                    (*(volatile u8*)0x58)
#define 	TIMSK			                    (*(volatile u8*)0x59)

#endif        /* PWMOUT_PRV_H_ */
