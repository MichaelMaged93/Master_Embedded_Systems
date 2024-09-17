/*
 * CA.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Michael Maged
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"
#include "stdio.h"
#include "stdlib.h"
//Define State
enum
{
	DC_idle,
	DC_busy,
}DC_State_ID ;

//Declare state functions CA
STATE_define(DC_idle);
STATE_define(DC_busy);
void DC_init();
//STATE pointer to function
extern void (*DC_state)();


#endif /* DC_H_ */
