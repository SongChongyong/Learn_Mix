
void Adjust( ElementType A[], int i, int N )
{	/* ��A[]�е�ǰN��Ԫ�شӵ�i��Ԫ�ؿ�ʼ����Ǩ�Ƶ��� */
	int Child;
	ElementType temp;

	for( temp = A[i]; (2*i + 1) < N; i = child){
		Child = (2*i + 1);  /* ���ӽڵ� */
		if ( (Child != N-1) && A[Child + 1] > A[Child])
			Child++; /* Childָ�������ӽ��Ľϴ��� */
		if( temp < A[Child] )
			A[i] = A[Child];  /* �ƶ�ChildԪ�ص��ϲ� */
		else	break;
	}
	A[i] = temp;    /*��temp�ŵ���ǰλ�á�*/
}

void HeapSort( ElementType A[], int N ) 
{   /* ������ */
	int i;
	ElementType temp;

    /* ��������*/
	for( i = (N-1)/2; i >= 0; i-- )  /*���ж��ӵ����һ����㿪ʼ*/
		Adjust(A, i, N); 
	for( i = N-1; i > 0; i-- ){
        /* ���Ѷ�Ԫ��A[0]�뵱ǰ�ѵ����һ��Ԫ��A[i]��λ */
		temp = A[0]; A[0] = A[i]; A[i] = temp;
        /* ����i��Ԫ�ص��¶ѴӸ�������¹��˵��� */
		Adjust(A, 0, i);
	}
}
