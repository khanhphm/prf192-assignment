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
void editGrade();
void editName();
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
        printf(" 2. Edit student grade\n");
        printf(" 3. Edit student name\n");
        printf(" 4. Remove student\n");
        printf(" 5. Sort list by grade\n");
        printf(" 6. Sort list by name\n");
        printf(" 7. Print out all of list\n");
        printf(" 8. Print out list by ID\n");
        printf(" 9. Print out list by grade\n");
        printf("10. Print out average, highest, lowest grade\n");
        printf(" Other to Exit\n");
        // readFromFile();
        printf("Please Choose: ");
        scanf("%d", &opt);
        fflush(stdin);

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
    system("cls");
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

    listSV[stNum] = newSt;

    printf("-----------------------------------------\n");
    printf("Student %s is added successful!\n", listSV[stNum].IDStudent);
    printf("-----------------------------------------\n");
    stNum++;
    // saveToFile();

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
    do{
        printf("Do you want to sort list by grade?\n1. Yes\n2. Cancel\nYour selection: ");
        scanf("%d", &selectionSortGrade);
        if(selectionSortGrade != 1 && selectionSortGrade != 2){
            system("cls");
            printf("Your selection is inappropriate\n");
            printf("Enter your selection again, please!\n");
        }
    }while(selectionSortGrade != 1 && selectionSortGrade != 2);
    if(selectionSortGrade == 1){
        int i, j;
        for(i = 0 ; i < stNum -1; i++){
            for(j = i + 1; j < stNum; j++){
                if(listSV[i].FinalPoint < listSV[j].FinalPoint) swap(&listSV[i], &listSV[j]);
            }
        }
        printf("\n-----------------------------------------\n");
        printf("This list was sorted by grade\n");
        printf("-----------------------------------------\n");
    }
    else{
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
    do{
        printf("Do you want to sort list by name?\n1. Yes\n2. Cancel\nYour selection: ");
        scanf("%d", &selectionSortName);
        if(selectionSortName != 1 && selectionSortName != 2){
            system("cls");
            printf("Your selection is inappropriate\n");
            printf("Enter your selection again, please!\n");
        }
    }while(selectionSortName != 1 && selectionSortName != 2);
    if(selectionSortName == 1){
        int i, j;
        for(i = 0 ; i < stNum -1; i++){
            for(j = i + 1; j < stNum; j++){
                if(strcmp(listSV[i].FirstName, listSV[j].FirstName) > 0) swap(&listSV[i], &listSV[j]);
            }
        }
        printf("\n-----------------------------------------\n");
        printf("This list was sorted by name\n");
        printf("-----------------------------------------\n");
    }
    else{
        printf("\n-----------------------------------------\n");
        printf("The sorting list by name was cancelled\n");
        printf("-----------------------------------------\n");
    }
    system("pause");
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
        fprintf(file, "%s,%s,%s,%s,%.2f\n", listSV[i].IDStudent, listSV[i].LastName, listSV[i].FirstName, listSV[i].Gender, listSV[i].FinalPoint);
    }

    fclose(file);
}

void readFromFile()
{
    stNum = 0;
    FILE *file = fopen("data.csv", "r");
    if (file == NULL)
    {
        printf("Không thể mở file.\n");
        exit(1);
    }

    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        SV st;
        sscanf(buffer, "%10[^,],%20[^,],%10[^,],%5[^,],%f", &st.IDStudent, &st.LastName, &st.FirstName, &st.Gender, &st.FinalPoint);

        listSV[stNum] = st;

        stNum++;
    }

    fclose(file);
}