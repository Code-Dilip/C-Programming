#include<stdio.h>
#include<stdlib.h>

struct code{
    int i;
    char c;
    struct code *ptr;
};

void print(struct code var){
    printf("\n\n int:%d ,char:%c ",var.i,var.c);
}

int main(){
    struct code var1,var2;
    var1.i=1;
    var1.c='A';
    var1.ptr=NULL;
    var2.i=2;
    var2.c='B';
    var2.ptr=NULL;
    print(var1);
    printf("\n");
    print(var2);
    var1.ptr=&var2;
    printf("\n\n");
    printf(" %d , %c:",var1.ptr->i,var1.ptr->c);
    printf("\n\n");
    printf("\n Done, Thank You! ");
}