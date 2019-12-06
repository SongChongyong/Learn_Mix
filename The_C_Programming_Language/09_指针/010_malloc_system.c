#include<stdio.h>
#include<stdlib.h> 

int main()
{
    void* p=NULL;
    int cnt=0;
    while(p=malloc(100*1024*1024)) //当p为NULL(0)时，表示此时无法再分配空间，跳出循环
    {
    	cnt++;
    }
    printf("分配了%d00MB空间\n",cnt);
    return 0;
}
/*
在32位编译器中运行结果： 
分配了1900MB空间
*/
