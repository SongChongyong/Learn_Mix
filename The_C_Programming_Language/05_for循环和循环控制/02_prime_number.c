# include<stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	int i;
	int isPrime = 1;  // isPrime=1,初始化为素数  
	for(i=2;i<x;i++){
		if (x%i == 0){
			isPrime = 0;  // 当x可以被i整除时，isPrime=0,表示不是素数 
			break;
		}
	}
	
	if (isPrime == 1){
		printf("%d是素数\n",x);
	} 
	else {
		printf("%d不是素数\n",x);
	}
	return 0; 
} 

/*
14
14不是素数
13
13是素数
*/
