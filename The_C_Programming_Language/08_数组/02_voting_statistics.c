# include <stdio.h> 
 
int main()
{
	const int number = 10;  // 数组大小 
	int x;
	int count[number];    //定义数组 
	int i;
	// 初始化数组，使count[0],count[1],...,count[9]都初始化为0 
	for (i=0; i<number; i++){
		count[i] = 0;
	}
	
	scanf("%d", &x);
	
	while (x!=-1){
		if (x>=0 && x<=9){
			count[x]++;  // 每读入一个数，让对应的count[x]都加一
		}
		scanf("%d", &x);
	}
	// 遍历数组元素 
	for (i=0; i<number; i++){
		printf("%d: %d\n", i , count[i]);
	}
}
/*
1 4 7 9 3 5 2 5 6 22 45 2 6 8 9 2 1 -1
0: 0
1: 2
2: 3
3: 1
4: 1
5: 2
6: 2
7: 1
8: 1
9: 2
*/
