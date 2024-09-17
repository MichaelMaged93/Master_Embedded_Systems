/*
 * main.c
 *
 *  Created on: Sep 6, 2024
 *      Author: Michael Maged
 */
#include "stdio.h"
#include "string.h"
int fun_sum_digits(char arr[]);
int main()
{
	int sum=0;
	char arr[30];
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%s",arr);//store number in array as a char
	sum=fun_sum_digits(arr);
	fflush(stdin); fflush(stdout);
	printf("->the output = %d",sum);
	return 0;
}
int fun_sum_digits(char arr[])
{int sum=0;//to return value
int integer_value=0;//to store int value
for(int i=0;arr[i]!='\0';i++)
{
	integer_value=arr[i]-'0';//to convert char to int
	sum+=integer_value;
}
return sum;
}

