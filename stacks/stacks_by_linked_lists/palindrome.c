#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define max 10

struct node {
    char alpha;
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

void push(char data){
    struct node *newp=add_node();
    if(newp==NULL){
        printf("\n Stack Overflow! \n");
        return;
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
    else{
        struct node *head=top;
        char data=head->alpha;
        top=top->nxt;
        free(head);
        return data;
    }
}

char peek(){
    if(isEmpty()){
        printf("\n The stack is Empty! \n");
    }
    else{
        printf("\n The top most element: %c \n",top->alpha);
    }
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

void check_palindrome(char *s){
    int i=0;
    while(s[i]!='X'){
        push(s[i]);
        i++;
    }
    i++;
    while(s[i]){
        if(isEmpty() || s[i]!=pop()){
            printf("\n The string is not a palindrome! ");
            return ;
        }
        i++;
    }
    if(isEmpty()){
        printf("\n The string is a palindrome! \n");
    }
    else{
        printf("\n The string is not a palindrome! \n");
    }
}


int main(){
    printf("\n PALINDROME! \n");
    char str[max];
    printf("\n enter the string: ");
    gets(&str);
    check_palindrome(str);
    printf("\n\n Done, Thank You! \n\n");
    return 0;
}
