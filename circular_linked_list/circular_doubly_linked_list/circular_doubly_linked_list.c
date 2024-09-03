#include<stdio.h>
#include<stdlib.h>

int i;

struct node{
    struct node *prev;
    int data1;
    int data2;
    struct node *nxt;
};

struct node *add_node(){
    i+=1;
    struct node *newp=malloc(sizeof(struct node));
    newp->prev=newp;
    printf("\n enter the first data for the #%d node: ",i);
    scanf("%d",&newp->data1);
    printf(" enter the second data for the #%d node: ",i);
    scanf("%d",&newp->data2);
    newp->nxt=newp;
    return newp;
}

void add_at_1st(struct node *tail){
    struct node *newp=add_node();
    newp->prev=tail;
    newp->nxt=tail->nxt;
    tail->nxt=newp;
    tail->prev=tail->prev->nxt;
}

void add_at_last(struct node **tail){
    struct node *newp=add_node(),*tptr=*tail;
    newp->prev=tptr;
    newp->nxt=tptr->nxt;
    tptr->nxt=newp;
    *tail=newp;
}

void add_at_pos(struct node **tail,int pos){
   if(pos==1){
    add_at_1st(*tail);
    return;
   }
   struct node *tptr=*tail,*head=tptr->nxt;
   int count=1;
   while(count<pos-1){
    head=head->nxt;
    count++;
   }
   if(head==*tail){
    add_at_last(&*tail);
    return;
   }
   struct node *newp=add_node();
   newp->nxt=head->nxt;
   newp->prev=head;
   head->nxt->prev=newp;
   head->nxt=newp;
}

void delete_1st_node(struct node *tail){
    struct node *head=tail->nxt;
    head->nxt->prev=tail;
    tail->nxt=head->nxt;
    free(head);
}

void delete_last_node(struct node **tail){
    struct node *tptr=*tail,*head=tptr->nxt;
    do{
        head=head->nxt;
    }while(head->nxt!=*tail);
    head->nxt=tptr->nxt;
    tptr->nxt->prev=head;
    free(*tail);
    *tail=head;
}

void delete_at_pos(struct node **tail,int pos){
    if(pos==1){
        delete_1st_node(*tail);
        return;
    }
    int count=1;
    struct node *tptr=*tail,*head=tptr->nxt;
    while (count<pos)
    {
        head=head->nxt;
        count++;
    }
    if(head==*tail){
        delete_last_node(&*tail);
        return;
    }
    head->prev->nxt=head->nxt;
    head->nxt->prev=head->prev;
    free(head);
}

void delete_list(struct node **tail){
    struct node *tptr=*tail,*curr=tptr->nxt;
    while(curr!=*tail){
        curr=curr->nxt;
        delete_1st_node(*tail);
    }
    delete_1st_node(*tail);
    *tail=NULL;
}

int search_ele(struct node *tail,int ele){
    i=0;
    struct node *head=tail->nxt;
    do{
        i+=1;
        if(head->data1==ele || head->data2==ele){
            return i;
        }
        else{
            head=head->nxt;
        }
    }while(head!=tail->nxt);
    return -1;
}

void reverse_list(struct node **tail){
    struct node *tptr=*tail,*head=tptr->nxt,*prev=NULL,*curr=head,*nxt_node=curr->nxt;
    while(curr!=*tail){
        prev=curr;
        curr=nxt_node;
        nxt_node=curr->nxt;
        curr->nxt=prev;
    }
    nxt_node->nxt=*tail;
    curr=head;
    head=*tail;
    *tail=curr;
}

void print_list(struct node *tail){
    if(tail==NULL){
        printf("\n The list is empty! ");
    }
    i=0;
    struct node *head=tail->nxt;
    do{
        i+=1;
        printf("\n The data of the #%d node is Data_1: %d, Data_2: %d ",i,head->data1,head->data2);
        head=head->nxt;
    }while(head!=tail->nxt);
}


int main(){
    int n;
    printf("\n enter the no. of nodes: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n No nodes were created! ");
        exit(0);
    }
    struct node *tail=add_node();
    int j,pos,ord,ele;
    char wd,ws='y';
    printf("\n enter the order of the linked list: ");
    scanf("%d",&ord);
    if(ord==1){
        for(j=2;j<=n;j++){
            add_at_1st(tail);
        }
    }
    if(ord==-1){
        for(j=2;j<=n;j++){
            add_at_last(&tail);
        }
    }
    printf("\n\n The linked list formed is......");
    print_list(tail);

    printf("\n\n enter the position to insert a new node: ");
    scanf("%d",&pos);
    if(pos!=0){
        add_at_pos(&tail,pos);
        printf("\n\n The list after inserting a node at #%d position is.........",pos);
        print_list(tail);
    }

    printf("\n\n The list after deleting the first node of the list is......");
    delete_1st_node(tail);
    print_list(tail);

    printf("\n\n The list after deleting the last node of the list is........");
    delete_last_node(&tail);
    print_list(tail);

    printf("\n\n enter the position to delete the node from: ");
    scanf("%d",&pos);
    if(pos!=0){
        delete_at_pos(&tail,pos);
        printf("\n The list after the deletion of a node at #%d position is.......",pos);
        print_list(tail);
    }

    printf("\n");
    while(ws=='y' || ws=='Y'){
        printf("\n enter the search element to search it in the list: ");
        scanf("%d",&ele);
        pos=search_ele(tail,ele);
        if(pos!=-1){
           printf(" The search element %d is found in #%d node of the list! ",ele,pos);
        }
        else{
            printf(" The search element %d is not found in the list! ",ele);
        }
        printf("\n\n Do you want to search more elements(y/n)? ");
        scanf("%s",&ws);
    }

    printf("\n The list after reversing is.......");
    reverse_list(&tail);
    print_list(tail);

    printf("\n\n Do you want to delete the list(y/n)?: ");
    scanf("%s",&wd);
    if(wd=='y' || wd=='Y'){
        delete_list(&tail);
        if(tail==NULL){
            printf(" The list is deleted successfully! ");
        }
    }
    return 0;
}