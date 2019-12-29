#include<stdio.h>

int f_1(void);
int f_2(void);
int f_3(void);
int gAll;    // 全局变量gAll,初始化为12.如果没有初始化，系统会默认初始化为0

int main()
{
    printf("Define int all=1\n");
    f_1();
    f_1();
    printf("========\n");
    printf("Define static int all=1\n");
    f_2();
    f_2();
    f_3();
    return 0;
}

int f_1(void)
{
    int all=1;
    printf("in %s, all=%d\n",__func__, all);
    all +=2;
    printf("After all=+2, in %s, all=%d\n",__func__, all);
    return all;
}

int f_2(void)
{
    static int all=1;
    printf("in %s, all=%d\n",__func__, all);
    all +=2;
    printf("After all=+2, in %s, all=%d\n",__func__, all);
    return all;
}

int f_3(void)
{
    int k=0;
    static int all =1;
    printf("&gAll           =%p\n", &gAll);
    printf("&static int all =%p\n", &all);
    printf("&int k          =%p\n", &k);
    return 0;
}

/*
Define int all=1
in f_1, all=1
After all=+2, in f_1, all=3
in f_1, all=1
After all=+2, in f_1, all=3
========
Define static int all=1
in f_2, all=1
After all=+2, in f_2, all=3
in f_2, all=3
After all=+2, in f_2, all=5
&gAll           =0x601054
&static int all =0x60104c
&int k          =0x7ffed51690f4
*/

