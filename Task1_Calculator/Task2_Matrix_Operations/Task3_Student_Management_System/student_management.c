#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    char name[50];
    float marks;
};

void addStudent()
{
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat","ab");

    printf("Enter ID: ");
    scanf("%d",&s.id);

    printf("Enter Name: ");
    scanf("%s",s.name);

    printf("Enter Marks: ");
    scanf("%f",&s.marks);

    fwrite(&s,sizeof(s),1,fp);

    fclose(fp);

    printf("Student Added Successfully!\n");
}

void displayStudents()
{
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat","rb");

    if(fp==NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\nID\tName\tMarks\n");

    while(fread(&s,sizeof(s),1,fp))
    {
        printf("%d\t%s\t%.2f\n",s.id,s.name,s.marks);
    }

    fclose(fp);
}

int main()
{
    int choice;

    do
    {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    }while(choice!=3);

    return 0;
}
