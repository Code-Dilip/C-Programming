#include<stdio.h>
#include<stdlib.h>

void print_array(int arr[],int n){
    if(n=0){
        printf("\n The array is empty! ");
    }
    else {
        printf("[ %d",arr[0]);
        for(int i=1;i<n;i++){
            printf(",%d",arr[i]);
        }
        printf(" ] ");
    }
}

int main(){
    int arr[100],n,pos,data;
    printf("\n enter the size of the array: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf(" enter the #%d element in the array: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n enter the new element to insert into the array: ");
    scanf("%d",&data);
    printf(" enter the position to insert a new element into the array:  ");
    scanf("%d",&pos);
    
    printf("\n The array before insertion of new element %d is ",data);
    printf("[ %d",arr[0]);
        for(int i=1;i<n;i++){
            printf(",%d",arr[i]);
        }
        printf(" ] ");

    for(int i=n-1;i>=pos-1;i--){
        arr[i+1] = arr[i];
    }
    arr[pos-1] = data;
    n = n+1;

    printf("\n The array after insertion of new element %d in position %d is ",data,pos);
    printf("[ %d",arr[0]);
        for(int i=1;i<n;i++){
            printf(",%d",arr[i]);
        }
        printf(" ] ");
    
    return 0;
}