#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct sinhVien
{
    char IDStudent[10];
    char LastName[20];
    char FirstName[10];
    char Gender[5];
    float FinalPoint;
} SV;

SV listSV[];

void addStudent();
void editGrade();
void editName();
void removeStudent();
void sortGrade();
void sortName();
void printAll();
void printId();
void printGrade();
void printAverage();

int main()
{
    printf("      ~ MENU ~\n");
    printf(" 1. Add student\n");
    printf(" 2. Edit student grade\n");
    printf(" 3. Edit student name\n");
    printf(" 4. Remove student\n");
    printf(" 5. Sort list by grade\n");
    printf(" 6. Sort list by name\n");
    printf(" 7. Print out all of list\n");
    printf(" 8. Print out list by ID\n");
    printf(" 9. Print out list by grade\n");
    printf("10. Print out average, highest, lowest grade\n");
    printf(" 0. Exit\n");

    int opt;
    do
    {
        printf("Please Choose: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            addStudent();
            break;
        case 2:
            editGrade();
            break;
        case 3:
            editName();
            break;
        case 4:
            removeStudent();
            break;
        case 5:
            sortGrade();
            break;
        case 6:
            sortName();
            break;
        case 7:
            printAll();
            break;
        case 8:
            printId();
            break;
        case 9:
            printGrade();
            break;
        case 10:
            printAverage();
            break;
        default:
            break;
        }

    } while (opt != 0);
}

void addStudent()
{
    // Enter main part of function
}
void editGrade()
{
    // Enter main part of function
}

void editName()
{
    // Enter main part of function
}

void removeStudent()
{
    int studentId;
    scanf("%d", studentId);
}

void sortGrade()
{
    // Enter main part of function
}

void sortName()
{
    // Enter main part of function
}

void printAll()
{
    printf("%-10s %-20s %-8s %-10s\n", "ID", "Full Name", "Gender", "Grade");
    printf("====================================================\n");
    int i;
    for (i = 0; i < stNum; i++)
    {
        char fullName[50] = "";
        strcat(fullName, listSV[i].FirstName);
        strcat(fullName, " ");
        strcat(fullName, listSV[i].LastName);
        printf("%-10s %-20s %-8s %-10.2f\n", listSV[i].IDStudent, fullName, listSV[i].Gender, listSV[i].FinalPoint);
    }
}
void printId()
{
    // Enter main part of function
}

void printGrade()
{
    // Enter main part of function
}

void printAverage()
{
    // Enter main part of function
}