#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 20

int stack[max],top=-1;
char postfix[max],infix[max];

int isFull(){
    if(top==max-1){
        return 1;
    }
    return 0;
}
int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

void push(int data){
    if(isFull()){
        printf("\n Stack Overflow! \n");
        return;
    }
    top+=1;
    stack[top]=data;
}

int pop(){
    if(isEmpty()){
        printf("\n Stack Underflow! \n");
        exit(1);
    }
    int val=stack[top];
    top-=1;
    return val;
}

void print(char *s){
    for(int i=0;i<strlen(s);i++){
        printf("%c",s[i]);
    }
    printf(" \n");
}

int space(char s){
    if(s==' ' && s=='\t'){
        return 1;
    }
    return 0;
}

int precedence(char s){
    switch (s)
    {
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default : return 0;
    }
}

void inToPost(char *s){
    int j=0;
    char symbol;
    for(int i=0;i<strlen(s);i++){
        symbol=s[i];
        if(!space(symbol)){
            switch(symbol){
                case'(': {
                    push(symbol);
                }
                break;

                case')': {
                    while(stack[top]!=')'){
                        postfix[j++]=pop();
                    }
                pop();
                }
                break;

                case '^':
                case '*':
                case '/':
                case '+':
                case '-':{
                    while(!isEmpty() && precedence(stack[top]) >= precedence(symbol)){
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


int Pow(int b,int a){
    int c=1;
    while(a){
        c*=b;
        a--;
    }
    return c;
}

int post_eval(char *s){
    int a,b;
    char symbol;
    for(int i=0;i<strlen(s);i++){
        symbol=s[i];
        if(symbol>='0' && symbol<='9'){
            push(symbol-'0');
        }
        else{
            a=pop();
            b=pop();
            switch(symbol){
                case '+': push(b+a); break;
                case '-': push(b-a); break;
                case '*': push(b*a); break;
                case '/': push(b/a); break;
                case '^': push(Pow(b,a)); break;
            }
        }
    }
    pop();
}

int main(){
    int result;
    printf("\n INFIX TO POSTFIX AND POSTFIX EVALUATION! \n");
    printf("\n enter the infix expression: ");
    gets(&infix);

    inToPost(infix);
    printf("\n The postfix expression for above infix expression: ");
    print(postfix);

    result=post_eval(postfix);
    printf("\n The result of the above infix expression: %d \n",result);
    printf("\n Thank You! \n\n");
    return 0;
}