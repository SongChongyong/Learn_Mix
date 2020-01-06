
void LevelOrderTraversal ( BinTree BT )
{ 
	Queue Q; 
	BinTree T;

	if ( !BT ) return; /* ���ǿ�����ֱ�ӷ��� */
	
	Q = CreatQueue( MaxSize ); /*��������ʼ������Q*/
	AddQ( Q, BT );
	while ( !IsEmptyQ( Q ) ) {
		T = DeleteQ( Q );
		printf("%d\n", T->Data); /*����ȡ�����еĽ��*/
		if ( T->Left )   AddQ( Q, T->Left );
		if ( T->Right )  AddQ( Q, T->Right );
	}
}
