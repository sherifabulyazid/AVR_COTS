/*
 * RTOS_Interface.h
 *
 *  Created on: Jan 27, 2024
 *      Author: Sherif Abuelyazid
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_



typedef struct {
	uint8 priority;
	uint16 priodicity;
	uint16 firstDelay;
	uint8 taskState;
	void (*task_fn_ptr) (void);

}task_t;

void RTOS_Start(void);
uint8 RTOS_CreateTask(uint8 copy_priority, uint16 copy_periodicity, uint16 copy_firstDelay, void (*copy_Task_Funcion)(void));
void RTOS_SuspendTask(uint8 copy_priority);
void RTOS_ResumeTask(uint8 copy_priority);
void RTOS_DeleteTask(uint8 copy_priority);

#endif /* RTOS_INTERFACE_H_ */
