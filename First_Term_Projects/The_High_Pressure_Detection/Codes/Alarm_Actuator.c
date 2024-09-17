/*
 * Alarm_Actuator.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Michael maged
 */
#include "Alarm_Actuator.h"

//define pointer to store the state of alarm actuator
void (*state_alarm_actuator)();
//===================================================

void Alarm_Actuator_init()
{
	state_alarm_actuator=STATE_(stop);
}
//===================================================

void State_Actuator(state_alarm state)
{
	if( state == start)
	{
		state_alarm_actuator=STATE_(start);
	}
	else if(state == stop)
	{
		state_alarm_actuator=STATE_(stop);
	}
}
//===================================================

STATE_Define(stop)
{
	Set_Alarm_actuator(1);
	state_alarm_actuator=STATE_(stop);
}
STATE_Define(start)
{
	Set_Alarm_actuator(0);
	state_alarm_actuator =STATE_(wait);
}
STATE_Define(wait)
{
	Delay(60000);
	state_alarm_actuator=STATE_(stop);
}
//===================================================

