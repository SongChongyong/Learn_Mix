
struct People DeleteQ( Queue Q )
{   /* ��Q���׵Ĺ˿ͳ��� */
	struct People X;

    /* ��λ�ڶ���ǰ�˵ı�����ɾ���Ĺ˿�����ɾ�� */
	while ( Q->Customer[Q->front].VIP == -1 ) {
		Q->front++;
		Q->size--;
	}
	if ( IsEmpty(Q) ) { /* ���������ֶ����ѿգ����ؿ��ź� */
		X.T = -1;
		return X;
	}
	if ( Q->Customer[Q->front].VIP == 1 )
		X = DeleteVIP(Q); /* ����׵�VIP�ͻ����� */
	else {  /* ��ͨ�˿ͳ��� */
		X.T = Q->Customer[Q->front].T;
		X.P = Q->Customer[Q->front].P;
	}
    /* ɾ�����׵Ĺ˿� */
	Q->front++;
	Q->size--;
	return X;
}
