# edX C Programming Linked List

## 5.2 Structures and Pointers

### 5.2.3 Get to know the concept of a linked list

#### 5.2.3.1 Link structures together in a linked list

将结构用指针连起来构建成一个链表：

```c
#include <stdio.h>

struct point{
    int x;
    int y;
    struct point * next;
};

int main(void) {
    //! showMemory(start=65520)
    struct point pt1 = {1, 2, NULL};
    struct point pt2 = {-2, 3, NULL};
    struct point pt3 = {5, -4, NULL};
    struct point * start, * ptr;
    
    start = &pt1;
    pt1.next = &pt2;
    pt2.next = &pt3;
    
    ptr = start;
    while (ptr!=NULL) {
        printf("(%d, %d)\n", ptr->x, ptr->y);
        ptr = ptr->next;
    }
	return 0;
}
/*
(1, 2)                                                                          
(-2, 3)                                                                         
(5, -4) 
*/

```

下面是构建过程中地址的变化：

![01_linked_list.png](./images/01_linked_list.png)



#### 5.2.3.2 Print a linked list

改造5.2.3.1的代码，用一个函数实现main函数中的while循环，打印所有点的坐标。

```c
#include <stdio.h>

struct point{
    int x;
    int y;
    struct point * next;
};
void printPoints(struct point *start);
int main(void) {
    //! showMemory(start=65520)
    struct point pt1 = {1, 2, NULL};
    struct point pt2 = {-2, 3, NULL};
    struct point pt3 = {5, -4, NULL};
    struct point * start;       
    
    start = &pt1;
    pt1.next = &pt2;
    pt2.next = &pt3;
    
    printPoints(start);
	return 0;
}

void printPoints(struct point *start) {
    //! showMemory(start = 65520, cursors=[ptr])
    struct point * ptr;    // ptr是一个游动的指针，用来实现遍历
    ptr = start;
    while (ptr!=NULL) {
        printf("(%d, %d)\n", ptr->x, ptr->y);
        ptr = ptr->next;
    }
}
/*
(1, 2)                                                                          
(-2, 3)                                                                         
(5, -4) 
*/
```

此时，在printPoints()函数中，指针ptr的变化状态是：

![02_pointer_ptr_memory.png](./images/02_pointer_ptr_memory.png)



#### 5.2.3.3 Append new nodes to a linked list

上面代码通过语句 `start = &pt1;pt1.next = &pt2; pt2.next = &pt3;`来实现结构节点间的链接，现在尝试用函数来实现：

```c
#include <stdio.h>

struct point{
    int x;
    int y;
    struct point * next;
};
void printPoints(struct point *start);
struct point * append (struct point * end, struct point * newpt);
int main(void) {
    //! showMemory(start=65520)
    struct point pt1 = {1, 2, NULL};
    struct point pt2 = {-2, 3, NULL};
    struct point pt3 = {5, -4, NULL};
    
	/*创建start指针来存储链表起始位置
	  创建end指针作为节点尾部，每次更新end指针实现连接*/
    struct point * start, * end;      
    start = end = &pt1;
    end = append(end, &pt2);
    end = append(end, &pt3);
    
    printPoints(start);
    
	return 0;
}

void printPoints(struct point *start) {
    //! showMemory(start = 65520, cursors=[ptr])
    struct point * ptr;
    ptr = start;
    while (ptr!=NULL) {
        printf("(%d, %d)\n", ptr->x, ptr->y);
        ptr = ptr->next;
    }
}
/* 
将指针newpt所指的结构变量添加到指针end所指的结构变量后面，并返回新列表的end 
pass the current end of a list and the adress of a new point,
the new point will be appened to the list, ant it returns a new end of the list
*/
struct point * append (struct point * end, struct point * newpt) {
    end->next = newpt;
    return(end->next);
} 
```



#### 5.2.3.4 Delete a linked list

输入num个点，然后将他们连接成链表。由于num的数不定，所以不能直接用数组实现，需要用指针，同时需要malloc申请内存空间，完整代码如下：

```c
#include <stdio.h>
#include <stdlib.h>
struct point{
    int x;
    int y;
    struct point * next;
};
void printPoints(struct point *start);
struct point * createPoint(int x, int y) ;
struct point * append (struct point * end, struct point * newpt);
void freePoints(struct point * start);
int main(void) {
    //! showMemory(start=65520)
    struct point * start, * end, * newpt;
    int num, i;
    int x, y;
    
    printf("How many points? ");
    scanf("%d", &num);
    
    /* 循环输入num个点的坐标,并添加到链表的节点*/
    for (i=0; i<num; i++) {
        printf("x = ");
        scanf("%d", &x);
        printf("y = ");
        scanf("%d", &y);
        newpt = createPoint(x,y);
        if (i==0) {
            start = end = newpt;
        } else {
            end = append(end,newpt);
        }
    }
    printf("You entered: ");
    printPoints(start);
    freePoints(start);        /*释放creatPoint()函数申请的内存*/
	return 0;
}

/*从头开始，遍历打印所有的点的坐标*/
void printPoints(struct point *start) {
    //! showMemory(start = 65520, cursors=[ptr])
    struct point * ptr;
    ptr = start;
    while (ptr!=NULL) {
        printf("(%d, %d)\n", ptr->x, ptr->y);
        ptr = ptr->next;
    }
}

/*将指针newpt所指的结构变量添加到指针end所指的结构变量后面，并返回新列表的end*/
struct point * append (struct point * end, struct point * newpt) {
    end->next = newpt;
    return(end->next);
} 

/*传入点的x坐标和y坐标，将值传入相应节点point，并返回该节点point的地址*/
struct point * createPoint(int x, int y) {
    struct point *ptr;
    ptr = (struct point *)malloc(sizeof(struct point));
    ptr->x = x;
    ptr->y = y;
    ptr->next = NULL;
    return(ptr);
}

/*
释放creatPoint()函数申请的内存
由于如果直接free掉start的内存，就会不知道下一个元素保存在哪里，所以先用一个ptr来保存一下当前start地址
*/
void freePoints(struct point * start) {
    struct point * ptr = start;
    while (ptr!=NULL) {
        start = ptr;
        ptr = ptr->next;
        free(start);
    }
}

/*
How many points? 2                                                              
x = 3                                                                           
y = 4                                                                           
x = 5                                                                                               y = 6                                                                           
You entered: (3, 4)                                                             
(5, 6) 
*/
```

运行creatPoint()函数过程的流程图及内存变化：

![03_createPoin_memory.png](./images/03_createPoin_memory.png)



## 5.3 Linked list

### 5.3.1 Create a node of a linked list







----

## 参考资料

1. 翁恺讲义：[可变数组.pdf](./可变数组.pdf)
2. 翁恺讲义：[链表.pdf](./链表.pdf)