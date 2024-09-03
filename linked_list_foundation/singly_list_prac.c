#include<stdio.h>
#include<stdlib.h>

int i;

struct node{
    int data1;
    int data2;
    struct node *nxt;
};

struct node *add_node(){
    i+=1;
    struct node *temp;
    temp=malloc(sizeof(struct node));
    printf("\n enter the first data in the %d node: ",i);
    scanf("%d",&temp->data1);
    printf(" enter the second data in the %d node: ",i);
    scanf("%d",&temp->data2);
    temp->nxt=NULL;
    return temp;
}

void add_at_1st(struct node **head){
    struct node *temp=add_node();
    temp->nxt=*head;
    *head=temp;
}

void add_at_end(struct node *head){
    struct node *temp=add_node();
    while(head->nxt){
        head=head->nxt;
    }
    head->nxt=temp;
    temp->nxt=NULL;
}

void add_at_pos(struct node **head,int pos){
    if(pos==1){
        add_at_1st(&*head);
        return;
    }
    int count=1;
    struct node *ptr=*head;
    while(count<pos-1){
        ptr=ptr->nxt;
        count++;
    }
    if(ptr->nxt==NULL || ptr==NULL){
        add_at_end(*head);
        return;
    }
    struct node *temp=add_node();
    temp->nxt=ptr->nxt;
    ptr->nxt=temp;
}

void delete_at_1st(struct node **head){
    if(*head==NULL){
        printf("\n The list is empty! ");
        return;
    }
    struct node *ptr=*head;
    *head=ptr->nxt;
    free(ptr);
}

void delete_at_last(struct node *head){
    if(head==NULL){
        printf("\n The list is empty! ");
        return ;
    }
    while(head->nxt->nxt){
        head=head->nxt;
    }
    free(head->nxt->nxt);
    head->nxt=NULL;
}

void delete_list(struct node **head){
    if(*head==NULL){
        printf("\n The list is already empty! ");
        return;
    }
    struct node *ptr=*head;
    while(ptr){
        *head=ptr;
        ptr=ptr->nxt;
        free(*head);
    }
    *head=NULL;
}

void reverse_list(struct node **head){
    if(*head==NULL){
        printf("\n The list is empty! ");
        return;
    }
    struct node *prev=NULL,*curr=*head,*nxt_node=NULL;
    while (curr)
    {
        nxt_node=curr->nxt;
        curr->nxt=prev;
        prev=curr;
        curr=nxt_node;
    }
    *head=prev;
}


void print_list(struct node *ptr){
    i=0;
    while(ptr!=NULL){
        i+=1;
        printf("\n The data of the %d node is....... Data_1: %d, Data_2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->nxt;
    }
}

int main(){
    int n;
    printf("\n enter the no. of nodes: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n No nodes were created! ");
        exit(0);
    }
    int j;
    struct node *head=add_node(),*ptr;
    int ord,pos;
    char wd;
    
    printf("\n enter the order of the list: ");
    scanf("%d",&ord);
    if(ord==1){
        for(j=2;j<=n;j++){
            add_at_1st(&head);
        }
    }
    else if(ord==-1){
        for(j=2;j<=n;j++){
            add_at_end(head);
        }
    }
    printf("\n The linked list formed is.......");
    print_list(head);
    
    printf("\n\n enter the position to insert a new node: ");
    scanf("%d",&pos);
    add_at_pos(&head,pos);
    printf("\n The list after adding a new node at #%d position is......",pos);
    print_list(head);
    printf("\n");

    printf("\n The list after reversing is.......");
    reverse_list(&head);
    print_list(head);

    delete_at_1st(&head);
    printf("\n\n The list after deleting the first node is.......");
    print_list(head);

    printf("\n\n The list after deleting the last node is.......");
    delete_at_last(head);
    print_list(head);

    printf("\n\n Do you want to delete entire list(y/n)?  ");
    scanf("%s",&wd);
    if(wd=='y' || 'Y'){
        delete_list(&head);
        if(head==NULL){
            printf(" The list is deleted successfully! ");
        }
    }

    printf("\n Done, Thank You! ");
    return 0;
}