/******************************************************************/
/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: HAL               ********************/
/*****************    SWC:   IR_Sensor         ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

#define IR_OBJ_DETECTED          2
#define IR_OBJ_NOT_DETECTED      3

/*Description: Outputs: IR_OBJ_DETECTED if there is an object within the determined distance
 * by the potentiometer, IR_OBJ_NOT_DETECTED "Black-line is detected" otherwise.
 * It also returns an error state.
 *
 *Inputs: IR_Port: The specific port for the OUTPUT PIN in the IR
 *        IR_Pin:  Input pin
 *        StatusValue: IR_OBJ_DETECTED if there is an object within the determined distance
 *                     by the potentiometer, IR_OBJ_NOT_DETECTED otherwise.
 *Note: Set the pins direction and initial values in PORT_config.h
 */
u8 IR_u8GetStatus(u8 Copy_u8IR_Port, u8 Copy_u8IR_Pin, u8* Copy_u8StatusValue);


#endif
