# include <stdio.h>  // ������׼�⣨����������⣩����Ϣ 

int main()
{
	int price = 0;
	printf("�������Ԫ��:");
	scanf("%d", &price);
	
	int change = 100 - price;
	printf("����%dԪ\n",change); 
	
	return 0;
}

/*
�������Ԫ��:30
����70Ԫ

*/
