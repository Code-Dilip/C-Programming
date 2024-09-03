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

    printf("\n\n");
    free(tail);
    return 0;
}