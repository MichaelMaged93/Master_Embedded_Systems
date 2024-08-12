/*
 ============================================================================
 Name        : EX1_Prime_Numbers_between_two_Intervals_by_Making_User_Defiend_Function.c
 Author      : Michael Maged
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int prime_num(int x);
int main(void) {
	int n1 , n2, flag ;
	printf("Enter two numbers(intervals):");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&n1,&n2);
	fflush(stdin);fflush(stdout);
	printf("prime number between %d and %d are : ",n1,n2);
	for(int i = n1+1;i<n2;i++){
		flag=prime_num(i);
		if(flag==0){
			printf(" %d ",i);
		}
	}
	return 0;
}
int prime_num(int x){
	int j , flag=0;
	for(j=2;j<=x/2;j++){
		if(x%j==0){
			flag=1;
			break;
		}
	}
	return flag;
}
