# include<stdio.h>

int main()
{
	//! showMemory(start=65520)
	// ����showMemory�����Ϊ��ʹ��edX��C���Կγ��ṩCodecast sandboxչʾ��ַ 
	char *str = "Hello World"; 
	str[0] = 'B';  
	// ���԰������ַ�����һλ����'B' ;
	// ������ֳ������д��� 
	printf("Here! s[0]=%c\n",str[0]);

}
