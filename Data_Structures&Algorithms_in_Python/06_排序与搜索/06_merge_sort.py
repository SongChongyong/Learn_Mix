# coding:utf-8


def merge_sort(alist):
    """归并排序"""
    n = len(alist)
    if n <= 1:
        return alist
    
    mid = n//2
    # left 采用归并排序后形成的有序的新的列表(递归调用merge_sort)
    left_li = merge_sort(alist[:mid])

    # right 采用归并排序后形成的有序的新的列表
    right_li = merge_sort(alist[mid:])

    # 将两个有序的子序列合并为一个新的整体
    # merge(left, right)
    left_pointer, right_pointer = 0, 0  # 左右两个指针初始都是指向第一个元素
    result = []

    # 循环控制左右两个指针走遍整个左右两个分列表
    while left_pointer < len(left_li) and right_pointer < len(right_li):  
        # 当左边列表的元素小时，拿出此时左边列表所指向的元素，添加到左边的列表，同时左边指针向后一位
        if left_li[left_pointer] <=  right_li[right_pointer]:
            result.append(left_li[left_pointer])
            left_pointer += 1
        # 当右边列表的元素小或相等时，拿出此时右边列表所指向的元素，添加到右边的列表，同时右边指针向后一位
        else:
            result.append(right_li[right_pointer])
            right_pointer += 1

    result += left_li[left_pointer:]
    result += right_li[right_pointer:]
    return result


if __name__ == "__main__":
    li = [54, 26, 93, 17, 77, 31, 44, 55, 20]
    print(li)         # [54, 26, 93, 17, 77, 31, 44, 55, 20]
    sorted_li = merge_sort(li)  # 这里需要额外存储为另一个列表sorted_li，所以归并排序内存使用更高
    print(li)         # [54, 26, 93, 17, 77, 31, 44, 55, 20]
    print(sorted_li)  # [17, 20, 26, 31, 44, 54, 55, 77, 93]

'''
merge_sort执行流程：
sorted_li = merge_sort([54, 26, 93, 17, 77, 31, 44, 55, 20])   
    left_li = merge_sort [54, 26, 93, 17]
    
        left_li = merge_sort [54, 26]
        
                 left_li = meige_sort[54]  # n=1,直接返回[54]
                 right_li = meige_sort[26]
                 result = [26, 54] # 合并
                 return result
        left_li = [26, 54]
    
        right_li = merge_sort([93, 17])
    
                left_li = merge_sort([93])    # n=1,直接返回[93]
                            return [93]
                left_li =[93]
    
                right_li = merge_sort([17])    
                            return [17]
                right_li = [17]
    
                result = [17, 93]  # 合并
    
                return result
    
        right_li = [17, 93]
    
        result = [17, 26, 54, 93]
    
        return result
    
    left_li = [17, 26, 54, 93]
    
    right_li = merge_sort([77, 31, 44, 55, 20])
        result = [20, 31, 44, 55, 77]
        return result
    right_li = [20, 31, 44, 55, 77]
    
    
    result = [...]
    return result
'''




