#include<stdio.h>
#include<stdlib.h>

#define max 5

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
        return;
    }
    top+=1;
    stack_arr[top]=data;
}

int pop(){
    if(isEmpty()){
        printf("\n Stack Underflow! \n");
        exit(0);
    }
    int val=stack_arr[top];
    top-=1;
    return val;
}

void peek(){
    if(isEmpty()){
        printf("\n Empty! \n");
        return;
    }
    printf("\n The top most value is %d ",stack_arr[top]);
}

void print(){
    if(isEmpty()){
        printf("\n Empty! \n");
        return ;
    }
    int j=top;
    for(j=top;j>0;j--){
        printf(" %d ->",stack_arr[j]);
    }
    printf(" %d ",stack_arr[j]);
}

void prime_factors(int num){
    int n=num,i=2;
    while(n!=1){
        while(n%i==0){
            push(i);
            n/=i;
        }
        i++;
    }
    printf("\n The prime factors of %d are: ",num);
    print();
}

int main(){
    int num;
    printf("\n enter a number to find prime factors of it: ");
    scanf("%d",&num);
    while(num==0){
        printf("\n enter a non zero number! ");
        printf("\n enter a number once again: ");
        scanf("%d",&num);
        printf("\n");
    }
    prime_factors(num);
    printf("\n\n Done, Thank You! \n");
    return 0;
}