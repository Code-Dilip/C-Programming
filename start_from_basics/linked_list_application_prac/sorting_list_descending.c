#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void insert_node_descending(struct node **head,struct node *temp){
    if((*head)==NULL || (*head)->data < temp->data){
        temp->link = (*head);
        *head = temp;
    }
    else{
        struct node *ptr = (*head);
        while(ptr->link != NULL && ptr->link->data > temp->data){
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}

void sort_descending(struct node *ptr,struct node **head){
    struct node *temp = NULL;
    while(ptr != NULL){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = ptr->data;
        temp->link = ptr->link;
        insert_node_descending(head,temp);
        ptr = ptr->link;
    }
}

void add_node_at_end(struct node **head,int i){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf(" enter the data in the #%d node: ",i);
    scanf("%d",&(temp->data));
    temp->link = NULL;

    if((*head) == NULL){
        *head = temp;
    }
    else{
        struct node *ptr = (*head);
        while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
    }
}

void create_linked_list(struct node **head){
    int n;
    printf("\n enter the no. of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        add_node_at_end(head,i);
    }
}

void print_list(struct node *ptr){
    while(ptr->link != NULL){
        printf(" %d ->",ptr->data);
        ptr = ptr->link;
    }
    printf(" %d .",ptr->data);
}

int main(){
    struct node *head1 = NULL,*head2 = NULL;
    create_linked_list(&head1);
    printf("\n The unsorted linked list is");
    print_list(head1);

    sort_descending(head1,&head2);
    printf("\n\n The sorted linked list is");
    print_list(head2);

    printf("\n\n");
    free(head1);
    return 0;
}