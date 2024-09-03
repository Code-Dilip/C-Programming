#include<stdio.h>
#include<stdlib.h>

struct student{
    char name[50];
    int age;
    int roll_no;
    float marks;
};

void print(char name[],int age,int roll_no,float marks){
    printf("\n Student's name: %s ",name);
    printf("Student's age: %d ",age);
    printf("\n Student's roll_no.: %d ",roll_no);
    printf("\n Student's marks: %.2f ",marks);
}

int main(){
    
    struct student s1;
    printf("\n enter the name of the Student: ");
    fgets(s1.name,sizeof(s1.name),stdin);
    printf(" enter the age of the student: ");
    scanf("%d",&s1.age);
    printf(" enter the roll_no. of the student: ");
    scanf("%d",&s1.roll_no);
    printf(" enter the marks of the student: ");
    scanf("%f",&s1.marks);

    printf("\n\n The Student Details are: ");
    print(s1.name,s1.age,s1.roll_no,s1.marks);
    printf("\n");

    return 0;
}