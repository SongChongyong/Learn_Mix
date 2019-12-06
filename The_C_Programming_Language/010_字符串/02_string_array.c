# include<stdio.h>

int main()
{
	//! showMemory(start=65520)
	// 上面语句是为了使用edX中C语言课程提供Codecast sandbox展示地址 
	char s[15] = "Hello World"; 
	s[0] = 'B';  

	printf("Here! s[0]=%c\n",s[0]);
	// Here! s[0]=B
	return 0;
}
