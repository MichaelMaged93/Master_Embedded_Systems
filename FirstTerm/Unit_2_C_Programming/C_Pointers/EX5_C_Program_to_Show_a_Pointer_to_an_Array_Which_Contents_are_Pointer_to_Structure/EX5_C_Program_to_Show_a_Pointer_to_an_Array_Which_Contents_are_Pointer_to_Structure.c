/*
 * EX5_C_Program_to_Show_a_Pointer_to_an_Array_Which_Contents_are_Pointer_to_Structure.c
 *
 * Created on : 21/7/2024
 *     Author : Michael Maged
 */
#include <stdio.h>
struct SEmployee
{
	char* name;
	int id;
};

int main(){
	struct SEmployee emp1={"michael",2001},emp2={"thomas",2003},emp3={"mina",2004};
	struct SEmployee *arr[3]={&emp1,&emp2,&emp3};
	struct SEmployee *(*ptr)=arr;
	printf(" Employee Name : %s \n",(*(ptr+1))->name);
	printf(" Employee ID :  %d \n",(*(ptr+1))->id);
	return 0;
}
