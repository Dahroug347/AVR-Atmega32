#include     "Std_types.h"
#include     "Int_vect_map.h"

#include     "Extint_cfg.h"
#include     "Extint.h"

#define      GICR		*((volatile u8*)0x5B)
#define      MCUCR		*((volatile u8*)0x55)
#define      MCUCSR		*((volatile u8*)0x54)

#define      GICR_EXT_INT_CLR	    0x1F
#define      INT0_MODE_CLEAR		0xFC
#define      INT1_MODE_CLEAR		0xF3
#define      INT2_MODE_CLEAR		0xBF

static pfunc INT0_func;
static pfunc INT1_func;
static pfunc INT2_func;

void Extint_vidInit (void)
{
	GICR &= GICR_EXT_INT_CLR;
	GICR |= (EXT_INT0_INIT_STATE | EXT_INT1_INIT_STATE | EXT_INT2_INIT_STATE);
#if EXT_INT0_INIT_STATE == EXT_INT0_ENABLE
	MCUCR &= INT0_MODE_CLEAR;
	MCUCR |= EXT_INT0_INIT_MODE;
#endif

#if EXT_INT1_INIT_STATE == EXT_INT1_ENABLE
	MCUCR &= INT1_MODE_CLEAR;
	MCUCR |= EXT_INT1_INIT_MODE;
#endif

#if EXT_INT2_INIT_STATE == EXT_INT2_ENABLE
	MCUCSR &= INT2_MODE_CLEAR;
	MCUCSR |= EXT_INT2_INIT_MODE;
#endif
}

void Extint_vidEnableAndSetPolarity (u8 EXT_INTx_ENABLE, u8 EXT_INTx_MODE)
{
		GICR   |= EXT_INTx_ENABLE;
	
	if(EXT_INTx_ENABLE == EXT_INT2_ENABLE)
	{
		MCUCSR |= EXT_INTx_MODE;
	}
	else 
	{
		MCUCR  |= EXT_INTx_MODE;
	}
}

void Extint_vidDisable (u8 EXT_INTx_DISABLE)
{
	GICR &= EXT_INTx_DISABLE;
}

Std_enuErrorStatus Extint_tenuSetCallBack_INT0 (pfunc func)
{
	u8 ret_val = OK;
	
	if (func != NULL)
	{
		INT0_func  = func;
	}

    else 
	{
		ret_val = NULL_PTR;
	}
	
		return ret_val;
}

Std_enuErrorStatus Extint_tenuSetCallBack_INT1 (pfunc func)
{
	u8 ret_val = OK;
	
	if (func != NULL)
	{
		INT1_func  = func;
	}

    else 
	{
		ret_val = NULL_PTR;
	}
	
		return ret_val;
}

Std_enuErrorStatus Extint_tenuSetCallBack_INT2 (pfunc func)
{
	u8 ret_val = OK;
	
	if (func != NULL)
	{
		INT2_func  = func;
	}

    else 
	{
		ret_val = NULL_PTR;
	}
	
		return ret_val;
}

void EXT_INT0_Handler (void)
{
 if (INT0_func != NULL)
	{
		INT0_func();
	}
}
void EXT_INT1_Handler (void)
{
 if (INT1_func != NULL)
	{
		INT1_func();
	}
}

void EXT_INT2_Handler (void)
{
 if (INT2_func != NULL)
	{
		INT2_func();
	}
}
