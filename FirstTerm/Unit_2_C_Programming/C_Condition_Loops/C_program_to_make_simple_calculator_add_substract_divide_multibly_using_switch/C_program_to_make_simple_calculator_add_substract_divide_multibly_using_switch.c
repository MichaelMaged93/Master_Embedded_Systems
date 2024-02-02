/*
 ============================================================================
 Name        : C_program_to_make_simple_calculator_add_substract_divide_multibly_using_switch.c
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
	char operat ;
	printf("Enter the first number :");
	fflush(stdin); fflush(stdout);
	scanf("%f",&num1);
	printf("Enter the operation either + or - or / or * :");
	fflush(stdin); fflush(stdout);
	scanf("%c",&operat);
	fflush(stdin); fflush(stdout);
	printf("Enter the second number :");
	fflush(stdin); fflush(stdout);
	scanf("%f",&num2);
	switch (operat){
	case '+' :{
		printf("%f %c %f = %f ",num1,operat,num2,num1+num2);
		break ;
	}
	case '-' :{
		printf("%f %c %f = %f ",num1,operat,num2,num1-num2);
		break ;
	}
	case '/' :{
		printf("%f %c %f = %f ",num1,operat,num2,num1/num2);
		break ;
	}
	case '*' :{
		printf("%f %c %f = %f ",num1,operat,num2,num1*num2);
		break ;
	}
	default :
		printf("Error! operator is not correct");
	}
	return 0;
}
