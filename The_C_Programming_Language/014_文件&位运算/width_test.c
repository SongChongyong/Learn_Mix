#include<stdio.h>

int main(int argc, char const *argv[])
{
    printf("%9.2f\n", 123.0);   // 9.2f表示浮点数总共占据9位，其中小数2位
    printf("%*d\n",6, 123);     // *d中，*对应后面的6，表示总共占据6位，d对应的是123

    return 0;
}

/*
   123.00
   123
*/
