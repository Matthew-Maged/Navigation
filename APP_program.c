/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: APP               ********************/
/*****************    SWC:   LINE_FOLLOWING    ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/

#include <util/delay.h>

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "TIMER2_interface.h"

#include "IR_interface.h"
#include "DCM_interface.h"

#include "APP_interface.h"
#include "APP_private.h"
#include "APP_config.h"

static u8 APP_u8StopFlag = 0;

void APP_voidMoveForward(void)
{
	DCM_voidRotateCcw(APP_RIGHT_MOTOR_PORT, APP_RIGHT_MOTOR_PIN1, APP_RIGHT_MOTOR_PIN2);
	DCM_voidRotateCcw(APP_LEFT_MOTOR_PORT, APP_LEFT_MOTOR_PIN1, APP_LEFT_MOTOR_PIN2);
}

void APP_voidMoveBackward(void)
{
	DCM_voidRotateCw(APP_RIGHT_MOTOR_PORT, APP_RIGHT_MOTOR_PIN1, APP_RIGHT_MOTOR_PIN2);
	DCM_voidRotateCw(APP_LEFT_MOTOR_PORT, APP_LEFT_MOTOR_PIN1, APP_LEFT_MOTOR_PIN2);
}

void APP_voidTurnRight(void)
{
	DCM_voidRotateCcw(APP_LEFT_MOTOR_PORT, APP_LEFT_MOTOR_PIN1, APP_LEFT_MOTOR_PIN2);
	DCM_voidStop(APP_RIGHT_MOTOR_PORT, APP_RIGHT_MOTOR_PIN1, APP_RIGHT_MOTOR_PIN2);
}

void APP_voidTurnLeft(void)
{
	DCM_voidRotateCcw(APP_RIGHT_MOTOR_PORT, APP_RIGHT_MOTOR_PIN1, APP_RIGHT_MOTOR_PIN2);
	DCM_voidStop(APP_LEFT_MOTOR_PORT, APP_LEFT_MOTOR_PIN1, APP_LEFT_MOTOR_PIN2);
}

void APP_voidStop(void)
{
	DCM_voidStop(APP_RIGHT_MOTOR_PORT, APP_RIGHT_MOTOR_PIN1, APP_RIGHT_MOTOR_PIN2);
	DCM_voidStop(APP_LEFT_MOTOR_PORT, APP_LEFT_MOTOR_PIN1, APP_LEFT_MOTOR_PIN2);
}

u8 APP_u8GetRightIRState(void)
{
	u8 Local_u8Status = 0;
	IR_u8GetStatus(APP_RIGHT_IR_PORT, APP_RIGHT_IR_PIN, &Local_u8Status);
	return Local_u8Status;
}

u8 APP_u8GetLeftIRState(void)
{
	u8 Local_u8Status = 0;
	IR_u8GetStatus(APP_LEFT_IR_PORT, APP_LEFT_IR_PIN, &Local_u8Status);
	return Local_u8Status;
}

void APP_voidFollowLine(void)
{
	if ((APP_u8GetRightIRState() == IR_OBJ_DETECTED) && (APP_u8GetLeftIRState() == IR_OBJ_DETECTED))
	{
		APP_voidMoveForward();
	}
	else if ((APP_u8GetRightIRState() == IR_OBJ_DETECTED) && (APP_u8GetLeftIRState() == IR_OBJ_NOT_DETECTED))
	{
		APP_voidTurnLeft();
	}
	else if ((APP_u8GetRightIRState() == IR_OBJ_NOT_DETECTED) && (APP_u8GetLeftIRState() == IR_OBJ_DETECTED))
	{
		APP_voidTurnRight();
	}
	else if ((APP_u8GetRightIRState() == IR_OBJ_NOT_DETECTED) && (APP_u8GetLeftIRState() == IR_OBJ_NOT_DETECTED))
	{
		APP_voidStop();
		_delay_ms(APP_STOP_DELAY_MS);
		APP_voidMoveStep();
		APP_u8StopFlag = 1;
	}
}

void APP_voidRotateRight90(void)
{
	//TIMER2_voidSetCompareValue(180);
	APP_voidTurnRight(); //To make sure it's not on a black line*/
	_delay_ms(APP_ROTATE_RIGHT_90_DELAY_MS);
	while(APP_u8GetRightIRState() == IR_OBJ_DETECTED)
	{
		APP_voidTurnRight();
	}
	/*TIMER2_voidSetCompareValue(155);*/
	APP_voidStop();
	_delay_ms(APP_STOP_DELAY_MS);

}

