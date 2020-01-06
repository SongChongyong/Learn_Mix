
typedef struct Node *PtrToNode;
typedef PtrToNode List;
struct Node {
       int Key[MaxDigit];
       PtrToNode Next;
};

List RadixSort( List A )
{   /* �������� */
	List Bucket[Radix]; /* ����Radix��Ͱ */
	List Rear[Radix];   /* ��Ҫ��¼ÿ��Ͱ�����βԪ��λ�� */
	int i, j, Digit;

	for ( i=MaxDigit-1; i>=0; i-- ){ /* �����λ�ؼ��ֿ�ʼ */
		for ( j=0; j<Radix; j++ )
			Bucket[j] = Rear[j] = NULL; /* ��ʼ�� */
		while (A) { /* ���ؼ�����һ���䵽Ͱ */
			Digit = A->Key[i]; /* ȡ����ǰ�ؼ���λ */
			if ( !Bucket[Digit] ) /* ����Ӧ��Ͱ�ǿյ� */
				Bucket[Digit] = A; /* �����Ͱ */
			else  Rear[Digit]->Next = A; /* �������Ͱβ */
			Rear[Digit] = A; /* ����βָ�� */
			A = A->Next;
		} /* ����while�������*/
		for ( j=Radix-1; i>=0; j-- ){ /* ������Ͱ��Ԫ���ռ����� */
			if ( Bucket[j] ) { 
				Rear[j]->Next = A;
				A = Bucket[j];
			}
		} /* ����for�ռ����� */
	}
	return A;
}
