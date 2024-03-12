/*
 * GPIO_INTERFACE.h
 *
 *  Created on: Feb 6, 2024
 *      Author: hp
 */
#include "STD.h"
#include "BIT_MATH.h"
#include "GPIO_REGISTER.h"
#include "GPIO_CONFIG.h"
#include "GPIO_INTERFACE.h"
#include "GPIO_Private.h"

void GPIO_VoidSetPinDirection(uint8 Copy_uint8Port,uint8 copy_uint8Pin,uint8 Copy_uint8Mode);
void GPIO_VoidSetPinValue(uint8 Copy_uint8Port,uint8 copy_uint8Pin,uint8 Copy_uint8Value);
uint8 GPIO_VoidGetPinValue(uint8 Copy_uint8Port,uint8 copy_uint8Pin,uint8* Copy_uint8PinStatus);

