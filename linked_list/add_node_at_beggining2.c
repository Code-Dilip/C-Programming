#include<stdio.h>
#include<stdlib.h>

int i=1;

struct node{
    int data1;
    int data2;
    struct node *link;
};

void add_node_at_begg(struct node **head){
    i+=1;
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("\n enter the first data in #%d node: ",i);
    scanf("%d",&(ptr->data1));
    printf(" enter the secoind data in #%d node: ",i);
    scanf("%d",&(ptr->data2));
    ptr->link=*head;
    *head=ptr;
    
}

int print_nodes(struct node *head){
    i=0;
    while(head!=NULL){
        i+=1;
        printf("\n The data of #%d node is....... Data_1: %d, Data_2: %d ",i,head->data1,head->data2);
        head=head->link;
    }
    free(head);
    return i;

}

int main(){
    int len,m,j;
    struct node *head;
    printf("\n enter the lenght of the linked list: ");
    scanf("%d",&m);
    if(m==0){
        printf("\n No nodes were created ! ");
        printf("\n Done, Thank You! \n\n");
        return(0);
    }
    head=(struct node *)malloc(sizeof(struct node));
    printf("\n enter the first data in #%d node: ",i);
    scanf("%d",&(head->data1));
    printf(" enter the secoind data in #%d node: ",i);
    scanf("%d",&(head->data2));
    head->link=NULL;

    for(j=2;j<=m;j++){
    add_node_at_begg(&head);
    }

    len=print_nodes(head);
    printf("\n The total no. of nodes is %d ",len);
    printf("\n\n Done, Thank You! \n\n");
    free(head);
    return 0;

}