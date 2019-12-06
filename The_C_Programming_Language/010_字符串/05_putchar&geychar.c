#  include<stdio.h>

 // 输入什么字符，就输入什么字符，直到输入Ctrl+c导致EOF退出 
int main(int argc, char const *argv[]){
	int ch;
	while((ch = getchar())!=EOF){
		putchar(ch);
	}
	printf("EOF");
	return 0;
}
/*
123
123

35567
35567

最后Ctrl+c退出 
*/


