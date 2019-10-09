# include <stdio.h>

main()
{
	int a;
	int b;
	
	printf("请输入两个整数：");
	scanf("%d %d", &a, &b);                 # 读入多个 
	printf("%d + %d = %d\n", a, b, a+b);
	
	return 0;
} 

/*
请输入两个整数：22 33
22 + 33 = 55

*/ 
