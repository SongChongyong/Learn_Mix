
void InsertionSort ( ElementType A[ ], int N )
{	/* �������� */
	int i, j ;
	ElementType temp;

	for ( i = 1; i < N; i++ ) {
		temp = A[i]; /* ȡ��δ���������еĵ�һ��Ԫ��*/
	    for ( j = i; (j > 0) && (temp < A[j-1]); j-- )
			A[ j ] = A[ j - 1 ]; /*������������������Ԫ�رȽϲ�����*/
		A[j] = temp; /* �Ž����ʵ�λ�� */
	}
}
