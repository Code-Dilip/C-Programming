#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *nxt;
};

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

int main(){
    struct node *tail = NULL;

    add_node_at_beginning(&tail,5);
    add_node_at_beginning(&tail,4);
    add_node_at_beginning(&tail,3);
    add_node_at_beginning(&tail,2);
    add_node_at_beginning(&tail,1);
    printf("\n\n The linked list after adding few nodes at the begining is");
    print_list(tail);

    printf("\n\n");
    free(tail);
    return 0;
}