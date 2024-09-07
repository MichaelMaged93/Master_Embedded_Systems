/*
 * main.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Michael Maged
 */
#include "stdio.h"
int max_num_of_ones(int n1);
int main()
{
	int num,sum;
	printf("enter the number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	printf("binary of %d is ",num);
	sum=max_num_of_ones(num);
	printf(" so has %d max ones between two zeros",sum);
	return 0;

}
int max_num_of_ones(int n1)
{
	int arr[32]={0},sum=0;
	int start ;//to reserved zeros
	for(int i=0;n1>0;i++)
	{
		if(n1%2!=0)
		{
			n1=n1/2;
			arr[i]=1;
		}
		else
		{
			n1=n1/2;
			arr[i]=0;
		}
	}
	for(int i = 0; i < 31; i++)
	{
	    if(arr[i] == 0 && arr[i+1] == 1)
	    {
	        int count = 0;
	        for(int j = i + 1; j < 32; j++)
	        {
	            if(arr[j] == 1)
	            {
	                count++;
	            }
	            else
	                break;
	        }
	        if(count > sum)
	        {
	            sum = count;
	        }
	    }
	}
	for(int i = 31; i >= 0; i--)
	{
		if(arr[i] == 1)
		{
			start = i;
			break;
		}
	}
	for(int i = start; i >= 0; i--)
	{
		printf("%d", arr[i]);
	}
return sum;
}
