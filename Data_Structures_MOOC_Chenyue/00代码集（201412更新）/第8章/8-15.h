
int CheckCycle( Vertex V1, Vertex V2 )
{   /* �������V1��V2�ı��Ƿ������е���С�������Ӽ��й��ɻ�· */
	Vertex Root1 = Find(V1); /* �õ�V1��������ͨ������ */
	Vertex Root2 = Find(V2); /* �õ�V2��������ͨ������ */

	if(Root1==Root2) /* ��V1��V2�Ѿ���ͨ����ñ߲���Ҫ������0 */
		return 0;
	else {  /* ����ñ߿��Ա��ռ���ͬʱ��V1��V2����ͬһ��ͨ�� */
		SetUnion(Root1, Root2);
		return 1;
	}
}
