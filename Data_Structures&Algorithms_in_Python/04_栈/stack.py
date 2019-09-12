# coding:utf-8

class Stack(object):
    """栈"""
    def __init__(self):
        self.__list = []      # 用列表来实现这个Stack(容器)，且封装成私有

    def push(self, item):
        """添加一个新的元素item到栈顶"""
        self.__list.append(item)  # 用列表的append()函数添加元素

    def pop(self):
        """弹出栈顶元素"""
        return self.__list.pop()    # 用列表的pop()函数添加元素

    def peek(self):
        """返回栈顶元素"""
        if self.__list:
            # 当列表不为空时
            return self.__list[-1]  # 直接返回列表的尾部元素
        else:
            # 列表为空时，返回None
            return None

    def is_empty(self):
        """判断栈是否为空"""
        return self.__list == []
        # return not self.__list

    def size(self):
        """返回栈的元素个数"""
        return len(self.__list)


if __name__ == "__main__":
    stack = Stack()
    stack.push("hello")
    stack.push("world")
    stack.push("itcast")
    print (stack.size())
    print (stack.peek())
    print (stack.pop())
    print (stack.pop())
    print (stack.pop())
'''
3
itcast
itcast
world
hello
'''
