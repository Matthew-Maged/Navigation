/******************************************************************/
/*****************    Author: Matthew Maged    ********************/
/*****************    Layer: APP               ********************/
/*****************    SWC:   LINE_FOLLOWING    ********************/
/*****************    Version: 1.00            ********************/
/******************************************************************/
/******************************************************************/


#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

/*Options: DIO_u8PORTA,.....,DIO_u8PORTD*/
#define APP_RIGHT_MOTOR_PORT         DIO_u8PORTA
#define APP_LEFT_MOTOR_PORT          DIO_u8PORTA

/*Options: DIO_u8PIN0, DIP_u8PIN1,.....,DIO_u8PIN7*/
#define APP_RIGHT_MOTOR_PIN1          DIO_u8PIN0
#define APP_RIGHT_MOTOR_PIN2          DIO_u8PIN1
#define APP_LEFT_MOTOR_PIN1           DIO_u8PIN2
#define APP_LEFT_MOTOR_PIN2           DIO_u8PIN3

/*Options: DIO_u8PORTA,.....,DIO_u8PORTD*/
#define APP_RIGHT_IR_PORT             DIO_u8PORTA
#define APP_LEFT_IR_PORT              DIO_u8PORTA

/*Options: DIO_u8PIN0, DIP_u8PIN1,.....,DIO_u8PIN7*/
#define APP_RIGHT_IR_PIN              DIO_u8PIN4
#define APP_LEFT_IR_PIN               DIO_u8PIN5

/*Options: Any integer number*/
#define APP_ROTATE_RIGHT_90_DELAY_MS  250
#define APP_ROTATE_LEFT_90_DELAY_MS   250
#define APP_ROTATE_DOWN_180_DELAY_MS  1900
#define APP_MOVE_STEP_DELAY_MS        200/*325*/
#define APP_STOP_DELAY_MS             500

#endif





