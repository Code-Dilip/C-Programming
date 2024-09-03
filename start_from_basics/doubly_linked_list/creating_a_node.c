#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev,*nxt;
};

int main(){
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 5;
    head->nxt = NULL;
    printf("\n The data of the data is %d .",head->data);
    
    free(head);
    printf("\n\n");
    return 0;
}