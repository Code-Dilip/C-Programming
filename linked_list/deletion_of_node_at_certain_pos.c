#include<stdio.h>
#include<stdlib.h>
int i=1;

struct node{
    int data1;
    int data2;
    struct node *link;
};


struct node *add_node_at_end(struct node *ptr){
    i+=1;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&(temp->data1));
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&(temp->data2));
    temp->link=NULL;
    ptr->link=temp;
    ptr=ptr->link;
    return ptr;
    
}

int printing_nodes(struct node *ptr){
    int i=0;
    while(ptr!=NULL){
        i+=1;
        printf("\n The data of #%d node is..... Data_1: %d , Data_2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->link;
    }
    return i;
}

void deletion(struct node **head,int pos){
    int count=1;
    struct node *ptr,*ptr2;
    ptr=*head;
    ptr2=*head;
    if(pos==1){
        *head=ptr->link;
        free(ptr);
        ptr=NULL;
    }
    else if(*head==NULL){
        printf("\n There's only one node ");
    }
    else{
        while(count<pos){
            ptr2=ptr;
            ptr=ptr->link;
            count++;
        }
        ptr2->link=ptr->link;
        free(ptr);
        ptr=NULL;
    }
}

int main(){
    int n,len,m,j,pos;
    printf("\n enter the lenght of the linked list: ");
    scanf("%d",&m);
    if(m==0){
        printf(" No nodes were created ! ");
        printf("\n Done ,Thank You! \n\n");
        exit(1);
    }
    struct node *head,*ptr;
    head=(struct node *)malloc(sizeof(struct node));
    ptr=head;
    printf("\n enter the first data in the #%d node: ",1);
    scanf("%d",&(head->data1));
    printf(" enter the second data in the #%d node: ",1);
    scanf("%d",&(head->data2));
    for(j=2;j<=m;j++){
        head=add_node_at_end(head);
    }
    len=printing_nodes(ptr);
    printf("\n\n The total no. of nodes is %d.",len);

    printf("\n enter a position from where u want to delete a node: ");
    scanf("%d",&pos);
    printf("\n The singly linked list after deleting a node at #%d position is....",pos);
    deletion(&ptr,pos);
    len=printing_nodes(ptr);
    printf("\n\n The total no. of nodes is %d.",len);
    printf("\n Done ,Thank You! \n\n");
    return 0;
}