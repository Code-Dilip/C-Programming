#include<stdio.h>
#include<stdlib.h>

int i=1;

struct node{
    int data1;
    int data2;
    struct node *link;
};

void add_at_beg(struct node **head){
    i+=1;
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    printf("\n enter the first data of the #%d node: ",i);
    scanf("%d",&(ptr->data1));
    printf(" enter the second data of the #%d node: ",i);
    scanf("%d",&(ptr->data2));
    ptr->link=*head;
    *head=ptr;
}

struct node *add_at_end(struct node *head){
    i+=1;
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    printf("\n enter the first data of the #%d node: ",i);
    scanf("%d",&(ptr->data1));
    printf(" enter the second data of the #%d node: ",i);
    scanf("%d",&(ptr->data2));
    ptr->link=NULL;
    head->link=ptr;
    head=ptr;
    return head;
}

void insert_node(struct node *head,int pos){
    int count=1;
    i+=1;
    struct node *ptr=malloc(sizeof(struct node));
    printf("\n enter the first data of the #%d node: ",i);
    scanf("%d",&(ptr->data1));
    printf(" enter the second data of the #%d node: ",i);
    scanf("%d",&(ptr->data2));
    while(count<pos-1){
        head=head->link;
        count++;
    }
    ptr->link=head->link;
    head->link=ptr;
}
int print_list(struct node *ptr){
    i=0;
    while(ptr!=NULL){
        i+=1;
        printf("\n The data of the #%d node is.....Data1: %d , Data2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->link;
    }
    return i;
}

int main(){
    int n,j,ord,len,pos,m;
    char ord2;
    printf("\n enter the no. of nodes: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n No nodes were created! ");
        return 0;
    }
    struct node *ptr,*head=malloc(sizeof(struct node));
    ptr=head;

    printf("\n enter the first data of the #%d node: ",i);
    scanf("%d",&(head->data1));
    printf(" enter the second data of the #%d node: ",i);
    scanf("%d",&(head->data2));
    head->link=NULL;

    printf("\n enter the order of the list( 1,-1): ");
    scanf("%d",&ord);
    
    if(ord==-1){
        for(j=2;j<=n;j++){
            head=add_at_end(head);
        }
    }
    else if(ord==1){
        for(j=2;j<=n;j++){
            add_at_beg(&head);
        }
        ptr=head;
    }
    len=print_list(ptr);
    printf("\n The total no.of nodes is %d ",len);

    printf("\n Do you want to insert more elements: ");
    scanf("%s",&ord2);
    if(ord2=='y' || ord2=='Y'){
        printf("\n enter the no. of nodes that you want to insert: ");
        scanf("%d",&m);
        for(j=1;j<m;j++){
            printf("\n enter the position of the #%d node to insert: ",j);
            scanf("%d",&pos);
            insert_node(head,pos);
        }
        len=print_list(ptr);
        printf("\n The total no. of nodes is %d ",len);
    }
    
    printf("\n Done ,Thank You! ");
    return 0;
}