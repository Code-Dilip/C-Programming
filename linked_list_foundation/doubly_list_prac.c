#include<stdio.h>
#include<stdlib.h>

int i;

struct node{
    struct node *prev;
    int data1;
    int data2;
    struct node *nxt;
};

struct node *add_node(){
    i+=1;
    struct node *ptr=malloc(sizeof(struct node));
    ptr->prev=NULL;
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&ptr->data1);
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&ptr->data2);
    ptr->nxt=NULL;
    return ptr;
}

void add_at_1st(struct node **head){
    struct node *newp=add_node(),*heady=*head;
    heady->prev=newp;
    newp->nxt=heady;
    *head=newp;
}

void add_at_last(struct node *head){
    struct node *newp=add_node();
    while(head->nxt){
        head=head->nxt;
    }
    head->nxt=newp;
    newp->prev=head;
}

void add_at_pos(struct node **head,int pos){
    if(pos==1){
        add_at_1st(&*head);
        return;
    }
    struct node *heady=*head;
    int count=1;
    while(count<pos-1){
        heady=heady->nxt;
        count++;
    }
    if(heady->nxt==NULL || heady==NULL){
        add_at_last(*head);
        return;
    }
    struct node *newp=add_node();
    newp->prev=heady;
    newp->nxt=heady->nxt;
    heady->nxt->prev=newp;
    heady->nxt=newp;
}

void delete_at_1st(struct node **head){
    if(*head==NULL){
        printf("\n The list is empty! ");
        return;
    }
    struct node *heady=*head;
    *head=heady->nxt;
    heady->nxt->prev=NULL;
    free(heady);
}

void delete_at_last(struct node *head){
    if(head==NULL){
        printf("\n The list is empty! ");
        return;
    }
    while (head->nxt)
    {
        head=head->nxt;
    }
    head->prev->nxt=NULL;
    free(head);
}

void delete_at_pos(struct node **head,int pos){
    if(pos==1){
        delete_at_1st(&*head);
        return;
    }
    struct node *temp=*head;
    int count=1;
    while(count<pos){
        temp=temp->nxt;
        count++;
    }
    if(temp->nxt==NULL || temp==NULL){
        delete_at_last(*head);
        return;
    }
    temp->prev->nxt=temp->nxt;
    temp->nxt->prev=temp->prev;
}

void reverse_list(struct node **head){
   struct node *prev=NULL,*curr=*head,*nxt_node=NULL;
   while(curr){
    nxt_node=curr->nxt;
    curr->nxt=prev;
    prev=curr;
    curr=nxt_node;
   }
   *head=prev;
}

void delete_list(struct node **head){
    if(*head==NULL){
        printf("\n The list is already empty! ");
        return;
    }
    struct node *heady=*head;
    while(heady){
        *head=heady;
        heady=heady->nxt;
        free(*head);
    }
    *head=NULL;
}

void print_list(struct node *head){
    int i=0;
    while(head){
        i+=1;
        printf("\n The data of the #%d node is....... Data_1: %d, Data_2: %d ",i,head->data1,head->data2);
        head=head->nxt;
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
    int ord,j,pos;
    char wd;
    struct node *head=add_node();
    printf("\n enter the order of the list: ");
    scanf("%d",&ord);
    if(ord==1){
        for(j=2;j<=n;j++){
            add_at_1st(&head);
        }
    }
    else if(ord==-1){
        for(j=2;j<=n;j++){
            add_at_last(head);
        }
    }
    printf("\n The list is......");
    print_list(head);

    printf("\n\n Enter a poistion to insert a node: ");
    scanf("%d",&pos);
    if(pos!=0){
        add_at_pos(&head,pos);
        printf("\n\n The list after adding a element at #%d position is.......",pos);
        print_list(head);
    }

    printf("\n\n The list after deleting the first node is......");
    delete_at_1st(&head);
    print_list(head);

    printf("\n\n The list after deleting the last node is.....");
    delete_at_last(head);
    print_list(head);

    printf("\n\n enter a position to delete a node: ");
    scanf("%d",&pos);
    if(pos!=0){
        delete_at_pos(&head,pos);
        printf("\n\n The list after deleting a node at #%d position is........",pos);
        print_list(head);
    }
    
    printf("\n The list after reversing is.......");
    reverse_list(&head);
    print_list(head);

    printf("\n\n Do you want to delete the list(y/n)? ");
    scanf("%s",&wd);
    if(wd=='y' || wd=='Y'){
        delete_list(&head);
        if(head==NULL){
            printf("\n The list is deleted successfully! ");
        }
    }
    printf("\n Done, Thank You! \n\n");
    return 0;
}