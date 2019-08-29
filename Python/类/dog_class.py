# coding：utf-8

# 定义Dog类
class Dog():                             # 定义Dog类（类名首字母大写）
    '''一次模拟小狗的简单尝试'''
    def __init__(self, name, age):       #方法（即类中的函数），方法后必须加形参self
        '''初始化属性name和age'''
        self.name = name                # 属性（即变量）
        self.age = age                    # 属性（即变量）
        
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