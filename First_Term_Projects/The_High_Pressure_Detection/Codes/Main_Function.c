/*
 * Main_Function.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Michael maged
 */
#include"stdio.h"
#include "Main_Function.h"
//define the variables for this block
int P_value=0,P_threshold=20;
//declare the function to send signal to alarm in state detect the high pressure
void High_Pressure_Detect();
//define the pointer to function to store the state of main function
void (*Pointer_main_state)();
//===================================================
//defination the function it read from pressure sensor
void Read_Pressure(int Pval)
{
	P_value=Pval;
	(P_value <= P_threshold)? (Pointer_main_state=STATE_(main_waiting)) : (Pointer_main_state=STATE_(main_detect_high_pressure));

}
//===================================================
//defination the function for each states
STATE_Define(main_waiting)
{
	Pointer_main_state=STATE_(main_waiting);
}
STATE_Define(main_detect_high_pressure)
{
	High_Pressure_Detect();
	Pointer_main_state=STATE_(main_waiting);
}
//===================================================
