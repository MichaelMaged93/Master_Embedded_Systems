/*
 ============================================================================
 Name        : EX4_Write_C_Program_to_Find_ASCII_Value_of_a_Character.c
 Author      : Michael Maged
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char x;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&x);
	printf("ASCII value of %c = %d ",x,x);

	return EXIT_SUCCESS;
}
