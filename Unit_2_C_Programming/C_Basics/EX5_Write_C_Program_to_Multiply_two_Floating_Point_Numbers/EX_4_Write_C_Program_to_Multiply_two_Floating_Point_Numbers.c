/*
 ============================================================================
 Name        : EX_4_Write_C_Program_to_Multiply_two_Floating_Point_Numbers.c
 Author      : Michael Maged
 Description :Write C Program to Multiply two Floating Point Numbers Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main(void) {
	float num1,num2,multi;
	printf("Enter two numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&num1,&num2);
	multi= num1 * num2 ;
	printf("Product:  %f", multi);
	return 0;
}
