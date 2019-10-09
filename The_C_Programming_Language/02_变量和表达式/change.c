# include <stdio.h>  // 包含标准库（输入库和输出库）的信息 

int main()
{
	int price = 0;
	printf("请输入金额（元）:");
	scanf("%d", &price);
	
	int change = 100 - price;
	printf("找您%d元\n",change); 
	
	return 0;
}

/*
请输入金额（元）:30
找您70元

*/
