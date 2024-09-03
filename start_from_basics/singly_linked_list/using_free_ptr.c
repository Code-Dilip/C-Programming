#include<stdio.h>
#include<stdlib.h>

int *input(int n){
    
    int *ptr = (int *)malloc(n*sizeof(int));
    printf("\n");
    for(int i=0;i<n;i++){
        printf(" enter the element in the #%d memory block: ",i+1);
        scanf("%d",(ptr+i));
    }
    return ptr;
}

int main(){
    int n;
    printf("\n enter the no. of memory blocks required: ");
    scanf("%d",&n);
    int *ptr = input(n),sum=0;
    for(int i=0;i<n;i++){
        sum += *(ptr+i);
    }
    printf("\n The sum of %d number of elements is %d.",n,sum);

    free(ptr);
    ptr = NULL;
    return 0;

}