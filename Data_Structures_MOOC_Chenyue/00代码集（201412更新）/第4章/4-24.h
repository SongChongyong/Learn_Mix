
void Insert( MaxHeap H, ElementType item )
{ /* ��Ԫ��item ��������H������H->Elements[0]�Ѿ�����Ϊ�ڱ� */
    int i;
 
	if ( IsFull(H) ) { 
        printf("��������");
        return;
    }

	i = ++H->Size; /* iָ��������е����һ��Ԫ�ص�λ�� */
	for ( ; H->Elements[i/2] < item; i/=2 )
        H->Elements[i] = H->Elements[i/2]; /* ���¹��˽�� */
	H->Elements[i] = item; /* ��item ���� */
}
