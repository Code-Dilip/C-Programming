#include<stdio.h>
#include<stdlib.h>


struct point {
int x;
int y;
};

void print(struct point p){
printf(" point 1:%d, point 2:%d",p.x,p.y);
}

int main(){
struct point p1={1,2};
struct point p2={3,4};
print(p1);
printf("\n");
print(p2);
printf("\n Done, Thank You !");
return 0;
}
