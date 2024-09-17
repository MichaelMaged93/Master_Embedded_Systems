/*
 * Main_Function.h
 *
 *  Created on: Sep 15, 2024
 *      Author: Michael Maged
 */

#ifndef MAIN_FUNCTION_H_
#define MAIN_FUNCTION_H_
#include "driver.h"
//define the states of the main function
typedef enum {
    main_waiting,
    main_detect_high_pressure
} State_Main;
//===================================================
//declare the function for each states
STATE_Define(main_waiting);
STATE_Define(main_detect_high_pressure);
//===================================================
//declare the pointer to function to read form all files
extern void (*Pointer_main_state)();

#endif /* MAIN_FUNCTION_H_ */
