/*
 * CA.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Michael Maged
 */
#include "state.h"
#include "DC.h"
//Variables
int DC_speed=0;



//STATE pointer to function
void (*DC_state)();


void DC_init()
{
	//init DC driver
	printf(" DC_init \n");
}

//================================================================================================

void DC_motor(int s)
{
	DC_speed=s;
	DC_state=STATE(DC_busy);
	printf("CA----------Speed=%d------->DC \n",DC_speed);

}
//==============================================================================================
STATE_define(DC_idle)
{
	//State_Name
	DC_State_ID=DC_idle;
	//State_Action
	//call DC_motor to make speed = DC_speed

	printf("DC_idle State: speed = %d \n",DC_speed);
}

//==================================================================================================
STATE_define(DC_busy)
{
	//State_Name
	DC_State_ID=DC_busy;
	//DC_Motor(speed)
	DC_state=STATE(DC_idle);

	//Event_Check
	printf("DC_busy State: speed = %d \n",DC_speed);
}

