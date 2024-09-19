/*
 * main.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Michael Maged
 */
#include "CA.h"
#include "DC.h"
#include "US.h"
#include "state.h"
void setup()
{
	// init all the Drivers
	// init IRQ ....
	//init HAL US_Driver DC_Driver
	//init block
	US_init();
	DC_init();
	//set States pointers for each block
	CA_state=STATE(CA_waiting);
	US_state=STATE(US_busy);
	DC_state=STATE(DC_idle);
}

void main()
{
setup();
while(1)
{

	//call state for each block
	US_state();
	CA_state();
	DC_state();
	//Delay
	for(int d=0;d<=1000;d++);

}
}
