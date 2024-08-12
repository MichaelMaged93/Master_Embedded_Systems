/*
 ============================================================================
 Name        : EX4_C_Program_to_Calculate_the_Power_of_a_Number_Using_Recursion.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int power_fun(int base,int power);
int main(void) {
	int base_num , power_num,result,negative_power;
	printf("Enter the base number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&base_num);
	fflush(stdin); fflush(stdout);
	printf("Enter the power number(positive integer):");
	fflush(stdin); fflush(stdout);
	scanf("%d",&power_num);
	if(power_num>1){
	result = power_fun(base_num,power_num);
	printf(" %d ^ %d = %d ",base_num,power_num,result);
	}
	else if(power_num<1){
	negative_power=-power_num;
	result = power_fun(base_num,negative_power);
	printf(" %d ^ %d = 1/%d ",base_num,power_num,result);
	}
	else
		printf(" %d ^ %d = %d ",base_num,power_num,1);

	return 0;
}
int power_fun(int base,int power){
	if(power>=1)
		return base*power_fun(base,power-1);
	else
		return 1;
}
