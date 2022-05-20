#include "Std_types.h"

#include "Dio.h"

#include "Keypad.h"
#include "Keypad_cfg.h"


static u8 Keypad_u82DaButtonMap[NUMBER_OF_ROWS][NUMBER_OF_COLS] = {                           /*Keypad physical map the programmer wants*/
																	  {0x1,0x2,0x3,ENTER},
																	  {0x4,0x5,0x6,0xA},
																	  {0x7,0x8,0x9,0xB},
																	  {'*',0x0,'#',0xC}
																   };

u8 KeypaD_u8GetKey (void)
{

	static u8 aRowPinMap[NUMBER_OF_ROWS] = {ROW_1_PIN, ROW_2_PIN, ROW_3_PIN, ROW_4_PIN};

	static u8 aColPinMap[NUMBER_OF_COLS] = {COL_1_PIN, COL_2_PIN, COL_3_PIN, COL_4_PIN};
	
	static u8 Loc_su8PressedKey = NO_PRESSED_KEY;

	u8 Loc_u8RetPinVal;


	for (u8 row = 0; row < NUMBER_OF_ROWS; row ++)
	{
		if (Dio_enuReadChannel(aRowPinMap[row], &Loc_u8RetPinVal) == ROWS)
		{	
			for (u8 col = 0; col <NUMBER_OF_COLS; col++)
			{
				Dio_enuWriteChannel(aColPinMap[col], DIO_u8HIGH);
				
				if (Dio_enuReadChannel(aRowPinMap[row], &Loc_u8RetPinVal) == COLS)
				{
					Dio_enuWriteChannel(aColPinMap[col], DIO_u8LOW);
					Loc_su8PressedKey = Keypad_u82DaButtonMap [row][col];
				}
				else
				{
					
				}

				Dio_enuWriteChannel(aColPinMap[col], DIO_u8LOW);
			 }
		}
		else
		{

		}
	}
	
	return Loc_su8PressedKey;
}
