/*
 * Alarm_Monitor.h
 *
 *  Created on: Sep 15, 2024
 *      Author: Michael Maged
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "driver.h"
//define states of this block
typedef enum
{
	stop_alarm,
	start_alarm,
}State_Alarm;
//define the function for each state
STATE_Define(stop_alarm);
STATE_Define(start_alarm);
//declare the pointer to function to read form all files
extern void (*Pointer_Alarm_state)();

#endif /* ALARM_MONITOR_H_ */
