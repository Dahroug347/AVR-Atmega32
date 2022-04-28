#ifndef      LED_H_
#define      LED_H_

/* Options (ON/OFF) */
#define     LED_u8ON 	            DIO_u8HIGH
#define     LED_u8OFF             	DIO_u8LOW

extern Std_enuErrorStatus           Led_tenuvidTurnOnLed		(u8 LED_X_PIN);
extern Std_enuErrorStatus           Led_tenuvidTurnOffLed		(u8 LED_X_PIN);
extern Std_enuErrorStatus           Led_tenuvidToggleLed		(u8 LED_X_PIN);

extern Std_enuErrorStatus           Led_tenuvidNumberPattern 	(u8 value);

#endif 
