
void  DFS( Graph G,  int V )
{   /* �ӵ�V����������ݹ��������ȱ���ͼG */
	Visited[V] = TRUE;
	VisitFunc(V);  /* ���ʵ�V������ */
	for( W = FirstAdjV(G, V);  W;  W = NextAdjV (G, V, W) )
		if ( !Visited[W] )
			DFS(G, W);   /* ��V����δ���ʵ��ڽӶ���W�ݹ����DFS */
}
