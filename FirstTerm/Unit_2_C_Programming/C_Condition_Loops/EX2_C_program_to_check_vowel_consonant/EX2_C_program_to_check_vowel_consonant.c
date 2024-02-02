/*
 ============================================================================
 Name        : test.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char a,b ;
		again:
		printf("Enter an alphabet : ");
		fflush(stdin); fflush(stdout);
		scanf("%c",&a);
		if (a>=97 && a<=122){
			printf(" %c is vowel " , a);
		}
		else if (a>=65 && a<=90){
			printf (" %c is consonant " ,a );
		}
		else
			printf ("enter alphabet ");

		printf ("enter y if need again ");
		fflush(stdin); fflush(stdout);
		scanf("%c",&b);
		if( b == 'y'){
			goto  again;
		}	return 0;
}