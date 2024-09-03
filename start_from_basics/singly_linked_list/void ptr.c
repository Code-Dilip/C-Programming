#include<stdio.h>

int main(){
    int n=10;
    void *ptr;
    ptr = &n;
    printf("Address in the void ptr is %p",ptr);
    printf("\nThe value sotred in the void ptr is %d",*(int *)ptr);
    return 0;
}