
List *Delete( int  i, List *PtrL )
{
	List  *p, *s;

	if ( i == 1 ) {            /* ɾ����ĵ�һ����� */
		s = PtrL;              /*sָ���1�����*/
		PtrL = PtrL->Next;     /*��������ɾ��*/
		free(s);               /*�ͷű�ɾ����� */
		return PtrL;
	}
	p = FindKth( i-1, PtrL );  /*���ҵ�i-1�����*/
    if ( p == NULL ) { 
		printf("��%d����㲻����", i-1);
		return NULL; 
	}
	else  if ( p->Next == NULL ){ 
		printf("��%d����㲻����", i);
		return NULL; 
	}
	else  {
		s = p->Next;          /*sָ���i�����*/
		p->Next = s->Next;    /*��������ɾ��*/
		free(s);              /*�ͷű�ɾ����� */
		return PtrL;
	}
}
