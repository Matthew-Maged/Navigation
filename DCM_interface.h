/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: HAL               ********************/
/*****************    SWC:   DC_MOTOR          ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/

#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

#define PRE_BUILD_CONFIG          1
#define POST_BUILD_CONFIG         2

/*Options: PRE_BUILD_CONFIG: Serves only one motor
 *         POST_BUILD_CONFIG: Serves multiple motors*/

#define BUILD_CONFIG             POST_BUILD_CONFIG

#if BUILD_CONFIG == PRE_BUILD_CONFIG

void DCM_voidRotateCw(void);

void DCM_voidRotateCcw(void);

void DCM_voidStop(void);

#elif BUILD_CONFIG == POST_BUILD_CONFIG

void DCM_voidRotateCw(u8 Copy_u8DCM_PORT,u8 Copy_u8DCM_FirstPin,u8 Copy_u8DCM_SecondPin);

void DCM_voidRotateCcw(u8 Copy_u8DCM_PORT,u8 Copy_u8DCM_FirstPin,u8 Copy_u8DCM_SecondPin);

void DCM_voidStop(u8 Copy_u8DCM_PORT,u8 Copy_u8DCM_FirstPin,u8 Copy_u8DCM_SecondPin);

#endif

#endif




