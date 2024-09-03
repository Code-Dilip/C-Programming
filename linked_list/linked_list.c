#include<stdio.h>
#include<stdlib.h>

int i=1;

struct node{
    int data1;
    int data2;
    struct node *link;
};

void print(struct node *ptr){
    i+=1;
    printf("\n The data of #%d node is.... data_1:%d , data_2:=%d ",i,ptr->data1,ptr->data2);
}

int main(){

    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->data1=3;
    head->data2=6;
    print(head);

    head->link=(struct node *)malloc(sizeof(struct node));
    head->link->data1=9;
    head->link->data2=12;
    print(head->link);

    head->link->link=(struct node *)malloc(sizeof(struct node));
    head->link->link->data1=15;
    head->link->link->data2=18;
    head->link->link->link=NULL;
    print(head->link->link);

    free(head->link->link);
    free(head->link);
    free(head);
    
    printf("\n Done, Thank You! ");
    return 0;

}