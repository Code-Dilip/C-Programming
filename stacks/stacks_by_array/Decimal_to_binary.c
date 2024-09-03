#include<stdio.h>
#include<stdlib.h>

#define max 10

int stack_arr[max],top=-1;

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
        return ;
    }
    top++;
    stack_arr[top]=data;
}

int pop(){
    if(isEmpty()){
        printf("\n Stack Underflow! \n");
        exit(1);
    }
    int val=stack_arr[top];
    top--;
    return val;
}

int peek(){
    if(isEmpty()){
        printf("\n The stack is empty! \n");
    }
    return stack_arr[top];
}

void dec_to_bin(int num){
    int n=num;
    while(n!=0){
        push(n%2);
        n/=2;
    }
    printf("\n The binary representation of %d is ",num);
    int j;
    for(j=top;j>=0;j--){
        printf("%d",stack_arr[j]);
    }
    printf(" \n");
}

void print(){
    if(isEmpty()){
        printf("\n The stack is Empty! ");
        return;
    }
    int j;
    printf(" ");
    for(j=top;j>0;j--){
        printf(" %d ->",stack_arr[j]);
    }
    printf(" %d \n",stack_arr[j]);
}

int main(){
    int num;
    printf("\n Binary Representation! \n");
    printf("\n enter the number: ");
    scanf("%d",&num);
    while(!num){
        printf("\n enter a non-zero number: ");
        scanf("%d",&num);
    }
    dec_to_bin(num);
    printf("\n\n Done, Thank You! ");
    return 0;
}