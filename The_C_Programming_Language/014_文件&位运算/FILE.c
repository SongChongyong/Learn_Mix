#include<stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("new.in", "r");   // 打开new.in这个文件
    if (fp){
        int num;
        fscanf(fp, "%d", &num);        // fscanf()函数去度fp指向的文件
        printf("%d\n", num);
        fclose(fp);
    } else {
        printf("无法打开文件\n");
    }

    return 0;
}
/*
123456
*/

