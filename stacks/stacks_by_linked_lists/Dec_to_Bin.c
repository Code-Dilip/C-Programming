#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *nxt;
} *top=NULL;

struct node *add_node(){
    struct node *newp = malloc(sizeof(struct node));
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
        return ;
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
    struct node *head=top;
    top=top->nxt;
    int val=head->data;
    free(head);
    return val;
}

int peek(){
    if(isEmpty()){
        printf("\n Stack is Empty! \n");
        exit(1);
    }
    return top->data;
}

void dec_to_bin(int num){
    int n=num;
    while(n!=0){
        push(n%2);
        n/=2;
    }
    printf("\n The decimal representation of %d is ",num);
    struct node *head=top;
    while(head){
        printf("%d",head->data);
        head=head->nxt;
    }
}

void print(){
    if(isEmpty()){
        printf("\n Stack is Empty! \n");
        return ;
    }
    struct node *head=top;
    while(head->nxt){
        printf(" %d ->",head->data);
        head=head->nxt;
    }
    printf(" %d ",head->data);
}

int main(){
    printf("\n Binary Representation! \n");
    int num;
    printf("\n enter the number: ");
    scanf("%d",&num);
    while(!num){
        printf("\n enter a non-zero number: ");
        scanf("%d",&num);
    }
    dec_to_bin(num);
    printf("\n\n Done, Thank You! \n\n");
    return 0;
}