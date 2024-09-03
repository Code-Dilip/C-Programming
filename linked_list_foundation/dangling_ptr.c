#include<stdio.h>

int func(){
int n=10;
return &n;
}

int main(){
int *ptr=NULL;
ptr=func();
printf(" the value stored in ptr is %d .",*ptr);
printf("\n");
return 0;
}
