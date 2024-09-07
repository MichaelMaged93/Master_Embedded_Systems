/*
 * main.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Michael Maged
 */
#include "stdio.h"
void calc_number_of_ones(int n1);
int main()
{
	int num;
	printf("Enter the number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	calc_number_of_ones(num);
	return 0;
}
void calc_number_of_ones(int n1)
{int sum=0,i,number;
number=n1;//to store first number before change to print it
int arr[32]={0};//to set zeros in bits
for(i=0;n1>0;i++)
{
	if(n1%2!=0)
	{
		n1=n1/2;
		sum+=1;
		arr[i]=1;
	}
	else
	{
		n1=n1/2;
		arr[i]=0;
	}
}
printf("binary of %d is ",number);
for(int j = i-1;j>=0;j--)
{
	printf("%d", arr[j]);
}
printf(" so has %d ones",sum);
}

