
Position FindMin( BinTree BST )
{
    if( !BST ) return NULL; /*�յĶ���������������NULL*/
    else
        if( !BST->Left ) return BST; /*�ҵ�����Ҷ��㲢����*/
        else
            return FindMin( BST->Left ); /*�����֧��������*/
}
