/*
 ============================================================================
 Name        : EX4_C_Program_to_Print_the_Elements_of_an_Array_in_reverse_order.c
 Author      : Michael Maged William
 created on : 20/7/202
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[10],rev_arr[10],size;
	int *p_arr;
	int *p_rev_arr;
	p_arr=arr;
	p_rev_arr=rev_arr;
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size);
	fflush(stdin);fflush(stdout);
	printf("\nInput %d number of elements in the array :\n",size);
	for(int i=0;i<size;i++){
		printf("element-%d: \n",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<size;i++){
		p_arr++;
	}
	for(int i=0;i<size;i++){
		p_arr--;
		*p_rev_arr=*p_arr;
		p_rev_arr++;
	}
	printf("The elements of array in reverse order are : \n");
	for(int i=0;i<size;i++){
		printf("element -%d: %d\n",5-i,rev_arr[i]);
	}
	return 0;
}
