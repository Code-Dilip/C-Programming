#include<stdio.h>
#include<stdlib.h>
int i=1;

struct node{
    int data1;
    int data2;
    struct node *link;
};

struct node *add_node_at_end(struct node *head){
    i+=1;
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("\n enter the first data of the #%d node: ",i);
    scanf("%d",&(ptr->data1));
    printf(" enter the second data of the #%d node: ",i);
    scanf("%d",&(ptr->data2));
    ptr->link=NULL;
    head->link=ptr;
    head=head->link;
    return head;
}

void add_node_at_beg(struct node **head){
    i+=1;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\n enter the first data of the #%d node: ",i);
    scanf("%d",&(temp->data1));
    printf(" enter the second data of the #%d node: ",i);
    scanf("%d",&(temp->data2));
    temp->link=*head;
    *head=temp;

}

int print_nodes(struct node *ptr){
    i=0;
    while(ptr!=NULL){
        i+=1;
        printf("\n The Data of #%d node is..... Data_1: %d, Data_2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->link;
    }
    return i;
}

int main(){
    int n,j,len,ord;
    printf("\n enter the length of the linked list: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n No nodes were created! ");
        printf("\n\n Done, Thank You! \n\n");
        return 0;
    }
    struct node *head,*ptr;
    head=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    printf("\n enter the first data of the #%d node: ",i);
    scanf("%d",&(head->data1));
    printf(" enter the second data of the #%d node: ",i);
    scanf("%d",&(head->data2));
    head->link=NULL;
    printf("\n enter the order if forward-(1) reverse-(0): ");
    scanf("%d",&ord);

    if(ord==1){
        for(j=2;j<=n;j++){
        head=add_node_at_end(head);
    }
    }

    if(ord==0){
        for(j=2;j<=n;j++){
        add_node_at_beg(&head);
    }
    ptr=head;
    }
    
    len=print_nodes(ptr);
    printf("\n\n The total no. of nodes is %d ",len);
    printf("\n Done, Thank You!\n\n ");
    return 0;

}