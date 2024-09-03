#include<stdio.h>
#include<stdlib.h>

struct node{
    int data1;
    int data2;
    struct node *link;
};

struct node *create_list(int n){
    if(n==0){
        printf("\n No node is created ! \n\n");
        exit(1);
    }
    struct node *ptr=NULL,*head=NULL;
    int i=1;
    head=(struct node *)malloc(sizeof(struct node));
    printf(" enter the first data of #%d node: ",i);
    scanf("%d",&(head->data1));
    printf(" enter the second data of #%d node: ",i);
    scanf("%d",&(head->data2));
    ptr=head;
    for(i=2;i<=n;i++){
        head->link=(struct node *)malloc(sizeof(struct node));
        head=head->link;
        printf("\n");
        printf(" enter the first data of #%d node: ",i);
        scanf("%d",&(head->data1));
        printf(" enter the second data of #%d node: ",i);
        scanf("%d",&(head->data2));
    }
    head->link=NULL;
    head=head->link;
    free(head);
    return ptr;
}

int print_linked_list(struct node *head){
    int i=0;
    while(head!=NULL){
        i+=1;
        printf("\n Data of #%d node is..... Data_1: %d, Data_2: %d ",i,head->data1,head->data2);
        head=head->link;
    }
    free(head);
    return i;
    
}

int main(){
    struct node *head;
    int n,m=0;
    printf("\n enter the length of the linked list: ");
    scanf("%d",&n);
    printf("\n\n");
    head=create_list(n);
    m=print_linked_list(head);
    printf("\n\n The total no. of nodes is %d .",m);
    printf("\n Done ,Thank You! \n\n");
    return 0;
}