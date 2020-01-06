
int Kruskal( int N, int M )
{   /* �������ͱߵ���Ŀ��������С��������Ȩ�� */
	int EdgeN = 0;     /* �������߼��ϼ����� */
	int Cost = 0;      /* ��С������Ȩ���ۼ� */
	int NextEdge = M; /* ��һ����СȨ�رߵ�λ�ã���ʼ��Ϊ�ܱ��� */

	InitializeVSet( N );  /* ��ʼ����㲢�鼯VSet */
	InitializeESet( M );  /* ���ݱߵ�Ȩ�ؽ�����С��ESet */
	while (EdgeN < N-1) { /* ���ռ��ı߲����Թ�����ʱ */
		NextEdge = GetEdge(NextEdge); /* �ӱ߼��еõ���С�ߵ�λ�� */
		if (NextEdge < 0)  break; /* �߼��ѿ� */
		if ( CheckCycle( ESet[NextEdge].V1, ESet[NextEdge].V2 ) ) {
        /* ����ñߵļ��벻���ɻ�·�������˽�㲻����ͬһ��ͨ�� */
			Cost += ESet[NextEdge].W; /* ����ñߣ��ۼ�Ȩ�� */
			EdgeN++; /* �������б�����1 */
		}
	}
	if (EdgeN < N-1) Cost = -1; /* ���ռ��ı߲����Թ������������ź� */
	return Cost;
}
