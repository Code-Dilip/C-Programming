#include<stdio.h>
#include<stdlib.h>
int i=1;

struct node{
    int data1;
    int data2;
    struct node *link;
};

void insertion_of_node(struct node *ptr,int pos){
    i+=1;
    int count=1;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&(temp->data1));
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&(temp->data2));
    temp->link=NULL;
    
    while(count<pos-1){
        ptr=ptr->link;
        count++;
    }
    temp->link=ptr->link;
    ptr->link=temp;
}

void add_at_beg(struct node **head){
    i+=1;
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&(ptr->data1));
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&(ptr->data2));
    ptr->link=*head;
    *head=ptr;
}

struct node *add_at_end(struct node *head){
    i+=1;
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&(ptr->data1));
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&(ptr->data2));
    ptr->link=NULL;
    head->link=ptr;
    head=ptr;
    return head;
}

int print_nodes(struct node *ptr){
    i=0;
    while(ptr!=NULL){
        i+=1;
        printf("\n The Data of the #%d node is Data_1: %d, Data_2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->link;
    }
    return i;
}

int main(){
    int n,j,len,ord,pos,m,cn;
    printf("\n enter the lenght of the linked list: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n\n No nodes were created! ");
        printf("\n Done, Thank You! \n\n");
    }
    struct node *head,*ptr;
    head=(struct node *)malloc(sizeof(struct node));
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&(head->data1));
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&(head->data2));
    head->link=NULL;
    ptr=head;
    
    printf("\n enter the order of the linked list (1/-1): ");
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
    
    len=print_nodes(ptr);
    printf("\n The total number of nodes is %d ",len);

    printf("\n\n Do you want to enter more elements?(0/1): ");
    scanf("%d",&cn);
    if(cn==1){
       printf("\n enter the no. of nodes to insert: ");
       scanf("%d",&m);
       for(j=1;j<=m;j++){
       printf("\n enter the position to insert the #%d new node: ",j);
       scanf("%d",&pos);
       insertion_of_node(ptr,pos);
       }
    }
    else{
        printf("\n\n Done, Thank You! \n\n");
        free(head);
        return 0;
    }
    len=print_nodes(ptr);
    printf("\n The total number of nodes is %d ",len);

    printf("\n\n Done, Thank You! \n\n");
    free(head);
    return 0;
    
}
