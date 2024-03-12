/*
 * RTOS_Prog.c
 *
 *  Created on: Jan 27, 2024
 *      Author: Sherif Abuelyazid
 */
#include "STD.h"
#include "BIT_MATH.h"
#include "RTOS_Config.h"
#include "RTOS_Interface.h"
#include "RTOS_Private.h"
#include "Timer_interface.h"

task_t Tasks_Array[TASK_NUMS] = {{0}};

void RTOS_Start(void)
{
	Timer0_CTC_CallBack(&RTOS_schedular);
	Enable_Global_Interrupt();
	Timer0_CTC();
}

uint8 RTOS_CreateTask(uint8 copy_priority, uint16 copy_periodicity, uint16 copy_firstDelay, void (*copy_Task_Funcion)(void))
{
	uint8 local_error=0;
	if(Tasks_Array[copy_priority].task_fn_ptr == NULL)
	{
		Tasks_Array[copy_priority].task_fn_ptr=copy_Task_Funcion;
		Tasks_Array[copy_priority].priority=copy_priority;
		Tasks_Array[copy_priority].firstDelay = copy_firstDelay;
		Tasks_Array[copy_priority].taskState=TASK_STATE_RUNNING;
		Tasks_Array[copy_priority].priodicity= copy_periodicity;
	}
	else
	{
		local_error=1;
	}

	return local_error;
}
void RTOS_SuspendTask(uint8 copy_priority)
{
	Tasks_Array[copy_priority].taskState=TASK_STATE_SUSPENDED;
}
void RTOS_ResumeTask(uint8 copy_priority)
{
	Tasks_Array[copy_priority].taskState=TASK_STATE_RUNNING;
}
void RTOS_DeleteTask(uint8 copy_priority)
{
	Tasks_Array[copy_priority].task_fn_ptr = NULL;
}

static void RTOS_schedular(void)
{
	
	uint8 iterator=0;

	for (iterator=0; iterator<TASK_NUMS; iterator++)
	{

		if (Tasks_Array[iterator].taskState==TASK_STATE_RUNNING)
		{
			if (Tasks_Array[iterator].firstDelay != 0)
			{
				Tasks_Array[iterator].firstDelay--;
			}
			else
			{
				Tasks_Array[iterator].firstDelay= Tasks_Array[iterator].priodicity-1;
				if(Tasks_Array[iterator].task_fn_ptr != NULL)
				{
					Tasks_Array[iterator].task_fn_ptr();
				}
				else
				{

				}
			}
		}
		else
		{
			/*Do nothing*/
		}
	}
}
