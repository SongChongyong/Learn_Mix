# include<stdio.h>

int main()
{
	//! showMemory(start=65520)
	// ���������Ϊ��ʹ��edX��C���Կγ��ṩCodecast sandboxչʾ��ַ 
	char s[15] = "Hello World"; 
	s[0] = 'B';  

	printf("Here! s[0]=%c\n",s[0]);
	// Here! s[0]=B
	return 0;
}
