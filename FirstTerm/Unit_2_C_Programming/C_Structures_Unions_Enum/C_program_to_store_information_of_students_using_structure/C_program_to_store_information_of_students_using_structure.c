/*
 ============================================================================
 Name        : C_program_to_store_information_of_students_using_structure.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
struct Sdata{
	char name[50];
	int marks;
}student[10];
int main(void) {
	printf("Enter information of students\n");
	for(int i=0;i<10;i++){
		printf("For roll number %d \n",i+1);
		fflush(stdin);fflush(stdout);
		printf("Enter name: ");
		fflush(stdin);fflush(stdout);
		scanf("%s",&student[i].name);
		fflush(stdin);fflush(stdout);
		printf("Enter marks: ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&student[i].marks);
	}
	printf("\nDisplaying information of student\n");
	for(int i=0;i<10;i++){
		printf("information of roll number %d\n",i+1);
		fflush(stdin);fflush(stdout);
		printf("Name: %s\n",student[i].name);
		fflush(stdin);fflush(stdout);
		printf("Marks: %d\n",student[i].marks);
	}
	return 0;
}
