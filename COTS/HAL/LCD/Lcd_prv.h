#ifndef     LCD_PRV_H_
#define     LCD_PRV_H_

/*****************************************************************************************************************
SECTION (0):
- Macros that can be used by the Owner developer.
*****************************************************************************************************************/
/* LCD (RW/RS/EN) VALUES */
#define 	LCD_RS_CMD		         DIO_u8LOW
#define 	LCD_RW_WRITE  	         DIO_u8LOW
#define 	LCD_EN_LOW		         DIO_u8LOW

#define 	LCD_RS_DATA		         DIO_u8HIGH
#define 	LCD_RW_READ  	         DIO_u8HIGH
#define 	LCD_EN_HIGH		         DIO_u8HIGH


/* LCD PINS INDECIES */
#define 	LCD_D0_INDEX			 0
#define 	LCD_D1_INDEX			 1
#define 	LCD_D2_INDEX			 2
#define 	LCD_D3_INDEX			 3
#define 	LCD_D4_INDEX			 4
#define 	LCD_D5_INDEX			 5
#define 	LCD_D6_INDEX			 6
#define 	LCD_D7_INDEX			 7

/* DELAYS USED BY THE LCD MPU */
#define 	LCD_CLR_DISP_DELAY		 10
#define 	LCD_EN_DELAY		     2
#define 	LCD_INIT_DELAY			 40


/*Replacing user function name with a private name for the owner*/
#define 	LCD_vidWriteCmd		Lcd_vidSendCommand
#define 	LCD_vidWriteData 	Lcd_vidDisplayCharacter
#define 	LCD_vidWriteNum		Lcd_vidDisplayNumber

/*private Command macros values*/
#define 	LCD_INIT_FUNC_SET		 0b00100000 

/*general private macros values*/
#define 	LCD_RSH_4BITS			 4
#define 	LCD_ZERO_VAL			 0
#define 	LCD_BYTE_CHAR			 8
#define 	LCD_DECIMAL_BASE		 10	

#endif
