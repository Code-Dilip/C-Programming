#include<stdlib.h>
#include<stdio.h>
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
        return ;
    }
    newp->data=data;
    newp->nxt=top;
    top=newp;
}

char pop(){
    if(isEmpty()){
        printf("\n Stack Underflow! \n");
        exit(1);
    }
    char data=top->data;
    struct node *temp=top;
    top=top->nxt;
    free(temp);
    return data;
}

int match(char a, char b){
    if(a=='[' && b==']'){
        return 1;
    }
    else if(a=='{' && b=='}'){
        return 1;
    }
    else if(a=='(' && b==')'){
        return 1;
    }
    return 0;
}

void check_validity(char *s){
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='[' || s[i]=='{' || s[i]=='('){
            push(s[i]);
        }
        else if(s[i]==']' || s[i]=='}' || s[i]==')'){
            if(isEmpty()){
                printf("\n Invalid Expression! As no. of right braces are more than the left braces \n");
                return ;
            }
            else if(!match(pop(),s[i])){
                printf("\n Invalid Expression! \n");
                return ;
            }
        }
    }
    if(isEmpty()){
        printf("\n Valid Expression! \n");
    }
    else{
        printf("\n Invalid Expression! As no. of left braces are more than right braces \n");
    }
    return;
}

int main(){
    char str[20];
    printf("\n CHECK EXPRESSION! \n");
    printf("\n enter the expression: ");
    gets(str);
    check_validity(str);
    
    printf("\n Thank You, Done! \n");
    return 0;
}