#include<stdio.h>
#include<stdlib.h>  // 要使用malloc先申明头文件 

int main()
{
	int number;
	int *a; 
	int i;
	scanf("%d", &number);
	a = (int*)malloc(number*sizeof(int));  // 这样才能定义大小是number的int数组a
	
	// 下面可以对数组a(或者叫指针a做各种操作) 
	printf("Input items for a[number]:", number);
	for (i=0; i<number; i++){
		scanf("%d", &a[i]);
	}
	printf("a[%d] = ", number);
	for (i=number-1; i>=0; i--){
		printf("%d ", a[i]);
	}
	free(a);   //最终必须把申请得来的空间还给系统 
	return 0;
}
/*
5
Input items for a[number]:2 5 7 2 9
a[5] = 9 2 7 5 2
*/

