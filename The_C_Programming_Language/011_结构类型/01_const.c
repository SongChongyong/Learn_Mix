#include <stdio.h>
// ´Ë´úÂëerror 
const int red = 1;
const int yellow = 2;
const int green = 3;
 
int main(int argc,char const *argv[]){
	int colour = -1;
    char *colourName = NULL;
 
    printf("Please input your favorite colour code:\n");
    printf("(red 1, yellow 2, green 3)");
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
  
