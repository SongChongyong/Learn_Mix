#include <stdio.h>
union AnElt{
    int i;
    char c;
}elt1,elt2;

int main(){
    //! showMemory(start=65520)
    elt2.c='a';
    elt2.i=0xDEADBEEF;
    printf("The adress of elt1 is   %p\n",&elt1);
    printf("The adress of elt1.i is %p\n",&elt1.i);
    printf("The adress of elt1.c is %p\n",&elt1.c);
    printf("The adress of elt2 is   %p\n",&elt2);
    printf("The adress of elt2.i is %p\n",&elt2.i);
    printf("The adress of elt2.c is %p\n",&elt2.c);
    printf("The sizeof of elt2 is %d\n",sizeof(elt2));
    
	return 0;
} 
/*
The adress of elt1 is   004053D0
The adress of elt1.i is 004053D0
The adress of elt1.c is 004053D0
The adress of elt2 is   004053D4
The adress of elt2.i is 004053D4
The adress of elt2.c is 004053D4
The sizeof of elt2 is 4
*/ 
