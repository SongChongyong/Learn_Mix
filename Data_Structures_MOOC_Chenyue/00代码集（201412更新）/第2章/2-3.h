
float Max(float A[], int N)    
{  /*  ��N��Ԫ�������е����ֵ  */
	float CurMax = A[0];
	int i;

	for(i=1; i<N; i++)
		if (A[i]>CurMax)
			CurMax=A[i];

	return CurMax;
}
