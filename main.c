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
    char Gender[1];
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
    printf("Gender: ");
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
void swap(SV *sv1, SV *sv2){
    SV tam = *sv1;
    *sv1 = *sv2;
    *sv2 = tam;
}
void sortGrade()
{
    system("cls");
    int selectionSortGrade;
    do
    {
        printf("Do you want to sort list by grade?\n1. Yes\n2. Cancel\nYour selection: ");
        scanf("%d", &selectionSortGrade);
        if (selectionSortGrade != 1 && selectionSortGrade != 2)
        {
            system("cls");
            printf("Your selection is inappropriate\n");
            printf("Enter your selection again, please!\n");
        }
    } while (selectionSortGrade != 1 && selectionSortGrade != 2);
    if (selectionSortGrade == 1)
    {
        int i, j;
        for (i = 0; i < stNum - 1; i++)
        {
            for (j = i + 1; j < stNum; j++)
            {
                if (listSV[i].FinalPoint < listSV[j].FinalPoint)
                    swap(&listSV[i], &listSV[j]);
            }
        }
        saveToFile();
        printf("\n-----------------------------------------\n");
        printf("This list was sorted by grade\n");
        printf("-----------------------------------------\n");
    }
    else
    {
        printf("\n-----------------------------------------\n");
        printf("The sorting list by grade was cancelled\n");
        printf("-----------------------------------------\n");
    }
    system("pause");
}

void sortName()
{
    system("cls");
    int selectionSortName;
    do
    {
        printf("Do you want to sort list by name?\n1. Yes\n2. Cancel\nYour selection: ");
        scanf("%d", &selectionSortName);
        if (selectionSortName != 1 && selectionSortName != 2)
        {
            system("cls");
            printf("Your selection is inappropriate\n");
            printf("Enter your selection again, please!\n");
        }
    } while (selectionSortName != 1 && selectionSortName != 2);
    if (selectionSortName == 1)
    {
        int i, j;
        for (i = 0; i < stNum - 1; i++)
        {
            for (j = i + 1; j < stNum; j++)
            {
                if (strcmp(listSV[i].FirstName, listSV[j].FirstName) > 0)
                    swap(&listSV[i], &listSV[j]);
            }
        }
        saveToFile();
        printf("\n-----------------------------------------\n");
        printf("This list was sorted by name\n");
        printf("-----------------------------------------\n");
    }
    else
    {
        printf("\n-----------------------------------------\n");
        printf("The sorting list by name was cancelled\n");
        printf("-----------------------------------------\n");
    }
    system("pause");
}

void printAll()
{
    system("cls");
    printf("%-10s %-30s %-8s %-10s\n", "ID", "Full Name", "Gender", "Grade");
    printf("==========================================================\n");
    int i;
    for (i = 0; i < stNum; i++)
    {
        char fullName[50] = "";
        strcat(fullName, listSV[i].FirstName);
        strcat(fullName, " ");
        strcat(fullName, listSV[i].LastName);
        printf("%-10s %-30s %-8s %-10.2f\n", listSV[i].IDStudent, fullName, listSV[i].Gender, listSV[i].FinalPoint);
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

    int otp;
    do
    {
        system("cls");
        printf("    ~ OPTION ~\n");
        printf("1. Print out average grade\n");
        printf("2. Print out the highest grade\n");
        printf("3. Print out the lowest grade\n");
        printf("0. Exit\n");
        printf("Please choose: ");
        scanf("%d", &otp);
        switch (otp)
        {
        case 1:
            printAverageGrade();
            break;
        case 2:
            printHighest();
            break;
        case 3:
            printLowest();
            break;
        default:
            break;
        }
    } while (otp != 0);
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
