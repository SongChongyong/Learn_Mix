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

// 把src拷贝到dst的后面，接成一个长的字符串
char * mycat(char *dst, const char* src)
{
    while(dst[strlen(dst)]=*src++); 
    // *p++：先取出p所指的那个数据来，之后把p移到下一个位置。
    return dst;
}

/*
123-456
*/
