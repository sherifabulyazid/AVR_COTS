/*
 * GPIO_REGISTER.h
 *
 *  Created on: Feb 6, 2024
 *      Author: hp
 */

#ifndef GPIO_REGISTER_H_
#define GPIO_REGISTER_H_

typedef struct {
	uint32 CRL;
	uint32 CRH;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 BRR;
	uint32 LCKR;
}GPIO_t;

#define GPIOA    ((volatile GPIO_t*)0x40010800)
#define GPIOB    ((volatile GPIO_t*)0x40010C00)
#define GPIOC    ((volatile GPIO_t*)0x40011000)
#define GPIOD    ((volatile GPIO_t*)0x40011400)
#define GPIOE    ((volatile GPIO_t*)0x40011800)

#endif /* GPIO_REGISTER_H_ */
