#include<stdio.h>

int n,q,rem,result=0;

int armstrong_or_not(int n){
    int digit=0;
    q=n;
    while(q){
        rem=q%10;
        digit++;
        q=q/10;
    }
    printf("\n The no. of digits: %d ",digit);
    q=n;
    while(q){
        rem=q%10;
        for(int i=1;i<=digit;i++){
            rem*=rem;
            printf("\n %d ",rem);
        }
        result+=rem;
        printf("\n\n %d ",result);
        q=q/10;
    }
    if(result==n){
        return 1;
    }
    else{
        return -1;
    }
}


int main(){
    printf("\n enter a number to check whether it's armstrong or not: ");
    scanf("%d",&n);
    
    int p;
    p=armstrong_or_not(n);
    if(p==1){
        printf("\n The no. %d is an armstrong number! ",n);
    }
    else{
        printf("\n The no. %d is not an armstrong number! ",n);
    }
    return 0;
}