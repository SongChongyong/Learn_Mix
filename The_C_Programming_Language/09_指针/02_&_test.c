# include<stdio.h>

//int main()
//{
//	// ���ڱ����ĵ�ַ
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
	
	printf("%p\n",&a);      // ����ĵ�ַ
	printf("%p\n",a);	
	printf("%p\n",&a[0]);   // ���鵥Ԫ�ĵ�ַ
	printf("%p\n",&a[1]);	// ���ڵ����鵥Ԫ�ĵ�ַ 
	/*
	0061FE88
	0061FE88
	0061FE88
	0061FE8C
	*/
	
}

