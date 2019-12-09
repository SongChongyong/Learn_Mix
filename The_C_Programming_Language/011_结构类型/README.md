## 11

# 11 结构类型

## 11.1 枚举 enum

- 常量符号化：用符号而不是具体的数字来表示程序中的数字，增加程序的可读性。

    ```c
    #include <stdio.h>
    // 此代码error 
    const int red = 0;
    const int yellow = 1;
    const int green = 2;
     
    int main(int argc,char const *argv[]){
    	int colour = -1;
        char *colourName = NULL;
     
        printf("Please input your favorite colour code:\n");
        printf("(red 0, yellow 1, green 2)");
        scanf("%d", &colour);
        switch(colour){
            case red: colourName = "red"; break;
            case yellow: colourName = "yellow";break;
            case green: colourName = "green";break;
            default: colourName = "unknown";break;
        }
        printf("Your favorite colour is: %s\n",colourName);
        return 0;
    }
      
    ```

    (详细代码见: [01_const.c](./01_const.c))



- **枚举**：用枚举而不是定义独立的const int变量，而是可以定义一些排列起来的常量值

    枚举是一种用户定义的数据类型，它用关键字enum以如下语法来申明：

    **enmu 枚举类型名字 {名字0, 名字1,...,名字n};**

    枚举类型名字通常并不真的使用，要用的是在大括号里的名字，这些名字就是字符常量，它们的类型是int，值从0到n。

    如：`enmu colours{red, yellow, green};`：创建了三个常量，red的值是0，yellow是1，green是2

    ```c
    #include <stdio.h>
    
    enum COLOURS {RED, YELLOW, GREEN}; 
     
    int main(int argc,char const *argv[])
    {
    	int colour = -1;
        char *colourName = NULL;
     
        printf("Please input your favorite colour code:");
        printf("(red 0, yellow 1, green 2) ");
        scanf("%d", &colour);
        switch(colour)
    	{
            case RED: colourName = "red"; break;
            case YELLOW: colourName = "yellow";break;
            case GREEN: colourName = "green";break;
            default: colourName = "unknown";break;
        }
        printf("Your favorite colour is: %s\n",colourName);
        return 0;
    }
    /*
    Please input your favorite colour code:(red 0, yellow 1, green 2) 1
    Your favorite colour is: yellow
    */
    ```

    (详细代码见: [02_enum_colours.c](./02_enum_colours.c))



- 枚举量可以作为值，枚举类型可以跟上enum作为类型，但是在实际上**以整数来做内部计算和外部输入输出**。

    ```c
    #include<stdio.h>
    
    enum colour {red, yellow, green};
    
    void fun(enum colour c); 
    int main(void)
    {
    	//! showMemory(start=65520)
    	enum colour t = red;
    	scanf("%d", &t);
    	fun(t);
    	return 0;
    }
    
    void fun(enum colour c)
    {
    	printf("%d\n", c);
    }
    ```

    

- **自动计数的枚举**

    下面代码使用枚举实现计数， NumCOLOURS = 4，可以在后续遍历、数组下标时使用。

    ```c
    #include <stdio.h>
    
    enum COLOURS {RED, YELLOW, GREEN, NumCOLOURS};  // 使用枚举实现计数， NumCOLOURS = 4 
     
    int main(int argc,char const *argv[])
    {
    	int colour = -1;
    	char *ColourNames[NumCOLOURS] = {"red", "yellow", "green",};
        char *colourName = NULL;
     
        printf("Please input your favorite colour code:");
        printf("(red 0, yellow 1, green 2) ");
        scanf("%d", &colour);
        if (colour>=0 && colour<NumCOLOURS){
        	colourName = ColourNames[colour];
        }
        else {
        	colourName = "unknown";
        }
        printf("Your favorite colour is: %s\n",colourName);
        return 0;
    }
    /*
    Please input your favorite colour code:(red 0, yellow 1, green 2) 2
    Your favorite colour is: green
    */
      
    ```

    (详细代码见: [04_enum_circle.c](./04_enum_circle.c))



- **申明枚举量的时候可以指定值，未指定的就在前一个值的基础上+1**

    `enum COLOURS {RED=1, YELLOW, GREEN=5};`

    表示RED=1, YELLOW=2, GREEN=5

    

### 枚举总结

1. **枚举类型在实际上以int类型来做内部计算和外部输入输出，枚举是一个常量整型值的列表**
2. 枚举类型可以当做类型来使用，但是实际上不好用，很少使用
3. 枚举比宏(macro)好，因为枚举有int类型



## 11.2 结构

引例：

```c
#include<stdio.h>

int main()
{
    // 申明data结构
	struct date {
		int month;
		int day;
		int year;
	};
	
	struct date today;  // 结构变量
	today.month = 12;
	today.day = 8;        
	// 这些写"08"会error:invalid digit "8" in octal constant 表示如果以0开始就是8进制常量，08无效了 
	// 所以要打印 XXXX-0X-0X用这个程序实现不了 
	today.year = 2019;
	printf("Today's date is %i-%i-%i.\n", today.year, today.month, today.day);
	// Today's date is 2019-12-8. 
	
	return 0;
}
```

(详细代码见: [05_struct_date.c](./05_struct_date.c))

- 和本地变量一样，**在函数内部声明的结构类型只能在函数内部使用**，所以通常在函数外部声明结构类型，这样就可以被多个函数所使用

    

- **结构申明**三种方式：

![33结构申明.png](C:/Users/yong/Desktop/The_C_Programming_Language/images/33%E7%BB%93%E6%9E%84%E7%94%B3%E6%98%8E.png)

对于第一和第三种形式，都声明了结构point。但是第二种形式没有声明point，只是定义了两个变量。



- **结构变量及其初始化**

```c
#include<stdio.h>

// 申明data结构
struct date {
	int month;
	int day;
	int year;
};

int main()
{	
	//! showMemory(start=65520)
    struct date today = {07,31,2014};  				 // 结构变量及初始化 
	struct date thisMonth = {.month=7, .year=2014};  // 结构变量及初始化     

	printf("Today's date is %i-%i-%i.\n", today.year, today.month, today.day);
    printf("Today's date is %i-%i-%i.\n", thisMonth.year, thisMonth.month, thisMonth.day);
	// Today's date is 2014-7-31.
	// Today's date is 2014-7-0. 
	
	return 0;
}
```



- 结构成员

    结构与数字有点像:

    1. 数字用"[]"运算符和下标访问其成员，如`a[0] =10`;
    2. 结构用"."运算符和名字访问其成员，如`today.day`, `pl.x`, `pl.y`





------

## 参考资料

1. 翁恺讲义：[枚举.pdf](./枚举.pdf)
2. 翁恺讲义：[结构.pdf](./结构.pdf)
3. 翁恺讲义：[联合.pdf](./联合.pdf)