
LinkStack *CreateStack() 
{   /* ����һ����ջ��ͷ��㣬���ظý��ָ�� */
	LinkStack *S;

	S = malloc( sizeof( struct Node ));
	S->Next = NULL;
	return S;
}

int IsEmpty( LinkStack *S )  
{   /*�ж϶�ջS�Ƿ�Ϊ�գ���Ϊ�պ�����������1�����򷵻�0 */
	return ( S->Next == NULL );
}

void Push( ElementType item, LinkStack *S )    
{   /* ��Ԫ��itemѹ���ջS  */
	struct Node *TmpCell;

	TmpCell = malloc( sizeof( struct Node ) );
	TmpCell->Element = item;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}

ElementType Pop( LinkStack *S )  
{   /* ɾ�������ض�ջS��ջ��Ԫ�� */
	struct Node *FirstCell;
	ElementType TopElem;

	if( IsEmpty( S ) ) {
		printf("��ջ��"); 
		return NULL;
	}
	else {
		FirstCell = S->Next; 
		S->Next = FirstCell->Next;
		TopElem = FirstCell ->Element;
		free(FirstCell);
		return TopElem;
	}
}
