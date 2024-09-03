#include<stdio.h>
#include<stdlib.h>

struct node{
    int data1;
    int data2;
    struct node *link;
};

int main(){
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    head->data1=1;
    head->data2=2;
    head->link=NULL;
    printf("\n data_1:%d, data_2:%d ",head->data1,head->data2);
    printf("\n address to which head ptr is pointing to....%p ",head);
    printf("\n Done, Thank You! ");
    return 0;
}