
void CreateALGraph( ALGraph *G )
{
	int i,j,k;
	EdgeNode *edge;

	G-> GType = DG;  /* Directed Graph  ����ͼ  */
	printf( "�����붥�����ͱ���(�����ʽΪ:������,����)��\n" );
	scanf( "%d,%d", &(G->n), &(G->e) );      /* ���붥�����ͱ��� */ 
	printf( "�����붥����Ϣ(�����ʽΪ:�����<CR>)��\n" );
	for ( i=0; i < G->n; i++ ) {   /* ������n������Ķ���� */
		scanf( " %c", &(G->adjlist[i].vertex) );  /* ���붥����Ϣ */
		G->adjlist[i].firstedge = NULL; /* ����ı߱�ͷָ����Ϊ�� */
	}
	printf( "������ߵ���Ϣ(�����ʽΪ: i, j <CR>)��\n" );
	for ( k=0; k < G->e; k++ ){   /* �����߱� */
		scanf( "\n%d,%d", &i, &j); /* �����<vi,vj>�Ķ����Ӧ���*/
		edge = (EdgeNode*) malloc( sizeof( EdgeNode ) );
		/* �����±߱���edge */
		edge->AdjV = j; /* �ڽӵ����Ϊj */
		edge->Next = G->adjlist[i].FirstEdge;
		/* ���±߱���edge���뵽����vi�ı߱�ͷ�� */
		G->adjlist[i].FirstEdge = edge;
		/* ��������ͼ����Ҫ����һ����㣬������ʾ��< vj, vi>  */
	}
}
