/*
 ============================================================================
 Name        : C_program_to_find_factorial_of_number.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num ,fact=1;
	printf("Enter an integer :");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	if(num>0){
	for(int i=num;i>0;i--){
		fact=fact*i;
	}
	printf("Factorial = %d",fact);
	}
	else if(num<0){
		printf("Error!!! the Factorial of negative number is doesnt exist ");
	}
	else
		printf("the factorial = 1");
	return 0;
}
