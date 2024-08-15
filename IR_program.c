/******************************************************************/
/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: HAL               ********************/
/*****************    SWC:   IR_Sensor         ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "IR_interface.h"
#include "IR_config.h"
#include "IR_private.h"


u8 IR_u8GetStatus(u8 Copy_u8IR_Port, u8 Copy_u8IR_Pin, u8* Copy_u8StatusValue){
	u8 Local_u8ErrorState;
	Local_u8ErrorState = DIO_u8GetPinValue(Copy_u8IR_Port, Copy_u8IR_Pin, Copy_u8StatusValue);
	if(*Copy_u8StatusValue == DIO_u8PIN_LOW)
		*Copy_u8StatusValue = IR_OBJ_DETECTED;     /*No black line*/
	else if (*Copy_u8StatusValue == DIO_u8PIN_HIGH)
		*Copy_u8StatusValue = IR_OBJ_NOT_DETECTED; /*There is a black line*/
	return Local_u8ErrorState;
}

