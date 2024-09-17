/*
 * main.c
 *
 *  Created on: Sep 6, 2024
 *      Author: Michael Maged
 */
#include "stdio.h"
float fun_square_root(int num);
int main()
{
	int number;
	float result;
	printf("Enter the number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&number);
	if(number>0)
	{
		result=fun_square_root(number);
		printf("the square root = %.2f",result);
	}
	else if(number=0)
	{
		result=0;
		printf("the square root = %.2f",result);
	}
	else
		printf("sorry the number is negative");

	return 0;
}
float fun_square_root(int num)
{
	float accuracy=0.0001;//to accuray the number
	float root_old=num/2.0;//the first iteration
	float root_new;//the update of iteration
	float difference_iteration=0;
	//using newton raphson method to get the square root
	root_new = (root_old+(num/root_old))/2.0;
	difference_iteration = root_new-root_old;//to store diff between to iterations
	if(difference_iteration<0)
	{
		difference_iteration=-difference_iteration;
	}
	for(int i =0;difference_iteration>accuracy;i++)
	{
		root_new = (root_old+(num/root_old))/2.0;
		difference_iteration = root_new-root_old;//to store diff between to iterations
		if(difference_iteration<0)
		{
			difference_iteration=-difference_iteration;
		}
		root_old=root_new;
	}
	return root_old;
}

