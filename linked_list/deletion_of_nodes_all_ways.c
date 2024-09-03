#include<stdio.h>
#include<stdlib.h>

int i=1;

struct node {
    int data1;
    int data2;
    struct node *link;
};

void del_list(struct node **head){
    if(*head==NULL){
        printf("\n The list is empty! ");
    }
    else{
        struct node *ptr=*head;
        while(ptr!=NULL){
            ptr=ptr->link;
            free(*head);
            *head=ptr;
        }
    }
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

int print_list(struct node *ptr){
    i=0;
    while(ptr!=NULL){
        i+=1;
        printf("\n The data of the #%d node is..... Data 1: %d ,Data 2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->link;
    }
    return i;
}

int main(){
    int n,j,len,pos;
    char del;
    printf("\n enter the lenght of the list: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n No nodes were created! ");
        return 0;
    }
    struct node *head,*ptr;
    head=malloc(sizeof(struct node));
    ptr=head;
    printf("\n enter the first data of the #%d node: ",i);
    scanf("%d",&(head->data1));
    printf(" enter the second data of the #%d node: ",i);
    scanf("%d",&(head->data2));
    head->link=NULL;

    for(j=2;j<=n;j++){
        head=add_at_end(head);
    }
    len=print_list(ptr);
    printf("\n The total no. of nodes is %d ",len);

    printf("\n\n Do you want to delete the list?(y/n): ");
    scanf("%s",&del);
    if(del=='y' || del=='Y'){
        del_list(&ptr);
    }
    if(ptr==NULL){
        printf("\n The list is deleted successfully! ");
    }
    len=print_list(ptr);
    printf("\n the total no. of node is %d ",len);
    free(head);
    printf("\n\n Done, Thank You! ");
    return 0;
}