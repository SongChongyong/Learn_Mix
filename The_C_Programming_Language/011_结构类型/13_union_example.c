#include <stdio.h>
typedef union{
	int i;
	char ch[sizeof(int)];
}CHI;

int main(){
	CHI chi;
	int i;
	chi.i=1234;    /*10进制的1234对应16进制是 0x04D2，下面遍历打印一下存储的字符形式的chi*/
	for (i=0;i<sizeof(int);i++)
		printf("%02hhX",chi.ch[i]);   /*%02hhX是格式符，表示16进制，不到10就补充0 */ 
		/*
		打印结果是： 
		FFD2040000
		结果表示 chi.ch[0]=D2,chi.ch[1]=04,chi.ch[2]=00,chi.ch[3]=00
		*/
		
	printf("\n");
	return 0;
} 
