/*
 * main.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Michael Maged
 */

#include "fifo.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#define width 5
element_types buffer[width];
void main(){
	FIFO_buf_t FIFO_UART ;
	element_types i,temp=0;
	if(FIFO_init(&FIFO_UART,buffer,5)==FIFO_no_error)
		printf("FIFO init is-------------->DONE \n");
	for(i=0;i<7;i++){
		printf("FIFO enqueue (%x) \n",i);
		if(FIFO_Enqueue(&FIFO_UART,i)==FIFO_no_error)
			printf("fifo enqueue is----------DONE \n");
		else
			printf("fifo enqueue is----------failed \n");
	}
	FIFO_print(&FIFO_UART);
	if(FIFO_Dequeue(&FIFO_UART,&temp)==FIFO_no_error)
		printf("fifo dequeue %x \n",temp);
	if(FIFO_Dequeue(&FIFO_UART,&temp)==FIFO_no_error)
		printf("fifo dequeue %x \n",temp);
	FIFO_print(&FIFO_UART);
	for(i=8;i<10;i++){
		FIFO_Enqueue(&FIFO_UART,i);
		printf("fifo enqueue is----------DONE \n");
	}
	FIFO_print(&FIFO_UART);
}
