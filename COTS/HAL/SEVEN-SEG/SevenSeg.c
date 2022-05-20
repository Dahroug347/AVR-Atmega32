
#include "Std_types.h"
#include "Delay_ms.h"

#include "Dio.h"

#include "SevenSeg.h"
#include "SevenSeg_cfg.h"

typedef struct
{
		u8 ones;
		u8 tens;
}sSevSeg_t;

#define 	   SEVSEG_HEXSYSTEM			  16
#define        SEVSEG_DELAY	          	  11
#define        SEVSEG_HOLD_VALUE          20
#define 	   SEVSEG_MAX_DISPLAYS        17

#if  SEVSEG_TYPE == SEVSEG_CATHODE
/* All Displays that can be shown on one seven segment of type CATHODE*/
#define 	   SEVSEG_CATHODE_0		      0x5F
#define 	   SEVSEG_CATHODE_1		      0x6
#define 	   SEVSEG_CATHODE_2		      0x3B
#define 	   SEVSEG_CATHODE_3		      0x2F
#define 	   SEVSEG_CATHODE_4		      0x66
#define 	   SEVSEG_CATHODE_5		      0x6D
#define 	   SEVSEG_CATHODE_6		      0x7D
#define 	   SEVSEG_CATHODE_7		      0x7
#define 	   SEVSEG_CATHODE_8		      0x7F
#define 	   SEVSEG_CATHODE_9		      0x6F
#define 	   SEVSEG_CATHODE_A		      0x77
#define 	   SEVSEG_CATHODE_B		      0x7C
#define 	   SEVSEG_CATHODE_C		      0x59
#define 	   SEVSEG_CATHODE_D		      0xBE
#define 	   SEVSEG_CATHODE_E		      0x79
#define 	   SEVSEG_CATHODE_F		      0x71
#define 	   SEVSEG_CATHODE_DOT	      0x80

#else
/* All Displays that can be shown on one seven segment of type ANODE*/
#define 	   SEVSEG_ANODE_0		      0xA0
#define 	   SEVSEG_ANODE_1		      0xF9
#define 	   SEVSEG_ANODE_2		      0xC4
#define 	   SEVSEG_ANODE_3		      0xD0
#define 	   SEVSEG_ANODE_4		      0x99
#define 	   SEVSEG_ANODE_5		      0x92
#define 	   SEVSEG_ANODE_6		      0x82
#define 	   SEVSEG_ANODE_7		      0xF8
#define 	   SEVSEG_ANODE_8		      0x80
#define 	   SEVSEG_ANODE_9		      0x90
#define 	   SEVSEG_ANODE_A		      0x88
#define 	   SEVSEG_ANODE_B		      0x83
#define 	   SEVSEG_ANODE_C		      0xA6
#define 	   SEVSEG_ANODE_D		      0x41
#define 	   SEVSEG_ANODE_E		      0x86
#define 	   SEVSEG_ANODE_F		      0x8E
#define 	   SEVSEG_ANODE_DOT	     	  0x7F

#endif

static sSevSeg_t  SevenSeg_strSplitNum (u8 num)
{
	sSevSeg_t sVar;
	
	{
		sVar.tens = num/SEVSEG_HEXSYSTEM;
		sVar.ones = num%SEVSEG_HEXSYSTEM;
	}

	
	return sVar;
}

/* Numbers to be displayed will be displayed in a HEX numbering system, So the largest value that can be displayed is "0xFF"  */
void SevenSeg_vidWriteNumber (u8 number)
{
	#if  SEVSEG_TYPE == SEVSEG_CATHODE
	
	u8 aSevSeg[17]   = {SEVSEG_CATHODE_0, SEVSEG_CATHODE_1, SEVSEG_CATHODE_2, SEVSEG_CATHODE_3, SEVSEG_CATHODE_4, SEVSEG_CATHODE_5,
			            SEVSEG_CATHODE_6, SEVSEG_CATHODE_7, SEVSEG_CATHODE_8, SEVSEG_CATHODE_9, SEVSEG_CATHODE_A, SEVSEG_CATHODE_B,
						SEVSEG_CATHODE_C, SEVSEG_CATHODE_D, SEVSEG_CATHODE_E, SEVSEG_CATHODE_F, SEVSEG_CATHODE_DOT
	                   };

		sSevSeg_t split = SevenSeg_strSplitNum(number);

	   	   	   	Dio_enuWriteChannel(SEVSEG_EN1_PIN, DIO_u8HIGH);
	   	   	   	Dio_enuWritePort(SEVSEG_PORT, aSevSeg[split.tens]);
	   	   	   	Dio_enuWriteChannel(SEVSEG_EN2_PIN, DIO_u8LOW);
	   			delay_ms (SEVSEG_DELAY);

	   			Dio_enuWriteChannel(SEVSEG_EN2_PIN, DIO_u8HIGH);
	   			Dio_enuWritePort(SEVSEG_PORT, aSevSeg[split.ones]);
	   			Dio_enuWriteChannel(SEVSEG_EN1_PIN, DIO_u8LOW);
	   			delay_ms (SEVSEG_DELAY);

	#elif SEVSEG_TYPE == SEVSEG_ANODE

	u8 aSevSeg[17]   = {SEVSEG_ANODE_0, SEVSEG_ANODE_1, SEVSEG_ANODE_2, SEVSEG_ANODE_3, SEVSEG_ANODE_4, SEVSEG_ANODE_5,
						SEVSEG_ANODE_6, SEVSEG_ANODE_7, SEVSEG_ANODE_8, SEVSEG_ANODE_9, SEVSEG_ANODE_A, SEVSEG_ANODE_B,
						SEVSEG_ANODE_C, SEVSEG_ANODE_D, SEVSEG_ANODE_E, SEVSEG_ANODE_F, SEVSEG_ANODE_DOT
					   };

		sSevSeg_t split = SevenSeg_strSplitNum(number);
		
				Dio_enuWriteChannel(SEVSEG_EN1_PIN, DIO_u8LOW);
				Dio_enuWritePort(SEVSEG_PORT, aSevSeg[split.tens]);
				Dio_enuWriteChannel(SEVSEG_EN2_PIN, DIO_u8HIGH);
				delay_ms (SEVSEG_DELAY);

				Dio_enuWriteChannel(SEVSEG_EN2_PIN, DIO_u8LOW);
				Dio_enuWritePort(SEVSEG_PORT, aSevSeg[split.ones]);
				Dio_enuWriteChannel(SEVSEG_EN1_PIN, DIO_u8HIGH);
				delay_ms (SEVSEG_DELAY);
	}
	
	#endif
}



