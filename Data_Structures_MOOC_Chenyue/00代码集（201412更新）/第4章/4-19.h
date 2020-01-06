
BinTree Delete( ElementType X, BinTree BST ) 
{ 
    Position Tmp; 

    if( !BST ) 
        printf("Ҫɾ����Ԫ��δ�ҵ�"); 
    else 
        if( X < BST->Data ) 
            BST->Left=Delete( X, BST->Left);       /* �������ݹ�ɾ�� */
        else
            if( X > BST->Data ) 
                BST->Right=Delete( X, BST->Right); /* �������ݹ�ɾ�� */
            else /*�ҵ�Ҫɾ���Ľ�� */ 
                if( BST->Left && BST->Right ) {
                    /*��ɾ����������������ӽ�� */ 

                    Tmp = FindMin( BST->Right ); 
                    /*��������������С��Ԫ�����ɾ�����*/

                    BST->Data = Tmp->Data; 

                    BST->Right = Delete( BST->Data, BST->Right);
					/*��ɾ��������������ɾ����СԪ��*/
                } 
                else { /*��ɾ�������һ�������ӽ��*/
                    Tmp = BST; 
                    if( !BST->Left )       /* ���Һ��ӻ����ӽ�� */
                        BST = BST->Right; 
                    else if( !BST->Right ) /* �����ӻ����ӽ�� */
                        BST = BST->Left;
                    free( Tmp );
                }
    return BST;
}
