void Swap ( ElementType *a, ElementType *b )
{   /*����a��b����Ԫ��*/
	ElementType temp = *a ;
	*a = *b ; 
	*b = temp ;
}

ElementType FindKthLargest ( ElementType S[ ], int K, int Low, int High )
{  /* ��S[Low]..S[High]���ҵ�K������  */
	ElementType Pivot = S[Low]; /* ��ȡ��Ԫ��Ϊ��׼ */
	int Left = Low, Right = High;

	if ( Low >= High ) return Pivot;
	Swap ( &S[Low], &S[Right] ) ; /*����׼�����һ��Ԫ�ؽ���*/
	while (1) {/*�������бȻ�׼����Ƶ���׼��ߣ�С���Ƶ��ұ�*/
		while ( (Low<High)&&(Pivot <= S[Low]) ) Low++ ;
		while ( (Low<High)&&(Pivot >= S[High]) ) High-- ;
        if ( Low < High )
		    Swap ( &S[Low], &S[High] ) ;
		else  break;
	}
    Swap ( &S[Low], &S[Right] ) ; /* �����Ļ�׼������ȷ��λ�� */
	if ( K <= High-Left ) /* High-Left�����˼���S1�Ĵ�С*/
		return FindKthLargest(S, K, Left, High-1); /*�ڼ���S1�м����� */
	else if ( K == High-Left+1 ) /* �ҵ������� */
		return Pivot;
	else /*�ڼ���S2���� */
		return FindKthLargest(S, K-High+Left-1, High+1, Right);
}
