# include<stdio.h>

int isPrime(int x, int knownPrimes[], int number_of_Known_Primes);

// ��ӡǰ100������ 
int main(void)
{
	const int number = 100;
	int prime[100] = {2};   // ������������
	int count = 1;
	int i = 3;
	while (count < number){
		if (isPrime(i, prime, count)){
			prime[count++] = i;   // ��� i��������д������ 
		}
		i++;
	} 
	for (i=0; i<number; i++){
		printf("%d",prime[i]);
		if ((i+1)%5){
			printf("\t");
		}
		else {
			printf("\n");
		}
	}
	return 0;
} 

// �ж��ܷ���֪����<x����������
int isPrime(int x, int knownPrimes[], int number_of_Known_Primes)
{
	int ret = 1;  // ret=1,��ʼ��Ϊ����
	int i;  
	for(i=0; i<number_of_Known_Primes; i++){
		if (x % knownPrimes[i] == 0){
			ret = 0;  // ��x���Ա�knownPrimes[i]����ʱ��ret=0,��ʾ�������� 
			break;
		}
	}
	return ret;
}


/*
2       3       5       7       11
13      17      19      23      29
31      37      41      43      47
53      59      61      67      71
73      79      83      89      97
101     103     107     109     113
127     131     137     139     149
151     157     163     167     173
179     181     191     193     197
199     211     223     227     229
233     239     241     251     257
263     269     271     277     281
283     293     307     311     313
317     331     337     347     349
353     359     367     373     379
383     389     397     401     409
419     421     431     433     439
443     449     457     461     463
467     479     487     491     499
503     509     521     523     541
*/
