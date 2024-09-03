#include<stdio.h>

int main(){
    int n=10;
    void *ptr=&n;
    printf("%d ",*(int*)ptr);
    printf("\n");
    return 0;
}