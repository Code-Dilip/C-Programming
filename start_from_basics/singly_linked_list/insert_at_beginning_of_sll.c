#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void print_list(struct node *ptr){
    if(ptr==NULL)
      printf("\n The list is empty!");
    int count = 0;
    while(ptr!=NULL){
        count++;
        printf("\n The data of the #%d node is %d .",count,ptr->data);
        ptr = ptr->link;
    }
}

struct node *insert_node_at_begging(struct node *head,int data){
   struct node *ptr = (struct node *)malloc(sizeof(struct node));
   ptr->data = data;
   ptr->link = head;
   head = ptr;
   return head;
}

int main(){
    struct node *head = NULL;
    head = insert_node_at_begging(head,5);
    head = insert_node_at_begging(head,4);
    head = insert_node_at_begging(head,3);
    head = insert_node_at_begging(head,2);
    head = insert_node_at_begging(head,1);
    
    printf("\n The linked list: ");
    print_list(head);
    printf("\n\n");
    return 0;h7ytv
}