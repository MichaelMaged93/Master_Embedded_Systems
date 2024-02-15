/*
 ============================================================================
 Name        : C_program_to_find_the_frequency_of_characters_in_strings.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char c[100] , ch ;
	int i ,count=0 ;
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(c);
	printf("Enter the character to find frequency: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&ch);
	for(i=0;c[i]!='\0';i++){
		if(c[i]==ch){
			count++;
		}
	}

	if(count!=0){
		printf("frequency of %c = %d ",ch,count);
	}
	else
		printf("the character is not found");
	return 0;
}
