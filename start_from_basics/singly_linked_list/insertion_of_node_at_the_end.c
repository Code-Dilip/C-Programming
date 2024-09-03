#include<stdlib.h>
#include<stdio.h>

struct node {
    int data;
    struct node *link;
};

void print_list(struct node *head){
    if(head == NULL)
       printf("\n The linked list is empty! ");
    struct node *ptr = head;
    int count = 0;
    while(ptr!=NULL){
        count++;
        printf("\n The data of the #%d node is %d .",count,ptr->data);
        ptr = ptr->link;
    }
}

void add_node_at_end(struct node *head,int data){

    struct node *ptr,*temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;

}

int main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;
    
    add_node_at_end(head,2);
    add_node_at_end(head,3);
    add_node_at_end(head,4);

    printf("\n");
    print_list(head);
    printf("\n\n");

    free(head);
    return 0;
}