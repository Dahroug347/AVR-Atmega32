#ifndef        KEYPAD_CONFIG_H
#define        KEYPAD_CONFIG_H

#define        KEYPAD_INPUT        0                                                             /*PULL-UP*/
#define        KEYPAD_OUTPUT       1

#define        ROWS                KEYPAD_INPUT
#define        COLS                KEYPAD_OUTPUT

/*Options (portA,portB,portC,portD)*/
/*Options (pin0,pin1,pin2,pin3,pin4,pin5,pin6,pin7)*/

#define        ROW_1_PIN 	       DIO_u8PD0

#define        ROW_2_PIN 	       DIO_u8PD1

#define        ROW_3_PIN 	       DIO_u8PD2

#define        ROW_4_PIN 	       DIO_u8PD3

#define        COL_1_PIN 	       DIO_u8PD4

#define        COL_2_PIN 	       DIO_u8PD5

#define        COL_3_PIN 	       DIO_u8PD6

#define        COL_4_PIN 	       DIO_u8PD7

#define        ENTER  		       70

#define        NO_PRESSED_KEY      0xFF                                            /*default value*/

#endif
