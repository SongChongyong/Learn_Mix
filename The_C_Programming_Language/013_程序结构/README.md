# 13 程序结构

## 13.1 全局变量

- **全局变量**：定义在函数外面的变量是全局变量

- 全局变量具有全局的生存期和作用域：
    1. 它们与任何函数都无关
    2. 在任何函数内部都可以使用它们

```c
#include<stdio.h>

int f(void);
int gAll=12;    // 全局变量gAll,初始化为12.如果没有初始化，系统会默认初始化为0

int main()
{
    printf("in %s, gAll=%d\n",__func__,gAll);  //__func__:当前函数名
    f();
    printf("Again,in %s, gAll=%d\n",__func__,gAll);
}

int f(void)
{
    printf("in %s, gAll=%d\n",__func__, gAll);
    gAll +=2;
    printf("Again, in %s, gAll=%d\n",__func__, gAll);
    return gAll;
}

/*
in main, gAll=12
in f, gAll=12
Again, in f, gAll=14
Again,in main, gAll=14
*/

```

(详细代码见: [13.1.c](./13.1.c))



- **全局变量初始化**：

    1. 没有初始化的全局变量会得到0值(指针会得到NULL值)

    2. 只能用编译时刻已知的值来初始化全局变量

        ```c
        int f(void);
        int gAll=f();   // f()不是已知的值，这样初始化不行，或error
        
        
        int gAll=12;
        int g2 = gAll;   // error，
        ```

        

- 如果函数内部存在与全局变量同名的变量，则全局变量会被隐藏。

    ```c
    #include<stdio.h>
    
    int f(void);
    int gAll=12;    // 全局变量gAll,初始化为12.如果没有初始化，系统会默认初始化为0
    
    int main()
    {
        printf("in %s, gAll=%d\n",__func__,gAll);  //__func__:当前函数名
        f();
        printf("Again,in %s, gAll=%d\n",__func__,gAll);
    }
    
    int f(void)
    {
        int gAll=1;     // 函数内部int变量gAll与全局变量同名，隐藏全局变量
        printf("in %s, gAll=%d\n",__func__, gAll);
        gAll +=2;
        printf("Again, in %s, gAll=%d\n",__func__, gAll);
        return gAll;
    }
    
    /*
    in main, gAll=12
    in f, gAll=1
    Again, in f, gAll=3
    Again,in main, gAll=12
    */
    ```

    

## 13.2 static 静态本地变量

- 在本地变量定义时加上static修饰符就成为**静态本地变量**
- 当函数离开时，静态本地变量会继续存在并保持其值
- 静态本地变量的初始化只会在第一次进入该函数时做，以后进入函数时会保持上次离开时的值

```c
#include<stdio.h>

int f_1(void);
int f_2(void);
int gAll=12;    // 全局变量gAll,初始化为12.如果没有初始化，系统会默认初始化为0

int main()
{
    printf("Define int all=1\n");
    f_1();
    f_1();
    printf("========\n");
    printf("Define static int all=1\n");
    f_2();
    f_2();
    return 0;
}

int f_1(void)
{
    int all=1;
    printf("in %s, all=%d\n",__func__, all);
    all +=2;
    printf("After all=+2, in %s, all=%d\n",__func__, all);
    return all;
}

int f_2(void)
{
    static int all=1;
    printf("in %s, all=%d\n",__func__, all);
    all +=2;
    printf("After all=+2, in %s, all=%d\n",__func__, all);
    return all;
}

/*
Define int all=1
in f_1, all=1
After all=+2, in f_1, all=3
in f_1, all=1
After all=+2, in f_1, all=3
========
Define static int all=1
in f_2, all=1
After all=+2, in f_2, all=3
in f_2, all=3
After all=+2, in f_2, all=5
*/

```

(详细代码见: [13.2_static.c](./13.2_static.c))



- **静态本地变量实际上是特殊的全局变量，它们位于相同的内存区域。**
- 静态本地变量有全局的生存期，函数内的局部作用域。

```c
int f_3(void);
int gAll;

int main()
{
    f_3();
    return 0;
}

int f_3(void)
{
    int k=0;
    static int all =1;
    printf("&gAll           =%p\n", &gAll);   //打印全局变量地址
    printf("&static int all =%p\n", &all);    //打印静态本地变量地址
    printf("&int k          =%p\n", &k);      //打印本地地址
    return 0;
}
/*
&gAll           =0x601054
&static int all =0x60104c
&int k          =0x7ffed51690f4
*/
```

由结果可知，全局变量gAll和静态本地变量all存储同一区域。



## 13.3 全局变量和静态本地变量总结

- 对于返回指针的函数，返回本地变量的地址是危险的

```c
#include<stdio.h>

int *f(void);
void g(void);

int main()
{
    int *p=f();
    printf("*p=%d\n", *p);
    g();
    printf("*p=%d\n", *p);
    /*
    运行结果：
    *p=12                                                                        
     k=24                                                                            
    *p=12
    分析结果可知，先执行f()时返回的是本地变量i的地址，而地址上存储的是12，
    在运行g()后，新的变量k存储到这个地址上，地址上存储的是24
    */

    return 0;
}

int *f(void)
{
    int i=12;
    return &i;    // 这里返回的是函数本地变量i的地址
}

void g(void)
{
    int k=24;
    printf("k=%d\n", k);
}


```





