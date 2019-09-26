# coding:utf-8


def select_sort(alist):
    """选择排序"""
    n = len(alist)
    # 需要进行n-1次选择操作
    for j in range(n-1):    # j: 0 ~ n-2
        # 记录最小位置
        min_index = j
        # 从j+1位置到末尾选择出最小数据
        for i in range(j+1, n):
            if alist[min_index] > alist[i]:
                min_index = i
        
        # 如果选择出的数据不在正确位置，进行交换
        if min_index != j:        
            alist[j], alist[min_index] = alist[min_index], alist[j]


if __name__ == "__main__":
    li = [54,226,93,17,77,31,44,55,20]

    print(li)    # [54, 226, 93, 17, 77, 31, 44, 55, 20]
    select_sort(li)
    print(li)    # [17, 20, 31, 44, 54, 55, 77, 93, 226]
    
    