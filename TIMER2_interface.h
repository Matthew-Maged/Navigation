#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_


#define TIMER2_NORMAL                                              1
#define TIMER2_PWM_PHASE_CORRECT                                   2
#define TIMER2_CLR_ON_COMP                                         3
#define TIMER2_FAST_PWM                                            4

#define TIMER2_PWM_INVERTING                                       5
#define TIMER2_PWM_NON_INVERTING                                   6

#define TIMER2_PRES_STOPPED                                        0
#define TIMER2_PRES_NO_PRESCALING                                  1
#define TIMER2_PRES_8                                              2
#define TIMER2_PRES_64                                             3
#define TIMER2_PRES_256                                            4
#define TIMER2_PRES_1024                                           5
#define TIMER2_EXTERNAL_CLK_T0_ON_FALLING_EDGE                     6
#define TIMER2_EXTERNAL_CLK_T0_ON_RISING_EDGE                      7

#define TIMER2_OVERFLOW_INT                                        10
#define TIMER2_COMP_MATCH_INT                                      11


void TIMER2_voidInit(void);
void TIMER2_voidStopTimer2(void);
void TIMER2_voidSetCompareValue(u8 Copy_u8CompareValue);

/*Options:
 * TIMER2_PRES_STOPPED
 * TIMER2_PRES_NO_PRESCALING
 * TIMER2_PRES_8
 * TIMER2_PRES_64
 * TIMER2_PRES_256
 * TIMER2_PRES_1024
 * TIMER2_EXTERNAL_CLK_T0_ON_FALLING_EDGE
 * TIMER2_EXTERNAL_CLK_T0_ON_RISING_EDGE
 * */
u8   TIMER2_u8SetPrescaler(u8 Copy_u8PrescalerOption);

/*Inputs: Local_u32DutyCycle_ms: DutyCycle in percentage, Examples: 1, 2, 3, ..., 100
 *
 *        Copy_u8Timer0WaveMode: TIMER2_PWM_PHASE_CORRECT
 *                               TIMER2_FAST_PWM
 *
 *        Copy_u8PwmType:        TIMER2_PWM_INVERTING
 *                               TIMER2_PWM_NON_INVERTING
 * */
u8   TIMER2_u8SetPwmDutyCycle(u8 Copy_u32DutyCycle, u8 Copy_u8Timer0WaveMode, u8 Copy_u8PwmType);



/*Inputs: Copy_u8InterruptType:  TIMER2_OVERFLOW_INT
 *                               TIMER2_COMP_MATCH_INT
 * */
u8   TIMER2_u8IntEnable(u8 Copy_u8InterruptType);
u8   TIMER2_u8IntDisable(u8 Copy_u8InterruptType);

u8   TIMER2_u8SetCallBackCompMatch(void (*Copy_pvCallBackFunc)(void));
u8   TIMER2_u8SetCallBackOverflow(void (*Copy_pvCallBackFunc)(void));



#endif
