
ElementType Average( ElementType S[], int N )
{   /* �󼯺�Ԫ�ص�ƽ��ֵ������Ԫ�ش��������S�У������СΪN */
	int i;
	ElementType Sum=0;

    for(i=0; i<N; i++)
		Sum += S[i];     /* ������Ԫ���ۼӵ�Sum�� */
    return Sum/N;
}
