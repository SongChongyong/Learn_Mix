#include<stdio.h>

int main()
{
	// ����data�ṹ 
	struct date {
		int month;
		int day;
		int year;
	};
	
	struct date today;   
	today.month = 12;
	today.day = 8;        
	// ��Щд"08"��error:invalid digit "8" in octal constant ��ʾ�����0��ʼ����8���Ƴ�����08��Ч�� 
	// ����Ҫ��ӡ XXXX-0X-0X���������ʵ�ֲ��� 
	today.year = 2019;
	printf("Today's date is %i-%i-%i.\n", today.year, today.month, today.day);
	// Today's date is 2019-12-8. 
	
	return 0;
}
