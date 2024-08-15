/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: APP               ********************/
/*****************    SWC:   LINE_FOLLOWING    ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/


#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

void APP_voidMoveForward(void);

void APP_voidMoveBackward(void);

void APP_voidTurnRight(void);

void APP_voidTurnLeft(void);

void APP_voidStop(void);

u8 APP_u8GetRightIRState(void);

u8 APP_u8GetLeftIRState(void);

u8 APP_u8GoToLine(u8 Copy_u8LineNumber);

void APP_voidFollowLine(void);

void APP_voidRotateRight90(void);

void APP_voidRotateLeft90(void);

void APP_voidRotateDown180(void);

void APP_voidMoveStep(void);

u8 APP_u8GoToXY(s8 Copy_s8CoordinateX, s8 Copy_s8CoordinateY);

#endif
