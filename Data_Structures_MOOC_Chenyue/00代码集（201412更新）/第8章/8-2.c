#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define MaxProc 60
#define MaxWindow 10
#include "8-1.h"

typedef struct People ElementType;

int IsEmpty( Queue Q )
{
	if ( Q->front == Q->rear ) 
		return 1;
	else  
		return  0;
}

void AddQ( Queue Q, ElementType item )
{         
     if ( (Q->rear+1) % MaxSize == Q->front ) {
		 printf("������");
		 return;
	 }
	 Q->rear =(Q->rear+1)% MaxSize;
	 Q->Customer[Q->rear] = item;
	 Q->size++;
}

ElementType DeleteQ ( Queue Q )
{       
	ElementType ERROR;

	if ( IsEmpty(Q) ) { 
		printf("���п�");
		ERROR.T = -1; /* �����־ */
		return ERROR;
	}
	else  {
		Q->front =(Q->front+1)% MaxSize;
		return  Q->Customer[Q->front];
	}
} 

#include "8-3.h"
#include "8-5.h"
#include "8-4.h"

int main()
{	int N;    /* �˿����� */
	Queue Q;  /* �˿Ͷ��� */

	scanf("%d", &N);  /* ����˿����� */
	Q = CreateQueue( N ); /* �����˿Ͷ��� */

	/* ��ӡ��Nλ�˿�ƽ���ȴ�ʱ�� */
	printf("Average waiting time = %.1lf minute(s).\n", QueueingAtBank( Q, N ));
	
	return 0;
}
