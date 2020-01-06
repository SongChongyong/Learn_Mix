
void Merge( ElementType A[], ElementType TmpA[], int Left, int Mid, int Right )
{	/* �������A[Left]~A[Mid-1]��A[Mid]~A[Right]�鲢��һ���������� */
	int Tp, LeftEnd, i;

	Tp = Left; /* �������е���ʼλ�� */
	LeftEnd = Mid - 1; /* ���������ֹ��λ�� */
	while ( ( Left<LeftEnd ) && ( Mid<Right ) )
		if ( A[Left] <= A[Mid] )
			TmpA[Tp++] = A[Left++]; /* �����Ԫ�ظ��Ƶ�TmpA */
		else
			TmpA[Tp++] = A[Mid++]; /* ���ұ�Ԫ�ظ��Ƶ�TmpA */
		while ( Left <= LeftEnd ) /* ��������Ԫ��ʣ�¶��ұ��Ѿ����� */
			TmpA[Tp++] = A[Left++]; /* �����ʣ��Ԫ�ظ��Ƶ�TmpA */
		while ( Mid <= Right ) /* ����ұ���Ԫ��ʣ�¶�����Ѿ����� */
			TmpA[Tp++] = A[Mid++]; /* ���ұ�ʣ��Ԫ�ظ��Ƶ�TmpA */
		for ( i=Right-Left; i>=0; i--, Right-- ) 
			A[Right] = TmpA[Right]; /* �������TmpA[]���ƻ�A[]*/
}

void MSort( ElementType A[], ElementType TmpA[], int Left, int Right )
{	/* �ݹ�ؽ�A[Left]~A[Right]���� */
	if ( Left < Right ) {
		MSort(A, TmpA, Left, (Left+Right)/2);     /*�ݹ�������*/
		MSort(A, TmpA, (Left+Right)/2+1, Right); /*�ݹ����Ұ��*/
		Merge(A, TmpA, Left, (Left+Right)/2+1, Right); /*�鲢*/
	}
}

void MergeSort( ElementType A[], int N )
{   /* �鲢���� */
	ElementType *TmpA;

	TmpA = malloc( N * sizeof(ElementType) ); /*������ʱ�ռ�*/
	MSort( A, TmpA, 0, N-1);
	free( TmpA );
}
