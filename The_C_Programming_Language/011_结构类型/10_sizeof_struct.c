#include <stdio.h>

struct student{
	char firstName[5];
	char lastName[5];
	int birthYear;
	double aveGrade;
};

int main(void) {
    //! showMemory(start=65520)
	struct student me;
    printf("Size of struct student is %d.\n", sizeof(struct student));
    printf("Size of firstName is %d.\n", sizeof(me.firstName));
    printf("Size of lastName is %d.\n", sizeof(me.lastName));
    printf("Size of birthYear is %d.\n", sizeof(me.birthYear));
    printf("Size of aveGrade is %d.\n", sizeof(me.aveGrade));

	return 0;
}
/*
edX 的Codecase sandbox运行结果：
Size of struct student is 22.                                                   
Size of firstName is 5.                                                         
Size of lastName is 5.                                                          
Size of birthYear is 4.                                                         
Size of aveGrade is 8. 
 
32为GCC编译器结果： 
Size of struct student is 24.
Size of firstName is 5.
Size of lastName is 5.
Size of birthYear is 4.
Size of aveGrade is 8.
*/
