# include<stdio.h>

int main()
{

	int x;
	int n=0;
	
	scanf("%d", &x);
	
	n++;
	x /= 10;
	if (x>0)
	{
		n++;
		x /= 10;
		if (x>0)
		{
			n++;
			x /= 10;
			if ...     // �������г���10
		}         
	} 
	
	printf("%d\n",n);
}
