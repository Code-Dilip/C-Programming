#include<stdio.h>
#include<stdlib.h>

struct student{
char name[20];
int age;
float marks;
};

void print(char name[],int *age,float *marks){
printf(" Student Name: %s ,Student Age: %d ,Student Marks: %.2f.",name,*age,*marks);
}

int main(){
struct student s={"Dilip Kumar BS",18,100};
print((s.name),&(s.age),&(s.marks));
printf("\n Done !,Thank You ");
printf("\n\n");
return 0;
}


