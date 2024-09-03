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

void delete_node_at_beginning(struct node **head){
    if((*head) == NULL){
        printf("\n\n The linked list is empty! ");
    }
    else if((*head)->nxt == NULL){
        free(*head);
        *head = NULL;
    }
    else{
        struct node *ptr = (*head)->nxt;
        ptr->prev = NULL;
        free(*head);
        *head = ptr;
    }
}

void delete_node_at_end(struct node **head){
    if(*head == NULL){
        printf("\n\n The linked list is empty! ");
    }
    else if((*head)->nxt == NULL){
        free(*head);
        *head = NULL;
    }
    else{
        struct node *ptr = *head;
        while((ptr->nxt)->nxt != NULL){
            ptr = ptr->nxt;
        }
        free(ptr->nxt);
        ptr->nxt = NULL;
    }
}

void delete_node_at_certain_pos(struct node **head,int pos){
    struct node *ptr = *head;
    if(*head == NULL){
        printf("\n The linked list is empty! ");
    }
    if(pos == 1){
        delete_node_at_beginning(head);
    }
    else if(pos > count_nodes(ptr)){
        delete_node_at_end(head);
    }
    else{
        struct node *prev = *head;
        while(pos != 1){
            prev = ptr;
            ptr = ptr->nxt;
            pos --;
        }
        (ptr->nxt)->prev = ptr->prev;
        prev->nxt = ptr->nxt;
        free(ptr);
    }
}

void delete_entire_list(struct node **head){
    if(*head == NULL){
        printf("\n The list is already empty! ");
    }
    else{
        struct node *temp = *head;
        while((*head) != NULL){
            temp = temp->nxt;
            free(*head);
            *head = temp;
        }
    }
}

void reverse_list(struct node **head){
    if(*head == NULL){
        printf("\n The linked list afready empty! ");
    }
    else{
        struct node *prev = NULL,*nxt = NULL;
        while(*head != NULL){
            nxt = (*head)->nxt;
            (*head)->nxt = prev;
            prev = *head;
            *head = nxt;
        }
        *head = prev;
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

    delete_node_at_beginning(&head);
    printf("\n\n The linked list after deleting a node at the beginning is");
    print_list(head);

    delete_node_at_end(&head);
    printf("\n\n The linked list after deleting a node at the end is");
    print_list(head);

    delete_node_at_certain_pos(&head,1);
    delete_node_at_certain_pos(&head,3);
    delete_node_at_certain_pos(&head,20);
    printf("\n\n The linked list after deleting nodes at certain positions is");
    print_list(head);

    reverse_list(&head);
    printf("\n\n The linked list after reversing is");
    print_list(head);

    delete_entire_list(&head);
    if(head == NULL){
        printf("\n\n The list deleted successfully! ");
    }
    printf("\n The linked list after deleting it entirely is");
    print_list(head);

    printf("\n\n");
    free(head);
    return 0;

}