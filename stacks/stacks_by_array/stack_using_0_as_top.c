#include<stdio.h>
#include<stdlib.h>

#define max 5

int first =-1;
int stack_arr[max];

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
    first+=1;
    int j;
    for(j=first-1;j>=0;j--){
        stack_arr[j+1]=stack_arr[j];
    }
    stack_arr[0]=data;
}

int pop(){
    if(isEmpty()){
        printf("\n Stack Underflow! \n");
    }
    else{
      int j,val;
      val=stack_arr[0];
      for(j=0;j<first;j++){
        stack_arr[j]=stack_arr[j+1];
      }
      first-=1;
      printf("\n The element poped: %d \n",val);
    }
}

int peek(){
    if(isEmpty()){
        printf("\n Stack is empty! \n");
    }
    else{
        printf("\n The Top most element: %d \n",stack_arr[0]);
    }

}

void print_stack(){
    if(isEmpty()){
        printf("\n The stack is empty! \n");
        return ;
    }
    int j;
    for(j=0;j<first;j++){
        printf(" %d ->",stack_arr[j]);
    }
    printf(" %d ",stack_arr[j]);
}

int main(){
    int choice;
    printf("\n");
    while(1){

        printf("\n enter (1) to push a element into the stack! ");
        printf("\n enter (2) to pop element from the stack! ");
        printf("\n enter (3) to peek into the stack! ");
        printf("\n enter (4) to print stack! ");
        printf("\n enter (5) to quit! ");
        
        printf("\n\n enter the choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: {
                int data;
                printf("\n enter the data to insert into the stack: ");
                scanf("%d",&data);
                push(data);
            }
            break;

            case 2: {
                pop();
            }
            break;

            case 3: {
                peek();
            }
            break;
            
            case 4: {
                printf("\n The stack: ");
                print_stack();
            }
            break;

            case 5: {
                printf("\n Abnormal termination! ");
                printf("\n Done, Thank You! \n\n");
                exit(1);
            }
            break;

            default: {
                printf("\n Invalid Choice! ");
            }
        }
    }
    printf("\n\n Done, Thank You! ");
    return 0;
}