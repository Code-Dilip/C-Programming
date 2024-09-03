#include<stdio.h>
#include<stdlib.h>
int i=1,j;

struct node{
    int data1;
    int data2;
    struct node *link;
};


void deletion(struct node **head){
    struct node *ptr;
    ptr=*head;
    if(*head==NULL){
        printf("\n The List is already empty! ");
    }   
    else{
        while(ptr!=NULL){
            ptr=ptr->link;
            free(*head);
            *head=ptr;
        }
        *head=NULL;
    }
}

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
int main(){
    int n,len,m;
    char del;
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
        ptr=add_node_at_end(ptr);
    }
    len=printing_nodes(head);
    printf("\n\n The total no. of nodes is %d.",len);
    
    printf("\n Do you want to delete entire list? (y/n): ");
    scanf("%s",&del);
    if(del==('y'|'Y')){
        head=ptr;
        deletion(&head);
    }
    
    if(head==NULL){
        printf("\n The singly linked list is deleted successfully! ");
    }
    free(head);
    printf("\n Done ,Thank You! \n\n");
    return 0;
}