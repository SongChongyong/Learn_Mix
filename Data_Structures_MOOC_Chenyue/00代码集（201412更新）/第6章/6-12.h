
void Floyd ( MGraph G,  PathMatrix *P[],  DistanceMatrix *D )
{   /*��������G�и��Զ���v��w֮������·��P[v][w]�����Ȩ����D[v][w] */
    /*��P[v][w]=u������u�Ǵ�v��w�����·���ؾ��Ķ��㡣*/
	int u, v, w, i;

	for( v = 0; v < G.n; ++v ) /* ���Զ���֮���ʼ��֪·�������� */
		for( w = 0; w < G.n; ++w ) {
			D[v][w] = G.Edges [v][w];
	        P[v][w] = v;  /* �����v��w��ֱ��·��*/
		}/*���������ֱ�ӵıߣ�D[v][w] = �ޣ�P[v][w] = vҲ�������*/
		for( u = 0; u < G.n; ++u )
			for( v = 0; v < G.n; ++v )
				for( w = 0; w < G.n; ++w )
					if ( D[v][u] + D[u][w] < D[v][w] ) {
						/*��v��u��w��һ��·������*/
						D[v][w] = D[v][u] + D[u][w];
						P[v][w] = u;
					}
}
