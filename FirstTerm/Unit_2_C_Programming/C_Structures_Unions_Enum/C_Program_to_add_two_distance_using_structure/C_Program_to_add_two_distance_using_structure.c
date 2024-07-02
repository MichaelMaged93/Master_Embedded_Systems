/*
 ============================================================================
 Name        : C_Program_to_add_two_distance_using_structure.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct distance{
	int feet ;
	float inch ;
}d1,d2,sum;
int main(void) {
	printf("Enter information for 1st distance\n");
	fflush(stdin);fflush(stdout);
	printf("Enter feet : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&d1.feet);
	fflush(stdin);fflush(stdout);
	printf("Enter inch : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&d1.inch);
	fflush(stdin);fflush(stdout);
	printf("Enter information for 2nd distance\n");
	fflush(stdin);fflush(stdout);
	printf("Enter feet : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&d2.feet);
	fflush(stdin);fflush(stdout);
	printf("Enter inch : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&d2.inch);
	fflush(stdin);fflush(stdout);
sum.feet=d1.feet+d2.feet;
sum.inch=d1.inch+d2.inch;
if(sum.inch>12){
	sum.inch=sum.inch-12;
	sum.feet++;
}
printf("sum of distance %d'-%.1f\"",sum.feet,sum.inch);
	return 0;
}
