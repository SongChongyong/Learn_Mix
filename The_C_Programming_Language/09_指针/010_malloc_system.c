#include<stdio.h>
#include<stdlib.h> 

int main()
{
    void* p=NULL;
    int cnt=0;
    while(p=malloc(100*1024*1024)) //��pΪNULL(0)ʱ����ʾ��ʱ�޷��ٷ���ռ䣬����ѭ��
    {
    	cnt++;
    }
    printf("������%d00MB�ռ�\n",cnt);
    return 0;
}
/*
��32λ�����������н���� 
������1900MB�ռ�
*/
