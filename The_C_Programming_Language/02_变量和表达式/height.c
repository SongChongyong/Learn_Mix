#include <stdio.h>

int main()
{
	printf("请分别输入身高的英尺和英寸，"
		"如输入\"5 7\"表示5英尺7英寸：");

	double foot;
	double inch;

	scanf("%lf %lf", &foot, &inch);   // %lf 表示输入浮点数 

	printf("身高是%f米。\n",          // %f 表示按照浮点数打印 
		((foot + inch / 12) * 0.3048));

	return 0;
}

/*
请分别输入身高的英尺和英寸，如输入"5 7"表示5英尺7英寸：5 7
身高是1.701800米。

*/ 
