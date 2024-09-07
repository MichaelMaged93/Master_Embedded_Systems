/*
 * main.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Michael Maged
 */
#include "stdio.h"
#include "string.h"

int unique_number(int arr[],int size);


int main()
{int res;
int arr[7]={1,8,1,2,8,1,1};
res=unique_number(arr,7);
printf("the output: %d",res);

return 0;
}
int unique_number(int arr[],int size)
{
	int res=0;
	for(int i=0;i<size;i++)
	{
		res ^= arr[i];
	}
	return res;
}

