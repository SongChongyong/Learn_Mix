
Index Hash ( const char *Key, int TableSize )
{   
    unsigned int h = 0;     /* ɢ�к���ֵ����ʼ��Ϊ0 */

    while ( *Key != '\0' )  /* λ��ӳ�� */
        h = ( h << 5 ) + *Key++;

    return h % TableSize;
}
