/*
 * Pressure_Sensor.h
 *
 *  Created on: Sep 15, 2024
 *      Author: Michael Maged
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
#include "driver.h"
//===================================================
//Define States of Presure Sensor
typedef enum {
    waiting_state,
    reading_state
} state_sensor;
//===================================================
// function to initialize the Pressure Sensor
void Pressure_Sensor_init();
//===================================================
//declare the function of states
STATE_Define(waiting_state);
STATE_Define(reading_state);
//===================================================
//declare the pointer to function to read from the main function
extern void (*Pointer_sensor)();
#endif /* PRESSURE_SENSOR_H_ */
