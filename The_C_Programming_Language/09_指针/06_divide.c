# include<stdio.h>

// 如果除法成功，返回1；否则返回0

int main(void)
{
	int a = 5;
	int b = 2;
	int c;
	if (divide(a, b, &c)){
		printf("%d/%d = %d\n", a, b, c); // 5/2 = 2
	}
	return 0;
} 

int divide(int a, int b, int *result)
{
	int ret = 1;
	if (b==0){
		ret = 0;
	} 
	else {
		*result = a/b;
	}
	return ret;  // 返回运算的状态
}
