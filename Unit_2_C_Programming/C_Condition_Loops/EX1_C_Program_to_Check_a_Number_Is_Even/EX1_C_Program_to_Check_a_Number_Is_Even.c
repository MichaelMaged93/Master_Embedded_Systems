/*
 ============================================================================
 Name        : EX1_C_Program_to_Check_a_Number_Is_Even.c
 Author      : Michael Maged
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
int main()
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if(num % 2 == 0)
        printf("%d is even.", num);
    else
        printf("%d is odd.", num);

    return 0;
}
