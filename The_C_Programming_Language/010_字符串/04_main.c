# include<stdio.h>

// main函数参数有两个:
// 1个是int argc，告诉后面字符串到底有多少个字符串
// 1个是char const *argv[]，一个字符串数组
int main( int argc, char const *argv[])
{
	int i;
    // 尝试打印字符串数组char const *argv[]中所有的字符串
	for (i=0; i<argc; i++){
		printf("%d: %s\n", i, argv[i]);
		// 0: C:\Users\yong\Desktop\The_C_Programming_Language\010_字符串\04_main.exe
	}
} 
