/*
 * Pressure_Sensor.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Michael Maged
 */
#include "driver.h"
#include "Pressure_Sensor.h"
//define the variables of block
int Pval=0,Psensor_pull_time=1000;
//declare the function is to be send to main function
void Read_Pressure(int Pval);
//define the pointer to function to store the current state of pressure sensor
void (*Pointer_sensor)();
//init function of pressure sensor
void Pressure_Sensor_init()
{
	Pointer_sensor=STATE_(reading_state);//by default the start of pressure sensor read of pressure
}
//===================================================
//defination the states of Pressure Sensor
STATE_Define(waiting_state)
{
	Delay(Psensor_pull_time);//delay to waiting period and reading again
	Pointer_sensor=STATE_(reading_state);
}
//===================================================
STATE_Define(reading_state)
{
	Pval=getPressureVal();
	Read_Pressure(Pval);
	Pointer_sensor=STATE_(waiting_state);
}
//===================================================

