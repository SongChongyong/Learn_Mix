
Position IterFind( ElementType X, BinTree BST )
{
    while( BST ) {
        if( X > BST->Data )
			BST = BST->Right;    /*�����������ƶ�����������*/
        else
            if( X < BST->Data )
				BST = BST->Left; /*�����������ƶ�����������*/
            else /* X == BST->Data */
                return BST; /*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
    }
    return NULL; /*����ʧ��*/
}
