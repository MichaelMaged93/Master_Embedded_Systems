/*
 ============================================================================
 Name        : EX2_C_Program_to_Print_All_Alphabets_Using_a_pointer.c
 Author      : Michael Maged William
 created on  : 20/7/2024
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char alphabet[26];
	char *ptr;
	ptr=alphabet;
	*ptr='A';
	for(int i=0;i<26;i++){
		*ptr='A'+i;
		ptr++;
	}
	ptr=alphabet;
	printf("The Alphabets are :\n");
	for(int i=0; i<26;i++){
		printf(" %c ",*ptr);
		ptr++;
	}
	return 0;
}
