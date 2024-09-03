#include<stdlib.h>
#include<stdio.h>

int i=0;

struct node{
    struct node *prev;
    int data1;
    int data2;
    struct node *nxt;
};

struct node *add_to_empty(struct node *head){
    i+=1;
    struct node  *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&temp->data1);
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&temp->data2);
    temp->nxt=NULL;
    head=temp;
    return head;
}

void add_at_end(struct node **head){
    struct node *temp,*heady=*head;
    temp=add_to_empty(temp);
    heady->nxt=temp;
    temp->prev=heady;
    heady=temp;
    *head=heady;
}

void add_at_begg(struct node **head){
    struct node *temp,*ptr=*head;

    temp=add_to_empty(temp);
    ptr->prev=temp;
    temp->nxt=*head;
    *head=temp;
}

void insert_a_node(struct node **head,int pos){
    if(pos==1){
        add_at_begg(&*head);
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
        struct node *ptr=add_to_empty(ptr);
        ptr->prev=heady;
        ptr->nxt=heady->nxt;
        heady->nxt->prev=ptr;
        heady->nxt=ptr;
    }
}

void delete_at_1st(struct node **head){
    if(head==NULL){
        printf("\n\n The list is already empty! ");
        return ;
    }
    struct node *ptr=*head;
    ptr=ptr->nxt;
    ptr->prev=NULL;
    free(*head);
    *head=ptr;
}

void delete_at_end(struct node *head){
    if(head==NULL){
        printf("\n\n The list is already empty! ");
        return ;
    }
    struct node *ptr;
    while(head->nxt){
        head=head->nxt;
    }
    ptr=head->prev;
    head->prev->nxt=NULL;
    free(head);
    head=ptr;
}

void delete_from_pos(struct node **head,int pos){
    if(pos==1){
        delete_at_1st(&*head);
        return;
    }
    int count=1;
    struct node *heady=*head;
    while(count<pos){
        heady=heady->nxt;
        count++;
    }
    if(heady->nxt==NULL ||heady==NULL){
        delete_at_end(heady);
    }
    else{
        heady->prev->nxt=heady->nxt;
        heady->nxt->prev=heady->prev;
        heady->prev=NULL;
        heady->nxt=NULL;
        free(heady);
    }
}

void delete_list(struct node**head){
    struct node *heady=*head;
    while(heady){
        heady=heady->nxt;
        free(*head);
        *head=heady;
    }
    free(*head);
    *head=NULL;
}

void print_list(struct node *ptr){
    if(ptr==NULL){
        printf("\n The list is already empty! ");
    }
    i=0;
    while(ptr){
        i+=1;
        printf("\n The Data of the #%d node is..... Data_1: %d, Data_2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->nxt;
    }
}

int main(){
    int n;
    printf("\n enter the lenght of the list: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n No nodes were created! ");
        return 0;
    }
    struct node *ptr,*head;
    int j,pos;
    char wd;

    head=add_to_empty(head);
    ptr=head;

    for(j=2;j<=n;j++){
        add_at_end(&head);
    }

    print_list(ptr);

    printf("\n\n enter a position to insert a new node: ");
    scanf("%d",&pos);
    insert_a_node(&ptr,pos);
    
    printf("\n The list after inserting a new node is.....");
    print_list(ptr);

    printf("\n\n The list after deleting the first node is.....");
    delete_at_1st(&ptr);
    print_list(ptr);

    printf("\n\n The list after deleting the last node is......");
    delete_at_end(ptr);
    print_list(ptr);

    printf("\n\n enter a position to delete a node: ");
    scanf("%d",&pos);
    
    printf("\n\n The list after deleting of node from #%d position is....... ",pos);
    delete_from_pos(&ptr,pos);
    print_list(ptr);

    printf("\n\n Do you want to deleter the entire list?(y/n): ");
    scanf("%s",&wd);
    if(wd=='y' || wd=='Y'){
        delete_list(&ptr);
    }

    if(ptr==NULL){
        printf("\n\n The list is deleted successfully! ");
        print_list(ptr);
    }
    printf("\n\n  Done, Thank You! ");
    free(head);
    return 0;
}