
ElementType Pop( Stack *PtrS )
{
    if ( PtrS->Top == -1 ) {
		printf("��ջ��");
		return ERROR; /* ERROR��ElementType������ֵ����־���� */
	}
	else 
		return ( PtrS->Data[(PtrS->Top)--] );
}
