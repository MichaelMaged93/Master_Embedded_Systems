/*
 ============================================================================
 Name        : C_program_to_find_length_of_string.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char c[100];
	int i,count=0;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(c);
	for(i=0;c[i]!='\0';i++){
		count++;
	}
	printf("the length of string= %d ",count);
	return 0;
}
