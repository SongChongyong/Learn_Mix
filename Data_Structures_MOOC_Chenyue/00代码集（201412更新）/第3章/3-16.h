
ElementType DeleteQ ( LinkQueue  *PtrQ )
{
	Qnode  *FrontCell; 
	ElementType FrontElem;
	
	if  ( PtrQ->front == NULL) {
		printf("���п�");
		return ERROR;
	} 
	FrontCell = PtrQ->fornt;
	if ( PtrQ->front == PtrQ->rear) /* ������ֻ��һ��Ԫ�� */
		PtrQ->front = PtrQ->rear = NULL; /* ɾ���������Ϊ�� */
	else                     
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;

	free( FrontCell );  /* �ͷű�ɾ�����ռ�  */
	return  FrontElem;
}
