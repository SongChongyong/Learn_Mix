
int  Length ( List  *PtrL )
{
	List  *p = PtrL;  /* pָ���ĵ�һ�����*/
	int  j = 0;

	while ( p ) { 
		p = p->Next; 
		j++;         /* ��ǰpָ����ǵ� j �����*/
	}   

	return  j;
}
