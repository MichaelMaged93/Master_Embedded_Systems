/*
 ============================================================================
 Name        : C_program_to_search_an_element_in_array.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[10],num_element,num_searched,find_num=0,i;
	printf("Enter the no element: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num_element);
	for( i=0;i<num_element;i++){
		scanf("%d",&arr[i]);
	}
	for( i=0;i<num_element;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	// done
	printf("Enter the elements to be searched: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num_searched);

	for(i=0;i<num_element;i++){
		if(arr[i]==num_searched){
			printf("number found at the location = %d \n",i+1);
			find_num=1;
		}
	}
	if(find_num!=1){
		printf("the number not found ");
	}
	return 0;
}
