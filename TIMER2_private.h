
#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_


#define TIMER2_MAX_VAL                                             255

#define TIMER2_NORMAL                                              1
#define TIMER2_PWM_PHASE_CORRECT                                   2
#define TIMER2_CLR_ON_COMP                                         3
#define TIMER2_FAST_PWM                                            4

#define TIMER2_OC2_DISCONNECTED                                    0
#define TIMER2_OC2_TOGGLE_OR_RESEREVED                             0b00010000
#define TIMER2_OC2_CLR_ON_COMP_OR_NON_INVERTING_MODE               0b00100000
#define TIMER2_OC2_SET_ON_COMP_OR_INVERTING_MODE                   0b00110000

#define TIMER2_PRES_STOPPED                                        0
#define TIMER2_PRES_NO_PRESCALING                                  1
#define TIMER2_PRES_8                                              2
#define TIMER2_PRES_64                                             3
#define TIMER2_PRES_256                                            4
#define TIMER2_PRES_1024                                           5
#define TIMER2_EXTERNAL_CLK_T0_ON_FALLING_EDGE                     6
#define TIMER2_EXTERNAL_CLK_T0_ON_RISING_EDGE                      7

#define TIMER2_INT_ENABLED                                         1
#define TIMER2_INT_DISABLED                                        2


#define TIMER2_COMP_MATCH_OUTPUT_MASK                              0b11001111
                
#define TIMER2_PRES_MASK                                           0b11111000



#endif
