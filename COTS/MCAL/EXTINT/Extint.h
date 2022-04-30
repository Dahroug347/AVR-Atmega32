#ifndef            EXT_INT_H_
#define            EXT_INT_H_


#define 	       EXTINT_INT0			    0
#define 	       EXTINT_INT1			    1
#define 	       EXTINT_INT2			    2

/* These values are used to enable or disable external interrupts on pins PB2,PD2,PD3 and they are used within the GICR register*/
#define            EXT_INT0_ENABLE			0x40
#define            EXT_INT0_DISABLE		    0xBF

#define            EXT_INT1_ENABLE			0x80
#define            EXT_INT1_DISABLE		    0x7F

#define            EXT_INT2_ENABLE			0X20
#define            EXT_INT2_DISABLE		    0XDF



/* These values are used for external interrupts modes on pins PB2,PD2,PD3 and they are used within the MCUCR (INT0 & INT1) & MCUCSR (INT2) registers*/
#define            EXT_INT0_LOWLEV			0x00  	/* connection must be input pull-up*/
#define            EXT_INT0_LEVCHG			0x01	/* connection must be input pull-down*/
#define            EXT_INT0_FALL			0x02
#define            EXT_INT0_RISE			0x03

#define            EXT_INT1_LOWLEV			0x00  	/* connection must be input pull-up*/
#define            EXT_INT1_LEVCHG			0x04	/* connection must be input pull-down*/
#define            EXT_INT1_FALL			0x08
#define            EXT_INT1_RISE			0x0C

#define            EXT_INT2_FALL 			0x00
#define            EXT_INT2_RISE 			0x40


extern void               Extint_vidInit                  (void);
extern void               Extint_vidEnableAndSetPolarity  (u8 EXT_INTx_ENABLE, u8 EXT_INTx_MODE);
extern void               Extint_vidDisable               (u8 EXT_INTx_DISABLE);

extern Std_enuErrorStatus Extint_tenuSetCallBack_INT0 (pfunc func);
extern Std_enuErrorStatus Extint_tenuSetCallBack_INT1 (pfunc func);
extern Std_enuErrorStatus Extint_tenuSetCallBack_INT2 (pfunc func);


void               EXT_INT0_Handler(void) __attribute__((signal, used));
void               EXT_INT1_Handler(void) __attribute__((signal, used));
void               EXT_INT2_Handler(void) __attribute__((signal, used));


#endif
