/******************************************************************/
/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: MCAL              ********************/
/*****************    SWC:   TIMER             ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TIMER0_MAX_VAL                                             255

#define TIMER0_NORMAL                                              1
#define TIMER0_PWM_PHASE_CORRECT                                   2
#define TIMER0_CLR_ON_COMP                                         3
#define TIMER0_FAST_PWM                                            4

#define TIMER0_OC0_DISCONNECTED                                    0
#define TIMER0_OC0_TOGGLE_OR_RESEREVED                             0b00010000
#define TIMER0_OC0_CLR_ON_COMP_OR_NON_INVERTING_MODE               0b00100000
#define TIMER0_OC0_SET_ON_COMP_OR_INVERTING_MODE                   0b00110000

#define TIMER0_PRES_STOPPED                                        0
#define TIMER0_PRES_NO_PRESCALING                                  1
#define TIMER0_PRES_8                                              2
#define TIMER0_PRES_64                                             3
#define TIMER0_PRES_256                                            4
#define TIMER0_PRES_1024                                           5
#define TIMER0_EXTERNAL_CLK_T0_ON_FALLING_EDGE                     6
#define TIMER0_EXTERNAL_CLK_T0_ON_RISING_EDGE                      7

#define TIMER0_INT_ENABLED                                         1
#define TIMER0_INT_DISABLED                                        2




#define TIMER0_COMP_MATCH_OUTPUT_MASK     0b11001111

#define TIMER0_PRES_MASK                  0b11111000

#endif
