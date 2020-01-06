
HashTable  InitializeTable( int TableSize )
{
            HashTable H;
            int i;

/* 1*/      if( TableSize < MinTableSize ){
/* 2*/          Error( "ɢ�б�̫С" );
/* 3*/          return NULL;
            }

            /* ����ɢ�б� */
/* 4*/      H = malloc( sizeof( struct HashTbl ) );
/* 5*/      if( H == NULL )
/* 6*/          FatalError( "�ռ����!!!" );

/* 7*/      H->TableSize = NextPrime( TableSize );

/* 8*/      H->TheCells = malloc( sizeof( Cell ) * H->TableSize );
/* 9*/      if( H->TheCells == NULL )
/*10*/          FatalError( "�ռ����!!!" );

/*11*/      for( i = 0; i < H->TableSize; i++ )
/*12*/          H->TheCells[ i ].Info = Empty;

/*13*/      return H;
}
