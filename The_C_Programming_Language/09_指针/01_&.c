# include<stdio.h>

int main()
{
	int i = 0;
	int p;
	p = (int)&i;   // 把i的地址(&i)强制赋值给p
	printf("0x%x\n",&i);
	printf("%p\n",&i);
	printf("%p\n",p);	
	return 0;
}
/*
32位架构下运行结果： 
0x61fea8
0061FEA8
0061FEA8

64位环境下运行结果：
0x9ffe48
00000000009FFE48
00000000009FFE48 
*/
