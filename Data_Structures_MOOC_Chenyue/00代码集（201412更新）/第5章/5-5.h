
void  Insert( ElementType Key, HashTable H )
{
			Position Pos;

/* 1*/		Pos = Find( Key, H );
/* 2*/		if( H->TheCells[ Pos ].Info != Legitimate ) {
                /* ȷ���ڴ˲��� */
/* 3*/         H->TheCells[ Pos ].Info = Legitimate;
/* 4*/         H->TheCells[ Pos ].Element = Key;
               /*�ַ������͵Ĺؼ�����Ҫ strcpy ����!! */
            }
}
