/*
 * Port_prv.h
 *
 *  Created on: Mar 6, 2022
 *      Author: dahroug
 */

#ifndef 	PORT_PRV_H_
#define 	PORT_PRV_H_

#define 	DDRD 									*((volatile u8*)0x31)             /* Accessing  content of physical registers in the memory*/  
#define 	DDRC 									*((volatile u8*)0x34)					 
#define 	DDRB 									*((volatile u8*)0x37)
#define 	DDRA 									*((volatile u8*)0x3A)
										
#define 	PORTD 									*((volatile u8*)0x32)
#define 	PORTC 									*((volatile u8*)0x35)					 
#define 	PORTB 									*((volatile u8*)0x38)
#define 	PORTA 									*((volatile u8*)0x3B)

/* PORTS available in the Atmega32 */
#define 	PORT_PORTA								0
#define 	PORT_PORTB								1
#define 	PORT_PORTC								2
#define 	PORT_PORTD								3

/*	set pin direction function macros */
#define 	PORT_u8MCU_PINS							32
#define 	PORT_u8DIRECTIONS						2

/*	set pin mode function macros */
#define 	PORT_u8MODES							4

/* Port initialization function macros */
#define 	CONC(A,B,C,D,E,F,G,H)					CONC_HELPER(A,B,C,D,E,F,G,H)	
#define 	CONC_HELPER(A,B,C,D,E,F,G,H)			0b##A##B##C##D##E##F##G##H

#define 	DDRA_INIT_VALUE 						CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define 	DDRB_INIT_VALUE 						CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define 	DDRC_INIT_VALUE 						CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define 	DDRD_INIT_VALUE 						CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)
					
#define 	PORTA_INIT_VALUE						CONC(PORTA_PIN7_VALUE,PORTA_PIN6_VALUE,PORTA_PIN5_VALUE,PORTA_PIN4_VALUE,PORTA_PIN3_VALUE,PORTA_PIN2_VALUE,PORTA_PIN1_VALUE,PORTA_PIN0_VALUE)
#define 	PORTB_INIT_VALUE						CONC(PORTB_PIN7_VALUE,PORTB_PIN6_VALUE,PORTB_PIN5_VALUE,PORTB_PIN4_VALUE,PORTB_PIN3_VALUE,PORTB_PIN2_VALUE,PORTB_PIN1_VALUE,PORTB_PIN0_VALUE)
#define 	PORTC_INIT_VALUE						CONC(PORTC_PIN7_VALUE,PORTC_PIN6_VALUE,PORTC_PIN5_VALUE,PORTC_PIN4_VALUE,PORTC_PIN3_VALUE,PORTC_PIN2_VALUE,PORTC_PIN1_VALUE,PORTC_PIN0_VALUE)
#define 	PORTD_INIT_VALUE						CONC(PORTD_PIN7_VALUE,PORTD_PIN6_VALUE,PORTD_PIN5_VALUE,PORTD_PIN4_VALUE,PORTD_PIN3_VALUE,PORTD_PIN2_VALUE,PORTD_PIN1_VALUE,PORTD_PIN0_VALUE)


#endif 		/* PORT_PRV_H_ */

	

