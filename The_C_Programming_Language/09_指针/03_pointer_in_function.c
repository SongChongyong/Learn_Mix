# include <stdio.h>

void fun(int *p);

int main(void)
{
	int i = 6;
	printf("&i=%p\n", &i);
	fun(&i);
	printf("i=%d\n",i);
	return ;
} 

void fun(int *p)
{
	printf("p=%p\n", p);      // 指针"p"表示的是地址
	printf("*p=%d\n", *p);    // // "*p"表达的是一个变量
	*p = 26;
	
}
/*
&i=0061FEAC
p=0061FEAC
*p=6
i=26
*/
