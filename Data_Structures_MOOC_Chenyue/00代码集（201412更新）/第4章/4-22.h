
AVLTree DoubleLeftRightRotation ( AVLTree A )
{ /* ע�⣺A������һ�����ӽ��B����B������һ�����ӽ��C */
  /* ��A��B��C����ͼ4.38��ʾ�����ε����������µĸ����C */
      
  A->Left = SingleRightRotation(A->Left); /*��B��C���ҵ�����C������*/

  return SingleLeftRotation(A); /*��A��C��������C������*/
}
