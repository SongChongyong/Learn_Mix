#include<stdio.h>

// 此代码error 
const int red = 0;
const int yellow = 1;
const int green = 2;
 
int main(int argc,char const *argv[]){
	int colour = -1;
    char *colourName = NULL;
 
    printf("Please input your favorite colour code:\n");
    printf("(red 0, yellow 1, green 2)");
    scanf("%d", &colour);
    switch(colour){
        case red: colourName = "red"; break;
        case yellow: colourName = "yellow";break;
        case green: colourName = "green";break;
        default: colourName = "unknown";break;
    }
    printf("Your favorite colour is: %s\n",colourName);
    return 0;
}
