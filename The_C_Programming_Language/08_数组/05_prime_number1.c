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
		printf("%d是素数\n",x);
	} 
	else {
		printf("%d不是素数\n",x);
	}
	return 0; 
} 

// 判断是否是素数函数，从2到x-1测试是否整除
int isPrime(int x)
{
	int ret = 1;  // ret=1,初始化为素数
	int i;
	if (x ==1){
		ret = 0;
	}  
	for(i=2; i<x; i++){
		if (x%i == 0){
			ret = 0;  // 当x可以被i整除时，ret=0,表示不是素数 
			break;
		}
	}
	return ret;
}

// 判断是否是素数函数，去掉偶数后，从3到x-1，每次加二
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

// 判断是否是素数函数，去掉偶数后，从3到sqrt(x)，每次加二
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
14不是素数
13
13是素数
*/
