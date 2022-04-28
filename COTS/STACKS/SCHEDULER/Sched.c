/*
 * Sched.c
 *
 *  Created on: Apr 14, 2022
 *      Author: dahroug
 */


/****** section of includes ******/
#include "Std_types.h"

#include "Sched.h"
#include "Sched_prv.h"
#include "Sched_cfg.h"

#include "Gpt.h"
/* ----------------------------- */

/***************************** Section of global variables **************************************/
static TaskCtrlBlock_t*  SCHED_tenuArrTasks [SCHED_TASKS_NUM] = {NULL};

static u8 		   SCHED_su8TasksCounter     				  = SCHED_ZERO;

u8 				   SCHED_u8StartFlag 						  = SCHED_STOP;
/* -------------------------------------------------------------------------------------------- */


/****************************************************** section of User function section  ******************************************************/

Std_enuErrorStatus Sched_tenuInit(void)
{
	Std_enuErrorStatus Loc_tenuErrStatusRetVal = OK;

	if (Gpt_enuInit() != OK )
	{
		Loc_tenuErrStatusRetVal = NOK;
	}
	else if (Gpt_enuRegisterCbf_TIM0_OVF(Sched_vidSetSchedRunFlag) != OK)
	{
		Loc_tenuErrStatusRetVal = NULL_PTR;
	}
	else
	{

	}
	return Loc_tenuErrStatusRetVal;
}

Std_enuErrorStatus Sched_tenuAddTask(TaskCtrlBlock_t* Add_typeTcbTask)
{

	Std_enuErrorStatus Loc_tenuErrStatusRetVal = OK;

	if (SCHED_su8TasksCounter == SCHED_TASKS_NUM)
	{
		Loc_tenuErrStatusRetVal = NOK;
	}
	else if (Add_typeTcbTask == NULL)
	{
		Loc_tenuErrStatusRetVal = NULL_PTR;
	}
	else
	{
		SCHED_tenuArrTasks[SCHED_su8TasksCounter] = Add_typeTcbTask;
		SCHED_tenuArrTasks[SCHED_su8TasksCounter]->index = SCHED_su8TasksCounter;
	}

	SCHED_su8TasksCounter ++;

	return Loc_tenuErrStatusRetVal;

}

Std_enuErrorStatus  Sched_tenuStopTask (u8 Copy_u8TaskIndex)
{
	Std_enuErrorStatus Loc_tenuErrStatusRetVal = OK;

	if (SCHED_tenuArrTasks[Copy_u8TaskIndex] == NULL)
	{
		Loc_tenuErrStatusRetVal = NULL_PTR;
	}
	else
	{
		SCHED_tenuArrTasks[Copy_u8TaskIndex]->state = PASSIVE;
	}

	return Loc_tenuErrStatusRetVal;
}

void 				Sched_vidDeleteTask(u8 Copy_u8TaskIndex)
{
	if (SCHED_tenuArrTasks[Copy_u8TaskIndex] != NULL)
	{
		while (Copy_u8TaskIndex < SCHED_su8TasksCounter)
		{
			SCHED_tenuArrTasks[Copy_u8TaskIndex] = SCHED_tenuArrTasks[Copy_u8TaskIndex + SCHED_ONE];
			if (SCHED_tenuArrTasks[Copy_u8TaskIndex + SCHED_ONE] != NULL)
			{
				SCHED_tenuArrTasks[Copy_u8TaskIndex]->index = SCHED_tenuArrTasks[Copy_u8TaskIndex]->index - SCHED_ONE;
			}
			else
			{

			}

			Copy_u8TaskIndex++;
		}
		SCHED_su8TasksCounter --;
	}
	else
	{

	}
}

Std_enuErrorStatus  Sched_tenuStartSched (void)
{
	Std_enuErrorStatus Loc_tenuErrStatusRetVal = OK;

		if (Gpt_enuStartTimer(TIMER0, SCHED_TICK) != OK)
		{
			Loc_tenuErrStatusRetVal = NOK;
		}
		else
		{
			while(1)
			{
				if (SCHED_u8StartFlag == SCHED_START)
				{
					SCHED_u8StartFlag = SCHED_STOP;
					Sched_vidRunSched();
				}
			}
		}
	return Loc_tenuErrStatusRetVal;
}
/*--------------------------------------------------------------------------------------------------*/


/************************* section of private function section  ************************************/
void Sched_vidRunSched(void)
{
	u8 Loc_u8SchedIterator;

	#if SCHED_PRORITY
		u8 Loc_u8TaskIterator, Loc_u8SizeReference = SCHED_ONE;

		u8 Loc_u8TasksOrderState = SCHED_NOT_SORTED;

		while (Loc_u8TasksOrderState == SCHED_NOT_SORTED)
		{
			Loc_u8TasksOrderState = SCHED_SORTED;

			for (Loc_u8TaskIterator = SCHED_ZERO; Loc_u8TaskIterator < (SCHED_TASKS_NUM - Loc_u8SizeReference); Loc_u8TaskIterator++)
			{
				if (SCHED_tenuArrTasks[Loc_u8TaskIterator]->priority > SCHED_tenuArrTasks[Loc_u8TaskIterator + SCHED_ONE]->priority)
				{
					Sched_vidSwapTasks(SCHED_tenuArrTasks[Loc_u8TaskIterator], SCHED_tenuArrTasks[Loc_u8TaskIterator + SCHED_ONE]);
					Loc_u8TasksOrderState = SCHED_NOT_SORTED;
				}
				else
				{

				}
			}

			Loc_u8SizeReference ++;
		}
	#endif

	for (Loc_u8SchedIterator = SCHED_ZERO; Loc_u8SchedIterator < SCHED_TASKS_NUM; Loc_u8SchedIterator++)
	{
		if (SCHED_tenuArrTasks[Loc_u8SchedIterator] != NULL)
		{
			if (SCHED_tenuArrTasks[Loc_u8SchedIterator]->state == RUNNING)
				{
					if (SCHED_tenuArrTasks[Loc_u8SchedIterator]->firstDelay == SCHED_ZERO && SCHED_tenuArrTasks[Loc_u8SchedIterator]->pCode != NULL)
					{
						SCHED_tenuArrTasks[Loc_u8SchedIterator]->pCode();
						SCHED_tenuArrTasks[Loc_u8SchedIterator]->firstDelay = SCHED_tenuArrTasks[Loc_u8SchedIterator]->periodicity;
					}
					else
					{

					}
					SCHED_tenuArrTasks[Loc_u8SchedIterator]->firstDelay --;
				}
			else
			{

			}
		}
		else
		{

		}

	}


}

#if SCHED_PRORITY
void Sched_vidSwapTasks (TaskCtrlBlock_t* Add_tenuTask1, TaskCtrlBlock_t* Add_tenuTask2)
{
		TaskCtrlBlock_t Loc_tenuTaskTempHolder = *Add_tenuTask1;
		*Add_tenuTask1 = *Add_tenuTask2;
		*Add_tenuTask2 = Loc_tenuTaskTempHolder;

		Add_tenuTask1->index = Add_tenuTask1->priority;
		Add_tenuTask2->index = Add_tenuTask2->priority;
}
#endif

void Sched_vidSetSchedRunFlag(void)
{
	SCHED_u8StartFlag = SCHED_START;
}
/* ------------------------------------------------------------------------------------------------ */
