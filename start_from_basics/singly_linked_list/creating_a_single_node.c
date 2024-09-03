#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf(" enter the data with of the node: ");
    scanf("%d",&(head->data));
    head->link = NULL;

    printf("\n The data of the node is %d .",head->data);
    free(head);
    return 0;
}