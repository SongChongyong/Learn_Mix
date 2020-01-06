#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP 100    /* ���������п��ܵ���󳤶� */
#define MaxSize 100  /* ��ջԪ�������� */
#define NUMBER 0      /* �������ı�ʶ */
typedef double ElementType; /* ����ջ��Ԫ�����;��廯 */

/* ���ڶ�ջ�Ĵ�����μ���ջ�Ķ���ʹ���3.10��3.11 */
typedef struct {
		ElementType Data[MaxSize];
		int Top;
} Stack;
#define ERROR -1 /* ����ջΪ��ʱ���ش�������Ĭ����ȷ����ֵȫ������ */

#include "3-10.h"
#include "3-11.h"

int GetOp( char s[] )
{   /* �������л����һ�����󣨲�������������������������ַ�����s��*/
    /* ����ֵΪNUMBER����������� */
	int i, c;

    /* �������ʽǰ�ո���ַ� */
	while ( (s[0] = c = getchar()) == ' ' || c == '\t' ); 

	s[1]= '\0';
	if ( !isdigit(c) && c!= '.' ) /* ���c������� */
		return c;  /* ֱ�ӷ�������� */
	i = 0;
	if( isdigit(c) ) /* ���c�����֣���һֱ�������������ֲ�����s */
		while ( isdigit(s[++i] = c = getchar()) );
	if( c == '.' ) /* �����С���㣬���������С�������������� */
		while ( isdigit(s[++i]=getchar()) );
	s[i] = '\0'; /* ��ɶ�ʵ���ַ����Ĵ洢 */
	return NUMBER;  /* ��ʾ��ʱs�д����һ������ */
}

int main()
{	
	int Type;
	double Op2;
	char s[MAXOP];
    Stack *PtrS;

	/* ����һ���¶�ջ��PtrSָ��ö�ջ */
	PtrS = (Stack *)malloc(sizeof(Stack)); 
	PtrS->Top = -1;

    while( (Type = GetOp(s))!=EOF ) { /* ��δ�����������ʱ */
		switch (Type) {
			case NUMBER: Push(PtrS, atof(s)); break;
			case '+': Push(PtrS, Pop(PtrS) + Pop(PtrS));  break;
			case '*': Push(PtrS, Pop(PtrS) * Pop(PtrS));  break;
			case '-': 
				Op2 = Pop(PtrS); 
				Push( PtrS, Pop(PtrS) - Op2);
				break;
			case '/': 
				Op2 = Pop(PtrS);
				if( Op2 != 0.0 ) /* �������ķ�ĸ�Ƿ�Ϊ0 */
					Push(PtrS, Pop(PtrS)/Op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n': printf("%.8g\n", Pop(PtrS)); break;
		    default: printf("error: unknown command %s \n", s); break;
		}
	}

	free(PtrS);    /* �ͷŶ�ջ */
	return 0;
}
