#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define max 5

struct node {
    char alpha;
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

void push(char data){
    struct node *newp=add_node();
    if(newp==NULL){
        printf("\n Stack Overflow! \n");
        return;
    }
    newp->alpha=data;
    newp->nxt=top;
    top=newp;
}

char pop(){
    if(isEmpty()){
        printf("\n Stack Underflow! \n");
    }
    else{
        struct node *head=top;
        char data=head->alpha;
        top=top->nxt;
        free(head);
        printf("\n The element poped: %c \n",data);
    }
}

char peek(){
    if(isEmpty()){
        printf("\n The stack is Empty! \n");
    }
    else{
        printf("\n The top most element: %c \n",top->alpha);
    }
}

void print(){
    if(isEmpty()){
        printf("\n The stack is Empty! \n");
        return ;
    }
    printf("\n The stack: ");
    struct node *ptr=top;
    while(ptr->nxt){
        printf(" %c ->",ptr->alpha);
        ptr=ptr->nxt;
    }
    printf(" %c \n",ptr->alpha);
}


int main(){
    int choice;
    while(1){
        printf("\n ");
        printf("\n enter (1) to push a element into the stack! ");
        printf("\n enter (2) to pop a element from the stack! ");
        printf("\n enter (3) to peek into the stack! ");
        printf("\n enter (4) to print the stack! ");
        printf("\n enter (5) to quit! ");

        printf("\n\n enter the choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: {
                char data;
                printf("\n enter the data: ");
                scanf("%s",&data);
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
                print();
            }
            break;

            case 5: {
                printf("\n Abnormal Termination! \n");
                printf("\n Done, Thank You! \n\n");
                exit(1);
            }
        }
        }
    printf("\n Done, Thank You! \n");
    return 0;
}