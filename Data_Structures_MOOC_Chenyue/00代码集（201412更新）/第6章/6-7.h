
void  BFS ( Graph G )
{   /* ��������ȱ���ͼG��ʹ�ø�������Q�ͷ��ʱ�־����Visited */
	Queue  *Q; 	
	VertexType  U, V, W;
		    
	for ( U = 0; U < G.n; ++U )  
		Visited[U] = FALSE;
	Q = CreatQueue( MaxSize ); /* �����ն���Q */
	for ( U = 0; U<G.n; ++U )
		if (!Visited[U] ) { /* ��U��δ���� */
			Visited[U] = TRUE; 
			VisitFunc(U);  /* ����U */
			AddQ (Q, U);    /* U����� */
			while ( ! IsEmptyQ(Q) ) {
				V = DeleteQ( Q );  /*  ��ͷԪ�س��Ӳ���ΪV */
				for( W = FirstAdjV(G, V);  W;  W = NextAdjV(G, V, W) )
					if ( !Visited[W] ) {
						Visited[W] = TRUE;
						VisitFunc (W);      /* ����W */
						AddQ (Q, W);
					}
			} /* while����*/
		} /* ������U��ʼ��BFS */
}
