# 类

类(Class) 由3个部分构成

- 类的**名称**:类名 （首字母大写）
- 类的**属性**:一组数据----------------------------------------------变量
- 类的**方法**:允许对进行操作的方法 (行为)-------------------方法即类中的函数

```python
# 定义Dog类
class Dog():                             # 定义Dog类（类名首字母大写）
    '''一次模拟小狗的简单尝试'''
    def __init__(self, name, age):       #方法（即类中的函数），方法后必须加形参self
        '''初始化属性name和age'''
        self.name = name                 # 属性（即变量）
        self.age = age                   
        
    def sit(self):                       # 方法
        '''模拟小狗被命令时蹲下'''
        print(self.name.title() + ' is now sitting.')
        
    def roll_over(self):                 # 方法
        '''模拟小狗被命令时打滚'''
        print(self.name.title() + ' rolled over!')
        
    def __str__(self):                   # str方法会自动执行
        '''自动打印小狗的属性'''
        msg = "The name of %s is %d" %(self.name, self.age)
        return msg
        
# 创建实例
my_dog = Dog('willie',6)
print(my_dog.name.title())       # Willie
print(my_dog.age)                # 6

# 调用方法
my_dog.sit()       
my_dog.roll_over()
print(my_dog)             # 打印结果为"The name of willie is 6"，是自动执行__str__(self)的结果
'''
Willie is now sitting.
Willie rolled over!
The name of willie is 6
'''

```

**_ __init__ _(self)方法**

- `__init__()`方法，在创建一个对象时默认被调用，不需要手动调用

- `__init__(self)`中，默认有1个参数名字为self，如果在创建对象时传递了2个实参，那么`__init__(self)`中出了self作为第一个形参外还需要2个形参，例如`__init__(self,x,y)`

- `__init__(self)`中的self参数，不需要开发者传递，python解释器会自动把当前的对象引用传递进去

**“魔法”方法**

- 在python中方法名如果是`__xxxx__()`的，那么就有特殊的功能，因此叫做“魔法”方法

- 当使用print输出对象的时候，只要自己定义了`__str__(self)`方法，那么就会打印从在这个方法中return的数据

**self**

- 所谓的self，可以理解为自己

- 可以把self当做C++中类里面的this指针一样理解，就是对象自身的意思

- 某个对象调用其方法时，python解释器会把这个对象作为第一个参数传递给self，所以开发者只需要传递后面的参数即可

  







-----

参考链接

1. [廖雪峰Python教程-类和实例](<https://www.liaoxuefeng.com/wiki/1016959663602400/1017496031185408>)
2. Eric Matthes 著《Python从入门到实践》第九章 类