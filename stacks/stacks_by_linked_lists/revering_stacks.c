#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *nxt;
} *top=NULL;

struct node *add_node(){
    struct node *newp=malloc(sizeof(struct node));
    return newp;
}

int isEmpty(struct node *top){
    if(top==NULL){
        return 1;
    }
    return 0;
}

void push(int data,struct node **top){
    struct node *newp=add_node();
    if(newp==NULL){
        printf("\n Stack Overflow! \n");
        return;
    }
    newp->data=data;
    newp->nxt=*top;
    *top=newp;
}

int pop(struct node **top){
    if(isEmpty(*top)){
        printf("\n Stack Underflow! \n");
        exit(1);
    }
    struct node *head=*top;
    int val=head->data;
    *top=(*top)->nxt;
    free(head);
    return val;
}

void peek(struct node *top){
    if(isEmpty(top)){
        printf("\n The Stack is Empty! \n");
        return ;
    }
    printf("\n The Top Most element: %c \n",top->data);
}

void print(struct node *top){
    if(isEmpty(top)){
        printf("\n The Stack is Empty! \n");
        return ;
    }
    printf("\n The Stack: ");
    struct node *head=top;
    while(head->nxt){
        printf(" %c ->",head->data);
        head=head->nxt;
    }
    printf(" %c \n",head->data);
}

void reverse(struct node **top){
    if(isEmpty(*top)){
        printf("\n The Stack is Empty! \n");
        return;
    }
    printf("\n Before reversing! ");
    print(*top);
    struct node *temp1=NULL,*temp2=NULL;
    while(*top){
        push(pop(&*top),&temp1);
    }
    while(temp1){
        push(pop(&temp1),&temp2);
    }
    while(temp2){
        push(pop(&temp2),&*top);
    }
    printf("\n After reversing! ");
    print(*top);
}


int main(){
    char choice;
    while(1){
        printf("\n\n enter (1) to push a element into the stack! ");
        printf("\n enter (2) to pop a element from the stack! ");
        printf("\n enter (3) to peek into the stack! ");
        printf("\n enter (4) to reverse the stack! ");
        printf("\n enter (5) to print the stack! ");
        printf("\n enter (6) to quit! ");

        printf("\n\n enter the choice: ");
        scanf("%s",&choice);

        switch(choice){
            case '1': {
                char data;
                printf("\n enter the data: ");
                scanf("%s",&data);
                push(data,&top);
            }
            break;

            case '2': {
                int ele;
                ele=pop(&top);
                printf("\n The element poped: %c \n",ele);
            }
            break;

            case '3': {
                peek(top);
            }
            break;

            case '4': {
                reverse(&top);
            }
            break;

            case '5': {
                print(top);
            }
            break;

            case '6': {
                printf("\n Abnormal Termation! \n");
                printf("\n Done, Thank You! \n");
                exit(1);
            }
            break;

            default: {
                printf("\n Invalid Input! \n");
            }
            break;
        }
    }
    printf("\n\n Done, Thank You! \n");
    return 0;
}