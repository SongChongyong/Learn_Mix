# 搜索

搜索是在一个项目集合中找到一个特定项目的算法过程。搜索通常的答案是真的或假的，因为该项目是否存在。 搜索的几种常见方法：顺序查找、二分法查找、二叉树查找、哈希查找

## 01 二分法查找

二分查找又称折半查找，优点是比较次数少，查找速度快，平均性能好；其缺点是**要求待查表为有序表，且插入删除困难**。因此，折半查找方法适用于不经常变动而查找频繁的有序列表。首先，假设表中元素是按升序排列，将表中间位置记录的关键字与查找关键字比较，如果两者相等，则查找成功；否则利用中间位置记录将表分成前、后两个子表，如果中间位置记录的关键字大于查找关键字，则进一步查找前一子表，否则进一步查找后一子表。重复以上过程，直到找到满足条件的记录，使查找成功，或直到子表不存在为止，此时查找不成功。

![18binary_search_into_array.png](images/18binary_search_into_array.png)

```python
def binary_search(alist, item):
    """二分查找,递归"""
    n = len(alist)
    if n > 0:
        mid = n//2
        if alist[mid] == item:
            return True
        elif item < alist[mid]:
            return binary_search(alist[:mid], item)
        else:
            return binary_search(alist[mid+1:], item)
    return False



def binary_search_2(alist, item):
    """二分查找， 非递归"""
    n = len(alist)
    first = 0
    last = n-1
    while first <= last:
        mid = (first + last)//2
        if alist[mid] == item:
            return True
        elif item < alist[mid]:
            last = mid - 1
        else:
            first = mid + 1
    return False
```

### 时间复杂度

- 最优时间复杂度：O(1)
- 最坏时间复杂度：$O(log_2 n)$