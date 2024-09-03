#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *nxt;
};

struct node *top_ptr=NULL;

struct node *add_node(int data){
    struct node *newp=malloc(sizeof(struct node));
    newp->data=data;
    newp->nxt=NULL;
    return newp;
}

int isEmpty(){
    if(!top_ptr){
        return 1;
    }
    return 0;
}

void push(int data){
    struct node *newp=add_node(data);
    newp->nxt=top_ptr;
    top_ptr=newp;
}

void pop(){
    if(isEmpty()){
        printf("\n Stack Underflow! \n");
        return;
    }
    struct node *head=top_ptr;
    top_ptr=top_ptr->nxt;
    printf("\n The element poped: %d \n",head->data);
    free(head);
}

void peek(){
    if(isEmpty()){
        printf("\n Stack is Empty! \n");
        return;
    }
    printf("\n The Top most value: %d \n",top_ptr->data);
}

void print_stack(){
    if(isEmpty()){
        printf(" Empty! ");
        return ;
    }
    struct node *ptr=top_ptr;
    while(ptr->nxt){
        printf(" %d ->",ptr->data);
        ptr=ptr->nxt;
    }
    printf(" %d ",ptr->data);
}

int main(){
    int choice;
    printf("\n");
    while(1){
        printf("\n enter (1) to push a element into the stack! ");
        printf("\n enter (2) to pop a element from the stack! ");
        printf("\n enter (3) to peek into the stack: ");
        printf("\n enter (4) to print the stack: ");
        printf("\n enter (5) to quit! ");

        printf("\n\n enter the choice: ");
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
                pop();
            }
            break;

            case 3:{
                peek();
            }
            break;

            case 4:{
                printf("\n The stack : ");
                print_stack();
            }
            break;

            case 5:{
                printf("\n Abnormal Termination! ");
                printf("\n\n Done, Thank You! ");
                exit(1);
            }
            break;

            default: {
                printf("\n Invalid Input! ");
            }
        }
    }
    printf("\n\n Done, Thank You! ");
    return 0;
}
