
int Find( ElementType X, List *PtrL )
{
	int i = 0;

	while( i <= PtrL->Last && PtrL->Data[i]!= X )
		i++;
	if ( i > PtrL->Last )  return -1; /* ���û�ҵ�������-1 */
	else  return i;  /* �ҵ��󷵻ص��Ǵ洢λ�� */
}
