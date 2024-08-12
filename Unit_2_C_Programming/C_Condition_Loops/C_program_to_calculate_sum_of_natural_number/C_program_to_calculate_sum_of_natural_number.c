/*
 ============================================================================
 Name        : C_program_to_calculate_sum_of_natural_number.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num,sum=0 ;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	for(int i=1; i<=num;i++){
		sum+=i;
	}
	printf("sum = %d",sum);
	fflush(stdin); fflush(stdout);
	return 0;
}
