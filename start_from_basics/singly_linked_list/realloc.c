#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m;
    printf(" enter the no. of memory blocks needed: ");
    scanf("%d",&n);

    int *ptr = (int *)malloc(n*sizeof(int));
    int i;
    printf("\n");

    for(i=0;i<n;i++){
        printf(" enter the element in the #%d memory block: ",i+1);
        scanf("%d",(ptr+i));
    }

    for(i=0;i<n;i++){
        printf("\n The element in the #%d memory block is %d",i+1,*(ptr+i));
    }
    
    printf("\n\n enter the no. of extra memory blocks needed: ");
    scanf("%d",&m);
    printf("\n");

    for(i=n;i<(n+m);i++){
        printf(" enter the element in the #%d memory block: ",i+1);
        scanf("%d",(ptr+i));
    }

    printf("\n The elements are: ");
    for(i=0;i<(n+m);i++){
        printf("\n The element in the #%d memory block: %d",i+1,*(ptr+i));
    }
    printf("\n");

    return 0;

}