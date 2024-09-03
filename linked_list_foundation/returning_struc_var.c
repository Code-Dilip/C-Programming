#include<stdio.h>

struct point {
int x;
int y;
};

struct point edit(struct point p){
p.x++;
p.y*=5;
return p;
};

void print(struct point p){
printf(" point1:%d, point2:%d ",p.x,p.y);
}

int main(){
struct point p1={5,6};
struct point p2={7,8};
p1=edit(p1);
p2=edit(p2);
print(p1);
printf("\n\n");
print(p2);
printf("\n\n");
return 0;
}
