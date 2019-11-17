# include<stdio.h>

int main()
{
	//得到字符'A'后面的字符
	char c = 'A';
	c++;
	printf("字符'A'后面的字符：%c\n",c); 
	
	//两个字符相减，得到它们在表中的距离
	int i = 'Z'-'A';
	printf("字符'Z'和字符'A'在ASCII表中的距离：%d\n",i);  
	
	// 对任意表示字母的字符'd' ：
	//		(1) d + 'a'-'A' 可以把大写字母变成小写字母
	//		(2) d + 'A'-'a' 可以把小写字母变成大写字母
	char d = 'D';
	d = d + 'a' - 'A';
	printf("'D' + 'a'-'A'的结果为%c\n",d);	 
} 
/*
字符'A'后面的字符：B
字符'Z'和字符'A'在ASCII表中的距离：25
'D' + 'a'-'A'的结果为d
*/  
