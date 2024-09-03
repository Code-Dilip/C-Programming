#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void insert_node_ascending(struct node **head,struct node *temp){
    if((*head)==NULL || (*head)->data > temp->data){
        temp->link = (*head);
        *head = temp;
    }
    else{
        struct node *ptr = (*head);
        while(ptr->link != NULL && ptr->link->data < temp->data){
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}

void create_linked_list(struct node **head){
    int n;
    struct node *temp = NULL;
    printf("\n enter the no. of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        temp = (struct node *)malloc(sizeof(struct node));
        printf(" enter the data in the #%d node: ",i);
        scanf("%d",&(temp->data));
        temp->link = NULL;
        insert_node_ascending(head,temp);
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
    struct node *head1 = NULL;
    create_linked_list(&head1);
    printf("\n The sorted linked list is");
    print_list(head1);

    printf("\n\n");
    free(head1);
    return 0;
}