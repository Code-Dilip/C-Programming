#include<stdio.h>
#include<stdlib.h>

 struct point {
int x;
int y;
};

struct point *func(int a,int b){
struct point *ptr=(struct point *)malloc(sizeof(struct point));
ptr->x=a;
ptr->y=a+b;
return ptr;
}

void print(struct point *p){
printf(" point1: %d, point2: %d ",p->x,p->y);
}

int main(){
struct point *ptr1,*ptr2;
ptr1=func(1,2);
ptr2=func(3,4);
print(ptr1);
printf("\n");
print(ptr2);
printf("\n Done , Thank You!");
free(ptr1);
free(ptr2);
return 0;
}


