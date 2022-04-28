#include "Std_types.h"
#include "Delay_ms.h"

#define   TM 		(322.0f)
#define   T1		3.5991667

void delay_ms (u32 time_ms)
{	
	   u32 i =0;
	   u32 count = (u32) ((float)(time_ms*1000) - (TM))/(T1);

	for (;i < count; i++)
	{
		asm("NOP");
	}
	
}
