/*
 ============================================================================
 Name        : EX_1_Multi_dimensional_array.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float j[2][2],k[2][2],sum[2][2];
	printf("enter the element of 1st matrix ");
	fflush(stdin);fflush(stdout);
	for (int i=0;i<2;i++){
		for(int t=0;t<2;t++){
			printf("enter a%d%d ",1+i,1+t);
			fflush(stdin);fflush(stdout);
			scanf("%f",&j[i][t]);
		}}
	printf("enter the element of 2nd matrix ");
	fflush(stdin);fflush(stdout);
	for (int i=0;i<2;i++){
		for(int t=0;t<2;t++){
			printf("enter a%d%d ",1+i,1+t);
			fflush(stdin);fflush(stdout);
			scanf("%f",&k[i][t]);
		}}
	printf(" the sum of the matrix: ");
	fflush(stdin);fflush(stdout);
	for (int i=0;i<2;i++){
		for(int t=0;t<2;t++){
			sum[i][t]=j[i][t] + k[i][t];
		}}
	for (int i=0;i<2;i++){
		for(int t=0;t<2;t++){
			printf(" %f ",sum[i][t]);
			fflush(stdin);fflush(stdout);
		}}


	return 0;
}
