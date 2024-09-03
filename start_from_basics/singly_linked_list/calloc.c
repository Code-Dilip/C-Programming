#include<stdlib.h>
#include<stdio.h>

int main(){
    int *ptr,n;
    printf("enter the number of memory blocks required: ");
    scanf("%d",&n);

    ptr = (int *)calloc(n,sizeof(int));

    if(ptr == NULL){
        printf("\nThe requried number of memory blocks aren't available!");
        exit(1);
    }

    printf("\n");

    for(int i=0;i<n;i++){
        printf("enter the element into the #%d memory block: ",(i+1));
        scanf("%d",(ptr+i));
    }


    for(int i=0;i<n;i++){
        printf("\nThe element in the #%d memory block is %d ",(i+1),*(ptr+i));
    }

    return 0;
}