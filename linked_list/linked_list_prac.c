#include<stdio.h>
#include<stdlib.h>

struct node{
    int data1;
    int data2;
    struct node *link;
};

struct node *create_linked_list(int n){

    if(n==0){
        printf("\n No node is created! \n");
        return 0;
    }
    int i=1;
    struct node *ptr=NULL,*head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    printf("\n enter the first data in #%d node: ",i);
    scanf("%d",&(head->data1));
    printf(" enter the second data in #%d node: ",i);
    scanf("%d",&(head->data2));
    for(i=2;i<=n;i++){
        head->link=(struct node *)malloc(sizeof(struct node));
        head=head->link;
        printf("\n enter the first data in #%d node: ",i);
        scanf("%d",&(head->data1));
        printf(" enter the second data in #%d node: ",i);
        scanf("%d",&(head->data2));
    }
    head->link=NULL;
    head=head->link;
    free(head);
    return ptr;
}

int printing_nodes(struct node *ptr){
    int i=0;
    while(ptr!=NULL){
        i+=1;
        printf("\n The data of #%d node is...... Data_1: %d, Data_2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->link;
    }
    return i;
}

int main(){
    int n,m;
    struct node *ptr;
    printf("\n enter the no. of nodes: ");
    scanf("%d",&n);
    ptr=create_linked_list(n);
    m=printing_nodes(ptr);
    printf("\n\n The total no. of nodes is %d ",m);
    printf("\n Done, Thank You! \n\n");
    return 0;
}