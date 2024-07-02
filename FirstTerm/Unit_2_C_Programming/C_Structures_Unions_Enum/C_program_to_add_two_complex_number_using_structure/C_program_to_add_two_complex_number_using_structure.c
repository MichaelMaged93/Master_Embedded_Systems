/*
 ============================================================================
 Name        : C_program_to_add_two_complex_number_using_structure.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct Scomplex{
	float realnum;
	float imgnum;
}num1,num2;
struct Scomplex add(struct Scomplex x,struct Scomplex y){
	struct Scomplex z;
	z.realnum=x.realnum+y.realnum;
	z.imgnum=x.imgnum+y.imgnum;
	return z;
}
int main(void) {
	struct Scomplex result;
	printf("for 1st complex number\n");
	fflush(stdin);fflush(stdout);
	printf("Enter the real and imaginary respectively : ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&num1.realnum,&num1.imgnum);
	fflush(stdin);fflush(stdout);
	printf("\nfor 2st complex number\n");
	fflush(stdin);fflush(stdout);
	printf("Enter the real and imaginary respectively : ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&num2.realnum,&num2.imgnum);
	result=add(num1,num2);
	printf("\nsum=%.1f+%.1fi",result.realnum,result.imgnum);
	return 0;
}
