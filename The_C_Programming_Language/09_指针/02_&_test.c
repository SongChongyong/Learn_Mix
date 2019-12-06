# include<stdio.h>

//int main()
//{
//	// 相邻变量的地址
//	int i ;
//	int p;
//	printf("%p\n",&i);
//	printf("%p\n",&p);
//	/*
//	0061FEAC
//	0061FEA8
//	*/ 
//	return 0;
//
//}

int main ()
{
	int a[10];
	
	printf("%p\n",&a);      // 数组的地址
	printf("%p\n",a);	
	printf("%p\n",&a[0]);   // 数组单元的地址
	printf("%p\n",&a[1]);	// 相邻的数组单元的地址 
	/*
	0061FE88
	0061FE88
	0061FE88
	0061FE8C
	*/
	
}

