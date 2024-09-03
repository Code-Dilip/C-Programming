#include<stdio.h>

void print_array(int arr[],int n);
int deletion_at_pos(int arr[],int n,int pos);

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
    printf("\n\n enter the position to delete a element: ");
    scanf("%d",&pos);
    n=deletion_at_pos(arr,n,pos);
    printf("\n\n The size of the array after deletion of element is %d ",n);
    printf("\n\n Done, Thank You! ");
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

int deletion_at_pos(int arr[],int n,int pos){
    int i;
    for(i=pos;i<n;i++){
        arr[i-1]=arr[i];
    }
    n=n-1;
    print_array(arr,n);
    return n;
}