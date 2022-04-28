#ifndef     LCD_H_
#define     LCD_H_

/*****************************************************************************************************************
SECTION (0): 
- Macros that can be used by the application developer.
*****************************************************************************************************************/
#define 	LCD_CLEAR_DISP			0b00000001    /*A Command Value to clear LCD screen when LSB is 1*/

#define 	LCD_8_BIT				0b00010000	  /*A Command Value to set LCD in 8-bit operating mode when 5th bit is 1*/
#define 	LCD_4_BIT				0b00000000	  /*A Command Value to set LCD in 4-bit operating mode when 5th bit is 0*/

#define		LCD_BIG_FONT	   		0b00000100	  /*A Command Value to switch LCD to big Font when 3rd bit is 1*/
#define		LCD_SMALL_FONT	   		0b00000000    /*A Command Value to switch LCD to small Font when 3rd bit is 0*/

#define 	LCD_TWO_LINES			0b00001000	  /*A Command Value to set LCD in two lines operating mode when 4th bit is 1*/
#define 	LCD_ONE_LINE			0b00000000	  /*A Command Value to set LCD in two lines operating mode when 4th bit is 0*/

#define 	LCD_DISPLAY_ON			0b00001100	  /*A Command Value to set Display the LCD in when 4th & 3rd bits are all 1's*/

#define 	LCD_1ST_LINE      		0b10000000	  /*A Command Value to set LCD cursor at the beginning of the 1st line when 8th bit is 1*/
#define 	LCD_2ND_LINE      		0b11000000    /*A Command Value to set LCD cursor at the beginning of the 2nd line when 8th & 7th bits are all 1's*/

#define 	LCD_CGRAM_MODE     		0b01000000	  /*A Command value to switch the address pointer to the CGRAM*/
#define     LCD_DDRAM_MODE     	    0b10000000	  /*A Command value to switch the address pointer to the DDRAM*/

#define 	LCD_ARABIC_MODE		    0b00010000	  /*A Command value to make cursor shift from right to left by default*/
#define 	LCD_ENGLISH_MODE		0b00010100	  /*A Command value to make cursor shift from left to right by default*/
/*_______________________________________________________________________________________________________________________________________________________________*/


/*****************************************************************************************************************
SECTION (1): 
- Essential functions prototypes used by the application developer that can be directly performed by LCD hardware
*****************************************************************************************************************/
extern void Lcd_vidSendCommand (u8 Copy_u8Command);   /*This function sends 8-bit commands to lcd Microprocessor to be executed (clear display, blink cursor, etc...)*/

extern void Lcd_vidInit (void);                /*This function is used to put LCD in an initial mode of operation*/

extern void Lcd_vidDisplayCharacter (u8 Copy_u8character); /*This function is used to display any ascii stored character in CGROM on LCD-screen*/

extern void Lcd_vidCreateCustomCharacter (pu8 Copy_u8ArrCustomCharacter); /*This function is used to display any custom character built and stored in CGRAM on LCD-screen*/
/*_______________________________________________________________________________________________________________________________________________________________*/



/*************************************************************************************************************************************************************
SECTION (2):
- Service functions prototypes used by the application developer that can be indirectly performed by LCD hardware and will be handled through the Lcd-Manager
**************************************************************************************************************************************************************/
extern void Lcd_vidGoto (u8 Copy_u8Row, u8 Copy_u8Col);  /*This function is used to move the cursor at any given coordinate character in the LCD*/

extern void Lcd_vidDisplayNumber (u32 Copy_u8Num); /*This function is used to display any Non-ascii raw number on LCD-screen*/

extern void Lcd_vidDisplayString (pu8 Copy_strString); /*This function is used to display a string on LCD-screen*/
/*_______________________________________________________________________________________________________________________________________________________________*/


#endif
