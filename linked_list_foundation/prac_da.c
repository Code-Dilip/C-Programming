#include<stdio.h>
#include<stdlib.h>

int main(){
int n,m,i,*ptr;
printf("\n enter the no. of elements: ");
scanf("%d",&n);
printf("\n %d no.'s right! Hmmm....\n",n);
ptr=(int *)calloc(n,sizeof(int));

if(ptr==NULL){
printf("\n Sorry, Memory isn't allocated !");
exit(1);
}
else{
printf("\n Memory is allocated successfully!");
}

for(i=0;i<n;i++){
printf("\n enter the #%d integer: ",i+1);
scanf("%d",ptr+i);
}

printf("\n The elements are........\n");
for(i=0;i<n;i++){
printf("\n the #%d integer is %d.",i+1,*(ptr+i));
}

printf("\n enter a new size: ");
scanf("%d",&m);
ptr=(int *)realloc(ptr,m*sizeof(int));
for(i=n;i<m;i++){
printf(" enter the #%d element: ",i+1);
scanf("%d",ptr+i);
}

printf("\n the list of elements after entering the few more elemets are...........\n");
for(i=0;i<m;i++){
printf(" the #%d element is %d.",i+1,*(ptr+i));
}
printf("\n\n");
printf("\n Done!, Thank You!");
free(ptr);
return 0;

}


