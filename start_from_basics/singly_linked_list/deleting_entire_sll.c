#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void print_list(struct node *ptr){
    if(ptr == NULL){
        printf("\n The linked list is empty!");
    }
    int count = 0;
    while (ptr!=NULL)
    {
        count ++;
        printf("\n The data of the #%d node is %d .",count,ptr->data);
        ptr = ptr->link;
    }
}

int count_nodes(struct node *ptr){
    int count = 0;
    while(ptr!=NULL){
        count ++;
        ptr = ptr->link;
    }
    return count;
}

void add_node_at_end(struct node **head,int data){
    struct node *ptr = *head,*temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if(*head == NULL){
        *head = temp;
    }
    else{
        while(ptr->link != NULL) {
            ptr = ptr->link;
        }
    ptr->link = temp;
    }
}

void add_node_at_beginning(struct node **head,int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if(*head == NULL){
        *head = temp;
    }
    else{
        temp->link = *head;
        *head = temp;
    }
}

void add_node_at_certain_pos(struct node **head,int pos,int data){
    struct node *ptr = *head;
    if(pos == 1){
        add_node_at_beginning(head,data);
    }
    else if(pos > count_nodes(ptr)){
        add_node_at_end(head,data);
    }
    else {
        struct node *ptr = *head,*temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->link = NULL;
    
        pos --;
        while(pos!=1){
          ptr = ptr->link;
          pos --;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}

void delete_node_at_beginning(struct node **head){
    if(*head == NULL){
        printf("\n The linked list is already empry! ");
    }
    else{
        struct node *ptr = (*head)->link;
        free(*head);
        *head = ptr;
    }
}

void delete_node_at_end(struct node **head){
    if(*head == NULL){
        printf("\n The linked list is already empty! ");
    }
    else if((*head)->link == NULL){
        free(*head);
        (*head) = NULL;
    }
    else{
        struct node *ptr = (*head);
        while((ptr->link)->link != NULL){
            ptr = ptr->link;
        }
        free((ptr->link)->link);
        (ptr->link) = NULL;
    }
}

void delete_node_at_certain_pos(struct node **head,int pos){
    struct node *ptr = *head;
    if(pos == 1){
        delete_node_at_beginning(head);
    }
    else if(pos >= count_nodes(ptr)){
        delete_node_at_end(head);
    }
    else{
        struct node *prev = NULL;
        while(pos!=1){
            prev = ptr;
            ptr = ptr->link;
            pos --;
        }
        prev->link = ptr->link;
        free(ptr);
        ptr = NULL;
    }
}

void delete_entire_linked_list(struct node **head){
    if(*head == NULL){
        printf("\n The linked list is already empty! ");
    }
    else{
        struct node *temp = *head;
        while(temp!=NULL){
            temp = temp->link;
            free(*head);
            (*head) = temp;
        }
        *head = NULL;
        free(temp);
    }
}

int main(){
    struct node *head = NULL;
    add_node_at_end(&head,1);
    add_node_at_end(&head,2);
    add_node_at_end(&head,3);
    add_node_at_end(&head,4);
    add_node_at_end(&head,5);

    printf("\n The linked list before inserting few more nodes is as follows: ");
    print_list(head);
    add_node_at_certain_pos(&head,1,6);
    add_node_at_certain_pos(&head,3,7);
    add_node_at_certain_pos(&head,5,8);
    add_node_at_certain_pos(&head,20,9);

    printf("\n\n The linked list after adding few more nodes is as follows: ");
    print_list(head);
    
    delete_node_at_beginning(&head);
    printf("\n\n The linked list after deleting a node at the beginning of the linked list is as follows: ");
    print_list(head);

    delete_node_at_end(&head);
    printf("\n\n The linked list after deleting the last node is as follows: ");
    print_list(head);
    
    delete_node_at_certain_pos(&head,5);
    delete_node_at_certain_pos(&head,9);
    printf("\n\n The linked list after deleting a node at certain position is as follows: ");
    print_list(head);

    delete_entire_linked_list(&head);
    if(head == NULL){
        printf("\n\n The linked list is deleted successfully! ");
    }
    print_list(head);

    printf("\n\n");
    free(head);
    return 0;
}