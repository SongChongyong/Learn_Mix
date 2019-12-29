#include<stdio.h>

int f(void);
int gAll=12;    // 全局变量gAll,初始化为12.如果没有初始化，系统会默认初始化为0

int main()
{
    printf("in %s, gAll=%d\n",__func__,gAll);  //__func__:当前函数名
    f();
    printf("Again,in %s, gAll=%d\n",__func__,gAll);
}

int f(void)
{
    printf("in %s, gAll=%d\n",__func__, gAll);
    gAll +=2;
    printf("Again, in %s, gAll=%d\n",__func__, gAll);
    return gAll;
}

/*
in main, gAll=12
in f, gAll=12
Again, in f, gAll=14
Again,in main, gAll=14
*/

