/*
 * Port_Cfg.h
 *
 *  Created on: Mar 6, 2022
 *      Author: dahroug
 */

#ifndef 	PORT_CFG_H_
#define 	PORT_CFG_H_

/*Direction configuration: Choose 0 for Input , 1 for output*/

#define 	PORTA_PIN0_DIR							0
#define 	PORTA_PIN1_DIR	            			0
#define 	PORTA_PIN2_DIR	            			0
#define 	PORTA_PIN3_DIR	            			0
#define 	PORTA_PIN4_DIR	            			1
#define 	PORTA_PIN5_DIR	            			1
#define 	PORTA_PIN6_DIR	            			1
#define 	PORTA_PIN7_DIR	            			1
	
#define 	PORTB_PIN0_DIR							1
#define 	PORTB_PIN1_DIR	            			1
#define 	PORTB_PIN2_DIR	            			0
#define 	PORTB_PIN3_DIR	            			0
#define 	PORTB_PIN4_DIR	            			0
#define 	PORTB_PIN5_DIR	            			0
#define 	PORTB_PIN6_DIR	            			0
#define 	PORTB_PIN7_DIR	            			1
	
#define 	PORTC_PIN0_DIR							1
#define 	PORTC_PIN1_DIR	            			0
#define 	PORTC_PIN2_DIR	            			0
#define 	PORTC_PIN3_DIR	            			0
#define 	PORTC_PIN4_DIR	            			0
#define 	PORTC_PIN5_DIR	            			0
#define 	PORTC_PIN6_DIR	            			0
#define 	PORTC_PIN7_DIR	            			0
	
#define 	PORTD_PIN0_DIR							0
#define 	PORTD_PIN1_DIR	            			0
#define 	PORTD_PIN2_DIR	            			0
#define 	PORTD_PIN3_DIR	            			0
#define 	PORTD_PIN4_DIR	            			0
#define 	PORTD_PIN5_DIR	            			0
#define 	PORTD_PIN6_DIR	            			0
#define 	PORTD_PIN7_DIR	            			0

/*Initial value configuration: If output mode is activated: choose 0 for output low, 1 for output high
							   If Input mode is activated:  choose 0 for Input floating, 1 for Input pulled up
*/

#define 	PORTA_PIN0_VALUE						0
#define 	PORTA_PIN1_VALUE	            		0
#define 	PORTA_PIN2_VALUE	            		0
#define 	PORTA_PIN3_VALUE	            		0
#define 	PORTA_PIN4_VALUE	            		0
#define 	PORTA_PIN5_VALUE	            		0
#define 	PORTA_PIN6_VALUE	            		0
#define 	PORTA_PIN7_VALUE	            		0
			
#define 	PORTB_PIN0_VALUE						0
#define 	PORTB_PIN1_VALUE	            		0
#define 	PORTB_PIN2_VALUE	            		0
#define 	PORTB_PIN3_VALUE	            		1
#define 	PORTB_PIN4_VALUE	            		0
#define 	PORTB_PIN5_VALUE	            		0
#define 	PORTB_PIN6_VALUE	            		0
#define 	PORTB_PIN7_VALUE	            		0
			
#define 	PORTC_PIN0_VALUE						0
#define 	PORTC_PIN1_VALUE	            		0
#define 	PORTC_PIN2_VALUE	            		0
#define 	PORTC_PIN3_VALUE	            		0
#define 	PORTC_PIN4_VALUE	            		0
#define 	PORTC_PIN5_VALUE	            		0
#define 	PORTC_PIN6_VALUE	            		0
#define 	PORTC_PIN7_VALUE	            		0
			
#define 	PORTD_PIN0_VALUE						0
#define 	PORTD_PIN1_VALUE	            		0
#define 	PORTD_PIN2_VALUE	            		1
#define 	PORTD_PIN3_VALUE	            		1
#define 	PORTD_PIN4_VALUE	            		0
#define 	PORTD_PIN5_VALUE	            		0
#define 	PORTD_PIN6_VALUE	            		0
#define 	PORTD_PIN7_VALUE	            		0


#endif 		/* PORT_CFG_H_ */
