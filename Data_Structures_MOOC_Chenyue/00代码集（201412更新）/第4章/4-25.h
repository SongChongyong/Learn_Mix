
ElementType DeleteMax( MaxHeap H )
{   /* ������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ����� */
    int Parent, Child;
    ElementType MaxItem, temp;

    if ( IsEmpty(H) ) {
        printf("������Ϊ��");
        return;
    }

    MaxItem = H->Elements[1]; /* ȡ����������ֵ */
    /* �����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²��� */
    temp = H->Elements[H->Size--];
	for( Parent=1; Parent*2<=H->Size; Parent=Child ) {
		Child = Parent * 2;
        if( (Child!= H->Size) && (H->Elements[Child] < H->Elements[Child+1]) )
            Child++;  /* Childָ�������ӽ��Ľϴ��� */
        if( temp >= H->Elements[Child] ) break;
		else  /* �ƶ�tempԪ�ص���һ�� */
			H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;

    return MaxItem;
} 
