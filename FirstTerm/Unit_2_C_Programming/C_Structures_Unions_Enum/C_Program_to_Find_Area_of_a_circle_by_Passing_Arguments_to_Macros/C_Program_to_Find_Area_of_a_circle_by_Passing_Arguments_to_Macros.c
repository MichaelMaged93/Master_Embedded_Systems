/*
 ============================================================================
 Name        : C_Program_to_Find_Area_of_a_circle_by_Passing_Arguments_to_Macros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#define PI 3.14159

double areaCirlce (float radius);

int main()
{
	float radius ;

	printf ("Enter the radius of the circle: ");
	fflush (stdin);	fflush (stdout);
	scanf ("%f", &radius);

	printf ("The Area of the circle is: %.2lf", areaCirlce (radius));

	return 0;
}


double areaCirlce (float radius)
{
	return (PI * radius * radius);
}
