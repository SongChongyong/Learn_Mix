# include<stdio.h>

// ��1~10��20~30��35~45��������
int main()
{
	int i;
	int sum;
	
	for (i=1,sum=0;i<=10;i++){
		sum +=i;
	}
	printf("%d��%d�ĺ���%d\n", 1, 10, sum);
	
	for (i=10,sum=0;i<=30;i++){
		sum +=i;
	}
	printf("%d��%d�ĺ���%d\n", 10, 30, sum);
	
	for (i=35,sum=0;i<=45;i++){
		sum +=i;
	}
	printf("%d��%d�ĺ���%d\n", 35, 45, sum);
	
	return 0;
} 
/*
1��10�ĺ���55
10��30�ĺ���420
35��45�ĺ���440
*/
