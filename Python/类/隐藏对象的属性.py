# coding:utf-8

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
print(age)

