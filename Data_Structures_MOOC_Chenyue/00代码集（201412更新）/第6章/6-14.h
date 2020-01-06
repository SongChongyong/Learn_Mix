
void ToplogicalSort ( Graph G, int TopNum[ ] )
{
     Queue queue;
     int Counter = 0;
     int v, w;

     int *InDegree = (int *)malloc( G.n * sizeof(int) );
     GetInDegree(G, InDegree);   /* ����ͼG�и��������� */

     /* �����ն��� */
     queue = CreateQueue( G.n );
     for( v = 1; v <= G.n; v++ )
          if( InDegree[v]==0 )
              AddQ( queue, v );
      while( ! IsEmptyQ(queue) ) {
           v = DeleteQ( queue );
           TopNum[v] = ++Counter;      /* ����������������� */
           for( G�й���v ��ÿ���ڽӵ�w )
              if( --InDegree[ w ] == 0 )
                  AddQ( queue, w );

      }
      if( Counter != G.n )
           Error( "ͼ���ڻ�·" );
      DisposeQueue(queue);    /* �ͷŶ��пռ�*/
	  free(InDgree);
}
