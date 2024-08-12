/*
 ============================================================================
 Name        : EX3_C_Program_to_Reverse_a_Sentence_Using_Recursion.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void reverse_arr(char arr[100],int n,int i);
int main(void) {
char arr[100];
int n,i=0;
printf("Enter the sentence : ");
fflush(stdin); fflush(stdout);
gets(arr);
n=strlen(arr)-1;
reverse_arr(arr,n,i);
printf("%s",arr);
	return 0;
}
void reverse_arr(char arr[100],int n,int i){
	char stem ;
	if(n>=0 && i<n){
	stem = arr[i];
	arr[i]=arr[n];
	arr[n]=stem;
	reverse_arr(arr,n-1,i+1);
	}
}

