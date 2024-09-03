#include<stdio.h>
#include<stdlib.h>

int main(){
int *ptr=NULL;
int n,i;
printf(" enter the no. of integers, that u want to enter: ");
scanf("%d",&n);
printf("\n %d no's right. hmmm.......",n);
ptr=(int *)malloc(n*sizeof(int));

if(ptr==NULL){
printf("\n memory was not allocated ");
exit(1);
}
else{
printf("\n memory allocated successfully! \n");
for(i=0;i<n;i++){
  printf(" enter the %d integer:",i+1);
  scanf("%d",ptr+i);
}
printf("\n the elements are .....");
}

for(i=0;i<n;i++){
printf(" the %d integer is %d.",i+1,*(ptr+i));
}

printf(" \n\n thank you! ");
printf("\n\n");
free(ptr);
return 0;
}