# include<stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	int i;
	int isPrime = 1;  // isPrime=1,��ʼ��Ϊ����  
	for(i=2;i<x;i++){
		if (x%i == 0){
			isPrime = 0;  // ��x���Ա�i����ʱ��isPrime=0,��ʾ�������� 
			break;
		}
	}
	
	if (isPrime == 1){
		printf("%d������\n",x);
	} 
	else {
		printf("%d��������\n",x);
	}
	return 0; 
} 

/*
14
14��������
13
13������
*/
