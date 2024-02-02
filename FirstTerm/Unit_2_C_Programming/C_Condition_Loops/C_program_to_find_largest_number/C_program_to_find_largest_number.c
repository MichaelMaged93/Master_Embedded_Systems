/*
 ============================================================================
 Name        : C_program_to_find_largest_number.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float num1 ,num2 ,num3 ;
	printf("Enter three Numbers :");
	fflush(stdin); fflush(stdout);
	scanf("%f %f %f",&num1 ,&num2 ,&num3);
	if (num1>num2&&num1>num3){
		printf("the largest number is %f ",num1);
	}
	else if (num2>num1&&num2>num3){
			printf("the largest number is %f",num2);
		}
	else
		printf("the largest number is %f ",num3);
	return 0;
}
