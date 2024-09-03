#include<stdio.h>
#include<stdlib.h>

int i=0;

struct node {
    int data;
    struct node *nxt;
};

struct node *add_node(){
    struct node *newp=malloc(sizeof(struct node));
    return newp;
}

void insert(struct node **head,int n){
    struct node *newp=add_node();
    newp->data=n;
    newp->nxt=NULL;
    if(*head==NULL){
        *head=newp;
        return;
    }
    struct node *heady=*head;
    while(heady->nxt){
        heady=heady->nxt;
    }
    heady->nxt=newp;
}

void reverse_list(struct node **head){
    struct node *prev=NULL,*curr=*head,*nxt_node=NULL;
    while(curr){
        nxt_node=curr->nxt;
        curr->nxt=prev;
        prev=curr;
        curr=nxt_node;
    }
    *head=prev;
}

void print_list(struct node *ptr){
    while(ptr->nxt){
        printf(" %d ->",ptr->data);
        ptr=ptr->nxt;
    }
    printf(" %d ",ptr->data);
}

void back_to_num(struct node *ptr){
    int rem=0,result=0;
    while(ptr){
        rem=ptr->data;
        result=result*10+rem;
        ptr=ptr->nxt;
    }
    printf("%d",result);
}

void add(struct node *head1,struct node *head2){
    int carr=0,sum=0;
    struct node *ptr1=head1,*ptr2=head2,*head3=NULL;
    while(ptr1 || ptr2){
        sum=0;
        sum+=carr;
        if(ptr1){
            sum+=ptr1->data;
        }
        if(ptr2){
            sum+=ptr2->data;
        }
        carr=sum/10;
        sum=sum%10;
        insert(&head3,sum);
        if(ptr1){
            ptr1=ptr1->nxt;
        }
        if(ptr2){
            ptr2=ptr2->nxt;
        }
    }

    reverse_list(&head1);
    reverse_list(&head2);
    reverse_list(&head3);
    printf("\n\n The list one: ");
    print_list(head1);
    printf("\n The list two: ");
    print_list(head2);
    printf("\n The list three: ");
    print_list(head3);

    printf("\n\n  ");
    back_to_num(head1);
    printf(" + ");
    back_to_num(head2);
    printf(" = ");
    back_to_num(head3);
}


int main(){
    int num1,num2,n1,n2,rem;
    printf("\n\n enter the first number: ");
    scanf("%d",&num1);
    printf("\n enter the second number: ");
    scanf("%d",&num2);
    if(!num1 && !num2){
        printf("\n 0+0=0 ");
        return 0;
    }
    else if(!num1){
        printf("\n %d+%d=%d ",num1,num2,num2);
        return 0;
    }
    else if(!num2){
        printf("\n %d+%d=%d ",num1,num2,num1);
        return 0;
    }

    n1=num1;
    n2=num2;
    struct node *head1=NULL,*head2=NULL;
    while(n1){
        rem=n1%10;
        insert(&head1,rem);
        n1=n1/10;
    }
    while(n2){
        rem=n2%10;
        insert(&head2,rem);
        n2=n2/10;
    }

    printf("\n The reversed list representation of the number %d: ",num1);
    print_list(head1);
    printf("\n The reversed list representation of the number %d: ",num2);
    print_list(head2);

    add(head1,head2);

    free(head1);
    free(head2);
    printf("\n\n Done, Thank You! \n\n");
    return 0;
}