#include<stdio.h>
#include<stdlib.h>

int i=1;

struct node {
    int data1;
    int data2;
    struct node *link;
};

struct node *add_at_end(struct node *head){
    i+=1;
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&(ptr->data1));
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&(ptr->data2));
    ptr->link=NULL;

    head->link=ptr;
    head=ptr;
    return head;
}

void add_at_beg(struct node **head){
    i+=1;
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&(ptr->data1));
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&(ptr->data2));
    ptr->link=*head;
    *head=ptr;
}

struct node *rev_list(struct node *head){
    struct node *prev=NULL,*nxt=NULL;
    while(head!=NULL){
        nxt=head->link;
        head->link=prev;
        prev=head;
        head=nxt;
    }
    head=prev;
    return head;
}

int print_list(struct node *ptr){
    i=0;
    while(ptr!=NULL){
        i+=1;
        printf("\n The data of the #%d node is..... Data_1: %d, Data_2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->link;
    }
    return i;
}

int main(){
    int n,len,j;
    char wr;
    printf("\n enter the no. of nodes: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n No nodes were created! ");
        exit(0);
    }
    struct node *head,*ptr;
    head=malloc(sizeof(struct node));
    ptr=head;
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&(head->data1));
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&(head->data2));
    head->link=NULL;

    for(j=2;j<=n;j++){
        head=add_at_end(head);
    }
    len=print_list(ptr);
    printf("\n The total no. of nodes in the list is %d ",len);

    printf("\n Do you want to reverse the list? (y/n): ");
    scanf("%s",&wr);
    if(wr=='y' || wr=='Y'){
        ptr=rev_list(ptr);
    }
    len=print_list(ptr);
    printf("\n The total no. of node in the list after reversing it is %d ",len);
    printf("\n Done , Thank You! ");
    free(head);
    return 0;
}