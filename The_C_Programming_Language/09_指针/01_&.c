# include<stdio.h>

int main()
{
	int i = 0;
	int p;
	p = (int)&i;   // ��i�ĵ�ַ(&i)ǿ�Ƹ�ֵ��p
	printf("0x%x\n",&i);
	printf("%p\n",&i);
	printf("%p\n",p);	
	return 0;
}
/*
32λ�ܹ������н���� 
0x61fea8
0061FEA8
0061FEA8

64λ���������н����
0x9ffe48
00000000009FFE48
00000000009FFE48 
*/
