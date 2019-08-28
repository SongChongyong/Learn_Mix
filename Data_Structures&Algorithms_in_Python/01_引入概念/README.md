# 1.引入概念

[TOC]


题目：如果 a+b+c=1000，且 a^2+b^2=c^2（a,b,c 为自然数），如何求出所有a、b、c可能的组合?

## 1.1 第一次尝试

**枚举法**

```python
# 枚举法
import time
start_time = time.time()

for a in range(0,1001):
    for b in range(0,1001):
        for c in range(0,1001):
            if a+b+c==1000 and a**2+b**2==c**2:
                print("a, b, c: %d, %d, %d"  %(a,b,c))

end_time = time.time()
print("elapsed: %f" % (end_time - start_time))
print("complete!")  
'''
a, b, c: 0, 500, 500
a, b, c: 200, 375, 425
a, b, c: 375, 200, 425
a, b, c: 500, 0, 500
elapsed: 164.262470
complete!
'''
```



## 1.2 算法的提出

**算法是独立存在的一种解决问题的方法和思想。**

**算法的五大特性**

1. **输入**: 算法具有0个或多个输入
2. **输出**: 算法至少有1个或多个输出
3. **有穷性**: 算法在有限的步骤之后会自动结束而不会无限循环，并且每一个步骤可以在可接受的时间内完成
4. **确定性**：算法中的每一步都有确定的含义，不会出现二义性
5. **可行性**：算法的每一步都是可行的，也就是说每一步都能够执行有限的次数完成



## 1.3 第二次尝试

a+b+c=1000, 则c = 1000-a-b, 不需要进行c的循环判断了

```python
# 注意是两重循环
start_time = time.time()
for a in range(0, 1001):
    for b in range(0, 1001-a):
        c = 1000 - a - b
        if a**2 + b**2 == c**2:
            print("a, b, c: %d, %d, %d" % (a, b, c))

end_time = time.time()
print("elapsed: %f" % (end_time - start_time))
print("complete!")
'''
a, b, c: 0, 500, 500
a, b, c: 200, 375, 425
a, b, c: 375, 200, 425
a, b, c: 500, 0, 500
elapsed: 0.729935
complete!
'''
```

## 

## 1.4 算法效率衡量

- (1) **执行时间**衡量算法效率

  **实现算法程序的执行时间可以反应出算法的效率，即算法的优劣**

  程序的运行离不开计算机环境（包括硬件和操作系统），这些客观原因会影响程序运行的速度并反应在程序的执行时间上，**单纯依靠运行的时间来比较算法的优劣并不一定是客观准确的！**

  

- (2) 时间复杂度与“大O记法”

  算法对于不同的机器环境而言，确切的单位时间是不同的，但是对于**算法进行多少个基本操作（即花费多少时间单位）**在规模数量级上却是相同的，由此可以忽略机器环境的影响而客观的反应算法的时间效率。

  对第一次尝试，基本操作个数T = 1000 * 1000 * 1000 * 2

  当条件变为"a+b+c=2000" 时，基本操作个数T = 1000 * 1000 * 1000 * 2

  ...

  当条件变为"a+b+c=n" 时，基本操作个数T = n * n * n * 2

  即最终的时间复杂度和解决问题的N有关，"T(n) = n^3*2"**

  T(n) = n^3*2

  g(n) = n^3, 则**函数g是f的一个渐近函数**

  **T(n)=O(g(n))=n^3----------------就是这个程序的时间复杂度**

  

  - **“大O记法”**：对于单调的整数函数f，如果存在一个整数函数g和实常数c>0，使得对于充分大的n总有f(n)<=c\*g(n)，就说函数g是f的一个渐近函数（忽略常数），记为f(n)=O(g(n))。也就是说，在趋向无穷的极限意义下，函数f的增长速度受到函数g的约束，亦即函数f与函数g的特征相似。
  - **时间复杂度**：假设存在函数g，使得算法A处理规模为n的问题示例所用时间为T(n)=O(g(n))，则称O(g(n))为算法A的渐近时间复杂度，简称时间复杂度，记为T(n)

  

