/*
 * main.c
 *
 *  Created on: Aug 14, 2024
 *      Author: Michael
 */
#include "lifo.h"
#include "stdio.h"
#include "stdlib.h"
#include "Platform_types.h"
unsigned int buffer1[5];

void main(){
	LIFO_Buf_t uart_lifo , I2C_lifo ;
	//static allocation
	LIFO_init(&uart_lifo ,buffer1,5);
	//dynamic allocation
	unsigned int* buffer2 =(unsigned int*)malloc (5*sizeof(unsigned int));//5*4=20 Bytes dynamic
	LIFO_init(&I2C_lifo ,buffer2 ,5);

	for(int i=0;i<5;i++){
		if( LIFO_Add_item(&uart_lifo,i)==LIFO_no_error )
			printf("Uart_LIFO add : %d\n",i);
	}

	for(int i=0;i<5;i++){
		int temp=0;
		if( LIFO_Pop_item(&uart_lifo,&temp) == LIFO_no_error)
			printf("Uart_LIFO Pop : %d\n",temp);
	}
}
