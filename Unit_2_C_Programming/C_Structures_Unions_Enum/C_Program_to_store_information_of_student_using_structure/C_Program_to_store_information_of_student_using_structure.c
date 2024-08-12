/*
 ============================================================================
 Name        : C_Program_to_store_information_of_student_using_structure.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct Sinformation{
	char name[100];
	int roll;
	float marks;
};

int main(void) {
	struct Sinformation info;
	printf("Enter name:  ");
	fflush(stdin);fflush(stdout);
	scanf("%s",info.name);
	fflush(stdin);fflush(stdout);
	printf("Enter roll number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&info.roll);
	fflush(stdin);fflush(stdout);
	printf("Enter marks: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&info.marks);
	fflush(stdin);fflush(stdout);
	printf("displaying information\n");
	printf("name:%s\nROLL:%d\nmarks:%.2f",info.name,info.roll,info.marks);

	return 0;
}
