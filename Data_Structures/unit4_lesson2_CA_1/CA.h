/*
 * CA.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Michael Maged
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
#include "stdio.h"
#include "stdlib.h"
//Define State
enum
{
	CA_waiting,
	CA_driving,
}CA_State_ID ;

//Declare state functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

//STATE pointer to function
extern void (*CA_state)();


#endif /* CA_H_ */
