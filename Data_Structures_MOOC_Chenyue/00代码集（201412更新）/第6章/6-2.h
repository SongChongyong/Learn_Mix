
void  CreateMGraph ( MGraph *G )
{  
		int  i, j, k, w;

		G-> GType = UN;    /* Undirected Network  ������ͼ  */
		printf( "�����붥�����ͱ���(�����ʽΪ:������, ����):\n" );
		scanf( "%d, %d",&(G->n), &(G->e) ); /* ���붥�����ͱ��� */
		printf("�����붥����Ϣ(�����ʽΪ:�����<CR>):\n");
		for ( i = 0; i < G->n; i++ ) 
			scanf( "%c",&(G-> Vertices[i]) );
			/*  ���붥����Ϣ�����������  */

/*1*/	for ( i = 0; i < G->n; i++ )
/*2*/      for ( j = 0; j < G->n; j++ )  
/*3*/          G->Edges[i][j] = INFINITY; /* ��ʼ���ڽӾ��� */
        printf( "������ÿ���߶�Ӧ�������������ź�Ȩֵ�������ʽΪ:i, j, w:\n" );
/*4*/	for ( k = 0; k < G->e; k++ ) {
			scanf("%d,%d,%d ",&i, &j, &w);
			/* ����e�����ϵ�Ȩ�������ڽӾ��� */
/*5*/		G->Edges[i][j] = w; 
/*6*/		G->Edges[j][i] = w; /* ��Ϊ������ͼ���ڽӾ����ǶԳƵ� */
        }
}
