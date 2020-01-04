#include<stdio.h>
#include<stdlib.h>
#include "array.h"

int main(int argc, char const *argv[])
{
    // 创建初始大小为10的数组
    Array a = array_creat(10);
    // 打印可变数组的大小
    printf("数组初始大小：%d\n", array_size(&a));    // 10
    printf("每次增加的BLOCK_SIZE = %d\n",BLOCK_SIZE);

    // 将可变数组的第0个位置写入10
    *array_at(&a, 0) = 10;
    printf("在a[0]位置写入10，打印写入后a[0]：%d\n", *array_at(&a, 0));   
    
    // 读入不为-1的number，然后将number写入可变数组中，让数组长大
    // 只有当输入的number为-1时，跳出循环，数组停止写入
    int number=0;
    int cnt = 0;
    printf("请输入需要添加到数组的元素：(输入-1表示终止)\n");
    while(number!= -1){
        scanf("%d", &number);
        if(number != -1){
            *array_at(&a, cnt++) = number;
        }
    } 
    // 打印数组增长后，数组的大小
    printf("数组增长后，数组的大小：%d\n", array_size(&a));
    // 打印当前数组的所有元素
    int i;
    for (i=0; i<array_size(&a);i++){
        printf("%d  ",a.array[i]);
    }

    printf("\n");


    // free掉数组a申请的内存空间
    array_free(&a);

    return 0;
}


/*
数组初始大小：10
每次增加的BLOCK_SIZE = 5
在a[0]位置写入10，打印写入后a[0]：10
请输入需要添加到数组的元素：(输入-1表示终止)
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 -1
数组增长后，数组的大小：20
1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  0  0  0
*/

