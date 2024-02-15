/*
 ============================================================================
 Name        : C_program_to_find_transpose_of_array.c
 Author      : Michael Maged
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a[10][10],b[10][10];
	int n,k;

	printf("Enter the number of rows and column : ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&n,&k);
	printf("Enter the element of matrix \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			printf("Enter the element of a%d%d",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}
	for(int i=0 ; i<n;i++ ){
		for(int j=0 ; j<k;j++){
			b[j][i]=a[i][j];
		}
	}
	printf("entered matrix: \n");
	for(int i=0 ; i<n;i++ ){
		for(int j=0 ; j<k;j++){
			printf(" %f ",a[i][j]);
			if(j==n-1){
				printf("\n");
			}
		}
	}
	printf("transpose matrix: \n");
	for(int i=0 ; i<n;i++ ){
		for(int j=0 ; j<k;j++){
			printf(" %f ",b[i][j]);
			if(j==n-1){
				printf("\n");
			}
		}
	}
	return 0;
}
