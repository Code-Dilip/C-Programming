#include<stdio.h>

int n,q,rem,result=0;

int palindrome(int n){
    q=n;
    while(q){
        rem=q%10;
        result=result*10+rem;
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
    int p;
    printf("\n enter a number to check whether it's palindrome or not: ");
    scanf("%d",&n);

    p=palindrome(n);
    if(p==1){
        printf("\n The no. %d is palindrome! ",n);
    }
    else{
        printf("\n The no. %d is not a palindrome! ",n);
    }
    return 0;
}