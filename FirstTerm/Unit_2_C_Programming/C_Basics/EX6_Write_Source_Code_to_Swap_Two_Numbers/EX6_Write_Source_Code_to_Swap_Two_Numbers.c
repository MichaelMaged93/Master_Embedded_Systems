/*
 ============================================================================
 Name        : EX6_Write_Source_Code_to_Swap_Two_Numbers.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
float a,b,swap;
printf("Enter value of a: ");
fflush(stdin); fflush(stdout);
scanf("%f",&a);
fflush(stdin); fflush(stdout);
printf("Enter value of b: ");
fflush(stdin); fflush(stdout);
scanf("%f",&b);
swap=a;
a=b;
b=swap;
printf("After swapping, value of a = %f\n",a);
printf("After swapping, value of b = %f",b);
	return 0;
}
