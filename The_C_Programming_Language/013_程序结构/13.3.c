#include<stdio.h>

int *f(void);
void g(void);

int main()
{
    int *p=f();
    printf("*p=%d\n", *p);
    g();
    printf("*p=%d\n", *p);
    /*
    运行结果：
    *p=12                                                                        
     k=24                                                                            
    *p=12
    分析结果可知，先执行f()时返回的是本地变量i的地址，而地址上存储的是12，
    在运行g()后，新的变量k存储到这个地址上，地址上存储的是24
    */

    return 0;
}

int *f(void)
{
    int i=12;
    return &i;    // 这里返回的是函数本地变量i的地址
}

void g(void)
{
    int k=24;
    printf("k=%d\n", k);
}


