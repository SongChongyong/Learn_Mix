#include<stdio.h>
#include<string.h>

int main()
{
	char s[] = "Hello";
	// �ҵ�һ��l��λ��
	char *p = strchr(s, 'l');
	printf("p = %s\n", p);      // p = llo
	
//	// �ҵڶ���l��λ�� 
//	p = strchr(p+1, 'l');
//	printf("p = %s\n", p);    // p = lo
	
	
	// ����ֻ���ҵ��˵�һ��l��λ�ã�����������Ҫ��l����ַ������Ƴ���
	char *t = (char*)malloc(strlen(p)+1);
	strcpy(t,p);
	printf("t = %s\n",t);
	free(t);   // t = llo
	
	// �ҵ��˵�һ��l��λ�ú󣬼���������Ҫ��lǰ���ַ������Ƴ���	 
	char c = *p;
	*p = '\0';
	char *q = (char*)malloc(strlen(s)+1);
	strcpy(q,s);
	printf("q = %s\n",q);
	free(q);   // q = He
} 
