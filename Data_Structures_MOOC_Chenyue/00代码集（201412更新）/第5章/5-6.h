
/* �������ӷ�ɢ�б�.h�ļ� */

#define KEYLENGTH 15            /* �ؼ����ַ����ĳ��Ȳ����� 15 */
typedef char ElementType[KEYLENGTH+1]; /* �ؼ����������ַ��� */

typedef unsigned int Index;
#ifndef _HashSep_H
#define _HashSep_H

struct ListNode;
typedef struct ListNode *Position, *List;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( ElementType Key, HashTable H );
void Insert( ElementType Key, HashTable H );
/* ʡ��Delete �� MakeEmpty �Ⱥ��� */

#endif  /* _HashSep_H */

/* ���¶������Դ������ */
#define Error( Str )        fprintf( stderr, "%s\n", Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

#define MinTableSize (10)
struct ListNode{
	ElementType Element;
	unsigned short Times;  /* ��Ƶͳ��Ӧ��ʵ�������ڳ��ִ��� */
	Position Next;
};
/*  Ϊ�˼�������������ͷ������ɢ�б�����Ԫ�� */
struct HashTbl{
	int TableSize;
	List TheLists;
};
