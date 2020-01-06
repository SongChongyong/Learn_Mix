#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "5-6.h"
#include "5-12.h"
#include "5-1.h"
#include "5-7.h"
#include "5-8.h"
#include "5-9.h"
#include "5-10.h"
#include "5-13.h"
#include "5-14.h"
#include "5-15.h"

int main()
{
/* 1 */     int TableSize = 100; /* ɢ�б�Ĺ��ƴ�С�����Ը���Ӧ�ø��� */
	        int wordcount = 0, length;
            HashTable H;
            ElementType word;
	        FILE *fp;
/* 2 */     char document[30] = "HarryPotter.txt";
                              /* Ҫ��ͳ�ƴ�Ƶ���ļ��� */

/* 3 */     H = InitializeTable( TableSize ); /* ����ɢ�б� */

/* 4 */     if(( fp = fopen(document, "r" )) == NULL)
                FatalError("�޷����ļ���\n" );
                   	
           	while( !feof( fp ) ){
/* 5 */        length = GetAWord( fp, word );
/* 6 */        if(length > 3){     /* ֻ���ǳ��ȴ���3���ַ��ĵ��� */
/* 7 */	         wordcount++;      
/* 8 */	         InsertAndCount( word, H );
		       }
   	        }
   	        fclose( fp );

/* 9 */    printf("���ĵ������� %d ����Ч����", wordcount);
/* 10 */   Show( H, 10.0/100 );  /* ��ʾ��Ƶǰ10%�����е��� */
/* 11 */   DestroyTable( H );    /* ����ɢ�б� */
		   return 0;
}
