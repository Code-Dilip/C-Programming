#include<stdio.h>
#include<stdlib.h>

int i;

struct node {
    float coeff;
    int expo;
    struct node *nxt;
};

struct node *add_term(){
    i+=1;
    struct node *newp=malloc(sizeof(struct node));
    printf("\n enter the coefficient of the #%d term: ",i);
    scanf("%f",&newp->coeff);
    printf(" enter the exponent of the #%d node: ",i);
    scanf("%d",&newp->expo);
    newp->nxt=NULL;
    return newp;
}

void insert_term(struct node **head,struct node *newp){
    struct node *heady=*head;
    if(*head==NULL || newp->expo > heady->expo){
        newp->nxt=*head;
        *head=newp;
        return;
    }
    else{
        while(heady->nxt && newp->expo < heady->nxt->expo){
            heady=heady->nxt;
        }
        newp->nxt=heady->nxt;
        heady->nxt=newp;
    }
}

void create_polynomial(struct node **head){
    i=0;
    int n;
    printf("\n enter the no. of terms: ");
    scanf("%d",&n);
    for(int j=1;j<=n;j++){
        struct node *newp=add_term();
        insert_term(&*head,newp);
    }
}

void print_poly(struct node *ptr){
    while(ptr->nxt){
        printf(" (%.2fx^%d) +",ptr->coeff,ptr->expo);
        ptr=ptr->nxt;
    }
    printf(" (%2.fx^%d) ",ptr->coeff,ptr->expo);
}

void add_poly(struct node *head1,struct node *head2){
    struct node *ptr1=head1,*ptr2=head2,*head3=NULL;
    while(ptr1 && ptr2){
        struct node *newp=malloc(sizeof(struct node));
        if(ptr1->expo == ptr2->expo){
            newp->coeff=ptr1->coeff + ptr2->coeff;
            newp->expo=ptr1->expo;
            ptr1=ptr1->nxt;
            ptr2=ptr2->nxt;
        }
        else if(ptr1->expo > ptr2->expo){
            newp->coeff=ptr1->coeff;
            newp->expo=ptr1->expo;
            ptr1=ptr1->nxt;
        }
        else if(ptr2->expo > ptr1->expo){
            newp->coeff=ptr2->coeff;
            newp->expo=ptr2->expo;
            ptr2=ptr2->nxt;
        }
        newp->nxt=NULL;
        insert_term(&head3,newp);
    }
    
    while(ptr1){
        struct node *newp=malloc(sizeof(struct node));
        newp->coeff=ptr1->coeff;
        newp->expo=ptr1->expo;
        newp->nxt=NULL;
        insert_term(&head3,newp);
        ptr1=ptr1->nxt;
    }

    while(ptr2){
        struct node *newp=malloc(sizeof(struct node));
        newp->coeff=ptr2->coeff;
        newp->expo=ptr2->expo;
        newp->nxt=NULL;
        insert_term(&head3,newp);
        ptr2=ptr2->nxt;
    }

    printf("\n\n The addition: ");
    print_poly(head1);
    printf(" +");
    print_poly(head2);
    printf(" =");
    print_poly(head3);

}


void multiply(struct node *head1,struct node *head2){
    if(!head1 || !head2){
        printf("\n Zero Polynomial! ");
        return ;
    }
    
    struct node *ptr1=head1,*ptr2=head2,*head3=NULL;
    while(ptr1){
        while(ptr2){
            struct node *newp=malloc(sizeof(struct node));
            newp->coeff = ptr1->coeff * ptr2->coeff;
            newp->expo = ptr1->expo + ptr2->expo;
            newp->nxt=NULL;
            insert_term(&head3,newp);
            ptr2=ptr2->nxt;
        }
        ptr2=head2;
        ptr1=ptr1->nxt;
    }

    struct node *temp;
    ptr1=head3;
    while(ptr1->nxt){
        if(ptr1->expo == ptr1->nxt->expo){
            ptr1->coeff = ptr1->coeff + ptr1->nxt->coeff;
            temp=ptr1->nxt;
            ptr1->nxt=temp->nxt;
            free(temp);
            temp=NULL;
        }
        else{
            ptr1=ptr1->nxt;
        }
    }

    printf("\n\n The multiplication: ");
    print_poly(head1);
    printf(" *");
    print_poly(head2);
    printf(" =");
    print_poly(head3);
    printf("\n");
}

int main(){
    printf("\n Enter the first polynomial! ");
    struct node *head1=NULL;
    create_polynomial(&head1);
    printf("\n The first polynomial: ");
    print_poly(head1);
    
    printf("\n\n Enter the second polynomial: ");
    struct node *head2=NULL;
    create_polynomial(&head2);
    printf("\n The second polynomial: ");
    print_poly(head2);

    add_poly(head1,head2);
    multiply(head1,head2);

    free(head1);
    free(head2);
    printf("\n Thank You! \n\n");
    return 0;
}
