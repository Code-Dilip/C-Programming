#include<stdio.h>
#include<stdlib.h>

int i=1;

struct node {
    int data1;
    int data2;
    struct node *link;
};

struct node *delete_list(struct node *head){
    if(head==NULL){
        printf("\n The list is empty! ");
    }
    else if(head->link=NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *ptr=head;
        while(head!=NULL){
            free(head);
            ptr=ptr->link;
            head=ptr;
        }
    }
}

void del_1st(struct node **head){
    if(*head==NULL){
        printf("\n The list is empty! ");
    }
    else{
    struct node *ptr=*head;
    *head=ptr->link;
    free(ptr);
    ptr=NULL;
    }
}

void del_last(struct node *head){
    if(head==NULL){
        printf("\n The list is empty! ");
    }
    else{
        struct node *ptr=head;
        while(ptr->link->link!=NULL){
            ptr=ptr->link;
        }
        free(ptr->link);
        ptr->link=NULL;
    }
}

void del_at_pos(struct node **head,int pos){
    if(*head==NULL){
        printf("\n The list is empty! ");
    }
    else if(pos==1){
        struct node *ptr=*head;
        *head=ptr->link;
        free(ptr);
        ptr=NULL;
    }
    else{
        struct node *prev=*head,*current=*head;
        int count =1;
        while(count<pos){
            prev=current;
            current=current->link;
            count++;
            }
        prev->link=current->link;
        free(current);
        current=NULL;
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

    /*printf("\n enter the position from where u want to delete the node: ");
    scanf("%d",&pos);

    printf("\n\n The list after deleting the particular node is.....");
    del_at_pos(&ptr,pos);
    len=print_list(ptr); */
    ptr=delete_list(ptr);
    if(ptr==NULL){
        printf("\n The list is deleted successfully! ");
    }
    printf("\n The total no. of nodes is %d ",len);
    printf("\n Done , Thank You! ");
    free(head);
    return 0;
}