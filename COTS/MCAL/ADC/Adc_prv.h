/*
 * Adc_prv.h
 *
 *  Created on: May 18, 2022
 *      Author: dahroug
 */

#ifndef       ADC_PRV_H_
#define       ADC_PRV_H_

#define 	  ADC_ADMUX			                            (*(volatile u8*)0x27)
#define 	  ADC_ADCSRA		                            (*(volatile u8*)0x26)
#define 	  ADC_ADCH_L		                            (*(volatile u16*)0x24)
#define 	  ADC_ADCH		                            	(*(volatile u16*)0x25)
#define 	  ADC_ADCL		                            	(*(volatile u16*)0x24)

#define 	  ADC_SFIOR			                            (*(volatile u8*)0x50)

#define 	  ADC_ADMUX_CLR_MSK                             ((u8)0x00)
#define 	  ADC_ADCSRA_CLR_MSK                            ((u8)0x00)

#define 	  ADC_ADMUX_CHANNEL_CLR_MASK	                ((u8)0xE0)
#define 	  ADC_ADMUX_VOLT_REF_CLR_MASK	                ((u8)0x3F)

#define 	  ADC_ADCSRA_PRESCALE_MASK		                ((u8)0xF8)

#define 	  ADC_ADMUX_ADLAR_INDEX			                5

#define 	  ADC_ADCSRA_ADIE_INDEX			                3
#define 	  ADC_ADCSRA_ADIF_INDEX			                4
#define 	  ADC_ADCSRA_ADATE_INDEX     	                5
#define 	  ADC_ADCSRA_ADSC_INDEX			                6
#define 	  ADC_ADCSRA_ADEN_INDEX			                7

#define 	  ADC_MAX_CHANNEL_NUM							31

#define 	  ADC_ZERO									    0
#define 	  ADC_ONE										1

#define 	  ADC_LEFT_ADJUSTMENT_SHFT_MASK					6

#define 	  ADC_SFIOR_AUTO_TRIGGER_MODE_CLR_MASK			((u8)0x1F)

void ADC_Handler(void) __attribute__((signal,used));

#endif        /* ADC_PRV_H_ */
