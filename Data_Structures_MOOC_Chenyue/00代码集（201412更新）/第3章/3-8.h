
List *Insert( ElementType X, int i, List *PtrL )
{
	List  *p, *s;

	if ( i == 1 ) {     /* �½������ڱ�ͷ */
		s = (List *)malloc(sizeof(List)); /*���롢��װ���*/
		s->Data = X; 
		s->Next = PtrL;
		return s;      /*�����±�ͷָ��*/
    }
    p = FindKth( i-1, PtrL );   /* ���ҵ�i-1����� */
    if ( p == NULL ) {  /* ��i-1�������ڣ����ܲ��� */
		printf("����i��");
		return NULL; 
	}
	else {
		s = (List *)malloc(sizeof(List)); /*���롢��װ���*/
		s->Data = X; 
		s->Next = p->Next;     /*�½������ڵ�i-1�����ĺ���*/
		p->Next = s; 
		return PtrL;
	}
}
