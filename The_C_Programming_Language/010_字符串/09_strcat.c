#include<stdio.h>
#include<string.h>

char * mycat(char *dst,const char* src); 
int main()
{
    //! showMemory(start=65520)
	char s1[10]="123";
    char s2[5]="-456";   
    printf("%s\n",mycat(s1,s2));
    return 0;
}

// ��src������dst�ĺ��棬�ӳ�һ�������ַ���
char * mycat(char *dst, const char* src)
{
    while(dst[strlen(dst)]=*src++); 
    // *p++����ȡ��p��ָ���Ǹ���������֮���p�Ƶ���һ��λ�á�
    return dst;
}

/*
123-456
*/
