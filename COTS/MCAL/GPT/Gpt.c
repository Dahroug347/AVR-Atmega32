#include "Std_types.h"
#include "Int_vect_map.h"

#include "Glbint.h"
#include "Gpt.h"
#include "Gpt_prv.h"
#include "Gpt_cfg.h"

#if TIMER_0
	#if 	TIMER0_CLK_SRC == INTCLK
		#define 	TIMER0_PRESCALER 	INTCLK

	#elif 	TIMER0_CLK_SRC == INTCLK_PRESCALE_8

		#define 	TIMER0_PRESCALER 	PRESCALER_8

	#elif 	TIMER0_CLK_SRC == INTCLK_PRESCALE_64

		#define 	TIMER0_PRESCALER 	PRESCALER_64

	#elif 	TIMER0_CLK_SRC == INTCLK_PRESCALE_256

		#define 	TIMER0_PRESCALER 	PRESCALER_256

	#elif 	TIMER0_CLK_SRC == INTCLK_PRESCALE_1024

		#define 	TIMER0_PRESCALER 	PRESCALER_1024
	#endif
#endif

#if TIMER_1
	#if 	TIMER1_CLK_SRC == INTCLK
		#define 	TIMER1_PRESCALER 	INTCLK

	#elif 	TIMER1_CLK_SRC == INTCLK_PRESCALE_8

		#define 	TIMER1_PRESCALER 	PRESCALER_8

	#elif 	TIMER1_CLK_SRC == INTCLK_PRESCALE_64

		#define 	TIMER1_PRESCALER 	PRESCALER_64

	#elif 	TIMER1_CLK_SRC == INTCLK_PRESCALE_256

		#define 	TIMER1_PRESCALER 	PRESCALER_256

	#elif 	TIMER1_CLK_SRC == INTCLK_PRESCALE_1024

		#define 	TIMER1_PRESCALER 	PRESCALER_1024
	#endif
#endif

#if TIMER_2
	#if 	TIMER2_CLK_SRC == INTCLK2
		#define 	TIMER2_PRESCALER 	INTCLK2

	#elif 	TIMER2_CLK_SRC == INTCLK2_PRESCALE_8

		#define 	TIMER2_PRESCALER 	PRESCALER_8

	#elif 	TIMER2_CLK_SRC == INTCLK2_PRESCALE_32

		#define 	TIMER2_PRESCALER 	PRESCALER_32

	#elif 	TIMER2_CLK_SRC == INTCLK2_PRESCALE_64

		#define 	TIMER2_PRESCALER 	PRESCALER_64

	#elif 	TIMER2_CLK_SRC == INTCLK2_PRESCALE_128

		#define 	TIMER2_PRESCALER 	PRESCALER_128

	#elif 	TIMER2_CLK_SRC == INTCLK2_PRESCALE_256

		#define 	TIMER2_PRESCALER 	PRESCALER_256

	#elif 	TIMER2_CLK_SRC == INTCLK2_PRESCALE_1024

		#define 	TIMER2_PRESCALER 	PRESCALER_1024
	#endif
#endif


#if TIMER_1

	static pfunc Gpt_pfunTIMER1_Ov_ISR;
	static pfunc Gpt_pfunTIMER1_CompA_ISR;
	static pfunc Gpt_pfunTIMER1_CompB_ISR;
	static pfunc Gpt_pfunTIMER1_Icu_ISR;

	static f32 Gpt_sf32OvfTimeOfTimer1 = (f32) TIMER1_PRESCALER*SEC_IN_MILLI*REG_16_COUNT / FREQ_CPU;

	static volatile f32 Gpt_svf32Timer1NoOfOVF   = GPT_CLR_VAL;

	static volatile u32 Gpt_svu32Timer1IntCount  = GPT_CLR_VAL;

	static u32 Gpt_su32Timer1StartTime           = GPT_CLR_VAL;

	static volatile u16 Gpt_svu16TCNT1InitValue  = GPT_CLR_VAL;
#endif	

