/****************************************************************************************************************************
 SECTION (0):
 - Inclusion SECTION (including libraries, services, modules from MCAL layer and LCD driver header files)
 *****************************************************************************************************************************/
/* libs */
#include "Std_types.h"
#include "Bit_utils.h"
#include "Delay_ms.h"

/* MCAL */
#include "Dio.h"

/* HAL --> LCD */
#include "Lcd.h"
#include "Lcd_prv.h"
#include "Lcd_cfg.h"
/*_______________________________________________________________________________________________________________________________________________________________*/

/****************************************************************************************************************************
 SECTION (1):
 - Private functions used by the LCD driver owner developer that helps and simplifying in user functions development
 *****************************************************************************************************************************/
static void Lcd_vidSetEnablePulse(void)
{
	Dio_enuWriteChannel(LCD_EN_PIN, LCD_EN_HIGH);
	delay_ms(LCD_EN_DELAY);
	Dio_enuWriteChannel(LCD_EN_PIN, LCD_EN_LOW);
	delay_ms(LCD_EN_DELAY);
}
/*_______________________________________________________________________________________________________________________________________________________________*/

/****************************************************************************************************************************
 SECTION (2):
 - Essential functions used by the application developer that can be directly performed by LCD hardware
 *****************************************************************************************************************************/
void Lcd_vidSendCommand(u8 Copy_u8Command)
{
	Dio_enuWriteChannel(LCD_RS_PIN, LCD_RS_CMD);
	Dio_enuWriteChannel(LCD_RW_PIN, LCD_RW_WRITE);

#if LCD_BIT_MODE == LCD_8_BIT

	Dio_enuWriteChannel(LCD_D0_PIN, (GET_BIT(Copy_u8Command, LCD_D0_INDEX))); //  ((Copy_u8Command>>D0)&1)
	Dio_enuWriteChannel(LCD_D1_PIN, (GET_BIT(Copy_u8Command, LCD_D1_INDEX)));
	Dio_enuWriteChannel(LCD_D2_PIN, (GET_BIT(Copy_u8Command, LCD_D2_INDEX)));
	Dio_enuWriteChannel(LCD_D3_PIN, (GET_BIT(Copy_u8Command, LCD_D3_INDEX)));
	Dio_enuWriteChannel(LCD_D4_PIN, (GET_BIT(Copy_u8Command, LCD_D4_INDEX)));
	Dio_enuWriteChannel(LCD_D5_PIN, (GET_BIT(Copy_u8Command, LCD_D5_INDEX)));
	Dio_enuWriteChannel(LCD_D6_PIN, (GET_BIT(Copy_u8Command, LCD_D6_INDEX)));
	Dio_enuWriteChannel(LCD_D7_PIN, (GET_BIT(Copy_u8Command, LCD_D7_INDEX)));

	Lcd_vidSetEnablePulse();

	if (Copy_u8Command == LCD_CLEAR_DISP)
	{
		delay_ms(LCD_CLR_DISP_DELAY);
	}
	else
	{

	}

#elif LCD_BIT_MODE == LCD_4_BIT

	Dio_enuWriteChannel(LCD_D4_PIN, (GET_BIT(Copy_u8Command,LCD_D4_INDEX)));
	Dio_enuWriteChannel(LCD_D5_PIN, (GET_BIT(Copy_u8Command,LCD_D5_INDEX)));
	Dio_enuWriteChannel(LCD_D6_PIN, (GET_BIT(Copy_u8Command,LCD_D6_INDEX)));
	Dio_enuWriteChannel(LCD_D7_PIN, (GET_BIT(Copy_u8Command,LCD_D7_INDEX)));
	Lcd_vidSetEnablePulse();

	Dio_enuWriteChannel(LCD_D4_PIN, (GET_BIT(Copy_u8Command,LCD_D0_INDEX)));
	Dio_enuWriteChannel(LCD_D5_PIN, (GET_BIT(Copy_u8Command,LCD_D1_INDEX)));
	Dio_enuWriteChannel(LCD_D6_PIN, (GET_BIT(Copy_u8Command,LCD_D2_INDEX)));
	Dio_enuWriteChannel(LCD_D7_PIN, (GET_BIT(Copy_u8Command,LCD_D3_INDEX)));
	Lcd_vidSetEnablePulse();

	if (Copy_u8Command== LCD_CLEAR_DISP)
	{
		delay_ms(LCD_CLR_DISP_DELAY);
	}
	else
	{

	}
#else
#error "Invalid Data-length in function Lcd_vidSendCommand"

#endif
}

void Lcd_vidInit(void)
{
	delay_ms(LCD_INIT_DELAY);

#if LCD_BIT_MODE == LCD_8_BIT

	LCD_vidWriteCmd(LCD_INIT_FUNC_SET | LCD_FONT_SIZE | LCD_LINES_NUM | LCD_BIT_MODE);
	Lcd_vidSetEnablePulse();
	LCD_vidWriteCmd(LCD_DISPLAY_ON);
	Lcd_vidSetEnablePulse();
	LCD_vidWriteCmd(LCD_CLEAR_DISP);
	Lcd_vidSetEnablePulse();

#elif LCD_BIT_MODE == LCD_4_BIT

	LCD_vidWriteCmd (LCD_INIT_FUNC_SET);
	LCD_vidWriteCmd ((LCD_FONT_SIZE | LCD_LINES_NUM) << LCD_RSH_4BITS);
	Lcd_vidSetEnablePulse();

	LCD_vidWriteCmd(LCD_DISPLAY_ON << LCD_RSH_4BITS );
	Lcd_vidSetEnablePulse();

	LCD_vidWriteCmd(LCD_CLEAR_DISP << LCD_RSH_4BITS);
	Lcd_vidSetEnablePulse();

#endif
}

