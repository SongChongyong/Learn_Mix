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
    // �ṹ��"."����������ַ������Ա,firstName���������飬���Բ���&
    scanf("%s", learner.firstName);

    printf("Year of birth:");
    // �ṹ��"."����������ַ������Ա
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
�ɽ����֪���ṹ�����ĳ�ԱfirstName[5],lastName[5], birthYear, aveGrade����ʼ��Ϊ0��������"."������������Ա 
*/ 

