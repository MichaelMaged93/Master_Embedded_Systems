/*
 * Alarm_Actuator.h
 *
 *  Created on: Sep 15, 2024
 *      Author: Michael Maged
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_
#include "driver.h"
//define the state of alarm actuator
typedef enum {
    start,
    stop,
    wait
} state_alarm;

//===================================================
//define function to send state of alarm to alarm actuator
void State_Actuator(state_alarm state);
//===================================================
//define the function of each state
STATE_Define(stop);
STATE_Define(start);
STATE_Define(wait);
extern void (*state_alarm_actuator)();
#endif /* ALARM_ACTUATOR_H_ */
