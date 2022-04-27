#ifndef 	GLBINT_PRV_H_
#define 	GLBINT_PRV_H_

/* GLBINT register mapping */
#define 	SREG 									*((volatile u8*)0x5F)

/* GLBINT  global interrupt enable bit in SREG register  */
#define 	SREG_GIE								0x80

/* GLBINT needed programming values */
#define 	GLBINT_u8CLRVAL							0x00
#define 	GLBINT_u8FIRST_CRITICAL_SECTION_ENTRY 	1

#endif