/*
 * CA.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Michael Maged
 */
#include "state.h"
#include "CA.h"
//Variables
int CA_speed=0;
int CA_distance=0;
int CA_threshold=50;


//STATE pointer to function
void (*CA_state)();
//=========================================================================================================
void US_set_distance(int d)
{
	CA_distance=d;
	(CA_distance<=CA_threshold)? (CA_state=STATE(CA_waiting)):(CA_state=STATE(CA_driving));
	printf("US----------Distance=%d------->CA \n",CA_distance);
}
//======================================================================================================
STATE_define(CA_waiting)
{
	//State_Name
	CA_State_ID=CA_waiting;
	printf("CA_waiting State: distance = %d speed = %d \n",CA_distance,CA_speed);

	//State_Action
	CA_speed=0;
	//DC_Motor(speed)
	DC_motor(CA_speed);
}


//==================================================================================
STATE_define(CA_driving)
{
	//State_Name
	CA_State_ID=CA_driving;
	printf("CA_driving State: distance = %d speed = %d \n",CA_distance,CA_speed);
	//State_Action
	CA_speed=30;
	//DC_Motor(speed)
	DC_motor(CA_speed);
}

