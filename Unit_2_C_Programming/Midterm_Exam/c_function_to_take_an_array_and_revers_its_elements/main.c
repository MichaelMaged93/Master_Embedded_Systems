/*
 * main.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Michael Maged
 */


#include "stdio.h"
void rev_array(int arr[],int size);
int main()
{
	int arr[5]={1,2,3,4,5};
	rev_array(arr,5);
	for(int i =0; i<5;i++)
		printf(" %d ",arr[i]);
	return 0;
}
void rev_array(int arr[],int size)
{
	int swap=0;
	int length=size-1;
	for(int i=0; i<=length/2;i++)
	{
		swap=arr[i];
		arr[i]=arr[length-i];
		arr[length-i]=swap;
	}
}