#if TIMER_0

	static pfunc Gpt_pfunTIMER0_Ov_ISR;
	static pfunc Gpt_pfunTIMER0_Comp_ISR;

	static f32 Gpt_sf32OvfTimeOfTimer0 = (f32) TIMER0_PRESCALER*SEC_IN_MILLI*REG_8_COUNT / FREQ_CPU;

	static volatile u32 Gpt_svu32Timer0IntCount  = GPT_CLR_VAL;

	static u32 Gpt_su32Timer0StartTime           = GPT_CLR_VAL;

	static volatile f32 Gpt_svf32Timer0NoOfOVF   = GPT_CLR_VAL;

	static volatile u8  Gpt_svu8TCNT0InitValue   = GPT_CLR_VAL;
#endif

#if TIMER_2

	static pfunc Gpt_pfunTIMER2_Ov_ISR;
	static pfunc Gpt_pfunTIMER2_Comp_ISR;

	static f32 Gpt_sf32OvfTimeOfTimer2 = (f32) TIMER2_PRESCALER*SEC_IN_MILLI*REG_8_COUNT / FREQ_CPU;

	static volatile u32 Gpt_svu32Timer2IntCount  = GPT_CLR_VAL;

	static u32 Gpt_su32Timer2StartTime           = GPT_CLR_VAL;

	static volatile f32 Gpt_svf32Timer2NoOfOVF   = GPT_CLR_VAL;

	static volatile u8  Gpt_svu8TCNT2InitValue   = GPT_CLR_VAL;
#endif	

Std_enuErrorStatus Gpt_enuInit (void)
{
	Std_enuErrorStatus Loc_enuErrState = OK;

	TIMSK = GPT_CLR_VAL;
	
#if TIMER_0 

	TCCR0 = TIMER0_CLR_REG_VALS;
	TCCR0 = (TIMER0_WAVGEN_MODE | TIMER0_COMPOP_MODE);
	
	TCNT0 = TIMER0_CLR_REG_VALS;
	OCR0  = TIMER0_CLR_REG_VALS;
	
#endif

#if TIMER_1   
	
	Glbint_vidEnterCriticalSec();

	TCCR1 = TIMER1_CLR_REG_VALS;
	TCCR1 = (TIMER1_WAVGEN_MODE | TIMER1_COMPA_MODE | TIMER1_COMPB_MODE);

	if (TIMER1_ICUNOISE_CANCEL == TCCR1_ICU_NOISECANCEL_OFF)
	{
		TCCR1 &= TIMER1_ICUNOISE_CANCEL;
	}
	else
	{
		TCCR1 |= TIMER1_ICUNOISE_CANCEL;
	}

  	if ( TIMER1_ICU_EDGE == TCCR1_ICU_RISE)
	{
		TCCR1 |= TIMER1_ICU_EDGE;
	}
	else
	{
		TCCR1 &= TIMER1_ICU_EDGE;
	}

 	ICR1  = TIMER1_CLR_REG_VALS;
 	OCR1B = TIMER1_CLR_REG_VALS;
	OCR1A = TIMER1_CLR_REG_VALS;
 	TCNT1 = TIMER1_CLR_REG_VALS;

	Loc_enuErrState = Glbint_enuExitCriticalSec ();

#endif

#if TIMER_2 

	TCCR2 = TIMER2_CLR_REG_VALS;
	TCCR2 = (TIMER2_WAVGEN_MODE | TIMER2_COMPOP_MODE);
	
	TCNT2 = TIMER2_CLR_REG_VALS;
	OCR2  = TIMER2_CLR_REG_VALS;
	
#endif

	return Loc_enuErrState;
}

Std_enuErrorStatus Gpt_enuGetTimeElapsed (u8 Copy_u8TimerId, pf32 Add_pf32TimeMs)
{
	Std_enuErrorStatus Loc_enuErrState = OK;
	if (Copy_u8TimerId >= GPT_CHANNELS_NUM)
	{
		Loc_enuErrState = INVALID_ARG;
	}
	else if (Add_pf32TimeMs == NULL)
	{
		Loc_enuErrState = NULL_PTR;
	}
	else
	{
		switch (Copy_u8TimerId)
		{
			case TIMER0:
				if (!TIMER_0)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
#if TIMER_0
					*Add_pf32TimeMs = (f32)Gpt_svu32Timer0IntCount * (Gpt_sf32OvfTimeOfTimer0 + (f32)(TCNT0/REG8_TOPVAL));
#endif
				}
			break;

			case TIMER1:
				if (!TIMER_1)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
#if TIMER_1
					Glbint_vidDisable();
					*Add_pf32TimeMs = (f32)Gpt_svu32Timer1IntCount * (Gpt_sf32OvfTimeOfTimer1 + (f32)(TCNT1/REG16_TOPVAL));
					Glbint_vidEnable();
#endif
				}
			break;

			case TIMER2:
				if (!TIMER_2)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
#if TIMER_2
					*Add_pf32TimeMs = (f32)Gpt_svu32Timer2IntCount * (Gpt_sf32OvfTimeOfTimer2 + (f32)(TCNT2/REG8_TOPVAL));
#endif
				}
			break;

			default:
			break;	
		}
	}
	
	return Loc_enuErrState;
}

