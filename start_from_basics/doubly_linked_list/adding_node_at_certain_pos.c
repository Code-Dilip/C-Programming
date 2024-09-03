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

void add_node_at_end(struct node **head,int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->nxt = NULL;
    if(*head == NULL){
        *head = temp;
    }
    else{
        struct node *ptr = *head;
        while((ptr->nxt)!=NULL){
            ptr = ptr->nxt;
        }
        temp->prev = ptr;
        ptr->nxt = temp;
    }
}

void add_node_at_certain_pos(struct node **head,int data,int pos){
    struct node *ptr = *head;
    if(pos == 1 || (*head == NULL)){
        add_node_at_beginning(head,data);
    }
    else if(pos >= count_nodes(ptr)){
        add_node_at_end(head,data);
    }
    else{
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->prev = NULL;
        temp->data = data;
        temp->nxt = NULL;

        pos --;
        while(pos != 1){
            ptr = ptr->nxt;
            pos --;
        }
        temp->prev = ptr;
        temp->nxt = ptr->nxt;
        ptr->nxt = temp;
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

    add_node_at_end(&head,6);
    add_node_at_end(&head,7);
    add_node_at_end(&head,8);
    add_node_at_end(&head,9);
    add_node_at_end(&head,10);
    printf("\n\n The linked list after adding few more nodes at the end is");
    print_list(head);

    add_node_at_certain_pos(&head,11,1);
    add_node_at_certain_pos(&head,12,3);
    add_node_at_certain_pos(&head,13,5);
    add_node_at_certain_pos(&head,14,7);
    add_node_at_certain_pos(&head,15,20);
    printf("\n\n The linked list after adding nodes at certain positions is");
    print_list(head);

    printf("\n\n");
    free(head);
    return 0;

}