/*
 * fifo.h
 *
 *  Created on: Aug 15, 2024
 *      Author: Michael Maged
 */
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#ifndef FIFO_H_
#define FIFO_H_

//user cofiguration

//slect the element types (uint8_t , uint26_t , uint32_t , ....)
#define element_types uint8_t


//FIFO data types
typedef struct {
	uint32_t length; //the size of buffer
	uint32_t counter;//to increment the number of value it assign in buffer
	element_types* head ;//to increment the location in buffer to assign the next value
	element_types* base ;//the statrt address of buffer
	element_types* tail ;//to pop value and empty location
}FIFO_buf_t;
//create enum to return the status of buffer
typedef enum{
	FIFO_no_error,//0
	FIFO_full,//1
	FIFO_empty,//2
	FIFO_null//3
}FIFO_buf_status;

//FIFO_APIs
FIFO_buf_status FIFO_init(FIFO_buf_t* fifo , element_types* buf, uint32_t length);//to create buffer and assign in the array
FIFO_buf_status FIFO_Enqueue(FIFO_buf_t* fifo , element_types item);//to push values from uart or another mcu
FIFO_buf_status FIFO_Dequeue(FIFO_buf_t* fifo , element_types* item);//to pop values from uart or another mcu
FIFO_buf_status FIFO_EMPTY(FIFO_buf_t* fifo);
FIFO_buf_status FIFO_IS_FULL(FIFO_buf_t* fifo);//to check the buffer is full or no
void FIFO_print(FIFO_buf_t* fifo);//to print all values in buffer

#endif /* FIFO_H_ */
