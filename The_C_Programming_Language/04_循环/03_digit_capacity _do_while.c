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
	}while (x>0);    // ע��while����Ҫ�ӷֺţ���ʾ������       
	
	printf("%d\n",n);
}