- (3) 最坏时间复杂度

  分析算法时，存在几种可能的考虑：

  - 算法完成工作最少需要多少基本操作，即**最优时间复杂度**
  - 算法完成工作最多需要多少基本操作，即**最坏时间复杂度**
  - 算法完成工作平均需要多少基本操作，即**平均时间复杂度**

  

  对于最坏时间复杂度，提供了一种保证，表明算法在此种程度的基本操作中一定能完成工作。最坏时间复杂度也是我们需要关注的。

  

- (4) 时间复杂度的几条基本计算规则

  1. 基本操作，即只有常数项，认为其时间复杂度为O(1)
  2. 顺序结构，时间复杂度按**加法**进行计算
  3. 循环结构，时间复杂度按**乘法**进行计算
  4. 分支结构，时间复杂度**取最大值**
  5. 判断一个算法的效率时，往往只需要关注操作数量的最高次项，其它次要项和常数项可以忽略
  6. 在没有特殊说明时，我们所分析的算法的时间复杂度都是指**最坏时间复杂度**



## 1.5 算法分析

1. 第一次尝试的算法核心部分

```python
for a in range(0, 1001):
    for b in range(0, 1001):
        for c in range(0, 1001):
            if a**2 + b**2 == c**2 and a+b+c == 1000:
                print("a, b, c: %d, %d, %d" % (a, b, c))
```

  **时间复杂度：**

T(n) = O(n * n * n) = O(n^3)

2. 第二次尝试的算法核心部分

```python
for a in range(0, 1001):
    for b in range(0, 1001-a):
        c = 1000 - a - b
        if a**2 + b**2 == c**2:
            print("a, b, c: %d, %d, %d" % (a, b, c))
```

**时间复杂度：**

T(n) = O(n * n * (1+1)) = O(n * n) = O(n^2)

**由此可见，我们尝试的第二种算法要比第一种算法的时间复杂度好多的。**



## 1.6 常见时间复杂度

**常见时间复杂度**

| 执行次数函数举例 |     阶     | 非正式术语 |
| ---------------- | :--------: | :--------- |
| 12               |    O(1)    | 常数阶     |
| 2n+3             |    O(n)    | 线性阶     |
| 3n2+2n+1         |   O(n2)    | 平方阶     |
| $5log_2n+20$     | $O(logn)$  | 对数阶     |
| $2n+3nlog_2n+19$ | $O(nlogn)$ | nlogn阶    |
| 6n3+2n2+3n+4     |   O(n3)    | 立方阶     |
| 2n               |   O(2n)    | 指数阶     |

**注意，经常将$log_2n$（以2为底的对数）简写成logn**

**常见时间复杂度之间的关系**

![01算法效率关系](C:/Users/yong/Desktop/Data_Structures&Algorithms_in_Python/01_%E5%BC%95%E5%85%A5%E6%A6%82%E5%BF%B5/pictures/01%E7%AE%97%E6%B3%95%E6%95%88%E7%8E%87%E5%85%B3%E7%B3%BB.bmp)

所消耗的时间从小到大
$$
O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)
$$


## 1.7 Python内置类型性能分析

- **timeit模块**

  timeit模块可以用来测试一小段Python代码的执行速度。

  **class timeit.Timer(stmt='pass', setup='pass', timer=<timer function>)**

  Timer是测量小段代码执行速度的类。

  stmt参数是要测试的代码语句（statment）；

  setup参数是运行代码时需要的设置；

  timer参数是一个定时器函数，与平台有关。

  **timeit.Timer.timeit(number=1000000)**

  Timer类中测试语句执行速度的对象方法。number参数是测试代码时的测试次数，默认为1000000次。方法返回执行代码的平均耗时，一个float类型的秒数


- list的操作测试