Std_enuErrorStatus Gpt_enuGetTimeRemaining(u8 Copy_u8TimerId, pf32 Add_pf32TimeMs)
{
	Std_enuErrorStatus Loc_enuErrState = OK;
	if (Copy_u8TimerId >= GPT_CHANNELS_NUM)
	{
		Loc_enuErrState = INVALID_ARG;
	}
	else if (Add_pf32TimeMs == NULL)
	{
		Loc_enuErrState = NULL_PTR;
	}
	else
	{
		switch (Copy_u8TimerId)
		{
			case TIMER0:
				if (!TIMER_0)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
#if TIMER_0
					*Add_pf32TimeMs = (f32)Gpt_su32Timer0StartTime - ((f32)Gpt_svu32Timer0IntCount * (Gpt_sf32OvfTimeOfTimer0 + (f32)(TCNT0/REG8_TOPVAL)));
#endif
				}
			break;

			case TIMER1:
				if (!TIMER_1)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
#if TIMER_1
					Glbint_vidDisable();
					*Add_pf32TimeMs = (f32)Gpt_su32Timer1StartTime - ((f32)Gpt_svu32Timer1IntCount * (Gpt_sf32OvfTimeOfTimer1 + (f32)(TCNT1/REG16_TOPVAL)));
					Glbint_vidEnable();
#endif
				}
			break;

			case TIMER2:
				if (!TIMER_2)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
#if TIMER_2
					*Add_pf32TimeMs = (f32)Gpt_su32Timer2StartTime - ((f32)Gpt_svu32Timer2IntCount * (Gpt_sf32OvfTimeOfTimer2 + (f32)(TCNT2/REG8_TOPVAL)));
#endif
				}
			break;

			default:
			break;
		}
	}	
	return Loc_enuErrState;
}

