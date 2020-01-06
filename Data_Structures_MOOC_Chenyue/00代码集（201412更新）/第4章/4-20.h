
typedef struct AVLTreeNode *AVLTree;
typedef struct AVLTreeNode{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
}

AVLTree AVL_Insertion ( ElementType X, AVLTree T )
{ /* ��X����AVL��T�У����ҷ��ص������AVL�� */
	if ( !T ) { /* ��������������½�����һ�������� */
		T = malloc(sizeof(struct AVLTreeNode));
		T->Data = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	} /* if (�������) ���� */

	else if (X < T->Element) { /* ����T�������� */
		T->Left = AVL_Insertion(X, T->Left);
        if (GetHeight(T->Left) - GetHeight(T->Right) == 2 )
			/* ��Ҫ���� */
            if (X < T->Left->Data) 
               T = SingleLeftRotation(T);      /* ���� */
            else 
               T = DoubleLeftRightRotation(T); /* ��-��˫�� */
	} /* else if (����������) ���� */
    
	else if (X > T->Element) { /* ����T�������� */
		T->Right = AVL_Insertion(X, T->Right);
        if (GetHeight(T->Left) - GetHeight(T->Right) == -2 )
			/* ��Ҫ���� */
            if (X > T->Right->Data) 
               T = SingleRightRotation(T);     /* �ҵ��� */
            else 
               T = DoubleRightLeftRotation(T); /* ��-��˫�� */
	} /* else if (����������) ���� */

    /* else X == T->Data��������� */

	T->Height = Max(GetHeight(T->Left),GetHeight(T->Right))+1;
	/*��������*/
	
	return T;
}
