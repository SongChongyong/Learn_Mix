# include <stdio.h>

int main()
{
	int x;
	double sum = 0;
	int cnt = 0;
	int number[100];  // 定义数组
	scanf("%d",&x);
	// 当输入-1时，结束输入 
	while (x!=-1){
		number[cnt] = x; 
		sum += x;
		cnt++;
		scanf("%d", &x);
	}
	
	if (cnt>0){
		int i;
		double average = sum/cnt;
		printf("平均数是：%f\n，比平均值大的数有：\n",average);
		// 遍历数组，使用数组中的元素与平均数比较，输出大的数 
		for (i=0;i<cnt;i++){
			if (number[i] > average){
				printf("%d ",number[i]);    
			}
		}
	} 
}
/*
2 4 5 7 8 -1
平均数是：5.200000
，比平均值大的数有：
7 8
*/

