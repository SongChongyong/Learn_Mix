# coding:utf-8


class Node(object):
    """单向循环链表的结点"""
    def __init__(self,item):
        # _item存放数据元素
        self.item = item
        # _next是下一个节点的标识
        self.next = None


class SingCycleleLinkList(object):
    """单向循环链表"""
    def __init__(self,node=None):
        self.__head = node
        # 设置循环
        if node:
            node.next = node

    def is_empty(self):
        """判断链表是否为空"""
        return self.__head == None  # __head指向为空(None)，则列表为空
    
    def length(self):
        """链表长度"""

        # 如果链表为空，返回长度0
        if self.is_empty():
            return 0
        count = 1           # count记录数量，初始化为1 (与单链表不一样)
                # cur初始时指向头节点(cur表示一个指针、游标，用来移动遍历节点)
        cur = self.__head
        # 当未到达尾部时
        while cur.next != self.__head:
            count += 1
            # 将cur后移一个节点
            cur = cur.next
        return count
    
    def travel(self):
        """遍历链表"""
        # 如果链表为空，直接返回
        if self.is_empty():
            return
        cur = self.__head
        while cur.next != self.__head:
            print (cur.item, end=" ")   # 用end=" "让遍历元素直接空一格打印而不是换行打印
            cur = cur.next
            # 退出此循环，cur指向尾结点，单尾结点不执行循环，尾结点未打印
        print (cur.item) #  单独打印循环中未执行的尾结点
        
    def add(self, item):
        """头部添加元素，头插法"""
        node = Node(item)
        if self.is_empty():
            self.__head = node
            node.next = self.__head
        else:
            # (1) 添加的节点指向__head (这一步还不改变整个链表位置)
            node.next = self.__head
            # (2) 指针移到链表尾部，将尾部节点的next指向node
            cur = self.__head
            while cur.next != self.__head:
                cur = cur.next
            cur.next = node
            # (3) __head指向添加node的
            self.__head = node

    
    def append(self, item):
        """尾部添加节点，尾插法"""
        node = Node(item)
        if self.is_empty():
            self.__head = node
            node.next = self.__head
        else:
            # 移到链表尾部
            cur = self.__head
            while cur.next != self.__head:
                cur = cur.next
            # 将尾节点指向node
            cur.next = node
            # 将node指向头节点__head
            node.next = self.__head
    
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
            node = Node(item)
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
 
    def search(self, item):
        """查找节点是否存在"""
        if self.is_empty():
            return False
        cur = self.__head  # 指向头结点
        while cur.next != self.__head:
            cur = cur.next
            if cur.item == item:
                return True
        # 退出循环后，cur指向尾节点，这里还需额外判断尾结点是否等于item
        if cur.item == item:
            return True
        return False

    def remove(self, item):
        """删除一个节点"""
        # 若链表为空，则直接返回
        if self.is_empty():
            return
        # 将cur指向头节点
        cur = self.__head
        pre = None
        # 若头节点的元素就是要查找的元素item
        if cur.item == item:
            # 如果链表不止一个节点
            if cur.next != self.__head:
                # 先找到尾节点，将尾节点的next指向第二个节点
                while cur.next != self.__head:
                    cur = cur.next
                # cur指向了尾节点
                cur.next = self.__head.next
                self.__head = self.__head.next
            else:
                # 链表只有一个节点
                self.__head = None
        else:
            pre = self.__head
            # 第一个节点不是要删除的
            while cur.next != self.__head:
                # 找到了要删除的元素
                if cur.item == item:
                    # 删除
                    pre.next = cur.next
                    return
                else:
                    pre = cur
                    cur = cur.next
            # cur 指向尾节点
            if cur.item == item:
                # 尾部删除
                pre.next = cur.next    
           
'''
    # remove函数的第二种方法
    def remove(self, item):
        """删除节点"""
        # 若链表为空，则直接返回
        if self.is_empty():
            return

        cur = self.__head
        pre = None
        
        while cur.next != self.__head:   #遍历链表，item在头部或中间
            if cur.item == item:
                # 先判断此结点是否是头节点
                if cur == self.__head:
                    # 1.头节点的情况
                    # 1.1先找尾节点
                    rear = self.__head
                    while rear.next != self.__head:
                        rear = rear.next
                    # 1.2 把head指向cur的下一个节点(即此时删除了头结点)
                    self.__head = cur.next
                    # 1.3 尾结点指向新的头结点
                    rear.next = self.__head
                else:
                    # 2.中间节点
                    # 直接把把前一节点指向后一节点，就删除了cur这个节点了
                    pre.next = cur.next
                return
            else:
                pre = cur         #遍历链表操作
                cur = cur.next    #遍历链表操作
        # 退出循环，cur指向尾节点, 还需额外判断尾结点是否等于item，即尾部节点删除
        # 3.尾部节点删除
        if cur.elem == item:
            if cur == self.__head:
                # 3.1 链表只有一个节点
                self.__head = None
            else:
                # 3.1 链表有多个节点
                # pre.next = cur.next
                pre.next = self.__head
'''
        
# 测试append是否成功
if __name__ == "__main__":
    link_1 = SingCycleleLinkList()   # 创建空链表link_1
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
    