# include<stdio.h>

int main()
{

	int x;
	int n=0;
	
	scanf("%d", &x);
	
	n++;
	x /= 10;
	do 
	{
		n++;
		x /= 10;
	}while (x>0);    // 注意while后需要加分号，表示语句结束       
	
	printf("%d\n",n);
}
