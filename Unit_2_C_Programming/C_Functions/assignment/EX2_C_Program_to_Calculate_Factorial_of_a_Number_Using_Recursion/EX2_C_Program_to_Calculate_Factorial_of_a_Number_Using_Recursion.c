/*
 ============================================================================
 Name        : EX2_C_Program_to_Calculate_Factorial_of_a_Number_Using_Recursion.c
 Author      : Michael Maged
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int fact(int n);
int main(void) {
	int n,result=0;
	printf("Enter the number : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	if(n>=1){
		result = fact(n);
	}
	else
		printf("no factorial for zero\n");

	printf(" the factorial of %d = %d",n,result);
	return 0;
}
int fact(int n){
	if(n==1)
		return 1;
	else
		return n*fact(n-1) ;
}
