#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20

char infix[max],postfix[max];

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

int is_space(char s){
    if(s==' ' || s=='\t'){
        return 1;
    }
    return 0;
}

int precedence(char s){
    switch(s){
        case'^': return 3;
        case'*':
        case'/': return 2;
        case'+':
        case'-':return 1;
        default : return 0;
    }
}

int Pow(int b, int a){
    int c=b;
    b=1;
    while(a){
        b*=c;;
        a--;
    }
    return b;
}

void infixToPostfix(char *s){
    int j=0;
    char symbol;
    for(int i=0;i<strlen(s);i++){
        symbol=s[i];
        if(!is_space(symbol)){
            switch(symbol){
                case'(':{
                    push(symbol);
                }
                break;

                case')':{
                    while(top->data != '('){
                        postfix[j++]=pop();
                    }
                    pop();
                }
                break;

                case'^':
                case'*':
                case'/':
                case'+':
                case'-':{
                    while(!isEmpty() && precedence(top->data) >= precedence(symbol)){
                        postfix[j++]=pop();
                    }
                    push(symbol);
                }
                break;

                default: {
                    postfix[j++]=symbol;
                }
                break;
            }
        }
    }
    while(!isEmpty()){
        postfix[j++]=pop();
    }
}

int postfix_Eval(char *s){
    int a,b;
    for(int i=0;i<strlen(s);i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            push(postfix[i]-'0');
        }
        else{
            a=pop();
            b=pop();
            switch(postfix[i]){
                case'^': push(Pow(b,a));break;
                case'*': push(b*a);break;
                case'/': push(b/a);break;
                case'+': push(b+a);break;
                case'-': push(b-a);break;
            }
        }
    }
    return pop();
}

void print(char *s){
    for(int i=0;i<strlen(s);i++){
        printf("%c",s[i]);
    }
}

int main(){

    printf("\n INFIX TO POSTFIX! \n");
    printf("\n enter the infix expression: ");
    gets(&infix);

    infixToPostfix(infix);

    printf("\n The postfix form of ");
    print(infix);
    printf(" is ");
    print(postfix);
    printf(" \n");

    printf("\n The result of ");
    print(postfix);
    printf(" is %d \n",postfix_Eval(postfix));

    printf("\n Thank You, Done! \n");
    return 0;
}