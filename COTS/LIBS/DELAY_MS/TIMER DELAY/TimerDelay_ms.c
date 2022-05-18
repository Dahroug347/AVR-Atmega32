/*
 * TimerDelay_ms.c
 *
 *  Created on: May 18, 2022
 *      Author: dahroug
 */

#include "Std_types.h"

#include "Gpt.h"

#include "TimerDelay_ms.h"
#include "TimerDelay_ms_cfg.h"

static u8 Del_Glbu8Flag = 0;

static void setDelayFlag (void)
{
	Del_Glbu8Flag = 1;
}

Std_enuErrorStatus TimerDelay_ms (u32 Copy_u32TimeMsec)
{
  Std_enuErrorStatus Loc_enuRetErrStatus = OK;

  static u8 flag = 0;

  if (Copy_u32TimeMsec > REG_32_COUNT)
  {
	  Loc_enuRetErrStatus = INVALID_ARG;
  }

  else
  {
	  if (flag == 0)
	  {
		Gpt_enuInit();
	#if DELAY_TIMER == TIMER0
		Gpt_enuRegisterCbf_TIM0_OVF(setDelayFlag);
	#elif DELAY_TIMER == TIMER1
		Gpt_enuRegisterCbf_TIM1_OVF(setDelayFlag);
	#else
		Gpt_enuRegisterCbf_TIM2_OVF(setDelayFlag);
	#endif
		flag = 1;
	  }

	  Gpt_enuStartTimer(Copy_u32TimeMsec, DELAY_TIMER);

	  while (Del_Glbu8Flag != 1)
	  {
		  asm("NOP");
	  }

	  Del_Glbu8Flag = 0;
  }

  return Loc_enuRetErrStatus;
}
