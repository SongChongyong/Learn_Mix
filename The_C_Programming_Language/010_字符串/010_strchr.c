#include<stdio.h>
#include<string.h>

int main()
{
	char s[] = "Hello";
	// 找第一个l的位置
	char *p = strchr(s, 'l');
	printf("p = %s\n", p);      // p = llo
	
//	// 找第二个l的位置 
//	p = strchr(p+1, 'l');
//	printf("p = %s\n", p);    // p = lo
	
	
	// 上面只是找到了第一个l的位置，假如我们需要把l后的字符串复制出来
	char *t = (char*)malloc(strlen(p)+1);
	strcpy(t,p);
	printf("t = %s\n",t);
	free(t);   // t = llo
	
	// 找到了第一个l的位置后，假如我们需要把l前的字符串复制出来	 
	char c = *p;
	*p = '\0';
	char *q = (char*)malloc(strlen(s)+1);
	strcpy(q,s);
	printf("q = %s\n",q);
	free(q);   // q = He
} 
