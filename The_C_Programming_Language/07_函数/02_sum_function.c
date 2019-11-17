# include <stdio.h>

// 计算从begin到end的和 
void sum(int begin, int end)
{
	int i;
	int sum=0;
	for (i=begin; i<=end; i++){
		sum += i;
	}
	printf("%d到%d的和是%d\n", begin, end, sum);
}

int main()
{
	sum(1,10);  
	sum(20,30);
	sum(35,45);
	
	return 0;
}
/*
1到10的和是55
20到30的和是275
35到45的和是440
*/
