# include<stdio.h>

// main��������������:
// 1����int argc�����ߺ����ַ��������ж��ٸ��ַ���
// 1����char const *argv[]��һ���ַ�������
int main( int argc, char const *argv[])
{
	int i;
    // ���Դ�ӡ�ַ�������char const *argv[]�����е��ַ���
	for (i=0; i<argc; i++){
		printf("%d: %s\n", i, argv[i]);
		// 0: C:\Users\yong\Desktop\The_C_Programming_Language\010_�ַ���\04_main.exe
	}
} 
