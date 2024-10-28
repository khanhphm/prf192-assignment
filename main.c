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

char fileAddress[255];

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
void handleOpenFile();
void handleCreateFile();
void handleRemoveFile();
void handleFile();

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        int opt;
        do
        {
            system("cls");
            printf("      ~ MENU ~\n");
            printf(" 1. New file\n");
            printf(" 2. Open file\n");
            printf(" 3. Delete file\n");
            printf(" 0. To Exit\n");
            printf("Please Choose: ");
            scanf("%d", &opt);
            fflush(stdin);
            stNum = 0;

            switch (opt)
            {
            case 1:
                handleCreateFile();
                break;

            case 2:
                handleOpenFile();
                break;
            case 3:
                handleRemoveFile();
                break;

            default:
                system("cls");
                break;
            }

        } while (opt != 0);
    }
    else
    {
        strcpy(fileAddress, argv[1]);
        printf("Handling at: %s\n", fileAddress);
        system("pause");
        handleFile();
    }
}

void handleCreateFile()
{

    char fileType[4] = ".csv";
    char fileName[10];
    char file[255] = "./data/";

    system("cls");
    printf("File name: ");
    gets(fileName);
    strcat(file, fileName);
    strcat(file, fileType);
    strcpy(fileAddress, file);

    saveToFile();
    system("pause");
    handleFile();
}

void handleOpenFile()
{

    char fileType[4] = ".csv";
    char fileName[10];
    char file[255] = "./data/";
    system("cls");
    printf("File name: ");
    scanf("%s", &fileName);
    strcat(file, fileName);
    strcat(file, fileType);
    strcpy(fileAddress, file);

    readFromFile();
    printf("Open file successful!!\n");
    system("pause");
    handleFile();
}

void handleRemoveFile()
{

    char fileType[4] = ".csv";
    char fileName[10];
    char file[255] = ".\\data\\";
    char delCmd[20] = "del ";

    system("cls");
    printf("File name: ");
    scanf("%s", &fileName);
    strcat(file, fileName);
    strcat(file, fileType);
    strcat(delCmd, file);
    system(delCmd);
    system("pause");
}

void handleFile()
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
    printf("Gender(M|F): ");
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
    printf("\nChoose option: ");
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
    return;
}
void swap(SV *sv1, SV *sv2)
{
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
    system("cls");
    char id[10];
    printf("Insert ID student: ");
    gets(id);
    int i;
    printf("%-10s %-30s %-8s %-10s\n", "ID", "Full Name", "Gender", "Grade");
    printf("===========================================================\n");
    for (i = 0; i < stNum; i++)
    {
        if (strcmp(id, listSV[i].IDStudent) == 0)
        {
            char fullName[50] = "";
            strcat(fullName, listSV[i].FirstName);
            strcat(fullName, " ");
            strcat(fullName, listSV[i].LastName);
            printf("%-10s %-30s %-8s %-10.2f\n", listSV[i].IDStudent, fullName, listSV[i].Gender, listSV[i].FinalPoint);
        }
    }
    system("pause");
}

void printGrade()
{
    system("cls");
    float a, b;
    printf("Insert grade \n");
    printf("from ");
    scanf("%f", &a);
    system("cls");
    printf("Insert grade \n");
    printf("from %.2f ", a);
    printf("to ");
    scanf("%f", &b);
    int i;
    printf("%-10s %-30s %-8s %-10s\n", "ID", "Full Name", "Gender", "Grade");
    printf("===========================================================\n");
    for (i = 0; i < stNum; i++)
    {
        if (listSV[i].FinalPoint >= a && listSV[i].FinalPoint <= b)
        {
            char fullName[50] = "";
            strcat(fullName, listSV[i].FirstName);
            strcat(fullName, " ");
            strcat(fullName, listSV[i].LastName);
            printf("%-10s %-30s %-8s %-10.2f\n", listSV[i].IDStudent, fullName, listSV[i].Gender, listSV[i].FinalPoint);
        }
    }
    system("pause");
}
void printAverageGrade()
{
    system("cls");
    float sum = 0;
    int i;
    for (i = 0; i < stNum; i++)
    {
        sum += listSV[i].FinalPoint;
    }
    printf("Average grade: %.2f\n", sum / stNum);
    system("pause");
}
void printHighest()
{
    system("cls");
    float max = 0.00;
    int i;
    for (i = 0; i < stNum; i++)
    {
        if (max < listSV[i].FinalPoint)
        {
            max = listSV[i].FinalPoint;
        }
    }
    printf("%-10s %-30s %-8s %-10s\n", "ID", "Full Name", "Gender", "Grade");
    printf("===========================================================\n");
    for (i = 0; i < stNum; i++)
    {
        if (max == listSV[i].FinalPoint)
        {
            char fullName[50] = "";

            strcat(fullName, listSV[i].FirstName);
            strcat(fullName, " ");
            strcat(fullName, listSV[i].LastName);
            printf("%-10s %-30s %-8s %-10.2f\n", listSV[i].IDStudent, fullName, listSV[i].Gender, listSV[i].FinalPoint);
        }
    }
    system("pause");
}
void printLowest()
{
    system("cls");
    float min = 10.00;
    int i;
    for (i = 0; i < stNum; i++)
    {
        if (min > listSV[i].FinalPoint)
        {
            min = listSV[i].FinalPoint;
        }
    }
    printf("%-10s %-30s %-8s %-10s\n", "ID", "Full Name", "Gender", "Grade");
    printf("===========================================================\n");
    for (i = 0; i < stNum; i++)
    {
        if (min == listSV[i].FinalPoint)
        {
            char fullName[50] = "";
            strcat(fullName, listSV[i].FirstName);
            strcat(fullName, " ");
            strcat(fullName, listSV[i].LastName);
            printf("%-10s %-30s %-8s %-10.2f\n", listSV[i].IDStudent, fullName, listSV[i].Gender, listSV[i].FinalPoint);
        }
    }
    system("pause");
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
    FILE *file = fopen(fileAddress, "w");
    if (file == NULL)
    {
        printf("OPEN FILE TO WRITE ERROR");
        exit(1);
    }

    int i;
    for (i = 0; i < stNum; i++)
    {
        fprintf(file, "%s,%s,%s,%s,%.1f\n", listSV[i].IDStudent, listSV[i].LastName, listSV[i].FirstName, listSV[i].Gender, listSV[i].FinalPoint);
    }

    fclose(file);
}

void readFromFile()
{
    stNum = 0;
    FILE *file = fopen(fileAddress, "r");
    if (file != NULL)
    {
        char buffer[100];

        while (fgets(buffer, sizeof(buffer), file) != NULL)
        {
            SV st;
            sscanf(buffer, "%10[^,],%20[^,],%10[^,],%1[^,],%f", &st.IDStudent, &st.LastName, &st.FirstName, &st.Gender, &st.FinalPoint);

            listSV[stNum] = st;

            stNum++;
        }
    }
    fclose(file);
}
