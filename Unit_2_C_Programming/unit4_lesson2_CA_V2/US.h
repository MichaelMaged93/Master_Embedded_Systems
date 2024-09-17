/*
 * CA.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Michael Maged
 */

#ifndef US_H_
#define US_H_
#include "state.h"
#include "stdio.h"
#include "stdlib.h"
//Define State
enum
{
	US_busy
}US_State_ID ;
//Declare state functions US
STATE_define(US_busy);
void US_init();
//STATE pointer to function
extern void (*US_state)();


#endif /* US_H_ */
