#include<stdio.h>
#define cube(x) ((x)*(x)*(x))

int main(int argc, char const *argv[])
{
    int i;
    scanf("%d", &i);
    printf("%d\n", cube(i+2));  // cube(i+2)表示((i+2)*(i+2)*(i+2))
    return 0;
}
/*
2
64
*/
