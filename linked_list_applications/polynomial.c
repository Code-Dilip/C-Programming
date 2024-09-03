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

void insert_node(struct node **head){
    struct node *heady=*head,*newp=add_node();
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
        return;
    }
}

void print_list(struct node *ptr){
    printf(" Coefficients: ");
    while(ptr->nxt){
        printf("%.2f -> ",ptr->coeff);
        ptr=ptr->nxt;
    }
    printf("%.2f \n",ptr->coeff);
}

void create_polynomial(struct node **head){
    int n;
    printf("\n enter the no. of terms: ");
    scanf("%d",&n);
    i=0;
    for(int j=1;j<=n;j++){
        insert_node(&*head);
        print_list(*head);
    }
}

void print_polynomial(struct node *ptr){
    while(ptr->nxt){
        printf("(%.2fx^%d) + ",ptr->coeff,ptr->expo);
        ptr=ptr->nxt;
    }
    printf("(%.2fx^%d) ",ptr->coeff,ptr->expo);
}

int main(){
    printf("\n Enter the first polynomial! ");
    struct node *head1=NULL;
    create_polynomial(&head1);
    printf("\n The first polynomial: ");
    print_polynomial(head1);

    printf("\n\n Enter the second polynomial: ");
    struct node *head2=NULL;
    create_polynomial(&head2);
    printf("\n The second polynomial: ");
    print_polynomial(head2);

    free(head1);
    free(head2);
    return 0;
}