Std_enuErrorStatus Gpt_enuStartTimer(u8 Copy_u8TimerId, u32 Copy_u32TimeMs)
{
	Std_enuErrorStatus Loc_enuErrState = OK;
	
	f32 Loc_f32NoOfOvfRemainder = GPT_CLR_VAL;

	if (Copy_u8TimerId >= GPT_CHANNELS_NUM || Copy_u32TimeMs > REG_32_COUNT )
	{
		Loc_enuErrState = INVALID_ARG;
	}
	else
	{
		switch (Copy_u8TimerId)
		{
			case TIMER0:
				if (!TIMER_0)
				{
					Loc_enuErrState = NOK;
				}
				else
				{

#if TIMER_0
					Gpt_su32Timer0StartTime = Copy_u32TimeMs;

					if ( Copy_u32TimeMs > ((u32)Gpt_sf32OvfTimeOfTimer0) )
					{

						Gpt_svf32Timer0NoOfOVF = (f32)Copy_u32TimeMs/Gpt_sf32OvfTimeOfTimer0;
						Loc_f32NoOfOvfRemainder = Gpt_svf32Timer0NoOfOVF - (u32)Gpt_svf32Timer0NoOfOVF;

						if (Loc_f32NoOfOvfRemainder > (f32)GPT_CLR_VAL)
						{
							Gpt_svf32Timer0NoOfOVF ++;
							Gpt_svu32Timer0IntCount = (u32)Gpt_svf32Timer0NoOfOVF;
							TCNT0 = REG8_TOPVAL - (Loc_f32NoOfOvfRemainder*REG_8_COUNT);
							Gpt_svu8TCNT0InitValue = TCNT0;
						}
						else
						{
							Gpt_svu32Timer0IntCount = (u32)Gpt_svf32Timer0NoOfOVF;
							TCNT0 = GPT_CLR_VAL;
							Gpt_svu8TCNT0InitValue = GPT_CLR_VAL;
						}
					}

					else if ((f32)Copy_u32TimeMs < Gpt_sf32OvfTimeOfTimer0)
					{

						Gpt_svf32Timer0NoOfOVF   = GPT_ONE_VAL;
						Gpt_svu32Timer0IntCount  = GPT_ONE_VAL;
						TCNT0 = REG8_TOPVAL - (u32)((f32)Copy_u32TimeMs*REG_8_COUNT/Gpt_sf32OvfTimeOfTimer0);
						Gpt_svu8TCNT0InitValue   = TCNT0;
					}

					else
					{


						Gpt_svf32Timer0NoOfOVF   = GPT_ONE_VAL;
						Gpt_svu32Timer0IntCount  = GPT_ONE_VAL;
						TCNT0 = GPT_CLR_VAL;
						Gpt_svu8TCNT0InitValue   = GPT_CLR_VAL;
					}
				TCCR0 |= TIMER0_CLK_SRC;
#endif
				}	
			break;

			case TIMER1:
				if (!TIMER_1)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
#if TIMER_1
				  Glbint_vidEnterCriticalSec();
					Gpt_su32Timer1StartTime = Copy_u32TimeMs;

					if ( Copy_u32TimeMs > ((u32)Gpt_sf32OvfTimeOfTimer1) )
					{
						Gpt_svf32Timer1NoOfOVF = (f32)Copy_u32TimeMs/Gpt_sf32OvfTimeOfTimer1;
						Loc_f32NoOfOvfRemainder = Gpt_svf32Timer1NoOfOVF - (u32)Gpt_svf32Timer1NoOfOVF;

						if (Loc_f32NoOfOvfRemainder > (f32)GPT_CLR_VAL)
						{
							Gpt_svf32Timer1NoOfOVF ++;
							Gpt_svu32Timer1IntCount = (u32)Gpt_svf32Timer1NoOfOVF;
							TCNT1 = REG16_TOPVAL - (Loc_f32NoOfOvfRemainder*REG_16_COUNT);
							Gpt_svu16TCNT1InitValue = TCNT1;
						}
						else
						{
							Gpt_svu32Timer1IntCount = (u32)Gpt_svf32Timer1NoOfOVF;
							TCNT1 = GPT_CLR_VAL;
							Gpt_svu16TCNT1InitValue = GPT_CLR_VAL;
						}
					}

					else if ((f32)Copy_u32TimeMs < Gpt_sf32OvfTimeOfTimer1)
					{
						Gpt_svf32Timer1NoOfOVF   = GPT_ONE_VAL;
						Gpt_svu32Timer1IntCount  = GPT_ONE_VAL;
						TCNT1 = REG16_TOPVAL - (u32)((f32)Copy_u32TimeMs*REG_16_COUNT/Gpt_sf32OvfTimeOfTimer1);
						Gpt_svu16TCNT1InitValue  = TCNT1;
					}

					else
					{
						Gpt_svf32Timer1NoOfOVF   = GPT_ONE_VAL;
						Gpt_svu32Timer1IntCount  = GPT_ONE_VAL;
						TCNT1 = GPT_CLR_VAL;
						Gpt_svu16TCNT1InitValue  = GPT_CLR_VAL;
					}
				  TCCR1 |= TIMER1_CLK_SRC;
				 Loc_enuErrState = Glbint_enuExitCriticalSec ();
#endif
				}
			break;

			case TIMER2:
				if (!TIMER_2)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
#if TIMER_2
					Gpt_su32Timer2StartTime = Copy_u32TimeMs;

					if ( Copy_u32TimeMs > ((u32)Gpt_sf32OvfTimeOfTimer2) )
					{
						Gpt_svf32Timer2NoOfOVF = (f32)Copy_u32TimeMs/Gpt_sf32OvfTimeOfTimer2;
						Loc_f32NoOfOvfRemainder = Gpt_svf32Timer2NoOfOVF - (u32)Gpt_svf32Timer2NoOfOVF;

						if (Loc_f32NoOfOvfRemainder > (f32)GPT_CLR_VAL)
						{
							Gpt_svf32Timer2NoOfOVF ++;
							Gpt_svu32Timer2IntCount = (u32)Gpt_svf32Timer2NoOfOVF;
							TCNT2 = REG8_TOPVAL - (Loc_f32NoOfOvfRemainder*REG_8_COUNT);
							Gpt_svu8TCNT2InitValue = TCNT2;
						}
						else
						{
							Gpt_svu32Timer2IntCount = (u32)Gpt_svf32Timer2NoOfOVF;
							TCNT2 = GPT_CLR_VAL;
							Gpt_svu8TCNT2InitValue = GPT_CLR_VAL;
						}
					}

					else if ((f32)Copy_u32TimeMs < Gpt_sf32OvfTimeOfTimer2)
					{
						Gpt_svf32Timer2NoOfOVF   = GPT_ONE_VAL;
						Gpt_svu32Timer2IntCount  = GPT_ONE_VAL;
						TCNT2 = REG8_TOPVAL - (u32)((f32)Copy_u32TimeMs*REG_8_COUNT/Gpt_sf32OvfTimeOfTimer2);
						Gpt_svu8TCNT2InitValue   = TCNT2;
					}

					else
					{
						Gpt_svf32Timer2NoOfOVF   = GPT_ONE_VAL;
						Gpt_svu32Timer2IntCount  = GPT_ONE_VAL;
						TCNT2 = GPT_CLR_VAL;
						Gpt_svu8TCNT2InitValue   = GPT_CLR_VAL;
					}

				TCCR2 |= TIMER2_CLK_SRC;
#endif
				}
			break;

			default:
			break;
		} 
	}
	return Loc_enuErrState;
}

