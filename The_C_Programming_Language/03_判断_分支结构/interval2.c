#include <stdio.h>

int main()
{
	int hour1, minute1;
	int hour2, minute2;

	scanf("%d %d", &hour1, &minute1);
	scanf("%d %d", &hour2, &minute2);

	int ih = hour2 - hour1;
	int im = minute2 - minute1;
	if ( im <0 ) 		// 判断如果(im小于0)，那么... 
	{				
		im = 60 + im;
		ih --;
	}
	
	printf("时间差是%d小时%d分。\n", ih, im);
	
	return 0;
}

/*
10 40
11 20
时间差是0小时40分。

*/
