#include<stdio.h>
#include<stdlib.h>

int main(){

int n,i,m,*ptr=NULL;
printf("\n enter the no. of elements: ");
scanf("%d",&n);
printf("\n %d no.'s right. Hmmmm.....!",n);
ptr=(int *)malloc(n*sizeof(int));

if(ptr==NULL){
printf("\n Sorry ,The memory is not allocated! \n");
exit(1);
}
else{
printf("\n The memory is allocated successfully! \n");
}

for(i=0;i<n;i++){
printf(" enter the %d integer: ",i+1);
scanf("%d",ptr+i);
}
printf("\n The elements are..........");

for(i=0;i<n;i++){
printf(" The #%d inieger is %d",i+1,*(ptr+i));
}
printf("\n\n");

printf("\n enter the new size: ");
scanf("%d",&m);
ptr=(int *)realloc(ptr,m*sizeof(int));

for(i=n;i<m;i++){
printf(" enter the #%d new element: ",i+1-n);
scanf("%d",ptr+i);
j++;
}

printf("\n\n the elements after adding %d more element are........\n\n\n",m-n);
for(i=0;i<m;i++){
printf(" The #%d element is %d.",i+1,*(ptr+i));
}

printf("\n Done ,Thank you !");
printf("\n\n");
free(ptr);
ptr=NULL;
return 0;

}
