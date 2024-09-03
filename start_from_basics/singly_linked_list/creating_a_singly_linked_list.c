#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

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
    printf("\n The data of the fourth node is %d .",(head->link->link->link)->data);
    printf("\n\n");

    free(head);
    free(current);

    return 0;
}