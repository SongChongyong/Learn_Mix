
void Show( HashTable H, double percent )
{
	        int diffwordcount = 0;    /* ��ͬ�ĵ������� */
            int maxf = 0;               /* ���Ĵ�Ƶ */
			int *diffwords;            /* ÿ����Ƶ�еĲ�ͬ�������� */
			int maxCollision = 0;     /* ����ͻ��������ʼ��Ϊ0 */
			int minCollision = 100;   /* ��С��ͻ��������ʼ��Ϊ100 */
			Position L;
			int i, j, k, count = 0;

/* 1 */     for( i = 0; i < H->TableSize; i++ ) {
			    /* ����ͬ�ĵ������� */
/* 2 */			diffwordcount += H->TheLists[ i ].Times;
				if( maxCollision < H->TheLists[ i ].Times )
					maxCollision = H->TheLists[ i ].Times;
				if( minCollision > H->TheLists[ i ].Times )
					minCollision = H->TheLists[ i ].Times;
				/* �������Ĵ�Ƶ */
/* 3 */			L = H->TheLists[ i ].Next; 
/* 4 */			while( L ){
/* 5 */				if( maxf < L->Times) maxf = L->Times;
/* 6 */				L = L->Next;
				}
			}
 
/* 7 */    printf(" ���� %d ����ͬ�ĵ��ʣ���Ƶ����� %d��\n", diffwordcount, maxf);
/* 8 */    printf(" ����ͻ������ %d, ��С��ͻ������ %d.\n", maxCollision, minCollision);
			
            /* ����ÿ����Ƶ�ȼ�ӵ�еĲ�ͬ�������� */
            /* �������Ĵ�Ƶ������һ���������� */
/* 9 */		diffwords = malloc( sizeof( int ) * ( maxf+1 ) );
/* 10 */	if(diffwords == NULL )
/* 11 */       FatalError( "�ռ����!!!" );

            /* ͳ�ƴ�Ƶ�ֱ��1��maxf�ĵ������� */
			for( i = 0; i <= maxf; i++ ) 
			    diffwords[ i ] = 0;   
/* 12 */	for( i = 0; i < H->TableSize; i++ ) {
/* 13 */		L = H->TheLists[ i ].Next; 
/* 14 */		while( L ){
/* 15 */			diffwords[ L->Times ]++; /* �ô�Ƶ����һ������ */
/* 16 */			L = L->Next;
				}
			}

            /* ���ض��Ĵ�Ƶ��ʹ�ô��ڵ��ڸô�Ƶ�ĵ����ܺͳ��������ı��� */
/* 17 */   count = diffwords[ maxf ];
/* 18 */   i = maxf;
/* 19 */   while( i > 1 && count <  diffwordcount * percent)
/* 20 */		count += diffwords[ --i ]; /* ������һ����Ƶ�ĵ������� */
            
/* 21 */   for( j = maxf; j >= i; j-- ) /* ����Ƶ�Ӵ�С������� */
/* 22 */   for( k = 0; k < H->TableSize; k++ ) {
/* 23 */		L = H->TheLists[ k ].Next; 
/* 24 */		while( L ){
/* 25 */			if( j == L->Times) /* ����õ��ʼ���Ƶ */
/* 26 */				printf(" %-15s : %d \n", L->Element ,L->Times);
/* 27 */			L = L->Next;
				}
			}
            
/* 28 */    free( diffwords );
}