```python
def test1():
   l = []
   for i in range(1000):
      l = l + [i]
def test2():
   l = []
   for i in range(1000):
      l.append(i)
def test3():
   l = [i for i in range(1000)]
def test4():
   l = list(range(1000))
   
t1 = Timer("test1()", "from __main__ import test1")
print("concat ",t1.timeit(number=1000), "seconds")
t2 = Timer("test2()", "from __main__ import test2")
print("append ",t2.timeit(number=1000), "seconds")
t3 = Timer("test3()", "from __main__ import test3")
print("comprehension ",t3.timeit(number=1000), "seconds")
t4 = Timer("test4()", "from __main__ import test4")
print("list range ",t4.timeit(number=1000), "seconds")

'''
concat  1.735037316 seconds
append  0.07950437899999985 seconds
comprehension  0.04237880400000016 seconds
list range  0.01636211700000012 seconds
'''
# 由结果可知，使用concat费时特别长，所以程序中尽量少用列表加法

x = range(2000000)
pop_zero = Timer("x.pop(0)","from __main__ import x")
print("pop_zero ",pop_zero.timeit(number=1000), "seconds")
x = range(2000000)
pop_end = Timer("x.pop()","from __main__ import x")
print("pop_end ",pop_end.timeit(number=1000), "seconds")
```



**list内置操作的时间复杂度**

![list内置操作的时间复杂度](./pictures/list操作.png)

**dict内置操作的时间复杂度**

![dict内置操作的时间复杂度](./pictures/dict操作.png)



## 1.8 数据结构

问题： 我们如何用Python中的类型来保存一个班的学生信息(name,age,hometown)？  如果想要快速的通过学生姓名获取其信息呢？

```python
# 方法一：列表+元组
[
    ("Zhangsan", 24, "Beijing")
    ("Zhangsan", 24, "Beijing")
    ("Zhangsan", 24, "Beijing")
]
# 找到特定的"Zhangsan"学生的信息
for stu in staus:
    if stu(0)=="Zhangsan": #找到特定的"Zhangsan"学生的信息

# 方法二：列表+字典
[
    {
        "name": "Zhangsan",
        "age": 23,
        "hometown": "Beijing"
    }
]

# 方法三：字典+字典
{
    "Zhangsan":{
        "age":24,
        "hometown": Beijing
        }
}
# 找到特定的"Zhangsan"学生的信息
stus["Zhangsan"]
```

可以看到方法三和方法一要找到"Zhangsan"学生的信息算法不一样，所以，数据保存的类型不一样，程序的算法也不一样，这就引出“**数据结构**”问题。

**数据**是一个抽象的概念，将其进行分类后得到程序设计语言中的基本类型。如：int，float，char等。数据元素之间不是独立的，存在特定的关系，这些关系便是结构。数据结构指数据对象中数据元素之间的关系。

Python给我们提供了很多现成的数据结构类型，这些系统自己定义好的，不需要我们自己去定义的数据结构叫做Python的**内置数据结构**，比如<u>列表、元组、字典</u>。而有些数据组织方式，Python系统里面没有直接定义，需要我们自己去定义实现这些数据的组织方式，这些数据组织方式称之为**Python的扩展数据结构**，比<u>如栈，队列</u>等。

- **算法与数据结构的区别**

  数据结构只是静态的描述了数据元素之间的关系。

  高效的程序需要在数据结构的基础上设计和选择算法。

  **程序 = 数据结构 + 算法**

  **总结：算法是为了解决实际问题而设计的，数据结构是算法需要处理的问题载体**

- **抽象数据类型(Abstract Data Type)**

  抽象数据类型(ADT)的含义是指一个数学模型以及定义在此数学模型上的一组操作。即<u>把数据类型和数据类型上的运算捆在一起，进行封装。</u>

  引入抽象数据类型的目的是把数据类型的表示和数据类型上运算的实现与这些数据类型和运算在程序中的引用隔开，使它们相互独立。

  最常用的数据运算有五种：

  - 插入
  - 删除
  - 修改
  - 查找
  - 排序