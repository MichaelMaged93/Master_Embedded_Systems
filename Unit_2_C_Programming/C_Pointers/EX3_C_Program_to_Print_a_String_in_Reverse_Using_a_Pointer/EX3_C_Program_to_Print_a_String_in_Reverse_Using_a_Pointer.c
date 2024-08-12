/*
 ============================================================================
 Name        : EX3_C_Program_to_Print_a_String_in_Reverse_Using_a_Pointer.c
 Author      : Michael Maged William
 created on  : 20/7/202
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *rev_ptr;
	char *ptr;
	char alphabet[20]="michael";
	char rev_alphabet[20];
	ptr=alphabet;
	rev_ptr=rev_alphabet;
	printf("Input a string : ");
	fflush(stdin);fflush(stdout);
	gets(alphabet);
	int i=-1;
	for(i;*ptr;i++){
		ptr++;
	}
	for(i;i>=0;i--){
		ptr--;
		*rev_ptr=*ptr;
		rev_ptr++;
	}
	*rev_ptr='\0';
	printf("Pointer : Print a string in reverse order :\n");
	printf("------------------------------------------------\n");
	printf("Input a string : %s\n",alphabet);
	printf("Reverse of the string is : %s",rev_alphabet);

	return 0;
}
