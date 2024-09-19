/*
 * main.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Michael Maged
 */
#include "Student_Managment_System.h"
#include "stdio.h"
#include "string.h"

Sdata_t  buf[50];
int main()
{
FIFO_buf_t Fifo_data;
int choice;
FIFO_init(&Fifo_data,buf,50);
Dprintf("Welcome to the Student management System \n");
	printf("\n*******************************************\n");
	while(1)
	{
		Dprintf("Choose the task that you want perform \n");
		Dprintf("\t1. Add the Student Details Manually \n");
		Dprintf("\t2. Add the Student Details From Text File \n");
		Dprintf("\t3. Find the Student Details by Roll Number \n");
		Dprintf("\t4. Find the Student Details by First Name \n");
		Dprintf("\t5. Find the Student Details by Course ID \n");
		Dprintf("\t6. Find the Total Number Of Students \n");
		Dprintf("\t7. Delete the Students Details by Roll Number \n");
		Dprintf("\t8. Update the Students Details by Roll Number \n");
		Dprintf("\t9. Show All Information \n");
		Dprintf("\t10. To Exit \n");
		Dprintf("\nEnter your choice to perform the task :");
		Dscanf(&choice,"%d");
		switch(choice)
		{
		case 1:
			Dprintf("\n*****************************************\n");
			Add_Student_Manually(&Fifo_data);
			Dprintf("\n*******************************************\n");
			break;
		case 2:
			Dprintf("\n******************************************\n");
			Add_Student_From_File(&Fifo_data);
			Dprintf("\n*******************************************\n");
			break;
		case 3:
			Dprintf("\n*******************************************\n");
			Find_Student_By_ID(&Fifo_data);
			Dprintf("\n*******************************************\n");
			break;
		case 4:
			Dprintf("\n*******************************************\n");
			Find_Student_By_First_Name(&Fifo_data);
			Dprintf("\n*******************************************\n");
			break;
		case 5:
			Dprintf("\n*******************************************\n");
			Find_NO_Of_Student_IN_Course(&Fifo_data);
			Dprintf("\n*******************************************\n");
			break;
		case 6:
			Find_Total_Number(&Fifo_data);
			Dprintf("\n*******************************************\n");
			break;
		case 7:
			Dprintf("\n*******************************************\n");
			Delete_Student(&Fifo_data);
			Dprintf("\n*******************************************\n");
			break;
		case 8:
			Dprintf("\n*******************************************\n");
			Update_Student_Info(&Fifo_data);
			Dprintf("\n*******************************************\n");
			break;
		case 9:
			Dprintf("\n*******************************************\n");
			Show_Student(&Fifo_data);
			Dprintf("\n*******************************************\n");
			break;
		case 10:
			Dprintf("\n*******************************************\n");
			Dprintf("Thank You For Using Our Student management System ");
			exit(1);
			Dprintf("\n*******************************************\n");
			break;
		default:
			Dprintf("\n*******************************************\n");
			Dprintf("\n You Entered a Wrong Option \n");
			Dprintf("\n*******************************************\n");
			break;
		}

	}
return 0;
}

