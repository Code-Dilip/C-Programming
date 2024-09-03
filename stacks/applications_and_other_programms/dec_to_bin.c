#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
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
    return top->data;
}

void print(){
    struct node *ptr=top;
    while(ptr){
        printf("%d",ptr->data);
        ptr=ptr->nxt;
    }
}

void dec2bin(int num){
    int n=num;
    while(n!=0){
        push(n%2);
        n/=2;
    }
    printf("\n The binary representation of %d is ",num);
    print();
    printf(" \n");
}

int main(){
    int num;
    printf("\n enter the number: ");
    scanf("%d",&num);

    dec2bin(num);

    printf("\n Thank You, Done! \n");
    return 0;
}