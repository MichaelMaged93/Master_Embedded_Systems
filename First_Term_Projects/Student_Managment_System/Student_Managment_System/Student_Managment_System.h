/*
 * Student_Managment_System.h
 *
 *  Created on: Sep 18, 2024
 *      Author: Michael Maged
 */

#ifndef STUDENT_MANAGMENT_SYSTEM_H_
#define STUDENT_MANAGMENT_SYSTEM_H_
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#define Dprintf(...) {fflush(stdin);fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);fflush(stdout);}

#define Dscanf(val,...) {fflush(stdin);fflush(stdout);\
		scanf(__VA_ARGS__,val);\
		fflush(stdin);fflush(stdout);}
// Defination of struct contains student information
/* student information will be 1- first name
 *                             2- last name
 *                             3- unique roll number (ID)
 *                             4- courses ID
 *                             5- GPA
 */
typedef struct
{
	char First_name[10];
	char last_name[10];
	int ID;
	int Course[5];
	float GPA;
}Sdata_t;
//FIFO data types
typedef struct {
	uint32_t length; //the size of buffer
	uint32_t counter;//to increment the number of value it assign in buffer
	Sdata_t* head ;//to increment the location in buffer to assign the next value
	Sdata_t* base ;//the statrt address of buffer
	Sdata_t* tail ;//to pop value and empty location
}FIFO_buf_t;

//create enum to return the status of buffer
typedef enum{
	FIFO_no_error,//0
	FIFO_full,//1
	FIFO_empty,//2
	FIFO_null,//3
	FIFO_error//4
}FIFO_buf_status;

// Prototypes of system API's

// API to initialize items to our FIFO : we will recive the FIFO, the array which will store in , and the lenth
void FIFO_Init_Items( FIFO_buf_t* fifo_buf , Sdata_t* buf , int length );

// API to add students info from file to our FIFO : we will recive the FIFO
void Add_Student_From_File( FIFO_buf_t* fifo_buf);

//API to store the data in fifo
FIFO_buf_status FIFO_Enqueue(FIFO_buf_t* fifo , Sdata_t item);

// API to add student info manually to our FIFO : we will recive the FIFO
void Add_Student_Manually( FIFO_buf_t* fifo_buf );

// API to search and find the student information by roll number
void Find_Student_By_ID( FIFO_buf_t* fifo_buf );

// API to search and find the student information by first name
void Find_Student_By_First_Name( FIFO_buf_t* fifo_buf );

//API to find the number of student inrolled in course using course ID
void Find_NO_Of_Student_IN_Course(FIFO_buf_t* fifo_buf );

// API to count the total number of student
void Find_Total_Number( FIFO_buf_t* fifo_buf );

// API to delete student information from the system
void Delete_Student( FIFO_buf_t* fifo_buf );

// API to update student information in the system the system
void Update_Student_Info( FIFO_buf_t* fifo_buf );

// API to show all students infomation in the system
void Show_Student( FIFO_buf_t* fifo_buf );

// API to check if FIFO is full
FIFO_buf_status FIFO_IS_FULL( FIFO_buf_t *fifo_buf );

// API to check if FIFO is empty
FIFO_buf_status FIFO_EMPTY( FIFO_buf_t* fifo_buf );

// API to check if ID is Repeated or no
FIFO_buf_status Check_ID(FIFO_buf_t* fifo_buf,Sdata_t item);
#endif /* STUDENT_MANAGMENT_SYSTEM_H_ */
