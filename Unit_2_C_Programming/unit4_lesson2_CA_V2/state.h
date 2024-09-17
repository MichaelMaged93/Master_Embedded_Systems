/*
 * state.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Michael Maged
 */

#ifndef STATE_H_
#define STATE_H_

//Automatic State Function Generated
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()//to can be declare the function in CA.h
#define STATE(_stateFUN_)  ST_##_stateFUN_//to can be pass address of function to pointer

//States connection
void US_set_distance(int d);
void DC_motor(int s);

#endif /* STATE_H_ */
