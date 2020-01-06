
Position  Find( ElementType Key, HashTable H )
{
            Position CurrentPos, NewPos;
            int CNum;        /*   ��¼��ͻ����   */

/* 1*/      CNum = 0;
/* 2*/      NewPos = CurrentPos = Hash( Key, H->TableSize );
/* 3*/      while( H->TheCells[ NewPos ].Info != Empty && H->TheCells[ NewPos ].Element != Key ) {
                                                         /* �ַ������͵Ĺؼ�����Ҫ strcmp ����!! */
/* 4*/			if(++CNum % 2){ /*  �жϳ�ͻ����ż��  */
/* 5*/				NewPos = CurrentPos + (CNum+1)/2*(CNum+1)/2;
/* 6*/				while( NewPos >= H->TableSize )
/* 7*/					NewPos -= H->TableSize;
				}
				else {
/* 8*/				NewPos = CurrentPos - CNum/2 * CNum/2;
/* 9*/				while( NewPos < 0 )
/* 10*/					NewPos += H->TableSize;
				}
			}
/* 11*/		return NewPos;
}
