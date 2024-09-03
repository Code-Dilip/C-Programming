#include<stdio.h>
#include<stdlib.h>

int i;

struct node {
    struct node *prev;
    int data1;
    int data2;
    struct node *nxt;
};

struct node *add_a_node(struct node *head){
    i+=1;
    struct node *ptr=malloc(sizeof(struct node));
    ptr->prev=NULL;
    printf("\n enter the first data of the #%d node: ",i);
    scanf("%d",&ptr->data1);
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&ptr->data2);
    ptr->nxt=NULL;
    head=ptr;
    return head;
}

void add_at_end(struct node **head){
    struct node *ptr=add_a_node(ptr),*heady=*head;
    ptr->prev=*head;
    heady->nxt=ptr;
    *head=ptr;
}

void add_at_1st(struct node **head){
    struct node *ptr=add_a_node(ptr),*heady=*head;
    heady->prev=ptr;
    ptr->nxt=*head;
    *head=ptr;
}

void print_list(struct node *ptr){
    i=0;
    while(ptr){
        i+=1;
        printf("\n The Data of the #%d node is.... Data_1: %d, Data_2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->nxt;
    }
}

void insert_a_node(struct node **head,int pos){
    if(pos==1){
        add_at_1st(&*head);
        return;
    }
    int count=1;
    struct node *heady=*head;
    while(count<pos-1){
        heady=heady->nxt;
        count++;
    }
    if(heady->nxt==NULL){
        add_at_end(&heady);
    }
    else{
        struct node *ptr=add_a_node(ptr);
        ptr->prev=heady;
        ptr->nxt=heady->nxt;
        heady->nxt->prev=ptr;
        heady->nxt=ptr;
    }
}

int main(){
    int n;
    printf("\n enter the no. of nodes: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n No, nodes were created! ");
        printf(" Done, Thank You! ");
        return 0;
    }
    struct node *head=add_a_node(head),*ptr;
    ptr=head;
    int j,pos;
    for(j=2;j<=n;j++){
        add_at_end(&head);
    }
    print_list(ptr);

    printf("\n\n enter a position to add a node: ");
    scanf("%d",&pos);
    insert_a_node(&ptr,pos);
    
    printf("\n\n The list after adding a node is...");
    print_list(ptr);
    printf("\n\n Done, Thank You! ");
    return 0;
}