
ElementType KthLargest( ElementType S[], int K)
{   /* ��Ϊα���� */
	
	/* ѡȡS�еĵ�һ��Ԫ��e; */
	/* ����e������S�ֽ�Ϊ���ڵ���e ��Ԫ�ؼ���S1��С��e��Ԫ�ؼ���S2;*/
	if (|S1|>K) return KthLargest(S1��K);
	else if (|S1|<K) return KthLargest(S2��K-|S1|);
	else return e;      
}
