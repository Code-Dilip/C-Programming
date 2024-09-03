#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int count_nodes(struct node *head){
    if(head == NULL){
        printf("\n The linked list is empty! ");
    }
    struct node *ptr = head;
    int count = 0;
    while(ptr!=NULL){
        count ++;
        ptr = ptr->link;
    }
    return count;
}

int main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the data in the first node: ");
    scanf("%d",&(head->data));
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    printf(" enter the data in the second node: ");
    scanf("%d",&(current->data));
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    printf(" enter the data in the third node: ");
    scanf("%d",&(current->data));
    current->link = NULL;
    head->link->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    printf(" enter the data in the fourth node: ");
    scanf("%d",&(current->data));
    current->link = NULL;
    head->link->link->link = current;

    printf("\n\n The data of the first node is %d .",head->data);
    printf("\n The data of the second node is %d .",(head->link)->data);
    printf("\n The data of the third node is %d .",(head->link->link)->data);
    printf("\n The data of the fourth node is %d .",(head->link->link->link->data));

    printf("\n\n The no. of nodes in the linked list is %d .",count_nodes(head));
    printf("\n\n");
    return 0;
}