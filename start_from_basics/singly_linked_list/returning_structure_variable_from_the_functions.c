#include<stdio.h>
#include<stdlib.h>

struct point{
    int x;
    int y;
};

void input(int *x,int *y){
    printf("\n enter the value for x: ");
    scanf("%d",x);
    printf(" enter the value for y: ");
    scanf("%d",y);
}

void print(struct point *ptr){
    printf("(%d,%d). ",ptr->x,ptr->y);
}

struct point edit(struct point *ptr){
    ptr->x += ptr->x;
    ptr->y *= ptr->y;
    return *ptr;
}

int main(){
    
    int x,y;
    input(&x,&y);
    struct point p = {x,y};
    printf("\n The point before editing is ");
    print(&p);
    
    printf("\n");
    p = edit(&p);
    printf("\n The point after editing is ");
    print(&p);

    return 0;
}