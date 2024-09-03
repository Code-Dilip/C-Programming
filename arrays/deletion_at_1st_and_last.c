#include<stdio.h>

int deletion_at_1st(int arr[],int n);
void print_array(int arr[],int n);
void insertion_at_pos(int arr[],int n,int pos);
int deletion_at_last(int arr[],int n);

int main(){
    int n;
    printf("\n enter the size of the array: ");
    scanf("%d",&n);
    int arr[n],i,pos;
    for(i=0;i<n;i++){
        printf(" enter the #%d element into the array: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n the array is ");
    print_array(arr,n);

    printf("\n\n enter the position to insert to element into the array: ");
    scanf("%d",&pos);
    insertion_at_pos(arr,n,pos);

    printf("\n\n The array after deletion of first element is ");
    n=deletion_at_1st(arr,n);

    printf("\n\n The array after deletion of last element is ");
    n=deletion_at_last(arr,n);
    printf("\n The size of the array at last is %d ",n);
    printf("\n Thank You! \n\n");
    return 0;
}

void print_array(int arr[],int n){
    int i;
    printf("[ ");
    for(i=0;i<n-1;i++){
        printf("%d, ",arr[i]);
    }
    printf("%d ]",arr[n-1]);

}

void insertion_at_pos(int arr[],int n, int pos){
    int m=n+1,arr2[m],i;
    for(i=0;i<n;i++){
        arr2[i]=arr[i];
    }
    for(i=n-1;i>=pos-1;i--){
        arr2[i+1]=arr2[i];
    }
    printf("\n enter the new element to insert at %d position of the array: ",pos);
    scanf("%d",&arr2[pos-1]);
    printf("\n The array after insertion of new element is ");
    print_array(arr2,m);
}

int deletion_at_1st(int arr[],int n){
    int i;
    for(i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    n=n-1;
    print_array(arr,n);
    return n;
}

int deletion_at_last(int arr[],int n){
    arr[n-1]=0;
    n=n-1;
    print_array(arr,n);
    return n;
}