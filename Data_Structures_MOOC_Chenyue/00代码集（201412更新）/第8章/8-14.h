
void MinHeap( int i, int M )
{   /* ��M��Ԫ�ص���������ESet[i]Ϊ�����Ӷѵ���Ϊ��С�� */
	int child;
	struct EdgeType temp;

	temp = ESet[i];
	for(; (2*i + 1) < M; i = child){
		child = 2*i+1;
		if(child != M-1 && ESet[child + 1].W < ESet[child].W)
			child++;
		if(temp.W > ESet[child].W) 
			ESet[i] = ESet[child];
		else
			break;
	}
	ESet[i] = temp;  
}

int GetEdge( int CurrentSize )
{   /* ������ǰ�ѵĴ�СCurrentSize������ǰ��С��λ�õ����������� */
	struct EdgeType temp;

    /* ����С���뵱ǰ�ѵ����һ��λ�õı߽��� */
	temp = ESet[0];
	ESet[0] = ESet[CurrentSize-1];
	ESet[CurrentSize-1] = temp;  
    /* ��ʣ�µı߼�����������С�� */
	MinHeap(0, CurrentSize-1);

	return CurrentSize-1; /* ������С������λ�� */
}
