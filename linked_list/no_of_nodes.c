#include<stdio.h>
#include<stdlib.h>

int i;

struct node{
    int data1;
    int data2;
    struct node *link;
};

int no_of_nodes(struct node *ptr){
    while(ptr!=NULL){
        i+=1;
        printf("\n Data of #%d node is.....Data_1: %d , Data_2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->link;
    }
    printf("\n The total no. of nodes is %d .",i);
}

int main(){

    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->data1=3;
    head->data2=6;
    
    head->link=(struct node*)malloc(sizeof(struct node));
    head->link->data1=9;
    head->link->data2=12;
    
    head->link->link=(struct node*)malloc(sizeof(struct node));
    head->link->link->data1=15;
    head->link->link->data2=18;
    
    head->link->link->link=NULL;

    no_of_nodes(head);
    free(head->link->link);
    free(head->link);
    free(head);

    printf("\n Done, Thank You! ");
    return 0;
    
}