#include<stdio.h>

void print_arr(int arr[],int n);
void insert_at_beg(int arr[],int n);
void insert_at_end(int arr[],int n);

int main(){
    int n,i;
    printf("\n enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\n");
    for(i=0;i<n;i++){
        printf(" enter the #%d element into the array: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n The array is....");
    print_arr(arr,n);
    insert_at_beg(arr,n);
    insert_at_end(arr,n);
    printf("\n Done, Thank You! ");
    return 0;
}

void print_arr(int arr[],int n){
    int i;
    printf("[ ");
    for(i=0;i<n-1;i++){
        printf("%d, ",arr[i]);
    }
    printf("%d ]",arr[n-1]);
}

void insert_at_beg(int arr[],int n){
    int m=n+1;
    int arr2[m],i;
    for(i=n;i>=0;i--){
        arr2[i+1]=arr[i];
    }
    printf("\n enter the element that want to insert at beginning: ");
    scanf("%d",&arr2[0]);
    printf("\n The array after insertion of a element is....");
    print_arr(arr2,m);
}

void insert_at_end(int arr[],int n){
    int m=n+1,arr2[m],i;
    for(i=0;i<n;i++){
        arr2[i]=arr[i];
    }
    printf("\n enter the new element to insert at end: ");
    scanf("%d",&arr2[n]);
    printf("\n\n The array after inserting a element at last is.....");
    print_arr(arr2,m);
}