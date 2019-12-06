#include<stdio.h>
#include<string.h>

int mycmp1 (const char* s1, const char* s2);
int mycmp2 (const char* s1, const char* s2);

int main(int argc, char const *argv[])
{
	char s1[] = "abc";
	char s2[] = "abc";
	char s3[] = "bbc";
	char s4[] = "ABc";
	printf("%d\n", strcmp(s1, s2));  // 0
	printf("%d\n", strcmp(s1, s3));  // -1
	printf("%d\n", strcmp(s1, s4));  // 32
	printf("%d\n", mycmp1(s1, s4));  // 32
	printf("%d\n", mycmp2(s1, s4));  // 32
	
} 

// 用数组形式实现strcmp 
int mycmp1 (const char* s1, const char* s2)
{
	int idx = 0;
	while(s1[idx] == s2[idx] && s1[idx] != '\0'){
		idx ++;
	}
	return s1[idx] - s2[idx];
}

// 用指针形式实现strcmp 
int mycmp2 (const char* s1, const char* s2)
{
	while(*s1 == *s2 && *s1 != '\0'){
		s1++;
		s2++;
	}
	return *s1 - *s2;
}


