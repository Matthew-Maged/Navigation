/******************************************************************/
/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: MCAL              ********************/
/*****************    SWC:   TIMER             ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

/*Output Compare Register0*/
#define OCR0                                       *((volatile u8*)0x5C)

/*Timer Mask*/
#define TIMSK                                      *((volatile u8*)0x59)
#define TIMSK_OCIE0                                1 /*Output Compare Match Interrupt Enable*/
#define TIMSK_TOIE0                                0 /*Overflow Interrupt Enable*/

#define TIFR             						   *((volatile u8*)0x58)
#define TIFR_OCF0                                  1 /*Output Compare Flag*/
#define TIFR_TOV0                                  0 /*Overflow Flag*/


/*Timer0 Control Register*/												   
#define TCCR0									   *((volatile u8*)0x53)
#define TCCR0_FOC0                                 7 
#define TCCR0_WGM00                                6 /*Waveform Generation Mode bit0*/
#define TCCR0_COM01                                5 
#define TCCR0_COM00                                4
#define TCCR0_WGM01                                3 /*Waveform Generation Mode bit1*/
#define TCCR0_CS02                                 2 /*Prescaler bit2*/
#define TCCR0_CS01                                 1 /*Prescaler bit1*/
#define TCCR0_CS00                                 0 /*Prescaler bit0*/


#define TCNT0                                      *((volatile u8*)0x52)  



#endif
