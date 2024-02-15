/*
 ============================================================================
 Name        : C_program_to_insert_an__element_in_an_array.c
 Author      : Michael Maged
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[33],num_element,location,i,number;
	printf("Enter no of elements : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num_element);
	for(int i=0;i<num_element;i++){
		arr[i]=i+1;
	}
	for(i=0;i<num_element;i++){
		printf(" %d ",arr[i]);
	}
	// done
	printf("\nEnter the element to be inserted: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&number);
	fflush(stdin); fflush(stdout);
	printf("Enter the location: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&location);

	for(i=num_element-1;i>=location;i--){
		if(i+1==num_element){
			arr[i+1]=num_element;
		}
		arr[i]=arr[i-1];
	}
	arr[location-1]=number;
	for(i=0;i<=num_element;i++){
		printf(" %d ",arr[i]);
	}
	return 0;
}
