#include<stdio.h>
#include<string.h>

int mylen(const char *s);

int main(int argc, char const *argv[])
{
	char line[] = "Hello";
	printf("strlen = %lu\n", strlen(line));
	printf("sizeof = %lu\n", sizeof(line));
	printf("mylen = %lu\n", mylen(line));
	/*
	strlen = 5
	sizeof = 6
	mylen = 5
	*/
}

// 自己写一个计算字符串长度的函数 
int mylen(const char *s)
{
	int idx = 0;   // 计数器
	while ( s[idx] != '\0'){
		idx ++;
	}
	return idx;
} 
