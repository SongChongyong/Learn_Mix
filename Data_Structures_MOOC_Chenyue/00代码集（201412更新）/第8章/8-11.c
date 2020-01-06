#include <stdio.h>

#define MaxSize 100

typedef int Vertex;
typedef Vertex ElementType;

typedef struct {
    ElementType Data;
    int Parent;
} SetType;

void Initialization( SetType S[], int N )
{
	int i;

	for (i=0; i<N; i++) {
		S[i].Data = i;
		S[i].Parent = -1;
	}
}

#include "4-28.h"
#include "4-29.h"

void InputConnection( SetType S[], int M )
{   /* ����M���ߣ������б������Ľ�㲢��ͬһ���� */
	Vertex U, V;    /* ��¼����Ľ�� */
	Vertex V1, V2;  /* ��¼���������ڵļ��ϵĸ���� */
	int i;

	for (i=0; i<M; i++) {
		scanf("%d %d", &U, &V);
		V1 = Find( S, U );
		V2 = Find( S, V );
		if ( V1 != V2 )
			Union( S, V1, V2 );
	}
}

int CountConnectedComponents( SetType S[], int N )
{   /*���㼯��S����ͨ���ĸ��� */
	int i, cnt = 0;

	for (i=1; i<=N; i++) {
		if ( S[i].Parent < 0 )
			cnt ++;
	}
	return cnt;
}

int main()
{
	SetType S[MaxSize];
	int N, M;

	scanf("%d %d", &N, &M);
	Initialization( S, N );
	InputConnection( S, M );
	printf("Number of roads = %d\n", CountConnectedComponents( S, N )-1 );

	return 0;
}
