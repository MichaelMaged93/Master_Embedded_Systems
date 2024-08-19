/*
 * fifo.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Michael Maged
 */
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "fifo.h"
//defination the APIs
FIFO_buf_status FIFO_init(FIFO_buf_t* fifo , element_types* buf, uint32_t length)
{
	//to check the FIFO is existed or no
	if(buf==NULL)
		return FIFO_null;
	//to intialize the FIFO
	fifo->base=buf;
	fifo->head=buf;
	fifo->tail=buf;
	fifo->length=length;
	fifo->counter=0;
	return FIFO_no_error;
}


FIFO_buf_status FIFO_Enqueue(FIFO_buf_t* fifo , element_types item)
{
	//to check the FIFO is not null and check the base , tail , head is existed
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	//to check the FIFO IS FULL or no?
	if(FIFO_IS_FULL(fifo)==FIFO_full)
		return FIFO_full;
	//start of Enqueue process
	*(fifo->head)=item; //assign the value of the item in head
	fifo->counter++;// increment the counter
	//write code of circular FIFO
	if(fifo->head==(fifo->head+(fifo->length*sizeof(element_types))))//if the head is reach to end of FIFO or no
		fifo->head=fifo->base;
	else
		fifo->head++;

	return FIFO_no_error;//return the status of FIFO
}


FIFO_buf_status FIFO_Dequeue(FIFO_buf_t* fifo , element_types* item)
{
	//to check the FIFO is not null and check the base , tail , head is existed
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	//check FIFO is empty ?
	if(fifo->counter==0)
		return FIFO_empty;

	//Start of dequeue process
	*item=*(fifo->tail);//pop the value from FIFO to pointer to print it or another process and empty this location
	fifo->counter--;// decrement the counter

	//write code of circular FIFO
	if(fifo->tail==(fifo->tail+(fifo->length*sizeof(element_types))))
		fifo->tail=fifo->base;

	else
		fifo->tail++;

	return FIFO_no_error;
}


//to check the FIFO is full or not
FIFO_buf_status FIFO_IS_FULL(FIFO_buf_t* fifo)
{
	//to check the FIFO is not null and check the base , tail , head is existed
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	//to check the FIFO is full or no
	if(fifo->counter>=fifo->length)
		return FIFO_full;

	return FIFO_no_error;
}
FIFO_buf_status FIFO_EMPTY(FIFO_buf_t* fifo)
{
	//check if FIFO is null
	if(!fifo->head||!fifo->base||!fifo->tail)
		return FIFO_null;
	//to check FIFO is empty
	if(fifo->counter==0)
		return FIFO_empty;

	return FIFO_no_error;
}
void FIFO_print(FIFO_buf_t* fifo)
{
	element_types* temp=0;//pointer to return values from FIFO
	int i ;
	if(fifo->counter==0){
		printf("FIFO is Empty \n");
	}
	else {
		temp = fifo->tail;//to be sure the data print first in first out
		printf("\n============FIFO is print==============\n");
		for(i=0;i<fifo->counter;i++)
		{
			if(fifo->tail==(fifo->base+(fifo->length*sizeof(element_types))))
				temp=fifo->base;
			else{
				printf(" %x \n",*temp);
				temp++;
				//to print the next value
			}
			printf("*=================<Done>================*\n");
		}
	}
}


