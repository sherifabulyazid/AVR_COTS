/*
 * Interrupt_config.h
 *
 *  Created on: Dec 22, 2023
 *      Author: Sherif
 */

#ifndef INTERRUPT_CONFIG_H_
#define INTERRUPT_CONFIG_H_


#define LOW_LEVEL						1
#define ON_CHANGE						2
#define FALLING_EDGE					3
#define RISING_EDGE						4

#define EXTI_INT0_SENSE_CONTROL			LOW_LEVEL
#define EXTI_INT1_SENSE_CONTROL			LOW_LEVEL
#define EXTI_INT2_SENSE_CONTROL			RISING_EDGE


#endif /* INTERRUPT_CONFIG_H_ */
