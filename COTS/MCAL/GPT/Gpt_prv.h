#ifndef     GPT_PRV_H_
#define     GPT_PRV_H_

/* --------------------------------------------- GPT REGISTER MAPPINGS --------------------------------------------*/
#define 	ICR1			                    (*(volatile u16*)0x46)
#define 	OCR1B			                    (*(volatile u16*)0x48)
#define 	OCR1A			                    (*(volatile u16*)0x4A)
#define 	TCNT1			                    (*(volatile u16*)0x4C)
#define 	TCCR1			                    (*(volatile u16*)0x4E)

#define 	TCNT0 			                    (*(volatile u8*)0x52)
#define 	TCCR0 			                    (*(volatile u8*)0x53)
#define 	OCR0 			                    (*(volatile u8*)0x5C)

#define 	TCNT2 			                    (*(volatile u8*)0x44)
#define 	TCCR2 			                    (*(volatile u8*)0x45)
#define 	OCR2 			                    (*(volatile u8*)0x43)

#define 	TIFR 			                    (*(volatile u8*)0x58)
#define 	TIMSK			                    (*(volatile u8*)0x59)
/*--------------------------------------------------------------------------------------------------------------*/

/* --------------------------------------------- SYSTEM FREQUENCIES --------------------------------------------*/
#define 	MGHZ_1						        1000000UL
#define 	MGHZ_2						        2000000UL
#define 	MGHZ_4						        4000000UL
#define 	MGHZ_8						        8000000UL
#define 	MGHZ_12						        12000000UL
#define 	MGHZ_16						        16000000UL
/*--------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------- SWITCH ON/OFF  MACROS -------------------------------------------------*/
#define 	ON					                1
#define	    OFF					                0
/*---------------------------------------------------------------------------------------------------------------------------*/

/* ----------------------------------------------- GPT Prescaler Values ---------------------------------------------*/
#define     PRESCALER_8				            8
#define     PRESCALER_32			            32
#define     PRESCALER_64		                64
#define     PRESCALER_128			            128
#define     PRESCALER_256			            256
#define     PRESCALER_1024			            1024
/*-------------------------------------------------------------------------------------------------------------------*/



/*--------------------------------------------------- TIMER FUNCYIONALITY MODES MACROS --------------------------------------*/
#define	    GPT					                0
/*---------------------------------------------------------------------------------------------------------------------------*/


/* ----------------------------------------------- Needed programming Values ---------------------------------------------*/
#define     GPT_CLR_VAL                         0
#define     TIMER0_CLR_REG_VALS 	            0x00
#define     TIMER1_CLR_REG_VALS 	            0x0000
#define     TIMER2_CLR_REG_VALS 	            0x0000

#define     TIMER0_STOP_VAL		                0xF8
#define     TIMER1_STOP_VAL			            0xFFF8
#define     TIMER2_STOP_VAL		                0xF8

#define     REG_8_COUNT				            256
#define     REG_16_COUNT			            65536
#define     REG_32_COUNT                        4294967296

#define     REG8_TOPVAL				            255
#define     REG16_TOPVAL			            65535

#define     SEC_IN_MILLI			            1000

#define     GPT_CHANNELS_NUM                    3
#define     GPT_MODES_NUM                       2
#define     GPT_ONE_VAL                         1
/*-------------------------------------------------------------------------------------------------------------------*/


/* ------------------------------------------------------------------ ENABLE/DISABLE NOTIFICATION-------------------------------------------------------------------------------------------------------------*/
#define     TIMER0_ENABLE_NOTIFICATION			(TIMSK_TIMER0_OCIE_ENABLE | TIMSK_TIMER0_TOFIE_ENABLE)
#define     TIMER0_DISABLE_NOTIFICATION			(TIMSK_TIMER0_OCIE_DISABLE & TIMSK_TIMER0_TOFIE_DISABLE)   /* when using this option do ANDING */

#define     TIMER1_ENABLE_NOTIFICATION			(TIMSK_TIMER1_OCF1B_ENABLE | TIMSK_TIMER1_ICF1_ENABLE | TIMSK_TIMER1_OCF1A_ENABLE | TIMSK_TIMER1_TOV1_ENABLE )
#define     TIMER1_DISABLE_NOTIFICATION			(TIMSK_TIMER1_OCF1B_DISABLE & TIMSK_TIMER1_ICF1_DISABLE & TIMSK_TIMER1_OCF1A_DISABLE & TIMSK_TIMER1_TOV1_DISABLE)    /* when using this option do ANDING */

#define     TIMER2_ENABLE_NOTIFICATION			(TIMSK_TIMER2_OCIE_ENABLE | TIMSK_TIMER2_TOFIE_ENABLE)
#define     TIMER2_DISABLE_NOTIFICATION			(TIMSK_TIMER2_OCIE_DISABLE & TIMSK_TIMER2_TOFIE_DISABLE)   /* when using this option do ANDING */
/* ------------------------------------------------------------------ ENABLE/DISABLE NOTIFICATION--------------------------------------------------------------------------------------------------------------*/

/* ---------------------------------------------- Handlers prototypes--------------------------------------- */
void TIM0_OVF_Handler   (void) __attribute__((signal, used));
void TIM0_COMP_Handler  (void) __attribute__((signal, used));
void TIM1_OVF_Handler   (void) __attribute__((signal, used));
void TIM1_COMPB_Handler (void) __attribute__((signal, used));
void TIM1_COMPA_Handler (void) __attribute__((signal, used));
void TIM1_CAPT_Handler  (void) __attribute__((signal, used));
void TIM2_OVF_Handler   (void) __attribute__((signal, used));
void TIM2_COMP_Handler  (void) __attribute__((signal, used));
/* ---------------------------------------------- Handlers prototypes--------------------------------------- */

#endif
