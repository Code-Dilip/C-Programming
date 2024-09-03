#include<stdio.h>
#include<stdlib.h>

#define max 10

int stack_arr[max],first=-1;

int isFull(){
    if(first==max-1){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(first==-1){
        return 1;
    }
    return 0;
}

void push(int data){
    if(isFull()){
        printf("\n Stack Overflow! \n");
        return ;
    }
    int j;
    first++;
    for(j=first-1;j>=0;j--){
        stack_arr[j+1]=stack_arr[j];
    }
    stack_arr[0]=data;
}

int pop(){
    if(isEmpty()){
        printf("\n Stack Overflow! \n");
        exit(1);
    }
    int j,val=stack_arr[0];
    for(j=0;j<first;j++){
        stack_arr[j]=stack_arr[j+1];
    }
    first--;
    return val;
}

int peek(){
    if(isEmpty()){
        printf("\n Stack is Empty! \n");
        exit(1);
    }
    return stack_arr[0];
}

void dec_to_bin(int num){
    int n=num;
    while(n!=0){
        push(n%2);
        n/=2;
    }
    printf("\n The decimat representation of %d is ",num);
    int j;
    for(j=0;j<=first;j++){
        printf("%d",stack_arr[j]);
    }
    printf(" \n");
}

void print(){
    if(isEmpty()){
        printf("\n Stack is Empty! \n");
        return ;
    }
    int j;
    for(j=first;j>0;j--){
        printf(" %d ->",stack_arr[j]);
    }
    printf(" %d ",stack_arr[j]);
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