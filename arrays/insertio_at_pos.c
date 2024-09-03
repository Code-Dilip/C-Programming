#include<stdio.h>

void print_array(int arr[],int n);
void insertion(int arr[],int n,int pos);

int main(){
    int n,j,pos;
    printf("\n enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\n");
    for(j=0;j<n;j++){
        printf(" enter the #%d element into the array: ",j+1);
        scanf("%d",&arr[j]);
    }
    printf("\n The array is......");
    print_array(arr,n);
    printf("\n\n enter the position to insert the new element into the array: ");
    scanf("%d",&pos);
    printf("\n Insertion of a element at beginning of the array...");
    insertion(arr,n,pos);
}

void print_array(int arr[],int n){
    printf("[ ");
    int i;
    for(i=0;i<n-1;i++){
        printf("%d, ",arr[i]);
    }
    printf("%d ]",arr[n-1]);
}

void insertion(int arr[],int n,int pos){
   int m=n+1,arr2[m],i;
   for(i=0;i<n;i++){
    arr2[i]=arr[i];
   }
   for(i=n-1;i>=pos-1;i--){
    arr2[i+1]=arr[i];
   }
   printf("\n enter the new element to insert at %d position: ",pos);
   scanf("%d",&arr2[pos-1]);
   print_array(arr2,m);
}