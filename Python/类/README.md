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

## _ __init__ _(self)方法

- `__init__()`方法，在创建一个对象时默认被调用，不需要手动调用

- `__init__(self)`中，默认有1个参数名字为self，如果在创建对象时传递了2个实参，那么`__init__(self)`中出了self作为第一个形参外还需要2个形参，例如`__init__(self,x,y)`

- `__init__(self)`中的self参数，不需要开发者传递，python解释器会自动把当前的对象引用传递进去

## “魔法”方法

- 在python中方法名如果是`__xxxx__()`的，那么就有特殊的功能，因此叫做“魔法”方法

- 当使用print输出对象的时候，只要自己定义了`__str__(self)`方法，那么就会打印从在这个方法中return的数据

## self

- 所谓的self，可以理解为自己

- 可以把self当做C++中类里面的this指针一样理解，就是对象自身的意思

- 某个对象调用其方法时，python解释器会把这个对象作为第一个参数传递给self，所以开发者只需要传递后面的参数即可


## 保护(隐藏)对象的属性

如果有一个对象，当需要对其进行修改属性时，有2种方法

- 对象名.属性名 = 数据 ---->直接修改

- **对象名.方法名() ---->间接修改(推荐使用,可以在方法中方法中定义各种限制属性)**

  ```python
  class Dog:
      def set_age(self,new_age):
          '''设置年龄,同时合法年龄在0~100范围内,若不在范围,默认设置为0'''
          # 用判断语句把new_age设置在0~100范围内
          if new_age>0 and new_age<=100: 
              self.age = new_age
          else:
              self.age = 0
      
      def get_age(self):
          '''获取年龄age'''
          return self.age
  
  dog = Dog()
  dog.set_age(10)       # 调用方法set_age来设置年龄为10
  age = dog.get_age()   # 获取年龄
  print(age)		# 10
  ```

  完整代码见:[隐藏对象的属性.py](./隐藏对象的属性.py)

## 私有方法

为了更好的保存属性安全，即不能随意修改，一般的处理方式为

- 将属性定义为**私有属性**,仅仅可以在class内调用这个方法
- 添加一个可以调用的方法，供调用这个私有方法
- 在方法前加双下划线'__'即创建的是私有方法

```python
class Dog:

    #私有方法
    def __send_msg(self):
        print("------正在发送短信------")

    #公有方法
    def send_msg(self, new_money):
        if new_money>10000:
            self.__send_msg()     # 仅可以在class内调用私有方法__send_msg
        else:
            print("余额不足,请先充值 再发送短信")
```

完整代码见:[私有方法.py](./私有方法.py)

## __del__()方法

创建对象后，python解释器默认调用`__init__()`方法；

当删除一个对象时，python解释器也会默认调用一个方法，这个方法为`__del__()`方法

```python
class Animal(object):
	...
    # 析构方法
    # 当对象被删除时，会自动被调用
    def __del__(self):
        print("__del__方法被调用")
        print("%s对象马上被干掉了..."%self.__name)

# 创建对象
dog = Animal("哈皮狗")
# 删除对象
del dog

```

完整代码见[delete_class.py](./delete_class.py)

#### 总结

- 当有1个变量保存了对象的引用时，此对象的引用计数就会加1
- 当使用del删除变量指向的对象时，如果对象的引用计数不会1，比如3，那么此时只会让这个引用计数减1，即变为2，当再次调用del时，变为1，如果再调用1次del，此时会真的把对象进行删除







-----

参考链接

1. [廖雪峰Python教程-类和实例](<https://www.liaoxuefeng.com/wiki/1016959663602400/1017496031185408>)
2. Eric Matthes 著《Python从入门到实践》第九章 类