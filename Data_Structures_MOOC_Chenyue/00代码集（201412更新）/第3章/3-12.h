
void Push( struct DStack *PtrS, ElementType item, int Tag )
{   /* Tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2 */
	if ( PtrS->Top2 - PtrS->Top1 == 1) {  /*��ջ��*/
		printf("��ջ��");
		return ;
	}
	if ( Tag == 1 ) /* �Ե�һ����ջ���� */
		PtrS->Data[++(PtrS->Top1)] = item;
	else              /* �Եڶ�����ջ���� */
		PtrS->Data[--(PtrS->Top2)] = item;
}

ElementType Pop( struct DStack *PtrS, int Tag )
{   /* Tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2  */
	if ( Tag == 1 ) {  /* �Ե�һ����ջ����  */
		if ( PtrS->Top1 == -1 ) { /*��ջ1�� */
			printf("��ջ1��");
			return NULL;
		}
		else return PtrS->Data[(PtrS->Top1)--];
	}
	else {          /* �Եڶ�����ջ���� */
		if ( PtrS->Top2 == MaxSize ) { /*��ջ2�� */
			printf("��ջ2��");
			return NULL;
		}
		else  return PtrS->Data[(PtrS->Top2)++];
	}
}