Std_enuErrorStatus Gpt_enuStopTimer(u8 Copy_u8TimerId)
{
	Std_enuErrorStatus Loc_enuErrState = OK;

	if (Copy_u8TimerId >= GPT_CHANNELS_NUM)
	{
		Loc_enuErrState = INVALID_ARG;
	}
	else
	{
		switch (Copy_u8TimerId)
		{
			case TIMER0:
				if (!TIMER_0)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					TCCR0 &= TIMER0_STOP_VAL;
				}
			break;

			case TIMER1:
				if (!TIMER_1)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					Glbint_vidDisable();
					TCCR1 &= TIMER1_STOP_VAL;
					Glbint_vidEnable();
				}
			break;

			case TIMER2:
				if (!TIMER_2)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					TCCR2 &= TIMER2_STOP_VAL;
				}
			break;

			default:
			break;
		}
	}
	return Loc_enuErrState;
}

Std_enuErrorStatus Gpt_enuEnableNotification (u8 Copy_u8TimerId)
{
	Std_enuErrorStatus Loc_enuErrState = OK;

	if (Copy_u8TimerId >= GPT_CHANNELS_NUM)
	{
		Loc_enuErrState = INVALID_ARG;
	}
	else
	{
		switch (Copy_u8TimerId)
		{
			case TIMER0:
				if (!TIMER_0)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					TIMSK |= TIMER0_ENABLE_NOTIFICATION;
				}
			break;

			case TIMER1:
				if (!TIMER_1)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					Glbint_vidDisable();
					TIMSK |= TIMER1_ENABLE_NOTIFICATION;
					Glbint_vidEnable();
				}
			break;

			case TIMER2:
				if (!TIMER_2)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					TIMSK |= TIMER2_ENABLE_NOTIFICATION;
				}
			break;

			default:
			break;
		}
	}
	return Loc_enuErrState;
}

Std_enuErrorStatus Gpt_enuDisableNotification (u8 Copy_u8TimerId)
{
	Std_enuErrorStatus Loc_enuErrState = OK;

	if (Copy_u8TimerId >= GPT_CHANNELS_NUM)
	{
		Loc_enuErrState = INVALID_ARG;
	}
	else
	{
		switch (Copy_u8TimerId)
		{
			case TIMER0:
				if (!TIMER_0)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					TIMSK &= TIMER0_DISABLE_NOTIFICATION;
				}
			break;

			case TIMER1:
				if (!TIMER_1)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					Glbint_vidDisable();
					TIMSK &= TIMER1_DISABLE_NOTIFICATION;
					Glbint_vidEnable();
				}
			break;

			case TIMER2:
				if (!TIMER_2)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					TIMSK &= TIMER2_DISABLE_NOTIFICATION;
				}
			break;

			default:
			break;
		}
	}
	return Loc_enuErrState;
}

