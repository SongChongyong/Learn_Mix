# coding:utf-8

class SingleNode(object):
    """单链表的结点"""
    def __init__(self,item):
        # _item存放数据元素
        self.item = item
        # _next是下一个节点的标识
        self.next = None


class SingleLinkList(object):
    """单链表"""
    def __init__(self):
        self.__head = None

    def is_empty(self):
        """判断链表是否为空"""
        return self.__head == None  # __head指向为空(None)，则列表为空
    
    def length(self):
        """链表长度"""
        # cur初始时指向头节点(cur表示一个指针、游标，用来移动遍历节点)
        cur = self.__head
        count = 0           # count记录数量，初始化为0
        # 尾节点指向None，当未到达尾部时
        while cur != None:
            count += 1
            # 将cur后移一个节点
            cur = cur.next
        return count
    
    def travel(self):
        """遍历链表"""
        cur = self.__head
        while cur != None:
            print (cur.item, end=" ")   # 用end=" "让遍历元素直接空一格打印而不是换行打印
            cur = cur.next
        print ("")
    
    def append(self, item):
        """尾部添加元素，尾插法"""
        
        # 先构造节点
        # 函数里的形参item只是一个数，还不是一个节点，所以要先构造为一个节点
        node = SingleNode(item)
        
        # 判断链表是否为空，若是空链表，则将__head指向新节点
        if self.is_empty():
            self.__head = node
        # 若不为空，则找到尾部，将尾节点的next指向新节点
        else:
            cur = self.__head
            while cur.next != None:
                cur = cur.next
            cur.next = node
    
    def add(self, item):
        """头部添加元素，头插法"""
        # 先创建一个保存item值的节点
        node = SingleNode(item)
        # 将新节点的链接域next指向头节点，即__head指向的位置
        node.next = self.__head
        # 将链表的头__head指向新节点
        self.__head = node
    
    def insert(self, pos, item):
        """
                    指定位置添加元素：参数pos从0开始
                    如 insert(2,100)表示在2位置添加节点100            
        """
        # 若指定位置pos为第一个元素之前，则执行头部插入
        if pos <= 0:
            self.add(item)
        # 若指定位置超过链表尾部，则执行尾部插入
        elif pos > (self.length()-1):
            self.append(item)
        # 找到指定位置
        else:
            node = SingleNode(item)
            count = 0
            # pre用来指向指定位置pos的前一个位置pos-1，初始从头节点开始移动到指定位置
            pre = self.__head       # pre先指向头结点
            while count < (pos-1):
                count += 1
                pre = pre.next      # 往后移动pre直到pos-1位置
            # 先将新节点node的next指向插入位置的节点
            node.next = pre.next
            # 将插入位置的前一个节点的next指向新节点
            pre.next = node    
 
    def search(self,item):
        """链表查找节点是否存在，并返回True或者False"""
        cur = self.__head
        while cur != None:
            if cur.item == item:
                return True
            cur = cur.next
        return False

    def remove(self,item):
        """删除节点"""
        cur = self.__head   # 指针cur指向当前节点，初始时指向头节点__head
        pre = None          # 指针pre指向前一个节点，初始时为None
        while cur != None:
            # 找到了指定元素
            if cur.item == item:
                # 如果第一个就是删除的节点
                # 先判断此节点是否是头结点
                if not pre:            # 也可以直接写成 "if cur == self.__head" 来判断是不是头结点   
                    # 将头指针指向头节点的后一个节点
                    self.__head = cur.next
                # 第一个就是删除的节点,但是此节点(cur)不是头结点
                else:
                    # 将删除位置前一个节点的next指向删除位置的后一个节点
                    pre.next = cur.next
                break   # 删除完节点需要退出循环
            else:
                # 继续按链表后移节点
                pre = cur
                cur = cur.next    
           
        
# 测试append是否成功
if __name__ == "__main__":
    link_1 = SingleLinkList()   # 创建空链表link_1
    print(link_1.is_empty())    # 判断link_1是否为空，结果为True
    print(link_1.length())      # 打印link_1长度,结果为0
    
    link_1.append(1)            # 往link_1尾端添加元素1
    print(link_1.is_empty())    # False
    print(link_1.length())      # 结果为1
    
    link_1.append(2)            # 往link_1尾端添加元素2
    link_1.append(3)            # 往link_1尾端添加元素3
    link_1.travel()             # 结果为1 2 3
    
    link_1.add(0)               # 往link_1头部添加元素0
    link_1.travel()             # 结果为0 1 2 3
    
    link_1.insert(-1, -100)     # 在-1位置添加-100节点，即在头部添加-100， 
    link_1.travel()             # 结果为-100 0 1 2 3
    link_1.insert(3, 1.5)       # 在3位置添加1.5节点 
    link_1.travel()             # -100 0 1 1.5 2 3 
    link_1.insert(10, 100)      # 在10位置添加100节点，10位置大于链表的 length()-1，所以等效于在尾部添加
    link_1.travel()             # -100 0 1 1.5 2 3
    
    link_1.remove(1.5)          # 删除1.5节点
    link_1.travel()             # -100 0 1 2 3 100 
    link_1.remove(-100)         # 删除头结点-100
    link_1.travel()             # 0 1 2 3 100 
    link_1.remove(3)            # 删除尾节点3
    link_1.travel()             # 0 1 2 100 

'''
True
0
False
1
1 2 3 
0 1 2 3 
-100 0 1 2 3 
-100 0 1 1.5 2 3 
-100 0 1 1.5 2 3 100 
-100 0 1 2 3 100 
0 1 2 3 100 
0 1 2 100  
'''  
    