/*
 * CA.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Michael Maged
 */
#include "state.h"
#include "US.h"
//Variables
int US_distance=0;

//STATE pointer to function
void (*US_state)();
int US_Get_distance_random(int l , int r , int count);
void US_init()
{
	//init US driver
	printf(" US_init \n	");
}
STATE_define(US_busy)
{
	//State_Name
	US_State_ID=US_busy;
	//state action
	US_distance=US_Get_distance_random(45,55,1);
	//DC_Motor(speed)
	//US_Get(CA_distance)
	//Event_Check
	printf("US_waiting State: distance = %d \n",US_distance);
	US_set_distance(US_distance);
	US_state =STATE(US_busy);
}

int US_Get_distance_random(int l , int r , int count)
{
	//this will generate random number in range l and r
	int i ;
	for(i=0;i<count;i++)
	{
		int rand_num = (rand()%(r-l+1))+l;
		return rand_num;

	}


}
