#include<stdio.h>
#include<stdlib.h>

struct node {
    float coeff;
    int expo;
    struct node *nxt;
};

void add_term(struct node **head,struct node *newp){
    if(*head==NULL){
        newp->nxt = *head;
        *head = newp;
        return;
    }
    struct node *ptr = *head;
    while(ptr->nxt != NULL){
        ptr = ptr->nxt;
    }
    ptr->nxt = newp;
}

void insert_term(struct node **head,int i){
    struct node *newp = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the coefficient of the #%d term: ",i);
    scanf("%f",&(newp->coeff));
    printf(" enter the exponent of the #%d term: ",i);
    scanf("%d",&(newp->expo));

    if(*head == NULL || (*head)->expo < newp->expo){
        newp->nxt = *head;
        *head = newp;
        return;
    }
    struct node *ptr = *head;
    while(ptr->nxt != NULL && newp->expo < ptr->expo){
        ptr = ptr->nxt;
    }
    newp->nxt = ptr->nxt;
    ptr->nxt = newp;
}

void create_polynomial_func(struct node **head,int i){
    int n;
    printf("\n enter the number of terms in the #%d polynomial function: ",i);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        insert_term(head,i);
    }
}

void sum(struct node *ptr1,struct node *ptr2,struct node **head){
    while(ptr1!=NULL && ptr2!=NULL){
        struct node *newp = (struct node *)malloc(sizeof(struct node));
        if(ptr1->expo == ptr2->expo){
            newp->coeff = (ptr1->coeff + ptr2->coeff);
            newp->expo = ptr1->expo;
            ptr1 = ptr1->nxt;
            ptr2 = ptr2->nxt;
        }
        else if(ptr1->expo > ptr2->expo){
            newp->coeff = ptr1->coeff;
            newp->expo = ptr1->expo;
            ptr1 = ptr1->nxt;
        }
        else{
            newp->coeff = ptr2->coeff;
            newp->expo = ptr2->expo;
            ptr2 = ptr2->nxt;
        }
        newp->nxt = NULL;
        add_term(head,newp);
    }
    while(ptr1 != NULL){
        struct node *newp = (struct node *)malloc(sizeof(struct node));
        newp->coeff = ptr1->coeff;
        newp->expo = ptr1->expo;
        newp->nxt = NULL;
        add_term(head,newp);
        ptr1 = ptr1->nxt;
    }
    while(ptr2!=NULL){
        struct node *newp = (struct node *)malloc(sizeof(struct node));
        newp->coeff = ptr2->coeff;
        newp->expo = ptr2->expo;
        newp->nxt = NULL;
        add_term(head,newp);
        ptr2 = ptr2->nxt;
    }
}

void print_polynomial_func(struct node *ptr){
    if(ptr == NULL){
        printf("Empty!");
        return ;
    }
    printf("(%.2f*X^%d) ",ptr->coeff,ptr->expo);
    ptr = ptr->nxt;
    while(ptr!=NULL){
        printf("+ (%.2f*X^%d) ",ptr->coeff,ptr->expo);
        ptr = ptr->nxt;
    }
}

int main(){
    struct node *poly1 = NULL,*poly2 = NULL,*head = NULL;
    create_polynomial_func(&poly1,1);
    printf("\n The first plynomial function is ");
    print_polynomial_func(poly1);
    printf("\n");

    create_polynomial_func(&poly2,2);
    printf("\n The second polynomial function is ");
    print_polynomial_func(poly2);
    printf("\n");

    sum(poly1,poly2,&head);

    printf("\n {");
    print_polynomial_func(poly1);
    printf("} + {");
    print_polynomial_func(poly2);
    printf("} = ");
    print_polynomial_func(head);

    printf("\n\n");
    free(poly1);
    free(poly2);
    free(head);
    return 0;
}