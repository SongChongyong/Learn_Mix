#include<stdio.h>
#include<stdlib.h>
#include "array.h"
/*可变数组各函数定义*/


/*创建可变数组，传入开始设置的数组大小init_size */
Array array_creat(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*a.size);
    return a;
}

/* 数组Array a在创建的时候用malloc申请了存放*array的内存，需要free */
void array_free(Array *a)
{
    free(a->array);
    a->array = NULL;  // 保险起见,每次释放后让a->array = 0(NULL)
    a->size = 0;      // 保险起见,每次释放后让a->size = 0
}

/* 数组Array a的大小，封装 */
int array_size(const Array *a)
{
    return a->size;
}

/* 访问数组当中index位置的元素，可以读取也可以写入 */
int *array_at(Array *a, int index)
{
    // 当index越界情况, 调用数组增大函数array_inflate，每次多申请一个BLOCK_SIZE大小的新空间，
    // 然后复制原先数组的所有元素过去，重新定义数组用于存放新添加的元素
    if(index >= a->size){
        array_inflate(a, (index/BLOCK_SIZE+1)*BLOCK_SIZE - a -> size);
    }
    return &(a->array[index]);
}

/* 数组自动长大: 在原先数组a->size大小的基础上，用malloc申请”a->size + more_size“的空间 */
void array_inflate(Array*a, int more_size)
{
    int *p = (int*)malloc(sizeof(int) * (a->size + more_size));   // 申请增大的数组所需新空间
    // 有空间后，还需要把原先的数组内容用循环遍历一个个复制到新的空间
    int i;
    for(i=0; i<a->size; i++){
        p[i] = a->array[i];
    }
    // 复制完后free原先老数组的空间，然后重新定义新数组的array和size
    free (a->array);  
    a->array = p;
    a->size += more_size;
}