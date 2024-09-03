#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *nxt;
};

int count_nodes(struct node *tail){
    struct node *ptr = tail->nxt;
    int count = 0;
    do{
        count ++;
        ptr = ptr->nxt;
    }
    while(ptr != tail->nxt);
    
    return count;
}

void print_list(struct node *tail){
    if(tail == NULL){
        printf("\n The linked list is empty! ");
    }
    else {
        struct node *ptr = tail->nxt;
    printf(" %d ",ptr->data);
    ptr = ptr->nxt;
    do{
        printf("-> %d ",ptr->data);
        ptr = ptr->nxt;
    }
    while(ptr != tail->nxt);
    printf(".");
    }
}

struct node add_node_at_beginning(struct node **tail,int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->nxt = temp;
    if(*tail == NULL){
        *tail = temp;
    }
    else{
        temp->nxt = (*tail)->nxt;
        (*tail)->nxt = temp;
    }
}

struct node add_node_at_end(struct node **tail,int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->nxt = temp;
    if(*tail == NULL){
        *tail = temp;
    }
    else{
        temp->nxt = (*tail)->nxt;
        (*tail)->nxt = temp;
        *tail = temp;
    }
}

struct node add_node_at_certain_pos(struct node **tail,int data,int pos){
    struct node *ptr = (*tail)->nxt;
    if(*tail == NULL || pos == 1){
        add_node_at_beginning(tail,data);
    }
    else if(pos >= count_nodes(ptr)){
        add_node_at_end(tail,data);
    }
    else{
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->nxt = temp;
        pos --;
        while(pos != 1){
            ptr = ptr->nxt;
            pos --;
        }
        temp->nxt = ptr->nxt;
        ptr->nxt = temp;
    }
}

struct node delete_node_at_beginning(struct node **tail){
    if(*tail == NULL){
        printf("\n The linked list is empty! ");
    }
    else{
        struct node *ptr = (*tail)->nxt;
        (*tail)->nxt = ptr->nxt;
        free(ptr);
        ptr = NULL;
    }
}

struct node delete_node_at_end(struct node **tail){
    if(*tail == NULL){
        printf("\n The linked list is empty! ");
    }
    else{
        struct node *ptr = (*tail)->nxt;
        do{
            ptr = ptr->nxt;
        }
        while((ptr->nxt)->nxt != (*tail)->nxt);
        ptr->nxt = (*tail)->nxt;
        free(*tail);
        *tail = ptr;
    }
}

struct node delete_node_at_certain_position(struct node **tail,int pos){
    struct node *ptr = (*tail)->nxt;
    if(*tail == NULL){
        printf("\n The linked list is empty! ");
    }
    if(pos == 1){
        delete_node_at_beginning(tail);
    }
    else if(pos >= count_nodes(ptr)){
        delete_node_at_beginning(tail);
    }
    else{
        struct node *prev = NULL;
        while(pos != 1){
            prev = ptr;
            ptr = ptr->nxt;
            pos --;
        }
        prev->nxt = ptr->nxt;
        free(ptr);
        ptr = NULL;
    }
}

struct node delete_entire_list(struct node **tail){
    if(*tail == NULL){
        printf("\n The list is already empty! ");
    }
    else{
        struct node *ptr = *tail;
        int count = count_nodes(ptr);
        while(count != 0){
            delete_node_at_end(tail);
            count --;
        }
        *tail = NULL;
    }
}

struct node reverse_list(struct node **tail){
    if(*tail == NULL){
        printf("\n The list is already empty! ");
    }
    else{
       struct node *head = (*tail)->nxt,*curr = head,*prev,*nxt = curr->nxt;
       while(curr != (*tail)){
        prev = curr;
        curr = nxt;
        nxt = curr->nxt;
        curr->nxt = prev;
       }
       nxt->nxt = *tail,

       curr = head;
       head = *tail;
       *tail = curr;
    }
}


int main(){
    struct node *tail = NULL;

    add_node_at_beginning(&tail,5);
    add_node_at_beginning(&tail,4);
    add_node_at_beginning(&tail,3);
    add_node_at_beginning(&tail,2);
    add_node_at_beginning(&tail,1);
    printf("\n\n The linked list after adding few nodes at the begining is");
    print_list(tail);

    add_node_at_end(&tail,6);
    add_node_at_end(&tail,7);
    add_node_at_end(&tail,8);
    add_node_at_end(&tail,9);
    add_node_at_end(&tail,10);
    printf("\n\n The linked list after adding few nodes at the end is");
    print_list(tail);

    add_node_at_certain_pos(&tail,11,1);
    add_node_at_certain_pos(&tail,12,3);
    add_node_at_certain_pos(&tail,13,5);
    add_node_at_certain_pos(&tail,14,7);
    add_node_at_certain_pos(&tail,15,20);
    printf("\n\n The linked list after adding few nodes at certain positions is");
    print_list(tail);

    delete_node_at_beginning(&tail);
    printf("\n\n The linked list after deleting a node at beginning is");
    print_list(tail);
    
    delete_node_at_end(&tail);
    printf("\n\n The linked list after deleting a node at end is");
    print_list(tail);

    delete_node_at_certain_position(&tail,1);
    delete_node_at_certain_position(&tail,3);
    delete_node_at_certain_position(&tail,5);
    delete_node_at_certain_position(&tail,20);
    printf("\n\n The linked list after deleting nodes at certain positions is");
    print_list(tail);

    reverse_list(&tail);
    printf("\n\n The linked list after reversing is");
    print_list(tail);

    delete_entire_list(&tail);
    if(tail == NULL){
        printf("\n\n The linked list is deleted successfully! ");
    }
    printf("\n The list after deleting the entire list at once is");
    print_list(tail);

    printf("\n\n");
    free(tail);
    return 0;
}