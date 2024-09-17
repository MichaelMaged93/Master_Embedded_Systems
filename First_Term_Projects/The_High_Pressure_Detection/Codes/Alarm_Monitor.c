/*
 * Alarm_Monitor.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Michael maged
 */
#include "Alarm_Monitor.h"
#include "Alarm_Actuator.h"

//===================================================
//define the pointer to store the state of alarm
void (*Pointer_Alarm_state)();
//defination the function that get the signal from the main
void High_Pressure_Detect()
{
	Pointer_Alarm_state=STATE_(start_alarm) ;
}
//===================================================

//the defination for each state in alarm
STATE_Define(stop_alarm)
{
	State_Actuator(stop);
	Pointer_Alarm_state=STATE_(stop_alarm) ;
}
STATE_Define(start_alarm)
{
	State_Actuator(start);
	Pointer_Alarm_state=STATE_(stop_alarm) ;
}

//===================================================
