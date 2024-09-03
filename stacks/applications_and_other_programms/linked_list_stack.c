#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node *nxt;
}*top=NULL;

struct node *add_node(){
    struct node *newp=malloc(sizeof(struct node));
    return newp;
}
int is_Empty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}

void push(int data){
    struct node *newp=add_node();
    if(newp==NULL){
        printf("\n Stack Overflow! \n");
        return;
    }
    newp->data=data;
    newp->nxt=top;
    top=newp;
}

int pop(){
    if(is_Empty()){
        printf("\n Stack Underflow! ");
        printf("\n abnormal Termination! \n");
        exit(1);
    }
    int data=top->data;
    struct node *temp=top;
    top=top->nxt;
    free(temp);
    return data;
}

void peek(){
    if(is_Empty()){
        printf("\n The stack is Empty! \n");
        return ;
    }
    printf("\n The top most element is %d \n",top->data);
}

void print(){
    struct node *ptr=top;
    while(ptr->nxt){
        printf("%d -> ",ptr->data);
        ptr=ptr->nxt;
    }
    printf("%d \n",ptr->data);
}

int main(){
    int choice;
    while(1){
        printf("\n enter 1 to push a element into the stack! ");
        printf("\n enter 2 to pop a element from the stack! ");
        printf("\n enter 3 to peek into the stack! ");
        printf("\n enter 4 to print the stack! ");
        printf("\n enter 5 to quit! ");

        printf("\n\n enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                int data;
                printf("\n enter the data: ");
                scanf("%d",&data);
                push(data);
            }
            break;

            case 2:{
                printf("\n The element poped is %d \n",pop());
            }
            break;

            case 3:{
                peek();
            }
            break;

            case 4:{
                printf("\n The stack: ");
                print();
            }
            break;

            case 5:{
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