/**
 ******************************************************************************
 * @file           : main.c
 * @author         :Michael Maged
 * @brief          : toggle led in cortexM4
 ******************************************************************************
 */
#include <stdint.h>
#define SYSCTL_RCGC2_R  (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR_R *((volatile unsigned long*)(0x40025400))
#define GPIO_PORTF_DEN_R *((volatile unsigned long*)(0x4002551C))
#define GPIOA_PORTF_DATA_R *((volatile unsigned long*)(0x400253FC))
int main(void){
	volatile unsigned long int delay_cont ;
	SYSCTL_RCGC2_R = 0x20 ;
	//delay to mke sure GPIO is up and runing 
	for ( delay_cont = 0; delay_cont < 200; delay_cont++);
		GPIO_PORTF_DIR_R |=1<<3 ; //DIR IS output for pin 3 port F
		GPIO_PORTF_DEN_R |=1<<3 ;
		while(1)
		{
			GPIOA_PORTF_DATA_R |= 1<<3 ;
			for ( delay_cont = 0; delay_cont < 200000; delay_cont++);
			GPIOA_PORTF_DATA_R &= ~(1<<3) ;
			for ( delay_cont = 0; delay_cont < 200000; delay_cont++);

		}

	return 0;
}
