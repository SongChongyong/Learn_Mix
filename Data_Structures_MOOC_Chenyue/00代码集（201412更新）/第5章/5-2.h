
/* ƽ��̽�ⷨɢ�б�.h�ļ� */
typedef int ElementType;  /* �ؼ������������� */

#ifndef _HashQuad_H
#define _HashQuad_H

typedef unsigned int Index; /* ɢ�е�ַ���� */
typedef Index Position;     /* ��������λ����ɢ�е�ַ��ͬһ���� */

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( ElementType Key, HashTable H );
void Insert( ElementType Key, HashTable H );
ElementType Retrieve( Position P, HashTable H );
HashTable Rehash( HashTable H );
/* ʡ����Delete �� MakeEmpty �Ⱥ��� */

#endif  /* _HashQuad_H */

/* ���¶������Դ������ */
#define Error( Str )      fprintf( stderr, "%s\n", Str )
#define FatalError( Str ) fprintf(stderr, "%s\n", Str ), exit( 1 )
#define MinTableSize (10)
enum EntryType { Legitimate, Empty, Deleted };

struct HashEntry{
	ElementType Element;
	enum EntryType Info;
};

typedef struct HashEntry Cell;
        
struct HashTbl{
	int TableSize;
	Cell *TheCells;
    /* ��Ԫ *TheCells ��һ�����飬ÿ��Ԫ���� HashEntry*/
    /* ������洢 */
};
