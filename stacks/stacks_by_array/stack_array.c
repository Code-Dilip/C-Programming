#include<stdio.h>
#include<stdlib.h>

#define max 5

int top=-1;
int stack_arr[max];


int isFull(){
    if(top==max){
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
        printf("\n Stack Overflow! ");
        return;
    }
    top+=1;
    stack_arr[top]=data;
}

int pop(){
    if(isEmpty()){
        printf("\n Stack Underflow! ");
    }
    else{
      int value;
      value=stack_arr[top];
      top-=1;
      return value;
    }
}


int peek(){
    if(isEmpty()){
        printf("\n Stack Underflow! ");
    }
    else{
        return stack_arr[top];
    }
}

void print_stack(){
    if(isEmpty()){
        printf("\n Stack Underflow! ");
        return ;
    }
    int j;
    for(j=top;j>0;j--){
        printf(" %d ->",stack_arr[j]);
    }
    printf(" %d ",stack_arr[j]);
}

int main(){
    int choice;
    while(1){
        printf("\n");
        printf("\n enter (1) to Push a element into stack! ");
        printf("\n enter (2) to Pop a element from the stack! ");
        printf("\n enter (3) to Peek! ");
        printf("\n enter (4) to Print Stack! ");
        printf("\n enter (5) to quit! ");
        printf("\n\n enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                int data;
                printf("\n enter the data: ");
                scanf("%d",&data);
                push(data);
            }
            break;
            
            case 2: {
                int del;
                del=pop();
                printf("\n The poped element: %d ",del);
            }
            break;;

            case 3: {
                int val;
                val=peek();
                printf("\n The Top most value: %d ",val);
            }
            break;

            case 4: {
                printf("\n The stack : ");
                print_stack();
            }
            break;

            case 5: {
                printf(" Abnormal Termination! \n\n");
                exit(1);
            }
        }
    }
    printf("\n\n Done, Thank You! ");
    return 0;
}