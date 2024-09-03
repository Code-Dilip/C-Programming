#include<stdio.h>

int main(){
void *ptr;
int *ptr2=NULL;
int n=10;
ptr=&n;
printf("%d ",*(int *)ptr);
printf("\n");
printf("value stored in null pointer is %ls .",ptr2);
return 0;
}
