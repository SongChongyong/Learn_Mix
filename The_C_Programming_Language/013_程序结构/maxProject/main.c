#include<stdio.h>
#include "max.h"    // 要调用max()函数，所以申明包含这个函数原型的头文件


int main(void)
{
    int a=5;
    int b=6;
    printf("%d\n",max(a,b));

    return 0;
}

