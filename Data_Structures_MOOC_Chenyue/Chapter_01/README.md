# 01 概论

## 1.4 实例：最大子列和

问题描述：给定n个正整数的序列$\{ a_1,a_2,..., a_n \}$，求函数$f(i,j)=max \{ 0, \sum_{k=i}^j a_k\}$的最大值。

分析：即求序列的最大子列，子列表示原始序列中连续的一段数字。如给定序列{-2,11,-4,13,-5,-2}，其最大子列为{11,-4,13}，和为20

### 1.4.1 穷举法

```c
// 穷举法：穷举所有子列和，从中找出最大值 
int MaxSubseqSum1( int List[], int N )
{   int ThisSum, MaxSum = 0;
	int i, j, k;

	for( i = 0; i < N; i++ ) { /* i是子列左端位置 */
		for( j = i; j < N; j++ ) { /* j是子列右端位置 */
			ThisSum = 0;  /* ThisSum是从List[i]到List[j]的子列和 */
			for( k = i; k <= j; k++ )
				ThisSum += List[k];
			if( ThisSum > MaxSum ) /* 如果刚得到的这个子列和更大 */
				{
					MaxSum = ThisSum;   /* 则更新结果 */
				}
		} /* j循环结束 */
    } /* i循环结束 */
	return MaxSum;
}

```



### 1.4.2 部分存储中间值的穷举

```c
// 部分存储中间值的穷举
int MaxSubseqSum2( int List[], int N )
{   int ThisSum, MaxSum = 0;
	int i, j;

	for( i = 0; i < N; i++ ) { /* i是子列左端位置 */
		ThisSum = 0;  /* ThisSum是从List[i]到List[j]的子列和 */
		for( j = i; j < N; j++ ) { /* j是子列右端位置 */
			ThisSum += List[j];
			/*对于相同的i，不同的j，只要在j-1次循环的基础上累加1项即可*/
			if( ThisSum > MaxSum ) /* 如果刚得到的这个子列和更大 */
				MaxSum = ThisSum;   /* 则更新结果 */
		} /* j循环结束 */
    } /* i循环结束 */
	return MaxSum;
}
```

