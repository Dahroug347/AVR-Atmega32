#ifndef     LCD_CFG_H_
#define     LCD_CFG_H_

/*LCD PINOUTS CONNECTIONS TO THE MCU OPTIONS (DIO_u8PAx -> DIO_u8PDx) where x ranges between (0-7)*/
#define 	LCD_EN_PIN		DIO_u8PD0
#define 	LCD_RW_PIN		DIO_u8PD1
#define 	LCD_RS_PIN		DIO_u8PD2

#define 	LCD_D0_PIN		DIO_u8PC0
#define 	LCD_D1_PIN		DIO_u8PC1
#define 	LCD_D2_PIN		DIO_u8PC2
#define 	LCD_D3_PIN		DIO_u8PC3
#define 	LCD_D4_PIN		DIO_u8PC4
#define 	LCD_D5_PIN		DIO_u8PC5
#define 	LCD_D6_PIN		DIO_u8PC6
#define 	LCD_D7_PIN		DIO_u8PC7
/*____________________________________________________*/



/**********************
Options:
	LCD_8_BIT
	LCD_4_BIT
**********************/
#define 	LCD_BIT_MODE	     LCD_8_BIT
/*____________________________________________________*/


/**********************
Options:
	LCD_SMALL_FONT
	LCD_BIG_FONT
**********************/
#define		LCD_FONT_SIZE	     LCD_BIG_FONT
/*____________________________________________________*/


/**********************
Options:
	LCD_TWO_LINES
	LCD_ONE_LINE	
**********************/
#define		LCD_LINES_NUM	     LCD_TWO_LINES
/*____________________________________________________*/

#endif
