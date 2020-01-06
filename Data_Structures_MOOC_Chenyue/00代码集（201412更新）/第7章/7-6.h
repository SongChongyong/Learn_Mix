
void Swap ( ElementType *a, ElementType *b )
{   /*����a��b����Ԫ��*/
	ElementType temp = *a ;
	*a = *b ; 
	*b = temp ;
}

void QSort ( ElementType A[ ], int Low, int High )
{  /* ��A[Low]~A[Hight]���п������� */
	ElementType Pivot = A[Low]; /* ��ȡ��Ԫ��Ϊ��׼ */
	int Left = Low, Right = High;

	if ( Low >= High ) return;
	Swap ( &A[Low], &A[Right] ) ; /*����׼�����һ��Ԫ�ؽ���*/
	while (1) {/*�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�*/
		while ( (Low<High)&&(Pivot >= A[Low]) ) Low++ ;
		while ( (Low<High)&&(Pivot <= A[High]) ) High-- ;
        if ( Low < High )
		    Swap ( &A[Low], &A[High] ) ;
		else  break;
	}
    Swap ( &A[Low], &A[Right] ) ; /* �����Ļ�׼������ȷ��λ�� */
	/*�ֱ�������Ӽ����п���*/
	QSort ( A, Left, Low - 1 ) ; 
	QSort ( A, Low + 1, Right ) ;
}

void QuickSort( ElementType A[ ], int N )
{   /* �������� */
    QSort( A, 0, N-1 );
}
