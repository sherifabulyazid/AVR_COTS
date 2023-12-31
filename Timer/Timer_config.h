/*
 * Timer0_config.h
 *
 *  Created on: Dec 30, 2023
 *      Author: Sherif Abuelyazid
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
/* Compare Output Mode, non-PWM Mode
   COM01 COM00
 */
#define OC0_disconnected 0x00
#define OC0_Toggle 		0x10
#define OC0_Clear  		0x20
#define OC0_Set 		0x30
#define OC0_MODE	 OC0_Toggle  // <<<<<---------

/* Compare Output Mode, non-PWM Mode
   COM01 COM00
 */
#define OC0_disconnected    0x00
#define non_inverting  		0x20
#define inverting 		    0x30
#define OC0_PWM_MODE	 non_inverting    // <<<<<---------

/*Clock Select*/
#define NO_CLOCK_SOURCE 0X00
#define CLOCK_DIV_BY_1 0X01
#define CLOCK_DIV_BY_8 0X02
#define CLOCK_DIV_BY_64 0X03
#define CLOCK_DIV_BY_256 0X04
#define CLOCK_DIV_BY_1024 0X05
#define EXTERNAL_CLOCK_FALLING 0X06
#define EXTERNAL_CLOCK_RISING 0X07
#define CLOCKSELECT		 CLOCK_DIV_BY_1024  // <<<<<---------

/*compare match value*/
#define TIMER0_COMPARE_MATCH_VALUE		100   // <<<<<---------



#endif /* TITIMER_CONFIG_H_*/