- 不要使用全局变量在函数间传递参数和结果
- **尽量避免使用全局变量**
- 使用全局变量和静态变量的函数是线程不安全的



## 13.4 宏

- #开头的是编译预处理指令，以#开头的语句不是C语言的成分，但是C语言程序离不开它们



- **#define用来定义一个宏**：

    `#define <名字> <值>`

    1. 注意结尾没有分号，因为不是C的语句

    2. 名字必须是一个单词，值可以是各种东西(数，表达式，...)

    3. 在C语音的编译器开始编译之前，编译预处理程序(cpp)会把程序中的名字换成值

        如对于[13.4_define.c](./13.4_define.c)程序，程序内容如下：

        ```c
        #include<stdio.h>
        #define PI 3.14159
        
        int main(int argc, char const *argv[])
        {
            printf("2*PI=%f\n",2*PI);
            return 0;
        }
        ```

        命令行执行编译过程(**--save-temps保存编译过程文件**)：

        `$ gcc 13.4_define.c -o 13.4_define --save-temps`

        会依次生成"13.4_define.i" , "13.4_define.s",  "13.4_define.o" , "13.4_define.out"文件，其中"13.4_define.c"文件编译预处理成"13.4_define.i"文件

        用命令行`$ tail 13.4_define.i`看"13.4_define.i"文件最后几行代码，可以看到编译预处理后宏的名字被替换成了值：

        ```c
        # 4 "13.4_define.c"
        int main(int argc, char const *argv[])
        {
            printf("2*PI=%f\n",2*3.14159);
            return 0;
        }
        ```

        

    4. 如果一个宏的值有其他宏的名字，编译预处理时也会被替换

        ```c
        #define PI 3.14159
        #define PI2 2*PI     //宏PI2中有其他的宏PI，预处理时被替换成2*3.14159
        
        int main(int argc, char const *argv[])
        {
            printf("2*PI=%f\n",PI2);
            return 0;
        }
        ```

        

    5. 如果一个宏的值超过一行，最后一行之前的行末需要加上\

    6. 宏后面的注释不会被当做宏的值的一部分



- 没有值的宏

    如`#define _DEBUG`

    这类宏是用于条件编译的，后面有其他的编译预处理指令来检查这个宏是否已经被定义过



- 预定义的宏

    - `__LINE__` 表示当前所在行号

    - `__FILE__` 表示源代码文件的文件名

    - `__DATE__` 表示编译时刻的日期

    - `__TIME__` 表示编译时刻的时间

    - `__STDC__` 整数常亮1，表示该编译器遵循ISO C标准

        ```c
        #include<stdio.h>
        
        int main(int argc, char const *argv[])
        {
            printf("在%s文件，此打印代码的行号:%d\n", __FILE__, __LINE__);
            printf("此文件编译的日期:%s    时间:%s\n", __DATE__, __TIME__);
            printf("整数常量1:%d\n", __STDC__);
        }
        /*
        在test.c文件，此打印代码的行号:5
        此文件编译的日期:Dec 27 2019    时间:16:48:16
        整数常量1:1
        */
        ```

        

## 13.5 带参数的宏

- 宏可以带参数

    如`#define cube(x) ((x)*(x)*(x))`

    ```c
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
    ```

    

- 定义带参数的宏时要注意：一切都有括号

    1. **整个值要括号**
    2. **参数出现的每个地方都要括号**

    如**错误定义**的宏：

    ​    `#define RADTOEG(x) (x*57.29578)`

    ​    `#define RADTOEG(x) (x)*57.29578`

    改成**正确定义**：

    ​    `#define RADTOEG(x) ((x)*57.29578)`



- 可以带多个参数，也可以组合嵌套其他宏

    如`#define MIN(a,b) ( (a)>(b) ? (b):(a) )`
    
    

- 在大型程序的代码中宏的使用非常普遍
- 部分宏会被inline函数代替

## 13.6 多个.c文件--项目

- main()函数里的代码如果很长，适合分成几个函数。

- 一个源代码文件太长，也需要分成几个文件，但是两个独立的源代码文件不能编译形成可执行的程序。

- 一个.c文件是一个**编译单元**，编译器每次编译只处理一个编译单元

- 有多个.c文件，就需要新建一个**项目**：

    如在Dev C++中新建一个项目，然后把几个源代码文件加入进去，Dev C++在编译时会把所有的源代码文件都编译后，链接起来。
    
    



## 13.7 头文件

