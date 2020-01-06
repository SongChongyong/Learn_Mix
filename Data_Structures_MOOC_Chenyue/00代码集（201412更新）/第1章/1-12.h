
int MaxSubseqSum2( int List[], int N )
{   int ThisSum, MaxSum = 0;
	int i, j;

	for( i = 0; i < N; i++ ) { /* i���������λ�� */
		ThisSum = 0;  /* ThisSum�Ǵ�List[i]��List[j]�����к� */
		for( j = i; j < N; j++ ) { /* j�������Ҷ�λ�� */
			ThisSum += List[j];
			/*������ͬ��i����ͬ��j��ֻҪ��j-1��ѭ���Ļ������ۼ�1���*/
			if( ThisSum > MaxSum ) /* ����յõ���������к͸��� */
				MaxSum = ThisSum;   /* ����½�� */
		} /* jѭ������ */
    } /* iѭ������ */
	return MaxSum;
}
