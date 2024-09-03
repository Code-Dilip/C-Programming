#include<stdlib.h>
#include<stdio.h>

struct node {
    int data;
    struct node *link;
};

void insert_node_at_beginning(struct node **head,int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = *head;
    *head = ptr;
}

void print_list(struct node *ptr){
    if(ptr == NULL)
      printf("\n The linked list is empty! ");
    int count = 0;
    while(ptr!=NULL){
        count ++;
        printf("\n The data of the #%d node is %d. ",count,ptr->data);
        ptr = ptr->link;
    }
}

int main(){
    struct node *head = NULL;
    int n,data;
    printf("\n enter the number of nodes you need to add: ");
    scanf("%d",&n);
    for(int i=n;i>0;i--){
        printf(" enter the data of the #%d node: ",i);
        scanf("%d",&data);
        insert_node_at_beginning(&head,data);
    }

    printf("\n The linked list is");
    print_list(head);
    printf("\n\n");
    free(head);
    return 0;

}