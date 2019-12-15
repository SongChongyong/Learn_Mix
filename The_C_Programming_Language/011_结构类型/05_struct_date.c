#include<stdio.h>

int main()
{
	// 申明data结构 
	struct date {
		int month;
		int day;
		int year;
	};
	
	struct date today;   
	today.month = 12;
	today.day = 8;        
	// 这些写"08"会error:invalid digit "8" in octal constant 表示如果以0开始就是8进制常量，08无效了 
	// 所以要打印 XXXX-0X-0X用这个程序实现不了 
	today.year = 2019;
	printf("Today's date is %i-%i-%i.\n", today.year, today.month, today.day);
	// Today's date is 2019-12-8. 
	
	return 0;
}
