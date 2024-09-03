#include<stdio.h>
#include<stdlib.h>

int insert_at_end(int arr[],int data,int free_pos){
    arr[free_pos] = data;
    free_pos ++;
    return free_pos;
}

void print_arr(int arr[],int free_pos){
    for(int i=0;i<free_pos;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[100];
    int n,free_pos,data;
    printf("\n enter the no. of elements: ");
    scanf("%d",&n);
    printf("\n");
    for(int i=0;i<n;i++){
        printf(" enter the #%d element into the array: ",i+1);
        scanf("%d",&arr[i]);
    }
    
    free_pos = n;
    printf(" enter the data: ");
    scanf("%d",&data);
    free_pos = insert_at_end(arr,data,free_pos);
    printf(" enter the data: ");
    scanf("%d",&data);
    free_pos = insert_at_end(arr,data,free_pos);

    printf("\n The array elements are:[ ");
    print_arr(arr,free_pos);
    printf("]\n\n");

    return 0;
    
}