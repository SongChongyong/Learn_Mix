
void  Dijkstra ( MGraph G��int v0,  int *P,  int *D )
{   /*��������G��v0���㵽���ඥ������·��P[]����·������D[]*/
    /*��P[v]==w����w�Ǵ�v0�� v��ǰ������·���ϵĶ���*/
    /*Final[v] ΪTRUE���ҽ���v��S�����Ѿ���ô�v0��v�����·��*/
    /*����INFINITYΪ����Ȩֵ���ܵ����ֵ*/

	int  Final[MaxVertexNum], v, w, i, j, min;

	for ( v = 0; v < G.n; ++v ) { /* ��ʼ�� */
		Final[v] = FALSE;  D[v] = G.Edges[v0][v];
		for ( w = 0; w < G.n; ++w ) 
			if ( D[w] < INFINITY )  P[w] = v0;  /* �踸����v0  */
	}
	D[v0] = 0;  Final[v0] = TRUE;  /* ��ʼ״̬��v0��������S�� */

	/*��ʼ��ѭ����ÿ�����v0��ĳ��v ��������·��������v���� */
	for( i = 1; i < G.n; ++i ) {
		min = INFINITY;   /* minΪ��ǰ��֪��v0������������ */
		for ( w = 0; w < G.n; ++w)
			if ( !Final[w] )  /* w������V��S�� */
				if (D[w] < min) {
					v = w;  min = D[w];
				} /* Ѱ�����·������v */
			if( min < INFINITY )
				Final[v] = TRUE; /* ��v0���������v����S���� */
			else  break; /* �����Ƿ���ͨͼ��������  */
		for( w = 0; w < G.n; ++w ) /* ���µ�ǰ���·��*/
			if ( !Final[w] && (min+G.Edges[v][w] < D[w]) ) {
				D[w] = min+G.Edges[v][w]; 
				P[w] = v; 
			}
	} /* ������ѭ�� */
}
