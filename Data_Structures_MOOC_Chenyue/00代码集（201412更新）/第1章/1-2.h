
void PrintN ( int N )
{  /* ��ӡ��1��N��ȫ�������� */
	if ( !N ) return; 
	PrintN( N - 1 ); 
	printf("%d\n", N ); 
	return;
}
