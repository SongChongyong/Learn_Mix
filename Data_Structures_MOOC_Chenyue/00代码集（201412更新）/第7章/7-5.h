
void BubbleSort ( ElementType A[ ], int N )
{   /*ð������*/
	int i, j ;
	bool flag;
	ElementType temp;

	for ( i = N - 1; i >= 0; i--) {
		flag = 0 ; /*��Ǹô�ѭ�����Ƿ������������ޣ���˵��������������*/
		for ( j = 0; j < i; j++ ) {
			/*ÿ��ѭ���ҳ�һ�����Ԫ�أ������������Ҷ�*/
			if ( A[ j ] > A[ j + 1 ] ) {
				temp = A[ j ] ;
				A[ j ] = A[ j + 1 ] ;
				A[ j + 1 ] = temp ;
				flag = 1 ;		/*����������������*/
			}
		}
		if ( !flag ) break ;		/*��û�з���������������ѭ��*/
	}
}
