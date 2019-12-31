#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    // %d对应,12345，%n表示当printf进行到此语句已经输出的字符个数，这里存入变量num
    printf("%d%n\n", 12345, &num);   
    printf("%d\n",num);

    printf("%dyyyyy%n\n", 12345, &num);   
    printf("%d\n",num);    

    return 0;
}

/*
12345
5
12345yyyyy
10
*/
