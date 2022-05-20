/*
 * PWMOut.c
 *
 *  Created on: May 19, 2022
 *      Author: dahroug
 */

#include "Std_types.h"
#include "Bit_utils.h"
#include "Int_vect_map.h"

#include "Gpt.h"

#include "PWMOut.h"
#include "PWMOut_prv.h"
#include "PWMOut_cfg.h"


Std_enuErrorStatus Pwm_enuInit(PwmCfg_t* Add_PwmCfg)
{
	Std_enuErrorStatus Loc_enuRetErrStatus = OK;

	if (Add_PwmCfg == NULL)
	{
		Loc_enuRetErrStatus = NULL_PTR;
	}
	else


	return Loc_enuRetErrStatus;
}
