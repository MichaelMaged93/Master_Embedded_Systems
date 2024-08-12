/*
 ============================================================================
 Name        : EX2_C_Program_To_Print_a_Integer_Entered_by_a_User.c
 Author      : Michael Maged
 Version     :
 Copyright   : Your copyright notice
 Description : EX2_C_Program_To_Print_a_Integer_Entered_by_a_User in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num;

		printf("Enter a integer: ");
		scanf("%d",&num);
		printf("You entered: %d",num);

		return 0;
}
