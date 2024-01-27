/*
 * Timer0_Prog.c
 *
 *  Created on: Dec 30, 2023
 *      Author: Sherif Abuelyazid
 */
#include "STD.h"
#include "BIT_MATH.h"
#include "Timer_config.h"
#include "Timer_registers.h"
#include "Timer_private.h"
#include "Timer_interface.h"

void (*Timer0_CTC_CallBackFun)(void)=NULL;
void (*Timer0_Normal_CallBackFun)(void)=NULL;
static float32 OV_Counts=0;

void Timer0_Normal(void)
{
	CLEARBIT(TCCR0,TCCR0_FOC0);
	/*Mode of operation : Normal*/
	CLEARBIT(TCCR0,TCCR0_WGM00);
	CLEARBIT(TCCR0,TCCR0_WGM01);

	/* Output Mode */
	CLEARBIT(TCCR0,TCCR0_COM00);
	CLEARBIT(TCCR0,TCCR0_COM01);
	TCCR0 |=OC0_MODE;

	/*Clock Select*/
	CLEARBIT(TCCR0,TCCR0_CS00);
	CLEARBIT(TCCR0,TCCR0_CS01);
	CLEARBIT(TCCR0,TCCR0_CS02);
	TCCR0 |=CLOCKSELECT;

	/*enable interrupt for Normal mode*/
	SETBIT(TIMSK,TIMSK_TOIE0);
	/*enable global interrupt*/
	SETBIT(SREG,GIE);
}
uint8 Timer0_Normal_CallBack(void (*Copy_Timer0_Normal_CallBackFun)(void),uint32 copy_time_ms)
{
	uint8 localError=1;

#if CLOCKSELECT ==CLOCK_DIV_BY_1
static float32 overflow_time=1*256.0/(16000.0); //in ms
#elif CLOCKSELECT ==CLOCK_DIV_BY_8
static float32 overflow_time=8*256.0/(16000.0); //in ms
#elif CLOCKSELECT ==CLOCK_DIV_BY_64
static float32 overflow_time=64*256.0/(16000.0); //in ms
#elif CLOCKSELECT ==CLOCK_DIV_BY_256
static float32 overflow_time=256*256.0/(16000.0); //in ms
#elif CLOCKSELECT ==CLOCK_DIV_BY_1024
static float32 overflow_time =1024.0*256.0/(16000.0); //in ms
#endif

	if(Copy_Timer0_Normal_CallBackFun==NULL)
	{
		localError=0;
	}
	else
	{
		Timer0_Normal_CallBackFun=Copy_Timer0_Normal_CallBackFun;
		OV_Counts=copy_time_ms/overflow_time;
	}
	return localError;
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static uint32 counter=0;
	counter++;
	if(counter>=OV_Counts)
	{
		if(Timer0_Normal_CallBackFun != NULL)
		{
			Timer0_Normal_CallBackFun();
		}
		counter=0;
	}

}

void Timer0_CTC(void)
{
	CLEARBIT(TCCR0,TCCR0_FOC0);

	/*Mode of operation : CTC*/
	CLEARBIT(TCCR0,TCCR0_WGM00);
	SETBIT(TCCR0,TCCR0_WGM01);

	/* Output Mode */
	CLEARBIT(TCCR0,TCCR0_COM00);
	CLEARBIT(TCCR0,TCCR0_COM01);
	TCCR0 |=OC0_MODE;

	/*Clock Select*/
	CLEARBIT(TCCR0,TCCR0_CS00);
	CLEARBIT(TCCR0,TCCR0_CS01);
	CLEARBIT(TCCR0,TCCR0_CS02);
	TCCR0 |=CLOCKSELECT;
	/*enable interrupt for CTC mode*/
	SETBIT(TIMSK,TIMSK_OCIE0);
	/*enable global interrupt*/
	SETBIT(SREG,GIE);
	/*set compare match value*/
	OCR0 = TIMER0_COMPARE_MATCH_VALUE;

}
uint8 Timer0_CTC_CallBack( void (*Copy_Timer0_CTC_CallBackFun)(void) , uint32 copy_time_ms)
{
	uint8 localError=1;

	#if CLOCKSELECT ==CLOCK_DIV_BY_1
	float32 Overflow_time=1.0*TIMER0_COMPARE_MATCH_VALUE/(16000.0); //in ms
	#elif CLOCKSELECT ==CLOCK_DIV_BY_8
	static float32 Overflow_time=8.0*TIMER0_COMPARE_MATCH_VALUE/(16000.0); //in ms
	CLOCKSELECT ==CLOCK_DIV_BY_64
	float32 Overflow_time=64.0*TIMER0_COMPARE_MATCH_VALUE/(16000.0); //in ms
	#elif CLOCKSELECT ==CLOCK_DIV_BY_256
	float32 Overflow_time=256.0*TIMER0_COMPARE_MATCH_VALUE/(16000.0); //in ms
	#elif CLOCKSELECT ==CLOCK_DIV_BY_1024
	float32 Overflow_time =1024.0*TIMER0_COMPARE_MATCH_VALUE/(16000.0); //in ms
	#endif

	if(Copy_Timer0_CTC_CallBackFun==NULL)
	{
		localError=0;
	}
	else
	{
		Timer0_CTC_CallBackFun=Copy_Timer0_CTC_CallBackFun;
		OV_Counts=copy_time_ms/Overflow_time;

	}
	return localError;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	static uint32 Counter=0;
	Counter++;
	if(Counter >= OV_Counts)
	{
		if(Timer0_CTC_CallBackFun != NULL)
		{
			Timer0_CTC_CallBackFun();
		}
		Counter=0;
	}

}

