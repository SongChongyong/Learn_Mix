#include <stdio.h>

int main()
{
	int i, j;
	
	for(i = 100; i <= 200; i++){    /* ���ѭ��*/
		j=2;
		while (j<i && i%j!=0) j++;  /* �ڲ�ѭ��,�б�i�Ƿ�������*/
		if (j==i) printf("%d ", i);   
          /*j==i˵���������whileѭ����i�����ܱ�j���������i������ */
	}
	
	return 0;
}
