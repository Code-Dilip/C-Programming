#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void print_data(struct node *head){
    if(head == NULL){
        printf("\n The linked list is empty!");
    }
    struct node *ptr = head;
    int count = 0;
    while(ptr!=NULL){
        count ++;
        printf("\n The data of the #%d node is %d .",count,ptr->data);
        ptr = ptr->link;
    }
}

int main() {

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

    printf("\n");
    print_data(head);
    printf("\n\n");
    
    free(head);
    free(current);

    return 0;
    }