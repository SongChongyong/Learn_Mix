#  include<stdio.h>

 // ����ʲô�ַ���������ʲô�ַ���ֱ������Ctrl+c����EOF�˳� 
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

���Ctrl+c�˳� 
*/


