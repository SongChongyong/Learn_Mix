# include <stdio.h>

void fun(int *p);

int main(void)
{
	int i = 6;
	printf("&i=%p\n", &i);
	fun(&i);
	printf("i=%d\n",i);
	return ;
} 

void fun(int *p)
{
	printf("p=%p\n", p);      // ָ��"p"��ʾ���ǵ�ַ
	printf("*p=%d\n", *p);    // // "*p"������һ������
	*p = 26;
	
}
/*
&i=0061FEAC
p=0061FEAC
*p=6
i=26
*/
