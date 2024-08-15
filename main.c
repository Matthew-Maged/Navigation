#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER0_interface.h"
#include "TIMER2_interface.h"

#include "DCM_interface.h"
#include "IR_interface.h"

#include "APP_interface.h"

void main(void)
{
	PORT_voidInit();
	TIMER0_voidInit();
	TIMER2_voidInit();

	/*	APP_voidStop();
	_delay_ms(2000);*/


	while (1)
	{
		APP_voidStop();
		_delay_ms(2000);

		APP_u8GoToXY(1,2);

		APP_voidMoveBackward();
		_delay_ms(500);
		APP_voidStop();

		_delay_ms(2000);

		APP_u8GoToXY(0,0);
	}
}
