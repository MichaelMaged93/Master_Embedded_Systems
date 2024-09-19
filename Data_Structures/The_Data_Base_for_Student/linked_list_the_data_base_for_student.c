/*
 * linked_list_the_data_base_for_student.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Michael Maged
 */


#include "stdio.h"
#include "stdint.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "linked_list_the_data_base_for_student.h"
#define FFLUSH fflush(stdin);fflush(stdout)

// define global pointer to point the first student and this pointer is base of linked list
struct SStudent* gPFirstStudent=NULL;
//defination for APIs
void Fill_New_Record(struct SStudent*PNewStudent)
{ char temp_student[40];
printf("\n Enter the ID : ");
FFLUSH;
gets(temp_student);
PNewStudent->student.ID = atoi(temp_student);
printf("\n Enter the full name of student: ");
FFLUSH;
gets(PNewStudent->student.name);
FFLUSH;
printf("\n Enter the height: ");
FFLUSH;
gets(temp_student);
PNewStudent->student.height= atof(temp_student);
}
//======================================================================================================================
//Create add API
void AddStudent()
{
	struct SStudent* PNewStudent;
	struct SStudent* PLastStudent;
	//======================================================================================================

	//check the list is empty == yes
	if(gPFirstStudent==NULL)
	{
		//create new record
		PNewStudent=(struct SStudent*)malloc(sizeof(struct SStudent)); //create new structure in heap

		//assign it to gpfirst
		gPFirstStudent=PNewStudent;
	}

	//======================================================================================================
	//no empty
	else //list contains records
	{
		//navigate until reach to the last record
		PLastStudent=gPFirstStudent;//in this step meaning the pointer PLastStudent->PNextStudent is assign to next pointer
		while(PLastStudent->PNextStudent)//check the node by node to reach the last node
			PLastStudent=PLastStudent->PNextStudent;

		PNewStudent=(struct SStudent*)malloc(sizeof(struct SStudent)); //create new structure in heap
		PLastStudent->PNextStudent=PNewStudent; //to assign the PLastStudentStudent pointer is point to PNewStudent
	}
	//======================================================================================================
	//fill new record
	Fill_New_Record(PNewStudent);
	//set the next pointer (new student) = null
	PNewStudent->PNextStudent=NULL;
}
//===========================================================================================================================
int Delet_Student()
{
	struct SStudent* PSelect_Student;
	struct SStudent* PPrevious_Student=NULL;
	char temp_student[40];
	uint32_t select_id;
	printf("\n Enter Student ID to be deleted: ");
	FFLUSH;
	gets(temp_student);
	select_id=atoi(temp_student);
	//======================================================================================================
	//check the list is empty or no
	if(gPFirstStudent)
	{
		// if not empty assign gPFirstStudent(start of list) in PSelect_Student
		PSelect_Student=gPFirstStudent;
		while(PSelect_Student)//loop for all records
		{
			if(PSelect_Student->student.ID==select_id)//case1: check the PSelect_Student = id
			{
				if(PPrevious_Student)//check Is there an record before this record?
				{
					PPrevious_Student->PNextStudent=PSelect_Student->PNextStudent;
				}
				//================================================================================================
				else//no record before this record
				{
					gPFirstStudent=PSelect_Student->PNextStudent;
				}
				//after choose the true case remove select id
				free(PSelect_Student);
				return 1;
			}
			//store previous record = select student;
			PPrevious_Student=PSelect_Student;
			PSelect_Student=PSelect_Student->PNextStudent;

		}
		if(PSelect_Student==NULL)
					{
						printf("the ID is not exist");
					}
	}
	else{
		printf("\n the list is empty");
		FFLUSH;
		return 0;
	}
}
//===============================================================================================================
int View_Student()//view record by ID
{	char temp_student[40];
struct SStudent* PSelect_Student= gPFirstStudent;
uint32_t select_id;
printf("Enter the record ID: ");
FFLUSH;
gets(temp_student);
select_id=atoi(temp_student);
// if not empty assign gPFirstStudent(start of list) in PSelect_Student
if(gPFirstStudent){
	while(PSelect_Student)//loop for all records
	{
		if(PSelect_Student->student.ID==select_id)//case1: check the PSelect_Student = id
		{
			printf("\n Name: %s",PSelect_Student->student.name);
			FFLUSH;
			printf("\n height: %.3f",PSelect_Student->student.height);
			FFLUSH;
			return 0;
		}
		else
		{
			PSelect_Student=PSelect_Student->PNextStudent;
		}
	}
	printf("the ID is not exist");
}
else
	printf("the list is empty");
FFLUSH;
}
//==============================================================================================================
void View_All_Students()
{
	uint32_t counter=0;
	struct SStudent* PView_Student= gPFirstStudent;
	if(gPFirstStudent){
		while(PView_Student)
		{
			printf("\nRecord number (%d)",counter+1);
			FFLUSH;
			printf("\n ID: %d",PView_Student->student.ID);
			FFLUSH;
			printf("\n Name: %s",PView_Student->student.name);
			FFLUSH;
			printf("\n Height: %.2f",PView_Student->student.height);
			FFLUSH;
			counter++;
			PView_Student=PView_Student->PNextStudent;
		}
	}
	else
	{
		printf("the list is empty")	;
	}
}
//===============================================================================================================
void Delete_All()
{
	struct SStudent* PCurrent_Student = gPFirstStudent;
	if(gPFirstStudent==NULL)
	{
		printf("\n the list is empty \n");
	}
	else
	{
		while(PCurrent_Student)
		{
			struct SStudent* Ptemp_Student = PCurrent_Student;
			PCurrent_Student=PCurrent_Student->PNextStudent;
			free(Ptemp_Student);
		}
		gPFirstStudent=NULL;
	}
}
//===============================================================================================================
void Reverse_List()
{
	struct SStudent* PCurrent_Student = gPFirstStudent;
	struct SStudent* PPrevious_Student = NULL;
	struct SStudent* PNext_Student = NULL;

	if(gPFirstStudent){
		while(PCurrent_Student != NULL)
		{
			PNext_Student=PCurrent_Student->PNextStudent;
			PCurrent_Student->PNextStudent=PPrevious_Student;
			PPrevious_Student=PCurrent_Student;
			PCurrent_Student=PNext_Student;
		}
		gPFirstStudent=PPrevious_Student;
	}
	else
		printf("the list is empty");
}
//===============================================================================================================
void Middle_List()
{
	struct SStudent* Ptr_slow = gPFirstStudent;
	struct SStudent* Ptr_fast = gPFirstStudent;
	if(gPFirstStudent){
		while(Ptr_fast->PNextStudent)
		{
			Ptr_slow=Ptr_slow->PNextStudent;
			Ptr_fast=Ptr_fast->PNextStudent;
			if(Ptr_fast->PNextStudent==NULL)
			{
				break;
			}
			Ptr_fast=Ptr_fast->PNextStudent;
		}
		printf("\n ID: %d",Ptr_slow->student.ID);
		FFLUSH;
		printf("\n Name: %s",Ptr_slow->student.name);
		FFLUSH;
		printf("\n Height: %.2f",Ptr_slow->student.height);
		FFLUSH;
	}
	else
		printf("\n the list is empty");
}
//===================================================================================================================
void n_the_Node_from_end()
{
  struct SStudent* Ptr_ref = gPFirstStudent;
  struct SStudent* Ptr_main = gPFirstStudent;
  char temp_student[40];
  int count=0,index;
  if(gPFirstStudent)
  {
    printf("\n Enter n’the node from the end: ");
    FFLUSH;
    gets(temp_student);
    index=atoi(temp_student);
    while(count!=index)
    {
      Ptr_ref=Ptr_ref->PNextStudent;
      count++;
    }
    while(Ptr_ref)
    {
      Ptr_ref=Ptr_ref->PNextStudent;
      Ptr_main=Ptr_main->PNextStudent;
    }
    printf("\n ID: %d",Ptr_main->student.ID);
    FFLUSH;
    printf("\n Name: %s",Ptr_main->student.name);
    FFLUSH;
    printf("\n Height: %.2f",Ptr_main->student.height);
    FFLUSH;
  }
  else
    printf("\n the list is empty");
}
//===================================================================================================================
void Get_Length()
{
	struct SStudent* pCurrent_Student = gPFirstStudent ;
	int Counter = 0;
	while(pCurrent_Student)
	{
		Counter++;
		pCurrent_Student=pCurrent_Student->PNextStudent;
	}
	printf("\n Length is %d ",Counter);
}

