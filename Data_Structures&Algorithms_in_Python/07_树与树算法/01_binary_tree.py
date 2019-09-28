# coding:utf-8

class Node(object):
    """树的节点类"""
    def __init__(self, item):
        self.elem = item
        self.lchild = None
        self.rchild = None

class Tree(object):
    """二叉树"""
    def __init__(self):
        self.root = None

    def add(self, item):
        """为树添加节点"""
        
        node = Node(item)
        queue = []
        queue = [self.root]
        
        # 如果树是空的，则对根节点赋值
        if self.root is None:
            self.root = node
            return
        
        # 对已有的节点进行层次遍历
        while queue:
            # 弹出队列的第一个元素
            cur_node = queue.pop(0)
            
            # 先判断左子树是否为空，如果是，则元素直接添加进去
            # 再判断右子树是否为空，如果是，则元素添加进去
            # 如果左右子树都不为空，左右子树加入队列继续判断
            if cur_node.lchild is None:
                cur_node.lchild = node
                return
            elif cur_node.rchild is None:
                cur_node.rchild = node
                return
            else:
                queue.append(cur_node.lchild)
                queue.append(cur_node.rchild)

    def breadth_travel(self):
        """广度遍历(利用队列实现)"""
        if self.root is None:
            return
        queue = [self.root]
        while queue:
            cur_node = queue.pop(0)
            print(cur_node.elem, end=" ")
            if cur_node.lchild is not None:
                queue.append(cur_node.lchild)
            if cur_node.rchild is not None:
                queue.append(cur_node.rchild)

    def preorder(self, node):
        """先序遍历，根节点->左子树->右子树，递归实现"""
        if node is None:
            return
        print(node.elem, end=" ")
        self.preorder(node.lchild)
        self.preorder(node.rchild)

    def inorder(self, node):
        """中序遍历，左子树->根节点->右子树，递归实现"""
        if node is None:
            return
        self.inorder(node.lchild)
        print(node.elem, end=" ")
        self.inorder(node.rchild)

    def postorder(self, node):
        """后序遍历，左子树->右子树->根节点，递归实现"""
        if node is None:
            return
        self.postorder(node.lchild)
        self.postorder(node.rchild)
        print(node.elem, end=" ")

if __name__ == "__main__":
    tree = Tree()
    tree.add(0)
    tree.add(1)
    tree.add(2)
    tree.add(3)
    tree.add(4)
    tree.add(5)
    tree.add(6)
    tree.add(7)
    tree.add(8)
    tree.add(9)
    tree.breadth_travel()       # 广度遍历结果： 0 1 2 3 4 5 6 7 8 9 
    print(" ")
    tree.preorder(tree.root)    # 先序遍历结果：  0 1 3 7 8 4 9 2 5 6 
    print(" ")
    tree.inorder(tree.root)     # 中序遍历结果：  7 3 8 1 9 4 0 5 2 6
    print(" ")
    tree.postorder(tree.root)   # 后序遍历结果：  7 8 3 9 4 1 5 6 2 0
    print(" ")
