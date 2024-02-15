/*
 ============================================================================
 Name        : C_program_to_reverse_string.c
 Author      : Michael Maged
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
char a[100],stem;
int i,j=0;
printf("Enter the string: ");
fflush(stdin); fflush(stdout);
gets(a);
i=0;
j=strlen(a)-1;
while(i<j)
{
	stem=a[i];
	a[i]=a[j];
	a[j]=stem;
	i++;
	j--;
	}
printf("the reverse string : %s",a);
	return 0;
}
