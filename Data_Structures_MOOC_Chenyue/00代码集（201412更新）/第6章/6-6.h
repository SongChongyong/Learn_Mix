
void  DFS_ALG( ALGraph  *G )
{   
	int i;
         
	for ( i = 0; i < G->n; i++ )
		Visited[ i ] = FALSE;  /* ��־������ʼ�� */
	for ( i = 0; i < G->n; i++ )
		if ( !Visited[i] ) /* ��viδ�����ʹ� */
			DFS( G, i ); /* ��Vi��ʼDFS����һ����ͨ���� */
}

void  DFS( ALGraph *G,  int i )
{   /* ��ViΪ��������ڽӱ�洢��ͼG����DFS���� */
	EdgeNode *W;

	printf( "visit vertex:V%c\n", G->adjlist[i].Vertex );
	/* �൱��VisitFunc(Vi)�������ʶ���Vi */
	Visited[i] = TRUE;   /* ���Vi�ѷ��� */
	for(W = G->adjlist[i].FirstEdge;  W;  W = W->Next ) 
		if ( !Visited[ W->AdjV ] )
			DFS( G, W->AdjV );
}
