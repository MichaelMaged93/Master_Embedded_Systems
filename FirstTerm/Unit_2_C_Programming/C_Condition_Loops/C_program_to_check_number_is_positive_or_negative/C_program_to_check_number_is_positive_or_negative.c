/*
 ============================================================================
 Name        : C_program_to_check_number_is_positive_or_negative.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   float num ;
   printf("Enter number :");
   fflush(stdin); fflush(stdout);
   scanf("%f",&num);

   if (num>=1)
	   printf("the number %f is positive ",num);
   else if (num<0)
	   printf("the number %f is negative ",num);
   else
	   printf("the number entered is zero ");
	return 0;
}
