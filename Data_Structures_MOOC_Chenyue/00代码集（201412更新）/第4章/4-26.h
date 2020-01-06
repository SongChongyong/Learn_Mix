
MaxHeap BuildMaxHeap( MaxHeap H )
{   /* �����������H->Size��Ԫ���Ѿ�����H->Elements[]��     */
    /* ��������H->Elements[]�е�Ԫ�ص�����ʹ�������ѵ������� */
	int Parent, Child, i;
	ElementType temp;

	for( i = H->Size/2; i>0; i-- ){ /*�����һ�����ĸ���㿪ʼ */
		temp = H->Elements[i];
		for( Parent=i; Parent*2<=H->Size; Parent=Child ) { /* ���¹��� */
			Child = Parent * 2;
            if( (Child!= H->Size) && (H->Elements[Child] < H->Elements[Child+1]) )
                Child++;  /* Childָ�������ӽ��Ľϴ��� */
            if( temp >= H->Elements[Child] ) break;
			else  /* �ƶ�tempԪ�ص���һ�� */
				H->Elements[Parent] = H->Elements[Child];
		} /* �����ڲ�forѭ������H->Elements[i]Ϊ���������ĵ��� */
		H->Elements[Parent] = temp;
	}

	return H;
}
