
Position FindMax( BinTree BST )
{
    if( !BST ) 
        while( BST->Right )
            BST = BST->Right; /*���ҷ�֧�������ң�ֱ������Ҷ���*/
    return BST;
}
