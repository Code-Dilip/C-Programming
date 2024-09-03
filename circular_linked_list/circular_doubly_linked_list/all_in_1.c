#include<stdio.h>
#include<stdlib.h>

int i=0;

struct node{
    struct node *prev;
    int data1;
    int data2;
    struct node *nxt;
};

struct node *add_node(void){
    i+=1;
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=temp;
    printf("\n enter the first data of the #%d node: ",i);
    scanf("%d",&temp->data1);
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&temp->data2);
    temp->nxt=temp;
}

void add_at_1st(struct node *tail){
    struct node *newp=add_node();
    newp->nxt=tail->nxt;
    tail->nxt=newp;
    newp->prev=tail;
}

void add_at_end(struct node **tail){
    struct node *newp=add_node(),*tp=*tail;
    newp->prev=tp;
    newp->nxt=tp->nxt;
    tp->nxt=newp;
    *tail=newp;
}

void create_list(struct node **tail){
    int n;
    printf("\n enter the no. of nodes: ");
    scanf("%d",&n);
    if(n==0){
        printf("\n No nodes were created! ");
        exit(0);
    }
    *tail=add_node();
    int j,ord;
    printf("\n enter the order of the linked list(1/-1): ");
    scanf("%d",&ord);
    if(ord==1){
        for(j=2;j<=n;j++){
        add_at_1st(*tail);
        }
    }
    else if(ord==-1){
        for(j=2;j<=n;j++){
        add_at_end(&*tail);
        }
    }
}

void insert_at_pos(struct node **tail,int pos){
    if(pos==1){
        add_at_1st(*tail);
        return ;
    }
    int count=1;
    struct node *head=*tail;
    head=head->nxt;
    while(count<pos-1){
        head=head->nxt;
        count++;
    }
    if(head==*tail){
        add_at_end(&*tail);
        return;
    }
    else{
        struct node *newp=add_node();
        newp->prev=head;
        newp->nxt=head->nxt;
        head->nxt->prev=newp;
        head->nxt=newp;
        return;
    }
}

void delete_at_1st(struct node *tail){
    if(tail==NULL){
        return;
    }
    struct node *head=tail->nxt;
    head->nxt->prev=tail->nxt;
    tail->nxt=head->nxt;
    free(head);
    head=NULL;
}

void delete_at_end(struct node **tail){
    if(*tail==NULL){
        return;
    }
    struct node *tp=*tail;
    tp->prev->nxt=tp->nxt;
    tp->nxt->prev=tp->prev;
    *tail=tp->prev;
    free(tp);
    tp=NULL;
}

void delete_at_pos(struct node **tail,int pos){
    if(pos==1){
        delete_at_1st(*tail);
        return;
    }
    int count=1;
    struct node *head=*tail;
    head=head->nxt;
    while (count<pos)
    {
        head=head->nxt;
        count++;
    }
    if(head==*tail){
        delete_at_end(&*tail);
        return;
    }
    else{
        head->prev->nxt=head->nxt;
        head->nxt->prev=head->prev;
        free(head);
        head=NULL;
        return;
    }
}

void delete_list(struct node **tail){
    struct node *tp=*tail,*head=tp->nxt,*prev;
    do{
        prev=head;
        head=head->nxt;
        free(prev);
    }while (head!=tp->nxt);
    *tail=NULL;
}


int  search_ele(struct node *tail,int ele){
    struct node *head=tail->nxt;
    int index=1;
    do{
        if(head->data1==ele ||head->data2==ele){
            return index;
        }
        head=head->nxt;
        index++;
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
        return;
    }
    i=0;
    struct node *head=tail->nxt;
    do{
        i+=1;
        printf("\n The Data of the #%d node is.......Data_1: %d, Data_2: %d ",i,head->data1,head->data2);
        head=head->nxt;
    }while(head!=tail->nxt);
}


int main(){
    struct node *tail;
    create_list(&tail);
    printf("\n\n The list is........");
    print_list(tail);

    int pos,ele;
    char wd,wr,ws='y';
    printf("\n\n enter the position to insert a new node: ");
    scanf("%d",&pos);
    if(pos!=0){
        insert_at_pos(&tail,pos);
        printf("\n The list after insertion of new node at #%d position is........",pos);
        print_list(tail);
    }

    printf("\n\n The list after deleting the first node is........");
    delete_at_1st(tail);
    print_list(tail);

    printf("\n\n The list after deleting the last node is.........");
    delete_at_end(&tail);
    print_list(tail);

    printf("\n\n enter the position to delete a node: ");
    scanf("%d",&pos);
    if(pos!=0){
        delete_at_pos(&tail,pos);
        printf("\n The list after deleting a node at #%d position is......",pos);
        print_list(tail);
    }

    while(ws=='y' || ws=='Y'){
        printf("\n enter the search element: ");
        scanf("%d",&ele);
        pos=search_ele(tail,ele);
        if(pos==-1){
            printf(" The search element %d is not present in the list! ",ele);
        }
        else{
            printf(" The search element %d is present in #%d node of the list! ",ele,pos);
        }
        printf("\n Do you want to search more elements(y/n)? ");
        scanf("%s",&ws);
    }

    printf("\n The list after reversing is......");
    reverse_list(&tail);
    print_list(tail);

    printf("\n\n Do you want to delete the list(y/n)? ");
    scanf("%s",&wd);
    if(wd=='y' || wd=='Y'){
        delete_list(&tail);
        if(tail==NULL){
            printf("\n The list is deleted successfully! ");
        }
        print_list(tail);
    }

    printf("\n\n Done, Thank You! \n\n");
    free(tail);
    return 0;
}