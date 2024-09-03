#include<stdio.h>
#include<stdlib.h>

int *func(){
    int n = 10;
    return &n;
}
int main(){
    int *ptr;
    ptr = func();
    printf("Adress of the pointer is %p ",ptr);
    //printf("\nThe value associated with the pointer is %d ",*ptr);
    return 0;
}