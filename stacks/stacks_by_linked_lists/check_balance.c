#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define max 25

struct node{
    char alpha;
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

void push(char data){
    struct node *newp=add_node();
    if(newp==NULL){
        printf("\n Stack Overflow! \n");
        return ;
    }
    newp->alpha=data;
    newp->nxt=top;
    top=newp;
}

char pop(){
    if(isEmpty()){
        printf("\n Stack Underflow! \n");
        exit(1);
    }
    struct node *head=top;
    char data=head->alpha;
    top=top->nxt;
    free(head);
    return data;
}

void peek(){
    if(isEmpty()){
        printf("\n The Stack is Empty! \n");
        return;
    }
    printf("\n The top most element: %c \n",top->alpha);
}

void print(){
    if(isEmpty()){
        printf("\n The stack is Empty! \n");
        return ;
    }
    printf("\n The stack: ");
    struct node *ptr=top;
    while(ptr->nxt){
        printf(" %c ->",ptr->alpha);
        ptr=ptr->nxt;
    }
    printf(" %c \n",ptr->alpha);
}

int match(char a,char b){
    if(a=='[' && b==']'){
        return 1;
    }
    else if(a=='(' && b==')'){
        return 1;
    }
    else if(a=='{' && b=='}'){
        return 1;
    }
    else{
        return 0;
    }
}

int check_balance(char *s){
    int i=0;
    while(s[i]){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            push(s[i]);
        }
        if(s[i]=='}' || s[i]==']' || s[i]==')'){
            if(isEmpty()){
                printf("\n Invalid Expression!, as number of right brackets are more than left brackets! ");
                return 0;
            }
            else if(!match(pop(),s[i])){
                printf("\n Ivalid Expression! \n");
                return 0;
            }
        }
        i++;
    }
    if(isEmpty()){
        printf("\n Valid Expression! \n");
        return 1;
    }
    else {
        printf("\n Invalid Expression!,as number of left brackets are more than right brackets! \n");
        return 0;
    }
}

int main(){
    printf("\n BALANCED EXPRESSION OR NOT! \n");
    char str[max];
    int balance;
    printf("\n enter the expression: ");
    gets(str);
    balance=check_balance(str);
    if(balance==1){
        printf("\n The expression is balanced! \n");
    }
    else if(balance==0){
        printf("\n The expression isn't balanced! \n");
    }
    printf("\n Done, Thank You! \n");
    return 0;
}