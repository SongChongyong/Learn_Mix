
void Push( Stack *PtrS, ElementType item )
{
    if ( PtrS->Top == MaxSize-1 ) {
		printf("��ջ��");
		return;
	}
	else {
		PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}
