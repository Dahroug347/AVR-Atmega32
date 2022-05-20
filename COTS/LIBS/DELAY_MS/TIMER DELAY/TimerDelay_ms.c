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
		Gpt_enuEnableNotification(DELAY_TIMER);
	#elif DELAY_TIMER == TIMER1
		Gpt_enuRegisterCbf_TIM1_OVF(setDelayFlag);
		Gpt_enuEnableNotification(DELAY_TIMER);
	#else
		Gpt_enuRegisterCbf_TIM2_OVF(setDelayFlag);
		Gpt_enuEnableNotification(DELAY_TIMER);
	#endif

		flag = 1;
	  }

	  Gpt_enuStartTimer(DELAY_TIMER, Copy_u32TimeMsec);

	  while (Del_Glbu8Flag != 1)
	  {
		  asm("NOP");
	  }

	  Gpt_enuStopTimer(DELAY_TIMER);

	  Del_Glbu8Flag = 0;
  }

  return Loc_enuRetErrStatus;
}
