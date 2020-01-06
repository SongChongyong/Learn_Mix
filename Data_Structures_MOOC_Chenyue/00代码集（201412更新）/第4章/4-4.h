
int BinarySearch ( StaticTable * Tbl, ElementType K)
{ /*�ڱ�Tbl�в��ҹؼ���ΪK������Ԫ��*/
	int left, right, mid, NoFound=-1;

    left=1;            /*��ʼ��߽�*/
    right=Tbl->Length; /*��ʼ�ұ߽�*/
    while(left<=right)
    {
        mid=(left+right)/2;  /*�����м�Ԫ������*/
        if( K < Tbl->Element[mid]) right=mid-1;      /*�����ұ߽�*/
        else if( K > Tbl->Element[mid]) left=mid+1;  /*������߽�*/
        else return mid;   /*���ҳɹ�����������Ԫ�ص��±�*/
    }
    return NoFound;   /*���Ҳ��ɹ�������-1*/
}
