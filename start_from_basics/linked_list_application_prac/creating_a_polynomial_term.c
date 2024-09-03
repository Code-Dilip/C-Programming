#include<stdio.h>
#include<stdlib.h>

struct node {
    float coeff;
    int exp;
    struct node *link;
};

void print_polynomial_func(struct node *ptr){
    while(ptr->link != NULL){
        printf("(%.2fX^%d)+",ptr->coeff,ptr->exp);
        ptr = ptr->link;
    }
    printf("(%.2fX^%d) .",ptr->coeff,ptr->exp);
}

void insert_term(struct node **head,int i){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the coefficient of %d term: ",i);
    scanf("%f",&(temp->coeff));
    printf(" enter the exponent of the %d term: ",i);
    scanf("%d",&(temp->exp));
    temp->link = NULL;

    if(*head == NULL || (*head)->exp < temp->exp){
        temp->link = (*head);
        (*head) = temp;
    }
    else{
        struct node *ptr = (*head);
        while(ptr->link != NULL && ptr->link->exp > temp->exp){
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}

void create_polynomial_func(struct node **head,int i){
    int n;
    printf("\n enter the no. of terms in #%d polynomial function: ",i);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        insert_term(head,i);
    }
}

int main(){
    struct node *head1 = NULL,*head2 = NULL;
    create_polynomial_func(&head1,1);
    create_polynomial_func(&head2,2);
    
    printf("\n The #%d polynomial function is ",1);
    print_polynomial_func(head1);
    printf("\n The #%d polynomial function is ",2);
    print_polynomial_func(head2);

    printf("\n\n");
    free(head1);
    free(head2);
    return 0;
}