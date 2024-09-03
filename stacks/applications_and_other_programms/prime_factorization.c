#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int data;
    struct node *nxt;
}*top=NULL;

struct node *add_node(){
    struct node *newp=malloc(sizeof(struct node));
    return newp;
}

int isEmpty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}

void push(int data){
    struct node *newp=add_node();
    if(newp==NULL){
        printf("\n Stack Overflow! \n");
        return;
    }
    newp->data=data;
    newp->nxt=top;
    top=newp;
}

int pop(){
    if(isEmpty()){
        printf("\n Stack Underflow! \n");
        exit(1);
    }
    int data=top->data;
    struct node *temp=top;
    top=top->nxt;
    free(temp);
    return data;
}

void print(){
    struct node *ptr=top;
    printf("( ");
    while(ptr->nxt){
        printf("%d , ",ptr->data);
        ptr=ptr->nxt;
    }
    printf("%d )",ptr->data);
}

void prime_factorization(int num){
    int n=num,i=2;
    while(n!=1){
        while(n%i==0){
            push(i);
            n/=i;
        }
        i++;
    }
    printf("\n The prime factors of %d are ",num);
    print();
    printf(" \n");
}

int main(){
    int num;
    printf("\n enter the number: ");
    scanf("%d",&num);

    prime_factorization(num);

    printf("\n Thank You, Done! \n");
    return 0;
}