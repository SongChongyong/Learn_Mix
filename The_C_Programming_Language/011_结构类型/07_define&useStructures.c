#include <stdio.h>

struct student{
    char firstName[5];
    char lastName[5];
    int birthYear;
    double aveGrade;
};

int main(void) {
	//! showMemory(start=65520)
    struct student me = {"Pet", "Bon", 1989, 3.5};
    struct student you = {"Remi", "Shk", 2005, 3.5};
    printf("Names: %s %s, %s %s\n", me.firstName, me.lastName, you.firstName, you.lastName);
    printf("Year of birth: %d\n", me.birthYear);
    printf("Average grade: %.2lf\n", me.aveGrade);
	return 0;
}
/*
Names: Pet Bon, Remi Shk                                                        
Year of birth: 1989                                                             
Average grade: 3.50
*/ 

