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

// ʹ�ýṹ����ָ��ʵ�ֶ��룬�������ܴ��ݵ��ⲿ
void readStudent(struct student *studptr) {
    printf("\nEnter a new student record: \n");
    printf("First name: ");
    scanf("%s", (*studptr).firstName);   // ע������д��: (*studptr).firstName
    printf("Last name: ");
    scanf("%s", (*studptr).lastName);
    printf("Birth year: ");
    scanf("%d", &(*studptr).birthYear);    // ע������д��:  &(*studptr).birthYear
    printf("Average grade: ");
    scanf("%lf", &(*studptr).aveGrade);
}

