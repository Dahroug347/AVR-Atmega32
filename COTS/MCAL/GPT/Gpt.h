#ifndef     GPT_H_
#define     GPT_H_

/*--------------------------------------------------- TIMERS (instances) -------------------------------------------------*/
#define 	TIMER0					        0
#define	    TIMER1					        1
#define 	TIMER2					        2
/*------------------------------------------------------------------------------------------------------------------------*/

/* ----------------------------------------------- Prescaler Options ---------------------------------------------*/
/* TCCR macros for TIMER_CLK with options: (no clk source "timer stopped", internal_clk 'no prescaling', prescale intclk/8, prescale intclk/64, prescale intclk/256, prescale intclk/1024, extclkT0 on falling, extclkT0 on rising*/		
#define 	INTCLK						    1
#define 	INTCLK_PRESCALE_8			    2
#define 	INTCLK_PRESCALE_64			    3
#define 	INTCLK_PRESCALE_256			    4
#define 	INTCLK_PRESCALE_1024		    5
#define 	EXTCLK_FALLT				    6
#define 	EXTCLK_RISET				    7
/*--------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------- GPT MODES -------------------------------------------------*/
#define 	GPT_NORMAL_MODE				    0
#define	    GPT_CTC_MODE				    1
/*------------------------------------------------------------------------------------------------------------------------*/

/* ---------------------------------------------- Timer 0 Macros ------------------------------------------------*/
/* ------- Default Values ----------- */

/* TCCR macros for wave generation modes with options: (normal, normal with Output signal on OC0,  phase correct, CTC, CTC with O/p signal on OC0, fast pwm) */
#define     TCCR0_WAVGEN_NORMAL				0x00
#define     TCCR0_WAVGEN_NORMAL_FOCS 		0x80  			/* Using the FOC0 "force o/p compare" (8th) bit 'SET', it forces an O/P signal on compare match on the OC0 pin in non-PWM modes it will consume high load on processor and affects its performance */

#define     TCCR0_PWM_PHASECORR				0x40

#define     TCCR0_WAVGEN_CTC				0x08            /* CTC is mainly used for controlling timers resolutions */
#define     TCCR0_WAVGEN_CTC_FOCS			0x88

#define     TCCR0_WAVGEN_FASTPWM			0x48


/* TCCR macros for o/p compare modes on compare match with options: (normal port operation no OC0, toggle OC0, clear OC0, Set OC0)*/
#define     TCCR0_COMPOP_NORMAL				0x00
#define     TCCR0_COMPOP_TOGGLE				0x10
#define     TCCR0_COMPOP_CLEAR				0x20
#define     TCCR0_COMPOP_SET				0x30
	
/*TIMSK macros for TIMER0 with options (Enable o/p compare & tov interrupt,  Disable interrupts for OCIE & TOVIE) */
#define     TIMSK_TIMER0_TOFIE_ENABLE		0x01
#define     TIMSK_TIMER0_OCIE_ENABLE		0x02
#define     TIMSK_TIMER0_TOFIE_DISABLE		0xFE    /*ANDING*/
#define     TIMSK_TIMER0_OCIE_DISABLE		0xFD    /*ANDING*/



/* TIFR macros for TIMER0 to check timer status flags with options (check o/p compare flag, check TOV0 flag).........  The following macro values are used as the bit numbers 'locations' in the register */
#define     TIFR_TOV0						0x00			/* to be checked*/
#define     TIFR_OCF0						0x01        	/* to be checked*/
/*------------------------------------------------------------------------------------------------------------------------------------------------*/		


/* ------------------------------- Timer 1 Macros ----------------------------------------- */

/* TCCR macros for wave generation modes with options: (normal, PWM_phasecorrect/8-bits, PWM_phasecorrect/9-bits, PWM_phasecorrect/10-bits, CTC, fast_pwm/8-bit, fast_pwm/9-bit, fast_pwm/10-bit, ) */
/* ------- Default Values ----------- */
#define 	TCCR1_DEFAULT_VALS				0x0000


#define     TCCR1_WAVGEN_NORMAL				0x0000
#define     TCCR1_WAVGEN_NORMAL_FOCBS		0X0400    		/* Using the FOC1A/B "force o/p compare"  bit 'SET', it forces an O/P signal on compare match on the OC1A/B pin in non-PWM modes it will consume high load on processor and affects its performance */
#define     TCCR1_WAVGEN_NORMAL_FOCAS		0X0800		
    
