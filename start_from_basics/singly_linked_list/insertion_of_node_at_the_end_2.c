#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *insert_node_at_end(struct node *ptr,int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
    return temp;
}

void print_list(struct node *ptr){
    if(ptr == NULL)
      printf("\n The linked list is empty! ");
    int count = 0;
    while(ptr!=NULL){
        count ++;
        printf("\n The data of the #%d node is %d .",count,ptr->data);
        ptr = ptr->link;
    }
}

int main(){

    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;
    struct node *ptr = head;

    ptr = insert_node_at_end(ptr,2);
    ptr = insert_node_at_end(ptr,3);
    ptr = insert_node_at_end(ptr,4);
    ptr = head;
    
    print_list(ptr);
    printf("\n\n");
    free(ptr);
    return 0;

}