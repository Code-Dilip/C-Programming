#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *nxt;
} *top=NULL;

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
        printf("\n Stack Overflow! ");
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
    int val=top->data;
    struct node *temp=top;
    top=top->nxt;
    free(temp);
    return val;
}

int peek(){
    if(isEmpty()){
        printf("\n Stack is Empty! \n");
        exit(1);
    }
    return top->data;
}

void print(){
    if(isEmpty()){
        printf("\n The stack is Empty! \n");
        return ;
    }
    struct node *temp=top;
    while(temp->nxt){
        printf(" %d ->",temp->data);
        temp=temp->nxt;
    }
    printf(" %d ",temp->data);
}

void prime_factors(int num){
    int n=num,i=2;
    while (num!=1)
    {
        while (num%i==0)
        {
            push(i);
            num/=i;
        }
        i++;   
    }
    printf("\n The prime factors of %d are: ",n);
    print();
}


int main(){
    int num;
    printf("\n enter the number to find prime factors of it: ");
    scanf(" %d",&num);
    while(!num){
        printf("\n enter a non-zero number: ");
        scanf(" %d",&num);
    }
    prime_factors(num);
    printf("\n\n Done, Thank You! \n\n");
    return 0;
}