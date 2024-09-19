/*
 * Student_Managment_System.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Michael Maged
 */
#include "Student_Managment_System.h"
#include "stdio.h"
#include "string.h"
//defination the APIs
FIFO_buf_status FIFO_init(FIFO_buf_t* fifo , Sdata_t* buf, uint32_t length)
{
	//to check the FIFO is existed or no
	if(buf==NULL)
		return FIFO_null;
	//to intialize the FIFO
	fifo->base=buf;
	fifo->head=buf;
	fifo->tail=buf;
	fifo->length=length;
	fifo->counter=0;
	return FIFO_no_error;
}
/*==================================================================================================*/

void Add_Student_From_File( FIFO_buf_t* fifo_buf)
{
	int i =0;//to count number of student is stored
	FIFO_buf_status check;//to check the state of fifo
	if( FIFO_IS_FULL(fifo_buf)==FIFO_full)
	{
		printf("[ERORR] FIFO is FULL \n");
		return ;
	}
	else if(FIFO_IS_FULL(fifo_buf)==FIFO_null)
	{
		printf("[ERORR] FIFO is NOT Exist \n");
		return ;
	}
	else
	{
		Sdata_t S_temp;//to store data and send it to the enqueue to store in head
		int result=0;//to check the information is complete for each student
		FILE *P_file;	//define the pointer from type file to read data from file

		P_file = fopen("Student_Data.txt","r");
		// Check if file is not opening

		if(P_file==NULL)
		{
			printf("Error! in opening file. \n");
			return ;
		}
		// Check if file is empty
		if (fscanf(P_file,"%d",&S_temp.ID)!=1)//this function is return non_zero if the file is empty "must be Try reading at least one"
		{
			if(feof(P_file)){
				printf("The file is empty.\n");
				fclose(P_file);
				return;
			}
		}

		while((result=fscanf(P_file,"%s %s %d %f %d %d %d %d %d",
				S_temp.First_name,
				S_temp.last_name,
				&S_temp.ID,
				&S_temp.GPA,
				&S_temp.Course[0],
				&S_temp.Course[1],
				&S_temp.Course[2],
				&S_temp.Course[3],
				&S_temp.Course[4]))==9)
		{
			++i;
			check=FIFO_Enqueue(fifo_buf, S_temp);
			if(check==FIFO_no_error)
			{
				printf("Student[%d] Details is added Successfully.\n",i);
			}
			else if(check==FIFO_full)//if between store the list is full before the data of all file is stored
			{
				printf("[Error] the list is Full\n");
				return ;
			}
		}
		if (result != EOF) {
			printf("Warning: Incomplete data found for a student.\n");
			return ;
		}
		fclose(P_file);
	}

	Find_Total_Number(fifo_buf);

}
/*==================================================================================================*/
void Add_Student_Manually( FIFO_buf_t* fifo_buf )
{
	FIFO_buf_status check_M;//to check the state of fifo
	Sdata_t S_Student;

	Dprintf("\nEnter the Roll Number: ");
	scanf("%d",&S_Student.ID);
	Dprintf("\nEnter the First Name: ");
	scanf("%s",S_Student.First_name);
	Dprintf("\nEnter the Last Name: ");
	scanf("%s",S_Student.last_name);
	Dprintf("\nEnter the GPA: ");
	scanf("%f",&S_Student.GPA);
	for(int i=0; i<5;i++)
	{
		Dprintf("\nCourse %d id: ",i+1);
		scanf("%d",&S_Student.Course[i]);
	}
	check_M=FIFO_Enqueue(fifo_buf, S_Student);
	if(check_M==FIFO_no_error)
	{
		printf("Student Details is added Successfully. \n");
	}
	else if(check_M==FIFO_full)//if between store the list is full before the data of all file is stored
	{
		printf("[Error] the list is Full\n");
		return ;
	}

	Find_Total_Number(fifo_buf);
}