void Timer0_PWM_Fast(void)
{
	CLEARBIT(TCCR0,TCCR0_FOC0);
	/*Waveform generation MODE : Fast PWM*/
	SETBIT(TCCR0,TCCR0_WGM00);
	SETBIT(TCCR0,TCCR0_WGM01);

	/* Output Mode */
	CLEARBIT(TCCR0,TCCR0_COM00);
	CLEARBIT(TCCR0,TCCR0_COM01);
	TCCR0 |=OC0_PWM_MODE;

	/*Clock Select*/
	CLEARBIT(TCCR0,TCCR0_CS00);
	CLEARBIT(TCCR0,TCCR0_CS01);
	CLEARBIT(TCCR0,TCCR0_CS02);
	TCCR0 |=CLOCKSELECT;

	/*set compare match value*/
	OCR0 = TIMER0_COMPARE_MATCH_VALUE;

}

void Timer0_PWM_Phase_Correct(void)
{
	/*force output compare =0*/
	CLEARBIT(TCCR0,TCCR0_FOC0);
	/*Waveform generation MODE: PWM_Phase_Correct */
	SETBIT(TCCR0,TCCR0_WGM00);
	CLEARBIT(TCCR0,TCCR0_WGM01);
	/*Output Mode*/
	CLEARBIT(TCCR0,TCCR0_COM00);
	CLEARBIT(TCCR0,TCCR0_COM01);
	TCCR0 |= OC0_PWM_MODE;
	/*Clock Select*/
	CLEARBIT(TCCR0,TCCR0_CS00);
	CLEARBIT(TCCR0,TCCR0_CS01);
	CLEARBIT(TCCR0,TCCR0_CS02);
	TCCR0 |=CLOCKSELECT;
	/*set compare match value*/
	OCR0= TIMER0_COMPARE_MATCH_VALUE;
}
void Delay_mS(uint32 copy_dtime_ms)
{
	uint32 counter=0;
	CLEARBIT(TCCR0,TCCR0_FOC0);

	/*Mode of operation : CTC*/
	CLEARBIT(TCCR0,TCCR0_WGM00);
	SETBIT(TCCR0,TCCR0_WGM01);

	/* OC0 is disconnected */
	CLEARBIT(TCCR0,TCCR0_COM00);
	CLEARBIT(TCCR0,TCCR0_COM01);

	/*Clock Select div by 256*/
	TCCR0 |=0x04;
	/*set compare match value*/
	OCR0 = 250;  //this will generate 4 ms every cycle
	uint16 CTC_Interrupt_counts=0;
	CTC_Interrupt_counts=copy_dtime_ms/4;
	while(counter<CTC_Interrupt_counts)
	{
		while(!GETBIT(TIFR,TIFR_OCF0));
		SETBIT(TIFR,TIFR_OCF0);//clearing the flag
		counter++;
	}
}


void Timer1_Servo(uint8 copy_Angle)
{
	TCCR1A|=0x80; //non inverting
	CLEARBIT(TCCR1A,2); //force output compare =0
	CLEARBIT(TCCR1A,3);
	SETBIT(TCCR1A,1); //Waveform Generation Mode
	CLEARBIT(TCCR1A,0);
	SETBIT(TCCR1B,3);
	SETBIT(TCCR1B,4);
	TCCR1B|=0x02; //Prescaler 8
	ICR1L=40000;  //max count value
	OCR1AL=2000+(copy_Angle)*(2000/180);//output compare
}

uint8 ADC_To_Angle(uint8 copy_ADC_val)
{
	uint8 Angle =0;
	Angle=copy_ADC_val*180/255;
	return Angle;
}
