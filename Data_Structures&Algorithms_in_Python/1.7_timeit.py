# coding:utf-8
from timeit import Timer 


def test1():
   l = []
   for i in range(1000):
      l = l + [i]
def test2():
   l = []
   for i in range(1000):
      l.append(i)
def test3():
   l = [i for i in range(1000)]
def test4():
   l = list(range(1000))
   
t1 = Timer("test1()", "from __main__ import test1")
print("concat ",t1.timeit(number=1000), "seconds")
t2 = Timer("test2()", "from __main__ import test2")
print("append ",t2.timeit(number=1000), "seconds")
t3 = Timer("test3()", "from __main__ import test3")
print("comprehension ",t3.timeit(number=1000), "seconds")
t4 = Timer("test4()", "from __main__ import test4")
print("list range ",t4.timeit(number=1000), "seconds")

'''
concat  1.735037316 seconds
append  0.07950437899999985 seconds
comprehension  0.04237880400000016 seconds
list range  0.01636211700000012 seconds
'''
# 由结果可知，使用concat费时特别长，所以程序中尽量少用列表加法

# x = range(2000000)
# pop_zero = Timer("x.pop(0)","from __main__ import x")
# print("pop_zero ",pop_zero.timeit(number=1000), "seconds")
# x = range(2000000)
# pop_end = Timer("x.pop()","from __main__ import x")
# print("pop_end ",pop_end.timeit(number=1000), "seconds")

