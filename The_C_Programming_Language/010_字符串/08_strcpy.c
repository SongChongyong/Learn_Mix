#include<stdio.h>

int mycpy1 (char* dst, const char* src);
int mycpy2 (char* dst, const char* src);

int main()
{
	//! showMemory(start=65520)
	char s1[4] = "";
	char s2[4] = "abc";
	printf("%s\n", mycpy1(s1, s2));  
	return 0;
	/*
	abc
	222
	*/	
} 

// ��������ʽʵ��strcpy 
int mycpy1 (char* dst, const char* src)
{
	int idx = 0;
	while(src[idx] != '\0'){
		dst[idx] = src[idx];
		idx ++;
	}
	dst[idx] = '\0';   //����һ��src����'\0' 
	
	return dst;
}

// ��ָ����ʽʵ��strcpy 
int mycpy2 (char* dst, const char* src)
{
	char *ret = dst;
	while(*src != '\0'){
		*dst++ = *src++;
	}
	*dst = '\0';   
	
	return ret;
}


