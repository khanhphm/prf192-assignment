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
    saveToFile();

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
    for(i=0;i<stNum;i++) {
    	if(strcmp(id,listSV[i].IDStudent)==0) {
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
	float a,b;
	printf("Insert grade \n");
	printf("from "); scanf("%f", &a);
	system("cls");
	printf("Insert grade \n");
	printf("from %.2f ", a);
	printf("to "); scanf("%f", &b);
	int i;
	printf("%-10s %-30s %-8s %-10s\n", "ID", "Full Name", "Gender", "Grade");
    printf("===========================================================\n");
	for(i=0;i<stNum;i++) {
		if(listSV[i].FinalPoint>=a && listSV[i].FinalPoint<=b) {
			char fullName[50] = "";
        	strcat(fullName, listSV[i].FirstName);
        	strcat(fullName, " ");
        	strcat(fullName, listSV[i].LastName);
        	printf("%-10s %-30s %-8s %-10.2f\n", listSV[i].IDStudent, fullName, listSV[i].Gender, listSV[i].FinalPoint);
		
		}
	}
	system("pause");
}
void printAverageGrade() {
    system("cls");
    float sum=0;
    int i;
    for(i=0;i<stNum;i++) {
        sum+=listSV[i].FinalPoint;
    }
    printf("%.2f\n", sum);
    printf("%d\n", stNum);
    printf("Average grade: %.2f\n", sum/stNum);
    system("pause");
}
void printHighest() {
    //system("cls");
    float max=0.00;
    int i;
    for (i=0;i<stNum;i++) {
        if(max<listSV[i].FinalPoint) {
            max=listSV[i].FinalPoint;
        }
    }
    printf("%-10s %-30s %-8s %-10s\n", "ID", "Full Name", "Gender", "Grade");
    printf("===========================================================\n");
    for (i=0;i<stNum;i++) {
	if (max == listSV[i].FinalPoint){
    	char fullName[50] = "";
    
        	strcat(fullName, listSV[i].FirstName);
        	strcat(fullName, " ");
        	strcat(fullName, listSV[i].LastName);
        	printf("%-10s %-30s %-8s %-10.2f\n", listSV[i].IDStudent, fullName, listSV[i].Gender, listSV[i].FinalPoint);
		}
	}
    system("pause");
}
void printLowest(){
    system("cls");
    float min=10.00;
    int i;
    for (i=0;i<stNum;i++) {
        if(min>listSV[i].FinalPoint) {
            min=listSV[i].FinalPoint;
        }
    }
    printf("%-10s %-30s %-8s %-10s\n", "ID", "Full Name", "Gender", "Grade");
    printf("===========================================================\n");
    for (i=0;i<stNum;i++) {
    	if(min==listSV[i].FinalPoint) {
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
    system("cls");
    int otp;
    do {
        printf("    ~ OPTION ~\n");
        printf("1. Print out average grade\n");
        printf("2. Print out the highest grade\n");
        printf("3. Print out the lowest grade\n");
        printf("0. Exit\n");
        printf("Please choose: ");
        scanf("%d", &otp);
    switch (otp) {
        case 1: 
            printAverageGrade();
            break;
        case 2:
            printHighest();
            break;
        case 3:
            printLowest();
            break;
        default : break;
    }
    } while(otp!=0);

    system("pause");

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
