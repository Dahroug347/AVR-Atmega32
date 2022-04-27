#ifndef 	GLBINT_H_
#define 	GLBINT_H_

extern void Glbint_vidInit (void);
extern void Glbint_vidEnable (void);
extern void Glbint_vidDisable (void);
extern void Glbint_vidEnterCriticalSec(void);
extern Std_enuErrorStatus  Glbint_enuExitCriticalSec  (void);

#endif
