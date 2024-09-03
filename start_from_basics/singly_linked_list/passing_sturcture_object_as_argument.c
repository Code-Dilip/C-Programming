#include<stdio.h>
#include<stdlib.h>

struct point {
    int x;
    int y;
};

void input(int *x,int *y){
    printf("\n enter the value for x co-ordinate: ");
    scanf("%d",x);
    printf(" enter the value for y co-ordinate: ");
    scanf("%d",y);
}

void print(struct point p){
    printf(" point is (%d,%d). ",p.x,p.y);
}

int main(){
    int x,y;
    input(&x,&y);
    struct point p1 = {x,y};
    print(p1);
    return 0;
}