/*==================================================================================================*/
void Find_Student_By_ID( FIFO_buf_t* fifo_buf )
{   int ID;
Sdata_t* check_Student = fifo_buf->tail;
Dprintf("\nEnter the Roll Number of the Student: ");
scanf("%d",&ID);
for (int i = 0; i < fifo_buf->counter; ++i)
{
	if (check_Student->ID == ID)
	{
		Dprintf("\nThe First Name: %s",check_Student->First_name);
		Dprintf("\nThe Last Name: %s",check_Student->last_name);
		Dprintf("\nThe GPA: %.2f",check_Student->GPA);
		Dprintf("\nThe Course ID are: %d",check_Student->Course[0]);
		Dprintf("\nThe Course ID are: %d",check_Student->Course[1]);
		Dprintf("\nThe Course ID are: %d",check_Student->Course[2]);
		Dprintf("\nThe Course ID are: %d",check_Student->Course[3]);
		Dprintf("\nThe Course ID are: %d",check_Student->Course[4]);
		return ;
	}
	check_Student = (check_Student + 1); // move to next element
	if (check_Student == (fifo_buf->base + fifo_buf->length * sizeof(Sdata_t)))
		check_Student = fifo_buf->base; //if fifo is reach to top fifo
}

Dprintf("[Error] Roll Number %d not found \n",ID);
}
/*==================================================================================================*/
void Find_Student_By_First_Name( FIFO_buf_t* fifo_buf )
{
	int found_student=0;//If the student finds it, he will let the program not print "[Error] the First Name not found"
	char check_name[10];
	Sdata_t* check_Student = fifo_buf->tail;
	Dprintf("\nEnter the First Number of the Student: ");
	scanf("%s",check_name);
	for (int i = 0; i < fifo_buf->counter; ++i)
	{
		if (stricmp(check_Student->First_name,check_name)==0)//using stricmp Because it is possible to enter the first name small letter
		{
			Dprintf("\nThe ID: %d",check_Student->ID);
			Dprintf("\nThe First Name: %s",check_Student->First_name);
			Dprintf("\nThe Last Name: %s",check_Student->last_name);
			Dprintf("\nThe GPA: %.2f",check_Student->GPA);
			Dprintf("\nThe Course ID are: %d",check_Student->Course[0]);
			Dprintf("\nThe Course ID are: %d",check_Student->Course[1]);
			Dprintf("\nThe Course ID are: %d",check_Student->Course[2]);
			Dprintf("\nThe Course ID are: %d",check_Student->Course[3]);
			Dprintf("\nThe Course ID are: %d",check_Student->Course[4]);
			Dprintf("\n====================================================");
			found_student=1;
		}
		check_Student = (check_Student + 1); // move to next element
		if (check_Student == (fifo_buf->base + fifo_buf->length * sizeof(Sdata_t)))
			check_Student = fifo_buf->base; //if fifo is reach to top fifo
	}
	//if student not found
	if(found_student==0)
	{
		Dprintf("[Error] the First Name: %s not found \n",check_name);
	}
}
/*==================================================================================================*/
void Find_NO_Of_Student_IN_Course(FIFO_buf_t* fifo_buf )
{
	Sdata_t* check_no_Student = fifo_buf->tail;
	int check_course_id=0;
	int number_students=0;
	Dprintf("\nEnter the Course ID: ");
	scanf("%d",&check_course_id);
	for(int i=0; i<fifo_buf->counter;i++)
	{
		for(int j=0;j<5;j++)
		{
			if ( check_course_id == check_no_Student->Course[j] )
			{
				Dprintf("\nThe Student Details are: ");
				Dprintf("\nThe First Name: %s",check_no_Student->First_name);
				Dprintf("\nThe Last Name: %s",check_no_Student->last_name);
				Dprintf("\nThe Roll Number is %d",check_no_Student->ID);
				Dprintf("\nThe GPA: %.2f",check_no_Student->GPA);
				Dprintf("\n====================================================");
				number_students+=1;
			}
		}
		check_no_Student = (check_no_Student + 1); // move to next element
		if (check_no_Student == (fifo_buf->base + fifo_buf->length * sizeof(Sdata_t)))
			check_no_Student = fifo_buf->base; //if fifo is reach to top fifo
	}
	Dprintf("\nTotal Number of Student Enrolled: %d",number_students);
}
/*==================================================================================================*/
void Find_Total_Number( FIFO_buf_t* fifo_buf )
{

	Dprintf("\n******************************************\n");
	Dprintf("[INFO] The total number of student is %d\n",fifo_buf->counter);
	Dprintf("[INFO] You can add up to %d students\n",50);
	Dprintf("[INFO] You can add %d more students\n",50-(fifo_buf->counter));

}
/*==================================================================================================*/
void Delete_Student( FIFO_buf_t* fifo_buf )
{
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
	{
		Dprintf("[Error]!The list is not exist");
		return;
	}
	//check FIFO is empty ?
	if(fifo_buf->counter==0)
	{
		Dprintf("[Error]!The list is empty");
		return;
	}

	Sdata_t* current_student = fifo_buf->tail;
	int delete_student_id;
	Dprintf("\nEnter the Roll Number which you want to delete: ");
	scanf("%d", &delete_student_id);

	int found = 0; // to track if student is found
	for (int i = 0; i < fifo_buf->counter; ++i)
	{
		if (current_student->ID == delete_student_id)
		{
			found = 1;
			break;
		}
		current_student++;
		if (current_student == (fifo_buf->base + fifo_buf->length * sizeof(Sdata_t)))
		{
			current_student = fifo_buf->base; // Circular FIFO
		}
	}

	if (!found)
	{
		Dprintf("[Error] Roll Number %d not found\n", delete_student_id);
		return;
	}

	// Shift all elements after the deleted one
	Sdata_t* next_student = current_student + 1;
	if (next_student == (fifo_buf->base + fifo_buf->length))
	{
		next_student = fifo_buf->base; // Circular FIFO
	}

	//to rearrange the list of student after delete id
	while (next_student != fifo_buf->head)
	{
		*current_student = *next_student; // shift the student
		current_student = next_student;//update adress of current_student to point the next element
		next_student++; //move to next element
		if (next_student == (fifo_buf->base + fifo_buf->length * sizeof(Sdata_t)))
		{
			next_student = fifo_buf->base; // Circular FIFO
		}
	}

	// Adjust head and counter
	if (fifo_buf->head == fifo_buf->base)
	{
		fifo_buf->head = fifo_buf->base + fifo_buf->length-1 ;
	}
	else
	{
		fifo_buf->head--;
	}

	fifo_buf->counter--;
	Dprintf("The Roll number is deleted successfully.\n");
	Find_Total_Number(fifo_buf);
}
/*==================================================================================================*/
void Update_Student_Info( FIFO_buf_t* fifo_buf )
{
	int ID;
	int choice;//to choice the task is will update
	int updated=0;//to check is update or no
	Sdata_t* check_Student = fifo_buf->tail;
	Dprintf("\nEnter the Roll Number to Update the Entry: ");
	scanf("%d",&ID);
	for (int i = 0; i < fifo_buf->counter; ++i)
	{
		if (check_Student->ID == ID)
		{
			int RESULT;//to store state of check
			Sdata_t temp_ID;//to store ID before check
			Dprintf("\n1. First Name.");
			Dprintf("\n2. Second Name.");
			Dprintf("\n3. roll no.");
			Dprintf("\n4. GPA.");
			Dprintf("\n5. Course.");
			Dprintf("\nEnter the task to update: ");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				Dprintf("\nEnter the First Name: ");
				scanf("%s",check_Student->First_name);
				break;
			case 2:
				Dprintf("\nEnter the Last Name: ");
				scanf("%s",check_Student->last_name);
				break;
			case 3:
				Dprintf("\nEnter the Roll Number: ");
				scanf("%d",&temp_ID.ID);
				RESULT=Check_ID(fifo_buf,temp_ID);//to check the update id is not repeated
				if(RESULT==FIFO_no_error)
					check_Student->ID=temp_ID.ID;
				break;
			case 4:
				Dprintf("\nEnter the GPA: ");
				scanf("%f",&check_Student->GPA);
				break;
			case 5:
				for(int j=0; j<5;j++)
				{
					Dprintf("\nCourse %d id: ",j+1);
					scanf("%d",&check_Student->Course[j]);
				}
				break;
			default:
				Dprintf("\n*******************************************\n");
				Dprintf("\n You Entered a Wrong Option \n");
				Dprintf("\n*******************************************\n");
				break;
			}
			updated=1;
		}
		check_Student++; // move to next element
		if (check_Student == (fifo_buf->base + fifo_buf->length * sizeof(Sdata_t)))
			check_Student = fifo_buf->base; //if fifo is reach to top fifo
	}
	if(updated!=1)
	{
		Dprintf("[Error] Roll Number %d not found \n",ID);
	}
	Find_Total_Number(fifo_buf);
}
/*==================================================================================================*/
void Show_Student( FIFO_buf_t* fifo_buf )
{
	Sdata_t* Show_student = fifo_buf->tail;

	if(FIFO_EMPTY(fifo_buf) == FIFO_empty)
	{
		Dprintf("[ERORR] The FIFO is empty \n");
		return;
	}
	// looping untill show all students
	for(int counter = 0 ; counter < fifo_buf->counter ; counter++)
	{
		Dprintf("\n*******************************************\n");
		Dprintf("Student first name %s\n",Show_student->First_name);
		Dprintf("Student last name %s\n",Show_student->last_name);
		Dprintf("Student roll number %d\n",Show_student->ID);
		Dprintf("Student GPA %0.2f\n",Show_student->GPA);
		Dprintf("The course ID are %d\n",Show_student->Course[0]);
		Dprintf("The course ID are %d\n",Show_student->Course[1]);
		Dprintf("The course ID are %d\n",Show_student->Course[2]);
		Dprintf("The course ID are %d\n",Show_student->Course[3]);
		Dprintf("The course ID are %d\n",Show_student->Course[4]);
		Show_student++;
	}
	Dprintf("\n*******************************************\n");
	Find_Total_Number(fifo_buf);
}
/*==================================================================================================*/
FIFO_buf_status FIFO_Enqueue(FIFO_buf_t* fifo , Sdata_t item)
{
	FIFO_buf_status check_student_id;
	//to check the FIFO is not null and check the base , tail , head is existed
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	//to check the FIFO IS FULL or no?
	if(FIFO_IS_FULL(fifo)==FIFO_full)
		return FIFO_full;

	// check the id is not repeated

	check_student_id=Check_ID(fifo,item);

	if(check_student_id!=FIFO_error)
	{
		//start of Enqueue process
		*(fifo->head)=item; //assign the value of the item in head
		fifo->counter++;// increment the counter
		//write code of circular FIFO
		if(fifo->head==(fifo->head+(fifo->length*sizeof(Sdata_t))))//if the head is reach to end of FIFO or no
			fifo->head=fifo->base;
		else
			fifo->head++;
		return FIFO_no_error;//return the status of FIFO
	}
	return FIFO_error;
}
/*==================================================================================================*/
FIFO_buf_status FIFO_IS_FULL( FIFO_buf_t *fifo_buf )
{
	//to check the FIFO is not null and check the base , tail , head is existed
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
		return FIFO_null;
	//to check the FIFO is full or no
	if(fifo_buf->counter>=fifo_buf->length)
		return FIFO_full;
	return FIFO_no_error;
}
/*==================================================================================================*/
FIFO_buf_status FIFO_EMPTY( FIFO_buf_t* fifo_buf )
{
	//check if FIFO is null
	if(!fifo_buf->head||!fifo_buf->base||!fifo_buf->tail)
		return FIFO_null;
	//to check FIFO is empty
	if(fifo_buf->counter==0)
		return FIFO_empty;

	return FIFO_no_error;
}
/*==================================================================================================*/
FIFO_buf_status Check_ID(FIFO_buf_t* fifo_buf , Sdata_t item)
{
	Sdata_t* check_ID = fifo_buf->tail;//to check the id is not repeated

	for (int i = 0; i < fifo_buf->counter; ++i)
	{
		if (check_ID->ID == item.ID)
		{
			printf("[ERROR] The ID is Repeated!!\n");
			return FIFO_error;
		}
		check_ID = (check_ID + 1); // move to next element
		if (check_ID == (fifo_buf->base + fifo_buf->length * sizeof(Sdata_t)))
			check_ID = fifo_buf->base; //if fifo is reach to top fifo
	}

	return FIFO_no_error;
}
/*==================================================================================================*/

