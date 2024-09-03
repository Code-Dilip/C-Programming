#include<stdio.h>
#include<stdlib.h>

int i;

struct node{
    int data;
    struct node *nxt;
};

struct node *add_node(){
    struct node *newp=malloc(sizeof(struct node));
    return newp;
}

void insert(struct node **head,int num){
    struct node *newp=add_node();
    newp->data=num;
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

void reverse(struct node **head){
    struct node *curr=*head,*prev=NULL,*next=NULL;
    while(curr){
        next=curr->nxt;
        curr->nxt=prev;
        prev=curr;
        curr=next;
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

void back_2_num(struct node *ptr){
    while(ptr){
        printf("%d",ptr->data);
        ptr=ptr->nxt;
    }
}

void add_2_num(struct node *head1,struct node *head2){
  struct node *ptr1=head1,*ptr2=head2,*head3=NULL;
  int sum,carry=0;
  while(ptr1 || ptr2){
    sum=0;
    if(ptr1){
        sum+=ptr1->data;
    }
    if(ptr2){
        sum+=ptr2->data;
    }
    sum+=carry;
    carry=sum/10;
    sum=sum%10;
    insert(&head3,sum);
    if(ptr1){
        ptr1=ptr1->nxt;
    }
    if(ptr2){
        ptr2=ptr2->nxt;
    }
  }
  if(carry){
    insert(&head3,carry);
  }

    printf("\n");
    print_list(head1);
    printf("\n+");
    print_list(head2);
    printf("\n=");
    print_list(head3);

    reverse(&head3);
    printf("\n\n");
    print_list(head3);
}


int main(){
    int num1,num2;
    printf("\n enter the first number: ");
    scanf("%d",&num1);
    printf("\n enter the second number: ");
    scanf("%d",&num2);
    if(!num1 && !num2){
        printf("\n Zero! ");
        return 0;
    }
    if(num1==0){
        printf("\n The sum is %d ",num2);
        return 0;
    }
    if(num2==0){
        printf("\n The sum is %d ",num2);
        return 0;
    }
    int n1,n2,rem;
    struct node *head1=NULL,*head2=NULL;
    n1=num1;
    n2=num2;
    while(n1){
        rem=n1%10;
        n1/=10;
        insert(&head1,rem);
    }
    printf("\n The first num: ");
    print_list(head1);

    while(n2){
        rem=n2%10;
        n2/=10;
        insert(&head2,rem);
    }
    printf("\n The second num: ");
    print_list(head2);

    add_2_num(head1,head2);

    printf("\n\n Done, Thank You! ");
    return 0;
}