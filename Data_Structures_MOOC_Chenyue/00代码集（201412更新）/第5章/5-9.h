
void InsertAndCount( ElementType Key, HashTable H )
{
            Position Pos, NewCell;
            List L;

/* 1*/      Pos = Find( Key, H );
/* 2*/      if( Pos ) /* �ؼ����ҵ� */
			     Pos->Times++;
			else { /* �ؼ���δ�ҵ� */
/* 3*/          NewCell = malloc( sizeof( struct ListNode ) );
/* 4*/          if( NewCell == NULL )
/* 5*/              FatalError( "�ռ����!!!" );
                 else{
/* 6*/              L = &(H->TheLists[ Hash( Key, H->TableSize ) ]);
/* 7*/              NewCell->Next = L->Next;      /* �����һ�����  */
/* 8*/              L->Next = NewCell; 
/* 9*/              strcpy(NewCell->Element, Key);  
/* 10*/				NewCell->Times = 1; 
/* 11*/             L->Times++; /* ͷ����Times��ʾ������ĳ��ȣ���1 */ 
                }
            }
}
