
MaxHeap Create( int MaxSize )
{   /* ��������ΪMaxSize�Ŀյ����� */
	MaxHeap H = malloc( sizeof( struct HeapStruct ) );
	H->Elements = malloc( (MaxSize+1) * sizeof( ElementType ) );
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = MaxData; /* ����"�ڱ�"Ϊ���ڶ������п���Ԫ�ص�ֵ*/

	return H;
}