#define     TCCR1_PWM_PHASECORR_8 			0x0100  
#define     TCCR1_PWM_PHASECORR_9 			0x0200
#define     TCCR1_PWM_PHASECORR_10 			0x0300
    
#define     TCCR1_WAVGEN_CTC				0x0008
#define     TCCR1_WAVGEN_CTC_FOCBS			0x0408
#define     TCCR1_WAVGEN_CTC_FOCAS			0x0808
    
#define     TCCR1_WAVGEN_FASTPWM_8			0x0108
#define     TCCR1_WAVGEN_FASTPWM_9			0x0208
#define     TCCR1_WAVGEN_FASTPWM_10			0x0308
    
#define     TCCR1_PWM_PHASEFREQ_CORR_ICR	0x0010
#define     TCCR1_PWM_PHASEFREQ_CORR_OCRA	0x0110
    
#define     TCCR1_PWM_PAHSECORR_ICR			0x0210
#define     TCCR1_PWM_PAHSECORR_OCRA		0x0310
    
#define     TCRR1_WAVGEN_CTC_ICR			0x0018
#define     TCCR1_WAVGEN_CTC_ICR_FOCBS		0x0418
#define     TCCR1_WAVGEN_CTC_ICR_FOCAS		0x0818
    
#define     TCRR1_WAVGEN_FASTPWM_ICR		0x0218
#define     TCRR1_WAVGEN_FASTPWM_OCRA		0x0318
    


/* TCCR macros for o/p compare modes on compare match with options: (normal port operation no OC1A & oc1B, toggle OC1A/B, clear OC1A/B, Set OC1A/B) */

#define     TCCR1_COMPB_NORMAL				0x0000
#define     TCCR1_COMPB_TOGGLE				0x1000
#define     TCCR1_COMPB_CLEAR				0x2000
#define     TCCR1_COMPB_SET					0x3000	

#define     TCCR1_COMPA_NORMAL				0x0000
#define     TCCR1_COMPA_TOGGLE				0x4000
#define     TCCR1_COMPA_CLEAR				0x8000
#define     TCCR1_COMPA_SET					0xC000	



/* TCCR macros for ICU noise cancellation or standard*/
#define     TCCR1_ICU_NOISECANCEL_ON		0x0080			/* This will result in CPU delay of 4 cycles before writing the signal into the ICR */
#define     TCCR1_ICU_NOISECANCEL_OFF		0xFF7F			/* ANDING here */


/* TCCR macros for ICU edge select*/
#define     TCCR1_ICU_RISE					0x0040
#define     TCCR1_ICU_FALL					0xFFBF			/* ANDING here */


/*TIMSK macros for TIMER1 with options (Enable o/p compare & tov & ICU interrupt,  Disable interrupts for OCIE & TOVIE & ICU) */
#define     TIMSK_TIMER1_ICF1_ENABLE		0x20
#define     TIMSK_TIMER1_OCF1A_ENABLE		0x10
#define     TIMSK_TIMER1_OCF1B_ENABLE		0x08  		 
#define     TIMSK_TIMER1_TOV1_ENABLE		0x04
#define     TIMSK_TIMER1_ICF1_DISABLE		0xDF   /* when using this option do ANDING */
#define     TIMSK_TIMER1_OCF1A_DISABLE		0xEF   /* when using this option do ANDING */
#define     TIMSK_TIMER1_OCF1B_DISABLE		0xF7   /* when using this option do ANDING */
#define     TIMSK_TIMER1_TOV1_DISABLE		0xFB   /* when using this option do ANDING */

/* TIFR macros for TIMER1 to check timer status flags with options (check o/p compare flag, check TOV1 flag) .........  The following macro values are used as the bit numbers 'locations' in the register */
#define     TIFR_TOV1						0x02   		/* to be checked*/
#define     TIFR_OCF1B						0x03		/* to be checked*/
#define     TIFR_OCF1A						0x04   		/* to be checked*/
#define     TIFR_ICF1						0x05		/* to be checked*/	
/*------------------------------------------------------------------------------------------------------------------------------------------------*/


/* ---------------------------------------------- Timer 2 Macros ------------------------------------------------*/
/* ------- Default Values ----------- */
/* TCCR macros for wave generation modes with options: (normal, normal with Output signal on OC2,  phase correct, CTC, CTC with O/p signal on OC2, fast pwm) */
#define     TCCR2_WAVGEN_NORMAL				0x00
#define     TCCR2_WAVGEN_NORMAL_FOCS 		0x80  			/* Using the FOC2 "force o/p compare" (8th) bit 'SET', it forces an O/P signal on compare match on the OC2 pin in non-PWM modes it will consume high load on processor and affects its performance */