Std_enuErrorStatus Gpt_enuSetMode (u8 Copy_u8TimerId, u8 Copy_u8Mode)
{
	Std_enuErrorStatus Loc_enuErrState = OK;

	if ( (Copy_u8TimerId >= GPT_CHANNELS_NUM) ||  (Copy_u8Mode >= GPT_MODES_NUM) )
	{
		Loc_enuErrState = INVALID_ARG;
	}
	else
	{
		switch (Copy_u8TimerId)
		{
			case TIMER0:
				if (!TIMER_0)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					if (GPT_NORMAL_MODE == Copy_u8Mode)
					{
						TCCR0 |= (TCCR0_WAVGEN_NORMAL | TIMER0_COMPOP_MODE);
					}
					else
					{
						TCCR0 |= (TCCR0_WAVGEN_CTC | TIMER0_COMPOP_MODE);
					}
				}
			break;

			case TIMER1:
				if (!TIMER_1)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					if (GPT_NORMAL_MODE == Copy_u8Mode)
					{
						Glbint_vidDisable();
						TCCR1 |= (TCCR1_WAVGEN_NORMAL | TIMER1_COMPA_MODE | TIMER1_COMPB_MODE);
						Glbint_vidEnable();
					}
					else
					{
						Glbint_vidDisable();
						TCCR1 |= (TCCR1_WAVGEN_CTC | TIMER1_COMPA_MODE | TIMER1_COMPB_MODE);
						Glbint_vidEnable();
					}	
				}
			break;

			case TIMER2:
				if (!TIMER_2)
				{
					Loc_enuErrState = NOK;
				}
				else
				{
					if (GPT_NORMAL_MODE == Copy_u8Mode)
					{
						TCCR2 |= (TCCR2_WAVGEN_NORMAL | TIMER2_COMPOP_MODE);
					}
					else
					{
						TCCR2 |= (TCCR2_WAVGEN_CTC | TIMER2_COMPOP_MODE);
					}
				}
			break;

			default:
			break;
		}
	}
	return Loc_enuErrState;
}

#if TIMER_0

	Std_enuErrorStatus Gpt_enuRegisterCbf_TIM0_OVF    (pfunc Add_pfunIsr)
	{
		Std_enuErrorStatus Loc_enuErrState = OK;

		if (Add_pfunIsr != NULL)
		{
			Gpt_pfunTIMER0_Ov_ISR = Add_pfunIsr;
		}
		else
		{
			Loc_enuErrState = NULL_PTR;
		}
		return Loc_enuErrState;
	}

	Std_enuErrorStatus Gpt_enuRegisterCbf_TIM0_COMP   (pfunc Add_pfunIsr)
	{
		Std_enuErrorStatus Loc_enuErrState = OK;

		if (Add_pfunIsr != NULL)
		{
			Gpt_pfunTIMER0_Comp_ISR = Add_pfunIsr;
		}
		else
		{
			Loc_enuErrState = NULL_PTR;
		}
		return Loc_enuErrState;
	}

	void TIM0_OVF_Handler (void)
	{
		Gpt_svu32Timer0IntCount --;

		if ((Gpt_svu32Timer0IntCount == GPT_CLR_VAL) && (Gpt_pfunTIMER0_Ov_ISR != NULL))
		{
			TCNT0 = Gpt_svu8TCNT0InitValue;
			Gpt_pfunTIMER0_Ov_ISR();
			Gpt_svu32Timer0IntCount = Gpt_svf32Timer0NoOfOVF;
		}
		else
		{

		}
	}

	void TIM0_COMP_Handler  (void)
	{
		if (Gpt_pfunTIMER0_Comp_ISR != NULL)
		{
			Gpt_pfunTIMER0_Comp_ISR ();
		}
		else
		{

		}
	}
#endif

