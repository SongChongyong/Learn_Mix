
ElementType Median( ElementType A[], int N )
{
	int i, j, max;
	ElementType t;

	for(i=0; i<N-1; i++) {
		max=i;
		for(j=i+1; j<N; j++)     /*��ѭ�����ҳ����ֵ���±�max */
			if (A[j]>A[max]) max=j;
            /* ���潫���ֵ����������еĵ�һ��Ԫ��A[i]���� */
			t=A[i];  A[i]=A[max];  A[max]=t;
	} /* �������  */

	return A[(N-1)/2];  
    /* �������±�Ϊ��N-1��/2λ�õ�Ԫ�ؾ��������е� N/2 ��Ԫ��*/
}
