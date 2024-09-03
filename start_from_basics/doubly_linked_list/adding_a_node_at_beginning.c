#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev,*nxt;
};

int count_nodes(struct node *ptr){
    int count = 0;
    while(ptr != NULL){
        count ++;
        ptr = ptr->nxt;
    }
    return count;
}

void print_list(struct node *ptr){
    if(ptr == NULL){
        printf("\n The linked list is empty! ");
    }
    else{
        printf(" %d ",ptr->data);
        ptr = ptr->nxt;
        while(ptr != NULL){
            printf("-> %d ",ptr->data);
            ptr = ptr->nxt;
        }
        printf(".");
    }
}

void add_node_at_beginning(struct node **head,int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->nxt = NULL;
    if(*head == NULL){
        *head = temp;
    }
    else{
        (*head)->prev = temp;
        temp->nxt = *head;
        *head = temp;
    }
}

int main(){

    struct node *head = NULL;
    add_node_at_beginning(&head,5);
    add_node_at_beginning(&head,4);
    add_node_at_beginning(&head,3);
    add_node_at_beginning(&head,2);
    add_node_at_beginning(&head,1);
    printf("\n The linked list after adding few nodes at the beginning is");
    print_list(head);

    printf("\n\n");
    free(head);
    return 0;

}