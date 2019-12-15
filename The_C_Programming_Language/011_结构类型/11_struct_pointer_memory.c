#include <stdio.h>
#include <stdlib.h>
struct point{
    int x;
    int y;
};
void printPoint(struct point pt);
void readPoint(struct point * ptr);
void printPoly(struct point *ptr, int vertices);

/*由用户输入一个数字num，然后构建具有num个顶点(vertex)的多边形(polygon)*/
int main(void) {
    //! showMemory(start=65520)
    struct point * polygon;
    int i, num;
    printf("How many vertices does your polygon have? ");
    scanf("%d", &num);
    polygon = (struct point *) malloc(num * sizeof(struct point));
    for (i=0; i<num; i++){
        readPoint(&polygon[i]);
    }
    printPoly(polygon, num);
    free(polygon);
	return 0;
}

void readPoint(struct point * ptr) {
    printf("\nEnter a new point: \n");
    printf("x-coordinate: ");
    scanf("%d", &ptr->x);
    printf("y-coordinate: ");
    scanf("%d", &ptr->y);
}

void printPoly(struct point *ptr, int vertices) {
    int i;
    for (i=0; i<vertices; i++) {
        printPoint(ptr[i]);
    }
}

void printPoint(struct point pt){
    printf("(%d, %d)\n", pt.x, pt.y);
}

/* 
How many vertices does your polygon have? 4

Enter a new point:
x-coordinate: 3
y-coordinate: 4

Enter a new point:
x-coordinate: 5
y-coordinate: 6

Enter a new point:
x-coordinate: 7
y-coordinate: 8

Enter a new point:
x-coordinate: 9
y-coordinate: 10
(3, 4)
(5, 6)
(7, 8)
(9, 10)
*/
