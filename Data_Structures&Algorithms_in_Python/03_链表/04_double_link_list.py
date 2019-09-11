# coding:utf-8

class Node(object):
    """双向链表节点"""
    def __init__(self, item):
        self.item = item
        self.next = None
        self.prev = None

class DoubleLinkList(object):
    """双向链表"""
    def __init__(self):
        self.__head = None

    def is_empty(self):
        """判断链表是否为空"""
        return self.__head == None

    def length(self):
        """返回链表的长度"""
        cur = self.__head
        count = 0
        while cur != None:
            count += 1
            cur = cur.next
        return count

    def travel(self):
        """遍历链表"""
        cur = self.__head
        while cur != None:
            print (cur.item, end=" ")
            cur = cur.next
        print ("")

    def add(self, item):
        """头部插入元素"""
        node = Node(item)
        if self.is_empty():
            # 如果是空链表，将__head指向node
            self.__head = node
        else:
            # 将node的next指向__head的头节点
            node.next = self.__head
            # 将__head的头节点的prev指向node
            self.__head.prev = node
            # 将__head 指向node
            self.__head = node

    def append(self, item):
        """尾部插入元素"""
        node = Node(item)
        if self.is_empty():
            # 如果是空链表，将__head指向node
            self.__head = node
        else:
            # 移动到链表尾部
            cur = self.__head
            while cur.next != None:
                cur = cur.next
            # 将尾节点cur的next指向node
            cur.next = node
            # 将node的prev指向cur
            node.prev = cur

    def search(self, item):
        """查找元素是否存在"""
        cur = self.__head
        while cur != None:
            if cur.item == item:
                return True
            cur = cur.next
        return False


    def search(self, item):
        """查找元素是否存在"""
        cur = self.__head
        while cur != None:
            if cur.item == item:
                return True
            cur = cur.next
        return False
    
    def insert(self, pos, item):
        """在指定位置添加节点"""
        if pos <= 0:
            self.add(item)
        elif pos > (self.length()-1):
            self.append(item)
        else:
            node = Node(item)
            cur = self.__head
            count = 0
            # 移动到指定位置的前一个位置
            while count < (pos-1):
                count += 1
                cur = cur.next
            # 将node的prev指向cur
            node.prev = cur
            # 将node的next指向cur的下一个节点
            node.next = cur.next
            # 将cur的下一个节点的prev指向node
            cur.next.prev = node
            # 将cur的next指向node
            cur.next = node    

    def remove(self, item):
        """删除元素"""
        if self.is_empty():
            return
        else:
            cur = self.__head
            if cur.item == item:
                # 如果首节点的元素即是要删除的元素
                if cur.next == None:
                    # 如果链表只有这一个节点
                    self.__head = None
                else:
                    # 将第二个节点的prev设置为None
                    cur.next.prev = None
                    # 将__head指向第二个节点
                    self.__head = cur.next
                return
            while cur != None:
                if cur.item == item:
                    # 将cur的前一个节点的next指向cur的后一个节点
                    cur.prev.next = cur.next
                    # 将cur的后一个节点的prev指向cur的前一个节点
                    cur.next.prev = cur.prev
                    break
                cur = cur.next

    
    
if __name__ == "__main__":
    link_2 = DoubleLinkList()   # 创建空链表link_2
    print(link_2.is_empty())    # 判断link_2是否为空，结果为True
    print(link_2.length())      # 打印link_2长度,结果为0
    
    link_2.append(1)            # 往link_2尾端添加元素1
    print(link_2.is_empty())    # False
    print(link_2.length())      # 结果为1
    
    link_2.append(2)            # 往link_2尾端添加元素2
    link_2.append(3)            # 往link_2尾端添加元素3
    link_2.travel()             # 结果为1 2 3
    
    link_2.add(0)               # 往link_2头部添加元素0
    link_2.travel()             # 结果为0 1 2 3
    
    link_2.insert(-1, -100)     # 在-1位置添加-100节点，即在头部添加-100， 
    link_2.travel()             # 结果为-100 0 1 2 3
    link_2.insert(3, 1.5)       # 在3位置添加1.5节点 
    link_2.travel()             # -100 0 1 1.5 2 3 
    link_2.insert(10, 100)      # 在10位置添加100节点，10位置大于链表的 length()-1，所以等效于在尾部添加
    link_2.travel()             # -100 0 1 1.5 2 3
    
    link_2.remove(1.5)          # 删除1.5节点
    link_2.travel()             # -100 0 1 2 3 100 
    link_2.remove(-100)         # 删除头结点-100
    link_2.travel()             # 0 1 2 3 100 
    link_2.remove(3)            # 删除尾节点3
    link_2.travel()             # 0 1 2 100 
    
    

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
    