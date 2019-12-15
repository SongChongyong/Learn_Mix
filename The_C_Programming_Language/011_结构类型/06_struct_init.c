#include<stdio.h>

// 申明data结构
struct date {
	int month;
	int day;
	int year;
};

int main()
{	
	//! showMemory(start=65520)
    struct date today = {07,31,2014};  				 // 结构变量及初始化 
	struct date thisMonth = {.month=7, .year=2014};  // 结构变量及初始化     

	printf("Today's date is %i-%i-%i.\n", today.year, today.month, today.day);
    printf("Today's date is %i-%i-%i.\n", thisMonth.year, thisMonth.month, thisMonth.day);
	// Today's date is 2014-7-31.
	// Today's date is 2014-7-0. 
	
	struct date *pDate = &today;
	printf("Adress of struct today is %p.\n", pDate);
	// Adress of struct today is 00000000009FFE30. 

	return 0;
}
