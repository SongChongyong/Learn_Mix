# include<stdio.h>

// 求1~10、20~30和35~45的三个和
int main()
{
	int i;
	int sum;
	
	for (i=1,sum=0;i<=10;i++){
		sum +=i;
	}
	printf("%d到%d的和是%d\n", 1, 10, sum);
	
	for (i=10,sum=0;i<=30;i++){
		sum +=i;
	}
	printf("%d到%d的和是%d\n", 10, 30, sum);
	
	for (i=35,sum=0;i<=45;i++){
		sum +=i;
	}
	printf("%d到%d的和是%d\n", 35, 45, sum);
	
	return 0;
} 
/*
1到10的和是55
10到30的和是420
35到45的和是440
*/
