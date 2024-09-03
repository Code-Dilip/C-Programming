#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void print_list(struct node *ptr){
    if(ptr == NULL)
      printf("\n The linked list is empty!");
    int count = 0;
    while(ptr != NULL){
        count ++;
        printf("\n The data of the #%d node is %d. ",count,ptr->data);
        ptr = ptr->link;
    }
}

void add_node_at_end(struct node **head,int data){
    if(*head == NULL){
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = data;
        ptr->link = NULL;
        *head = ptr;
    }
    else{
        struct node *temp = (struct node *)malloc(sizeof(struct node)),*ptr = *head;
        temp->data = data;
        temp->link = NULL;
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}

int main(){
    struct node *head = NULL;
    int n,data;
    printf("\n enter the no. of nodes you need: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf(" enter the data in the #%d node: ",i);
        scanf("%d",&data);
        add_node_at_end(&head,data);
    }

    printf("\n The linked list is");
    print_list(head);
    printf("\n\n");
    free(head);
    return 0;

}