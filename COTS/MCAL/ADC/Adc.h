/*
 * Adc.h
 *
 *  Created on: May 13, 2022
 *      Author: dahroug
 */

#ifndef         ADC_H_
#define         ADC_H_

typedef struct
{
	u8		Adc_u8CfgType_VoltageRef;
	u8 		Adc_u8CfgType_ResultAdjustment;                    // if left adjustment you can read ADCH only if you require 8 bit resolution only else you can ADCL first then ADCH if require all 10-bit
	u8 		Adc_u8CfgType_AutoTriggerMode;                     // free running mode or auto triggered
	u8 		Adc_u8CfgType_AutoTriggerSrc;
	u8 		Adc_u8CfgType_OperatingMode;                       //interrupt or polling ?
	u8 		Adc_u8CfgType_Prescaler;
}ADC_tCfg;


/* ADMUX REGISTER MACROS */
// Channel selection
#define 		ADC_ADMUX_ADC0		                        0x00
#define 		ADC_ADMUX_ADC1		                        0x01
#define 		ADC_ADMUX_ADC2		                        0x02
#define 		ADC_ADMUX_ADC3		                        0x03
#define 		ADC_ADMUX_ADC4		                        0x04
#define 		ADC_ADMUX_ADC5		                        0x05
#define 		ADC_ADMUX_ADC6		                        0x06
#define 		ADC_ADMUX_ADC7		                        0x07
#define 		ADC_ADMUX_ADC0_GAIN_10		                0x08
#define 		ADC_ADMUX_DIFF_ADC1_ADC0_GAIN_10	        0x09
#define 		ADC_ADMUX_ADC0_GAIN_200                     0x0A
#define 		ADC_ADMUX_DIFF_ADC1_ADC0_GAIN_200           0x0B
#define 		ADC_ADMUX_ADC2_GAIN_10                      0x0C
#define 		ADC_ADMUX_DIFF_ADC3_ADC2_GAIN_10            0x0D
#define 		ADC_ADMUX_ADC2_GAIN_200                     0x0E
#define 		ADC_ADMUX_DIFF_ADC3_ADC2_GAIN_200           0x0F
#define 		ADC_ADMUX_DIFF_ADC0_ADC1	                0x10
#define 		ADC_ADMUX_DIFF_ADC1		                    0x11
#define 		ADC_ADMUX_DIFF_ADC2_ADC1		            0x12
#define 		ADC_ADMUX_DIFF_ADC3_ADC1		            0x13
#define 		ADC_ADMUX_DIFF_ADC4_ADC1		            0x14
#define 		ADC_ADMUX_DIFF_ADC5_ADC1		            0x15
#define 		ADC_ADMUX_DIFF_ADC6_ADC1		            0x16
#define 		ADC_ADMUX_DIFF_ADC7_ADC1		            0x17
#define 		ADC_ADMUX_DIFF_ADC0_ADC2		            0x18
#define 		ADC_ADMUX_DIFF_ADC1_ADC2		            0x19
#define 		ADC_ADMUX_DIFF_ADC2		                    0x1A
#define 		ADC_ADMUX_DIFF_ADC3_ADC2		            0x1B
#define 		ADC_ADMUX_DIFF_ADC4_ADC2		            0x1C
#define 		ADC_ADMUX_DIFF_ADC5_ADC2		            0x1D
#define 		ADC_ADMUX_VBG		                        0x1E
#define 		ADC_ADMUX_GND		                        0x1F

//Voltage reference selection
#define			ADC_ADMUX_REFSx_AREF						0x00
#define			ADC_ADMUX_REFSx_AVCC						0x40
#define			ADC_ADMUX_REFSx_VREF_INT					0xC0

//ADC adjustment result
#define 		ADC_ADMUX_ADLAR_LEFT						0x20


/* ADCSRA REGISTER MACROS */
//ADC enable
#define 		ADC_ADCSRA_ADEN								0x80                     // will be set in the init func to enable ADC peripheral
//ADC start conversion
#define 		ADC_ADCSRA_ADSC								0x40					 /* Start Adc conversion will be a standalone func*/
//ADC Auto-Trigger Enable
#define 		ADC_ADCSRA_ADATE							0x20
//ADC interrupt flag that indicates complete adc conversion ("READ-ONLY")
#define 		ADC_ADCSRA_ADIF								0x10                     /* FLAG to indicate a special status*/
//ADC interrupt of conversion complete is enabled
#define 		ADC_ADCSRA_ADIE								0x08

//ADC prescaler select bits
#define 		ADC_ADCSRA_PRESCALE_2_0						0x00
#define 		ADC_ADCSRA_PRESCALE_2_1						0x01
#define 		ADC_ADCSRA_PRESCALE_4  						0x02
#define 		ADC_ADCSRA_PRESCALE_8  						0x03
#define 		ADC_ADCSRA_PRESCALE_16 						0x04
#define 		ADC_ADCSRA_PRESCALE_32 						0x05
#define 		ADC_ADCSRA_PRESCALE_64 						0x06
#define 		ADC_ADCSRA_PRESCALE_128						0x07

/* SFIOR REGISTER MACROS RELATED TO ADC PERIPHERAL */
// ADC Mode (auto trigger or free running with options of triggering source if auto-trigger is selected)
#define 		ADC_SFIOR_ADTSxxx_FREE_RUNNING				0x00
#define 		ADC_SFIOR_ADTSxxx_AUTO_TRG_ALG_COMP			0x20
#define 		ADC_SFIOR_ADTSxxx_AUTO_TRG_EXTI0			0x40
#define 		ADC_SFIOR_ADTSxxx_AUTO_TRG_COMP0			0x60
#define 		ADC_SFIOR_ADTSxxx_AUTO_TRG_OVF0				0x80
#define 		ADC_SFIOR_ADTSxxx_AUTO_TRG_COMP1B			0xA0
#define 		ADC_SFIOR_ADTSxxx_AUTO_TRG_OVF1				0xC0
#define 		ADC_SFIOR_ADTSxxx_AUTO_TRG_CAPT1			0xE0


/*------------------------------------------Functions' prototypes-------------------------------------------------------*/
extern Std_enuErrorStatus ADC_tenuInit(ADC_tCfg* Add_tStrAdcUserConfiguration);
extern Std_enuErrorStatus ADC_tenuStartConversion (u8  	Copy_u8Channel);
extern Std_enuErrorStatus ADC_tenuGetAdcValue (u16* Add_u16DigitalValue);

extern Std_enuErrorStatus ADC_tenuRegisterCallBack(pfunc Add_tpfuncAdcComplete);

#endif          /* ADC_H_ */
