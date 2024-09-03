#include<stdio.h>
#include<stdlib.h>

int i=0;

struct node{
    struct node *prev;
    int data1;
    int data2;
    struct node *nxt;
};

struct node *create_node(void){
    i+=1;
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    printf("\n enter the data for the #%d node: ",i);
    scanf("%d",&(temp->data1));
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&(temp->data2));
    temp->nxt=NULL;
    return temp;
}

void add_at_end(struct node **tail){
    struct node *heady=*tail;
    struct node *ptr=create_node();

    ptr->prev=heady;
    heady->nxt=ptr;
    *tail=ptr;
}

void add_at_beg(struct node **head){
    struct node *heady=*head;
    struct node *ptr=create_node();
    ptr->nxt=heady;
    heady->prev=ptr;
    *head=ptr;
}

void add_at_pos(struct node **head,struct node **tail, int pos){

    if(pos==1){
        add_at_beg(&*head);
        return;
    }
    struct node *heady=*head;
    int count=1;
    while(count<pos-1)
    {
        heady=heady->nxt;
        count++;
    }
    if(heady->nxt==NULL){
        add_at_end(&*tail);
        return;
    }
    else{
        struct node *ptr=create_node();
        ptr->prev=heady;
        ptr->nxt=heady->nxt;
        heady->nxt->prev=ptr;
        heady->nxt=ptr;
        return;
    }
    
}

void print_list(struct node *ptr){
    if(ptr==NULL){
        printf("\n The list is already empty! ");
    }
    i=0;
    while(ptr){
        i+=1;
        printf("\n The Data of the #%d node is Data_1: %d, Data_2; %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->nxt;
    }
}

void delete_at_1st(struct node **head){
    if(*head==NULL){
        printf("\n The list is empty! ");
        return ;
    }
    struct node *heady=*head;
    heady=heady->nxt;
    heady->prev=NULL;
    free(*head);
    *head=heady;
}

void delete_at_last(struct node **tail){
    if(*tail==NULL){
        printf("\n The list is empty! ");
        return ;
    }
    struct node *temp=*tail;
    temp=temp->prev;
    temp->nxt=NULL;
    free(*tail);
    *tail=temp;
}

void delete_at_pos(struct node **head,struct node **tail,int pos){
    
    if(pos==1){
        delete_at_1st(&*head);
        return;
    }
    int count=1;
    struct node *heady=*head;
    while(count<pos){
        heady=heady->nxt;
        count++;
    }
    if(heady->nxt==NULL){
        delete_at_last(&*tail);
        return;
    }
    else{
        heady->prev->nxt=heady->nxt;
        heady->nxt->prev=heady->prev;
        free(heady);
        heady=NULL;
        return;
    }
}

void delete_list(struct node **head){
    if(*head==NULL){
        printf("\n\n The list is already empty! ");
        return;
    }
    struct node *heady=*head;
    if(heady->nxt==NULL){
        delete_at_1st(&*head);
        return ;
    }
    while(*head){
        heady=heady->nxt;
        free(*head);
        *head=heady;
    }
    return;
}

void reverse_list(struct node **head){
    if(*head==NULL){
        printf("\n\n The list is empty! ");
    }
    struct node *prev=NULL,*nxt=NULL,*heady=*head;
    while(heady){
        nxt=heady->nxt;
        heady->nxt=prev;
        prev=heady;
        heady=nxt;
    }
    *head=prev;
}

int main(){
    int n;
    int ord;
    char wr,wd;
    printf("\n enter the no. of nodes: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n No, nodes were created! ");
        printf("\n\n Done ,Thank You! ");
        return 0;
    }
    struct node *head=create_node(),*tail;
    tail=head;
    int j,pos;
    
    if(n!=1){
      printf("\n\n enter the order in which u want to create the list (1/-1): ");
      scanf("%d",&ord);
      if(ord==1){
        for(j=2;j<=n;j++){
        add_at_beg(&head);
        }
      }
      else if(ord==-1){
        for(j=2;j<=n;j++){
        add_at_end(&tail);
        }
      }
    }
    printf("\n The list is.....");
    print_list(head);

    printf("\n\n enter the position to insert a new node: ");
    scanf("%d",&pos);
    if(pos!=0){
       add_at_pos(&head,&tail,pos);
       printf("\n\n The list after adding a new node at %d position is.....",pos);
    }
    print_list(head);

    printf("\n\n The list after deletion of the first node is......");
    delete_at_1st(&head);
    print_list(head);

    printf("\n\n The list after deletion of the last node is......");
    delete_at_last(&tail);
    print_list(head);

    printf("\n\n enter the position to delete a node: ");
    scanf("%d",&pos);
    if(pos!=0){
       delete_at_pos(&head,&tail,pos);
       printf("\n\n The list after deletion of the node at %d position is.....",pos);
    }
    print_list(head);

    printf("\n\n Do you want to reverse the list(y/n)? ");
    scanf("%s",&wr);
    if(wr=='y' || wr=='Y'){
        reverse_list(&head);
        printf("\n The list after reversing is......");
        print_list(head);
    }

    printf("\n\n Do you want to delete the list(y/n)? ");
    scanf("%s",&wd);
    if(wd=='Y' || wd=='y'){
        delete_list(&head);
        if(head==NULL){
        printf("\n The list is deleted successfully! ");
        print_list(head);
        printf("\n Done, Thank You! ");
        return 0;}
    }
    printf("\n\n Done, Thank You! ");
    free(head);
    return 0;
}