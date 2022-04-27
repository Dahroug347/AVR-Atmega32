#ifndef     GPT_CFG_H_
#define     GPT_CFG_H_

/*----------------------------------------------   system frequency ----------------------------------------- */
#define     FREQ_CPU		            MGHZ_16
/*------------------------------------------------------------------------------------------------------------*/

/* -------------------- TIMERS SELECTION ----------------------------- */
#define     TIMER_0			            ON
#define     TIMER_1			            ON
#define     TIMER_2			            ON
/*---------------------------------------------------------------------*/

/* -------------------- TIMERS SELECTION ----------------------------- */
#define     TIMER_0_MODE	            GPT
#define     TIMER_1_MODE			    GPT
#define     TIMER_2_MODE			    GPT
/*---------------------------------------------------------------------*/

/* ------------------------------------- TIMER0 MODES ---------------------------------------------------------------------------------- */
/* Choosing Wave generation mode */
#define     TIMER0_WAVGEN_MODE			TCCR0_WAVGEN_NORMAL

/* Choosing the o/p signal mode on compare match */
#define     TIMER0_COMPOP_MODE			TCCR0_COMPOP_NORMAL

/* Choosing the clock source */	
#define     TIMER0_CLK_SRC				INTCLK

/* Choosing to activate handlers or deactivate it */
#define     TIMER0_TOF_INT_MODE		    OFF
#define     TIMER0_OCM_INT_MODE		    OFF

/* General Modes (sleep mode/normal mode) mode */
//empty section
/*---------------------------------------------------------------------------------------------------------------------------------------*/

/* ------------------------------------- TIMER1 MODES ------------------------------------------------------------------------------------------------------------------------------------------- */
/* Choosing Wave generation mode */
#define     TIMER1_WAVGEN_MODE			TCCR1_WAVGEN_NORMAL

/* Choosing the o/p signal mode on compare match for OCA */
#define     TIMER1_COMPA_MODE			TCCR1_COMPA_NORMAL

/* Choosing the o/p signal mode on compare match for OCB*/
#define     TIMER1_COMPB_MODE			TCCR1_COMPB_NORMAL

/* Choosing the clock source */	
#define     TIMER1_CLK_SRC				INTCLK

/* Choosing ICU filtration mode for noise (ON/OFF) */
#define     TIMER1_ICUNOISE_CANCEL		TCCR1_ICU_NOISECANCEL_OFF

/* Choosing ICU edge select mode */
#define     TIMER1_ICU_EDGE			    TCCR1_ICU_RISE

/* Choosing to activate handlers or deactivate it */
#define     TIMER1_ICU_INT_MODE         OFF
#define     TIMER1_OCFA_INT_MODE        OFF
#define     TIMER1_OCFB_INT_MODE        OFF
#define     TIMER1_TOV_INT_MODE         OFF

/* General Modes (sleep mode/normal mode) mode */
//empty section
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* ------------------------------------- TIMER2 MODES ------------------------------------------------------------------------------------- */
/* Choosing Wave generation mode */
#define     TIMER2_WAVGEN_MODE			TCCR2_WAVGEN_NORMAL

/* Choosing the o/p signal mode on compare match */
#define     TIMER2_COMPOP_MODE			TCCR2_COMPOP_NORMAL

/* Choosing the clock source */	
#define     TIMER2_CLK_SRC				INTCLK2_PRESCALE_8

/* Choosing to activate handlers or deactivate it */
#define     TIMER2_TOF_INT_MODE	        OFF		
#define     TIMER2_OCM_INT_MODE	        OFF

/* General Modes (sleep mode/normal mode) mode */
//empty section
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

#endif
