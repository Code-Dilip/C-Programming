#include<stdio.h>
#include<stdlib.h>

struct point{
int x;
int y;
};

void print(struct point arr[]){
int i=0;
for(i=0;i<2;i++){
printf("\n point1:%d, point2:%d ",arr[i].x,arr[i].y);
}
}

int main(){
struct point arr[2]={{1,2},{3,4}};
print(arr);
printf("\n Done !,Thank You! ");
return 0;
}
