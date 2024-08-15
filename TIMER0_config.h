/******************************************************************/
/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: MCAL              ********************/
/*****************    SWC:   TIMER             ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


/*Options:
 * TIMER0_NORMAL
 * TIMER0_PWM_PHASE_CORRECT
 * TIMER0_CLR_ON_COMP
 * TIMER0_FAST_PWM
  */
#define TIMER0_WAVE_GEN_MODE           TIMER0_PWM_PHASE_CORRECT


/*Options:
 * TIMER0_OC0_DISCONNECTED
 * TIMER0_OC0_TOGGLE_OR_RESEREVED
 * TIMER0_OC0_CLR_ON_COMP_OR_NON_INVERTING_MODE
 * TIMER0_OC0_SET_ON_COMP_OR_INVERTING_MODE
 * */
/*Notes:
 * NON_INVERTING_MODE: Clear on compare, set at BOTTOM
 * /CLR on compare while up-counting, set on compare when down-counting
 * INVERTING_MODE:     SET on compare, clear at BOTTOM
 * /Set on compare when up-counting, clear on compare when down-counting.
 * */
#define TIMER0_OC0_MODE                TIMER0_OC0_CLR_ON_COMP_OR_NON_INVERTING_MODE


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
#define TIMER0_PRES_CLK                  TIMER0_PRES_8


/*Options: Values from 0 --> 255
 * */
#define TIMER0_INIT_VALUE                 0


/*Options: Values from 0 --> 255
 * */
#define TIMER0_INIT_COMP_VALUE            105


/*Options:
 * TIMER0_INT_ENABLED
 * TIMER0_INT_DISABLED
 * */
#define TIMER0_INIT_OVERFLOW_INT_STATE    TIMER0_INT_DISABLED

#define TIMER0_INTIT_COMP_MATCH_INT_STATE TIMER0_INT_DISABLED












#endif





