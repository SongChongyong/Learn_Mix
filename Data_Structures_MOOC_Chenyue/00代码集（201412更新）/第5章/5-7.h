
HashTable  InitializeTable( int TableSize )
{
            HashTable H;
            int i;

/* 1*/      if( TableSize < MinTableSize ) {
/* 2*/          Error( "ɢ�б�̫С" );
/* 3*/          return NULL;
            }

            /* ���·���ɢ�б� */
/* 4*/      H = malloc( sizeof( struct HashTbl ) );
/* 5*/      if( H == NULL )
/* 6*/          FatalError( "�ռ����!!!" );
/* 7*/      H->TableSize = NextPrime( TableSize );
            /* NextPrimeȷ��һ�� >= TableSize����������������5.6�� */

            /* ���·����ͷ���� */
/* 8*/      H->TheLists = malloc(sizeof(struct ListNode )*H->TableSize );
/* 9*/      if( H->TheLists == NULL )
/*10*/          FatalError( "�ռ����!!!" );

            /* �������ñ�ͷ��� */
/*11*/      for( i = 0; i < H->TableSize; i++ ) {
/*12*/          H->TheLists[ i ].Element[0] = '\0';
/*13*/			H->TheLists[ i ].Times = 0; /* �������н������ */
/*14*/          H->TheLists[ i ].Next = NULL;
            }

/*15*/      return H;
}
