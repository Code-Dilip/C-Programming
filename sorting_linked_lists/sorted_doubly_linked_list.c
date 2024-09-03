#include<stdlib.h>
#include<stdio.h>

int i=0;

struct node{
    struct node *prev;
    int data;
    struct node *nxt;
};

struct node *add_node(){
    i+=1;
    struct node *newp=malloc(sizeof(struct node));
    newp->prev=NULL;
    printf(" enter the data for the #%d node: ",i);
    scanf("%d",&newp->data);
    newp->nxt=NULL;
}

void inc_ord(struct node **head){
    struct node *heady=*head,*newp=add_node();
    if(*head==NULL){
        newp->nxt=*head;
        *head=newp;
        return;
    }
    else if(newp->data<heady->data){
        newp->nxt=*head;
        heady->prev=newp;
        *head=newp;
        return;
    }
    else{
        while (heady->nxt!=NULL && newp->data>heady->nxt->data)
        {
            heady=heady->nxt;
        }
        if(heady->nxt){
            heady->nxt->prev=newp;
        }
        newp->nxt=heady->nxt;
        newp->prev=heady;
        heady->nxt=newp;
    }
}

void dec_ord(struct node **head){
    struct node *heady=*head,*newp=add_node();
    if(*head==NULL){
        newp->nxt=*head;
        *head=newp;
        return;
    }
    else if(newp->data>heady->data){
        newp->nxt=*head;
        heady->prev=newp;
        *head=newp;
        return;
    }
    else{
        while(heady->nxt!=NULL && newp->data<heady->nxt->data){
            heady=heady->nxt;
        }
        if(heady->nxt){
            heady->nxt->prev=newp;
        }
        newp->prev=heady;
        newp->nxt=heady->nxt;
        heady->nxt=newp;
    }
}

void print_list(struct node *head){
    i=0;
    while(head){
        i+=1;
        printf("\n The data of the #%d node is %d.",i,head->data);
        head=head->nxt;
    }
}

int main(){
    int n;
    printf("\n enter the no. of the nodes: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n No nodes were created! ");
        exit(0);
    }
    struct node *head=NULL;
    int j,ord;
    printf("\n enter the order of the list: ");
    scanf("%d",&ord);
    if(ord==1){
        printf("\n");
        for(j=1;j<=n;j++){
            inc_ord(&head);
        }
    }
    else if(ord==-1){
        printf("\n");
        for(j=1;j<=n;j++){
            dec_ord(&head);
        }
    }
    printf("\n\n The list is.....");
    print_list(head);
    free(head);
    printf("\n Done, Thank You! ");
    return 0;
}