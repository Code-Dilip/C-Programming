#include<stdio.h>
#include<stdlib.h>

int i=0;

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
    printf(" enter the exponent of the #%d term: ",i);
    scanf("%d",&newp->expo);
    newp->nxt=NULL;
    return newp;
}

void insert_node(struct node **head,struct node *newp){
    struct node *heady=*head;
    if(!*head || newp->expo > (*head)->expo){
        newp->nxt=*head;
        (*head)=newp;
        return ;
    }
    while(heady->nxt && newp->expo < heady->nxt->expo){
        heady=heady->nxt;
    }
    newp->nxt=heady->nxt;
    heady->nxt=newp;
}

void create_poly(struct node **head){
    i=0;
    int n;
    printf("\n enter the no. of terms: ");
    scanf("%d",&n);
    for(int j=0;j<n;j++){
        struct node *newp=add_term();
        insert_node(&*head,newp);
    }
}

void print_poly(struct node *ptr){
    while(ptr->nxt){
        printf(" (%.1fx^%d) +",ptr->coeff,ptr->expo);
        ptr=ptr->nxt;
    }
    printf(" (%.1fx%d) ",ptr->coeff,ptr->expo);
}

void add_poly(struct node *head1,struct node *head2){
    if(!head1 && !head2){
        printf("\n Zero polynomial! \n");
    }
    struct node *head3=NULL,*ptr1=head1,*ptr2=head2;
    while(ptr1 && ptr2){
        struct node *newp=malloc(sizeof(struct node));
        if(ptr1->expo == ptr2->expo){
            newp->coeff = ptr1->coeff + ptr2->coeff;
            newp->expo = ptr1->expo;
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
        insert_node(&head3,newp);
    }
    while(ptr1){
        struct node *newp=malloc(sizeof(struct node));
        newp->coeff=ptr1->coeff;
        newp->expo=ptr1->expo;
        newp->nxt=NULL;
        insert_node(&head3,newp);
        ptr1=ptr1->nxt;
    }
    while(ptr2){
        struct node *newp=malloc(sizeof(struct node));
        newp->coeff=ptr2->coeff;
        newp->expo=ptr2->expo;
        newp->nxt=NULL;
        insert_node(&head3,newp);
        ptr2=ptr2->nxt;
    }

    printf("\n The addition: ");
    print_poly(head1);
    printf(" +");
    print_poly(head2);
    printf("=");
    print_poly(head3);
    printf(" \n");
}

void multiplication(struct node *head1,struct node *head2){
    if(!head1 || !head2){
        printf("\n Zero Polynomial! ");
        return ;
    }
    struct node *head3=NULL,*ptr1=head1,*ptr2=head2,*temp;
    while(ptr1){
        while(ptr2){
            struct node *newp = malloc(sizeof(struct node));
            newp->coeff = ptr1->coeff * ptr2->coeff;
            newp->expo = ptr1->expo + ptr2->expo;
            newp->nxt=NULL;
            insert_node(&head3,newp);
            ptr2=ptr2->nxt;
        }
        ptr2=head2;
        ptr1=ptr1->nxt;
    }
    printf("\n Before simplification! \n");
    printf("(");
    print_poly(head1);
    printf(")");
    printf("*");
    printf("(");
    print_poly(head2);
    printf(")");
    printf("=");
    print_poly(head3);
    printf("\n");

    ptr1=head3;
    while(ptr1->nxt){
        if(ptr1->expo == ptr1->nxt->expo){
            ptr1->coeff = ptr1->coeff + ptr1->nxt->coeff;
            temp=ptr1->nxt;
            ptr1->nxt=temp->nxt;
            free(temp);
        }
        else{
            ptr1=ptr1->nxt;
        }
    }

    printf("\n After simplification! \n");
    printf("(");
    print_poly(head1);
    printf(")");
    printf("*");
    printf("(");
    print_poly(head2);
    printf(")");
    printf("=");
    print_poly(head3);
    printf("\n");
}

int main(){
    struct node *head1=NULL;
    printf("\n enter the first polynomial: ");
    create_poly(&head1);
    printf("\n The first polynomial: ");
    print_poly(head1);

    struct node *head2=NULL;
    printf("\n\n enter the second polynomial: ");
    create_poly(&head2);
    printf("\n The second polynomial: ");
    print_poly(head2);

    add_poly(head1,head2);

    multiplication(head1,head2);

    printf("\n Done, Thank You! \n");
    return 0;
}