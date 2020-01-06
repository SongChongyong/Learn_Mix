
void  SixDegree_BFS( MGraph  G , VertexType  Start )
{   /* ������벻����SIX�Ľ��ٷֱȣ� ����G->adjlist[Start].percent  */
    struct QElementType {
		VertexType v;
		int layer
	} qe; 
    VertexType  v;
	EdgeNode *edge;
	LinkQueue Q; 
	long int VisitCount = 1;   /* ��¼·������<=SIX�Ķ����� */
     
	Initialize( &Q ); /* �ÿյĶ���Q */
	G->adjlist[Start].Visited = 1;
	qe.v = Start; qe.layer = 0; /* �����0�� */
	AddQ( &Q, qe ); /* qe����� */
	while ( !IsEmptyQ(&Q) ) { /* ���зǿ�ѭ�� */
		qe = DeleteQ(&Q);
		v = qe.v;
		for( edge=G->adjlist[v].FirstEdge; edge; edge=edge->Next )
			if ( !G->adjlist[edge->AdjV].Visited ) {/* ����v����δ���ʵ��ڽӶ��� */
				G->adjlist[edge->AdjV].Visited = 1;  /* �����Ϊ�������ڵĶ��� */
				VisitCount++ ;        /* ����·������<=SIX�Ķ����� */
				if( ++qe.layer < SIX ) {/* �����������ڵĶ����ٽ��� */
					qe.v = edge->AdjV;
					AddQ(&Q, qe);
				}
				qe.layer--;   /* �ָ�qe�Ĳ��� */
			} /* ����if��for */
     } /* ����whileѭ�� */
     DestroyQueue( Q );
     G->adjlist[Start].percent = (float) 100.0 * VisitCount / G->n;
}
