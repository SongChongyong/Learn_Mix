# include <stdio.h>

// �����begin��end�ĺ� 
void sum(int begin, int end)
{
	int i;
	int sum=0;
	for (i=begin; i<=end; i++){
		sum += i;
	}
	printf("%d��%d�ĺ���%d\n", begin, end, sum);
}

int main()
{
	sum(1,10);  
	sum(20,30);
	sum(35,45);
	
	return 0;
}
/*
1��10�ĺ���55
20��30�ĺ���275
35��45�ĺ���440
*/
