
void ToplogicalSort ( Graph G, int TopNum[ ] )
{
    int Counter;    /* ������� */
    int v, w;

    int *InDegree = (int *)malloc( G.n * sizeof(int) );
    GetInDegree(G, InDegree);   /* ����ͼG�и��������� */
    for( Counter = 0; Counter < G.n; Counter++ ) {
        v = FindNewVertexOfDegreeZero( );   
        /* �������Ϊ0�Ķ��㡣���Ҳ������Ϊ0�Ķ��㣬����NotAVertex */
        if ( v == NotAVertex ) {
             Error( "ͼ���ڻ�·");
             break;
        }
        TopNum[v] = Counter;
        for( G�й���v ��ÿ���ڽӵ�w )
           Indegree[w]--;  /* �붥��v�����ĸ��������ȼ�1 */
    }
}
