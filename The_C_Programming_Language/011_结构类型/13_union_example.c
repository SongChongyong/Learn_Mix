#include <stdio.h>
typedef union{
	int i;
	char ch[sizeof(int)];
}CHI;

int main(){
	CHI chi;
	int i;
	chi.i=1234;    /*10���Ƶ�1234��Ӧ16������ 0x04D2�����������ӡһ�´洢���ַ���ʽ��chi*/
	for (i=0;i<sizeof(int);i++)
		printf("%02hhX",chi.ch[i]);   /*%02hhX�Ǹ�ʽ������ʾ16���ƣ�����10�Ͳ���0 */ 
		/*
		��ӡ����ǣ� 
		FFD2040000
		�����ʾ chi.ch[0]=D2,chi.ch[1]=04,chi.ch[2]=00,chi.ch[3]=00
		*/
		
	printf("\n");
	return 0;
} 
