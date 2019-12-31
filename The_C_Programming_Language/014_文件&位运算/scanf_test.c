#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    scanf("%*d%d", &num);   // %*d%d表示输入两个%d，跳过第一个%d，读入第二个%d
    printf("%d\n",num);
   
    return 0;
}

/*
123 456
456
*/
