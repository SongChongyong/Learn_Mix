
void ShellSort( ElementType A[ ], int N, int Incre[ ], int M )
{	/* ϣ������*/
	/* ����Incre[]Ϊ����M�����������У��ݼ����������һ��Ԫ��Ϊ1 */
	int i, j, k, Increment;
	ElementType temp;

	for ( i = 0; i<M; i++ ) {
		Increment = Incre[ i ];	/* ѡ�����������Ҫ������ */
		for ( j = Increment; j < N; j++ ) { 
			temp = A[ j ];
			for ( k = j; k-Increment >= 0; k -= Increment ) {
				if ( temp >= A[ k - Increment ]) break;
                else
				    A[ k ] = A[ k - Increment ];
				A[k] = temp;
			} 
		} /* ����һ�˲������� */
	}
}
