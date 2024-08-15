#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER2_config.h"
#include "TIMER2_interface.h"
#include "TIMER2_private.h"

#include "TIMER2_register.h"


static void (*TIMER2_pvCallBackFuncCompMatch)(void) = NULL;
static void (*TIMER2_pvCallBackFuncOverflow)(void) = NULL;


void TIMER2_voidInit(void)
{
	/*Setting TIMER2 wave form Generation: */
#if TIMER2_WAVE_GEN_MODE == TIMER2_NORMAL
	CLR_BIT(TCCR2, TCCR2_WGM20);
	CLR_BIT(TCCR2, TCCR2_WGM21);
	/*Interrupt of Overflow(Normal) Mode*/
#if TIMER2_INIT_OVERFLOW_INT_STATE == TIMER2_INT_ENABLED
	SET_BIT(TIMSK, TIMSK_TOIE2);
#elif TIMER2_INIT_OVERFLOW_INT_STATE == TIMER2_INT_DISABLED
	CLR_BIT(TIMSK, TIMSK_TOIE2);
#else
#error "Wrong TIMER2_INIT_OVERFLOW_INT_STATE  configuration option "
#endif

#elif TIMER2_WAVE_GEN_MODE == TIMER2_PWM_PHASE_CORRECT
	SET_BIT(TCCR2, TCCR2_WGM20);
	CLR_BIT(TCCR2, TCCR2_WGM21);

#elif TIMER2_WAVE_GEN_MODE == TIMER2_CLR_ON_COMP
	CLR_BIT(TCCR2, TCCR2_WGM20);
	SET_BIT(TCCR2, TCCR2_WGM21);
	/*Interrupt of Compare Match Mode*/
#if TIMER2_INTIT_COMP_MATCH_INT_STATE == TIMER2_INT_ENABLED
	SET_BIT(TIMSK, TIMSK_OCIE2);
#elif TIMER2_INTIT_COMP_MATCH_INT_STATE == TIMER2_INT_DISABLED
	CLR_BIT(TIMSK, TIMSK_OCIE2);
#else
#error "Wrong TIMER2_INTIT_COMP_MATCH_INT_STATE configuration option"
#endif

#elif TIMER2_WAVE_GEN_MODE == TIMER2_FAST_PWM
	SET_BIT(TCCR2, TCCR2_WGM20);
	SET_BIT(TCCR2, TCCR2_WGM21);
#else
#error "Wrong TIMER2_WAVE_GEN_MODE configuration option"
#endif


	/*Setting an initial value for the Output compare register*/
	OCR2 = TIMER2_INIT_COMP_VALUE;

	/*Setting the OC2 Mode*/
	TCCR2 &= TIMER2_COMP_MATCH_OUTPUT_MASK;
	TCCR2 |= TIMER2_OC2_MODE;

	/*Prescaler Selection*/
	TCCR2 &= TIMER2_PRES_MASK;
	TCCR2 |= TIMER2_PRES_CLK;

	/*Setting an initial value for the Timer Register to start counting from*/
	TCNT2 = TIMER2_INIT_VALUE;
}



u8 TIMER2_u8SetPwmDutyCycle(u8 Copy_u32DutyCycle, u8 Copy_u8Timer0WaveMode, u8 Copy_u8PwmType)
{
	u8 Local_u8ErrorStatus = OK;
	if (Copy_u32DutyCycle <= 100)
	{
		if (Copy_u8Timer0WaveMode == TIMER2_PWM_PHASE_CORRECT)
		{
			/*Setting the mode to Phase Correct PWM*/
			SET_BIT(TCCR2, TCCR2_WGM20);
			CLR_BIT(TCCR2, TCCR2_WGM21);
		}
		else if (Copy_u8Timer0WaveMode == TIMER2_FAST_PWM)
		{
			/*Setting the mode to Fast PWM*/
			SET_BIT(TCCR2, TCCR2_WGM20);
			SET_BIT(TCCR2, TCCR2_WGM21);
		}
		else
		{
			Local_u8ErrorStatus = NOK;
		}

		switch (Copy_u8PwmType)
		{
		case TIMER2_PWM_INVERTING:
			TCCR2 &= TIMER2_COMP_MATCH_OUTPUT_MASK;
			TCCR2 |= TIMER2_OC2_SET_ON_COMP_OR_INVERTING_MODE;
			OCR2 = TIMER2_MAX_VAL - ((u16)((u16)Copy_u32DutyCycle * (u16)TIMER2_MAX_VAL) / 100.0);
			break;
		case TIMER2_PWM_NON_INVERTING:
			TCCR2 &= TIMER2_COMP_MATCH_OUTPUT_MASK;
			TCCR2 |= TIMER2_OC2_CLR_ON_COMP_OR_NON_INVERTING_MODE;
			OCR2 = ((u16)((u16)Copy_u32DutyCycle * (u16)TIMER2_MAX_VAL) / 100.0);
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




u8 TIMER2_u8SetPrescaler(u8 Copy_u8PrescalerOption)
{
	u8 Local_u8ErrorStatus = OK;
	if (Copy_u8PrescalerOption <= TIMER2_EXTERNAL_CLK_T0_ON_RISING_EDGE)
	{
		TCCR2 &= TIMER2_PRES_MASK;
		TCCR2 |= Copy_u8PrescalerOption;
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}
	return Local_u8ErrorStatus;
}

void TIMER2_voidStopTimer2(void)
{
	TCCR2 &= TIMER2_PRES_MASK;
	TCCR2 |= TIMER2_PRES_STOPPED;
}

void TIMER2_voidSetCompareValue(u8 Copy_u8CompareValue)
{
	OCR2 = Copy_u8CompareValue;
}


/* Interrupts */

u8 TIMER2_u8IntEnable(u8 Copy_u8InterruptType)
{
	u8 Local_u8ErrorStatus = OK;
	switch (Copy_u8InterruptType)
	{
	case TIMER2_OVERFLOW_INT:
		SET_BIT(TIMSK, TIMSK_TOIE2);
		break;
	case TIMER2_COMP_MATCH_INT:
		SET_BIT(TIMSK, TIMSK_OCIE2);
		break;
	default:
		Local_u8ErrorStatus = NOK;
		break;
	}
	return Local_u8ErrorStatus;
}



u8 TIMER2_u8IntDisable(u8 Copy_u8InterruptType)
{
	u8 Local_u8ErrorStatus = OK;
	switch (Copy_u8InterruptType)
	{
	case TIMER2_OVERFLOW_INT:
		CLR_BIT(TIMSK, TIMSK_TOIE2);
		break;
	case TIMER2_COMP_MATCH_INT:
		CLR_BIT(TIMSK, TIMSK_OCIE2);
		break;
	default:
		Local_u8ErrorStatus = NOK;
		break;
	}
	return Local_u8ErrorStatus;
}


/************* Callback Functions & ISRs****************/

u8 TIMER2_u8SetCallBackCompMatch(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;

	if (Copy_pvCallBackFunc != NULL)
	{
		TIMER2_pvCallBackFuncCompMatch = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

u8 TIMER2_u8SetCallBackOverflow(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;

	if (Copy_pvCallBackFunc != NULL)
	{
		TIMER2_pvCallBackFuncOverflow = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

/*CompMatch ISR*/
void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	if (TIMER2_pvCallBackFuncCompMatch != NULL)
	{
		TIMER2_pvCallBackFuncCompMatch();
	}
}

/*Overflow ISR*/
void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	if (TIMER2_pvCallBackFuncOverflow != NULL)
	{
		TIMER2_pvCallBackFuncOverflow();
	}
}
