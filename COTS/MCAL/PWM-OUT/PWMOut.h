/*
 * PWMOut.h
 *
 *  Created on: May 19, 2022
 *      Author: dahroug
 */

#ifndef PWMOUT_H_
#define PWMOUT_H_

typedef enum
{
	Pwm_enuNoPrescaler = 1,
	Pwm_enuClkDivBy8,
	Pwm_enuClkDivBy64,
	Pwm_enuClkDivBy256,
	Pwm_enuClkDivBy1024,
	Pwm_enuExternalTxFallingEdge,
	Pwm_enuExternalTxRisingEdge

}Pwm_enuClkSelect_t;

typedef enum
{
	Pwm_enuNoPrescaler = 1,
	Pwm_enuClkDivBy8,
	Pwm_enuClkDivBy32,
	Pwm_enuClkDivBy64,
	Pwm_enuClkDivBy128,
	Pwm_enuClkDivBy256,
	Pwm_enuClkDivBy1024

}Pwm2_enuClkSelect_t;

typedef enum
{
	Pwm_enuPhaseCorrect8_Bit = 1,
	Pwm_enuPhaseCorrect9_Bit,
	Pwm_enuPhaseCorrect10_Bit,

	Pwm_enuFastPwm8_Bit =5,
	Pwm_enuFastPwm9_Bit,
	Pwm_enuFastPwm10_Bit,

	Pwm_enuPhaseAndFreqCorrect_ICR1_Top,
	Pwm_enuPhaseAndFreqCorrect_OCR1A_Top,

	Pwm_enuPhaseCorrect_ICR1_TOP,
	Pwm_enuPhaseCorrect_OCR1A_TOP,

	Pwm_enuFastPwm_ICR1_TOP = 14,
	Pwm_enuFastPwm_OCR1A_TOP
}Pwm1Modes_t;

typedef struct
{
	u8                 Pwm0_u8Mode;
	u8                 Pwm0_u8OutputMode;
	Pwm_enuClkSelect_t Pwm0_enuClkSelect;
}PwmCh0Cfg_t;

typedef struct
{
	Pwm1Modes_t        Pwm1_enuMode;
	u8                 Pwm1_u8Output;
	Pwm_enuClkSelect_t Pwm1_enuClkSelect;
}PwmCh1Cfg_t;

typedef struct
{
	u8 Pwm2_u8Mode;
	u8 Pwm2_u8OutputMode;
	Pwm_enuClkSelect_t Pwm2_enuClkSelect;
}PwmCh2Cfg_t;

typedef struct
{
	PwmCh0Cfg_t * PwmCh0Cfg;
	PwmCh1Cfg_t * PwmCh1Cfg;
	PwmCh2Cfg_t * PwmCh2Cfg;
}PwmCfg_t;


#define 		PWM0_u8MODE_PHASECORRECT					        ((u8)0x40)
#define 		PWM0_u8MODE_FASTMODE						        ((u8)0x48)

#define 		PWM0_u8OUTPUTMODE_FPWM_OC0_DISCONNECT			    ((u8)0x00)
#define 		PWM0_u8OUTPUTMODE_FPWM_OC0_CLR_ONCMP_SET_TOP		((u8)0x20)
#define 		PWM0_u8OUTPUTMODE_FPWM_OC0_SET_ONCMP_CLR_TOP		((u8)0x30)


/*
#define 		PWM1_u8MODE_PHASECORRECT					        ((u8)0x40)
#define 		PWM1_u8MODE_FASTMODE						        ((u8)0x48)
*/
#define 		PWM1_u8OUTPUTMODE_OC1A_B_DISCONNECT			        ((u8)0x00)
#define 		PWM1_u8OUTPUTMODE_OC1A_B_CLR_ONCMP_SET_TOP		    ((u8)0x20)
#define 		PWM1_u8OUTPUTMODE_OC1A_B_SET_ONCMP_CLR_TOP		    ((u8)0x30)


#define 		PWM2_u8MODE_PHASECORRECT					        ((u8)0x40)
#define 		PWM2_u8MODE_FASTMODE						        ((u8)0x48)

#define 		PWM0_u8OUTPUTMODE_OC2_DISCONNECT			        ((u8)0x00)
#define 		PWM0_u8OUTPUTMODE_OC2_CLR_ONCMP_SET_TOP		        ((u8)0x20)
#define 		PWM0_u8OUTPUTMODE_OC2_SET_ONCMP_CLR_TOP		        ((u8)0x30)




Std_enuErrorStatus Pwm_enuInit(PwmCfg_t* Add_PwmCfg);

#endif /* PWMOUT_H_ */
