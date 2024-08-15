/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: HAL               ********************/
/*****************    SWC:   DC_MOTOR          ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "DCM_private.h"
#include "DCM_config.h"
#include "DCM_interface.h"


#if BUILD_CONFIG == PRE_BUILD_CONFIG

void DCM_voidRotateCw(void){
	DIO_u8SetPinValue(DCM_PORT,DCM_FIRST_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCM_PORT,DCM_SECOND_PIN,DIO_u8PIN_HIGH);
}


void DCM_voidRotateCcw(void){
	DIO_u8SetPinValue(DCM_PORT,DCM_SECOND_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCM_PORT,DCM_FIRST_PIN,DIO_u8PIN_HIGH);
}


void DCM_voidStop(void){
	DIO_u8SetPinValue(DCM_PORT,DCM_FIRST_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DCM_PORT,DCM_SECOND_PIN,DIO_u8PIN_LOW);
}


#elif BUILD_CONFIG == POST_BUILD_CONFIG

void DCM_voidRotateCw(u8 Copy_u8DCM_PORT,u8 Copy_u8DCM_FirstPin,u8 Copy_u8DCM_SecondPin){
	DIO_u8SetPinValue(Copy_u8DCM_PORT,Copy_u8DCM_FirstPin,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8DCM_PORT,Copy_u8DCM_SecondPin,DIO_u8PIN_HIGH);
}

void DCM_voidRotateCcw(u8 Copy_u8DCM_PORT,u8 Copy_u8DCM_FirstPin,u8 Copy_u8DCM_SecondPin){
	DIO_u8SetPinValue(Copy_u8DCM_PORT,Copy_u8DCM_SecondPin,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8DCM_PORT,Copy_u8DCM_FirstPin,DIO_u8PIN_HIGH);
}

void DCM_voidStop(u8 Copy_u8DCM_PORT,u8 Copy_u8DCM_FirstPin,u8 Copy_u8DCM_SecondPin){
	DIO_u8SetPinValue(Copy_u8DCM_PORT,Copy_u8DCM_FirstPin,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8DCM_PORT,Copy_u8DCM_SecondPin,DIO_u8PIN_LOW);
}

#endif



