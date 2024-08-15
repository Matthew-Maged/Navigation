/******************************************************************/
/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: MCAL              ********************/
/*****************    SWC:   TIMER             ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TIMER0_NORMAL                                              1
#define TIMER0_PWM_PHASE_CORRECT                                   2
#define TIMER0_CLR_ON_COMP                                         3
#define TIMER0_FAST_PWM                                            4

#define TIMER0_PWM_INVERTING                                       5
#define TIMER0_PWM_NON_INVERTING                                   6

#define TIMER0_PRES_STOPPED                                        0
#define TIMER0_PRES_NO_PRESCALING                                  1
#define TIMER0_PRES_8                                              2
#define TIMER0_PRES_64                                             3
#define TIMER0_PRES_256                                            4
#define TIMER0_PRES_1024                                           5
#define TIMER0_EXTERNAL_CLK_T0_ON_FALLING_EDGE                     6
#define TIMER0_EXTERNAL_CLK_T0_ON_RISING_EDGE                      7

#define TIMER0_OVERFLOW_INT                                        10
#define TIMER0_COMP_MATCH_INT                                      11

void TIMER0_voidInit(void);

/*Options:
 * TIMER0_PRES_STOPPED
 * TIMER0_PRES_NO_PRESCALING
 * TIMER0_PRES_8
 * TIMER0_PRES_64
 * TIMER0_PRES_256
 * TIMER0_PRES_1024
 * TIMER0_EXTERNAL_CLK_T0_ON_FALLING_EDGE
 * TIMER0_EXTERNAL_CLK_T0_ON_RISING_EDGE
 * */
u8 TIMER0_u8SetPrescaler(u8 Copy_u8PrescalerOption);

void TIMER0_voidStopTimer0(void);

void TIMER0_voidSetCompareValue(u8 Local_u8CompareValue);

/*Inputs: Local_u32DutyCycle_ms: DutyCycle in percentage, Examples: 1, 2, 3, ..., 100
 *
 *        Copy_u8Timer0WaveMode: TIMER0_PWM_PHASE_CORRECT
 *                               TIMER0_FAST_PWM
 *
 *        Copy_u8PwmType:        TIMER0_PWM_INVERTING
 *                               TIMER0_PWM_NON_INVERTING
 * */
u8 TIMER0_u8SetPwmDutyCycle(u8 Copy_u32DutyCycle,u8 Copy_u8Timer0WaveMode,u8 Copy_u8PwmType);

/*Inputs: Copy_u8InterruptType:  TIMER0_OVERFLOW_INT
 *                               TIMER0_COMP_MATCH_INT
 * */
u8 TIMER0_u8IntEnable(u8 Copy_u8InterruptType);

u8 TIMER0_u8IntDisable(u8 Copy_u8InterruptType);

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));






#endif
