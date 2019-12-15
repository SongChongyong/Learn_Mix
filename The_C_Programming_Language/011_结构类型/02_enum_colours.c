#include <stdio.h>

enum COLOURS {RED, YELLOW, GREEN}; 
 
int main(int argc,char const *argv[])
{
	int colour = -1;
    char *colourName = NULL;
 
    printf("Please input your favorite colour code:");
    printf("(red 0, yellow 1, green 2) ");
    scanf("%d", &colour);
    switch(colour)
	{
        case RED: colourName = "red"; break;
        case YELLOW: colourName = "yellow";break;
        case GREEN: colourName = "green";break;
        default: colourName = "unknown";break;
    }
    printf("Your favorite colour is: %s\n",colourName);
    return 0;
}
/*
Please input your favorite colour code:(red 0, yellow 1, green 2) 1
Your favorite colour is: yellow
*/
  
