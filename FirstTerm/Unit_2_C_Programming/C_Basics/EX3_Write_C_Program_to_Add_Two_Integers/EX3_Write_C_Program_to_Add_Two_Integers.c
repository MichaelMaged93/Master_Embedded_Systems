/*
 ============================================================================
 Name        : EX3_Write_C_Program_to_Add_Two_Integers.c
 Author      : Michael Maged
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num1, num2, sum;

	printf("Enter two integers: ");
     fflush(stdout);
	scanf("%d %d",&num1,&num2);
	sum = num1 + num2;

	printf("Sum: %d",sum);

	return 0;
}