void Lcd_vidDisplayCharacter(u8 Copy_u8character)
{
	Dio_enuWriteChannel(LCD_RS_PIN, LCD_RS_DATA);
	Dio_enuWriteChannel(LCD_RW_PIN, LCD_RW_WRITE);

#if LCD_BIT_MODE == LCD_8_BIT

	Dio_enuWriteChannel(LCD_D0_PIN, (GET_BIT(Copy_u8character, LCD_D0_INDEX))); //  ((LCD_RSH_4BITS>>D0)&1)
	Dio_enuWriteChannel(LCD_D1_PIN, (GET_BIT(Copy_u8character, LCD_D1_INDEX)));
	Dio_enuWriteChannel(LCD_D2_PIN, (GET_BIT(Copy_u8character, LCD_D2_INDEX)));
	Dio_enuWriteChannel(LCD_D3_PIN, (GET_BIT(Copy_u8character, LCD_D3_INDEX)));
	Dio_enuWriteChannel(LCD_D4_PIN, (GET_BIT(Copy_u8character, LCD_D4_INDEX)));
	Dio_enuWriteChannel(LCD_D5_PIN, (GET_BIT(Copy_u8character, LCD_D5_INDEX)));
	Dio_enuWriteChannel(LCD_D6_PIN, (GET_BIT(Copy_u8character, LCD_D6_INDEX)));
	Dio_enuWriteChannel(LCD_D7_PIN, (GET_BIT(Copy_u8character, LCD_D7_INDEX)));

	Lcd_vidSetEnablePulse();

#elif LCD_BIT_MODE == LCD_4_BIT

	Dio_enuWriteChannel(LCD_D4_PIN, (GET_BIT(Copy_u8character,LCD_D4_INDEX)));
	Dio_enuWriteChannel(LCD_D5_PIN, (GET_BIT(Copy_u8character,LCD_D5_INDEX)));
	Dio_enuWriteChannel(LCD_D6_PIN, (GET_BIT(Copy_u8character,LCD_D6_INDEX)));
	Dio_enuWriteChannel(LCD_D7_PIN, (GET_BIT(Copy_u8character,LCD_D7_INDEX)));

	Lcd_vidSetEnablePulse();

	Dio_enuWriteChannel(LCD_D4_PIN, (GET_BIT(Copy_u8character,LCD_D0_INDEX)));
	Dio_enuWriteChannel(LCD_D5_PIN, (GET_BIT(Copy_u8character,LCD_D1_INDEX)));
	Dio_enuWriteChannel(LCD_D6_PIN, (GET_BIT(Copy_u8character,LCD_D2_INDEX)));
	Dio_enuWriteChannel(LCD_D7_PIN, (GET_BIT(Copy_u8character,LCD_D3_INDEX)));

	Lcd_vidSetEnablePulse();

#else
#error "Invalid Data-length in function Lcd_vidDisplayCharacter"

#endif
}

void Lcd_vidCreateCustomCharacter (pu8 Copy_u8ArrCustomCharacter)
{
	static u8 counter = 0;

	if (counter == 0)
	{
		LCD_vidWriteCmd(LCD_CGRAM_MODE);
	}
	else
	{

	}

	for(u8 charachter = LCD_ZERO_VAL ; charachter < LCD_BYTE_CHAR; charachter++)
	{
		LCD_vidWriteData(Copy_u8ArrCustomCharacter[charachter]);
	}

	counter ++;

}
/*void Lcd_vidCreateCustomCharacter(pu8 Copy_u8ArrCustomCharacter[], u8 Copy_u8CustomCharArrSize, u8 Copy_u8Row, u8 Copy_u8Col, u8 Copy_u8LangMode)
{
	LCD_vidWriteCmd(LCD_CGRAM_MODE);

	u8 counter = 0;

	u8* customCharId;

	customCharId = (u8*) calloc(Copy_u8CustomCharArrSize, sizeof(u8));

	while (counter < Copy_u8CustomCharArrSize)
	{
		customCharId[counter] = counter;

		for (u8 charachter = LCD_ZERO_VAL; charachter < LCD_BYTE_CHAR; charachter++)
		{
			LCD_vidWriteData(Copy_u8ArrCustomCharacter[counter][charachter]);
		}
		counter ++;
	}


	for(u8 counter = 0; counter < Copy_u8CustomCharArrSize; counter ++)
	{
		if (Copy_u8LangMode == LCD_ARABIC_MODE)
		{
			LCD_vidWriteCmd(Copy_u8Row|(15-Copy_u8Col));
		}
		else
		{
			LCD_vidWriteCmd(Copy_u8Row|Copy_u8Col);
		}

		LCD_vidWriteData(customCharId[counter]);
		Copy_u8Col ++;
	}

	LCD_vidWriteCmd(LCD_DDRAM_MODE);
}*/
