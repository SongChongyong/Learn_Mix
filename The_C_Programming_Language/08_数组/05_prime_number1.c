# include<stdio.h>
# include<math.h>

int isPrime(int x);
int isPrime2(int x);
int isPrime2(int x);
int main()
{
	int x;
	scanf("%d", &x);
	if (isPrime3(x) ){
		printf("%d������\n",x);
	} 
	else {
		printf("%d��������\n",x);
	}
	return 0; 
} 

// �ж��Ƿ���������������2��x-1�����Ƿ�����
int isPrime(int x)
{
	int ret = 1;  // ret=1,��ʼ��Ϊ����
	int i;
	if (x ==1){
		ret = 0;
	}  
	for(i=2; i<x; i++){
		if (x%i == 0){
			ret = 0;  // ��x���Ա�i����ʱ��ret=0,��ʾ�������� 
			break;
		}
	}
	return ret;
}

// �ж��Ƿ�������������ȥ��ż���󣬴�3��x-1��ÿ�μӶ�
int isPrime2(int x)
{
	int ret = 1;
	int i;
	if (x ==1 || (x%2 == 0 && x!=2)){
		ret = 0;
	}
	for (i=3; i<x; i+=2){
		if (x%i == 0){
			ret = 0;
			break;
		}
	}
	return ret;
}

// �ж��Ƿ�������������ȥ��ż���󣬴�3��sqrt(x)��ÿ�μӶ�
int isPrime3(int x)
{
	int ret = 1;
	int i;
	if (x ==1 || (x%2 == 0 && x!=2)){
		ret = 0;
	}
	for (i=3; i<sqrt(x); i+=2){
		if (x%i == 0){
			ret = 0;
			break;
		}
	}
	return ret;
}


/*
14
14��������
13
13������
*/
