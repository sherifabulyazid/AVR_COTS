/**********************************************************
*Author: Mahmoud Khaled Alnmr
*SWC:
*Layer:
*Version:
***********************************************************/


#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"

#include "ADC_registers.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"

void ADC_init(void)
{
	/*choosind the reference voltage*/
#if VOLTAGR_REF == AREF
	CLR_BIT(ADMUX, REFS1);
	CLR_BIT(ADMUX, REFS0);
#elif VOLTAGR_REF==AVCC_WITH_CAP
	CLR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
#elif VOLTAGR_REF==INTERNAL_VREF
	SET_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
#endif
	
	/*setting the bits for Left adjust*/
	CLR_BIT(ADMUX, ADCLAR);
	
	/*set ADC as single conversion*/
	CLR_BIT(ADCSRA, ADATE);
	
	/*disable interrupt*/
	CLR_BIT(ADCSRA, ADIE);
	
	/*choosing the prescaler*/
	CLR_BIT(ADCSRA,ADPS2);
	CLR_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS0);
	ADCSRA |=ADC_PRESCALER;
	/*enable ADC*/
	SET_BIT(ADCSRA, ADEN);
}

uint8 ADC_StartConversion(uint8 copy_channel)
{
	/*choosing the ADC channel*/
	ADMUX &= 0b11100000;
	ADMUX |= copy_channel;
	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);
	
	while(!GET_BIT(ADCSRA,ADIF));
	
	/*clearing the flag*/
	SET_BIT(ADCSRA,ADIF);
	return ADCH;
}
