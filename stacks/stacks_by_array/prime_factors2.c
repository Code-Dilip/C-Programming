#include<stdio.h>
#include<stdlib.h>

#define max 10

int first=-1,stack_arr[max];

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
        return;
    }
    int j;
    first+=1;
    for(j=first-1;j>=0;j--){
        stack_arr[j+1]=stack_arr[j];
    }
    stack_arr[0]=data;
}

void pop(){
    if(isEmpty()){
        printf("\n Stack Underflow! \n");
        return;
    }
    int j,val;
    val=stack_arr[0];
    for(j=0;j<first;j++){
        stack_arr[j+1]=stack_arr[j];
    }
    first-=1;
    printf("\n The poped element: %d ",val);
}

void peek(){
    if(isEmpty()){
        printf("\n The stack is empty! ");
        return;
    }
    printf("\n The top most element: %d \n",stack_arr[0]);
}

void print(){
    if(isEmpty()){
        printf("\n Stack Underflow! \n");
        return;
    }
    int j;
    for(j=0;j<first;j++){
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
    printf("\n enter a number to find factors of it: ");
    scanf("%d",&num);
    while(!num){
        printf("\n\n enter a non zero number: ");
        scanf("%d",&num);
    }
    prime_factors(num);
    printf("\n\n Done, Thank You! \n\n");
    return 0;
}