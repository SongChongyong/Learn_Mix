#include <stdio.h>

struct student{
	char firstName[30];
	char lastName[30];
	int birthYear;
	double aveGrade;
};
void readStudent(struct student *studptr);
int main(void) {
   //! showMemory(start=65520)
    struct student me;
    readStudent(&me);
	return 0;
}

// 使用结构变量指针实现读入，这样才能传递到外部
void readStudent(struct student *studptr) {
    printf("\nEnter a new student record: \n");
    printf("First name: ");
    scanf("%s", (*studptr).firstName);   // 注意这里写法: (*studptr).firstName
    printf("Last name: ");
    scanf("%s", (*studptr).lastName);
    printf("Birth year: ");
    scanf("%d", &(*studptr).birthYear);    // 注意这里写法:  &(*studptr).birthYear
    printf("Average grade: ");
    scanf("%lf", &(*studptr).aveGrade);
}

