#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr,n;
    printf("enter the no. of memory blocks required: ");
    scanf("%d",&n);
    
    ptr = malloc(n*sizeof(int));

    if(ptr == NULL){
        printf("There's no memory to allocate!");
        exit(1);
    }

    printf("\n");

    for(int i=0;i<n;i++){
        printf("enter the element into #%d memory block: ",i+1);
        scanf("%d",(ptr+i));
    }

    for(int i=0;i<n;i++){
        printf("\nThe #%d element entered is %d",i+1,*(ptr+i));
    }

    free(ptr);

    return 0;
}