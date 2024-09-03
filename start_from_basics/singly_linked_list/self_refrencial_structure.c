#include<stdio.h>
#include<stdlib.h>

struct point {
    int x;
    int y;
};

struct point *func(int a,int b){
    struct point *ptr = malloc(sizeof(struct point));
    ptr->x = a;
    ptr->y = b;
    return ptr;
}

void print(struct point *ptr){
    printf("(%d,%d)",ptr->x,ptr->y);
}

void input(int *x,int *y){
    printf("\n enter the value for x: ");
    scanf("%d",x);
    printf(" enter the value for y: ");
    scanf("%d",y);
}

int main(){
    struct point *ptr;
    int x,y;
    input(&x,&y);
    ptr = func(2,3);
    printf("\n The point is ");
    print(ptr);
    printf("\n");
    return 0;
}