#include<stdio.h>
#include<stdlib.h>

int i=0;

struct node {
    int expo;
    float coeff;
    struct node *nxt;
};

struct node *add_node(){
    i+=1;
    struct node *newp=malloc(sizeof(struct node));
    printf("\n enter the coefficient of the #%d term: ",i);
    scanf("%f",&newp->coeff);
    printf(" enter the expo of the #%d term: ",i);
    scanf("%d",&newp->expo);
    newp->nxt=NULL;
    return newp;
}

void insert_node(struct node **head,struct node *newp){
    struct node *heady=*head;
    if(*head==NULL || newp->expo>heady->expo){
        newp->nxt=*head;
        *head=newp;
        return;
    }
    else{
        while(heady->nxt && newp->expo<heady->nxt->expo){
            heady=heady->nxt;
        }
        newp->nxt=heady->nxt;
        heady->nxt=newp;
    }
}

void print_list(struct node *ptr){
    printf(" coefficients: ");
    while(ptr->nxt){
        printf("%.1f -> ",ptr->coeff);
        ptr=ptr->nxt;
    }
    printf("%.1f \n",ptr->coeff);
}

void create_poly(struct node **head){
    int n;
    printf("\n enter the no. of terms: ");
    scanf("%d",&n);
    i=0;
    for(int j=1;j<=n;j++){
        struct node *newp=add_node();
        insert_node(&*head,newp);
        print_list(*head);
    }
}

struct node *add_polynomials(struct node *head1,struct node *head2){
   struct node *head3=NULL;

   while(head1 && head2){
    struct node *newp=malloc(sizeof(struct node));
    if(head1->expo == head2->expo){
        newp->coeff=head1->coeff+head2->coeff;
        newp->expo=head1->expo;
        head1=head1->nxt;
        head2=head2->nxt;
    }
    else if(head1->expo > head2->expo){
        newp->coeff=head1->coeff;
        newp->expo=head1->expo;
        head1=head1->nxt;
    }
    else if(head2->expo > head1->expo){
        newp->coeff=head2->coeff;
        newp->expo=head2->expo;
        head2=head2->nxt;
    }
    newp->nxt=NULL;
    insert_node(&head3,newp);
   }

   while(head1){
    struct node *newp=malloc(sizeof(struct node));
    newp->coeff=head1->coeff;
    newp->expo=head1->expo;
    newp->nxt=NULL;
    insert_node(&head3,newp);
    head1=head1->nxt;
   }

   while(head2){
    struct node *newp=malloc(sizeof(struct node));
    newp->coeff=head2->coeff;
    newp->expo=head2->expo;
    newp->nxt=NULL;
    insert_node(&head3,newp);
    head2=head2->nxt;
   }
   return head3;
}


void print_polynomial(struct node *ptr){
    printf("polynomial : ");
    while(ptr->nxt){
        printf("(%.2fx^%d)+",ptr->coeff,ptr->expo);
        ptr=ptr->nxt;
    }
    printf("(%.2fx^%d) ",ptr->coeff,ptr->expo);
}

int main(){
    struct node *head1=NULL;
    printf("\n\n Enter the first polynomial: ");
    create_poly(&head1);
    printf("\n The first ");
    print_polynomial(head1);
    printf("\n");

    printf("\n Enter the second polynomial: ");
    struct node *head2=NULL;
    create_poly(&head2);
    printf("\n The second ");
    print_polynomial(head2);
    printf("\n");

    struct node *head3=NULL;
    head3=add_polynomials(head1,head2);
    printf("\n The resultant ");
    print_polynomial(head3);
    printf("\n");
    printf("\n Done, Thank You! \n\n");

    free(head1);
    free(head2);
    free(head3);
    return 0;
}