# include <stdio.h>

int main()
{
	int x;
	double sum = 0;
	int cnt = 0;
	int number[100];  // ��������
	scanf("%d",&x);
	// ������-1ʱ���������� 
	while (x!=-1){
		number[cnt] = x; 
		sum += x;
		cnt++;
		scanf("%d", &x);
	}
	
	if (cnt>0){
		int i;
		double average = sum/cnt;
		printf("ƽ�����ǣ�%f\n����ƽ��ֵ������У�\n",average);
		// �������飬ʹ�������е�Ԫ����ƽ�����Ƚϣ��������� 
		for (i=0;i<cnt;i++){
			if (number[i] > average){
				printf("%d ",number[i]);    
			}
		}
	} 
}
/*
2 4 5 7 8 -1
ƽ�����ǣ�5.200000
����ƽ��ֵ������У�
7 8
*/

