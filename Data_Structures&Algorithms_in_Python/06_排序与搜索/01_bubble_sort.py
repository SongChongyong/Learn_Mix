# coding:utf-8


def bubble_sort(alist):
    """冒泡排序--顺序表实现"""
    n = len(alist)
    # j表示每次遍历需要比较的次数，是逐渐增大的
    for j in range(n-1):
        count = 0   # 对应最优序列，如 [1,2,3,4,5,6]，已经是有序的了，只判断缺不需要执行交换，直接return节约时间
        for i in range(0, n-1-j):
            # 班长从头走到尾
            if alist[i] > alist[i+1]:
                alist[i],alist[i+1] = alist[i+1], alist[i]
                count += 1
        if 0 == count:
            return


'''
i&j变化：
第1次exchange i 0 ~ n-2   range(0, n-1) j=0
第2次exchange i 0 ~ n-3   range(0, n-1-1) j=1
第3次exchange i 0 ~ n-4   range(0, n-1-2) j=2
第n次exchange j=n  i  range(0, n-1-j)
'''


if __name__ == "__main__":
    li = [54, 26, 93, 17, 77, 31, 44, 55, 20]
    print(li)           # [54, 26, 93, 17, 77, 31, 44, 55, 20]
    bubble_sort(li)
    print(li)           # [17, 20, 26, 31, 44, 54, 55, 77, 93]



# 冒泡排序写法二
def bubble_sort2(alist):
    for j in range(len(alist)-1,0,-1):
        # j表示每次遍历需要比较的次数，是逐渐减小的
        # [n-1, n-2, n-3, n-4,..., 1]
        
        for i in range(j):
            # [0, 1, 2, 3,...,n-2]
            if alist[i] > alist[i+1]:
                alist[i], alist[i+1] = alist[i+1], alist[i]






