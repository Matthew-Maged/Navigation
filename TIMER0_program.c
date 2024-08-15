/******************************************************************/
/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: MCAL              ********************/
/*****************    SWC:   TIMER             ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

static void (*TIMER0_pvCallBackFuncCompMatch)(void) = NULL;
static void (*TIMER0_pvCallBackFuncOverflow)(void) = NULL;

void TIMER0_voidInit(void){
	/*Setting TIMER0 wave form Generation: */
#if TIMER0_WAVE_GEN_MODE == TIMER0_NORMAL
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);


#elif TIMER0_WAVE_GEN_MODE == TIMER0_PWM_PHASE_CORRECT
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

#elif TIMER0_WAVE_GEN_MODE == TIMER0_CLR_ON_COMP
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

#elif TIMER0_WAVE_GEN_MODE == TIMER0_FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
#else
#error "Wrong TIMER0_WAVE_GEN_MODE configuration option"
#endif

	/*Setting an initial value for the Output compare register*/
	OCR0 = TIMER0_INIT_COMP_VALUE;

	/*Setting the OC0 Mode*/
	TCCR0 &= TIMER0_COMP_MATCH_OUTPUT_MASK;
	TCCR0 |= TIMER0_OC0_MODE;

	/*Prescaler Selection*/
	TCCR0 &= TIMER0_PRES_MASK;
	TCCR0 |= TIMER0_PRES_CLK;

	/*Setting an initial value for the Timer Register to start counting from*/
	TCNT0 = TIMER0_INIT_VALUE;

	/*Setting initial status for timer interrupts*/
#if TIMER0_INIT_OVERFLOW_INT_STATE == TIMER0_INT_ENABLED
	SET_BIT(TIMSK,TIMSK_TOIE0);
#elif TIMER0_INIT_OVERFLOW_INT_STATE == TIMER0_INT_DISABLED
	CLR_BIT(TIMSK,TIMSK_TOIE0);
#else
#error "Wrong TIMER0_INIT_OVERFLOW_INT_STATE configuration option"
#endif

#if   TIMER0_INTIT_COMP_MATCH_INT_STATE == TIMER0_INT_ENABLED
	SET_BIT(TIMSK,TIMSK_OCIE0);
#elif TIMER0_INTIT_COMP_MATCH_INT_STATE == TIMER0_INT_DISABLED
	CLR_BIT(TIMSK,TIMSK_OCIE0);
#else
#error "Wrong TIMER0_INTIT_COMP_MATCH_INT_STATE configuration option"
#endif
}


u8 TIMER0_u8SetPrescaler(u8 Copy_u8PrescalerOption){
	u8 Local_u8ErrorStatus = OK;
	if(Copy_u8PrescalerOption<=TIMER0_EXTERNAL_CLK_T0_ON_RISING_EDGE)
	{
		TCCR0 &= TIMER0_PRES_MASK;
		TCCR0 |= Copy_u8PrescalerOption;
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}
	return Local_u8ErrorStatus;
}


void TIMER0_voidStopTimer0(void){
	TCCR0 &= TIMER0_PRES_MASK;
	TCCR0 |= TIMER0_PRES_STOPPED;
}


void TIMER0_voidSetCompareValue(u8 Copy_u8CompareValue){
	OCR0 = Copy_u8CompareValue;
}


u8 TIMER0_u8SetPwmDutyCycle(u8 Copy_u32DutyCycle,u8 Copy_u8Timer0WaveMode,u8 Copy_u8PwmType){
	u8 Local_u8ErrorStatus = OK;
	if(Copy_u32DutyCycle<=100)
	{
		if(Copy_u8Timer0WaveMode == TIMER0_PWM_PHASE_CORRECT)
		{
			/*Setting the mode to Phase Correct PWM*/
			SET_BIT(TCCR0,TCCR0_WGM00);
			CLR_BIT(TCCR0,TCCR0_WGM01);
		}
		else if(Copy_u8Timer0WaveMode == TIMER0_FAST_PWM)
		{
			/*Setting the mode to Fast PWM*/
			SET_BIT(TCCR0,TCCR0_WGM00);
			SET_BIT(TCCR0,TCCR0_WGM01);
		}
		else
		{
			Local_u8ErrorStatus = NOK;
		}

		switch(Copy_u8PwmType)
		{
		case TIMER0_PWM_INVERTING:
			TCCR0 &= TIMER0_COMP_MATCH_OUTPUT_MASK;
			TCCR0 |= TIMER0_OC0_SET_ON_COMP_OR_INVERTING_MODE;
			OCR0 = TIMER0_MAX_VAL - ((u16)((u16)Copy_u32DutyCycle * (u16)TIMER0_MAX_VAL)/100.0);
			break;
		case TIMER0_PWM_NON_INVERTING:
			TCCR0 &= TIMER0_COMP_MATCH_OUTPUT_MASK;
			TCCR0 |= TIMER0_OC0_CLR_ON_COMP_OR_NON_INVERTING_MODE;
			OCR0 = ((u16)((u16)Copy_u32DutyCycle * (u16)TIMER0_MAX_VAL)/100.0);
			break;
		default:
			Local_u8ErrorStatus = NOK;
			break;
		}
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}
	return Local_u8ErrorStatus;
}









/*Interrupts and SetCallBack functions: */

u8 TIMER0_u8IntEnable(u8 Copy_u8InterruptType){
	u8 Local_u8ErrorStatus = OK;
	switch(Copy_u8InterruptType)
	{
	case TIMER0_OVERFLOW_INT:
		SET_BIT(TIMSK,TIMSK_TOIE0);
		break;
	case TIMER0_COMP_MATCH_INT:
		SET_BIT(TIMSK,TIMSK_OCIE0);
		break;
	default:
		Local_u8ErrorStatus = NOK;
		break;
	}
	return Local_u8ErrorStatus;
}


u8 TIMER0_u8IntDisable(u8 Copy_u8InterruptType){
	u8 Local_u8ErrorStatus = OK;
	switch(Copy_u8InterruptType)
	{
	case TIMER0_OVERFLOW_INT:
		CLR_BIT(TIMSK,TIMSK_TOIE0);
		break;
	case TIMER0_COMP_MATCH_INT:
		CLR_BIT(TIMSK,TIMSK_OCIE0);
		break;
	default:
		Local_u8ErrorStatus = NOK;
		break;
	}
	return Local_u8ErrorStatus;
}


u8 TIMER0_u8SetCallBackCompMatch(void (*Copy_pvCallBackFunc)(void)){
	u8 Local_u8ErrorState = OK;

	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFuncCompMatch = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}


u8 TIMER0_u8SetCallBackOverflow(void (*Copy_pvCallBackFunc)(void)){
	u8 Local_u8ErrorState = OK;

	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFuncOverflow = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}


/*CompMatch ISR*/
void __vector_10 (void)  __attribute__ ((signal));
void __vector_10 (void){
	if(TIMER0_pvCallBackFuncCompMatch != NULL)
	{
		TIMER0_pvCallBackFuncCompMatch();
	}
}

/*Overflow ISR*/
void __vector_11 (void)  __attribute__ ((signal));
void __vector_11 (void){
	if(TIMER0_pvCallBackFuncOverflow != NULL)
	{
		TIMER0_pvCallBackFuncOverflow();
	}
}


