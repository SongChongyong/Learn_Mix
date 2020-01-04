#ifndef __ARRAY__H__
#define __ARRAY__H__
#include "array.h"
#define BLOCK_SIZE 5

/*可变数组头文件*/


// 定义可变数组结构，并命名为Array
typedef struct {
    int *array;
    int size;
}Array;
/*
很多第三方库定义typedef struct {...}*Array----直接定义指针类型Array,
因为后续array_inflate()等函数传入的参数都是指针，
但是如果代码中需要定义“Array a;”这样一个本地变量就无法实现，所以还是定义结构为Array
*/

Array array_creat(int init_size);                   //创建一个数组
void array_free(Array *a);                          //free申请的内存
int  array_size(const Array *a);                          //目前有多少个单元可以用
int*array_at(Array*a, int index);                   //访问数组当中某个单元:可以读也可以写
void array_inflate(Array*a, int more_size);         //数组长大
void array_set(Array*a, int index, int value);      //向数组中写入东西

#endif


