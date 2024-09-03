#include<stdio.h>
#include<stdlib.h>

int main(){
int n,i,*ptr=NULL;
printf("\n enter the no. of elements: ");
scanf("%d",&n);
printf("\n %d no's rignt! Hmmm........",n);
ptr=(int *)calloc(n,sizeof(n));
if(ptr==NULL){
printf("\n sorry, memory isn't allocated! ");
exit(1);
}
else{
printf("\n memory is allocated successfully! ");
}
printf("\n");
for(i=0;i<n;i++){
printf(" enter the #%d integer: ",i+1);
scanf("%d",ptr+i);
}
printf("\n the elements are.....\n");
for(i=0;i<n;i++){
printf("\n the #%d integer is %d.",i+1,*(ptr+i));
}
printf("\n Done , Thank You! ");
printf("\n\n");
free(ptr);
return 0;
}
