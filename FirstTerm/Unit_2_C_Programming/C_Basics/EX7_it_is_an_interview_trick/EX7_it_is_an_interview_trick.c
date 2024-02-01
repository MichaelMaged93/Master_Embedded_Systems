/*
 ============================================================================
 Name        : EX7_it_is_an_interview_trick.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float num1 , num2 ;
	printf("Enter value of num1: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&num1);
	fflush(stdin); fflush(stdout);
	printf("Enter value of num2: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&num2);
	num1=num1+num2;
	num2=num1-num2;
	num1=num1-num2;
	printf("Enter value of num1: %f\n",num1);
	printf("Enter value of num2: %f",num2);
	return 0;
}
