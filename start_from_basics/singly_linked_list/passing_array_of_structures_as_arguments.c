#include<stdio.h>
#include<stdlib.h>

struct point{
    int x;
    int y;
};

void print(struct point arr[],int n){
    for(int i=0;i<n;i++){
        printf(",(%d,%d)",arr[i].x,arr[i].y);
    }
}

int main(){
    struct point arr[2] = {{2,3},{4,5}};
    printf("\n The array is ");
    print(arr,2);
    return 0;
}