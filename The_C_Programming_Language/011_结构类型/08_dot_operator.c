#include <stdio.h>

struct student{
	char firstName[5];
	char lastName[5];
	int birthYear;
	double aveGrade;
};

int main(void) {
    struct student learner;
    printf("First name: ");
    // 结构用"."运算符和名字访问其成员,firstName本身是数组，所以不用&
    scanf("%s", learner.firstName);

    printf("Year of birth:");
    // 结构用"."运算符和名字访问其成员
    scanf("%d", &learner.birthYear);

    
    printf("Name: %s %s\n", learner.firstName, learner.lastName);
	printf("Year of birth: %d\n",learner.birthYear);
	printf("Average grade: %.2lf\n",learner.aveGrade);
    
	return 0;
}
/*
First name: Pet
Year of birth:1989
Name: Pet
Year of birth: 1989
Average grade: 0.00
由结果可知，结构变量的成员firstName[5],lastName[5], birthYear, aveGrade都初始化为0，可以用"."运算符访问其成员 
*/ 

