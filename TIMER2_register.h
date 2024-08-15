#ifndef TIMER2_REGISTER_H_
#define TIMER2_REGISTER_H_


/* Timer/Counter Control Register */
#define  TCCR2                                     *((volatile u8*)0x45)
#define  TCCR2_FOC2                                7 
#define  TCCR2_WGM20                               6 /*Waveform Generation Mode bit0*/
#define  TCCR2_COM21                               5 
#define  TCCR2_COM20                               4
#define  TCCR2_WGM21                               3 /*Waveform Generation Mode bit1*/
#define  TCCR2_CS22                                2 /*Prescaler bit2*/
#define  TCCR2_CS21                                1 /*Prescaler bit1*/
#define  TCCR2_CS20                                0 /*Prescaler bit0*/
 
/* Timer/Counter Register */
#define  TCNT2                                     *((volatile u8*)0x44)

/* Output Compare Register */
#define  OCR2                                      *((volatile u8*)0x43)


/* Timer/Counter Interrupt Mask Register Pins */
/* Timer Interrupt Mask ==> shared with the three timers*/
#define  TIMSK                                      *((volatile u8*)0x59)
#define  TIMSK_OCIE2                                7  /* Timer/Counter2 Output Compare Match Interrupt Enable */
#define  TIMSK_TOIE2                                6  /* Timer/Counter2 Overflow Interrupt Enable */


/* Timer/Counter Interrupt Flag Register */
/* Timer Interrupt Flag ==> shared with the three timers*/
#define  TIFR             						   *((volatile u8*)0x58)
#define  TIFR_OCF2                                  7  /* Timer/Counter2 Overflow Flag */
#define  TIFR_TOV2                                  6  /* Output Compare Flag 2 */
  
#endif
