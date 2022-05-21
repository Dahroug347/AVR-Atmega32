/*
 * Adc.c
 *
 *  Created on: May 13, 2022
 *      Author: dahroug
 */


#include "Std_types.h"
#include "Bit_utils.h"
#include "Int_vect_map.h"

#include "Adc.h"
#include "Adc_prv.h"
#include "Adc_cfg.h"

u16 	ADC_u16GlbAdcReadValue = ADC_ZERO;
pfunc 	ADC_pFuncAdcConversionComplete;

Std_enuErrorStatus ADC_tenuInit(ADC_tCfg* Add_tStrAdcUserConfiguration)
{
	Std_enuErrorStatus Loc_enuErrStatRetValue = OK;

	u8 				   Loc_u8ADSCRACfg = ADC_ZERO;

	if (Add_tStrAdcUserConfiguration == NULL)
	{
		Loc_enuErrStatRetValue = NULL_PTR;
	}
	else
	{
		ADC_ADMUX   = ADC_ADMUX_CLR_MSK;
		ADC_ADCSRA  = ADC_ADCSRA_CLR_MSK;

		ADC_SFIOR  &= ADC_SFIOR_AUTO_TRIGGER_MODE_CLR_MASK;

		ADC_ADMUX  |= (Add_tStrAdcUserConfiguration->Adc_u8CfgType_ResultAdjustment | Add_tStrAdcUserConfiguration->Adc_u8CfgType_VoltageRef);

		Loc_u8ADSCRACfg |= (Add_tStrAdcUserConfiguration->Adc_u8CfgType_Prescaler        | Add_tStrAdcUserConfiguration->Adc_u8CfgType_OperatingMode
				        |   Add_tStrAdcUserConfiguration->Adc_u8CfgType_AutoTriggerMode  | ADC_ADCSRA_ADEN);

		ADC_ADCSRA = Loc_u8ADSCRACfg;

		ADC_SFIOR  |= (Add_tStrAdcUserConfiguration->Adc_u8CfgType_AutoTriggerSrc);
	}

	return Loc_enuErrStatRetValue;
}

Std_enuErrorStatus ADC_tenuStartConversion (u8 Copy_u8Channel)
{
	Std_enuErrorStatus  Loc_tenuRetErrStatusValue = OK;

	if (Copy_u8Channel > ADC_MAX_CHANNEL_NUM)
	{
		Loc_tenuRetErrStatusValue = INVALID_ARG;
	}
	else
	{
		ADC_ADMUX  &= ADC_ADMUX_CHANNEL_CLR_MASK;
		ADC_ADMUX  |= Copy_u8Channel;

		ADC_ADCSRA |= ADC_ADCSRA_ADSC;
	}

	return Loc_tenuRetErrStatusValue;
}

Std_enuErrorStatus ADC_tenuGetAdcValue (u16* Add_u16DigitalValue)
{
	Std_enuErrorStatus Loc_tenuErrStatusValue = OK;

	u8 				   Loc_u8OperatingMode = ADC_ZERO;

	if (Add_u16DigitalValue == NULL)
	{
		Loc_tenuErrStatusValue = NULL_PTR;
	}
	else
	{
		Loc_u8OperatingMode = GET_BIT(ADC_ADCSRA, ADC_ADCSRA_ADIE_INDEX);

		if (Loc_u8OperatingMode == ADC_ONE)
		{
			*Add_u16DigitalValue = ADC_u16GlbAdcReadValue;
		}
		else
		{
			while ( (ADC_ADCSRA & ADC_ADCSRA_ADIF) == ADC_ZERO);

			ADC_ADCSRA &= ~(ADC_ADCSRA_ADIF);

			if ( (ADC_ADMUX & ADC_ADMUX_ADLAR_LEFT) != ADC_ZERO)
			{
				*Add_u16DigitalValue = (ADC_ADCH_L >> ADC_LEFT_ADJUSTMENT_SHFT_MASK);

			}
			else
			{
				*Add_u16DigitalValue = ADC_ADCH_L;
			}
		}
	}

	return Loc_tenuErrStatusValue;
}

Std_enuErrorStatus ADC_tenuRegisterCallBack(pfunc Add_tpfuncAdcComplete)
{
	Std_enuErrorStatus Loc_tenuErrStatusReturnValue = OK;

	if (Add_tpfuncAdcComplete == NULL)
	{
		Loc_tenuErrStatusReturnValue = NULL_PTR;
	}
	else
	{
		ADC_pFuncAdcConversionComplete = Add_tpfuncAdcComplete;
	}

	return Loc_tenuErrStatusReturnValue;
}

void ADC_Handler(void)
{

	if (ADC_pFuncAdcConversionComplete != NULL)
	{
		ADC_pFuncAdcConversionComplete();
	}

	if ( (ADC_ADMUX & ADC_ADMUX_ADLAR_LEFT) != ADC_ZERO)
	{
		ADC_u16GlbAdcReadValue = (ADC_ADCH_L >> ADC_LEFT_ADJUSTMENT_SHFT_MASK);
	}
	else
	{
		ADC_u16GlbAdcReadValue = (ADC_ADCH_L);
	}


}
