# include<stdio.h>

// ��ӡ���ǰ50������ 
int main()
{
	int x =1;
	int cnt = 0;
	while (cnt < 50){
		int isPrime = 1;  // isPrime=1,��ʼ��Ϊ����
		int i;  
		for(i=2;i<x;i++){
			
			if (x%i == 0){
				isPrime = 0;  // ��x���Ա�i����ʱ��isPrime=0,��ʾ�������� 
				break;
			}
		}
		
		if (isPrime == 1){
			printf("%d\t",x);
			cnt ++;
					// ÿ�������
			if (cnt%5 == 0){
				printf("\n");
			}
		} 
		x++;		
	}
	return 0; 
} 
/*
1       2       3       5       7
11      13      17      19      23
29      31      37      41      43
47      53      59      61      67
71      73      79      83      89
97      101     103     107     109
113     127     131     137     139
149     151     157     163     167
173     179     181     191     193
197     199     211     223     227
*/


