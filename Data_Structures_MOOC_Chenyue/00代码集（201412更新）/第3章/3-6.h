
List  *FindKth( int K, List *PtrL )
{
	List  *p = PtrL;
	int  i = 1;

	while (p !=NULL && i < K ) {
		p = p->Next;
		i++;  
	}
	if ( i == K ) return p; /* �ҵ���K��������ָ�� */
	else  return NULL;     /* ���򷵻ؿ� */
}
