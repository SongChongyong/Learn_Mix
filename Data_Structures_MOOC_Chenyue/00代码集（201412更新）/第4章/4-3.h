
int SequentialSearch (StaticTable *Tbl, ElementType K)
{ /*�ڱ�Tbl�в��ҹؼ���ΪK������Ԫ��*/
	int i;

    Tbl->Element[0] = K; /*�����ڱ�*/
    for( i = Tbl->Length; Tbl->Element[i] != K; i--);
    return i; /*���ҳɹ���������Ԫ�����ڵ�Ԫ�±ꣻ���Ҳ��ɹ�����0*/
}
