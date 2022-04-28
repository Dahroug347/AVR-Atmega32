#ifndef     SEVENSEG_H_
#define     SEVENSEG_H_


#define        SEVSEG_CATHODE             0
#define        SEVSEG_ANODE               1


/* Numbers to be displayed will be displayed in a HEX numbering system, So the largest value that can be displayed is "0xFF"  */
extern void SevenSeg_vidWriteNumber (u8 number);

#endif
