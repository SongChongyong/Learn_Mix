#include <stdio.h>

int main()
{
	printf("��ֱ�������ߵ�Ӣ�ߺ�Ӣ�磬"
		"������\"5 7\"��ʾ5Ӣ��7Ӣ�磺");

	double foot;
	double inch;

	scanf("%lf %lf", &foot, &inch);   // %lf ��ʾ���븡���� 

	printf("�����%f�ס�\n",          // %f ��ʾ���ո�������ӡ 
		((foot + inch / 12) * 0.3048));

	return 0;
}

/*
��ֱ�������ߵ�Ӣ�ߺ�Ӣ�磬������"5 7"��ʾ5Ӣ��7Ӣ�磺5 7
�����1.701800�ס�

*/ 
