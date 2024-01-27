/*
 * RTOS_Private.h
 *
 *  Created on: Jan 27, 2024
 *      Author: Sherif Abuelyazid
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

void (*schedular)(void);
static void RTOS_schedular(void);

#define TASK_STATE_RUNNING     1
#define TASK_STATE_SUSPENDED   2


#endif /* RTOS_PRIVATE_H_ */
