/*
 * main.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Michael Maged
 */
#include "stdio.h"
#include "string.h"
void rev_string(char arr[],int size);
int main()
{
	char arr[30]="michael maged";
	int size;
	printf("Enter the string: ");
	fflush(stdin); fflush(stdout);
	gets(arr);
	size=strlen(arr);
	rev_string(arr,size-1);
	return 0;
}
void rev_string(char arr[],int size)
{int j,k,count=0;
char a[50]={0},temp[50]={0};
for(int i=0; i<size;i++)
{
	if(arr[i]==' ')
	{
		for(j=i+1,k=0;arr[j]!='\0';j++,k++)
		{
			a[k]=arr[j];
		}
		a[k]=' ';
		a[k+1]='\0';
		break;
	}
}
for(int i=0;arr[i]!=' ';i++)
{
	temp[i]=arr[i];
	count++;
}
temp[count]='\0';
strcat(a,temp);
printf("%s",a);
}