void APP_voidRotateLeft90(void)
{
//	TIMER0_voidSetCompareValue(180);
	APP_voidTurnLeft(); //To make sure it's not on a black line
	_delay_ms(APP_ROTATE_LEFT_90_DELAY_MS);
	while(APP_u8GetLeftIRState() == IR_OBJ_DETECTED)
	{
		APP_voidTurnLeft();
	}
	/*TIMER0_voidSetCompareValue(150);*/
	//_delay_ms(50);
	APP_voidStop();
	_delay_ms(APP_STOP_DELAY_MS);
}

void APP_voidRotateDown180(void)
{
	u8 Local_u8Counter;
	for(Local_u8Counter = 0; Local_u8Counter < 2; Local_u8Counter++)
	{
		APP_voidRotateRight90();
	}

	/*APP_voidTurnRight();
	_delay_ms(APP_ROTATE_DOWN_180_DELAY_MS);
	APP_voidStop();
	_delay_ms(APP_STOP_DELAY_MS);*/
}

void APP_voidMoveStep(void)
{
	APP_voidMoveForward();
	_delay_ms(APP_MOVE_STEP_DELAY_MS);
	APP_voidStop();
	_delay_ms(APP_STOP_DELAY_MS);
}

u8 APP_u8GoToXY(s8 Copy_s8CoordinateX, s8 Copy_s8CoordinateY)
{
	u8 Local_u8ErrorState = OK;
	s8 Local_s8Counter = 0;
	s8 Local_s8StepsX = 0;
	s8 Local_s8StepsY = 0;

	static s8 Local_s8CurrentX = 0;
	static s8 Local_s8CurrentY = 0;

	Local_s8StepsX = Copy_s8CoordinateX - Local_s8CurrentX;
	Local_s8StepsY = Copy_s8CoordinateY - Local_s8CurrentY;


	if((Copy_s8CoordinateX > 0) && (Copy_s8CoordinateY > 0))
	{
		for(Local_s8Counter = 0; Local_s8Counter<Local_s8StepsY; Local_s8Counter++)
		{
			APP_u8StopFlag = 0;
			while(APP_u8StopFlag == 0)
			{
				APP_voidFollowLine();
			}
		}
		APP_voidRotateRight90();
		for(Local_s8Counter = 0; Local_s8Counter<Local_s8StepsX; Local_s8Counter++)
		{
			APP_u8StopFlag = 0;
			while(APP_u8StopFlag == 0)
			{
				APP_voidFollowLine();
			}
		}
		APP_voidRotateLeft90();
	}

	else if((Copy_s8CoordinateX <= 0) && (Copy_s8CoordinateY <= 0))
	{
		APP_voidRotateDown180();

		for(Local_s8Counter = Local_s8StepsY; Local_s8Counter != 0; Local_s8Counter++)
		{
			APP_u8StopFlag = 0;
			while(APP_u8StopFlag == 0)
			{
				APP_voidFollowLine();
			}
		}

		APP_voidRotateRight90();
		for(Local_s8Counter = Local_s8StepsX; Local_s8Counter != 0; Local_s8Counter++)
		{
			APP_u8StopFlag = 0;
			while(APP_u8StopFlag == 0)
			{
				APP_voidFollowLine();
			}
		}
		APP_voidRotateRight90();
	}

	Local_s8CurrentX = Copy_s8CoordinateX;
	Local_s8CurrentY = Copy_s8CoordinateY;

	return Local_u8ErrorState;
}

u8 APP_u8GoToLine(u8 Copy_u8LineNumber)
{
	u8 Local_u8Counter;
	u8 Local_u8ErrorState = OK;
	if(Copy_u8LineNumber <= 3)
	{
		for(Local_u8Counter = 0; Local_u8Counter != Copy_u8LineNumber; Local_u8Counter++)
		{
			while(APP_u8GetLeftIRState() == IR_OBJ_DETECTED)
			{
				APP_voidTurnLeft();
			}
			_delay_ms(50);
			APP_voidStop();
			_delay_ms(3000);
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
