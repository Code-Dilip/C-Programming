#include<stdio.h>
#include<stdlib.h>

struct code{
int i;
char c;
struct code *ptr;
};

int main(){
struct code var1,var2;
var1.i=1;
var1.c='A';
var1.ptr=NULL;
var2.i=2;
var2.c='B';
var2.ptr=NULL;
var1.ptr=&var2;
printf("%d ,%c ",var1.ptr->i,var1.ptr->c);
printf("\n");
printf("\n Done! , Thank You!");
return 0;
}
