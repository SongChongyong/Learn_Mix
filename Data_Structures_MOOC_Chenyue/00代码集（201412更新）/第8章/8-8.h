
struct People DeleteVIP( Queue Q )
{   /* ��VIP���ж��׵Ŀͻ����� */
	struct People X;
	int Position;

	if ( Q->VIPsize ) { /* �������VIP�ͻ� */
		/* ��ö��׿ͻ��ڹ˿Ͷ����е�λ�� */
		Position = Q->VIPCustomer[Q->VIPfront]; 
		/* ����λ�ô�VIP������ɾ�� */
		Q->VIPfront++;
		Q->VIPsize--;
		Q->Customer[Position].VIP = -1; /* ����ɾ���˿Ͷ����е�VIP */
		X.T = Q->Customer[Position].T;
		X.P = Q->Customer[Position].P;
	}
	else  /* ���û��VIP�ͻ���������ͨ���� */
		X = DeleteQ(Q);
	
	return X;
}
