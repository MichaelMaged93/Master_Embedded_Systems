/*
 * main.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Michael Maged
 */
#include "CA.h"
void setup()
{
	// init all the Drivers
	// init IRQ ....
	//init HAL US_Driver DC_Driver
	//init block
	//set States pointers for each block
	CA_state=STATE(CA_waiting);
}

void main()
{
setup();
while(1)
{
	CA_state();
}
}
