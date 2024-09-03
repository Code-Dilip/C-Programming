#include<stdio.h>
#include<stdlib.h>


int i=0;

struct node {
    int data1;
    int data2;
    struct node *nxt;
};

struct node *add_node(void){
    i+=1;
    struct node *temp=malloc(sizeof(struct node));
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&temp->data1);
    printf(" enter the second data of the #%d node: ",i);
    scanf("%d",&temp->data2);
    temp->nxt=temp;
    return temp;
}

void add_at_beg(struct node *tail){
    struct node *newp=add_node(),*tp=tail;
    newp->nxt=tp->nxt;
    tp->nxt=newp;
}


void add_at_end(struct node **tail){
    struct node *tp=*tail, *newp=add_node();
    newp->nxt=tp->nxt;
    tp->nxt=newp;
    *tail=newp;
}

void print_list(struct node *tail){
    if(tail==NULL){
        printf("\n The list is empty! ");
        return;
    }
    i=0;
    struct node *tp=tail,*ptr=tp->nxt;
    do{
        i+=1;
        printf("\n The Data of the #%d node is......Data_1: %d, Data_2: %d ",i,ptr->data1,ptr->data2);
        ptr=ptr->nxt;
    }
    while(ptr!=tp->nxt);
    return;
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
    int ord,j;
    
    printf("\n enter the order of the list(1/-1): ");
    scanf("%d",&ord);
    if(ord==1){
        for(j=2;j<=n;j++){
            add_at_beg(*tail);
        }
    }
    else if(ord==-1){
        for(j=2;j<=n;j++){
            add_at_end(&*tail);
        }
    }
}

void insert_node(struct node **tail,int pos){
    if(pos==1){
        add_at_beg(*tail);
        return;
    }
    int count=1;
    struct node *tp=*tail,*ptr=tp->nxt;
    while (count<pos-1)
    {
        ptr=ptr->nxt;
        count++;
    }
    if(ptr==*tail){
        add_at_end(&*tail);
        return;
    }
    else{
        struct node *newp=add_node();
        newp->nxt=ptr->nxt;
        ptr->nxt=newp;
        return ;
    }
    
}

void delete_at_1st(struct node *tail){
    struct node *tp=tail,*ptr=tp->nxt;
    tp->nxt=ptr->nxt;
    free(ptr);
    ptr=NULL;
}

void delete_at_last(struct node **tail){
    struct node *tp=*tail,*ptr=tp->nxt;
    while (ptr->nxt!=*tail)
    {
        ptr=ptr->nxt;
    }
    ptr->nxt=tp->nxt;
    free(*tail);
    *tail=ptr;
}

void delete_at_pos(struct node **tail,int pos){
    if(pos==1){
        delete_at_1st(*tail);
        return;
    }
    int count=1;
    struct node *tp=*tail,*prev=tp->nxt,*curr=tp->nxt;
    while(count<pos){
        prev=curr;
        curr=curr->nxt;
        count++;
    }
    if(curr==*tail){
        delete_at_last(&*tail);
        return;
    }
    else{
        prev->nxt=curr->nxt;
        free(curr);
        curr=NULL;
        return;
    }
}


void delete_list(struct node **tail){
    struct node *tp=*tail,*curr=tp->nxt;
    while(curr!=*tail){
       curr=curr->nxt;
       delete_at_1st(*tail);
    }
    *tail=NULL;
}

void reverse_list(struct node **tail){
    struct node *tptr=*tail,*head=tptr->nxt,*prev=NULL,*curr=head,*nxt_node=curr->nxt;
    while (curr!=*tail)
    {
        prev=curr;
        curr=nxt_node;
        nxt_node=curr->nxt;
        curr->nxt=prev;
    }
    nxt_node=*tail;
    curr=head;
    head=*tail;
    *tail=curr;
}

int search_ele(struct node *tail,int ele){
    int index=1;
    struct node *head=tail->nxt;
    do{
        if(head->data1==ele || head->data2==ele){
            return index;
        }
        head=head->nxt;
        index++;
    }while (head!=tail->nxt);
    return -1;
}


int main(){
    
    struct node *tail;
    create_list(&tail);
    print_list(tail);

    int pos,ele;
    char wd,wr,sm='y';
    printf("\n\n enter the position to insert a new node: ");
    scanf("%d",&pos);
    if(pos!=0){
        insert_node(&tail,pos);
        printf("\n The list after inserting the new node at #%d position is.......",pos);
        print_list(tail);
    }

    printf("\n\n The list after deleting the first node is......");
    delete_at_1st(tail);
    print_list(tail);

    printf("\n\n The list after deleting the last node is.......");
    delete_at_last(&tail);
    print_list(tail);

    printf("\n\n enter the position to delete the node: ");
    scanf("%d",&pos);
    if(pos!=0){
        delete_at_pos(&tail,pos);
        printf("\n\n The list after deleting the node at #%d position is......",pos);
        print_list(tail);
    }

    while(sm=='y' || sm=='Y'){
    printf("\n enter the search element: ");
    scanf("%d",&ele);
    pos=search_ele(tail,ele);
    if(pos==-1){
        printf(" The search element %d is not present in the list ",ele);
    }
    else{
        printf(" The search element %d is present in #%d node ",ele,pos);
    }
    printf("\n Do you want to search more elements(y/n)? ");
    scanf("%s",&sm);
    }

    printf("\n\n The list after reversing is......");
    reverse_list(&tail);
    print_list(tail);

    printf("\n\n Do you want to delete the list?(y/n): ");
    scanf("%s",&wd);
    if(wd=='y' || wd=='Y'){
        delete_list(&tail);
        if(tail==NULL){
            printf("\n The list is deleted successfully! ");
            print_list(tail);
        }
    }

    printf("\n\n Done, Thank You! \n\n");
    free(tail);
    return 0;
}