#include <stdio.h>

enum COLOURS {RED, YELLOW, GREEN, NumCOLOURS};  // 使用枚举实现计数， NumCOLOURS = 4 
 
int main(int argc,char const *argv[])
{
	int colour = -1;
	char *ColourNames[NumCOLOURS] = {"red", "yellow", "green",};
    char *colourName = NULL;
 
    printf("Please input your favorite colour code:");
    printf("(red 0, yellow 1, green 2) ");
    scanf("%d", &colour);
    if (colour>=0 && colour<NumCOLOURS){
    	colourName = ColourNames[colour];
    }
    else {
    	colourName = "unknown";
    }
    printf("Your favorite colour is: %s\n",colourName);
    return 0;
}
/*
Please input your favorite colour code:(red 0, yellow 1, green 2) 2
Your favorite colour is: green
*/
  
