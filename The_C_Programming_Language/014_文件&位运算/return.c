#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    int i1 = scanf("%i", &num);     // scanf()函数返回读入的项目数
    int i2 = printf("%d\n",num);    // printf()函数返回输出的字符数
    printf("i1=%d, i2=%d\n", i1, i2);

    return 0;
}

/*
12345
12345
i1=1, i2=6
*/
