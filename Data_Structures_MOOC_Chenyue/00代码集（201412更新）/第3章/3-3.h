
void Insert( ElementType X, int i, List *PtrL )
{
	int j;

	if ( PtrL->Last == MAXSIZE��1) {
		/* ��ռ����������ܲ���*/
		printf("����"); 
		return; 
	}  
	if ( i < 1 || i > PtrL->Last+2) { /*������λ�õĺϷ���*/
		printf("λ�ò��Ϸ�");
		return; 
	} 
	for( j = PtrL->Last; j >= i-1; j-- )
		PtrL->Data[j+1] = PtrL->Data[j]; /*�� �� ˳������ƶ�*/
	PtrL->Data[i-1] = X;  /*��Ԫ�ز���*/
	PtrL->Last++;          /*Last��ָ�����Ԫ��*/
	return; 
} 
