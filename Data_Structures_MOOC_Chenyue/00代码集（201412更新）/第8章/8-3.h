
Queue CreateQueue( int MaxElements )
{   /* ��������MaxElements��Ԫ����Ϣ�Ķ��� */
	Queue Q;
	struct People X;
	int i;

	Q = malloc( sizeof( struct QueueRecord ) );
	Q->Customer = malloc( sizeof( struct People ) * MaxElements );
	Q->size = 0;
	Q->front = 0;
	Q->rear = -1;
	for ( i=0; i<MaxElements; i++ ) {
		scanf("%d %d", &X.T, &X.P);
		AddQ( Q, X);
	}

	return Q;
}