#define     TCCR2_PWM_PHASECORR				0x40

#define     TCCR2_WAVGEN_CTC				0x08            /* CTC is mainly used for controlling timers resolutions */
#define     TCCR2_WAVGEN_CTC_OCS			0x88

#define     TCCR2_WAVGEN_FASTPWM			0x48


/* TCCR macros for o/p compare modes on compare match with options: (normal port operation no OC2, toggle OC2, clear OC2, Set OC2)*/
#define     TCCR2_COMPOP_NORMAL				0x00
#define     TCCR2_COMPOP_TOGGLE				0x10
#define     TCCR2_COMPOP_CLEAR				0x20
#define     TCCR2_COMPOP_SET				0x30
	
/*TIMSK macros for TIMER2 with options (Enable o/p compare & tov interrupt,  Disable interrupts for OCIE & TOVIE) */
#define     TIMSK_TIMER2_TOFIE_ENABLE		0x40
#define     TIMSK_TIMER2_OCIE_ENABLE		0x80
#define     TIMSK_TIMER2_TOFIE_DISABLE		0xDF     /*ANDING*/
#define     TIMSK_TIMER2_OCIE_DISABLE		0xEF     /*ANDING*/



/* TIFR macros for TIMER2 to check timer status flags with options (check o/p compare flag, check TOV2 flag).........  The following macro values are used as the bit numbers 'locations' in the register */
#define     TIFR_TOV2						0x06			/* to be checked*/
#define     TIFR_OCF2						0x07        	/* to be checked*/

/* ----------------------------------------------- Prescaler Options For TIMER2 ---------------------------------------------*/
/* TCCR macros for TIMER_CLK with options: (no clk source "timer stopped", internal_clk 'no prescaling', prescale intclk/8, prescale intclk/64, prescale intclk/256, prescale intclk/1024, extclkT0 on falling, extclkT0 on rising*/
#define 	INTCLK2						    1
#define 	INTCLK2_PRESCALE_8			    2
#define 	INTCLK2_PRESCALE_32			    3
#define 	INTCLK2_PRESCALE_64			    4
#define 	INTCLK2_PRESCALE_128		    5
#define 	INTCLK2_PRESCALE_256			6
#define 	INTCLK2_PRESCALE_1024			7
/*--------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------------------*/


/* ---------------------------------------------- Function prototypes --------------------------------------- */
extern Std_enuErrorStatus Gpt_enuInit (void);
extern Std_enuErrorStatus Gpt_enuGetTimeElapsed (u8 Copy_u8TimerId, pf32 Add_pf32TimeMs);
extern Std_enuErrorStatus Gpt_enuGetTimeRemaining(u8 Copy_u8TimerId, pf32 Add_pf32TimeMs);
extern Std_enuErrorStatus Gpt_enuStartTimer(u8 Copy_u8TimerId, u32 Copy_u32TimeMs);
extern Std_enuErrorStatus Gpt_enuStopTimer(u8 Copy_u8TimerId);
extern Std_enuErrorStatus Gpt_enuEnableNotification (u8 Copy_u8TimerId);
extern Std_enuErrorStatus Gpt_enuDisableNotification (u8 Copy_u8TimerId);
extern Std_enuErrorStatus Gpt_enuSetMode (u8 Copy_u8TimerId, u8 Copy_u8Mode);

extern Std_enuErrorStatus Gpt_enuRegisterCbf_TIM0_OVF    (pfunc Add_pfunIsr);
extern Std_enuErrorStatus Gpt_enuRegisterCbf_TIM0_COMP   (pfunc Add_pfunIsr);
extern Std_enuErrorStatus Gpt_enuRegisterCbf_TIM1_OVF    (pfunc Add_pfunIsr);
extern Std_enuErrorStatus Gpt_enuRegisterCbf_TIM1_COMPB  (pfunc Add_pfunIsr);
extern Std_enuErrorStatus Gpt_enuRegisterCbf_TIM1_COMPA  (pfunc Add_pfunIsr);
extern Std_enuErrorStatus Gpt_enuRegisterCbf_TIM1_CAPT   (pfunc Add_pfunIsr);
extern Std_enuErrorStatus Gpt_enuRegisterCbf_TIM2_OVF    (pfunc Add_pfunIsr);
extern Std_enuErrorStatus Gpt_enuRegisterCbf_TIM2_COMP   (pfunc Add_pfunIsr);

#endif
