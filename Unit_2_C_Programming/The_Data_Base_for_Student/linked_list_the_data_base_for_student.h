/*
 * linked_list_the_data_base_for_student.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Michael Maged
 */

#ifndef LINKED_LIST_THE_DATA_BASE_FOR_STUDENT_H_
#define LINKED_LIST_THE_DATA_BASE_FOR_STUDENT_H_
#include "stdint.h"
//effective data
struct Sdata{
	int ID ;
	char name[40];
	float height;
};
//linked list node
struct SStudent
{
	struct Sdata student;
	struct SStudent * PNextStudent;
};
//APIs
void AddStudent();
int Delet_Student();
int View_Student();//view record by ID
void View_All_Students();
void Delete_All();
void Reverse_List();
void Middle_List();
void n_the_Node_from_end();
void Get_Length();

#endif /* LINKED_LIST_THE_DATA_BASE_FOR_STUDENT_H_ */
