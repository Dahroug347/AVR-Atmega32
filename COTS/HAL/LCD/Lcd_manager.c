/****************************************************************************************************************************
SECTION (0): 
- Inclusion SECTION (including libraries, services, modules from MCAL layer and LCD driver header files)
*****************************************************************************************************************************/
/* libs */
#include "Std_types.h"

/* HAL --> LCD */
#include "Lcd.h"
#include "Lcd_prv.h"
#include "Lcd_cfg.h"
/*_______________________________________________________________________________________________________________________________________________________________*/


/****************************************************************************************************************************
SECTION (1): 
Service functions used by the application developer that can be indirectly performed by LCD hardware and will be handled through the Lcd-Manager
*****************************************************************************************************************************/
void Lcd_vidGoto (u8 Copy_u8Row, u8 Copy_u8Col)
{
	LCD_vidWriteCmd(Copy_u8Row | Copy_u8Col);    /* first input parameter refers to a MACRO indicates wetheryou need 1st or 2nd Line ,, while second input parameter is a user input to refer which coloumn he needs to reach and it ranges from (0-15)*/
}


void Lcd_vidDisplayNumber (u32 Copy_u8Num)
{
	u32   digit   = LCD_ZERO_VAL;
	u32   unit    = LCD_ZERO_VAL;
	u32   counter = LCD_ZERO_VAL;

    while (Copy_u8Num != LCD_ZERO_VAL)
    {
    	digit += Copy_u8Num%LCD_DECIMAL_BASE;

    	digit *= LCD_DECIMAL_BASE;

    	counter ++;

    	Copy_u8Num /= LCD_DECIMAL_BASE;
    }

    digit /= LCD_DECIMAL_BASE;

	while (counter != LCD_ZERO_VAL)
	{
		unit  = digit%LCD_DECIMAL_BASE;
		unit  += '0';
		LCD_vidWriteData(unit);
		counter --;
		digit = digit/LCD_DECIMAL_BASE;
	}
} 


void Lcd_vidDisplayString (pu8 Copy_strString)
{
	for(u8 character = LCD_ZERO_VAL ; Copy_strString[character] != '\0'; character++)
	{
		LCD_vidWriteData(Copy_strString[character]);
	}
} 
/*_______________________________________________________________________________________________________________________________________________________________*/


