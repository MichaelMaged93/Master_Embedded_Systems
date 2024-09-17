/*
 * main.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Michael Maged
 */
#include "stdio.h"
int sum_digit(int n1,int n2);
int main()
{
	int n1,n2,sum=0;
	printf("Enter the start number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n1);
	fflush(stdin); fflush(stdout);
	printf("Enter the end number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n2);
	sum=sum_digit(n1,n2);
	printf("the summation = %d ",sum);
	return 0;
}
int sum_digit(int n1, int n2)
{
    if (n1 > n2) {
        return 0;
    }
    return n1 + sum_digit(n1 + 1, n2);
}
