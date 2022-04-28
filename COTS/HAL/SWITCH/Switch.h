#ifndef      SWITCH_H_
#define      SWITCH_H_

#define 	 PRESSED		0
#define		 UN_PRESSED 	1

extern void  Switch_vidConfiguration (u8 SWITCH_X_PIN, u8 ACTIVE_X);
extern u8 	 Switch_u8GetStatus      (u8 SWITCH_X);

#endif
