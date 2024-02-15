/*
 ============================================================================
 Name        : EX_2_C_PROGRAM_to_calculate_avarege_using_array.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float arr[100],sum=0;
	int n;
	printf("Enter the number of data : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		printf("Enter Number : ");
		fflush(stdin);fflush(stdout);
		scanf("%f",&arr[i]);
		sum+=arr[i];

	}
	printf("average : %f ",sum/i);

	return 0;
}
