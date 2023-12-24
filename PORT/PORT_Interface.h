/*
 * PORT_Interface.h
 *
 *  Created on: Dec 22, 2023
 *      Author: sherif
 */

#ifndef PORT_INTERFACE_H_
#define PORT_INTERFACE_H_

void Port_void_voidInit(void);

#define CONC_HELPER(p7,p6,p5,p4,p3,p2,p1,p0) 0b##p7##p6##p5##p4##p3##p2##p1##p0
#define CONC(p7,p6,p5,p4,p3,p2,p1,p0) CONC_HELPER(p7,p6,p5,p4,p3,p2,p1,p0)

#endif /* PORT_INTERFACE_H_ */
