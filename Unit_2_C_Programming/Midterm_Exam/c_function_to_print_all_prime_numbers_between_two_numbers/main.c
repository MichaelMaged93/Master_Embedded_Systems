/*
 * main.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Michael Maged
 */
#include "stdio.h"
void print_prime_num(int n1,int n2);
int main()
{
	int num1,num2;
	printf("Enter first number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num1);
	fflush(stdin); fflush(stdout);
	printf("Enter second number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num2);
	if (num1 == num2)
	{
		printf("Error! The two numbers are equal. Please try again.\n");
	}
	else
	{
		print_prime_num(num1, num2);
	}
	return 0;
}

void print_prime_num(int n1,int n2)
{
	int prime_number;//to check the number if prime print
	for(int i=n1;i<=n2;i++)
	{
		prime_number=1;//assume the first number is prime
		if(i>=2)
		{
			for(int j=2;j<i;j++)
			{
				if(i%j == 0)
				{
					prime_number=0;
					break;
				}
			}
			if(prime_number)
			{
				printf("->output: %d\n", i);
			}
		}
	}
}
