# include <stdio.h> 

void swap(int a, int b);
int main()
{
	int a = 5;
	int b = 6;
	swap(a,b);
	printf("a=%d  b=%d\n",a , b);  // 结果是：a=5  b=6 
	return 0;
}

// 交换a和b 
void swap(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}
