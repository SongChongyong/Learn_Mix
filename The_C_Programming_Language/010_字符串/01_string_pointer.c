# include<stdio.h>

int main()
{
	//! showMemory(start=65520)
	// 上面showMemory语句是为了使用edX中C语言课程提供Codecast sandbox展示地址 
	char *str = "Hello World"; 
	str[0] = 'B';  
	// 尝试把上面字符串第一位换成'B' ;
	// 编译后发现程序运行错误 
	printf("Here! s[0]=%c\n",str[0]);

}