- **把函数原型放到一个头文件(以.h结尾)中，在需要调用这个函数的源代码(.c文件)中#include这个头文件，就能让编译器在编译的时候知道函数的原型。**

    如在[maxProject](./maxProject)中，

    源代码 [main.c](./maxProject/main.c)：

    ```c
    #include<stdio.h>
    #include "max.h"    // 要调用max()函数，所以申明包含这个函数原型的头文件
    
    int main(void)
    {
        int a=5;
        int b=6;
        printf("%d\n",max(a,b));
    
        return 0;
    }
    ```

    源代码 [max.c](./maxProject/max.c)：

    ```c
    #include "max.h"    // 定义max()函数，也要申明包含这个函数原型的头文件
    
    int max(int a, int b)
    {
        return a>b?a:b;
    }
    ```

    **头文件 [max.h](./maxProject/max.h)**：

    ```h
    int max(int a, int b);   // 头文件中对max()函数原型申明
    ```

    定义完上面的main.c, max.c, max.h后，在命令行编译链接main.c：

    ```
    $ gcc main.c max.c -o main
    $ ls
    main  main.c  max.c  max.h
    
    ```

    这里发现如果直接编译main.c会失败：

    ```
    $ gcc main.c  --save-temps
    main.o: In function `main':
    main.c:(.text+0x21): undefined reference to `max'
    collect2: error: ld returned 1 exit status
    
    ```

    可以对main.c只做编译不链接(使用-c,，不产生.out文件，避免error)，同时用"--save-temps"保存中间文件

    ```
    $ gcc main.c -c --save-temps
    $ ls
    main  main.c  main.i  main.o  main.s  max.c  max.h
    
    ```

    然后看一下编译预处理后生成的 main.i文件

    ```
    $ tail -n 14 main.i
    
    # 1 "max.h"
    int max(int a, int b);
    # 3 "main.c" 2
    
    
    int main(void)
    {
        int a=5;
        int b=6;
        printf("%d\n",max(a,b));
    
        return 0;
    }
    
    ```

    由main.i文件内容可以，main.c文件在使用`#include "max.h"`时就把 "max.h"文件的内容直接复制插入到它所在的位置。

    

    (注：**"#include"是编译预处理指令**，和宏一样，在编译之前就处理了，它把include后面的文件的全部文本内容原封不动地插入到它所在的地方。)



- "#include"有两种形式来指出要插入的文件：

    1. ""要求编译器首先在当前目录寻找这个文件，如果没有，到编译器制定目录去找

        如 : `#include "max.h"`

        

    2. <>让编译器只在指定的目录去找

        如: `#include<stdio.h>`

        注：对Linux系统，这个"stdio.h"在 "/usr/include/"目录下



- **`#include`误区：**
    1. `#include`不是用来引入库的
    2. `stdio.h`里只有函数printf的原型，printf()的代码在另外的地方
    3. `#include<stdio.h`只是让编译器知道printf()函数的原型，保证调用时给出正确的参数类型。





### 头文件总结

- 把函数原型放到一个**头文件(以.h结尾)**中，在需要调用这个函数的源代码(.c文件)中#include这个头文件，就能让编译器在编译的时候知道函数的原型。
- 在**使用**和**定义**这个函数的地方都要#include这个头文件
- 一般的做法是任何.c都有对应同名的.h，把所有对外公开的函数的**原型**和**全局变量**的申明都放进去
- 只有声明可以放在头文件中 (是规则不是法律)



- 扩展
    - 在函数前面加上static就使得它成为只能在所在的编译单元中使用的函数
    - 在全局变量前面加上static就使得它成为只能在所在的编译单元中使用的全局变量



## 13.8 声明和标准头文件结构

### 声明

- 变量声明 extern

    假如，在一个项目中，一个源代码中定义了一个变量`int gAll =12;`，要想在另一个源代码中也使用这个变量，需要在头文件中加入这个变量的声明：

    ```h
    // 在头文件.h中声明
    extern int gAll;      
    ```

    

- **声明是不产生代码的东西**

    函数原型、变量声明、结构声明、宏声明、枚举声明、类型声明、inline函数

- **定义是产生代码的东西**



- 只有声明可以被放在头文件中，否则会造成一个项目中多个编译单元中有重名的实体。



### 标准头文件结构

- **重复声明**
    - 同一个比哪一单元中，同名的结构不能被重复声明
    - 但是在代码中，如果头文件有结构的声明，往往这个头文件会在一个编译单元里被#include多次
    - 所以需要**"标准头文件结构"**



- 运用条件编译和宏，保证这个头文件在编译单元中只会被#include一次。

    在max.h像下面代码这样定义标准头文件结构，避免重复声明：

    ```h
    /* 如果没有定义__MAX_H__，则定义__MAX_H__，否则如果已经定义多，则不再重复定义 */
    #ifndef __MAX_H__     
    #define __MAX_H__  
    
    struct Node{
        int value;
        char *name;
    };
    
    #endif            
    ```

    

- 除了运用条件编译和宏的标准头文件结构，某些编译器支持使用`#program once`实现同样的避免重复的功能。



----

1. 翁凯讲义：[全局变量.pdf](./全局变量.pdf)
2. 翁凯讲义：[宏.pdf](./宏.pdf)
3. 翁凯讲义：[大程序.pdf](./大程序.pdf)