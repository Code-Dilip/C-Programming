#include<stdio.h>

int n,i,j;

void equilateral_triangle(int n){
    for(i=1;i<=n;i++){
        for(j=1;j<=2*n-1;j++){
            if(j>=n-(i-1) && j<=n+(i-1)){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    printf("\n enter the no. of rows of the equilteral triangle: ");
    scanf("%d",&n);
    printf("\n\n The equilateral triangle is: \n");
    equilateral_triangle(n);
    return 0;
}