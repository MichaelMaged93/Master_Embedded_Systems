#include <stdio.h>
#include <stdlib.h>

int main(void) {
	union v{
		char b[2];
		int bit1;
	} ;
	union v a;
	a.b[0]=3;
	a.b[1]=2;
	printf("%d,%d,%d",a.b[0],a.b[1],a.bit1);
	return 0;
}