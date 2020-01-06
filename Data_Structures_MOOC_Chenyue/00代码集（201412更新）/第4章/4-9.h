
void InOrderTraversal( BinTree BT )
{
	BinTree T;
	Stack S = CreatStack( MaxSize ); /*��������ʼ����ջS*/

	T = BT;
	while( T || !IsEmpty(S) ){
		while(T){ /*һֱ���󲢽���;���ѹ���ջ*/
			Push(S,T); 
			T = T->Left; 
		}
		if( !IsEmpty(S) ){
			T = Pop(S); /*��㵯����ջ*/
            printf("%5d", T->Data); /*�����ʣ���ӡ���*/
			T = T->Right; /*ת��������*/
		}
	}
}
