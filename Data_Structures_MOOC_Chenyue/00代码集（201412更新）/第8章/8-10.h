
int CountConnectedComponents( Graph G )
{
	/* ����ͼG����ͨ���ĸ��� */
	Vertex V;

	InitializeVisited( G->NumOfVertices );
	cnt = 0;
	for ( V=0; V<G->NumOfVertices; V++ ) {
		if ( !Visited[V] ) {
			Dfs( V, G );
			cnt ++;
		}
	}
	return cnt;
}
