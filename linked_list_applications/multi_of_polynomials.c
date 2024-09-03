#include<stdio.h>
#include<stdlib.h>

int i=0;

struct node{
    float coeff;
    int expo;
    struct node *nxt;
};

struct node *add_node(){
    i+=1;
    struct node *newp=malloc(sizeof(struct node));
    printf("\n enter the coefficient of the #%d term: ",i);
    scanf("%f",&newp->coeff);
    printf(" enter the exponent of the #%d term: ",i);
    scanf("%d",&newp->expo);
    newp->nxt=NULL;
    return newp;
}

void insert_node(struct node **head,struct node *newp){
    struct node *heady=*head;
    if(*head==NULL || newp->expo > heady->expo){
        newp->nxt=*head;
        *head=newp;
        return;
    }
    else {
        while(heady->nxt && newp->expo<heady->nxt->expo){
            heady=heady->nxt;
        }
        newp->nxt=heady->nxt;
        heady->nxt=newp;
    }
}

void create_polynomial(struct node **head){
    int n;
    printf("\n enter the no. of terms: ");
    scanf("%d",&n);
    i=0;
    for(int j=1;j<=n;j++){
        struct node *newp=add_node();
        insert_node(&*head,newp);
    }
}

void print_polynomial(struct node *ptr){
    while(ptr->nxt){
        printf("(%.2fx^%d)+",ptr->coeff,ptr->expo);
        ptr=ptr->nxt;
    }
    printf("(%.2fx^%d) ",ptr->coeff,ptr->expo);
}


void poly_product(struct node *head1,struct node *head2){
    if(head1==NULL || head2==NULL){
        printf("\n Zero polynomial! ");
        return;
    }
    struct node *ptr1=head1,*ptr2=head2,*head3=NULL;
    while(ptr1){
        while (ptr2)
        {
            struct node *newp=malloc(sizeof(struct node));
            newp->coeff=ptr1->coeff*ptr2->coeff;
            newp->expo=ptr1->expo+ptr2->expo;
            newp->nxt=NULL;
            insert_node(&head3,newp);
            ptr2=ptr2->nxt;
        }
        ptr2=head2;
        ptr1=ptr1->nxt;
    }

    printf("\n\n Resultant polynomial- ");
    print_polynomial(head1);
    printf(" * ");
    print_polynomial(head2);
    printf(": \n\n Before simplification: ");
    print_polynomial(head3);

    struct node *ptr3=head3,*temp=NULL;
    while(ptr3->nxt){
        if(ptr3->expo == ptr3->nxt->expo){
           ptr3->coeff=ptr3->coeff+ptr3->nxt->coeff;
           temp=ptr3->nxt;
           ptr3->nxt=temp->nxt;
           free(temp);
           temp=NULL;
        }
        else{
            ptr3=ptr3->nxt;
        }
    }
    printf("\n After simplification: ");
    print_polynomial(head3);
    free(head3);
}


int main(){
    printf("\n Enter the first polynomial! ");
    struct node *head1=NULL;
    create_polynomial(&head1);
    printf("\n The first polynomial: ");
    print_polynomial(head1);

    printf("\n\n Enter the second polynomial! ");
    struct node *head2=NULL;
    create_polynomial(&head2);
    printf("\n The second polynomial: ");
    print_polynomial(head2);

    poly_product(head1,head2);

    printf("\n Thank You, Done! \n\n");
    free(head1);
    free(head2);
    return 0;
}