
void Delete( int  i, List *PtrL )
{
	int  j;

	if( i < 1 || i > PtrL->Last+1 ) { /*���ձ�ɾ��λ�õĺϷ���*/
		printf ("�����ڵ�%d��Ԫ��", i ); 
		return ; 
	}
	for( j = i; j <= PtrL->Last; j++ )
		PtrL->Data[j-1]= PtrL->Data[j]; /*��a[i+1]��a[n]˳����ǰ�ƶ�*/
	PtrL->Last--;    /*Last��ָ�����Ԫ��*/
	return;   
}
