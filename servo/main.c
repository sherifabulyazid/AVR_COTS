#include "STD.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "ADC_interface.h"
#include "Timer_interface.h"

int main (void)
{
	uint8 valueADC=0;
	uint8 angle=0;
	DIO_setPinDirection(DIO_PORTD,PIN5,OUTPUT);//Servo motor
	ADC_init();
while(1){
	valueADC=ADC_StartConversion(ADC1);
	angle=ADC_To_Angle(valueADC);
	Timer1_Servo(angle);
}
	return 0;
}


