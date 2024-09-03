#include<stdio.h>
#include<stdlib.h>

int i;

struct node{
    int data1;
    int data2;
    struct node *nxt;
};

struct node *add_node(){
    i+=1;
    struct node *ptr=malloc(sizeof(struct node));
    printf("\n enter the first data in the #%d node: ",i);
    scanf("%d",&ptr->data1);
    printf(" enter the second data in the #%d node: ",i);
    scanf("%d",&ptr->data2);
    ptr->nxt=ptr;
}

void add_node_at_1st(struct node *tail){
    struct node *newp=add_node();
    newp->nxt=tail->nxt;
    tail->nxt=newp;
}

void add_at_end(struct node **tail){
    struct node *newp=add_node(),*tptr=*tail;
    newp->nxt=tptr->nxt;
    tptr->nxt=newp;
    *tail=newp;
}

void add_at_pos(struct node **tail,int pos){
    if(pos==1){
        add_node_at_1st(*tail);
        return;
    }
    int count=1;
    struct node *tptr=*tail,*head=tptr->nxt;
    while(count<pos-1){
        head=head->nxt;
        count++;
    }
    if(head==tptr){
        add_at_end(&*tail);
        return;
    }
    struct node *newp=add_node();
    newp->nxt=head->nxt;
    head->nxt=newp;
}

void delete_at_1st(struct node *tail){
    struct node *head=tail->nxt;
    tail->nxt=head->nxt;
    free(head);
}

void delete_at_last(struct node **tail){
    struct node *tptr=*tail,*head=tptr->nxt;
    do{
        head=head->nxt;
    }while(head->nxt!=*tail);
    
    head->nxt=tptr->nxt;
    free(*tail);
    *tail=head;
}

void delete_at_pos(struct node **tail,int pos){
    if(pos==1){
        delete_at_1st(*tail);
        return;
    }
    struct node *temp1=*tail,*temp2=temp1->nxt;
    int count=1;
    while(count<pos){
        temp1=temp2;
        temp2=temp2->nxt;
        count++;
    }
    if(temp2==*tail){
        delete_at_last(&*tail);
        return;
    }
    temp1->nxt=temp2->nxt;
    free(temp2);
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
    while (curr!=*tail)
    {
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

void delete_list(struct node **tail){
    struct node *tptr=*tail,*curr=tptr->nxt;
    while(curr!=*tail){
        curr=curr->nxt;
        delete_at_1st(*tail);
    }
    delete_at_1st(*tail);
    *tail=NULL;
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
        printf("\n The data of the #%d node is...... Data_1: %d, Data_2: %d ",i,head->data1,head->data2);
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
    int j,ord,pos,ele;
    char wd,ws='y';
    printf("\n enter the order of the linked list: ");
    scanf("%d",&ord);
    if(ord==1){
        for(j=2;j<=n;j++){
        add_node_at_1st(tail);
    }
    }
    else if(ord==-1){
        for(j=2;j<=n;j++){
            add_at_end(&tail);
        }
    }
    printf("\n The list formed is......");
    print_list(tail);

    printf("\n\n enter the position to insert a node in the list: ");
    scanf("%d",&pos);
    if(pos!=0){
        add_at_pos(&tail,pos);
        printf("\n\n The list after inserting a node at #%d position is......",pos);
        print_list(tail);
    }

    printf("\n\n The list after deleting the first node is......");
    delete_at_1st(tail);
    print_list(tail);

    printf("\n\n The list after deleting the last node is......");
    delete_at_last(&tail);
    print_list(tail);

    printf("\n\n Enter the position to delete a node: ");
    scanf("%d",&pos);
    if(pos!=0){
        delete_at_pos(&tail,pos);
        printf("\n The list after deleting the node from #%d position is.......",pos);
        print_list(tail);
    }

    printf("\n");
    while(ws=='y' || ws=='Y'){
        printf("\n enter the search element to search it in the list: ");
        scanf("%d",&ele);
        pos=search_ele(tail,ele);
        if(pos!=-1){
            printf(" The search element %d is found in #%d node of the list ",ele,pos);
        }
        else{
            printf(" The search element %d is not found in the list ",ele);
        }
        printf("\n\n Do you want to search more elements(y/n)? ");
        scanf("%s",&ws);
    }

    printf("\n\n The list after reversing is......");
    reverse_list(&tail);
    print_list(tail);

    printf("\n\n Do you want to delete the list(y/n)? ");
    scanf("%s",&wd);
    if(wd=='y' || wd=='Y'){
        delete_list(&tail);
        if(tail==NULL){
            printf(" The list is successfully deleted! ");
        }
    }
    free(tail);
    return 0;
}