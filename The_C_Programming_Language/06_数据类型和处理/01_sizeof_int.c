#include<stdio.h>

int main()
{
	printf("char=%d\n",sizeof(char));
	printf("short=%d\n",sizeof(short));	
	printf("int=%d\n",sizeof(int));
//	printf("float=%d\n",sizeof(float));
//	printf("double=%d\n",sizeof(double));
	printf("long=%d\n",sizeof(long));
	printf("long long=%d",sizeof(long long));  
	return 0;
}

/*
char=1
short=2
int=4
long=4
long long=8
*/
