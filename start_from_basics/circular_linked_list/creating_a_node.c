#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *tail;
};

int main(){
    struct node *tail = (struct node *)malloc(sizeof(struct node));
    tail->data = 5;
    printf("\n The data of the first node is %d .",tail->data);
    printf("\n\n");

    free(tail);
    return 0;
}