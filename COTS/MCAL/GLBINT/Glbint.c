#include "Std_types.h"
#include "Bit_Utils.h"

#include "Glbint.h"
#include "Glbint_prv.h"


static u8 glbint_u8Counter = GLBINT_u8CLRVAL;

void Glbint_vidInit (void)
{
	
}

void Glbint_vidEnable (void)
{
	SREG |= SREG_GIE;
}

void Glbint_vidDisable (void)
{
	SREG &= ~(SREG_GIE);
}

void Glbint_vidEnterCriticalSec  (void)
{
	if (GLBINT_u8CLRVAL == glbint_u8Counter)
	{
		SREG &= ~(SREG_GIE);
	}
	else
	{
		
	}
	glbint_u8Counter ++;
}

Std_enuErrorStatus  Glbint_enuExitCriticalSec  (void)
{
	Std_enuErrorStatus Loc_enuReturnValue = OK;
	
	if (GLBINT_u8FIRST_CRITICAL_SECTION_ENTRY == glbint_u8Counter)
	{
		SREG |= SREG_GIE;
	}
	else
	{
		
	}
	if (GLBINT_u8CLRVAL < glbint_u8Counter)
	{
		glbint_u8Counter --;
	}
	else
	{
		Loc_enuReturnValue = NOK;
	}

	return Loc_enuReturnValue;
}

