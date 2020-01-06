
Position Find( ElementType X, BinTree BST )
{
	if( !BST ) return NULL; /*����ʧ��*/
	
	if( X > BST->Data ) 
		return Find( X, BST->Right );    /*���������м�������*/
	else
		if( X < BST->Data ) 
			return Find( X, BST->Left ); /*���������м�������*/
		else /* X == BST->Data */
			return BST;  /*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
}
