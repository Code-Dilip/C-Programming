#include<stdio.h>
#include<stdlib.h>

struct point{
    int x;
    int y;
};

struct point *func(int x,int y){
    struct point *ptr = (struct point *)malloc(sizeof(struct point));
    ptr->x = x;
    ptr->y = y;
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
    
    int x,y;
    input(&x,&y);
    struct point *p ;
    p = func(x,y);
    printf("\n The point is ");
    print(p);
    printf("\n");
    return 0;

}