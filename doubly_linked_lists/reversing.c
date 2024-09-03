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

void reverse_list(struct node **head){
    struct node *heady=*head,*nxt=NULL,*prev=NULL;
    while(heady){
        nxt=heady->nxt;
        heady->nxt=prev;
        prev=heady;
        heady=nxt;
    }
    *head=prev;
}

void print_list(struct node *ptr){
    i=0;
    while(ptr){
        i+=1;
        printf("\n The Data of the #%d node is.... Data_1: %d, Data_2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->nxt;
    }
}

int main(){
    int n;
    printf("\n enter the length of the list: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n\n No nodes were created! ");
        return 0;
    }
    struct node *head=add_a_node(head),*ptr=head;
    int j;
    char wr;

    for(j=2;j<=n;j++){
        add_at_end(&head);
    }
    
    printf("\n\n The linked list is.......");
    print_list(ptr);

    printf("\n\n Do you want to reverse the list?(y/n): ");
    scanf("%s",&wr);
    if(wr=='y' || wr=='Y'){
        reverse_list(&ptr);
    }

    printf(" The list after reversing is......");
    print_list(ptr);
    
    printf("\n\n Done, Thank You! \n\n");
    free(head);
    return 0;
} 
