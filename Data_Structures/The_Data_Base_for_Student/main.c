/*
 * main.c
 *
 *  Created on: Aug 16, 2024
 *      Author: Michael Maged
 */

//include all library it will be used
#include "stdio.h"
#include "stdint.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "linked_list_the_data_base_for_student.h"
#define FFLUSH fflush(stdin);fflush(stdout)

void main()
{
	char temp_text[40];
	int x=1;
	while(x){
		printf("\n<===========================================================================>");
		FFLUSH;
		printf("\n.............choose on the following Options............. \n");
		FFLUSH;
		printf("\n 1: Add_Student  ");
		FFLUSH;
		printf("\n 2: Delete_Student   ");
		FFLUSH;
		printf("\n 3: Delete_All_Students   ");
		FFLUSH;
		printf("\n 4: View_Student_with_ID   ");
		FFLUSH;
		printf("\n 5: View_All_Student   ");
		FFLUSH;
		printf("\n 6: Reverse_List ");
		FFLUSH;
		printf("\n 7: Middle_List ");
		FFLUSH;
		printf("\n 8: n’th Node from the end ");
		FFLUSH;
		printf("\n 9: Get_Length_the_list ");
		FFLUSH;
		printf("\n 10: EXit from program\n  (:)=> ");
		FFLUSH;
		gets(temp_text);
		FFLUSH;
		printf("************************wait******************************\n");
		FFLUSH;
		switch(atoi(temp_text))
		{
		case 1:
			AddStudent();
			break;
		case 2:
			Delet_Student();
			break;
		case 3:
			Delete_All();
			break;
		case 4:
			View_Student();
			break;
		case 5:
			View_All_Students();
			break;
		case 6:
			Reverse_List();
			break;
		case 7:
			Middle_List();
			break;
		case 8:
			n_the_Node_from_end();
			break;
		case 9:
			Get_Length();
			break;
		case 10:
			x=0;
			printf(" => DONE <= ");
			break;
		default:
			printf("Wrong Option");
			break;
		}
	}

}
