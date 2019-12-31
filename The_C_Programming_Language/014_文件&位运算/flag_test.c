#include<stdio.h>

int main(int argc, char const *argv[])
{
    printf("%9d\n", 123);
    printf("%-9d\n", 123);    // -表示左对齐
    printf("%+9d\n", 123);
    printf("%-+9d\n", 123);
    printf("%09d\n", 123);     // 0填充

    return 0;
}

/*
      123
123      
     +123
+123     
000000123 
*/
