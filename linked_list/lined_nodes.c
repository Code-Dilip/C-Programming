#include<stdio.h>
#include<stdlib.h>

struct node{
    int data1;
    int data2;
    struct node *link;
};

void print(struct node *ptr){
    printf("\n data_1:%d ,data_2:%d ",ptr->data1,ptr->data2);
}

int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data1=2;
    head->data2=4;
    head->link=NULL;
    print(head);
    
    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data1=8;
    current->data2=16;
    current->link=NULL;
    print(current);

    head->link=current;
    print(head);
    print(head->link);
    printf("\n Done , Thank You! ");
    return 0;
}