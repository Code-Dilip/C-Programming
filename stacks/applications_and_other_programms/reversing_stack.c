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
    int data=(*top)->data;
    struct node *temp=*top;
    (*top)=(*top)->nxt;
    free(temp);
    return data;
}

void peek(struct node *top){
    if(isEmpty(top)){
        printf("\n Stack is Empty! \n");
        return ;
    }
    printf("\n The top most data element is %d \n",top->data);
}

void reverse_stack(struct node **top){
    struct node *temp1=NULL,*temp2=NULL;
    while(*top){
        push(pop(&(*top)),&temp1);
    }

    while(temp1){
        push(pop(&(temp1)),&temp2);
    }

    while(temp2){
        push(pop(&(temp2)),&(*top));
    }
}

void print(struct node *top){
    while(top->nxt){
        printf("%d -> ",top->data);
        top=top->nxt;
    }
    printf("%d \n",top->data);
}

int main(){
    int choice;
    while(1){
        printf("\n enter 1 to push a element into the stack! ");
        printf("\n enter 2 to pop a element from the stack! ");
        printf("\n enter 3 to peek into the stack! ");
        printf("\n enter 4 to reverse the stack! ");
        printf("\n enter 5 to print the stack! ");
        printf("\n enter 6 to quit! ");

        printf("\n\n enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                int data;
                printf("\n enter the data: ");
                scanf("%d",&data);
                push(data,&top);
            }
            break;

            case 2:{
                printf("\n The element poped is %d \n",pop(&top));
            }
            break;

            case 3:{
                peek(top);
            }
            break;

            case 4:{
                reverse_stack(&top);
            }
            break;

            case 5:{
                printf("\n The stack: ");
                print(top);
            }
            break;

            case 6:{
                printf("\n Abnormal Termination! ");
                printf("\n Thank You, Done! \n");
                exit(1);
            }
            break;

            default: {
                printf("\n Invalid Input! \n");
            }
            break;
        }
    }
}