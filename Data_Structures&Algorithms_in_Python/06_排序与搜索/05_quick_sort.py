# coding:utf-8

'''
def quick_sort(alist):
    """快速排序--仅仅考虑第一趟过程，不考虑递归过程"""
    
    mid_value = alist[first]    # 设定起始元素为要寻找位置的基准元素
    low = 0                 # low为序列左边的由左向右移动的游标
    n = len(alist)
	high = n-1                 # high为序列右边的由右向左移动的游标
    while low < high:
        # 如果low与high未重合，high指向的元素不比基准元素小，则high向左移动
        while low < high and alist[high] >= mid_value:
            high -= 1
        # 将high指向的元素放到low的位置上
        alist[low] = alist[high]
        
        # 如果low与high未重合，low指向的元素比基准元素小，则low向右移动
        while low <high and alist[low] < mid_value:
            low += 1
        # 将low指向的元素放到high的位置上
        alist[high] = alist[low]
    
    # 退出循环后，low与high重合，此时所指位置为基准元素的正确位置
    # 将基准元素放到该位置
    alist[low] = mid_value
'''


def quick_sort(alist, first, last):
    """快速排序"""
    
    # 递归的退出条件
    if first >= last:
        return
    mid_value = alist[first]    # 设定起始元素为要寻找位置的基准元素
    low = first                 # low为序列左边的由左向右移动的游标
    high = last                 # high为序列右边的由右向左移动的游标
    while low < high:
        # 如果low与high未重合，high指向的元素不比基准元素小，则high向左移动
        while low < high and alist[high] >= mid_value:
            high -= 1
        # 将high指向的元素放到low的位置上
        alist[low] = alist[high]
        
        # 如果low与high未重合，low指向的元素比基准元素小，则low向右移动
        while low <high and alist[low] < mid_value:
            low += 1
        # 将low指向的元素放到high的位置上
        alist[high] = alist[low]
    
    # 退出循环后，low与high重合，此时所指位置为基准元素的正确位置
    # 将基准元素放到该位置
    alist[low] = mid_value

    # 对low左边的列表执行快速排序
    quick_sort(alist, first, low-1)

    # 对low右边的列表排序
    quick_sort(alist, low+1, last)


if __name__ == "__main__":
    li = [54, 26, 93, 17, 77, 31, 44, 55, 20]
    print(li)   # [54, 26, 93, 17, 77, 31, 44, 55, 20]
    quick_sort(li, 0, len(li)-1)
    print(li)   # [17, 20, 26, 31, 44, 54, 55, 77, 93]

