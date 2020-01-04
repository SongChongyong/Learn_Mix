#include<stdio.h>
#include<stdlib.h>
#define BLOCK_SIZE 5

typedef struct {
    int *array;
    int size;
}Array;

Array array_creat(int init_size);                   
void array_free(Array *a);                          
int  array_size(const Array *a);                         
int*array_at(Array*a, int index);                   
void array_inflate(Array*a, int more_size);        

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



/*可变数组各函数定义:*/
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
