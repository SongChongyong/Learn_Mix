
BinTree CreatBinTree( )
{
	int Data;
	BinTree BT, T;
	Queue Q = CreatQueue( MaxSize ); /*����һ������*/
	
	scanf("%d", &Data); /* ������1����㣬������� */
	if( Data ){ /*�������㵥Ԫ����������ַ���*/
		BT =(BinTree) malloc(sizeof(BinTree));
		BT->Data = Data;
		AddQ( Q, BT );
	}
	else return NULL; /* ����1�����ݾ���0�����ؿ��� */

	while( !IsEmptyQ( Q ) ){
		T = DeleteQ( Q ); /*�Ӷ�����ȡ��һ����ַ*/
		scanf("%d", &Data); /* ����T������ */
		if( !Data ) T->Left = NULL;
		else {  /*�����½�㣬��Ϊ���ӽ�����ӣ��½�����*/
			T->Left = (BinTree) malloc(sizeof(BinTree));
			T->Left->Data = Data;
			AddQ( Q, T->Left );
		}
		scanf("%d", &Data); /* ����T���Һ��� */
		if( !Data ) T->Right = NULL;
		else {  /*�����½�㣬��Ϊ���ӽ���Һ��ӣ��½�����*/
			T->Right = (BinTree) malloc(sizeof(BinTree));
			T->Right->Data = Data;
			AddQ( Q, T->Right );
		}
	} /* ����while */
	return BT;
}
