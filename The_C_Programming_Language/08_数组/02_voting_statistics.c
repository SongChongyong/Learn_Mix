# include <stdio.h> 
 
int main()
{
	const int number = 10;  // �����С 
	int x;
	int count[number];    //�������� 
	int i;
	// ��ʼ�����飬ʹcount[0],count[1],...,count[9]����ʼ��Ϊ0 
	for (i=0; i<number; i++){
		count[i] = 0;
	}
	
	scanf("%d", &x);
	
	while (x!=-1){
		if (x>=0 && x<=9){
			count[x]++;  // ÿ����һ�������ö�Ӧ��count[x]����һ
		}
		scanf("%d", &x);
	}
	// ��������Ԫ�� 
	for (i=0; i<number; i++){
		printf("%d: %d\n", i , count[i]);
	}
}
/*
1 4 7 9 3 5 2 5 6 22 45 2 6 8 9 2 1 -1
0: 0
1: 2
2: 3
3: 1
4: 1
5: 2
6: 2
7: 1
8: 1
9: 2
*/