#if TIMER_1

	Std_enuErrorStatus Gpt_enuRegisterCbf_TIM1_OVF    (pfunc Add_pfunIsr)
	{
		Std_enuErrorStatus Loc_enuErrState = OK;

		if (Add_pfunIsr != NULL)
		{
			Gpt_pfunTIMER1_Ov_ISR = Add_pfunIsr;
		}
		else
		{
			Loc_enuErrState = NULL_PTR;
		}
		return Loc_enuErrState;
	}

	Std_enuErrorStatus Gpt_enuRegisterCbf_TIM1_COMPB   (pfunc Add_pfunIsr)
	{
		Std_enuErrorStatus Loc_enuErrState = OK;

		if (Add_pfunIsr != NULL)
		{
			Gpt_pfunTIMER1_CompB_ISR = Add_pfunIsr;
		}
		else
		{
			Loc_enuErrState = NULL_PTR;
		}
		return Loc_enuErrState;
	}

	Std_enuErrorStatus Gpt_enuRegisterCbf_TIM1_COMPA   (pfunc Add_pfunIsr)
	{
		Std_enuErrorStatus Loc_enuErrState = OK;

		if (Add_pfunIsr != NULL)
		{
			Gpt_pfunTIMER1_CompA_ISR = Add_pfunIsr;
		}
		else
		{
			Loc_enuErrState = NULL_PTR;
		}
		return Loc_enuErrState;
	}

	Std_enuErrorStatus Gpt_enuRegisterCbf_TIM1_CAPT   (pfunc Add_pfunIsr)
	{
		Std_enuErrorStatus Loc_enuErrState = OK;

		if (Add_pfunIsr != NULL)
		{
			Gpt_pfunTIMER1_Icu_ISR = Add_pfunIsr;
		}
		else
		{
			Loc_enuErrState = NULL_PTR;
		}
		return Loc_enuErrState;
	}

	void TIM1_OVF_Handler   (void)
	{
		Gpt_svu32Timer1IntCount --;

		if ((Gpt_svu32Timer1IntCount == GPT_CLR_VAL) && (Gpt_pfunTIMER1_Ov_ISR != NULL))
		{
			TCNT1 = Gpt_svu16TCNT1InitValue;
			Gpt_pfunTIMER1_Ov_ISR();
			Gpt_svu32Timer1IntCount = Gpt_svf32Timer1NoOfOVF;
		}
		else
		{

		}
	}

	void TIM1_COMPB_Handler (void)
	{
		if (Gpt_pfunTIMER1_CompB_ISR != NULL)
		{
			Gpt_pfunTIMER1_CompB_ISR ();
		}
		else
		{

		}
	}

	void TIM1_COMPA_Handler (void)
	{
		if (Gpt_pfunTIMER1_CompA_ISR != NULL)
		{
			Gpt_pfunTIMER1_CompA_ISR ();
		}
		else
		{

		}
	}

	void TIM1_CAPT_Handler  (void)
	{
		if (Gpt_pfunTIMER1_Icu_ISR != NULL)
		{
			Gpt_pfunTIMER1_Icu_ISR ();
		}
		else
		{

		}
	}

#endif

#if TIMER_2

	Std_enuErrorStatus Gpt_enuRegisterCbf_TIM2_OVF    (pfunc Add_pfunIsr)
	{
		Std_enuErrorStatus Loc_enuErrState = OK;

		if (Add_pfunIsr != NULL)
		{
			Gpt_pfunTIMER2_Ov_ISR = Add_pfunIsr;
		}
		else
		{
			Loc_enuErrState = NULL_PTR;
		}
		return Loc_enuErrState;
	}

	Std_enuErrorStatus Gpt_enuRegisterCbf_TIM2_COMP   (pfunc Add_pfunIsr)
	{
		Std_enuErrorStatus Loc_enuErrState = OK;

		if (Add_pfunIsr != NULL)
		{
			Gpt_pfunTIMER2_Comp_ISR = Add_pfunIsr;
		}
		else
		{
			Loc_enuErrState = NULL_PTR;
		}
		return Loc_enuErrState;
	}

	void TIM2_OVF_Handler (void)
	{
		Gpt_svu32Timer2IntCount --;

		if ((Gpt_svu32Timer2IntCount == GPT_CLR_VAL) && (Gpt_pfunTIMER2_Ov_ISR != NULL))
		{
			TCNT2 = Gpt_svu8TCNT2InitValue;
			Gpt_pfunTIMER2_Ov_ISR();
			Gpt_svu32Timer2IntCount = Gpt_svf32Timer2NoOfOVF;
		}
		else
		{

		}
	}

	void TIM2_COMP_Handler  (void)
	{
		if (Gpt_pfunTIMER2_Comp_ISR != NULL)
		{
			Gpt_pfunTIMER2_Comp_ISR ();
		}
		else
		{

		}
	}

#endif
/*----------------------------------------------------------------------------------------------------------------------------------*/
