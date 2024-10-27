#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 10000

typedef struct sinhVien
{
    char IDStudent[10];
    char LastName[20];
    char FirstName[10];
    char Gender[5];
    float FinalPoint;
} SV;

SV listSV[MAX];
int stNum = 0;

void addStudent();
void updateStudent();
void removeStudent();
void sortGrade();
void sortName();
void printAll();
void printId();
void printGrade();
void printAverage();
void saveToFile();
void readFromFile();

int main()
{

    int opt;
    do
    {
        system("cls");
        printf("      ~ MENU ~\n");
        printf(" 1. Add student\n");
        printf(" 2. Update student\n");
        printf(" 3. Remove student\n");
        printf(" 4. Sort list by grade\n");
        printf(" 5. Sort list by name\n");
        printf(" 6. Print out all of list\n");
        printf(" 7. Print out list by ID\n");
        printf(" 8. Print out list by grade\n");
        printf(" 9. Print out average, highest, lowest grade\n");
        printf(" 0. To Exit\n");
        readFromFile();
        printf("Please Choose: ");
        scanf("%d", &opt);
        fflush(stdin);

        switch (opt)
        {
        case 1:
            addStudent();
            break;
        case 2:
            updateStudent();
            break;
        case 3:
            removeStudent();
            break;
        case 4:
            sortGrade();
            break;
        case 5:
            sortName();
            break;
        case 6:
            printAll();
            break;
        case 7:
            printId();
            break;
        case 8:
            printGrade();
            break;
        case 9:
            printAverage();
            break;
        default:
            system("cls");
            break;
        }

    } while (opt != 0);
}

void nameFormat(char *s)
{
}

void addStudent()
{
    // Enter main part of function
    system("cls");
    printf("ADD STUDENT");
    printf("\n-----------------------------------------\n");
    SV newSt;
    printf("Student ID: ");
    gets(newSt.IDStudent);
    printf("Last name: ");
    gets(newSt.LastName);
    printf("First name: ");
    gets(newSt.FirstName);
    printf("Gender(Male|Female): ");
    gets(newSt.Gender);
    printf("Final Point: ");
    scanf("%f", &newSt.FinalPoint);
    printf("\n-----------------------------------------\n");

    char opt;
    fflush(stdin);
    printf("Are you sure? (Y/N): ");
    scanf("%c", &opt);

    if (opt == 'y')
    {

        listSV[stNum] = newSt;

        printf("\n-----------------------------------------\n");
        printf("Student %s is added successful!\n", listSV[stNum].IDStudent);
        printf("-----------------------------------------\n");
        stNum++;
        saveToFile();
    }
    else
    {
        printf("Process is cancelled!!\n");
    }
    system("pause");

    return;
}

int searchById()
{
    char id[10];
    printf("Search by ID: ");
    gets(id);

    int i;
    for (i = 0; i < stNum; i++)
    {
        if (strcmp(listSV[i].IDStudent, id) == 0)
        {
            system("cls");
            printf("STUDENT INFORMATION");
            printf("\n-----------------------------------------\n");
            printf("%-10s %-20s %-8s %-10s\n", "ID", "Full Name", "Gender", "Grade");
            char fullName[50] = "";
            strcat(fullName, listSV[i].FirstName);
            strcat(fullName, " ");
            strcat(fullName, listSV[i].LastName);
            printf("%-10s %-20s %-8s %-10.2f\n", listSV[i].IDStudent, fullName, listSV[i].Gender, listSV[i].FinalPoint);
            printf("\n-----------------------------------------\n");
            return i;
        }
    }
    printf("\nID is not found!!\n");
    return -1;
}

void updateStudent()
{
    system("cls");
    printf("UPDATE STUDENT INFORMATION");
    printf("\n-----------------------------------------\n");
    int i = searchById();
    if (i == -1)
    {
        system("pause");
        return;
    }

    SV currentSt = listSV[i];
    printf("1. Edit ID\n");
    printf("2. Edit name\n");
    printf("3. Edit gender\n");
    scanf("\nChoose option: ");
    int opt;

    scanf("%d", &opt);
    fflush(stdin);
    system("cls");
    printf("UPDATE STUDENT INFORMATION");
    char fullName[50] = "";
    strcat(fullName, currentSt.FirstName);
    strcat(fullName, " ");
    strcat(fullName, currentSt.LastName);
    printf("\n-----------------------------------------\n");
    printf("%-10s %-20s %-8s %-10s\n", "ID", "Full Name", "Gender", "Grade");
    printf("%-10s %-20s %-8s %-10.2f\n", currentSt.IDStudent, fullName, currentSt.Gender, currentSt.FinalPoint);
    printf("\n-----------------------------------------\n");
    switch (opt)
    {
    case 1:

        printf("New ID: ");
        gets(currentSt.IDStudent);
        break;
    case 2:

        printf("New last name: ");
        gets(currentSt.LastName);
        printf("New first name: ");
        gets(currentSt.FirstName);

        break;
    case 3:

        printf("New gender: ");
        gets(currentSt.Gender);

        break;
    default:
        break;
    }

    printf("\n-----------------------------------------\n");

    printf("Are you sure? (y/n)");
    scanf("%c", &opt);
    if (opt == 'y')
    {
        listSV[i] = currentSt;
        saveToFile();
    }

    system("pause");
    return;
}

void removeStudent()
{
    system("cls");
    printf("REMOVE STUDENT");
    printf("\n-----------------------------------------\n");
    int id = searchById();
    char opt;
    printf("Press Y to remove %s: ", listSV[id].IDStudent);
    scanf("%c", &opt);
    if (opt == 'y')
    {
        int i;
        for (i = id; i < stNum - 1; i++)
        {
            listSV[i] = listSV[i + 1];
        }
        stNum--;
        saveToFile();
    }

    system("pause");
    return;
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
    system("cls");
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
    system("pause");
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

void saveToFile()
{
    FILE *file = fopen("data.csv", "w");
    if (file == NULL)
    {
        printf("OPEN FILE TO WRITE ERROR");
        exit(1);
    }

    int i;
    for (i = 0; i < stNum; i++)
    {
        fprintf(file, "%s,%s,%s,%s,%.1f,\n", listSV[i].IDStudent, listSV[i].LastName, listSV[i].FirstName, listSV[i].Gender, listSV[i].FinalPoint);
    }

    fclose(file);
}

void readFromFile()
{
    stNum = 0;
    FILE *file = fopen("data.csv", "r");
    if (file != NULL)
    {
        char buffer[100];

        while (fgets(buffer, sizeof(buffer), file) != NULL)
        {
            SV st;
            sscanf(buffer, "%10[^,],%20[^,],%10[^,],%5[^,],%f", &st.IDStudent, &st.LastName, &st.FirstName, &st.Gender, &st.FinalPoint);

            listSV[stNum] = st;

            stNum++;
        }
    }
    fclose(file);
}