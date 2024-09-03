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
    printf("\n\n");
    free(head);
    return 0;
}