
void SimpleSelectionSort( ElementType A[], int N )
{   /* ��ѡ������ */
	int i, j, min, temp;

	for (i = 0; i < N - 1; i++) { /*Ѱ����СԪ��*/
		min = i;
		for (j = i+1; j < N; j++)
			if (A[j] < A[min])
				min = j;
			/* ����i��Ԫ������СԪ�ؽ��� */
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;
	}
}
